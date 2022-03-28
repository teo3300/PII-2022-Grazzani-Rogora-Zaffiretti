// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c"
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c" 2
# 12 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c"
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stdint.h" 1 3 4
# 33 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stdint.h" 3 4
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 1 3 4
# 28 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 3 4
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3 4
# 10 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/_mingw_mac.h" 1 3 4
# 10 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3 4
# 277 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 1 3 4
# 13 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3 4
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3 4
# 674 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_directx.h" 1 3 4
# 674 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3 4

# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_ddk.h" 1 3 4
# 675 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3 4
# 13 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 2 3 4


#pragma pack(push,_CRT_PACKING)








 typedef __builtin_va_list __gnuc_va_list;






  typedef __gnuc_va_list va_list;
# 102 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3 4
#pragma pack(pop)
# 277 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3 4


#pragma pack(push,_CRT_PACKING)
# 370 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
__extension__ typedef unsigned long long size_t;
# 380 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
__extension__ typedef long long ssize_t;
# 392 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
__extension__ typedef long long intptr_t;
# 405 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
__extension__ typedef unsigned long long uintptr_t;
# 418 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
__extension__ typedef long long ptrdiff_t;
# 428 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
typedef unsigned short wchar_t;







typedef unsigned short wint_t;
typedef unsigned short wctype_t;
# 456 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
typedef int errno_t;




typedef long __time32_t;




__extension__ typedef long long __time64_t;







typedef __time64_t time_t;
# 607 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3 4
struct threadlocaleinfostruct;
struct threadmbcinfostruct;
typedef struct threadlocaleinfostruct *pthreadlocinfo;
typedef struct threadmbcinfostruct *pthreadmbcinfo;
struct __lc_time_data;

typedef struct localeinfo_struct {
  pthreadlocinfo locinfo;
  pthreadmbcinfo mbcinfo;
} _locale_tstruct,*_locale_t;



typedef struct tagLC_ID {
  unsigned short wLanguage;
  unsigned short wCountry;
  unsigned short wCodePage;
} LC_ID,*LPLC_ID;




typedef struct threadlocaleinfostruct {
  int refcount;
  unsigned int lc_codepage;
  unsigned int lc_collate_cp;
  unsigned long lc_handle[6];
  LC_ID lc_id[6];
  struct {
    char *locale;
    wchar_t *wlocale;
    int *refcount;
    int *wrefcount;
  } lc_category[6];
  int lc_clike;
  int mb_cur_max;
  int *lconv_intl_refcount;
  int *lconv_num_refcount;
  int *lconv_mon_refcount;
  struct lconv *lconv;
  int *ctype1_refcount;
  unsigned short *ctype1;
  const unsigned short *pctype;
  const unsigned char *pclmap;
  const unsigned char *pcumap;
  struct __lc_time_data *lc_time_curr;
} threadlocinfo;







const char *__mingw_get_crt_info (void);





#pragma pack(pop)
# 28 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 2 3 4




# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stddef.h" 1 3 4
# 31 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stddef.h" 3 4
typedef __typeof__(((int*)0)-((int*)0)) ptrdiff_t;



typedef __typeof__(sizeof(int)) size_t;




typedef unsigned short wchar_t;
# 32 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 2 3 4



typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned uint32_t;
__extension__ typedef long long int64_t;
__extension__ typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef int int_least32_t;
typedef unsigned uint_least32_t;
__extension__ typedef long long int_least64_t;
__extension__ typedef unsigned long long uint_least64_t;





typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;
typedef short int_fast16_t;
typedef unsigned short uint_fast16_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
__extension__ typedef long long int_fast64_t;
__extension__ typedef unsigned long long uint_fast64_t;


__extension__ typedef long long intmax_t;
__extension__ typedef unsigned long long uintmax_t;
# 33 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stdint.h" 2 3 4
# 13 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c" 2

typedef struct {
  uint64_t x0, x1, x2, x3, x4;
} state_t;



int crypto_aead_encrypt(unsigned char *c, unsigned long long *clen,
                        const unsigned char *m, unsigned long long mlen,
                        const unsigned char *ad, unsigned long long adlen,
                        const unsigned char *nsec, const unsigned char *npub,
                        const unsigned char *k);

int crypto_aead_decrypt(unsigned char *m, unsigned long long *mlen,
                        unsigned char *nsec, const unsigned char *c,
                        unsigned long long clen, const unsigned char *ad,
                        unsigned long long adlen, const unsigned char *npub,
                        const unsigned char *k);
# 40 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c"
static inline uint64_t ROR(uint64_t x, int n) {
  return (x << (64 - n)) | (x >> n);
}

