// SIDEmu.cpp: Implementierung der Klasse CSIDEmu.
//
//////////////////////////////////////////////////////////////////////

// Quick cut'n paste from TinySID sources
//
// The c64-emulation and the synth-renderer was written by Tammo Hinrichs (kb)
//
// Combining of the emulation and the renderer as well as improvements and bugfixes 
// by Rainer Sinsch (sinsch@stud.uni-frankfurt.de)
//
// spreading of the source code is FORBIDDEN!!!

//#include "stdafx.h"
#include "SIDEmu.h"

#include <math.h>
#include <memory.h>

#define FLAG_N 128
#define FLAG_V 64
#define FLAG_B 16
#define FLAG_D 8
#define FLAG_I 4
#define FLAG_Z 2
#define FLAG_C 1

#define imp 0
#define imm 1
#define abs 2
#define absx 3
#define absy 4
#define zp 6
#define zpx 7
#define zpy 8
#define ind 9
#define indx 10
#define indy 11
#define acc 12
#define rel 13

static inline int pfloat_ConvertFromInt(int i)
{
	return i<<16;
}
static inline int pfloat_ConvertFromFloat(float f)
{
	return (int)(f*(1<<16));
}
static inline int pfloat_Multiply(int a, int b)
{
	return (a>>8)*(b>>8);
}
static inline int pfloat_ConvertToInt(int i)
{
	return i>>16;
}

// ------------------------------------------------------------- constants
float CSIDEmu::attackTimes[16] =
{
  0.0022528606f, 0.0080099577f, 0.0157696042f, 0.0237795619f, 0.0372963655f,
  0.0550684591f ,0.0668330845f, 0.0783473987f, 0.0981219818f, 0.244554021f,
  0.489108042f, 0.782472742f, 0.977715461f, 2.93364701f, 4.88907793f, 7.82272493f
};
float CSIDEmu::decayReleaseTimes[16] =
{
  0.00891777693f, 0.024594051f, 0.0484185907f, 0.0730116639f, 0.114512475f,
  0.169078356f, 0.205199432f, 0.240551975f, 0.301266125f, 0.750858245f,
  1.50171551f, 2.40243682f, 3.00189298f, 9.00721405f, 15.010998f, 24.0182111f
};

int CSIDEmu::opcodes[256] = {
  brk,ora,xxx,xxx,xxx,ora,asl,xxx,php,ora,asl,xxx,xxx,ora,asl,xxx,
  bpl,ora,xxx,xxx,xxx,ora,asl,xxx,clc,ora,xxx,xxx,xxx,ora,asl,xxx,
  jsr,and,xxx,xxx,bit,and,rol,xxx,plp,and,rol,xxx,bit,and,rol,xxx,
  bmi,and,xxx,xxx,xxx,and,rol,xxx,sec,and,xxx,xxx,xxx,and,rol,xxx,
  rti,eor,xxx,xxx,xxx,eor,lsr,xxx,pha,eor,lsr,xxx,jmp,eor,lsr,xxx,
  bvc,eor,xxx,xxx,xxx,eor,lsr,xxx,cli,eor,xxx,xxx,xxx,eor,lsr,xxx,
  rts,adc,xxx,xxx,xxx,adc,ror,xxx,pla,adc,ror,xxx,jmp,adc,ror,xxx,
  bvs,adc,xxx,xxx,xxx,adc,ror,xxx,sei,adc,xxx,xxx,xxx,adc,ror,xxx,
  xxx,sta,xxx,xxx,sty,sta,stx,xxx,dey,xxx,txa,xxx,sty,sta,stx,xxx,
  bcc,sta,xxx,xxx,sty,sta,stx,xxx,tya,sta,txs,xxx,xxx,sta,xxx,xxx,
  ldy,lda,ldx,xxx,ldy,lda,ldx,xxx,tay,lda,tax,xxx,ldy,lda,ldx,xxx,
  bcs,lda,xxx,xxx,ldy,lda,ldx,xxx,clv,lda,tsx,xxx,ldy,lda,ldx,xxx,
  cpy,cmp,xxx,xxx,cpy,cmp,dec,xxx,iny,cmp,dex,xxx,cpy,cmp,dec,xxx,
  bne,cmp,xxx,xxx,xxx,cmp,dec,xxx,cld,cmp,xxx,xxx,xxx,cmp,dec,xxx,
  cpx,sbc,xxx,xxx,cpx,sbc,inc,xxx,inx,sbc,nop,xxx,cpx,sbc,inc,xxx,
  beq,sbc,xxx,xxx,xxx,sbc,inc,xxx,sed,sbc,xxx,xxx,xxx,sbc,inc,xxx
};


