// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2021.2 (64-bit)
// Copyright 1986-2021 Xilinx, Inc. All Rights Reserved.
// ==============================================================
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c"
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c" 1
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 147 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c" 2




# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/crypto_aead.h" 1
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/api.h" 1
# 2 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/crypto_aead.h" 2
# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/ascon.h" 1



# 1 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/types.h" 1
# 5 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/ascon.h" 2

typedef unsigned long long int state_t[5];
# 3 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/crypto_aead.h" 2


int crypto_aead_encrypt_c(
        unsigned char c[32 + 16], volatile unsigned long long int* clen,
        volatile unsigned char m[32], unsigned long long int mlen,
        volatile unsigned char ad[32], unsigned long long int adlen,
        volatile unsigned char nsec[0], volatile unsigned char npub[16],
        volatile unsigned char k[16]);
int crypto_aead_encrypt_h(
        unsigned char c[32 + 16], volatile unsigned long long int* clen,
        volatile unsigned char m[32], unsigned long long int mlen,
        volatile unsigned char ad[32], unsigned long long int adlen,
        volatile unsigned char nsec[0], volatile unsigned char npub[16],
        volatile unsigned char k[16]);

int crypto_aead_decrypt_c(
        unsigned char m[32], volatile unsigned long long int* mlen,
        volatile unsigned char nsec[0], volatile unsigned char c[32 + 16],
        unsigned long long int clen, volatile unsigned char ad[32],
        unsigned long long int adlen, volatile unsigned char npub[16],
        volatile unsigned char k[16]);
int crypto_aead_decrypt_h(
        unsigned char m[32], volatile unsigned long long int* mlen,
        volatile unsigned char nsec[0], volatile unsigned char c[32 + 16],
        unsigned long long int clen, volatile unsigned char ad[32],
        unsigned long long int adlen, volatile unsigned char npub[16],
        volatile unsigned char k[16]);
# 6 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c" 2

# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\inttypes.h" 1 3
# 11 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\inttypes.h" 3
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 10 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/_mingw_mac.h" 1 3
# 10 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3
# 277 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 1 3
# 13 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 674 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_directx.h" 1 3
# 674 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3

# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include/sdks/_mingw_ddk.h" 1 3
# 675 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3
# 13 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 2 3


#pragma pack(push,_CRT_PACKING)








 typedef __builtin_va_list __gnuc_va_list;






  typedef __gnuc_va_list va_list;
# 102 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\vadefs.h" 3
#pragma pack(pop)
# 277 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 2 3


#pragma pack(push,_CRT_PACKING)
# 370 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef unsigned long long size_t;
# 380 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long ssize_t;
# 392 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long intptr_t;
# 405 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef unsigned long long uintptr_t;
# 418 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
__extension__ typedef long long ptrdiff_t;
# 428 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef unsigned short wchar_t;







typedef unsigned short wint_t;
typedef unsigned short wctype_t;
# 456 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
typedef int errno_t;




typedef long __time32_t;




__extension__ typedef long long __time64_t;







typedef __time64_t time_t;
# 607 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 3
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
# 11 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\inttypes.h" 2 3

# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stdint.h" 1 3 4
# 33 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stdint.h" 3 4
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 1 3 4
# 28 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdint.h" 3 4
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3 4
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
# 12 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\inttypes.h" 2 3


# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/include\\stddef.h" 1 3 4
# 14 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\inttypes.h" 2 3






typedef struct {
 intmax_t quot;
 intmax_t rem;
 } imaxdiv_t;



# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw_print_push.h" 1 3
# 26 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\inttypes.h" 2 3
# 279 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\inttypes.h" 3
intmax_t __cdecl imaxabs (intmax_t j);




imaxdiv_t __cdecl imaxdiv (intmax_t numer, intmax_t denom);



intmax_t __cdecl strtoimax (const char* __restrict__ nptr,
                            char** __restrict__ endptr, int base);
uintmax_t __cdecl strtoumax (const char* __restrict__ nptr,
        char** __restrict__ endptr, int base);

intmax_t __cdecl wcstoimax (const wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, int base);
uintmax_t __cdecl wcstoumax (const wchar_t* __restrict__ nptr,
        wchar_t** __restrict__ endptr, int base);



# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw_print_pop.h" 1 3
# 299 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\inttypes.h" 2 3
# 8 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c" 2
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 1 3








# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 9 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 2 3


# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw_print_push.h" 1 3
# 11 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 2 3


#pragma pack(push,_CRT_PACKING)
# 26 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 3
 struct _iobuf {
    char *_ptr;
    int _cnt;
    char *_base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char *_tmpfname;
  };
  typedef struct _iobuf FILE;
