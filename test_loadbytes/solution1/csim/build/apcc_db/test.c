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
/* Structure forward decls */
typedef struct l_struct_OC__iobuf l_struct_OC__iobuf;

/* Structure contents */
struct l_struct_OC__iobuf {
   char *field0;
  unsigned int field1;
   char *field2;
  unsigned int field3;
  unsigned int field4;
  unsigned int field5;
  unsigned int field6;
   char *field7;
};


/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void fprint_bstr(l_struct_OC__iobuf *llvm_cbe_fp,  char *llvm_cbe_label,  char *llvm_cbe_data, signed long long llvm_cbe_length);
void init_buffer( char *llvm_cbe_buffer, signed long long llvm_cbe_numbytes);
signed int main(void);
signed int generate_test_vectors(void);
signed int load_test_c();
signed int load_test_h();


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str1[5] = "%02X";
static  char aesl_internal__OC_str3[44] = "test vector generation failed with code %d\n";
static  char aesl_internal__OC_str4[7] = "CST = ";
static  char aesl_internal__OC_str5[7] = "HST = ";
static  char aesl_internal__OC_str6[10] = "No errors";


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

void fprint_bstr(l_struct_OC__iobuf *llvm_cbe_fp,  char *llvm_cbe_label,  char *llvm_cbe_data, signed long long llvm_cbe_length) {
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
  static  unsigned long long aesl_llvm_cbe_fputs_count = 0;
  unsigned int llvm_cbe_fputs;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned char llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fprint_bstr\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%fputs = tail call i32 @fputs(i8* %%label, %%struct._iobuf* %%fp), !dbg !6 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_fputs_count);
   /*tail*/ fputs(( char *)llvm_cbe_label, (l_struct_OC__iobuf *)llvm_cbe_fp);
if (AESL_DEBUG_TRACE) {
printf("\nReturn fputs = 0x%X",llvm_cbe_fputs);
}
  if (((llvm_cbe_length&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%6, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__5);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i8* %%data, i64 %%storemerge1, !dbg !6 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__1 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i8* %%2, align 1, !dbg !6 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__2 = (unsigned char )*llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i8 %%3 to i32, !dbg !6 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__3 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__2&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 %%4) nounwind, !dbg !6 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_20_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_fp, ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__3);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__3);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i64 %%storemerge1, 1, !dbg !7 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__5 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__5&18446744073709551615ull)));
  if (((llvm_cbe_tmp__5&18446744073709551615ULL) == (llvm_cbe_length&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__5;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc = tail call i32 @fputc(i32 10, %%struct._iobuf* %%fp), !dbg !6 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_fputc_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_fp);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc = 0x%X",llvm_cbe_fputc);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fprint_bstr}\n");
  return;
}


void init_buffer( char *llvm_cbe_buffer, signed long long llvm_cbe_numbytes) {
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  unsigned char llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
   char *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @init_buffer\n");
  if (((llvm_cbe_numbytes&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%4, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__8);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = trunc i64 %%storemerge1 to i8, !dbg !6 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_39_count);
  llvm_cbe_tmp__6 = (unsigned char )((unsigned char )llvm_cbe_storemerge1&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%buffer, i64 %%storemerge1, !dbg !6 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__7 = ( char *)(&llvm_cbe_buffer[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%2, i8* %%3, align 1, !dbg !6 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_41_count);
  *llvm_cbe_tmp__7 = llvm_cbe_tmp__6;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i64 %%storemerge1, 1, !dbg !7 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__8 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__8&18446744073709551615ull)));
  if (((llvm_cbe_tmp__8&18446744073709551615ULL) == (llvm_cbe_numbytes&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__8;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @init_buffer}\n");
  return;
}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 @generate_test_vectors(), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__9 = (unsigned int ) /*tail*/ generate_test_vectors();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__9);
}
  if (((llvm_cbe_tmp__9&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__13;
  } else {
    goto llvm_cbe_tmp__14;
  }

llvm_cbe_tmp__14:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__10 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct._iobuf* %%4, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__11 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__10[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%5, i8* getelementptr inbounds ([44 x i8]* @aesl_internal_.str3, i64 0, i64 0), i32 %%1) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_59_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__11, ( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 44
#endif
])), llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__9);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__12);
}
  goto llvm_cbe_tmp__13;

llvm_cbe_tmp__13:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_tmp__9;
}