int CSIDEmu::modes[256] = {
 imp,indx,xxx,xxx,zp,zp,zp,xxx,imp,imm,acc,xxx,abs,abs,abs,xxx,
 rel,indy,xxx,xxx,xxx,zpx,zpx,xxx,imp,absy,xxx,xxx,xxx,absx,absx,xxx,
 abs,indx,xxx,xxx,zp,zp,zp,xxx,imp,imm,acc,xxx,abs,abs,abs,xxx,
 rel,indy,xxx,xxx,xxx,zpx,zpx,xxx,imp,absy,xxx,xxx,xxx,absx,absx,xxx,
 imp,indx,xxx,xxx,zp,zp,zp,xxx,imp,imm,acc,xxx,abs,abs,abs,xxx,
 rel,indy,xxx,xxx,xxx,zpx,zpx,xxx,imp,absy,xxx,xxx,xxx,absx,absx,xxx,
 imp,indx,xxx,xxx,zp,zp,zp,xxx,imp,imm,acc,xxx,ind,abs,abs,xxx,
 rel,indy,xxx,xxx,xxx,zpx,zpx,xxx,imp,absy,xxx,xxx,xxx,absx,absx,xxx,
 imm,indx,xxx,xxx,zp,zp,zp,xxx,imp,imm,acc,xxx,abs,abs,abs,xxx,
 rel,indy,xxx,xxx,zpx,zpx,zpy,xxx,imp,absy,acc,xxx,xxx,absx,absx,xxx,
 imm,indx,imm,xxx,zp,zp,zp,xxx,imp,imm,acc,xxx,abs,abs,abs,xxx,
 rel,indy,xxx,xxx,zpx,zpx,zpy,xxx,imp,absy,acc,xxx,absx,absx,absy,xxx,
 imm,indx,xxx,xxx,zp,zp,zp,xxx,imp,imm,acc,xxx,abs,abs,abs,xxx,
 rel,indy,xxx,xxx,zpx,zpx,zpx,xxx,imp,absy,acc,xxx,xxx,absx,absx,xxx,
 imm,indx,xxx,xxx,zp,zp,zp,xxx,imp,imm,acc,xxx,abs,abs,abs,xxx,
 rel,indy,xxx,xxx,zpx,zpx,zpx,xxx,imp,absy,acc,xxx,xxx,absx,absx,xxx
};



//////////////////////////////////////////////////////////////////////
// Konstruktion/Destruktion
//////////////////////////////////////////////////////////////////////

CSIDEmu::CSIDEmu()
{
	// Initialize postprocessing filters
	filterl1=0;
	filterb1=0;
	freq=0.9f;
	filterrez=0.2f;
}

CSIDEmu::~CSIDEmu()
{

}

#pragma warning(push)								// Inline Assembler Warnings unterdr�cken
#pragma warning(disable:4035)
inline byte CSIDEmu::get_bit(dword val, byte b)
{
	_asm {
		mov eax, val
		mov bl, b
		bt eax, bl
		setc al	
	}
}
#pragma warning(pop)

// ------------------------------------------------------------- synthesis
// initialize SID and frequency dependant values
void CSIDEmu::synth_init(dword mixfrq)
{
  freqmul = (dword)(15872000 / mixfrq);
  //filtmul = 21.5332031f / mixfrq;
  filtmul = pfloat_ConvertFromFloat(21.5332031f)/mixfrq;
  for (int i=0;i<16;i++) {
    attacks [i]=(dword) (0x1000000 / (attackTimes[i]*mixfrq));
    releases[i]=(dword) (0x1000000 / (decayReleaseTimes[i]*mixfrq));
  }
  memset(&sid,0,sizeof(sid));
  memset(osc,0,sizeof(osc));
  memset(&filter,0,sizeof(filter));
  osc[0].noiseval = 0xffffff;
  osc[1].noiseval = 0xffffff;
  osc[2].noiseval = 0xffffff;  
}