# 84 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 3
  typedef long _off_t;

  typedef long off_t;






  __extension__ typedef long long _off64_t;

  __extension__ typedef long long off64_t;





  __attribute__ ((__dllimport__)) FILE *__cdecl __iob_func(void);
# 120 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 3
  __extension__ typedef long long fpos_t;
# 157 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 3
  __attribute__ ((__dllimport__)) int __cdecl _filbuf(FILE *_File);
  __attribute__ ((__dllimport__)) int __cdecl _flsbuf(int _Ch,FILE *_File);



  __attribute__ ((__dllimport__)) FILE *__cdecl _fsopen(const char *_Filename,const char *_Mode,int _ShFlag);

  void __cdecl clearerr(FILE *_File);
  int __cdecl fclose(FILE *_File);
  __attribute__ ((__dllimport__)) int __cdecl _fcloseall(void);



  __attribute__ ((__dllimport__)) FILE *__cdecl _fdopen(int _FileHandle,const char *_Mode);

  int __cdecl feof(FILE *_File);
  int __cdecl ferror(FILE *_File);
  int __cdecl fflush(FILE *_File);
  int __cdecl fgetc(FILE *_File);
  __attribute__ ((__dllimport__)) int __cdecl _fgetchar(void);
  int __cdecl fgetpos(FILE * __restrict__ _File ,fpos_t * __restrict__ _Pos);
  char *__cdecl fgets(char * __restrict__ _Buf,int _MaxCount,FILE * __restrict__ _File);
  __attribute__ ((__dllimport__)) int __cdecl _fileno(FILE *_File);



  __attribute__ ((__dllimport__)) char *__cdecl _tempnam(const char *_DirName,const char *_FilePrefix);
  __attribute__ ((__dllimport__)) int __cdecl _flushall(void);
  FILE *__cdecl fopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode) ;
  FILE *fopen64(const char * __restrict__ filename,const char * __restrict__ mode);
  int __cdecl fprintf(FILE * __restrict__ _File,const char * __restrict__ _Format,...);
  int __cdecl fputc(int _Ch,FILE *_File);
  __attribute__ ((__dllimport__)) int __cdecl _fputchar(int _Ch);
  int __cdecl fputs(const char * __restrict__ _Str,FILE * __restrict__ _File);
  size_t __cdecl fread(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);
  FILE *__cdecl freopen(const char * __restrict__ _Filename,const char * __restrict__ _Mode,FILE * __restrict__ _File) ;
  int __cdecl fscanf(FILE * __restrict__ _File,const char * __restrict__ _Format,...) ;
  int __cdecl _fscanf_l(FILE * __restrict__ _File,const char * __restrict__ _Format,_locale_t locale,...) ;
  int __cdecl fsetpos(FILE *_File,const fpos_t *_Pos);
  int __cdecl fseek(FILE *_File,long _Offset,int _Origin);
  int fseeko64(FILE* stream, _off64_t offset, int whence);
  long __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  __extension__ int __cdecl _fseeki64(FILE *_File,long long _Offset,int _Origin);
  __extension__ long long __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(const void * __restrict__ _Str,size_t _Size,size_t _Count,FILE * __restrict__ _File);
  int __cdecl getc(FILE *_File);
  int __cdecl getchar(void);
  __attribute__ ((__dllimport__)) int __cdecl _getmaxstdio(void);
  char *__cdecl gets(char *_Buffer) ;
  int __cdecl _getw(FILE *_File);


  void __cdecl perror(const char *_ErrMsg);

  __attribute__ ((__dllimport__)) int __cdecl _pclose(FILE *_File);
  __attribute__ ((__dllimport__)) FILE *__cdecl _popen(const char *_Command,const char *_Mode);




  int __cdecl printf(const char * __restrict__ _Format,...);
  int __cdecl putc(int _Ch,FILE *_File);
  int __cdecl putchar(int _Ch);
  int __cdecl puts(const char *_Str);
  __attribute__ ((__dllimport__)) int __cdecl _putw(int _Word,FILE *_File);


  int __cdecl remove(const char *_Filename);
  int __cdecl rename(const char *_OldFilename,const char *_NewFilename);
  __attribute__ ((__dllimport__)) int __cdecl _unlink(const char *_Filename);

  int __cdecl unlink(const char *_Filename) ;


  void __cdecl rewind(FILE *_File);
  __attribute__ ((__dllimport__)) int __cdecl _rmtmp(void);
  int __cdecl scanf(const char * __restrict__ _Format,...) ;
  int __cdecl _scanf_l(const char * __restrict__ format,_locale_t locale,... ) ;
  void __cdecl setbuf(FILE * __restrict__ _File,char * __restrict__ _Buffer) ;
  __attribute__ ((__dllimport__)) int __cdecl _setmaxstdio(int _Max);
  __attribute__ ((__dllimport__)) unsigned int __cdecl _set_output_format(unsigned int _Format);
  __attribute__ ((__dllimport__)) unsigned int __cdecl _get_output_format(void);
  unsigned int __cdecl __mingw_set_output_format(unsigned int _Format);
  unsigned int __cdecl __mingw_get_output_format(void);




  int __cdecl setvbuf(FILE * __restrict__ _File,char * __restrict__ _Buf,int _Mode,size_t _Size);
  __attribute__ ((__dllimport__)) int __cdecl _scprintf(const char * __restrict__ _Format,...);
  int __cdecl sscanf(const char * __restrict__ _Src,const char * __restrict__ _Format,...) ;
  int __cdecl _sscanf_l(const char * __restrict__ buffer,const char * __restrict__ format,_locale_t locale,...) ;
  __attribute__ ((__dllimport__)) int __cdecl _snscanf(const char * __restrict__ _Src,size_t _MaxCount,const char * __restrict__ _Format,...) ;
  __attribute__ ((__dllimport__)) int __cdecl _snscanf_l(const char * __restrict__ input,size_t length,const char * __restrict__ format,_locale_t locale,...) ;
  FILE *__cdecl tmpfile(void) ;
  char *__cdecl tmpnam(char *_Buffer);
  int __cdecl ungetc(int _Ch,FILE *_File);
  int __cdecl vfprintf(FILE * __restrict__ _File,const char * __restrict__ _Format,va_list _ArgList);
  int __cdecl vprintf(const char * __restrict__ _Format,va_list _ArgList);


  extern
    __attribute__((__format__ (gnu_printf, 3, 0))) __attribute__ ((__nonnull__ (3)))
    int __cdecl __mingw_vsnprintf(char * __restrict__ _DstBuf,size_t _MaxCount,const char * __restrict__ _Format,
      va_list _ArgList);
  extern
    __attribute__((__format__ (gnu_printf, 3, 4))) __attribute__ ((__nonnull__ (3)))
    int __cdecl __mingw_snprintf(char * __restrict__ s, size_t n, const char * __restrict__ format, ...);
  extern
    __attribute__((__format__ (gnu_printf, 1, 2))) __attribute__ ((__nonnull__ (1)))
    int __cdecl __mingw_printf(const char * __restrict__ , ... ) __attribute__ ((__nothrow__));
  extern
    __attribute__((__format__ (gnu_printf, 1, 0))) __attribute__ ((__nonnull__ (1)))
    int __cdecl __mingw_vprintf (const char * __restrict__ , va_list) __attribute__ ((__nothrow__));
  extern
    __attribute__((__format__ (gnu_printf, 2, 3))) __attribute__ ((__nonnull__ (2)))
    int __cdecl __mingw_fprintf (FILE * __restrict__ , const char * __restrict__ , ...) __attribute__ ((__nothrow__));
  extern
    __attribute__((__format__ (gnu_printf, 2, 0))) __attribute__ ((__nonnull__ (2)))
    int __cdecl __mingw_vfprintf (FILE * __restrict__ , const char * __restrict__ , va_list) __attribute__ ((__nothrow__));
  extern
    __attribute__((__format__ (gnu_printf, 2, 3))) __attribute__ ((__nonnull__ (2)))
    int __cdecl __mingw_sprintf (char * __restrict__ , const char * __restrict__ , ...) __attribute__ ((__nothrow__));
  extern
    __attribute__((__format__ (gnu_printf, 2, 0))) __attribute__ ((__nonnull__ (2)))
    int __cdecl __mingw_vsprintf (char * __restrict__ , const char * __restrict__ , va_list) __attribute__ ((__nothrow__));

  __attribute__ ((__dllimport__)) int __cdecl _snprintf(char * __restrict__ _Dest,size_t _Count,const char * __restrict__ _Format,...) ;
  __attribute__ ((__dllimport__)) int __cdecl _snprintf_l(char * __restrict__ buffer,size_t count,const char * __restrict__ format,_locale_t locale,...) ;
  __attribute__ ((__dllimport__)) int __cdecl _vsnprintf(char * __restrict__ _Dest,size_t _Count,const char * __restrict__ _Format,va_list _Args) ;
  __attribute__ ((__dllimport__)) int __cdecl _vsnprintf_l(char * __restrict__ buffer,size_t count,const char * __restrict__ format,_locale_t locale,va_list argptr) ;
  int __cdecl sprintf(char * __restrict__ _Dest,const char * __restrict__ _Format,...) ;
  int __cdecl _sprintf_l(char * __restrict__ buffer,const char * __restrict__ format,_locale_t locale,...) ;
  int __cdecl vsprintf(char * __restrict__ _Dest,const char * __restrict__ _Format,va_list _Args) ;







  int __cdecl vsnprintf(char * __restrict__ _DstBuf,size_t _MaxCount,const char * __restrict__ _Format,va_list _ArgList) ;

  int __cdecl snprintf(char * __restrict__ s, size_t n, const char * __restrict__ format, ...);
