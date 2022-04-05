// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/aead.c"
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/aead.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/aead.c" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/api.h" 1
# 2 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/aead.c" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/ascon.h" 1



# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/types.h" 1
# 5 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/ascon.h" 2

typedef unsigned long long int state_t[5];
# 3 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/aead.c" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/crypto_aead.h" 1
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/api.h" 1
# 2 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/crypto_aead.h" 2



int crypto_aead_encrypt_c(unsigned char c[32 + 16], volatile unsigned long long int* clen,
      volatile unsigned char m[32], unsigned long long int mlen,
      volatile unsigned char ad[32], unsigned long long int adlen,
      volatile unsigned char nsec[0], volatile unsigned char npub[16],
      volatile unsigned char k[16], unsigned long long int st[5]);
int crypto_aead_encrypt_h(unsigned char c[32 + 16], volatile unsigned long long int* clen,
      volatile unsigned char m[32], unsigned long long int mlen,
      volatile unsigned char ad[32], unsigned long long int adlen,
      volatile unsigned char nsec[0], volatile unsigned char npub[16],
      volatile unsigned char k[16], unsigned long long int st[5]);

int crypto_aead_decrypt(unsigned char* m, unsigned long long* mlen,
                        unsigned char* nsec, const unsigned char* c,
                        unsigned long long clen, const unsigned char* ad,
                        unsigned long long adlen, const unsigned char* npub,
                        const unsigned char* k, unsigned long long int st[5]);
# 4 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/aead.c" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/permutations.h" 1



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
# 5 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/permutations.h" 2


# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/constants.h" 1
# 8 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/permutations.h" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/printstate.h" 1
# 9 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/permutations.h" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/round.h" 1






static inline unsigned long long int ROR(unsigned long long int x, int n) {
  return x >> n | x << (-n & 63);
}

static inline void ROUND(unsigned long long int s[5], unsigned char C) {
  unsigned long long int t[5];

  s[2] ^= C;


  s[0] ^= s[4];
  s[4] ^= s[3];
  s[2] ^= s[1];

  t[0] = s[0] ^ (~s[1] & s[2]);
  t[1] = s[1] ^ (~s[2] & s[3]);
  t[2] = s[2] ^ (~s[3] & s[4]);
  t[3] = s[3] ^ (~s[4] & s[0]);
  t[4] = s[4] ^ (~s[0] & s[1]);

  t[1] ^= t[0];
  t[0] ^= t[4];
  t[3] ^= t[2];
  t[2] = ~t[2];


  s[0] = t[0] ^ ROR(t[0], 19) ^ ROR(t[0], 28);
  s[1] = t[1] ^ ROR(t[1], 61) ^ ROR(t[1], 39);
  s[2] = t[2] ^ ROR(t[2], 1) ^ ROR(t[2], 6);
  s[3] = t[3] ^ ROR(t[3], 10) ^ ROR(t[3], 17);
  s[4] = t[4] ^ ROR(t[4], 7) ^ ROR(t[4], 41);
  do { } while (0);
}
# 10 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/permutations.h" 2