// render a buffer of n samples with the actual register contents
void CSIDEmu::synth_render (word *buffer, dword len)
{
  // step 1: convert the not easily processable sid registers into some
  //         more convenient and fast values (makes the thing much faster
  //         if you process more than 1 sample value at once)      
  for (byte v=0;v<3;v++) {
    osc[v].pulse   = (sid.v[v].pulse & 0xfff) << 16;		
    osc[v].filter  = get_bit(sid.res_ftv,v);
    osc[v].attack  = attacks[sid.v[v].ad >> 4];
    osc[v].decay   = releases[sid.v[v].ad & 0xf];
    osc[v].sustain = sid.v[v].sr & 0xf0;
    osc[v].release = releases[sid.v[v].sr & 0xf];
    osc[v].wave    = sid.v[v].wave;
    osc[v].freq    = ((dword)sid.v[v].freq)*freqmul;
  }

  //filter.freq  = (16* sid.ffreqhi + (sid.ffreqlo&0x7))*filtmul;  
  filter.freq = (16* sid.ffreqhi + (sid.ffreqlo&0x7))*filtmul;  
  
  
  if (filter.freq>pfloat_ConvertFromInt(1))
    filter.freq=pfloat_ConvertFromInt(1);
  // the above line isnt correct at all - the problem is that the filter
  // works only up to rmxfreq/4 - this is sufficient for 44KHz but isnt
  // for 32KHz and lower - well, but sound quality is bad enough then to
  // neglect the fact that the filter doesnt come that high ;)
  filter.l_ena = get_bit(sid.ftp_vol,4);
  filter.b_ena = get_bit(sid.ftp_vol,5);
  filter.h_ena = get_bit(sid.ftp_vol,6);
  filter.v3ena = !get_bit(sid.ftp_vol,7);
  filter.vol   = (sid.ftp_vol & 0xf)*16;  
  //filter.rez   = 1.2f-0.04f*(sid.res_ftv >> 4);
  filter.rez   = pfloat_ConvertFromFloat(1.2f) - 
					pfloat_ConvertFromFloat(0.04f)*(sid.res_ftv >> 4);
  
  
  // now render the buffer
  for (dword bp=0;bp<len;bp++) {
    int outo=0;
    int outf=0;
    // step 2 : generate the two output signals (for filtered and non-
    //          filtered) from the osc/eg sections
    for (v=0;v<3;v++) {
      // update wave counter
      osc[v].counter = (osc[v].counter+osc[v].freq) & 0xFFFFFFF;
      // reset counter / noise generator if reset get_bit set
      if (osc[v].wave & 0x08) {
        osc[v].counter  = 0;
        osc[v].noisepos = 0;
        osc[v].noiseval = 0xffffff;
      }
      byte refosc = v?v-1:2;  // reference oscillator for sync/ring
      // sync oscillator to refosc if sync bit set
      if (osc[v].wave & 0x02)
        if (osc[refosc].counter < osc[refosc].freq)
          osc[v].counter = osc[refosc].counter * osc[v].freq / osc[refosc].freq;
      // generate waveforms with really simple algorithms
      byte triout = (byte) (osc[v].counter>>19);
      if (osc[v].counter>>27)
        triout^=0xff;
      byte sawout = (byte) (osc[v].counter >> 20);
      byte plsout = (byte) ((osc[v].counter > osc[v].pulse)-1);

      // generate noise waveform exactly as the SID does.
      if (osc[v].noisepos!=(osc[v].counter>>23))
      {
        osc[v].noisepos = osc[v].counter >> 23;
        osc[v].noiseval = (osc[v].noiseval << 1) |
                          (get_bit(osc[v].noiseval,22) ^ get_bit(osc[v].noiseval,17));
        osc[v].noiseout = (get_bit(osc[v].noiseval,22) << 7) |
                          (get_bit(osc[v].noiseval,20) << 6) |
                          (get_bit(osc[v].noiseval,16) << 5) |
                          (get_bit(osc[v].noiseval,13) << 4) |
                          (get_bit(osc[v].noiseval,11) << 3) |
                          (get_bit(osc[v].noiseval, 7) << 2) |
                          (get_bit(osc[v].noiseval, 4) << 1) |
                          (get_bit(osc[v].noiseval, 2) << 0);
      }
      byte nseout = osc[v].noiseout;

      // modulate triangle wave if ringmod bit set

      if (osc[v].wave & 0x04)
        if (osc[refosc].counter < 0x8000000)
          triout ^= 0xff;

      // now mix the oscillators with an AND operation as stated in
      // the SID's reference manual - even if this is completely wrong.
      // well, at least, the $30 and $70 waveform sounds correct and there's
      // no real solution to do $50 and $60, so who cares.

      byte outv=0xFF;
      if (osc[v].wave & 0x10) outv &= triout;
      if (osc[v].wave & 0x20) outv &= sawout;
      if (osc[v].wave & 0x40) outv &= plsout;
      if (osc[v].wave & 0x80) outv &= nseout;

      // now process the envelopes. the first thing about this is testing
      // the gate bit and put the EG into attack or release phase if desired
      if (!(osc[v].wave & 0x01)) osc[v].envphase=3;
      else if (osc[v].envphase==3) osc[v].envphase=0;
      // so now process the volume according to the phase and adsr values	  
      switch (osc[v].envphase) {
        case 0 : {                          // Phase 0 : Attack
                   osc[v].envval+=osc[v].attack;
                   if (osc[v].envval >= 0xFFFFFF)
                   {
                     osc[v].envval   = 0xFFFFFF;
                     osc[v].envphase = 1;
                   }
                   break;
                 }
        case 1 : {                          // Phase 1 : Decay
                   osc[v].envval-=osc[v].decay;
                   if ((signed int) osc[v].envval <= (signed int) (osc[v].sustain<<16))
                   {
                     osc[v].envval   = osc[v].sustain<<16;
                     osc[v].envphase = 2;
                   }
                   break;
                 }
        case 2 : {                          // Phase 2 : Sustain
                   if ((signed int) osc[v].envval != (signed int) (osc[v].sustain<<16))
                   {
                     osc[v].envphase = 1;
                   }
                     // :) yes, thats exactly how the SID works. and maybe
                     // a music routine out there supports this, so better
                     // let it in, thanks :)
                   break;
                 }
        case 3 : {                          // Phase 3 : Release
                   osc[v].envval-=osc[v].release;
                   if (osc[v].envval < 0x40000) osc[v].envval= 0x40000;
                     // the volume offset is because the SID does not
                     // completely silence the voices when it should. most
                     // emulators do so though and thats the main reason
                     // why the sound of emulators is too, err... emulated :)
                   break;
                 }
      }
      // now route the voice output to either the non-filtered or the
      // filtered channel and dont forget to blank out osc3 if desired	  
	  //printf("%20f\n", (float)osc[v].envval*((float)outv-(float)0x80)/(float)0xFFFF);
      if (v<2 || filter.v3ena)
        if (osc[v].filter)
		  //outf+=osc[v].envval*((signed short)(outv-0x80))/0x3FFFFFF;		  		  
		  outf+=(((int)(outv-0x80))*osc[v].envval)>>26;
		
        else
		  //outo+=osc[v].envval*((signed short)(outv-0x80))/0x3FFFFFF;		  
		  outo+=(((int)(outv-0x80))*osc[v].envval)>>26;
    }		
    // step 3
    // so, now theres finally time to apply the multi-mode resonant filter
    // to the signal. The easiest thing ist just modelling a real electronic
    // filter circuit instead of fiddling around with complex IIRs or even
    // FIRs ...
    // it sounds as good as them or maybe better and needs only 3 MULs and
    // 4 ADDs for EVERYTHING. SIDPlay uses this kind of filter, too, but
    // Mage messed the whole thing completely up - as the rest of the
    // emulator.
    // This filter sounds a lot like the 8580, as the low-quality, dirty
    // sound of the 6581 is uuh too hard to achieve :)
	    
	//filter.h = outf - filter.b*filter.rez - filter.l;	  
	filter.h = pfloat_ConvertFromInt(outf) - pfloat_Multiply(filter.b, filter.rez) - filter.l;
	//filter.b += filter.freq * filter.h;
	filter.b += pfloat_Multiply(filter.freq, filter.h);
	//filter.l += filter.freq * filter.b;
	filter.l += pfloat_Multiply(filter.freq, filter.b);

    outf = 0;

	//if (filter.l_ena) outf+=filter.l;
	//if (filter.b_ena) outf+=filter.b;
	//if (filter.h_ena) outf+=filter.h;
	
    if (filter.l_ena) outf+=pfloat_ConvertToInt(filter.l);
    if (filter.b_ena) outf+=pfloat_ConvertToInt(filter.b);
    if (filter.h_ena) outf+=pfloat_ConvertToInt(filter.h);
	    	
	int final_sample = (filter.vol*(outo+outf));
		
	//filterl1 = filterl1 + freq * filterb1;
    //filterb1 = filterrez*filterb1 - freq * ( filterl1 + final_sample);
	//*(buffer+bp)=(signed short) filterl1;
	*(buffer+bp)=final_sample;
	
  }
}



