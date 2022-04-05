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
signed int main(void);
signed int generate_test_vectors(void);
void init_buffer( char *llvm_cbe_buffer, signed long long llvm_cbe_numbytes);
void fprint_bstr(l_struct_OC__iobuf *llvm_cbe_fp,  char *llvm_cbe_label,  char *llvm_cbe_data, signed long long llvm_cbe_length);
signed int crypto_aead_encrypt_c( char *, signed long long *,  char *, signed long long ,  char *, signed long long ,  char *,  char *,  char *, signed long long *);
signed int crypto_aead_encrypt_h( char *, signed long long *,  char *, signed long long ,  char *, signed long long ,  char *,  char *,  char *, signed long long *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str[44] = "test vector generation failed with code %d\n";
static  char aesl_internal__OC_str1[23] = "LWC_AEAD_KAT_%d_%d.txt";
static  char aesl_internal__OC_str2[2] = "w";
static  char aesl_internal__OC_str3[30] = "Couldn't open <%s> for write\n";
static  char aesl_internal__OC_str4[12] = "Count = %d\n";
static  char aesl_internal__OC_str11[21] = "ERROR: in cycle %d:\n";
static  char aesl_internal__OC_str5[7] = "Key = ";
static  char aesl_internal__OC_str6[9] = "Nonce = ";
static  char aesl_internal__OC_str7[6] = "PT = ";
static  char aesl_internal__OC_str8[6] = "AD = ";
static  char aesl_internal__OC_str9[6] = "CT = ";
static  char aesl_internal__OC_str12[7] = "CST = ";
static  char aesl_internal__OC_str15[5] = "%02X";
static  char aesl_internal__OC_str13[7] = "HST = ";


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

signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  unsigned int llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call i32 @generate_test_vectors(), !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_1_count);
  llvm_cbe_tmp__1 = (unsigned int ) /*tail*/ generate_test_vectors();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
  if (((llvm_cbe_tmp__1&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__5;
  } else {
    goto llvm_cbe_tmp__6;
  }

llvm_cbe_tmp__6:
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_8_count);
  llvm_cbe_tmp__2 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct._iobuf* %%4, i64 2, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_9_count);
  llvm_cbe_tmp__3 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__2[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%5, i8* getelementptr inbounds ([44 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%1) nounwind, !dbg !6 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_10_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__3, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 44
#endif
])), llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__1);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
  goto llvm_cbe_tmp__5;

llvm_cbe_tmp__5:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_tmp__1;
}