signed int generate_test_vectors(void) {
  static  unsigned long long aesl_llvm_cbe_key_count = 0;
   char llvm_cbe_key[16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_nonce_count = 0;
   char llvm_cbe_nonce[16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_c_state_count = 0;
  signed long long llvm_cbe_c_state[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_h_state_count = 0;
  signed long long llvm_cbe_h_state[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
   char *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
   char *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  signed long long *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  signed long long *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  signed long long *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  signed long long *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  signed long long *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
   char *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
   char *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  signed long long *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  signed long long *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  signed long long *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  signed long long *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  signed long long *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
   char *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
   char *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  unsigned long long llvm_cbe_storemerge;
  unsigned long long llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  unsigned long long llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  unsigned long long llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  unsigned long long llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  unsigned int llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @generate_test_vectors\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = bitcast [5 x i64]* %%c_state to i8*, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__15 = ( char *)(( char *)(&llvm_cbe_c_state));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call i8* @memset(i8* %%1, i32 0, i64 32 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_68_count);
  ( char *)memset(( char *)llvm_cbe_tmp__15, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__16);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr [5 x i64]* %%c_state, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__17 = (signed long long *)(&llvm_cbe_c_state[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 5 && "Write access out of array 'c_state' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* %%3, align 16, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_70_count);
  *llvm_cbe_tmp__17 = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr [5 x i64]* %%c_state, i64 0, i64 1, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__18 = (signed long long *)(&llvm_cbe_c_state[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 5 && "Write access out of array 'c_state' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* %%4, align 8, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_72_count);
  *llvm_cbe_tmp__18 = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr [5 x i64]* %%c_state, i64 0, i64 2, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_73_count);
  llvm_cbe_tmp__19 = (signed long long *)(&llvm_cbe_c_state[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 5 && "Write access out of array 'c_state' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* %%5, align 16, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_74_count);
  *llvm_cbe_tmp__19 = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr [5 x i64]* %%c_state, i64 0, i64 3, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__20 = (signed long long *)(&llvm_cbe_c_state[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 5 && "Write access out of array 'c_state' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* %%6, align 8, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_76_count);
  *llvm_cbe_tmp__20 = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr [5 x i64]* %%c_state, i64 0, i64 4, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__21 = (signed long long *)(&llvm_cbe_c_state[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )4ull) < 5 && "Write access out of array 'c_state' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 1, i64* %%7, align 16, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_78_count);
  *llvm_cbe_tmp__21 = 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 1ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = bitcast [5 x i64]* %%h_state to i8*, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__22 = ( char *)(( char *)(&llvm_cbe_h_state));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call i8* @memset(i8* %%8, i32 0, i64 32 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_81_count);
  ( char *)memset(( char *)llvm_cbe_tmp__22, 0u, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",32ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr [5 x i64]* %%h_state, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__24 = (signed long long *)(&llvm_cbe_h_state[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 5 && "Write access out of array 'h_state' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2, i64* %%10, align 16, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_83_count);
  *llvm_cbe_tmp__24 = 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr [5 x i64]* %%h_state, i64 0, i64 1, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__25 = (signed long long *)(&llvm_cbe_h_state[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 5 && "Write access out of array 'h_state' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2, i64* %%11, align 8, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_85_count);
  *llvm_cbe_tmp__25 = 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr [5 x i64]* %%h_state, i64 0, i64 2, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__26 = (signed long long *)(&llvm_cbe_h_state[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 5 && "Write access out of array 'h_state' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2, i64* %%12, align 16, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_87_count);
  *llvm_cbe_tmp__26 = 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr [5 x i64]* %%h_state, i64 0, i64 3, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__27 = (signed long long *)(&llvm_cbe_h_state[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 5 && "Write access out of array 'h_state' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2, i64* %%13, align 8, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_89_count);
  *llvm_cbe_tmp__27 = 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr [5 x i64]* %%h_state, i64 0, i64 4, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__28 = (signed long long *)(&llvm_cbe_h_state[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )4ull) < 5 && "Write access out of array 'h_state' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i64 2, i64* %%14, align 16, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_91_count);
  *llvm_cbe_tmp__28 = 2ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 2ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_92_count);
  llvm_cbe_tmp__29 = ( char *)(&llvm_cbe_key[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @init_buffer(i8* %%15, i64 16), !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_93_count);
  init_buffer(( char *)llvm_cbe_tmp__29, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",16ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 0, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_94_count);
  llvm_cbe_tmp__30 = ( char *)(&llvm_cbe_nonce[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @init_buffer(i8* %%16, i64 16), !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_95_count);
  init_buffer(( char *)llvm_cbe_tmp__30, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",16ull);
}
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__45;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__45:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi i64 [ 0, %%0 ], [ %%34, %%33  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (unsigned long long )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = 0x%I64X",llvm_cbe_storemerge);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__41);
}
  if ((((unsigned long long )llvm_cbe_storemerge&18446744073709551615ULL) < ((unsigned long long )33ull&18446744073709551615ULL))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e_critedge;
  }

llvm_cbe_tmp__46:
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i64 %%storemerge, 1, !dbg !8 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__41 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__41&18446744073709551615ull)));
  llvm_cbe_storemerge__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__41;   /* for PHI node */
  goto llvm_cbe_tmp__45;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i64 [ %%25, %%20 ], [ 0, %%17  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned long long )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",llvm_cbe_storemerge1);
printf("\n = 0x%I64X",llvm_cbe_tmp__34);
printf("\n = 0x%I64X",0ull);
}
  if ((((unsigned long long )llvm_cbe_storemerge1&18446744073709551615ULL) < ((unsigned long long )33ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__47;
  } else {
    goto llvm_cbe_tmp__46;
  }

llvm_cbe_tmp__47:
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = call i32 bitcast (i32 (...)* @load_test_c to i32 (i8*, i8*, i64*)*)(i8* %%15, i8* %%16, i64* %%3) nounwind, !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_106_count);
  load_test_c(( char *)llvm_cbe_tmp__29, ( char *)llvm_cbe_tmp__30, (signed long long *)llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__31);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = call i32 bitcast (i32 (...)* @load_test_h to i32 (i8*, i8*, i64*)*)(i8* %%15, i8* %%16, i64* %%10) nounwind, !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_107_count);
  load_test_h(( char *)llvm_cbe_tmp__29, ( char *)llvm_cbe_tmp__30, (signed long long *)llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__32);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = call i32 @memcmp(i8* %%1, i8* %%8, i64 40) nounwind, !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__33 = (unsigned int )memcmp(( char *)llvm_cbe_tmp__15, ( char *)llvm_cbe_tmp__22, 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__33);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i64 %%storemerge1, 1, !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__34 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull)));
  if (((llvm_cbe_tmp__33&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__34;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe_tmp__48;
  }

  } while (1); /* end of syntactic loop '.preheader' */
  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__48:
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__35 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds %%struct._iobuf* %%27, i64 2, !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__36 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__35[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @fprint_bstr(%%struct._iobuf* %%28, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str4, i64 0, i64 0), i8* %%1, i64 40), !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_115_count);
  fprint_bstr((l_struct_OC__iobuf *)llvm_cbe_tmp__36, ( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), ( char *)llvm_cbe_tmp__15, 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__37 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds %%struct._iobuf* %%29, i64 2, !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__38 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__37[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @fprint_bstr(%%struct._iobuf* %%30, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str5, i64 0, i64 0), i8* %%8, i64 40), !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_118_count);
  fprint_bstr((l_struct_OC__iobuf *)llvm_cbe_tmp__38, ( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), ( char *)llvm_cbe_tmp__22, 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !10 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__39 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__39);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = getelementptr inbounds %%struct._iobuf* %%31, i64 2, !dbg !10 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__40 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__39[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc = call i32 @fputc(i32 10, %%struct._iobuf* %%32), !dbg !10 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_fputc_count);
  fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_tmp__40);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc = 0x%X",llvm_cbe_fputc);
}
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe_tmp__49;

llvm_cbe__2e_critedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !10 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__42 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct._iobuf* %%35, i64 1, !dbg !10 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__43 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__42[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call i64 @fwrite(i8* getelementptr inbounds ([10 x i8]* @aesl_internal_.str6, i64 0, i64 0), i64 9, i64 1, %%struct._iobuf* %%36), !dbg !10 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_127_count);
  fwrite(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 10
#endif
])), 9ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",9ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__44);
}
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__49;

llvm_cbe_tmp__49:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i32 [ 1, %%26 ], [ 0, %%.critedge  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @generate_test_vectors}\n");
  return llvm_cbe_storemerge2;
}