//
// C64 Mem Routinen
//
inline byte CSIDEmu::getmem(word addr)
{    
  return memory[addr];
}

void CSIDEmu::setmem(word addr, byte value)
{
	memory[addr]=value;

	// Alte SID-routinen
	if ((addr&0xfc00)==0xd400)
	{        
		addr&=0x1f;		
		sidPoke(addr,value);
	}
}

void CSIDEmu::sidPoke(int reg, unsigned char val)
{  		
	int voice;

	if ((reg >= 0) && (reg <= 6)) voice=0;
	if ((reg >= 7) && (reg <=13)) {voice=1; reg-=7;}
	if ((reg >= 14) && (reg <=20)) {voice=2; reg-=14;}

	switch (reg) {
		case 0: { // Frequenz niederwertiges byte Stimme 1
				  sid.v[voice].freq = (sid.v[voice].freq&0xff00)+val;
				  //printf("Voice%d: %d\n", voice, sid.v[voice].freq);
				  break;
				}
		case 1: { // Frequenz h�herwertiges byte Stimme 1
				  sid.v[voice].freq = (sid.v[voice].freq&0xff)+(val<<8);
				  break;
				}
		case 2: { // Pulsbreite niederwertiges byte Stimme 1
				  sid.v[voice].pulse = (sid.v[voice].pulse&0xff00)+val;
				  break;
				}
		case 3: { // Pulsbreite h�herwertiges byte Stimme 1
				  sid.v[voice].pulse = (sid.v[voice].pulse&0xff)+(val<<8);
				  break;
				}
		case 4: { sid.v[voice].wave = val; break;}

		case 5: { sid.v[voice].ad = val; break;}
		case 6: { sid.v[voice].sr = val; break;}

		case 21: { sid.ffreqlo = val; break; }
		case 22: { sid.ffreqhi = val; break; }
		case 23: { sid.res_ftv = val; break; }
		case 24: { sid.ftp_vol = val; break;}
	}
  return;
}
void CSIDEmu::sidReset(void)
{
}

