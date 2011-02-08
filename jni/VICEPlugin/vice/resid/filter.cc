//  ---------------------------------------------------------------------------
//  This file is part of reSID, a MOS6581 SID emulator engine.
//  Copyright (C) 2010  Dag Lem <resid@nimrod.no>
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//  ---------------------------------------------------------------------------

#define RESID_FILTER_CC

#include "filter.h"
#include "dac.h"
#include "spline.h"

namespace reSID
{

// This is the SID op-amp voltage transfer function, measured on a chip marked
// MOS 6581R4AR 0687 14.
// All measured chips have op-amps with maximum output voltages (and thus
// maximum input voltages) well within the range of 0.75V - 10.25V.

static double_point opamp_voltage_6581[] = {
  {  0.75, 10.02 },  // Approximate start of actual range
  {  0.75, 10.02 },  // Repeated point
  {  2.50, 10.13 },
  {  2.75, 10.12 },
  {  2.90, 10.04 },
  {  3.00,  9.92 },
  {  3.10,  9.74 },
  {  3.25,  9.40 },
  {  3.50,  8.68 },
  {  4.00,  6.90 },
  {  4.25,  5.88 },
  {  4.53,  4.53 },  // Working point (vi = vo)
  {  4.75,  3.20 },
  {  4.90,  2.30 },  // Change of curvature
  {  4.95,  2.05 },
  {  5.00,  1.90 },
  {  5.10,  1.71 },
  {  5.25,  1.57 },
  {  5.50,  1.41 },
  {  6.00,  1.23 },
  {  7.50,  1.02 },
  {  9.00,  0.93 },
  { 10.25,  0.91 },  // Approximate end of actual range
  { 10.25,  0.91 }   // Repeated end point
};

// FIXME: Measure for the 8580.
static double_point opamp_voltage_8580[] = {
  {  0.75, 10.02 },  // Approximate start of actual range
  {  0.75, 10.02 },  // Repeated point
  {  2.50, 10.13 },
  {  2.75, 10.12 },
  {  2.90, 10.04 },
  {  3.00,  9.92 },
  {  3.10,  9.74 },
  {  3.25,  9.40 },
  {  3.50,  8.68 },
  {  4.00,  6.90 },
  {  4.25,  5.88 },
  {  4.53,  4.53 },  // Working point (vi = vo)
  {  4.75,  3.20 },
  {  4.90,  2.30 },  // Change of curvature
  {  4.95,  2.05 },
  {  5.00,  1.90 },
  {  5.10,  1.71 },
  {  5.25,  1.57 },
  {  5.50,  1.41 },
  {  6.00,  1.23 },
  {  7.50,  1.02 },
  {  9.00,  0.93 },
  { 10.25,  0.91 },  // Approximate end of actual range
  { 10.25,  0.91 }   // Repeated end point
};


typedef struct {
  // Op-amp transfer function.
  double_point* opamp_voltage;
  int opamp_voltage_size;
  // Voice output characteristics.
  double voice_voltage_range;
  double voice_DC_voltage;
  // Capacitor value.
  double C;
  // Transistor parameters.
  double Vdd;
  double Vth;      // Threshold voltage
  double K1_vcr;   // 1/2*u*Cox
  double WL_vcr;   // W/L for VCR
  double K1_snake; // 1/2*u*Cox
  double WL_snake; // W/L for "snake"
  // DAC parameters.
  double dac_zero;
  double dac_scale;
  double dac_2R_div_R;
  bool dac_term;
} model_filter_init_t;

static model_filter_init_t model_filter_init[2] = {
  {
    opamp_voltage_6581,
    sizeof(opamp_voltage_6581)/sizeof(*opamp_voltage_6581),
    // The dynamic analog range of one voice is approximately 1.5V,
    // riding at a DC level of approximately 5.0V.
    1.5,
    5.0,
    // Capacitor value.
    470e-12,
    // Transistor parameters.
    12.18,
    1.31,
    10e-6,
    9.0/1,
    10e-6,
    1.0/115,
    // DAC parameters.
    6.65,
    2.63,
    2.20,
    false
  },
  {
    opamp_voltage_8580,
    sizeof(opamp_voltage_8580)/sizeof(*opamp_voltage_8580),
    // FIXME: Measure for the 8580.
    1.5,
    0.75,  // FIXME: For now we pretend that the working point is 0V.
    470e-12,
    12.18,
    1.31,
    15e-6,
    9.0/1,
    10e-6,
    1.0/115,
    6.65,
    2.63,
    2.00,
    true
  }
};

unsigned short Filter::vcr_Vg[1 << 16];
unsigned short Filter::vcr_n_Ids[1 << 16];

Filter::model_filter_t Filter::model_filter[2];


// ----------------------------------------------------------------------------
// Constructor.
// ----------------------------------------------------------------------------
Filter::Filter()
{
  static bool class_init;

  if (!class_init) {
    for (int m = 0; m < 2; m++) {
      model_filter_init_t& fi = model_filter_init[m];
      model_filter_t& mf = model_filter[m];

      // Convert op-amp voltage transfer to 16 bit values.
      double vmin = fi.opamp_voltage[0][0];
      double vmax = fi.opamp_voltage[fi.opamp_voltage_size - 1][0];
      double denorm = vmax - vmin;
      double norm = 1.0/denorm;

      // Scaling and translation constants.
      double N16 = norm*((1u << 16) - 1);
      double N19 = norm*((1u << 19) - 1);
      double N31 = norm*((1u << 31) - 1);
      mf.vo_N16 = (int)(N16);  // FIXME: Remove?
      mf.vo_T19 = (int)(N19*vmin);
      mf.vo_T16 = (int)(N16*vmin);

      // The "zero" output level of the voices.
      // The digital range of one voice is 20 bits; create a scaling term
      // for multiplication which fits in 11 bits.
      double N14 = norm*(1u << 14);
      mf.voice_scale_s14 = (int)(N14*fi.voice_voltage_range);
      mf.voice_DC = (int)(N16*(fi.voice_DC_voltage - vmin));

      // Vth, Vdd - Vth
      mf.Vth = (int)(N16*fi.Vth + 0.5);
      mf.Vddt = (int)(N16*(fi.Vdd - fi.Vth) + 0.5);

      // Normalized VCR and snake current factors, 1 cycle at 1MHz.
      // Fit in 15 bits / 5 bits.
      mf.n_vcr = (int)(denorm*(1 << 13)*(fi.K1_vcr*fi.WL_vcr*1.0e-6/fi.C) + 0.5);
      mf.n_snake = (int)(denorm*(1 << 13)*(fi.K1_snake*fi.WL_snake*1.0e-6/fi.C) + 0.5);

      // Create lookup table mapping op-amp input voltage to op-amp output
      // voltage: vx -> vo
      // FIXME: No variable length arrays in ISO C++, hardcoding to max 50
      // points.
      // double_point scaled_voltage[fi.opamp_voltage_size];
      double_point scaled_voltage[50];

      for (int i = 0; i < fi.opamp_voltage_size; i++) {
	// The target output range is 16 bits, in order to fit in an unsigned
	// short.
	//
	// The y axis is temporarily scaled to 31 bits for maximum accuracy in
	// the calculated derivative.
	//
	// Values are normalized using
	//
	//   x_n = m*2^N*(x - xmin)
	//
	// and are translated back later (for fixed point math) using
	//
	//   m*2^N*x = x_n - m*2^N*xmin
	//
	scaled_voltage[i][0] = N19*(fi.opamp_voltage[i][0] - vmin);
	scaled_voltage[i][1] = N31*(fi.opamp_voltage[i][1] - vmin);
      }

      interpolate(scaled_voltage, scaled_voltage + fi.opamp_voltage_size - 1,
		  PointPlotter<int>(mf.opamp), 1.0);

      // Store both fn and dfn in the same table.
      int f = mf.opamp[0];
      for (int j = 0; j < (1 << 19); j++) {
	int fp = f;
	f = mf.opamp[j];  // Scaled by m*2^31
	// m*2^31*dy/1 = (m*2^31*dy)/(m*2^19*dx) = 2^12*dy/dx
	int df = f - fp;  // Scaled by 2^12

	// High 13 bits (12 bits + sign bit): 2^8*dfn
	// Low 19 bits (unsigned):            m*2^19*(fn - xmin)
	mf.opamp[j] = ((df << (19 + 8 - 12)) & ~0x7ffff) | (f >> 12);
      }

      // Create lookup tables for gains / summers.

      // 4 bit "resistor" ladders in the bandpass resonance gain and the audio
      // output gain necessitate 16 gain tables.
      // From die photographs of the bandpass and volume "resistor" ladders
      // it follows that gain ~ vol/8 and 1/Q ~ ~res/8 (assuming ideal
      // op-amps and ideal "resistors").
      int x;
      x = mf.vo_T19;
      for (int n8 = 0; n8 < 16; n8++) {
	int n = n8 << 4;  // Scaled by 2^7
	for (int vi = 0; vi < (1 << 16); vi++) {
	  mf.gain[n8][vi] = solve_gain(n, vi << 3, x, mf) >> 3;
	}
      }

      // The filter summer operates at n ~ 1, and has 5 fundamentally different
      // input configurations (2 - 6 input "resistors").
      //
      // Note that all "on" transistors are modeled as one. This is not
      // entirely accurate, since the input for each transistor is different,
      // and transistors are not linear components. However modeling all
      // transistors separately would be extremely costly.
      x = mf.vo_T19;
      int offset = 0;
      int size;
      for (int k = 0; k < 5; k++) {
	int idiv = 2 + k;        // 2 - 6 input "resistors".
	int n_idiv = idiv << 7;  // n*idiv, scaled by 2^7
	size = idiv << 16;
	for (int vi = 0; vi < size; vi++) {
	  mf.summer[offset + vi] =
	    solve_gain(n_idiv, (vi << 3)/idiv, x, mf) >> 3;
	}
	offset += size;
      }

      // The audio mixer operates at n ~ 8/6, and has 8 fundamentally different
      // input configurations (0 - 7 input "resistors").
      //
      // All "on", transistors are modeled as one - see comments above for
      // the filter summer.
      x = mf.vo_T19;
      offset = 0;
      size = 1;  // Only one lookup element for 0 input "resistors".
      for (int l = 0; l < 8; l++) {
	int idiv = l;                 // 0 - 7 input "resistors".
	int n_idiv = (idiv << 7)*8/6; // n*idiv, scaled by 2^7
	if (idiv == 0) {
	  // Avoid division by zero; the result will be correct since
	  // n_idiv = 0.
	  idiv = 1;
	}
	for (int vi = 0; vi < size; vi++) {
	  mf.mixer[offset + vi] =
	    solve_gain(n_idiv, (vi << 3)/idiv, x, mf) >> 3;
	}
	offset += size;
	size = (l + 1) << 16;
      }

      // Create lookup table mapping capacitor voltage to op-amp input voltage:
      // vc -> vx
      for (int m = 0; m < fi.opamp_voltage_size; m++) {
	scaled_voltage[m][0] = (N16*(fi.opamp_voltage[m][0] - fi.opamp_voltage[m][1]) + (1 << 16))/2;
	scaled_voltage[m][1] = N16*fi.opamp_voltage[m][0];
      }

      mf.vc_min = (int)(N31*(fi.opamp_voltage[0][0] - fi.opamp_voltage[0][1]));
      mf.vc_max = (int)(N31*(fi.opamp_voltage[fi.opamp_voltage_size - 1][0] - fi.opamp_voltage[fi.opamp_voltage_size - 1][1]));
      interpolate(scaled_voltage, scaled_voltage + fi.opamp_voltage_size - 1,
		  PointPlotter<unsigned short>(mf.opamp_rev), 1.0);

      // DAC table.
      int bits = 11;
      build_dac_table(mf.f0_dac, bits, fi.dac_2R_div_R, fi.dac_term);
      for (int n = 0; n < (1 << bits); n++) {
	mf.f0_dac[n] = (unsigned short)(N16*(fi.dac_zero + mf.f0_dac[n]*fi.dac_scale/(1 << bits)) + 0.5);
      }
    }

    // VCR - 6581 only.
    int Vddt = model_filter[0].Vddt;
    int Vth = model_filter[0].Vth;
    int n_vcr = model_filter[0].n_vcr;

    for (int i = 0; i < (1 << 16); i++) {
      // The table index is right-shifted 16 times in order to fit in
      // 16 bits; the argument to sqrt is thus multiplied by (1 << 16).
      vcr_Vg[i] = Vddt - (int)(sqrtf((float)i*(1 << 16)) + 0.5f);
    }

    for (int Vgs = 0; Vgs < (1 << 16); Vgs++) {
      int Vov_vcr = Vgs - Vth;
      if (Vov_vcr < 0) {
	vcr_n_Ids[Vgs] = 0;
      }
      else {
	// Scaled by (1/m)*2^13*m*2^16*m*2^16*2^-1*2^-1*2^-12*2^-15 = m*2^16
	vcr_n_Ids[Vgs] = n_vcr*((Vov_vcr >> 1)*(Vov_vcr >> 1) >> 12) >> 15;
      }
    }

    class_init = true;
  }

  enable_filter(true);
  set_chip_model(MOS6581);
  set_voice_mask(0x07);
  input(0);
  reset();
}


// ----------------------------------------------------------------------------
// Enable filter.
// ----------------------------------------------------------------------------
void Filter::enable_filter(bool enable)
{
  enabled = enable;
  set_sum_mix();
}


// ----------------------------------------------------------------------------
// Adjust the DAC bias parameter of the filter.
// This gives user variable control of the exact CF -> center frequency
// mapping used by the filter.
// The setting is currently only effective for 6581.
// ----------------------------------------------------------------------------
void Filter::adjust_filter_bias(double dac_bias)
{
  Vw_bias = int(dac_bias*model_filter[sid_model].vo_N16);
  set_w0();
}

// ----------------------------------------------------------------------------
// Set chip model.
// ----------------------------------------------------------------------------
void Filter::set_chip_model(chip_model model)
{
  sid_model = model;
  /* We initialize the state variables again just to make sure that
   * the earlier model didn't leave behind some foreign, unrecoverable
   * state. Hopefully set_chip_model() only occurs simultaneously with
   * reset(). */
  Vhp = 0;
  Vbp = Vbp_x = Vbp_vc = 0;
  Vlp = Vlp_x = Vlp_vc = 0;
}


// ----------------------------------------------------------------------------
// Mask for voices routed into the filter / audio output stage.
// Used to physically connect/disconnect EXT IN, and for test purposes
// (voice muting).
// ----------------------------------------------------------------------------
void Filter::set_voice_mask(reg4 mask)
{
  voice_mask = 0xf0 | (mask & 0x0f);
  set_sum_mix();
}


// ----------------------------------------------------------------------------
// SID reset.
// ----------------------------------------------------------------------------
void Filter::reset()
{
  fc = 0;
  res = 0;
  filt = 0;
  mode = 0;
  vol = 0;

  Vhp = 0;
  Vbp = Vbp_x = Vbp_vc = 0;
  Vlp = Vlp_x = Vlp_vc = 0;

  set_w0();
  set_Q();
  set_sum_mix();
}


// ----------------------------------------------------------------------------
// Register functions.
// ----------------------------------------------------------------------------
void Filter::writeFC_LO(reg8 fc_lo)
{
  fc = (fc & 0x7f8) | (fc_lo & 0x007);
  set_w0();
}

void Filter::writeFC_HI(reg8 fc_hi)
{
  fc = ((fc_hi << 3) & 0x7f8) | (fc & 0x007);
  set_w0();
}

void Filter::writeRES_FILT(reg8 res_filt)
{
  res = (res_filt >> 4) & 0x0f;
  set_Q();

  filt = res_filt & 0x0f;
  set_sum_mix();
}

void Filter::writeMODE_VOL(reg8 mode_vol)
{
  mode = mode_vol & 0xf0;
  set_sum_mix();

  vol = mode_vol & 0x0f;
}

// Set filter cutoff frequency.
void Filter::set_w0()
{
  model_filter_t& f = model_filter[sid_model];
  Vw = Vw_bias + f.f0_dac[fc];
  Vw_term = (f.Vddt >> 1)*(f.Vddt >> 1) - (Vw >> 1)*(f.Vddt >> 1) + (Vw >> 1)*(Vw >> 2);

  // FIXME: w0 is temporarily used for MOS 8580 emulation.
  // MOS 8580 cutoff: 0 - 12.5kHz.
  // Multiply with 1.048576 to facilitate division by 1 000 000 by right-
  // shifting 20 times (2 ^ 20 = 1048576).
  // 1.048576*2*pi*12500 = 82355
  w0 = 82355*fc >> 11;
}

/*
Set filter resonance.

In the MOS 6581, 1/Q is controlled linearly by res. From die photographs
of the resonance "resistor" ladder it follows that 1/Q ~ ~res/8
(assuming an ideal op-amp and ideal "resistors"). This implies that Q
ranges from 0.533 (res = 0) to 8 (res = E). For res = F, Q is actually
theoretically unlimited, which is quite unheard of in a filter
circuit.

To obtain Q ~ 1/sqrt(2) = 0.707 for maximally flat frequency response,
res should be set to 4: Q = 8/~4 = 8/11 = 0.7272 (again assuming an ideal
op-amp and ideal "resistors").

Q as low as 0.707 is not achievable because of low gain op-amps; res = 0
should yield the flattest possible frequency response at Q ~ 0.8 - 1.0
in the op-amp's pseudo-linear range (high amplitude signals will be
clipped). As resonance is increased, the filter must be clocked more
often to keep it stable.

In the MOS 8580, the resonance "resistor" ladder above the bp feedback
op-amp is split in two parts; one ladder for the op-amp input and one
ladder for the op-amp feedback.

input:         feedback:

               Rf
Ri R4 RC R8    R3
               R2
               R1


The "resistors" are switched in as follows by bits in register $17:

feedback:
R1: bit4&!bit5
R2: !bit4&bit5
R3: bit4&bit5
Rf: always on

input:
R4: bit6&!bit7
R8: !bit6&bit7
RC: bit6&bit7
Ri: !(R4|R8|RC) = !(bit6|bit7) = !bit6&!bit7


The relative "resistor" values are approximately (using channel length):

R1 = 15.3*Ri
R2 =  7.3*Ri
R3 =  4.7*Ri
Rf =  1.4*Ri
R4 =  1.4*Ri
R8 =  2.0*Ri
RC =  2.8*Ri


Approximate values for 1/Q can now be found as follows (assuming an
ideal op-amp):

res  feedback  input  -gain (1/Q)
---  --------  -----  ----------
 0   Rf        Ri     Rf/Ri      = 1/(Ri*(1/Rf))      = 1/0.71
 1   Rf|R1     Ri     (Rf|R1)/Ri = 1/(Ri*(1/Rf+1/R1)) = 1/0.78
 2   Rf|R2     Ri     (Rf|R2)/Ri = 1/(Ri*(1/Rf+1/R2)) = 1/0.85
 3   Rf|R3     Ri     (Rf|R3)/Ri = 1/(Ri*(1/Rf+1/R3)) = 1/0.92
 4   Rf        R4     Rf/R4      = 1/(R4*(1/Rf))      = 1/1.00
 5   Rf|R1     R4     (Rf|R1)/R4 = 1/(R4*(1/Rf+1/R1)) = 1/1.10
 6   Rf|R2     R4     (Rf|R2)/R4 = 1/(R4*(1/Rf+1/R2)) = 1/1.20
 7   Rf|R3     R4     (Rf|R3)/R4 = 1/(R4*(1/Rf+1/R3)) = 1/1.30
 8   Rf        R8     Rf/R8      = 1/(R8*(1/Rf))      = 1/1.43
 9   Rf|R1     R8     (Rf|R1)/R8 = 1/(R8*(1/Rf+1/R1)) = 1/1.56
 A   Rf|R2     R8     (Rf|R2)/R8 = 1/(R8*(1/Rf+1/R2)) = 1/1.70
 B   Rf|R3     R8     (Rf|R3)/R8 = 1/(R8*(1/Rf+1/R3)) = 1/1.86
 C   Rf        RC     Rf/RC      = 1/(RC*(1/Rf))      = 1/2.00
 D   Rf|R1     RC     (Rf|R1)/RC = 1/(RC*(1/Rf+1/R1)) = 1/2.18
 E   Rf|R2     RC     (Rf|R2)/RC = 1/(RC*(1/Rf+1/R2)) = 1/2.38
 F   Rf|R3     RC     (Rf|R3)/RC = 1/(RC*(1/Rf+1/R3)) = 1/2.60


These data indicate that the following function for 1/Q has been
modeled in the MOS 8580:

  1/Q = 2^(1/2)*2^(-x/8) = 2^(1/2 - x/8) = 2^((4 - x)/8)

*/
void Filter::set_Q()
{
  // Cutoff for MOS 6581.
  // The coefficient 8 is dispensed of later by right-shifting 3 times
  // (2 ^ 3 = 8).
  _8_div_Q = ~res & 0x0f;

  // FIXME: Temporary cutoff code for MOS 8580.
  // 1024*1/Q = 1024*2^((4 - res)/8)
  // The coefficient 1024 is dispensed of later by right-shifting 10 times
  // (2 ^ 10 = 1024).
  static const int _1024_div_Q_table[] = {
    1448,
    1328,
    1218,
    1117,
    1024,
    939,
    861,
    790,
    724,
    664,
    609,
    558,
    512,
    470,
    431,
    395
  };

  _1024_div_Q = _1024_div_Q_table[res];
}

// Set input routing bits.
void Filter::set_sum_mix()
{
  // NB! voice3off (mode bit 7) only affects voice 3 if it is routed directly
  // to the mixer.
  sum = filt & voice_mask;
  mix =
    (enabled ? (mode & 0x70) | ((~(filt | (mode & 0x80) >> 5)) & 0x0f) : 0x0f)
    & voice_mask;
}

} // namespace reSID