static inline void ROUND(state_t* s, uint8_t C) {
  state_t t;

  s->x2 ^= C;


  s->x0 ^= s->x4;
  s->x4 ^= s->x3;
  s->x2 ^= s->x1;

  t.x0 = s->x0 ^ (~s->x1 & s->x2);
  t.x1 = s->x1 ^ (~s->x2 & s->x3);
  t.x2 = s->x2 ^ (~s->x3 & s->x4);
  t.x3 = s->x3 ^ (~s->x4 & s->x0);
  t.x4 = s->x4 ^ (~s->x0 & s->x1);

  t.x1 ^= t.x0;
  t.x0 ^= t.x4;
  t.x3 ^= t.x2;
  t.x2 = ~t.x2;


  s->x0 = t.x0 ^ ROR(t.x0, 19) ^ ROR(t.x0, 28);
  s->x1 = t.x1 ^ ROR(t.x1, 61) ^ ROR(t.x1, 39);
  s->x2 = t.x2 ^ ROR(t.x2, 1) ^ ROR(t.x2, 6);
  s->x3 = t.x3 ^ ROR(t.x3, 10) ^ ROR(t.x3, 17);
  s->x4 = t.x4 ^ ROR(t.x4, 7) ^ ROR(t.x4, 41);

}
# 139 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c"
static inline void P12(state_t* s) {

  ROUND(s, 0xf0);
  ROUND(s, 0xe1);
  ROUND(s, 0xd2);
  ROUND(s, 0xc3);
  ROUND(s, 0xb4);
  ROUND(s, 0xa5);
  ROUND(s, 0x96);
  ROUND(s, 0x87);
  ROUND(s, 0x78);
  ROUND(s, 0x69);
  ROUND(s, 0x5a);
  ROUND(s, 0x4b);
}

static inline void P8(state_t* s) {

  ROUND(s, 0xb4);
  ROUND(s, 0xa5);
  ROUND(s, 0x96);
  ROUND(s, 0x87);
  ROUND(s, 0x78);
  ROUND(s, 0x69);
  ROUND(s, 0x5a);
  ROUND(s, 0x4b);
}

static inline void P6(state_t* s) {

  ROUND(s, 0x96);
  ROUND(s, 0x87);
  ROUND(s, 0x78);
  ROUND(s, 0x69);
  ROUND(s, 0x5a);
  ROUND(s, 0x4b);
}
# 210 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c"
typedef uint64_t word_t;
# 222 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src/crypto_aead/ascon128v12/ref/decrypt.c"
static inline uint64_t LOADBYTES(const uint8_t* bytes, int n) {
  uint64_t x = 0;
  for (int i = 0; i < n; ++i) x |= ((uint64_t)(bytes[i]) << (56 - 8 * (i)));
  return x;
}


static inline void STOREBYTES(uint8_t* bytes, uint64_t x, int n) {
  for (int i = 0; i < n; ++i) bytes[i] = ((uint8_t)((uint64_t)(x) >> (56 - 8 * (i))));
}


static inline uint64_t CLEARBYTES(uint64_t x, int n) {
  for (int i = 0; i < n; ++i) x &= ~((uint64_t)(0xff) << (56 - 8 * (i)));
  return x;
}



int crypto_aead_decrypt(unsigned char* m, unsigned long long* mlen,
                        unsigned char* nsec, const unsigned char* c,
                        unsigned long long clen, const unsigned char* ad,
                        unsigned long long adlen, const unsigned char* npub,
                        const unsigned char* k) {
  (void)nsec;

  if (clen < 16) return -1;


  *mlen = clen - 16;


  const uint64_t K0 = LOADBYTES(k, 8);
  const uint64_t K1 = LOADBYTES(k + 8, 8);
  const uint64_t N0 = LOADBYTES(npub, 8);
  const uint64_t N1 = LOADBYTES(npub + 8, 8);


  state_t s;
  s.x0 = (((uint64_t)(16 * 8) << 56) | ((uint64_t)(8 * 8) << 48) | ((uint64_t)(12) << 40) | ((uint64_t)(6) << 32));
  s.x1 = K0;
  s.x2 = K1;
  s.x3 = N0;
  s.x4 = N1;
  P12(&s);
  s.x3 ^= K0;
  s.x4 ^= K1;


  if (adlen) {

    while (adlen >= 8) {
      s.x0 ^= LOADBYTES(ad, 8);
      P6(&s);
      ad += 8;
      adlen -= 8;
    }

    s.x0 ^= LOADBYTES(ad, adlen);
    s.x0 ^= ((uint64_t)(0x80) << (56 - 8 * (adlen)));
    P6(&s);
  }

  s.x4 ^= 1;



  clen -= 16;
  while (clen >= 8) {
    uint64_t c0 = LOADBYTES(c, 8);
    STOREBYTES(m, s.x0 ^ c0, 8);
    s.x0 = c0;
    P6(&s);
    m += 8;
    c += 8;
    clen -= 8;
  }

  uint64_t c0 = LOADBYTES(c, clen);
  STOREBYTES(m, s.x0 ^ c0, clen);
  s.x0 = CLEARBYTES(s.x0, clen);
  s.x0 |= c0;
  s.x0 ^= ((uint64_t)(0x80) << (56 - 8 * (clen)));
  c += clen;



  s.x1 ^= K0;
  s.x2 ^= K1;
  P12(&s);
  s.x3 ^= K0;
  s.x4 ^= K1;



  uint8_t t[16];
  STOREBYTES(t, s.x3, 8);
  STOREBYTES(t + 8, s.x4, 8);


  int result = 0;
  for (int i = 0; i < 16; ++i) result |= c[i] ^ t[i];
  result = (((result - 1) >> 8) & 1) - 1;

  return result;
}