byte CSIDEmu::getaddr(int mode)
{
  word ad,ad2;  
  switch(mode)
  {
    case imp:
      cycles+=2;
      return 0;
    case imm:
      cycles+=2;
      return getmem(pc++);
    case abs:
      cycles+=4;      
	  ad = *(word *) &memory[pc];
	  pc+=2;
	  
	  return getmem(ad);	  	  
    case absx:
      cycles+=4;
      ad=getmem(pc++);
      ad|=256*getmem(pc++);
	  
      ad2=ad+x;
      if ((ad2&0xff00)!=(ad&0xff00))
        cycles++;
      return getmem(ad2);
    case absy:
      cycles+=4;
      ad=getmem(pc++);
      ad|=256*getmem(pc++);
      ad2=ad+y;
      if ((ad2&0xff00)!=(ad&0xff00))
        cycles++;
      return getmem(ad2);
    case zp:
      cycles+=3;
      ad=getmem(pc++);
      return getmem(ad);
    case zpx:
      cycles+=4;
      ad=getmem(pc++);
      ad+=x;
      return getmem(ad&0xff);
    case zpy:
      cycles+=4;
      ad=getmem(pc++);
      ad+=y;
      return getmem(ad&0xff);
    case indx:
      cycles+=6;
      ad=getmem(pc++);
      ad+=x;
      ad2=getmem(ad&0xff);
      ad++;
      ad2|=getmem(ad&0xff)<<8;
      return getmem(ad2);
    case indy:
      cycles+=5;
      ad=getmem(pc++);
      ad2=getmem(ad);
      ad2|=getmem((ad+1)&0xff)<<8;
      ad=ad2+y;
      if ((ad2&0xff00)!=(ad&0xff00))
        cycles++;
      return getmem(ad);
    case acc:
      cycles+=2;
      return a;
  }  
  return 0;
}

void CSIDEmu::setaddr(int mode, byte val)
{
  word ad,ad2;
  switch(mode)
  {
    case abs:
      cycles+=2;
      ad=getmem(pc-2);
      ad|=256*getmem(pc-1);
	  setmem(ad,val);
      return;
    case absx:
      cycles+=3;
      ad=getmem(pc-2);
      ad|=256*getmem(pc-1);
      ad2=ad+x;
      if ((ad2&0xff00)!=(ad&0xff00))
        cycles--;
      setmem(ad2,val);
      return;
    case zp:
      cycles+=2;
      ad=getmem(pc-1);
      setmem(ad,val);
      return;
    case zpx:
      cycles+=2;
      ad=getmem(pc-1);
      ad+=x;
      setmem(ad&0xff,val);	  
      return;
    case acc:
      a=val;
      return;	
  }
}


