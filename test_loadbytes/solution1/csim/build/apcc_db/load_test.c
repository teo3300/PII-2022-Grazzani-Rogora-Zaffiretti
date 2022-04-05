/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void copyState(signed long long *llvm_cbe_a, signed long long *llvm_cbe_b);
void load_test_c( char *llvm_cbe_k,  char *llvm_cbe_npub, signed long long *llvm_cbe_st);
void load_test( char *llvm_cbe_k,  char *llvm_cbe_npub, signed long long *llvm_cbe_st);
void load_test_h( char *llvm_cbe_k,  char *llvm_cbe_npub, signed long long *llvm_cbe_st);
static signed long long aesl_internal_LOADBYTES( char *llvm_cbe_bytes);


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void copyState(signed long long *llvm_cbe_a, signed long long *llvm_cbe_b) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  signed long long *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  signed long long *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  signed long long *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  unsigned long long llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  signed long long *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  signed long long *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  unsigned long long llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  signed long long *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  signed long long *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  unsigned long long llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  signed long long *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @copyState\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i64* %%a, align 8, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__1 = (unsigned long long )*llvm_cbe_a;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%1, i64* %%b, align 8, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_11_count);
  *llvm_cbe_b = llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i64* %%a, i64 1, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__2 = (signed long long *)(&llvm_cbe_a[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%2, align 8, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__3 = (unsigned long long )*llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i64* %%b, i64 1, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__4 = (signed long long *)(&llvm_cbe_b[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%3, i64* %%4, align 8, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_20_count);
  *llvm_cbe_tmp__4 = llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i64* %%a, i64 2, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_26_count);
  llvm_cbe_tmp__5 = (signed long long *)(&llvm_cbe_a[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_27_count);
  llvm_cbe_tmp__6 = (unsigned long long )*llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds i64* %%b, i64 2, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__7 = (signed long long *)(&llvm_cbe_b[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%6, i64* %%7, align 8, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_29_count);
  *llvm_cbe_tmp__7 = llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i64* %%a, i64 3, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__8 = (signed long long *)(&llvm_cbe_a[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = load i64* %%8, align 8, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__9 = (unsigned long long )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds i64* %%b, i64 3, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__10 = (signed long long *)(&llvm_cbe_b[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%9, i64* %%10, align 8, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_38_count);
  *llvm_cbe_tmp__10 = llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds i64* %%a, i64 4, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__11 = (signed long long *)(&llvm_cbe_a[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = load i64* %%11, align 8, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__12 = (unsigned long long )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds i64* %%b, i64 4, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__13 = (signed long long *)(&llvm_cbe_b[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%12, i64* %%13, align 8, !dbg !5 for 0x%I64xth hint within @copyState  --> \n", ++aesl_llvm_cbe_47_count);
  *llvm_cbe_tmp__13 = llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__12);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @copyState}\n");
  return;
}


void load_test_c( char *llvm_cbe_k,  char *llvm_cbe_npub, signed long long *llvm_cbe_st) {
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @load_test_c\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @load_test(i8* %%k, i8* %%npub, i64* %%st), !dbg !5 for 0x%I64xth hint within @load_test_c  --> \n", ++aesl_llvm_cbe_60_count);
   /*tail*/ load_test(( char *)llvm_cbe_k, ( char *)llvm_cbe_npub, (signed long long *)llvm_cbe_st);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @load_test_c}\n");
  return;
}


void load_test( char *llvm_cbe_k,  char *llvm_cbe_npub, signed long long *llvm_cbe_st) {
  static  unsigned long long aesl_llvm_cbe_s_count = 0;
  signed long long llvm_cbe_s[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
   char *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
   char *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  signed long long *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  signed long long *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  signed long long *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  signed long long *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  signed long long *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @load_test\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%k), !dbg !5 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__14 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe_k);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__14);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i8* %%k, i64 8, !dbg !5 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__15 = ( char *)(&llvm_cbe_k[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%2), !dbg !5 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__16 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__16);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%npub), !dbg !5 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__17 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe_npub);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__17);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds i8* %%npub, i64 8, !dbg !5 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__18 = ( char *)(&llvm_cbe_npub[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%5), !dbg !5 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__19 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [5 x i64]* %%s, i64 0, i64 0, !dbg !7 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__20 = (signed long long *)(&llvm_cbe_s[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 5 && "Write access out of array 's' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 -9205344418435956736, i64* %%7, align 16, !dbg !7 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_86_count);
  *llvm_cbe_tmp__20 = 9241399655273594880ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 9241399655273594880ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [5 x i64]* %%s, i64 0, i64 1, !dbg !6 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__21 = (signed long long *)(&llvm_cbe_s[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 5 && "Write access out of array 's' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%1, i64* %%8, align 8, !dbg !6 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_88_count);
  *llvm_cbe_tmp__21 = llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [5 x i64]* %%s, i64 0, i64 2, !dbg !6 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__22 = (signed long long *)(&llvm_cbe_s[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 5 && "Write access out of array 's' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%3, i64* %%9, align 16, !dbg !6 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_90_count);
  *llvm_cbe_tmp__22 = llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [5 x i64]* %%s, i64 0, i64 3, !dbg !6 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__23 = (signed long long *)(&llvm_cbe_s[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 5 && "Write access out of array 's' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%4, i64* %%10, align 8, !dbg !6 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_92_count);
  *llvm_cbe_tmp__23 = llvm_cbe_tmp__17;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [5 x i64]* %%s, i64 0, i64 4, !dbg !7 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__24 = (signed long long *)(&llvm_cbe_s[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )4ull) < 5 && "Write access out of array 's' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%6, i64* %%11, align 16, !dbg !7 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_94_count);
  *llvm_cbe_tmp__24 = llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  call void @copyState(i64* %%7, i64* %%st), !dbg !6 for 0x%I64xth hint within @load_test  --> \n", ++aesl_llvm_cbe_95_count);
  copyState((signed long long *)llvm_cbe_tmp__20, (signed long long *)llvm_cbe_st);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @load_test}\n");
  return;
}


void load_test_h( char *llvm_cbe_k,  char *llvm_cbe_npub, signed long long *llvm_cbe_st) {
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @load_test_h\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @load_test(i8* %%k, i8* %%npub, i64* %%st), !dbg !5 for 0x%I64xth hint within @load_test_h  --> \n", ++aesl_llvm_cbe_103_count);
   /*tail*/ load_test(( char *)llvm_cbe_k, ( char *)llvm_cbe_npub, (signed long long *)llvm_cbe_st);
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @load_test_h}\n");
  return;
}


static signed long long aesl_internal_LOADBYTES( char *llvm_cbe_bytes) {
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned char llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
   char *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  unsigned char llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  unsigned long long llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
   char *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned char llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned long long llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  unsigned long long llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
   char *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned char llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned long long llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned long long llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
   char *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  unsigned char llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  unsigned long long llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  unsigned long long llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
   char *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  unsigned char llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned long long llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  unsigned long long llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  unsigned long long llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
   char *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  unsigned char llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  unsigned long long llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  unsigned long long llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  unsigned long long llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
   char *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned char llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned long long llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_LOADBYTES\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = load i8* %%bytes, align 1, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__25 = (unsigned char )*llvm_cbe_bytes;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i8 %%1 to i64, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__26 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__25&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = shl nuw i64 %%2, 56, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__27 = (unsigned long long )llvm_cbe_tmp__26 << 56ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%bytes, i64 1, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_128_count);
  llvm_cbe_tmp__28 = ( char *)(&llvm_cbe_bytes[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8* %%4, align 1, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__29 = (unsigned char )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i8 %%5 to i64, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__30 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__29&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = shl nuw nsw i64 %%6, 48, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_131_count);
  llvm_cbe_tmp__31 = (unsigned long long )llvm_cbe_tmp__30 << 48ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = or i64 %%7, %%3, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__32 = (unsigned long long )llvm_cbe_tmp__31 | llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds i8* %%bytes, i64 2, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__33 = ( char *)(&llvm_cbe_bytes[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = load i8* %%9, align 1, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__34 = (unsigned char )*llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__34);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = zext i8 %%10 to i64, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__35 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__34&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = shl nuw nsw i64 %%11, 40, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_144_count);
  llvm_cbe_tmp__36 = (unsigned long long )llvm_cbe_tmp__35 << 40ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__36);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = or i64 %%12, %%8, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__37 = (unsigned long long )llvm_cbe_tmp__36 | llvm_cbe_tmp__32;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds i8* %%bytes, i64 3, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__38 = ( char *)(&llvm_cbe_bytes[(((signed long long )3ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i8* %%14, align 1, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__39 = (unsigned char )*llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = zext i8 %%15 to i64, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__40 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__39&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = shl nuw nsw i64 %%16, 32, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__41 = (unsigned long long )llvm_cbe_tmp__40 << 32ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = or i64 %%17, %%13, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_158_count);
  llvm_cbe_tmp__42 = (unsigned long long )llvm_cbe_tmp__41 | llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds i8* %%bytes, i64 4, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__43 = ( char *)(&llvm_cbe_bytes[(((signed long long )4ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = load i8* %%19, align 1, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__44 = (unsigned char )*llvm_cbe_tmp__43;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__44);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = zext i8 %%20 to i64, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__45 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__44&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = shl nuw nsw i64 %%21, 24, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__46 = (unsigned long long )llvm_cbe_tmp__45 << 24ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = or i64 %%22, %%18, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_171_count);
  llvm_cbe_tmp__47 = (unsigned long long )llvm_cbe_tmp__46 | llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds i8* %%bytes, i64 5, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_180_count);
  llvm_cbe_tmp__48 = ( char *)(&llvm_cbe_bytes[(((signed long long )5ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = load i8* %%24, align 1, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__49 = (unsigned char )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = zext i8 %%25 to i64, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__50 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__49&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = shl nuw nsw i64 %%26, 16, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__51 = (unsigned long long )llvm_cbe_tmp__50 << 16ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = or i64 %%27, %%23, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__52 = (unsigned long long )llvm_cbe_tmp__51 | llvm_cbe_tmp__47;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds i8* %%bytes, i64 6, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__53 = ( char *)(&llvm_cbe_bytes[(((signed long long )6ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = load i8* %%29, align 1, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_194_count);
  llvm_cbe_tmp__54 = (unsigned char )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = zext i8 %%30 to i64, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_195_count);
  llvm_cbe_tmp__55 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__54&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = shl nuw nsw i64 %%31, 8, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_196_count);
  llvm_cbe_tmp__56 = (unsigned long long )llvm_cbe_tmp__55 << 8ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = or i64 %%32, %%28, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_197_count);
  llvm_cbe_tmp__57 = (unsigned long long )llvm_cbe_tmp__56 | llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds i8* %%bytes, i64 7, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__58 = ( char *)(&llvm_cbe_bytes[(((signed long long )7ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i8* %%34, align 1, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__59 = (unsigned char )*llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = zext i8 %%35 to i64, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__60 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__59&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = or i64 %%36, %%33, !dbg !5 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__61 = (unsigned long long )llvm_cbe_tmp__60 | llvm_cbe_tmp__57;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__61);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_LOADBYTES}\n");
  return llvm_cbe_tmp__61;
}

