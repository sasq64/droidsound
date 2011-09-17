/*
 *           sc68 - YM-2149 emulator - Atari ST Volume Table
 *             Copyright (C) 2001-2009 Benjamin Gerard
 *           <benjihan -4t- users.sourceforge -d0t- net>
 *
 * This  program is  free  software: you  can  redistribute it  and/or
 * modify  it under the  terms of  the GNU  General Public  License as
 * published by the Free Software  Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT  ANY  WARRANTY;  without   even  the  implied  warranty  of
 * MERCHANTABILITY or  FITNESS FOR A PARTICULAR PURPOSE.   See the GNU
 * General Public License for more details.
 *
 * You should have  received a copy of the  GNU General Public License
 * along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 */

/* $Id$ */

/* Table of 4 bit D/A output level for 1 channel.*/
static const u16 volumetable_original[32 * 32 * 32] =
# include "ymout2k9.h"
  ;

/* Create a non-linear 3 channels 5 bit per channels DAC table.
 */
static void
create_table(s16 * out, uint_t level, const char * name)
{
  int h;

  if (!level) {
    for (h=0; h<32*32*32; ++h) {
      out[h] = 0;
    }
  } else {
    for (h=0; h<32*32*32; ++h) {
      out[h] = volumetable_original[h];
    }
  }

  if (level) {
    const int min = ((u16*)out)[0x0000];
    const int max = ((u16*)out)[0x7fff];
    const int div = max-min ? max-min : 1;
    const int mid = ( level + 1 ) >> 1;

    msg68(ym_cat,
	  "ym-2149: creating %s -- min:%d max:%d div:%d mid:%d\n",
	  name, min, max, div, mid);

    assert(level < 65536u);
    assert(max > min);

    for (h=0; h<32*32*32; ++h) {
      int tmp = ((u16*)out)[h], res;
      assert(tmp >= min);
      assert(tmp <= max);
      
      if (tmp < min || tmp > max) {
	msg68_critical
	  ("ym-2149: volume model -- *%s* -- %d out of range [%d..%d]\n",
	   name, tmp, min, max);
      }
      
      res = (tmp-min) * level / div - mid;
      out[h] = res;

      TRACE68(ym_cat,
	      "ym-2149: -- %s -- %02x %02x %02x -- %d\n",
	      name, h&31, (h>>5)&31, (h>>10)&31, res);
    }
  }
  msg68_info("ym-2149: volume model -- *%s* -- [%d..%d]\n",
	     name, out[0], out[0x7FFF]);
}

/* Create a non-linear 3 channels 5 bit per channels DAC table.
 */
void ym_create_5bit_atarist_table(s16 * out, unsigned int level)
{
  create_table(out, level,"atarist-5bit-2k9");
}

/* Create a non-linear 3 channels 4 bit per channels DAC table.
 */
void ym_create_4bit_atarist_table(s16 * out, unsigned int level)
{
  create_table(out, level,"atarist-4bit");
}