void CSIDEmu::putaddr(int mode, byte val)
{
  word ad,ad2;
  switch(mode)
  {
    case abs:
      cycles+=4;
      ad=getmem(pc++);
      ad|=getmem(pc++)<<8;
      setmem(ad,val);
      return;
    case absx:
      cycles+=4;
      ad=getmem(pc++);
      ad|=getmem(pc++)<<8;
      ad2=ad+x;
      setmem(ad2,val);
      return;
    case absy:
      cycles+=4;
      ad=getmem(pc++);
      ad|=getmem(pc++)<<8;
      ad2=ad+y;
      if ((ad2&0xff00)!=(ad&0xff00))
        cycles++;
      setmem(ad2,val);
      return;
    case zp:
      cycles+=3;
      ad=getmem(pc++);
      setmem(ad,val);
      return;
    case zpx:
      cycles+=4;
      ad=getmem(pc++);
      ad+=x;
      setmem(ad&0xff,val);
      return;
    case zpy:
      cycles+=4;
      ad=getmem(pc++);
      ad+=y;
      setmem(ad&0xff,val);
      return;
    case indx:
      cycles+=6;
      ad=getmem(pc++);
      ad+=x;
      ad2=getmem(ad&0xff);
      ad++;
      ad2|=getmem(ad&0xff)<<8;
      setmem(ad2,val);	  
      return;
    case indy:      
	  cycles+=5;
      ad=getmem(pc++);
      ad2=getmem(ad);
      ad2|=getmem((ad+1)&0xff)<<8;
      ad=ad2+y;
      setmem(ad,val);	  
      return;
    case acc:
      cycles+=2;
      a=val;
      return;
  }
}


inline void CSIDEmu::setflags(int flag, int cond)
{
  cond?p|=flag:p&=~flag;
}


inline void CSIDEmu::push(byte val)
{
  setmem(0x100+s,val);
  if (s) s--;
}

inline byte CSIDEmu::pop()
{
  if (s<0xff) s++;
  return getmem(0x100+s);
}

inline void CSIDEmu::branch(int flag)
{
  signed char dist;
  dist=(signed char)getaddr(imm);
  wval=pc+dist;
  if (flag)
  {
    cycles+=((pc&0x100)!=(wval&0x100))?2:1;
    pc=wval;
  }
}

void CSIDEmu::cpuReset()
{
  a=x=y=0;
  p=0;
  s=255; 
  pc=getaddr(0xfffc);  
}

void CSIDEmu::cpuResetTo(word npc, byte na/*=0*/, byte nx/*=0*/, byte ny/*=0*/)
{
  a=na;
  x=nx;
  y=ny;
  p=0;
  s=255;
  pc=npc; 
}