# 312 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 3
  int __cdecl vscanf(const char * __restrict__ Format, va_list argp);
  int __cdecl vfscanf (FILE * __restrict__ fp, const char * __restrict__ Format,va_list argp);
  int __cdecl vsscanf (const char * __restrict__ _Str,const char * __restrict__ Format,va_list argp);

  __attribute__ ((__dllimport__)) int __cdecl _vscprintf(const char * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _set_printf_count_output(int _Value);
  __attribute__ ((__dllimport__)) int __cdecl _get_printf_count_output(void);
# 330 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 3
  __attribute__ ((__dllimport__)) FILE *__cdecl _wfsopen(const wchar_t *_Filename,const wchar_t *_Mode,int _ShFlag);


  wint_t __cdecl fgetwc(FILE *_File);
  __attribute__ ((__dllimport__)) wint_t __cdecl _fgetwchar(void);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  __attribute__ ((__dllimport__)) wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(void);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t * __restrict__ _Dst,int _SizeInWords,FILE * __restrict__ _File);
  int __cdecl fputws(const wchar_t * __restrict__ _Str,FILE * __restrict__ _File);
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _getws(wchar_t *_String) ;
  __attribute__ ((__dllimport__)) int __cdecl _putws(const wchar_t *_Str);
  int __cdecl fwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);
  int __cdecl wprintf(const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __cdecl _scwprintf(const wchar_t * __restrict__ _Format,...);
  int __cdecl vfwprintf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,va_list _ArgList);
  int __cdecl vwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl swprintf(wchar_t * __restrict__ , const wchar_t * __restrict__ , ...) ;
  __attribute__ ((__dllimport__)) int __cdecl _swprintf_l(wchar_t * __restrict__ buffer,size_t count,const wchar_t * __restrict__ format,_locale_t locale,... ) ;
  __attribute__ ((__dllimport__)) int __cdecl vswprintf(wchar_t * __restrict__ , const wchar_t * __restrict__ ,va_list) ;
  __attribute__ ((__dllimport__)) int __cdecl _swprintf_c(wchar_t * __restrict__ _DstBuf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __cdecl _vswprintf_c(wchar_t * __restrict__ _DstBuf,size_t _SizeInWords,const wchar_t * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _snwprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,...) ;
  __attribute__ ((__dllimport__)) int __cdecl _vsnwprintf(wchar_t * __restrict__ _Dest,size_t _Count,const wchar_t * __restrict__ _Format,va_list _Args) ;





  int __cdecl snwprintf (wchar_t * __restrict__ s, size_t n, const wchar_t * __restrict__ format, ...);
  int __cdecl vsnwprintf (wchar_t * __restrict__ , size_t, const wchar_t * __restrict__ , va_list);
# 373 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 3
  int __cdecl vwscanf (const wchar_t * __restrict__ , va_list);
  int __cdecl vfwscanf (FILE * __restrict__ ,const wchar_t * __restrict__ ,va_list);
  int __cdecl vswscanf (const wchar_t * __restrict__ ,const wchar_t * __restrict__ ,va_list);

  __attribute__ ((__dllimport__)) int __cdecl _fwprintf_p(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __cdecl _wprintf_p(const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __cdecl _vfwprintf_p(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _vwprintf_p(const wchar_t * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _swprintf_p(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __cdecl _vswprintf_p(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _scwprintf_p(const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __cdecl _vscwprintf_p(const wchar_t * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _wprintf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __cdecl _wprintf_p_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __cdecl _vwprintf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _vwprintf_p_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _fwprintf_l(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __cdecl _fwprintf_p_l(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __cdecl _vfwprintf_l(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _vfwprintf_p_l(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _swprintf_c_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __cdecl _swprintf_p_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __cdecl _vswprintf_c_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _vswprintf_p_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _scwprintf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __cdecl _scwprintf_p_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __cdecl _vscwprintf_p_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _snwprintf_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  __attribute__ ((__dllimport__)) int __cdecl _vsnwprintf_l(wchar_t * __restrict__ _DstBuf,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList) ;
  __attribute__ ((__dllimport__)) int __cdecl _swprintf(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __cdecl _vswprintf(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,va_list _Args);
  __attribute__ ((__dllimport__)) int __cdecl __swprintf_l(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,_locale_t _Plocinfo,...) ;
  __attribute__ ((__dllimport__)) int __cdecl _vswprintf_l(wchar_t * __restrict__ buffer,size_t count,const wchar_t * __restrict__ format,_locale_t locale,va_list argptr) ;
  __attribute__ ((__dllimport__)) int __cdecl __vswprintf_l(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Format,_locale_t _Plocinfo,va_list _Args) ;
# 417 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 3
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wtempnam(const wchar_t *_Directory,const wchar_t *_FilePrefix);
  __attribute__ ((__dllimport__)) int __cdecl _vscwprintf(const wchar_t * __restrict__ _Format,va_list _ArgList);
  __attribute__ ((__dllimport__)) int __cdecl _vscwprintf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,va_list _ArgList);
  int __cdecl fwscanf(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,...) ;
  __attribute__ ((__dllimport__)) int __cdecl _fwscanf_l(FILE * __restrict__ _File,const wchar_t * __restrict__ _Format,_locale_t _Locale,...) ;
  int __cdecl swscanf(const wchar_t * __restrict__ _Src,const wchar_t * __restrict__ _Format,...) ;
  __attribute__ ((__dllimport__)) int __cdecl _swscanf_l(const wchar_t * __restrict__ _Src,const wchar_t * __restrict__ _Format,_locale_t _Locale,...) ;
  __attribute__ ((__dllimport__)) int __cdecl _snwscanf(const wchar_t * __restrict__ _Src,size_t _MaxCount,const wchar_t * __restrict__ _Format,...);
  __attribute__ ((__dllimport__)) int __cdecl _snwscanf_l(const wchar_t * __restrict__ _Src,size_t _MaxCount,const wchar_t * __restrict__ _Format,_locale_t _Locale,...);
  int __cdecl wscanf(const wchar_t * __restrict__ _Format,...) ;
  __attribute__ ((__dllimport__)) int __cdecl _wscanf_l(const wchar_t * __restrict__ _Format,_locale_t _Locale,...) ;
  __attribute__ ((__dllimport__)) FILE *__cdecl _wfdopen(int _FileHandle ,const wchar_t *_Mode);
  __attribute__ ((__dllimport__)) FILE *__cdecl _wfopen(const wchar_t * __restrict__ _Filename,const wchar_t *__restrict__ _Mode) ;
  __attribute__ ((__dllimport__)) FILE *__cdecl _wfreopen(const wchar_t * __restrict__ _Filename,const wchar_t * __restrict__ _Mode,FILE * __restrict__ _OldFile) ;



  __attribute__ ((__dllimport__)) void __cdecl _wperror(const wchar_t *_ErrMsg);

  __attribute__ ((__dllimport__)) FILE *__cdecl _wpopen(const wchar_t *_Command,const wchar_t *_Mode);




  __attribute__ ((__dllimport__)) int __cdecl _wremove(const wchar_t *_Filename);
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  __attribute__ ((__dllimport__)) wint_t __cdecl _fgetwc_nolock(FILE *_File);
  __attribute__ ((__dllimport__)) wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  __attribute__ ((__dllimport__)) wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);
# 475 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 3
  __attribute__ ((__dllimport__)) void __cdecl _lock_file(FILE *_File);
  __attribute__ ((__dllimport__)) void __cdecl _unlock_file(FILE *_File);
  __attribute__ ((__dllimport__)) int __cdecl _fclose_nolock(FILE *_File);
  __attribute__ ((__dllimport__)) int __cdecl _fflush_nolock(FILE *_File);
  __attribute__ ((__dllimport__)) size_t __cdecl _fread_nolock(void * __restrict__ _DstBuf,size_t _ElementSize,size_t _Count,FILE * __restrict__ _File);
  __attribute__ ((__dllimport__)) int __cdecl _fseek_nolock(FILE *_File,long _Offset,int _Origin);
  __attribute__ ((__dllimport__)) long __cdecl _ftell_nolock(FILE *_File);
  __extension__ __attribute__ ((__dllimport__)) int __cdecl _fseeki64_nolock(FILE *_File,long long _Offset,int _Origin);
  __extension__ __attribute__ ((__dllimport__)) long long __cdecl _ftelli64_nolock(FILE *_File);
  __attribute__ ((__dllimport__)) size_t __cdecl _fwrite_nolock(const void * __restrict__ _DstBuf,size_t _Size,size_t _Count,FILE * __restrict__ _File);
  __attribute__ ((__dllimport__)) int __cdecl _ungetc_nolock(int _Ch,FILE *_File);





  char *__cdecl tempnam(const char *_Directory,const char *_FilePrefix) ;
  int __cdecl fcloseall(void) ;
  FILE *__cdecl fdopen(int _FileHandle,const char *_Format) ;
  int __cdecl fgetchar(void) ;
  int __cdecl fileno(FILE *_File) ;
  int __cdecl flushall(void) ;
  int __cdecl fputchar(int _Ch) ;
  int __cdecl getw(FILE *_File) ;
  int __cdecl putw(int _Ch,FILE *_File) ;
  int __cdecl rmtmp(void) ;






#pragma pack(pop)


# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sec_api/stdio_s.h" 1 3








# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 1 3
# 9 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sec_api/stdio_s.h" 2 3
# 509 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 2 3


# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw_print_pop.h" 1 3
# 511 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\stdio.h" 2 3
# 9 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c" 2
# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 1 3








# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\_mingw.h" 1 3
# 9 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 2 3
# 36 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 3
  __attribute__ ((__dllimport__)) void *__cdecl _memccpy(void *_Dst,const void *_Src,int _Val,size_t _MaxCount);
                void *__cdecl memchr(const void *_Buf ,int _Val,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _memicmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  __attribute__ ((__dllimport__)) int __cdecl _memicmp_l(const void *_Buf1,const void *_Buf2,size_t _Size,_locale_t _Locale);
  int __cdecl memcmp(const void *_Buf1,const void *_Buf2,size_t _Size);
  void *__cdecl memcpy(void * __restrict__ _Dst,const void * __restrict__ _Src,size_t _Size) ;
  void *__cdecl memset(void *_Dst,int _Val,size_t _Size);

  void *__cdecl memccpy(void *_Dst,const void *_Src,int _Val,size_t _Size) ;
  int __cdecl memicmp(const void *_Buf1,const void *_Buf2,size_t _Size) ;


  char *__cdecl _strset(char *_Str,int _Val) ;
  char *__cdecl _strset_l(char *_Str,int _Val,_locale_t _Locale) ;
  char *__cdecl strcpy(char * __restrict__ _Dest,const char * __restrict__ _Source);
  char *__cdecl strcat(char * __restrict__ _Dest,const char * __restrict__ _Source);
  int __cdecl strcmp(const char *_Str1,const char *_Str2);
  size_t __cdecl strlen(const char *_Str);
  size_t __cdecl strnlen(const char *_Str,size_t _MaxCount);
  void *__cdecl memmove(void *_Dst,const void *_Src,size_t _Size) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strdup(const char *_Src);
                char *__cdecl strchr(const char *_Str,int _Val);
  __attribute__ ((__dllimport__)) int __cdecl _stricmp(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _strcmpi(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _stricmp_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  int __cdecl strcoll(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _strcoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _stricoll(const char *_Str1,const char *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _stricoll_l(const char *_Str1,const char *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _strncoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strncoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _strnicoll (const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strnicoll_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  size_t __cdecl strcspn(const char *_Str,const char *_Control);
  __attribute__ ((__dllimport__)) char *__cdecl _strerror(const char *_ErrMsg) ;
  char *__cdecl strerror(int) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strlwr(char *_String) ;
  char *strlwr_l(char *_String,_locale_t _Locale) ;
  char *__cdecl strncat(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) ;
  int __cdecl strncmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strnicmp(const char *_Str1,const char *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _strnicmp_l(const char *_Str1,const char *_Str2,size_t _MaxCount,_locale_t _Locale);
  char *strncpy(char * __restrict__ _Dest,const char * __restrict__ _Source,size_t _Count) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strnset(char *_Str,int _Val,size_t _MaxCount) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strnset_l(char *str,int c,size_t count,_locale_t _Locale) ;
                char *__cdecl strpbrk(const char *_Str,const char *_Control);
                char *__cdecl strrchr(const char *_Str,int _Ch);
  __attribute__ ((__dllimport__)) char *__cdecl _strrev(char *_Str);
  size_t __cdecl strspn(const char *_Str,const char *_Control);
                char *__cdecl strstr(const char *_Str,const char *_SubStr);
  char *__cdecl strtok(char * __restrict__ _Str,const char * __restrict__ _Delim) ;
  __attribute__ ((__dllimport__)) char *__cdecl _strupr(char *_String) ;
  __attribute__ ((__dllimport__)) char *_strupr_l(char *_String,_locale_t _Locale) ;
  size_t __cdecl strxfrm(char * __restrict__ _Dst,const char * __restrict__ _Src,size_t _MaxCount);
  __attribute__ ((__dllimport__)) size_t __cdecl _strxfrm_l(char * __restrict__ _Dst,const char * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);


  char *__cdecl strdup(const char *_Src) ;
  int __cdecl strcmpi(const char *_Str1,const char *_Str2) ;
  int __cdecl stricmp(const char *_Str1,const char *_Str2) ;
  char *__cdecl strlwr(char *_Str) ;
  int __cdecl strnicmp(const char *_Str1,const char *_Str,size_t _MaxCount) ;
  int __cdecl strncasecmp (const char *, const char *, size_t);
  int __cdecl strcasecmp (const char *, const char *);







  char *__cdecl strnset(char *_Str,int _Val,size_t _MaxCount) ;
  char *__cdecl strrev(char *_Str) ;
  char *__cdecl strset(char *_Str,int _Val) ;
  char *__cdecl strupr(char *_Str) ;





  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsdup(const wchar_t *_Str);
  wchar_t *__cdecl wcscat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) ;
                wchar_t *__cdecl wcschr(const wchar_t *_Str,wchar_t _Ch);
  int __cdecl wcscmp(const wchar_t *_Str1,const wchar_t *_Str2);
  wchar_t *__cdecl wcscpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source) ;
  size_t __cdecl wcscspn(const wchar_t *_Str,const wchar_t *_Control);
  size_t __cdecl wcslen(const wchar_t *_Str);
  size_t __cdecl wcsnlen(const wchar_t *_Src,size_t _MaxCount);
  wchar_t *wcsncat(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) ;
  int __cdecl wcsncmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  wchar_t *wcsncpy(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count) ;
  wchar_t *__cdecl _wcsncpy_l(wchar_t * __restrict__ _Dest,const wchar_t * __restrict__ _Source,size_t _Count,_locale_t _Locale) ;
                wchar_t *__cdecl wcspbrk(const wchar_t *_Str,const wchar_t *_Control);
                wchar_t *__cdecl wcsrchr(const wchar_t *_Str,wchar_t _Ch);
  size_t __cdecl wcsspn(const wchar_t *_Str,const wchar_t *_Control);
                wchar_t *__cdecl wcsstr(const wchar_t *_Str,const wchar_t *_SubStr);
  wchar_t *__cdecl wcstok(wchar_t * __restrict__ _Str,const wchar_t * __restrict__ _Delim) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcserror(int _ErrNum) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl __wcserror(const wchar_t *_Str) ;
  __attribute__ ((__dllimport__)) int __cdecl _wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _wcsicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicmp_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsrev(wchar_t *_Str);
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsset(wchar_t *_Str,wchar_t _Val) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcslwr(wchar_t *_String) ;
  __attribute__ ((__dllimport__)) wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale) ;
  __attribute__ ((__dllimport__)) wchar_t *__cdecl _wcsupr(wchar_t *_String) ;
  __attribute__ ((__dllimport__)) wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale) ;
  size_t __cdecl wcsxfrm(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount);
  __attribute__ ((__dllimport__)) size_t __cdecl _wcsxfrm_l(wchar_t * __restrict__ _Dst,const wchar_t * __restrict__ _Src,size_t _MaxCount,_locale_t _Locale);
  int __cdecl wcscoll(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _wcscoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2);
  __attribute__ ((__dllimport__)) int __cdecl _wcsicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsncoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _wcsncoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicoll(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount);
  __attribute__ ((__dllimport__)) int __cdecl _wcsnicoll_l(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);


  wchar_t *__cdecl wcsdup(const wchar_t *_Str) ;

  int __cdecl wcsicmp(const wchar_t *_Str1,const wchar_t *_Str2) ;
  int __cdecl wcsnicmp(const wchar_t *_Str1,const wchar_t *_Str2,size_t _MaxCount) ;
  wchar_t *__cdecl wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount) ;
  wchar_t *__cdecl wcsrev(wchar_t *_Str) ;
  wchar_t *__cdecl wcsset(wchar_t *_Str,wchar_t _Val) ;
  wchar_t *__cdecl wcslwr(wchar_t *_Str) ;
  wchar_t *__cdecl wcsupr(wchar_t *_Str) ;
  int __cdecl wcsicoll(const wchar_t *_Str1,const wchar_t *_Str2) ;








# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sec_api/string_s.h" 1 3








# 1 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 1 3
# 9 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\sec_api/string_s.h" 2 3
# 175 "C:/Xilinx/Vitis_HLS/2021.2/win64/tools/clang/bin/../lib/clang/3.1/../../../x86_64-w64-mingw32/include\\string.h" 2 3
# 10 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c" 2
# 28 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c"
void init_buffer(unsigned char *buffer, unsigned long long numbytes);

void fprint_bstr(FILE *fp, const char *label, const unsigned char *data,
                 unsigned long long length);

int generate_test_vectors();

int main() {
  int ret = generate_test_vectors();
  if (ret != 0) {
    fprintf((&__iob_func()[2]), "test vector generation failed with code %d\n", ret);
  }
  return ret;
}

#ifndef HLS_FASTSIM
#ifdef __cplusplus
extern "C"
#endif
int apatb_crypto_aead_decrypt_c_sw(unsigned char *, volatile unsigned long long *, volatile unsigned char *, volatile unsigned char *, unsigned long long, volatile unsigned char *, unsigned long long, volatile unsigned char *, volatile unsigned char *);
# 43 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c"
int generate_test_vectors() {
  FILE *fp;
  char fileName[256];
  unsigned char key[16];
  unsigned char nonce[16];
  unsigned char msg[32];
  unsigned char msg2[32];
  unsigned char ad[32];
  unsigned char ct[32 + 16];
  unsigned long long clen, mlen2;
  int count = 1;
  int func_ret, ret_val = 0;

  init_buffer(key, sizeof(key));
  init_buffer(nonce, sizeof(nonce));
  init_buffer(msg, sizeof(msg));
  init_buffer(ad, sizeof(ad));
  sprintf(fileName, "LWC_AEAD_KAT_%d_%d.txt", (16 * 8),
          (16 * 8));
  if ((fp = fopen(fileName, "w")) == ((void*)0)) {
    fprintf((&__iob_func()[2]), "Couldn't open <%s> for write\n", fileName);
    return -1;
  }

  for (unsigned long long mlen = 0;
       (mlen <= 32) && (ret_val == 0); mlen++) {
    for (unsigned long long adlen = 0; adlen <= 32;
         adlen++) {
      fprintf(fp, "Count = %d\n", count++);
      fprint_bstr(fp, "Key = ", key, 16);
      fprint_bstr(fp, "Nonce = ", nonce, 16);
      fprint_bstr(fp, "PT = ", msg, mlen);
      fprint_bstr(fp, "AD = ", ad, adlen);
      if ((func_ret = crypto_aead_encrypt_c(ct, &clen, msg, mlen, ad, adlen, ((void*)0),
                                          nonce, key)) != 0) {
        fprintf(fp, "crypto_aead_encrypt returned <%d>\n", func_ret);
        ret_val = -4;
        break;
      }
      fprint_bstr(fp, "CT = ", ct, clen);
      fprintf(fp, "\n");
      if ((func_ret = 
#ifndef HLS_FASTSIM
#define crypto_aead_decrypt_c apatb_crypto_aead_decrypt_c_sw
#endif
# 84 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c"
crypto_aead_decrypt_c(msg2, &mlen2, ((void*)0), ct, clen, ad,
                                          adlen, nonce, key))
#undef crypto_aead_decrypt_c
# 84 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c"
 != 0) {
        fprintf(fp, "crypto_aead_decrypt returned <%d>\n", func_ret);
        ret_val = -4;
        break;
      }
      if (mlen != mlen2) {
        fprintf(fp,
                "crypto_aead_decrypt returned bad 'mlen': Got <%" "I64u"
                ">, expected <%" "I64u" ">\n",
                (uint64_t)mlen2, (uint64_t)mlen);
        ret_val = -4;
        break;
      }
      if (memcmp(msg, msg2, mlen)) {
        fprintf(fp, "crypto_aead_decrypt did not recover the plaintext\n");
        ret_val = -4;
        break;
      }
    }
  }
  fclose(fp);
  return ret_val;
}
#endif
# 107 "H:/home/Documents/Git/PII-2022-Grazzani-Rogora-Zaffiretti/src-v3/original_genkat_aead.c"


void fprint_bstr(FILE *fp, const char *label, const unsigned char *data,
                 unsigned long long length) {
 fprintf(fp, "%s", label);
 for (unsigned long long i = 0; i < length; i++) fprintf(fp, "%02X", data[i]);
 fprintf(fp, "\n");
}

void init_buffer(unsigned char *buffer, unsigned long long numbytes) {
  for (unsigned long long i = 0; i < numbytes; i++)
    buffer[i] = (unsigned char)i;
}
