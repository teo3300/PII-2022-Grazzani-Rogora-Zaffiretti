#ifndef WORD_H_
#define WORD_H_

#include "types.h"

/* get byte from 64-bit Ascon word */
#define GETBYTE(x, i) ((u8)((u64)(x) >> (56 - 8 * (i))))

/* set byte in 64-bit Ascon word */
#define SETBYTE(b, i) ((u64)(b) << (56 - 8 * (i)))

/* set padding byte in 64-bit Ascon word */
#define PAD(i) SETBYTE(0x80, i)

/* load bytes into 64-bit Ascon word */
static inline u64 LOADBYTES(const u8 bytes[8], int n) {
	u64 x = 0;
  for (int i = 0; i < n; ++i)
	  x |= SETBYTE(bytes[i], i);
  return x;
}

/* store bytes from 64-bit Ascon word */
static inline void STOREBYTES(u8 bytes[MAX_MESSAGE_LENGTH + CRYPTO_ABYTES], u64 x, int n) {
  for (int i = 0; i < n; ++i) bytes[i] = GETBYTE(x, i);
}

/* clear bytes in 64-bit Ascon word */
static inline u64 CLEARBYTES(u64 x, int n) {
  for (int i = 0; i < n; ++i) x &= ~SETBYTE(0xff, i);
  return x;
}

/* set byte in 64-bit Ascon word */
#define SETWORD(b, i) (((u64)((b & (0xff << 8*(i&3))) >> 8*(i&3))) << (56 - 8 * (i)))

static inline u64 FASTFLOAD(const u32 word[2]) {
  /*u64 x = SETWORD(word[0],0);
  for (u8 i = 1; i < 8; ++i) {
    x |= SETWORD(word[i>>2], i);
  }
  return x;*/
  u64 	 x  = SETWORD(word[0],0) | SETWORD(word[0],1) | SETWORD(word[0],2) | SETWORD(word[0],3);
  return x |= SETWORD(word[1],4) | SETWORD(word[1],5) | SETWORD(word[1],6) | SETWORD(word[1],7);
}

static inline u64 FASTVLOAD(const u32 word[2], u8 n) {
  u64 x = 0;
  for (u8 i = 0; i < n; ++i) {
    x |= SETWORD(word[i>>2], i);
  }
  return x;
}

#endif /* WORD_H_ */