int CSIDEmu::cpuParse()
{
  cycles=0;
  
  byte opc=getmem(pc++);
  int cmd=opcodes[opc];
  int addr=modes[opc];
  int c;  
  switch (cmd)
  {
    case adc:
      		
	  wval=(word)a+getaddr(addr)+((p&FLAG_C)?1:0);	  
      setflags(FLAG_C, wval&0x100);
      a=(byte)wval;
      setflags(FLAG_Z, !a);
      setflags(FLAG_N, a&0x80);
      setflags(FLAG_V, (!!(p&FLAG_C)) ^ (!!(p&FLAG_N)));
	  
      break;
    case and:
      bval=getaddr(addr);
      a&=bval;
      setflags(FLAG_Z, !a);
      setflags(FLAG_N, a&0x80);
      break;
    case asl:
      wval=getaddr(addr);
      wval<<=1;
      setaddr(addr,(byte)wval);
      setflags(FLAG_Z,!wval);
      setflags(FLAG_N,wval&0x80);
      setflags(FLAG_C,wval&0x100);
      break;
    case bcc:
      branch(!(p&FLAG_C));
      break;
    case bcs:
      branch(p&FLAG_C);
      break;
    case bne:
      branch(!(p&FLAG_Z));
      break;
    case beq:
      branch(p&FLAG_Z);
      break;
    case bpl:
      branch(!(p&FLAG_N));
      break;
    case bmi:
      branch(p&FLAG_N);
      break;
    case bvc:
      branch(!(p&FLAG_V));
      break;
    case bvs:
      branch(p&FLAG_V);
      break;
    case bit:
      bval=getaddr(addr);
      setflags(FLAG_Z,!(a&bval));
      setflags(FLAG_N,bval&0x80);
      setflags(FLAG_V,bval&0x40);
      break;
    case brk:			  
	  	
	  // Aufruf komplett beenden
	  pc=0;	  
      cycles+=7;	  	  	  	
      break;
    case clc:
      cycles+=2;
      setflags(FLAG_C,0);
      break;
    case cld:
      cycles+=2;
      setflags(FLAG_D,0);
      break;
    case cli:
      cycles+=2;
      setflags(FLAG_I,0);
      break;
    case clv:
      cycles+=2;
      setflags(FLAG_V,0);
      break;
    case cmp:
      bval=getaddr(addr);
      wval=(word)a-bval;
      setflags(FLAG_Z,!wval);
      setflags(FLAG_N,wval&0x80);
      setflags(FLAG_C,a>=bval);
      break;
    case cpx:
      bval=getaddr(addr);
      wval=(word)x-bval;
      setflags(FLAG_Z,!wval);
      setflags(FLAG_N,wval&0x80);      
	  setflags(FLAG_C,x>=bval);
      break;
    case cpy:
      bval=getaddr(addr);
      wval=(word)y-bval;
      setflags(FLAG_Z,!wval);
      setflags(FLAG_N,wval&0x80);      
	  setflags(FLAG_C,y>=bval);
      break;
    case dec:
      bval=getaddr(addr);
      bval--;
      setaddr(addr,bval);	  
      setflags(FLAG_Z,!bval);
      setflags(FLAG_N,bval&0x80);
      break;
    case dex:
      cycles+=2;
      x--;
      setflags(FLAG_Z,!x);
      setflags(FLAG_N,x&0x80);	  
      break;
    case dey:
      cycles+=2;
      y--;
      setflags(FLAG_Z,!y);
      setflags(FLAG_N,y&0x80);	  
      break;
    case eor:
      bval=getaddr(addr);
      a^=bval;
      setflags(FLAG_Z,!a);
      setflags(FLAG_N,a&0x80);
      break;
    case inc:
      bval=getaddr(addr);
      bval++;
      setaddr(addr,bval);
      setflags(FLAG_Z,!bval);
      setflags(FLAG_N,bval&0x80);
      break;
    case inx:
      cycles+=2;
      x++;
      setflags(FLAG_Z,!x);
      setflags(FLAG_N,x&0x80);
      break;
    case iny:
      cycles+=2;
      y++;
      setflags(FLAG_Z,!y);
      setflags(FLAG_N,y&0x80);
      break;
    case jmp:
      cycles+=3;
      wval=getmem(pc++);
      wval|=256*getmem(pc++);
      switch (addr)
      {
        case abs:
          pc=wval;
          break;
        case ind:
          pc=getmem(wval);
          pc|=256*getmem(wval+1);
          cycles+=2;
          break;
      }
      break;
    case jsr:
      cycles+=6;
      push((pc+1)>>8);
      push((pc+1));
      wval=getmem(pc++);
      wval|=256*getmem(pc++);
      pc=wval;
      break;
    case lda:
      a=getaddr(addr);
      setflags(FLAG_Z,!a);
      setflags(FLAG_N,a&0x80);
      break;
    case ldx:
      x=getaddr(addr);
      setflags(FLAG_Z,!x);
      setflags(FLAG_N,x&0x80);
      break;
    case ldy:
      y=getaddr(addr);
      setflags(FLAG_Z,!y);
      setflags(FLAG_N,y&0x80);
      break;
    case lsr:      
	  bval=getaddr(addr); wval=(byte)bval;
      wval>>=1;
      setaddr(addr,(byte)wval);
      setflags(FLAG_Z,!wval);
      setflags(FLAG_N,wval&0x80);
      setflags(FLAG_C,bval&1);
      break;
    case nop:
      cycles+=2;
      break;
    case ora:
      bval=getaddr(addr);
      a|=bval;
      setflags(FLAG_Z,!a);
      setflags(FLAG_N,a&0x80);
      break;
    case pha:
      push(a);
      cycles+=3;
      break;
    case php:
      push(p);
      cycles+=3;
      break;
    case pla:
      a=pop();
      setflags(FLAG_Z,!a);
      setflags(FLAG_N,a&0x80);
      cycles+=4;
      break;
    case plp:
      p=pop();
      cycles+=4;
      break;
    case rol:
      bval=getaddr(addr);
      c=!!(p&FLAG_C);
      setflags(FLAG_C,bval&0x80);
      bval<<=1;
      bval|=c;
      setaddr(addr,bval);
      setflags(FLAG_N,bval&0x80);
      setflags(FLAG_Z,!bval);
      break;
    case ror:
      bval=getaddr(addr);
      c=!!(p&FLAG_C);
      setflags(FLAG_C,bval&1);
      bval>>=1;
      bval|=128*c;
      setaddr(addr,bval);
      setflags(FLAG_N,bval&0x80);
      setflags(FLAG_Z,!bval);
      break;
    case rti:
		// NEU, rti wie rts
    case rts:
      wval=pop();
      wval|=pop()<<8;
      pc=wval+1;
      cycles+=6;
      break;
    case sbc:      
	  bval=getaddr(addr)^0xff;
      wval=(word)a+bval+((p&FLAG_C)?1:0);
      setflags(FLAG_C, wval&0x100);
      a=(byte)wval;
      setflags(FLAG_Z, !a);
      setflags(FLAG_N, a>127);
      setflags(FLAG_V, (!!(p&FLAG_C)) ^ (!!(p&FLAG_N)));	  
      break;
    case sec:
      cycles+=2;
      setflags(FLAG_C,1);
      break;
    case sed:
      cycles+=2;
      setflags(FLAG_D,1);
      break;
    case sei:
      cycles+=2;
      setflags(FLAG_I,1);
      break;
    case sta:
      putaddr(addr,a);
      break;
    case stx:
      putaddr(addr,x);
      break;
    case sty:
      putaddr(addr,y);
      break;
    case tax:
      cycles+=2;
      x=a;
      setflags(FLAG_Z, !x);
      setflags(FLAG_N, x&0x80);
      break;
    case tay:
      cycles+=2;
      y=a;
      setflags(FLAG_Z, !y);
      setflags(FLAG_N, y&0x80);
      break;
    case tsx:
      cycles+=2;
      x=s;
      setflags(FLAG_Z, !x);
      setflags(FLAG_N, x&0x80);
      break;
    case txa:
      cycles+=2;
      a=x;
      setflags(FLAG_Z, !a);
      setflags(FLAG_N, a&0x80);
      break;
    case txs:
      cycles+=2;
      s=x;
      break;
    case tya:
      cycles+=2;
      a=y;
      setflags(FLAG_Z, !a);
      setflags(FLAG_N, a&0x80);
      break;  
  }
  return cycles;
}

