
#include "types.h"


/* set byte in 64-bit Ascon word */
#define SETBYTE(b, i) ((u64)(b) << (56 - 8 * (i)))

/* load bytes into 64-bit Ascon word */
static inline u64 LOADBYTES(volatile u8* bytes, u64 n) {
  u64 x = 0;
  for (u64 i = 0; i < n; ++i) x |= SETBYTE(bytes[i], i);
  return x;
}