static inline void P12(unsigned long long int s[5]) {
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

static inline void P8(unsigned long long int s[5]) {
  ROUND(s, 0xb4);
  ROUND(s, 0xa5);
  ROUND(s, 0x96);
  ROUND(s, 0x87);
  ROUND(s, 0x78);
  ROUND(s, 0x69);
  ROUND(s, 0x5a);
  ROUND(s, 0x4b);
}

static inline void P6(unsigned long long int s[5]) {
  ROUND(s, 0x96);
  ROUND(s, 0x87);
  ROUND(s, 0x78);
  ROUND(s, 0x69);
  ROUND(s, 0x5a);
  ROUND(s, 0x4b);
}
# 5 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/aead.c" 2

# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/word.h" 1







typedef uint64_t uint64_t;
# 20 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/word.h"
static inline unsigned long long int LOADBYTES(volatile const unsigned char bytes[8], int n) {
 unsigned long long int x = 0;
  for (int i = 0; i < n; ++i) x |= ((unsigned long long int)(bytes[i]) << (56 - 8 * (i)));
  return x;
}


static inline void STOREBYTES(volatile unsigned char bytes[8], unsigned long long int x, int n) {
  for (int i = 0; i < n; ++i) bytes[i] = ((unsigned char)((unsigned long long int)(x) >> (56 - 8 * (i))));
}


static inline unsigned long long int CLEARBYTES(unsigned long long int x, int n) {
  for (int i = 0; i < n; ++i) x &= ~((unsigned long long int)(0xff) << (56 - 8 * (i)));
  return x;
}
# 7 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/aead.c" 2






void copyState(volatile unsigned long long int a[5], volatile unsigned long long int b[5]){
    for(int i=0; i<5; i++){
        b[i] = a[i];
    }
}

int crypto_aead_encrypt(unsigned char c[32 + 16], volatile unsigned long long int* clen,
  volatile unsigned char m[32], unsigned long long int mlen,
  volatile unsigned char ad[32], unsigned long long int adlen,
  volatile unsigned char nsec[0], volatile unsigned char npub[16],
  volatile unsigned char k[16], unsigned long long int st[5]);

int crypto_aead_encrypt_c(unsigned char c[32 + 16], volatile unsigned long long int* clen,
  volatile unsigned char m[32], unsigned long long int mlen,
  volatile unsigned char ad[32], unsigned long long int adlen,
  volatile unsigned char nsec[0], volatile unsigned char npub[16],
  volatile unsigned char k[16], unsigned long long int st[5]){
 return crypto_aead_encrypt(c, clen, m, mlen, ad, adlen, nsec, npub, k, st);
}
int crypto_aead_encrypt_h(unsigned char c[32 + 16], volatile unsigned long long int* clen,
  volatile unsigned char m[32], unsigned long long int mlen,
  volatile unsigned char ad[32], unsigned long long int adlen,
  volatile unsigned char nsec[0], volatile unsigned char npub[16],
  volatile unsigned char k[16], unsigned long long int st[5]){
 return crypto_aead_encrypt(c, clen, m, mlen, ad, adlen, nsec, npub, k, st);
}
#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
int apatb_crypto_aead_encrypt_h_ir(unsigned char *, volatile unsigned long long *, volatile unsigned char *, unsigned long long, volatile unsigned char *, unsigned long long, volatile unsigned char *, volatile unsigned char *, volatile unsigned char *, unsigned long long *);
#ifdef __cplusplus
extern "C"
#endif
int crypto_aead_encrypt_h_hw_stub(unsigned char *c, volatile unsigned long long *clen, volatile unsigned char *m, unsigned long long mlen, volatile unsigned char *ad, unsigned long long adlen, volatile unsigned char *nsec, volatile unsigned char *npub, volatile unsigned char *k, unsigned long long *st){
int _ret = crypto_aead_encrypt_h(c, clen, m, mlen, ad, adlen, nsec, npub, k, st);
return _ret;
}
#ifdef __cplusplus
extern "C"
#endif
int apatb_crypto_aead_encrypt_h_sw(unsigned char *c, volatile unsigned long long *clen, volatile unsigned char *m, unsigned long long mlen, volatile unsigned char *ad, unsigned long long adlen, volatile unsigned char *nsec, volatile unsigned char *npub, volatile unsigned char *k, unsigned long long *st){
int _ret = apatb_crypto_aead_encrypt_h_ir(c, clen, m, mlen, ad, adlen, nsec, npub, k, st);
return _ret;
}
#endif
# 38 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/aead.c"


int crypto_aead_encrypt(unsigned char c[32 + 16], volatile unsigned long long int* clen,
  volatile unsigned char m[32], unsigned long long int mlen,
  volatile unsigned char ad[32], unsigned long long int adlen,
  volatile unsigned char nsec[0], volatile unsigned char npub[16],
  volatile unsigned char k[16], unsigned long long int st[5]) {
    (void)nsec;


    *clen = mlen + 16;


    const unsigned long long int K0 = LOADBYTES(k, 8);
    const unsigned long long int K1 = LOADBYTES(&k[8], 8);
    const unsigned long long int N0 = LOADBYTES(npub, 8);
    const unsigned long long int N1 = LOADBYTES(&npub[8], 8);


    unsigned long long int s[5];
    s[0] = (((unsigned long long int)(16 * 8) << 56) | ((unsigned long long int)(8 * 8) << 48) | ((unsigned long long int)(12) << 40) | ((unsigned long long int)(6) << 32));
    s[1] = K0;
    s[2] = K1;
    s[3] = N0;
    s[4] = N1;



    do { } while (0);
    P12(s);
    s[3] ^= K0;
    s[4] ^= K1;



    do { } while (0);

    if (adlen) {

        while (adlen >= 8) {
        s[0] ^= LOADBYTES(ad, 8);



    do { } while (0);
        P6(s);
        ad += 8;
        adlen -= 8;
        }

        s[0] ^= LOADBYTES(ad, adlen);
        s[0] ^= ((unsigned long long int)(0x80) << (56 - 8 * (adlen)));



    do { } while (0);
        P6(s);
    }

    s[4] ^= 1;



    do { } while (0);


    while (mlen >= 8) {
        s[0] ^= LOADBYTES(m, 8);
        STOREBYTES(c, s[0], 8);



    do { } while (0);
        P6(s);
        m += 8;
        c += 8;
        mlen -= 8;
    }

    s[0] ^= LOADBYTES(m, mlen);
    STOREBYTES(c, s[0], mlen);
    s[0] ^= ((unsigned long long int)(0x80) << (56 - 8 * (mlen)));
    c += mlen;



    do { } while (0);


    s[1] ^= K0;
    s[2] ^= K1;



    do { } while (0);
    P12(s);
    s[3] ^= K0;
    s[4] ^= K1;



    do { } while (0);


    STOREBYTES(c, s[3], 8);
    STOREBYTES(c + 8, s[4], 8);

    return 0;
}

int crypto_aead_decrypt(unsigned char* m, unsigned long long* mlen,
                        unsigned char* nsec, const unsigned char* c,
                        unsigned long long clen, const unsigned char* ad,
                        unsigned long long adlen, const unsigned char* npub,
                        const unsigned char* k, unsigned long long int st[5]) {
    (void)nsec;

    if (clen < 16) return -1;


    *mlen = clen - 16;


    const unsigned long long int K0 = LOADBYTES(k, 8);
    const unsigned long long int K1 = LOADBYTES(k + 8, 8);
    const unsigned long long int N0 = LOADBYTES(npub, 8);
    const unsigned long long int N1 = LOADBYTES(npub + 8, 8);


    unsigned long long int s[5];
    s[0] = (((unsigned long long int)(16 * 8) << 56) | ((unsigned long long int)(8 * 8) << 48) | ((unsigned long long int)(12) << 40) | ((unsigned long long int)(6) << 32));
    s[1] = K0;
    s[2] = K1;
    s[3] = N0;
    s[4] = N1;



    do { } while (0);
    P12(s);
    s[3] ^= K0;
    s[4] ^= K1;



    do { } while (0);

    if (adlen) {

        while (adlen >= 8) {
        s[0] ^= LOADBYTES(ad, 8);



    do { } while (0);
        P6(s);
        ad += 8;
        adlen -= 8;
        }

        s[0] ^= LOADBYTES(ad, adlen);
        s[0] ^= ((unsigned long long int)(0x80) << (56 - 8 * (adlen)));



    do { } while (0);
        P6(s);
    }

    s[4] ^= 1;



    do { } while (0);


    clen -= 16;
    while (clen >= 8) {
        unsigned long long int c0 = LOADBYTES(c, 8);
        STOREBYTES(m, s[0] ^ c0, 8);
        s[0] = c0;
        do { } while (0);
        P6(s);
        m += 8;
        c += 8;
        clen -= 8;
    }

    unsigned long long int c0 = LOADBYTES(c, clen);
    STOREBYTES(m, s[0] ^ c0, clen);
    s[0] = CLEARBYTES(s[0], clen);
    s[0] |= c0;
    s[0] ^= ((unsigned long long int)(0x80) << (56 - 8 * (clen)));
    c += clen;



    do { } while (0);


    s[1] ^= K0;
    s[2] ^= K1;



    do { } while (0);
    P12(s);
    s[3] ^= K0;
    s[4] ^= K1;



    do { } while (0);


    unsigned char t[16];
    STOREBYTES(t, s[3], 8);
    STOREBYTES(t + 8, s[4], 8);


    int result = 0;
    for (int i = 0; i < 16; ++i) result |= c[i] ^ t[i];
    result = (((result - 1) >> 8) & 1) - 1;

    return result;
}