signed int generate_test_vectors(void) {
  static  unsigned long long aesl_llvm_cbe_fileName_count = 0;
   char llvm_cbe_fileName[256];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_key_count = 0;
   char llvm_cbe_key[16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_nonce_count = 0;
   char llvm_cbe_nonce[16];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_msg_count = 0;
   char llvm_cbe_msg[32];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_ad_count = 0;
   char llvm_cbe_ad[32];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_cct_count = 0;
   char llvm_cbe_cct[48];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_hct_count = 0;
   char llvm_cbe_hct[48];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_cclen_count = 0;
  signed long long llvm_cbe_cclen;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_hclen_count = 0;
  signed long long llvm_cbe_hclen;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_c_state_count = 0;
  signed long long llvm_cbe_c_state[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_h_state_count = 0;
  signed long long llvm_cbe_h_state[5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
   char *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
   char *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
   char *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
   char *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
   char *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
   char *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  signed long long *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
   char *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  signed long long *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge7_count = 0;
  unsigned long long llvm_cbe_storemerge7;
  unsigned long long llvm_cbe_storemerge7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  unsigned int llvm_cbe_tmp__23;
  unsigned int llvm_cbe_tmp__23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge14_count = 0;
  unsigned long long llvm_cbe_storemerge14;
  unsigned long long llvm_cbe_storemerge14__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  unsigned int llvm_cbe_tmp__25;
  unsigned int llvm_cbe_tmp__25__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned int llvm_cbe_tmp__26;
  unsigned int llvm_cbe_tmp__26__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  unsigned int llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned long long llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned int llvm_cbe_tmp__40;
  unsigned int llvm_cbe_tmp__40__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned long long llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge2_count = 0;
  unsigned int llvm_cbe_storemerge2;
  unsigned int llvm_cbe_storemerge2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @generate_test_vectors\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 0, !dbg !11 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__7 = ( char *)(&llvm_cbe_key[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @init_buffer(i8* %%1, i64 16), !dbg !11 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_31_count);
  init_buffer(( char *)llvm_cbe_tmp__7, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",16ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 0, !dbg !11 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__8 = ( char *)(&llvm_cbe_nonce[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @init_buffer(i8* %%2, i64 16), !dbg !11 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_33_count);
  init_buffer(( char *)llvm_cbe_tmp__8, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",16ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [32 x i8]* %%msg, i64 0, i64 0, !dbg !11 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__9 = ( char *)(&llvm_cbe_msg[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @init_buffer(i8* %%3, i64 32), !dbg !11 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_35_count);
  init_buffer(( char *)llvm_cbe_tmp__9, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [32 x i8]* %%ad, i64 0, i64 0, !dbg !11 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_36_count);
  llvm_cbe_tmp__10 = ( char *)(&llvm_cbe_ad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @init_buffer(i8* %%4, i64 32), !dbg !11 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_37_count);
  init_buffer(( char *)llvm_cbe_tmp__10, 32ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",32ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = bitcast [5 x i64]* %%c_state to i8*, !dbg !11 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_38_count);
  llvm_cbe_tmp__11 = ( char *)(( char *)(&llvm_cbe_c_state));
if (AESL_DEBUG_TRACE)
printf("\n  call void @init_buffer(i8* %%5, i64 40), !dbg !11 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_39_count);
  init_buffer(( char *)llvm_cbe_tmp__11, 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = bitcast [5 x i64]* %%h_state to i8*, !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__12 = ( char *)(( char *)(&llvm_cbe_h_state));
if (AESL_DEBUG_TRACE)
printf("\n  call void @init_buffer(i8* %%6, i64 40), !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_41_count);
  init_buffer(( char *)llvm_cbe_tmp__12, 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [256 x i8]* %%fileName, i64 0, i64 0, !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__13 = ( char *)(&llvm_cbe_fileName[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = call i32 (i8*, i8*, ...)* @sprintf(i8* %%7, i8* getelementptr inbounds ([23 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 128, i32 128) nounwind, !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_43_count);
  sprintf(( char *)llvm_cbe_tmp__13, ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])), 128u, 128u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",128u);
printf("\nArgument  = 0x%X",128u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__14);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = call %%struct._iobuf* @fopen(i8* %%7, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str2, i64 0, i64 0)) nounwind, !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__15 = (l_struct_OC__iobuf *)aesl_fopen(( char *)llvm_cbe_tmp__13, ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__15);
}
  if (((llvm_cbe_tmp__15) == (((l_struct_OC__iobuf *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__44;
  } else {
    goto llvm_cbe__2e_preheader5;
  }

llvm_cbe__2e_preheader5:
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [48 x i8]* %%cct, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__16 = ( char *)(&llvm_cbe_cct[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [5 x i64]* %%c_state, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__17 = (signed long long *)(&llvm_cbe_c_state[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [48 x i8]* %%hct, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__18 = ( char *)(&llvm_cbe_hct[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [5 x i64]* %%h_state, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__19 = (signed long long *)(&llvm_cbe_h_state[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__23__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__44:
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__20 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds %%struct._iobuf* %%16, i64 2, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__21 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__20[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%17, i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str3, i64 0, i64 0), i8* %%7) nounwind, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_68_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__21, ( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), ( char *)llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__22);
}
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__45;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge7 = phi i64 [ 0, %%.preheader5 ], [ %%43, %%42  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_storemerge7_count);
  llvm_cbe_storemerge7 = (unsigned long long )llvm_cbe_storemerge7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = phi i32 [ 1, %%.preheader5 ], [ %%20, %%42  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_70_count);
  llvm_cbe_tmp__23 = (unsigned int )llvm_cbe_tmp__23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__23);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",llvm_cbe_tmp__24);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = add i32 %%19, 33, !dbg !10 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_tmp__23&4294967295ull)) + ((unsigned int )(33u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
  llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  llvm_cbe_tmp__25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__23;   /* for PHI node */
  llvm_cbe_tmp__26__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__46;

llvm_cbe_tmp__47:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = add i64 %%storemerge7, 1, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__42 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge7&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__42&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = and i1 %%44, %%4 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )(((((unsigned long long )llvm_cbe_tmp__42&18446744073709551615ULL) < ((unsigned long long )33ull&18446744073709551615ULL)) & ((llvm_cbe_tmp__40&4294967295U) == (0u&4294967295U)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    llvm_cbe_storemerge7__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__42;   /* for PHI node */
    llvm_cbe_tmp__23__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__24;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    goto llvm_cbe__2e_critedge;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__46:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge14 = phi i64 [ 0, %%.preheader ], [ %%41, %%39  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_storemerge14_count);
  llvm_cbe_storemerge14 = (unsigned long long )llvm_cbe_storemerge14__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__41);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = phi i32 [ %%19, %%.preheader ], [ %%24, %%39  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__25 = (unsigned int )llvm_cbe_tmp__25__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__25);
printf("\n = 0x%X",llvm_cbe_tmp__23);
printf("\n = 0x%X",llvm_cbe_tmp__27);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = phi i32 [ 0, %%.preheader ], [ %%40, %%39  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__26 = (unsigned int )llvm_cbe_tmp__26__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__26);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = add nsw i32 %%22, 1, !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__27 = (unsigned int )((unsigned int )(llvm_cbe_tmp__25&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__27&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%9, i8* getelementptr inbounds ([12 x i8]* @aesl_internal_.str4, i64 0, i64 0), i32 %%22) nounwind, !dbg !9 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_84_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__15, ( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 12
#endif
])), llvm_cbe_tmp__25);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__25);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__28);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @fprint_bstr(%%struct._iobuf* %%9, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str5, i64 0, i64 0), i8* %%1, i64 16), !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_85_count);
  fprint_bstr((l_struct_OC__iobuf *)llvm_cbe_tmp__15, ( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), ( char *)llvm_cbe_tmp__7, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",16ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @fprint_bstr(%%struct._iobuf* %%9, i8* getelementptr inbounds ([9 x i8]* @aesl_internal_.str6, i64 0, i64 0), i8* %%2, i64 16), !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_86_count);
  fprint_bstr((l_struct_OC__iobuf *)llvm_cbe_tmp__15, ( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
])), ( char *)llvm_cbe_tmp__8, 16ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",16ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @fprint_bstr(%%struct._iobuf* %%9, i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str7, i64 0, i64 0), i8* %%3, i64 %%storemerge7), !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_87_count);
  fprint_bstr((l_struct_OC__iobuf *)llvm_cbe_tmp__15, ( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), ( char *)llvm_cbe_tmp__9, llvm_cbe_storemerge7);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge7 = 0x%I64X",llvm_cbe_storemerge7);
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @fprint_bstr(%%struct._iobuf* %%9, i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str8, i64 0, i64 0), i8* %%4, i64 %%storemerge14), !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_88_count);
  fprint_bstr((l_struct_OC__iobuf *)llvm_cbe_tmp__15, ( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), ( char *)llvm_cbe_tmp__10, llvm_cbe_storemerge14);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge14 = 0x%I64X",llvm_cbe_storemerge14);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = call i32 @crypto_aead_encrypt_c(i8* %%11, i64* %%cclen, i8* %%3, i64 %%storemerge7, i8* %%4, i64 %%storemerge14, i8* null, i8* %%2, i8* %%1, i64* %%12) nounwind, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_89_count);
  crypto_aead_encrypt_c(( char *)llvm_cbe_tmp__16, (signed long long *)(&llvm_cbe_cclen), ( char *)llvm_cbe_tmp__9, llvm_cbe_storemerge7, ( char *)llvm_cbe_tmp__10, llvm_cbe_storemerge14, ( char *)(( char *)/*NULL*/0), ( char *)llvm_cbe_tmp__8, ( char *)llvm_cbe_tmp__7, (signed long long *)llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\nArgument storemerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__29);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i64* %%cclen, align 8, !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__30 = (unsigned long long )*(&llvm_cbe_cclen);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  call void @fprint_bstr(%%struct._iobuf* %%9, i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str9, i64 0, i64 0), i8* %%11, i64 %%27), !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_97_count);
  fprint_bstr((l_struct_OC__iobuf *)llvm_cbe_tmp__15, ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), ( char *)llvm_cbe_tmp__16, llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__30);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = call i32 @crypto_aead_encrypt_h(i8* %%13, i64* %%hclen, i8* %%3, i64 %%storemerge7, i8* %%4, i64 %%storemerge14, i8* null, i8* %%2, i8* %%1, i64* %%14) nounwind, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_98_count);
  crypto_aead_encrypt_h(( char *)llvm_cbe_tmp__18, (signed long long *)(&llvm_cbe_hclen), ( char *)llvm_cbe_tmp__9, llvm_cbe_storemerge7, ( char *)llvm_cbe_tmp__10, llvm_cbe_storemerge14, ( char *)(( char *)/*NULL*/0), ( char *)llvm_cbe_tmp__8, ( char *)llvm_cbe_tmp__7, (signed long long *)llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE) {
printf("\nArgument storemerge7 = 0x%I64X",llvm_cbe_storemerge7);
printf("\nArgument storemerge14 = 0x%I64X",llvm_cbe_storemerge14);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__31);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc = call i32 @fputc(i32 10, %%struct._iobuf* %%9), !dbg !12 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_fputc_count);
  fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc = 0x%X",llvm_cbe_fputc);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = call i32 @memcmp(i8* %%5, i8* %%6, i64 40) nounwind, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__32 = (unsigned int )memcmp(( char *)llvm_cbe_tmp__11, ( char *)llvm_cbe_tmp__12, 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__32);
}
  if (((llvm_cbe_tmp__32&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_tmp__40__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__26;   /* for PHI node */
    goto llvm_cbe_tmp__48;
  } else {
    goto llvm_cbe_tmp__49;
  }

llvm_cbe_tmp__48:
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = phi i32 [ -4, %%31 ], [ %%23, %%21  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__40 = (unsigned int )llvm_cbe_tmp__40__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__40);
printf("\n = 0x%X",4294967292u);
printf("\n = 0x%X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = add i64 %%storemerge14, 1, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__41 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge14&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__41&18446744073709551615ull)));
  if (((llvm_cbe_tmp__41&18446744073709551615ULL) == (33ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__47;
  } else {
    llvm_cbe_storemerge14__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__41;   /* for PHI node */
    llvm_cbe_tmp__25__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__27;   /* for PHI node */
    llvm_cbe_tmp__26__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__40;   /* for PHI node */
    goto llvm_cbe_tmp__46;
  }

llvm_cbe_tmp__49:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !10 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__33 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__33);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds %%struct._iobuf* %%32, i64 1, !dbg !10 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__34 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__33[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%33, i8* getelementptr inbounds ([21 x i8]* @aesl_internal_.str11, i64 0, i64 0), i32 %%24) nounwind, !dbg !10 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_104_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__34, ( char *)((&aesl_internal__OC_str11[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 21
#endif
])), llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__27);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__35);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__36 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__36);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds %%struct._iobuf* %%35, i64 1, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__37 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__36[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @fprint_bstr(%%struct._iobuf* %%36, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str12, i64 0, i64 0), i8* %%5, i64 40), !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_107_count);
  fprint_bstr((l_struct_OC__iobuf *)llvm_cbe_tmp__37, ( char *)((&aesl_internal__OC_str12[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), ( char *)llvm_cbe_tmp__11, 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__38 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = getelementptr inbounds %%struct._iobuf* %%37, i64 1, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__39 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__38[(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @fprint_bstr(%%struct._iobuf* %%38, i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str13, i64 0, i64 0), i8* %%6, i64 40), !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_110_count);
  fprint_bstr((l_struct_OC__iobuf *)llvm_cbe_tmp__39, ( char *)((&aesl_internal__OC_str13[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), ( char *)llvm_cbe_tmp__12, 40ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",40ull);
}
  llvm_cbe_tmp__40__PHI_TEMPORARY = (unsigned int )4294967292u;   /* for PHI node */
  goto llvm_cbe_tmp__48;

  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_critedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = call i32 @fclose(%%struct._iobuf* %%9) nounwind, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_134_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__43);
}
  llvm_cbe_storemerge2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__40;   /* for PHI node */
  goto llvm_cbe_tmp__45;

llvm_cbe_tmp__45:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge2 = phi i32 [ -1, %%15 ], [ %%40, %%.critedge  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_storemerge2_count);
  llvm_cbe_storemerge2 = (unsigned int )llvm_cbe_storemerge2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge2 = 0x%X",llvm_cbe_storemerge2);
printf("\n = 0x%X",4294967295u);
printf("\n = 0x%X",llvm_cbe_tmp__40);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @generate_test_vectors}\n");
  return llvm_cbe_storemerge2;
}


void init_buffer( char *llvm_cbe_buffer, signed long long llvm_cbe_numbytes) {
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  unsigned char llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
   char *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  unsigned long long llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;

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
printf("\n = 0x%I64X",llvm_cbe_tmp__52);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = trunc i64 %%storemerge1 to i8, !dbg !6 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__50 = (unsigned char )((unsigned char )llvm_cbe_storemerge1&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%buffer, i64 %%storemerge1, !dbg !6 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__51 = ( char *)(&llvm_cbe_buffer[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%2, i8* %%3, align 1, !dbg !6 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_150_count);
  *llvm_cbe_tmp__51 = llvm_cbe_tmp__50;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i64 %%storemerge1, 1, !dbg !7 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__52 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__52&18446744073709551615ull)));
  if (((llvm_cbe_tmp__52&18446744073709551615ULL) == (llvm_cbe_numbytes&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__52;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @init_buffer}\n");
  return;
}


void fprint_bstr(l_struct_OC__iobuf *llvm_cbe_fp,  char *llvm_cbe_label,  char *llvm_cbe_data, signed long long llvm_cbe_length) {
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputs_count = 0;
  unsigned int llvm_cbe_fputs;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned long long llvm_cbe_storemerge1;
  unsigned long long llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
   char *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  unsigned char llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  unsigned long long llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;

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
printf("\n = 0x%I64X",llvm_cbe_tmp__57);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i8* %%data, i64 %%storemerge1, !dbg !6 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__53 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_storemerge1))]);
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%I64X",((signed long long )llvm_cbe_storemerge1));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i8* %%2, align 1, !dbg !6 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_176_count);
  llvm_cbe_tmp__54 = (unsigned char )*llvm_cbe_tmp__53;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i8 %%3 to i32, !dbg !6 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__55 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__54&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str15, i64 0, i64 0), i32 %%4) nounwind, !dbg !6 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_178_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_fp, ( char *)((&aesl_internal__OC_str15[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__55);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__56);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i64 %%storemerge1, 1, !dbg !7 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__57 = (unsigned long long )((unsigned long long )(llvm_cbe_storemerge1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__57&18446744073709551615ull)));
  if (((llvm_cbe_tmp__57&18446744073709551615ULL) == (llvm_cbe_length&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__57;   /* for PHI node */
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