int CSIDEmu::cpuJSR(word npc, byte na, byte nx/*=0*/, byte ny/*=0*/)
{  
  a=na;
  x=nx;
  y=ny;
  p=0;
  s=255;
  pc=npc;
  push(0);
  push(0);
  int ccl=0;  

  while (pc > 1)
  {
	  ccl+=cpuParse();
  }
 
  return ccl;
}

void CSIDEmu::c64Init(void)
{  
	synth_init(44100);
	memset(memory, 0, 65535);
      
	cpuReset();    
}

word CSIDEmu::LoadSID(char *filename, word *load_addr, word *init_addr, word *play_addr)
{	
	word adr, offset=0;
	word data_file_offset;
	FILE *f;
	if ( (f=fopen(filename, "rb"))==NULL) return(0);
	// Feststellen von wo an das Datenfile beginnt
	fseek(f, 7, 0);
	data_file_offset = fgetc(f);
	// Init Adresse holen
	fseek(f, 10, 0);
	*init_addr = fgetc(f)<<8;
	*init_addr|= fgetc(f);

	// Play Adresse holen
	*play_addr = fgetc(f)<<8;
	*play_addr|= fgetc(f);			
	
	// Load Adresse holen
	fseek(f, 8, 0);
	adr = fgetc(f)<<8;
	adr|= fgetc(f);
		
	fseek(f, data_file_offset, 0);
	if (adr == 0) {		
		adr = fgetc(f);
		adr|= fgetc(f)<<8;
	};

	*load_addr = adr;
	
	// Daten einlesen
	memset(memory, 0, 65535);
	int songStart = ftell(f);
	while(!feof(f)) memory[(adr+offset++)%65536]=fgetc(f);	
	fclose(f);

	memcpy(memory_backup, memory, sizeof(memory));
	
	if (*play_addr == 0)
	{
		cpuJSR(*init_addr, 0);
		*play_addr = (memory[0x0315]<<8)+memory[0x0314];
	}

	return adr;	
}

CSIDEmu& CSIDEmu::Instance()
{
	static CSIDEmu instance;
	return(instance);
}
