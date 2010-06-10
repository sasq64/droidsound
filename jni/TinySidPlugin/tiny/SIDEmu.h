// SIDEmu.h: Schnittstelle f�r die Klasse CSIDEmu.
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


#if !defined(AFX_SIDEMU_H__32219DE5_C202_440C_991E_44A7A8136E44__INCLUDED_)
#define AFX_SIDEMU_H__32219DE5_C202_440C_991E_44A7A8136E44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Pseudofloat.h"

typedef unsigned char  byte;
typedef unsigned short word;
typedef unsigned long  dword;

#undef adc

class CSIDEmu  
{	
	enum { 
		  adc, and2, asl, bcc, bcs, beq, bit, bmi, bne, bpl, brk, bvc, bvs, clc,
		  cld, cli, clv, cmp, cpx, cpy, dec, dex, dey, eor, inc, inx, iny, jmp,
		  jsr, lda, ldx, ldy, lsr, nop, ora, pha, php, pla, plp, rol, ror, rti,
		  rts, sbc, sec, sed, sei, sta, stx, sty, tax, tay, tsx, txa, txs, tya,
		  xxx};
	
	// SID register definition
	struct s6581 {
	struct sidvoice {
			 word freq;
			 word pulse;
			 byte wave;
			 byte ad;
			 byte sr;
		   } v[3];
	byte ffreqlo;
	byte ffreqhi;
	byte res_ftv;
	byte ftp_vol;
	};

	// internal oscillator def
	struct sidosc {
                dword freq;
                dword pulse;
                byte wave;
                byte filter;
                dword attack;
                dword decay;
                dword sustain;
                dword release;
                dword       counter;  // Variablen
                signed long envval;
                byte        envphase;
                dword       noisepos;
                dword       noiseval;
                byte        noiseout;
    };

	// internal filter def
	struct sidflt {
                int freq;
                byte  l_ena;
                byte  b_ena;
                byte  h_ena;
                byte  v3ena;
                int vol;
                int rez;
                int h;
                int b;
                int l;
               };

	static float attackTimes[16];
	static float decayReleaseTimes[16];
	static int opcodes[256];
	static int modes[256];
	
	// --------------------------- pseudo-constants (depending on mixing freq)
	dword  freqmul;
	int  filtmul;
	dword  attacks [16];
	dword  releases[16];

	// --------------------------------------------------------------- globals
	struct s6581 sid;
	struct sidosc osc[3];
	struct sidflt filter;

	// ------------------------------------------------ postprocessing filters
	float filterl1,filterb1,freq,filterrez;

	// --------------------------------------------------------- C64 Emu Stuff
	int cycles;
	byte bval;
	word wval;
	// -------------------------------------------------------------- Register
	byte a,x,y,s,p;
	word pc;

	byte memory[65536];
	byte memory_backup[65536];

	byte get_bit(dword val, byte b);	
	byte getmem(word addr);
	void setmem(word addr, byte value);
	void sidPoke(int reg, unsigned char val);
	void sidReset(void);
	byte getaddr(int mode);
	void setaddr(int mode, byte val);
	void putaddr(int mode, byte val);
	void setflags(int flag, int cond);
	void push(byte val);
	byte pop();
	void branch(int flag);
	void cpuReset();
	void cpuResetTo(word npc, byte na=0, byte nx=0, byte ny=0);
	int cpuParse();

public:
	CSIDEmu();
	virtual ~CSIDEmu();
	int cpuJSR(word npc, byte na, byte nx=0, byte ny=0);
	void c64Init(void);
	word LoadSID(
		char *filename, word *load_addr, word *init_addr, 
		word *play_addr);
	void synth_init(dword mixfrq);
	void synth_render(word *buffer, dword len);
	static CSIDEmu& Instance();
};

#endif // !defined(AFX_SIDEMU_H__32219DE5_C202_440C_991E_44A7A8136E44__INCLUDED_)
