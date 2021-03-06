/*
 * Simulator of microcontrollers (regspdk.h)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
 * 
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
 *
 */

/* This file is part of microcontroller simulator: ucsim.

UCSIM is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

UCSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with UCSIM; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA. */
/*@1@*/

#ifndef REGPDK_HEADER
#define REGPDK_HEADER

#include "ddconfig.h"


struct t_regs
{
  u8_t a;

  u8_t flag;
  u8_t sp;
  u8_t clkmd;
  u8_t inten;
  u8_t intrq;
  u8_t t16m;
  u8_t eoscr;
  u8_t integs;
  u8_t padier;
  u8_t pbdier;
  u8_t pa;
  u8_t pac;
  u8_t paph;
  u8_t pb;
  u8_t pbc;
  u8_t pbph;
  u8_t misc;
  u8_t tm2c;
  u8_t tm2ct;
  u8_t tm2s;
  u8_t tm2b;
  u8_t tm3c;
  u8_t tm3ct;
  u8_t tm3s;
  u8_t tm3b;
  u8_t gpcc;
  u8_t gpcs;
  u8_t pwmg0c;
  u8_t pwmg0s;
  u8_t pwmg0cubh;
  u8_t pwmg0cubl;
  u8_t pwmg0dth;
  u8_t pwmg0dtl;
  u8_t pwmg1c;
  u8_t pwmg1s;
  u8_t pwmg1cubh;
  u8_t pwmg1cubl;
  u8_t pwmg1dth;
  u8_t pwmg1dtl;
  u8_t pwmg2c;
  u8_t pwmg2s;
  u8_t pwmg2cubh;
  u8_t pwmg2cubl;
  u8_t pwmg2dth;
  u8_t pwmg2dtl;
};

#define BIT_Z	0x01  // zero status, 1=zero, 0=nonzero
#define BIT_C	0x02  // carry status(addition and subtraction)
#define BIT_AC  0x04  // sign, 1=negative, 0=positive (or zero)
#define BIT_OV  0x08  // signed overflow, 1=overflow, 0=no overflow
#define BIT_ALL	(BIT_Z | BIT_C | BIT_AC | BIT_OV)  // all bits

#define BITPOS_Z 0    // 1
#define BITPOS_C 1    // 2H
#define BITPOS_AC 2    // 4H
#define BITPOS_OV 3    // 8H

#endif

/* End of pdk.src/regspdk.h */
