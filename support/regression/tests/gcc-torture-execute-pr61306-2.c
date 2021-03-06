/*
   pr61306-2.c from the execute part of the gcc torture tests.
 */

#include <testfwk.h>

#ifdef __SDCC
#pragma std_c99
#endif

#include <stdint.h>
#include <limits.h>

#define fake_const_swab32(x) ((uint32_t)(			      \
	(((uint32_t)         (x) & (uint32_t)0x000000ffUL) << 24) |   \
	(((uint32_t)(int16_t)(x) & (uint32_t)0x00ffff00UL) <<  8) |   \
	(((uint32_t)         (x) & (uint32_t)0x00ff0000UL) >>  8) |   \
	(((uint32_t)         (x) & (uint32_t)0xff000000UL) >> 24)))


/* Previous version of bswap optimization failed to consider sign extension
   and as a result would replace an expression *not* doing a bswap by a
   bswap.  */

#ifndef __SDCC_pdk14 // Lack of memory
uint32_t
fake_bswap32 (uint32_t in)
{
  return fake_const_swab32 (in);
}
#endif

void
testTortureExecute (void)
{
#ifndef __SDCC_pdk14 // Lack of memory
  if (sizeof (uint32_t) * CHAR_BIT != 32)
    return;
  if (sizeof (int16_t) * CHAR_BIT != 16)
    return;
  if (fake_bswap32 (0x81828384) != 0xff838281)
    ASSERT (0);
#endif
}
