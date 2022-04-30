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
signed int apatb_crypto_aead_encrypt_sw( char *, signed long long *,  char *, signed long long ,  char *, signed long long ,  char *,  char *,  char *);
signed int crypto_aead_decrypt( char *, signed long long *,  char *,  char *, signed long long ,  char *, signed long long ,  char *,  char *);


/* Global Variable Definitions and Initialization */
static  char aesl_internal__OC_str8[6] = "AD = ";
static  char aesl_internal__OC_str[44] = "test vector generation failed with code %d\n";
static  char aesl_internal__OC_str3[30] = "Couldn't open <%s> for write\n";
static  char aesl_internal__OC_str13[72] = "crypto_aead_decrypt returned bad 'mlen': Got <%I64u>, expected <%I64u>\n";
static  char aesl_internal__OC_str1[23] = "LWC_AEAD_KAT_%d_%d.txt";
static  char aesl_internal__OC_str9[35] = "crypto_aead_encrypt returned <%d>\n";
static  char aesl_internal__OC_str16[5] = "%02X";
static  char aesl_internal__OC_str4[12] = "Count = %d\n";
static  char aesl_internal__OC_str6[9] = "Nonce = ";
static  char aesl_internal__OC_str5[7] = "Key = ";
static  char aesl_internal__OC_str10[6] = "CT = ";
static  char aesl_internal__OC_str2[2] = "w";
static  char aesl_internal__OC_str7[6] = "PT = ";
static  char aesl_internal__OC_str12[35] = "crypto_aead_decrypt returned <%d>\n";
static  char aesl_internal__OC_str14[51] = "crypto_aead_decrypt did not recover the plaintext\n";


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
  static  unsigned long long aesl_llvm_cbe_ret_2e_0_count = 0;
  unsigned int llvm_cbe_ret_2e_0;
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  unsigned int llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;

  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%ret.0 = tail call i32 @generate_test_vectors(), !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_ret_2e_0_count);
  llvm_cbe_ret_2e_0 = (unsigned int ) /*tail*/ generate_test_vectors();
if (AESL_DEBUG_TRACE) {
printf("\nReturn ret.0 = 0x%X",llvm_cbe_ret_2e_0);
}
  if (((llvm_cbe_ret_2e_0&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__4;
  } else {
    goto llvm_cbe_tmp__5;
  }

llvm_cbe_tmp__5:
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = tail call %%struct._iobuf* @__iob_func() nounwind, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_4_count);
  llvm_cbe_tmp__1 = (l_struct_OC__iobuf *) /*tail*/ __iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds %%struct._iobuf* %%3, i64 2, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_5_count);
  llvm_cbe_tmp__2 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__1[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%4, i8* getelementptr inbounds ([44 x i8]* @aesl_internal_.str, i64 0, i64 0), i32 %%ret.0) nounwind, !dbg !11 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_6_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__2, ( char *)((&aesl_internal__OC_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 44
#endif
])), llvm_cbe_ret_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument ret.0 = 0x%X",llvm_cbe_ret_2e_0);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__3);
}
  goto llvm_cbe_tmp__4;

llvm_cbe_tmp__4:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return llvm_cbe_ret_2e_0;
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
  static  unsigned long long aesl_llvm_cbe_msg2_count = 0;
   char llvm_cbe_msg2[32];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_ad_count = 0;
   char llvm_cbe_ad[32];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_ct_count = 0;
   char llvm_cbe_ct[48];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_clen_count = 0;
  signed long long llvm_cbe_clen;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_mlen2_count = 0;
  signed long long llvm_cbe_mlen2;    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
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
   char *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
   char *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
   char *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
   char *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
   char *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
   char *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
   char *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
   char *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
   char *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
   char *llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
   char *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
   char *llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
   char *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
   char *llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
   char *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
   char *llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
   char *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
   char *llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
   char *llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
   char *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
   char *llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
   char *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
   char *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
   char *llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
   char *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
   char *llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
   char *llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
   char *llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
   char *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
   char *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
   char *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
   char *llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_i_2e_01_2e_i8_count = 0;
  unsigned long long llvm_cbe_i_2e_01_2e_i8;
  unsigned long long llvm_cbe_i_2e_01_2e_i8__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  unsigned char llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
   char *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned long long llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_i9_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
   char *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_i_2e_01_2e_i12_count = 0;
  unsigned long long llvm_cbe_i_2e_01_2e_i12;
  unsigned long long llvm_cbe_i_2e_01_2e_i12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  unsigned char llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
   char *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned long long llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_i13_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
   char *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
   char *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_fp_2e_0_count = 0;
  l_struct_OC__iobuf *llvm_cbe_fp_2e_0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
   char *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
   char *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  l_struct_OC__iobuf *llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  unsigned int llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_count_2e_056_count = 0;
  unsigned int llvm_cbe_count_2e_056;
  unsigned int llvm_cbe_count_2e_056__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_mlen_2e_054_count = 0;
  unsigned long long llvm_cbe_mlen_2e_054;
  unsigned long long llvm_cbe_mlen_2e_054__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_count_2e_1_count = 0;
  unsigned int llvm_cbe_count_2e_1;
  unsigned int llvm_cbe_count_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_adlen_2e_0_count = 0;
  unsigned long long llvm_cbe_adlen_2e_0;
  unsigned long long llvm_cbe_adlen_2e_0__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  unsigned long long llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_i_2e_01_2e_i23_count = 0;
  unsigned long long llvm_cbe_i_2e_01_2e_i23;
  unsigned long long llvm_cbe_i_2e_01_2e_i23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
   char *llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  unsigned char llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  unsigned int llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  unsigned long long llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_i24_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_i26_count = 0;
  unsigned int llvm_cbe_fputc_2e_i26;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  unsigned long long llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_i_2e_01_2e_i29_count = 0;
  unsigned long long llvm_cbe_i_2e_01_2e_i29;
  unsigned long long llvm_cbe_i_2e_01_2e_i29__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
   char *llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned char llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  unsigned int llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  unsigned long long llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_i30_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_i32_count = 0;
  unsigned int llvm_cbe_fputc_2e_i32;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  unsigned long long llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_i_2e_01_2e_i35_count = 0;
  unsigned long long llvm_cbe_i_2e_01_2e_i35;
  unsigned long long llvm_cbe_i_2e_01_2e_i35__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
   char *llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  unsigned char llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  unsigned int llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_i36_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_i38_count = 0;
  unsigned int llvm_cbe_fputc_2e_i38;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  unsigned long long llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_i_2e_01_2e_i17_count = 0;
  unsigned long long llvm_cbe_i_2e_01_2e_i17;
  unsigned long long llvm_cbe_i_2e_01_2e_i17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
   char *llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  unsigned char llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  unsigned int llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned int llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_i18_count = 0;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_i20_count = 0;
  unsigned int llvm_cbe_fputc_2e_i20;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  unsigned int llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned int llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  unsigned long long llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  unsigned long long llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_i_2e_01_2e_i1_count = 0;
  unsigned long long llvm_cbe_i_2e_01_2e_i1;
  unsigned long long llvm_cbe_i_2e_01_2e_i1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
   char *llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  unsigned char llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  unsigned int llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  unsigned int llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  unsigned long long llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_2e_i2_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_2e_i_count = 0;
  unsigned int llvm_cbe_fputc_2e_i;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  unsigned long long llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  unsigned int llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  unsigned int llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  unsigned int llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  unsigned int llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  unsigned long long llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  unsigned long long llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_ret_val_2e_171_count = 0;
  unsigned int llvm_cbe_ret_val_2e_171;
  unsigned int llvm_cbe_ret_val_2e_171__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  unsigned int llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_0_count = 0;
  unsigned int llvm_cbe__2e_0;
  unsigned int llvm_cbe__2e_0__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @generate_test_vectors\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 0, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__6 = ( char *)(&llvm_cbe_key[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%0, align 16, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_23_count);
  *llvm_cbe_tmp__6 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 1, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__7 = ( char *)(&llvm_cbe_key[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%1, align 1, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_26_count);
  *llvm_cbe_tmp__7 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 2, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_28_count);
  llvm_cbe_tmp__8 = ( char *)(&llvm_cbe_key[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 2, i8* %%2, align 2, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_29_count);
  *llvm_cbe_tmp__8 = ((unsigned char )2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )2));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 3, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__9 = ( char *)(&llvm_cbe_key[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 3, i8* %%3, align 1, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_32_count);
  *llvm_cbe_tmp__9 = ((unsigned char )3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )3));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 4, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__10 = ( char *)(&llvm_cbe_key[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )4ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 4, i8* %%4, align 4, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_35_count);
  *llvm_cbe_tmp__10 = ((unsigned char )4);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )4));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 5, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__11 = ( char *)(&llvm_cbe_key[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )5ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 5, i8* %%5, align 1, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_38_count);
  *llvm_cbe_tmp__11 = ((unsigned char )5);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )5));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 6, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__12 = ( char *)(&llvm_cbe_key[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )6ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 6, i8* %%6, align 2, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_41_count);
  *llvm_cbe_tmp__12 = ((unsigned char )6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )6));
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 7, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__13 = ( char *)(&llvm_cbe_key[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )7ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 7, i8* %%7, align 1, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_44_count);
  *llvm_cbe_tmp__13 = ((unsigned char )7);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )7));
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 8, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__14 = ( char *)(&llvm_cbe_key[(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )8ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 8, i8* %%8, align 8, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_47_count);
  *llvm_cbe_tmp__14 = ((unsigned char )8);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )8));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 9, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__15 = ( char *)(&llvm_cbe_key[(((signed long long )9ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )9ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 9, i8* %%9, align 1, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_50_count);
  *llvm_cbe_tmp__15 = ((unsigned char )9);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )9));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 10, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__16 = ( char *)(&llvm_cbe_key[(((signed long long )10ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )10ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 10, i8* %%10, align 2, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_53_count);
  *llvm_cbe_tmp__16 = ((unsigned char )10);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )10));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 11, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__17 = ( char *)(&llvm_cbe_key[(((signed long long )11ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )11ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 11, i8* %%11, align 1, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_56_count);
  *llvm_cbe_tmp__17 = ((unsigned char )11);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )11));
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 12, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__18 = ( char *)(&llvm_cbe_key[(((signed long long )12ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )12ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 12, i8* %%12, align 4, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_59_count);
  *llvm_cbe_tmp__18 = ((unsigned char )12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )12));
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 13, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__19 = ( char *)(&llvm_cbe_key[(((signed long long )13ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )13ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 13, i8* %%13, align 1, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_62_count);
  *llvm_cbe_tmp__19 = ((unsigned char )13);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )13));
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 14, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__20 = ( char *)(&llvm_cbe_key[(((signed long long )14ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )14ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 14, i8* %%14, align 2, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_65_count);
  *llvm_cbe_tmp__20 = ((unsigned char )14);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )14));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 15, !dbg !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__21 = ( char *)(&llvm_cbe_key[(((signed long long )15ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )15ull) < 16 && "Write access out of array 'key' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 15, i8* %%15, align 1, !dbg !131, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_68_count);
  *llvm_cbe_tmp__21 = ((unsigned char )15);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )15));
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_72_count);
  llvm_cbe_tmp__22 = ( char *)(&llvm_cbe_nonce[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 0, i8* %%16, align 16, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_73_count);
  *llvm_cbe_tmp__22 = ((unsigned char )0);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )0));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 1, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__23 = ( char *)(&llvm_cbe_nonce[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 1, i8* %%17, align 1, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_76_count);
  *llvm_cbe_tmp__23 = ((unsigned char )1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )1));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 2, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__24 = ( char *)(&llvm_cbe_nonce[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 2, i8* %%18, align 2, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_79_count);
  *llvm_cbe_tmp__24 = ((unsigned char )2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )2));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 3, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__25 = ( char *)(&llvm_cbe_nonce[(((signed long long )3ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )3ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 3, i8* %%19, align 1, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_82_count);
  *llvm_cbe_tmp__25 = ((unsigned char )3);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )3));
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 4, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__26 = ( char *)(&llvm_cbe_nonce[(((signed long long )4ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )4ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 4, i8* %%20, align 4, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_85_count);
  *llvm_cbe_tmp__26 = ((unsigned char )4);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )4));
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 5, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__27 = ( char *)(&llvm_cbe_nonce[(((signed long long )5ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )5ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 5, i8* %%21, align 1, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_88_count);
  *llvm_cbe_tmp__27 = ((unsigned char )5);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )5));
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 6, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__28 = ( char *)(&llvm_cbe_nonce[(((signed long long )6ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )6ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 6, i8* %%22, align 2, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_91_count);
  *llvm_cbe_tmp__28 = ((unsigned char )6);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )6));
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 7, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_93_count);
  llvm_cbe_tmp__29 = ( char *)(&llvm_cbe_nonce[(((signed long long )7ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )7ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 7, i8* %%23, align 1, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_94_count);
  *llvm_cbe_tmp__29 = ((unsigned char )7);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )7));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 8, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__30 = ( char *)(&llvm_cbe_nonce[(((signed long long )8ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )8ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 8, i8* %%24, align 8, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_97_count);
  *llvm_cbe_tmp__30 = ((unsigned char )8);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )8));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 9, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_99_count);
  llvm_cbe_tmp__31 = ( char *)(&llvm_cbe_nonce[(((signed long long )9ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )9ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 9, i8* %%25, align 1, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_100_count);
  *llvm_cbe_tmp__31 = ((unsigned char )9);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )9));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 10, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__32 = ( char *)(&llvm_cbe_nonce[(((signed long long )10ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )10ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 10, i8* %%26, align 2, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_103_count);
  *llvm_cbe_tmp__32 = ((unsigned char )10);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )10));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 11, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__33 = ( char *)(&llvm_cbe_nonce[(((signed long long )11ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )11ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 11, i8* %%27, align 1, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_106_count);
  *llvm_cbe_tmp__33 = ((unsigned char )11);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )11));
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 12, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__34 = ( char *)(&llvm_cbe_nonce[(((signed long long )12ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )12ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 12, i8* %%28, align 4, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_109_count);
  *llvm_cbe_tmp__34 = ((unsigned char )12);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )12));
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 13, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__35 = ( char *)(&llvm_cbe_nonce[(((signed long long )13ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )13ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 13, i8* %%29, align 1, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_112_count);
  *llvm_cbe_tmp__35 = ((unsigned char )13);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )13));
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 14, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__36 = ( char *)(&llvm_cbe_nonce[(((signed long long )14ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )14ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 14, i8* %%30, align 2, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_115_count);
  *llvm_cbe_tmp__36 = ((unsigned char )14);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )14));
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 15, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__37 = ( char *)(&llvm_cbe_nonce[(((signed long long )15ull))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )15ull) < 16 && "Write access out of array 'nonce' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 15, i8* %%31, align 1, !dbg !141, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_118_count);
  *llvm_cbe_tmp__37 = ((unsigned char )15);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned char )15));
  llvm_cbe_i_2e_01_2e_i8__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_i10;

  do {     /* Syntactic loop '.lr.ph.i10' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_i10:
if (AESL_DEBUG_TRACE)
printf("\n  %%i.01.i8 = phi i64 [ %%34, %%.lr.ph.i10 ], [ 0, %%.lr.ph.i  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_i_2e_01_2e_i8_count);
  llvm_cbe_i_2e_01_2e_i8 = (unsigned long long )llvm_cbe_i_2e_01_2e_i8__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i8 = 0x%I64X",llvm_cbe_i_2e_01_2e_i8);
printf("\n = 0x%I64X",llvm_cbe_tmp__40);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = trunc i64 %%i.01.i8 to i8, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__38 = (unsigned char )((unsigned char )llvm_cbe_i_2e_01_2e_i8&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds [32 x i8]* %%msg, i64 0, i64 %%i.01.i8, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__39 = ( char *)(&llvm_cbe_msg[(((signed long long )llvm_cbe_i_2e_01_2e_i8))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i8 = 0x%I64X",((signed long long )llvm_cbe_i_2e_01_2e_i8));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_i_2e_01_2e_i8) < 32 && "Write access out of array 'msg' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%32, i8* %%33, align 1, !dbg !149, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_125_count);
  *llvm_cbe_tmp__39 = llvm_cbe_tmp__38;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = add i64 %%i.01.i8, 1, !dbg !15 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__40 = (unsigned long long )((unsigned long long )(llvm_cbe_i_2e_01_2e_i8&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__40&18446744073709551615ull)));
  if (((llvm_cbe_tmp__40&18446744073709551615ULL) == (32ull&18446744073709551615ULL))) {
    goto llvm_cbe_init_buffer_2e_exit11;
  } else {
    llvm_cbe_i_2e_01_2e_i8__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__40;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_i10;
  }

  } while (1); /* end of syntactic loop '.lr.ph.i10' */
llvm_cbe_init_buffer_2e_exit11:
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds [32 x i8]* %%msg, i64 0, i64 0, !dbg !14 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__41 = ( char *)(&llvm_cbe_msg[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_i_2e_01_2e_i12__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_i14;

  do {     /* Syntactic loop '.lr.ph.i14' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_i14:
if (AESL_DEBUG_TRACE)
printf("\n  %%i.01.i12 = phi i64 [ %%38, %%.lr.ph.i14 ], [ 0, %%init_buffer.exit11  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_i_2e_01_2e_i12_count);
  llvm_cbe_i_2e_01_2e_i12 = (unsigned long long )llvm_cbe_i_2e_01_2e_i12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i12 = 0x%I64X",llvm_cbe_i_2e_01_2e_i12);
printf("\n = 0x%I64X",llvm_cbe_tmp__44);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = trunc i64 %%i.01.i12 to i8, !dbg !15 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_133_count);
  llvm_cbe_tmp__42 = (unsigned char )((unsigned char )llvm_cbe_i_2e_01_2e_i12&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [32 x i8]* %%ad, i64 0, i64 %%i.01.i12, !dbg !15 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_134_count);
  llvm_cbe_tmp__43 = ( char *)(&llvm_cbe_ad[(((signed long long )llvm_cbe_i_2e_01_2e_i12))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i12 = 0x%I64X",((signed long long )llvm_cbe_i_2e_01_2e_i12));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_i_2e_01_2e_i12) < 32 && "Write access out of array 'ad' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%36, i8* %%37, align 1, !dbg !156, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_135_count);
  *llvm_cbe_tmp__43 = llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__42);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add i64 %%i.01.i12, 1, !dbg !15 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__44 = (unsigned long long )((unsigned long long )(llvm_cbe_i_2e_01_2e_i12&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__44&18446744073709551615ull)));
  if (((llvm_cbe_tmp__44&18446744073709551615ULL) == (32ull&18446744073709551615ULL))) {
    goto llvm_cbe_init_buffer_2e_exit15;
  } else {
    llvm_cbe_i_2e_01_2e_i12__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__44;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_i14;
  }

  } while (1); /* end of syntactic loop '.lr.ph.i14' */
llvm_cbe_init_buffer_2e_exit15:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [32 x i8]* %%ad, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__45 = ( char *)(&llvm_cbe_ad[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds [256 x i8]* %%fileName, i64 0, i64 0, !dbg !15 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__46 = ( char *)(&llvm_cbe_fileName[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 256
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = call i32 (i8*, i8*, ...)* @sprintf(i8* %%40, i8* getelementptr inbounds ([23 x i8]* @aesl_internal_.str1, i64 0, i64 0), i32 128, i32 128) nounwind, !dbg !15 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_141_count);
  sprintf(( char *)llvm_cbe_tmp__46, ( char *)((&aesl_internal__OC_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 23
#endif
])), 128u, 128u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",128u);
printf("\nArgument  = 0x%X",128u);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__47);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fp.0 = call %%struct._iobuf* @fopen(i8* %%40, i8* getelementptr inbounds ([2 x i8]* @aesl_internal_.str2, i64 0, i64 0)) nounwind, !dbg !15 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_fp_2e_0_count);
  llvm_cbe_fp_2e_0 = (l_struct_OC__iobuf *)aesl_fopen(( char *)llvm_cbe_tmp__46, ( char *)((&aesl_internal__OC_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 2
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn fp.0 = 0x%X",llvm_cbe_fp_2e_0);
}
  if (((llvm_cbe_fp_2e_0) == (((l_struct_OC__iobuf *)/*NULL*/0)))) {
    goto llvm_cbe_tmp__98;
  } else {
    goto llvm_cbe__2e_preheader53;
  }

llvm_cbe__2e_preheader53:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = getelementptr inbounds [48 x i8]* %%ct, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__48 = ( char *)(&llvm_cbe_ct[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds [32 x i8]* %%msg2, i64 0, i64 0, !dbg !16 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_146_count);
  llvm_cbe_tmp__49 = ( char *)(&llvm_cbe_msg2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_count_2e_056__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
  llvm_cbe_mlen_2e_054__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_preheader;

llvm_cbe_tmp__98:
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = call %%struct._iobuf* @__iob_func() nounwind, !dbg !16 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__50 = (l_struct_OC__iobuf *)__iob_func();
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__50);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = getelementptr inbounds %%struct._iobuf* %%46, i64 2, !dbg !16 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_149_count);
  llvm_cbe_tmp__51 = (l_struct_OC__iobuf *)(&llvm_cbe_tmp__50[(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%47, i8* getelementptr inbounds ([30 x i8]* @aesl_internal_.str3, i64 0, i64 0), i8* %%40) nounwind, !dbg !16 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_150_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_tmp__51, ( char *)((&aesl_internal__OC_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 30
#endif
])), ( char *)llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__52);
}
  llvm_cbe__2e_0__PHI_TEMPORARY = (unsigned int )4294967295u;   /* for PHI node */
  goto llvm_cbe_tmp__99;

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%count.056 = phi i32 [ 1, %%.preheader53 ], [ %%count.1, %%.loopexit  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_count_2e_056_count);
  llvm_cbe_count_2e_056 = (unsigned int )llvm_cbe_count_2e_056__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ncount.056 = 0x%X",llvm_cbe_count_2e_056);
printf("\n = 0x%X",1u);
printf("\ncount.1 = 0x%X",llvm_cbe_count_2e_1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%mlen.054 = phi i64 [ 0, %%.preheader53 ], [ %%109, %%.loopexit  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_mlen_2e_054_count);
  llvm_cbe_mlen_2e_054 = (unsigned long long )llvm_cbe_mlen_2e_054__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nmlen.054 = 0x%I64X",llvm_cbe_mlen_2e_054);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__96);
}
  llvm_cbe_count_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_count_2e_056;   /* for PHI node */
  llvm_cbe_adlen_2e_0__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe_tmp__100;

llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%109 = add i64 %%mlen.054, 1, !dbg !26 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__96 = (unsigned long long )((unsigned long long )(llvm_cbe_mlen_2e_054&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__96&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__96&18446744073709551615ULL) < ((unsigned long long )33ull&18446744073709551615ULL))) {
    llvm_cbe_count_2e_056__PHI_TEMPORARY = (unsigned int )llvm_cbe_count_2e_1;   /* for PHI node */
    llvm_cbe_mlen_2e_054__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__96;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_ret_val_2e_171__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_critedge;
  }

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__100:
if (AESL_DEBUG_TRACE)
printf("\n  %%count.1 = phi i32 [ %%60, %%103 ], [ %%count.056, %%.preheader  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_count_2e_1_count);
  llvm_cbe_count_2e_1 = (unsigned int )llvm_cbe_count_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ncount.1 = 0x%X",llvm_cbe_count_2e_1);
printf("\n = 0x%X",llvm_cbe_tmp__60);
printf("\ncount.056 = 0x%X",llvm_cbe_count_2e_056);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%adlen.0 = phi i64 [ %%106, %%103 ], [ 0, %%.preheader  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_adlen_2e_0_count);
  llvm_cbe_adlen_2e_0 = (unsigned long long )llvm_cbe_adlen_2e_0__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nadlen.0 = 0x%I64X",llvm_cbe_adlen_2e_0);
printf("\n = 0x%I64X",llvm_cbe_tmp__94);
printf("\n = 0x%I64X",0ull);
}
  if ((((unsigned long long )llvm_cbe_adlen_2e_0&18446744073709551615ULL) < ((unsigned long long )33ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__101;
  } else {
    goto llvm_cbe__2e_loopexit;
  }

llvm_cbe_tmp__102:
if (AESL_DEBUG_TRACE)
printf("\n  %%104 = call i32 @memcmp(i8* %%35, i8* %%44, i64 %%mlen.054) nounwind, !dbg !25 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_280_count);
  llvm_cbe_tmp__93 = (unsigned int )memcmp(( char *)llvm_cbe_tmp__41, ( char *)llvm_cbe_tmp__49, llvm_cbe_mlen_2e_054);
if (AESL_DEBUG_TRACE) {
printf("\nArgument mlen.054 = 0x%I64X",llvm_cbe_mlen_2e_054);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__93);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%106 = add i64 %%adlen.0, 1, !dbg !25 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__94 = (unsigned long long )((unsigned long long )(llvm_cbe_adlen_2e_0&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__94&18446744073709551615ull)));
  if (((llvm_cbe_tmp__93&4294967295U) == (0u&4294967295U))) {
    llvm_cbe_count_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__60;   /* for PHI node */
    llvm_cbe_adlen_2e_0__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__94;   /* for PHI node */
    goto llvm_cbe_tmp__100;
  } else {
    goto llvm_cbe_tmp__103;
  }

llvm_cbe_tmp__104:
if (AESL_DEBUG_TRACE)
printf("\n  %%99 = load i64* %%mlen2, align 8, !dbg !250, !tbaa !22 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_274_count);
  llvm_cbe_tmp__91 = (unsigned long long )*(&llvm_cbe_mlen2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__91);
  if (((llvm_cbe_mlen_2e_054&18446744073709551615ULL) == (llvm_cbe_tmp__91&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__102;
  } else {
    goto llvm_cbe_tmp__105;
  }

llvm_cbe_fprint_bstr_2e_exit:
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.i = call i32 @fputc(i32 10, %%struct._iobuf* %%fp.0) nounwind, !dbg !24 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_fputc_2e_i_count);
  fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc.i = 0x%X",llvm_cbe_fputc_2e_i);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc = call i32 @fputc(i32 10, %%struct._iobuf* %%fp.0), !dbg !24 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_fputc_count);
  fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc = 0x%X",llvm_cbe_fputc);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%93 = load i64* %%clen, align 8, !dbg !162, !tbaa !22 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_255_count);
  llvm_cbe_tmp__88 = (unsigned long long )*(&llvm_cbe_clen);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%94 = call i32 @crypto_aead_decrypt(i8* %%44, i64* %%mlen2, i8* null, i8* %%43, i64 %%93, i8* %%39, i64 %%adlen.0, i8* %%16, i8* %%0) nounwind, !dbg !16 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__89 = (unsigned int )crypto_aead_decrypt(( char *)llvm_cbe_tmp__49, (signed long long *)(&llvm_cbe_mlen2), ( char *)(( char *)/*NULL*/0), ( char *)llvm_cbe_tmp__48, llvm_cbe_tmp__88, ( char *)llvm_cbe_tmp__45, llvm_cbe_adlen_2e_0, ( char *)llvm_cbe_tmp__22, ( char *)llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__88);
printf("\nArgument adlen.0 = 0x%I64X",llvm_cbe_adlen_2e_0);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__89);
}
  if (((llvm_cbe_tmp__89&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__104;
  } else {
    goto llvm_cbe_tmp__106;
  }

llvm_cbe_tmp__107:
if (AESL_DEBUG_TRACE)
printf("\n  %%85 = load i64* %%clen, align 8, !dbg !228, !tbaa !22 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_228_count);
  llvm_cbe_tmp__81 = (unsigned long long )*(&llvm_cbe_clen);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__81);
if (AESL_DEBUG_TRACE)
printf("\n  %%86 = call i64 @fwrite(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str10, i64 0, i64 0), i64 5, i64 1, %%struct._iobuf* %%fp.0), !dbg !23 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_233_count);
  fwrite(( char *)((&aesl_internal__OC_str10[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), 5ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",5ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__82);
}
  if (((llvm_cbe_tmp__81&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_fprint_bstr_2e_exit;
  } else {
    llvm_cbe_i_2e_01_2e_i1__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_i3;
  }

llvm_cbe_fprint_bstr_2e_exit21:
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.i20 = call i32 @fputc(i32 10, %%struct._iobuf* %%fp.0) nounwind, !dbg !22 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_fputc_2e_i20_count);
  fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc.i20 = 0x%X",llvm_cbe_fputc_2e_i20);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%80 = call i32 @apatb_crypto_aead_encrypt_sw(i8* %%43, i64* %%clen, i8* %%35, i64 %%mlen.054, i8* %%39, i64 %%adlen.0, i8* null, i8* %%16, i8* %%0) nounwind, !dbg !16 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__79 = (unsigned int )apatb_crypto_aead_encrypt_sw(( char *)llvm_cbe_tmp__48, (signed long long *)(&llvm_cbe_clen), ( char *)llvm_cbe_tmp__41, llvm_cbe_mlen_2e_054, ( char *)llvm_cbe_tmp__45, llvm_cbe_adlen_2e_0, ( char *)(( char *)/*NULL*/0), ( char *)llvm_cbe_tmp__22, ( char *)llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE) {
printf("\nArgument mlen.054 = 0x%I64X",llvm_cbe_mlen_2e_054);
printf("\nArgument adlen.0 = 0x%I64X",llvm_cbe_adlen_2e_0);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__79);
}
  if (((llvm_cbe_tmp__79&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__107;
  } else {
    goto llvm_cbe_tmp__108;
  }

llvm_cbe_fprint_bstr_2e_exit39:
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.i38 = call i32 @fputc(i32 10, %%struct._iobuf* %%fp.0) nounwind, !dbg !20 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_fputc_2e_i38_count);
  fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc.i38 = 0x%X",llvm_cbe_fputc_2e_i38);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%73 = call i64 @fwrite(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str8, i64 0, i64 0), i64 5, i64 1, %%struct._iobuf* %%fp.0), !dbg !21 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_199_count);
  fwrite(( char *)((&aesl_internal__OC_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), 5ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",5ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__73);
}
  if (((llvm_cbe_adlen_2e_0&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_fprint_bstr_2e_exit21;
  } else {
    llvm_cbe_i_2e_01_2e_i17__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_i19;
  }

llvm_cbe_fprint_bstr_2e_exit33:
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.i32 = call i32 @fputc(i32 10, %%struct._iobuf* %%fp.0) nounwind, !dbg !19 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_fputc_2e_i32_count);
  fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc.i32 = 0x%X",llvm_cbe_fputc_2e_i32);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = call i64 @fwrite(i8* getelementptr inbounds ([6 x i8]* @aesl_internal_.str7, i64 0, i64 0), i64 5, i64 1, %%struct._iobuf* %%fp.0), !dbg !20 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_186_count);
  fwrite(( char *)((&aesl_internal__OC_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 6
#endif
])), 5ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",5ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__67);
}
  if (((llvm_cbe_mlen_2e_054&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_fprint_bstr_2e_exit39;
  } else {
    llvm_cbe_i_2e_01_2e_i35__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_i37;
  }

  do {     /* Syntactic loop '.lr.ph.i31' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_i31:
if (AESL_DEBUG_TRACE)
printf("\n  %%i.01.i29 = phi i64 [ %%66, %%.lr.ph.i31 ], [ 0, %%fprint_bstr.exit27  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_i_2e_01_2e_i29_count);
  llvm_cbe_i_2e_01_2e_i29 = (unsigned long long )llvm_cbe_i_2e_01_2e_i29__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i29 = 0x%I64X",llvm_cbe_i_2e_01_2e_i29);
printf("\n = 0x%I64X",llvm_cbe_tmp__66);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = getelementptr inbounds [16 x i8]* %%nonce, i64 0, i64 %%i.01.i29, !dbg !19 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__62 = ( char *)(&llvm_cbe_nonce[(((signed long long )llvm_cbe_i_2e_01_2e_i29))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i29 = 0x%I64X",((signed long long )llvm_cbe_i_2e_01_2e_i29));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_i_2e_01_2e_i29) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'nonce' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i8* %%62, align 1, !dbg !196, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__63 = (unsigned char )*llvm_cbe_tmp__62;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = zext i8 %%63 to i32, !dbg !19 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_179_count);
  llvm_cbe_tmp__64 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__63&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp.0, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str16, i64 0, i64 0), i32 %%64) nounwind, !dbg !19 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_180_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_fp_2e_0, ( char *)((&aesl_internal__OC_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__64);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__65);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = add i64 %%i.01.i29, 1, !dbg !19 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__66 = (unsigned long long )((unsigned long long )(llvm_cbe_i_2e_01_2e_i29&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__66&18446744073709551615ull)));
  if (((llvm_cbe_tmp__66&18446744073709551615ULL) == (16ull&18446744073709551615ULL))) {
    goto llvm_cbe_fprint_bstr_2e_exit33;
  } else {
    llvm_cbe_i_2e_01_2e_i29__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__66;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_i31;
  }

  } while (1); /* end of syntactic loop '.lr.ph.i31' */
llvm_cbe_fprint_bstr_2e_exit27:
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = add nsw i32 %%count.1, 1, !dbg !17 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__60 = (unsigned int )((unsigned int )(llvm_cbe_count_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__60&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc.i26 = call i32 @fputc(i32 10, %%struct._iobuf* %%fp.0) nounwind, !dbg !18 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_fputc_2e_i26_count);
  fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc.i26 = 0x%X",llvm_cbe_fputc_2e_i26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = call i64 @fwrite(i8* getelementptr inbounds ([9 x i8]* @aesl_internal_.str6, i64 0, i64 0), i64 8, i64 1, %%struct._iobuf* %%fp.0), !dbg !19 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_174_count);
  fwrite(( char *)((&aesl_internal__OC_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 9
#endif
])), 8ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",8ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__61);
}
  llvm_cbe_i_2e_01_2e_i29__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_i31;

  do {     /* Syntactic loop '.lr.ph.i25' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_i25:
if (AESL_DEBUG_TRACE)
printf("\n  %%i.01.i23 = phi i64 [ %%59, %%.lr.ph.i25 ], [ 0, %%52  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_i_2e_01_2e_i23_count);
  llvm_cbe_i_2e_01_2e_i23 = (unsigned long long )llvm_cbe_i_2e_01_2e_i23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i23 = 0x%I64X",llvm_cbe_i_2e_01_2e_i23);
printf("\n = 0x%I64X",llvm_cbe_tmp__59);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = getelementptr inbounds [16 x i8]* %%key, i64 0, i64 %%i.01.i23, !dbg !18 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__55 = ( char *)(&llvm_cbe_key[(((signed long long )llvm_cbe_i_2e_01_2e_i23))
#ifdef AESL_BC_SIM
 % 16
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i23 = 0x%I64X",((signed long long )llvm_cbe_i_2e_01_2e_i23));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_i_2e_01_2e_i23) < 16)) fprintf(stderr, "%s:%d: warning: Read access out of array 'key' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load i8* %%55, align 1, !dbg !182, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__56 = (unsigned char )*llvm_cbe_tmp__55;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = zext i8 %%56 to i32, !dbg !18 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__56&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp.0, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str16, i64 0, i64 0), i32 %%57) nounwind, !dbg !18 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_166_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_fp_2e_0, ( char *)((&aesl_internal__OC_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__57);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__58);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = add i64 %%i.01.i23, 1, !dbg !18 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__59 = (unsigned long long )((unsigned long long )(llvm_cbe_i_2e_01_2e_i23&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__59&18446744073709551615ull)));
  if (((llvm_cbe_tmp__59&18446744073709551615ULL) == (16ull&18446744073709551615ULL))) {
    goto llvm_cbe_fprint_bstr_2e_exit27;
  } else {
    llvm_cbe_i_2e_01_2e_i23__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__59;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_i25;
  }

  } while (1); /* end of syntactic loop '.lr.ph.i25' */
llvm_cbe_tmp__101:
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp.0, i8* getelementptr inbounds ([12 x i8]* @aesl_internal_.str4, i64 0, i64 0), i32 %%count.1) nounwind, !dbg !17 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_156_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_fp_2e_0, ( char *)((&aesl_internal__OC_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 12
#endif
])), llvm_cbe_count_2e_1);
if (AESL_DEBUG_TRACE) {
printf("\nArgument count.1 = 0x%X",llvm_cbe_count_2e_1);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__53);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = call i64 @fwrite(i8* getelementptr inbounds ([7 x i8]* @aesl_internal_.str5, i64 0, i64 0), i64 6, i64 1, %%struct._iobuf* %%fp.0), !dbg !17 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_160_count);
  fwrite(( char *)((&aesl_internal__OC_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 7
#endif
])), 6ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",6ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__54);
}
  llvm_cbe_i_2e_01_2e_i23__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
  goto llvm_cbe__2e_lr_2e_ph_2e_i25;

  do {     /* Syntactic loop '.lr.ph.i37' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_i37:
if (AESL_DEBUG_TRACE)
printf("\n  %%i.01.i35 = phi i64 [ %%72, %%.lr.ph.i37 ], [ 0, %%fprint_bstr.exit33  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_i_2e_01_2e_i35_count);
  llvm_cbe_i_2e_01_2e_i35 = (unsigned long long )llvm_cbe_i_2e_01_2e_i35__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i35 = 0x%I64X",llvm_cbe_i_2e_01_2e_i35);
printf("\n = 0x%I64X",llvm_cbe_tmp__72);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = getelementptr inbounds [32 x i8]* %%msg, i64 0, i64 %%i.01.i35, !dbg !20 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__68 = ( char *)(&llvm_cbe_msg[(((signed long long )llvm_cbe_i_2e_01_2e_i35))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i35 = 0x%I64X",((signed long long )llvm_cbe_i_2e_01_2e_i35));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_i_2e_01_2e_i35) < 32)) fprintf(stderr, "%s:%d: warning: Read access out of array 'msg' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%69 = load i8* %%68, align 1, !dbg !206, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_190_count);
  llvm_cbe_tmp__69 = (unsigned char )*llvm_cbe_tmp__68;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%70 = zext i8 %%69 to i32, !dbg !20 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_191_count);
  llvm_cbe_tmp__70 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__69&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE)
printf("\n  %%71 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp.0, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str16, i64 0, i64 0), i32 %%70) nounwind, !dbg !20 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_192_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_fp_2e_0, ( char *)((&aesl_internal__OC_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__70);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__70);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__71);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%72 = add i64 %%i.01.i35, 1, !dbg !20 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_193_count);
  llvm_cbe_tmp__72 = (unsigned long long )((unsigned long long )(llvm_cbe_i_2e_01_2e_i35&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__72&18446744073709551615ull)));
  if (((llvm_cbe_tmp__72&18446744073709551615ULL) == (llvm_cbe_mlen_2e_054&18446744073709551615ULL))) {
    goto llvm_cbe_fprint_bstr_2e_exit39;
  } else {
    llvm_cbe_i_2e_01_2e_i35__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__72;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_i37;
  }

  } while (1); /* end of syntactic loop '.lr.ph.i37' */
  do {     /* Syntactic loop '.lr.ph.i19' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_i19:
if (AESL_DEBUG_TRACE)
printf("\n  %%i.01.i17 = phi i64 [ %%79, %%.lr.ph.i19 ], [ 0, %%fprint_bstr.exit39  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_i_2e_01_2e_i17_count);
  llvm_cbe_i_2e_01_2e_i17 = (unsigned long long )llvm_cbe_i_2e_01_2e_i17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i17 = 0x%I64X",llvm_cbe_i_2e_01_2e_i17);
printf("\n = 0x%I64X",llvm_cbe_tmp__78);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%75 = getelementptr inbounds [32 x i8]* %%ad, i64 0, i64 %%i.01.i17, !dbg !22 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_203_count);
  llvm_cbe_tmp__74 = ( char *)(&llvm_cbe_ad[(((signed long long )llvm_cbe_i_2e_01_2e_i17))
#ifdef AESL_BC_SIM
 % 32
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i17 = 0x%I64X",((signed long long )llvm_cbe_i_2e_01_2e_i17));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_i_2e_01_2e_i17) < 32)) fprintf(stderr, "%s:%d: warning: Read access out of array 'ad' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%76 = load i8* %%75, align 1, !dbg !220, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_204_count);
  llvm_cbe_tmp__75 = (unsigned char )*llvm_cbe_tmp__74;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%77 = zext i8 %%76 to i32, !dbg !22 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__76 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__75&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE)
printf("\n  %%78 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp.0, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str16, i64 0, i64 0), i32 %%77) nounwind, !dbg !22 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_206_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_fp_2e_0, ( char *)((&aesl_internal__OC_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__76);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__76);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__77);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%79 = add i64 %%i.01.i17, 1, !dbg !22 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__78 = (unsigned long long )((unsigned long long )(llvm_cbe_i_2e_01_2e_i17&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)));
  if (((llvm_cbe_tmp__78&18446744073709551615ULL) == (llvm_cbe_adlen_2e_0&18446744073709551615ULL))) {
    goto llvm_cbe_fprint_bstr_2e_exit21;
  } else {
    llvm_cbe_i_2e_01_2e_i17__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__78;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_i19;
  }

  } while (1); /* end of syntactic loop '.lr.ph.i19' */
  do {     /* Syntactic loop '.lr.ph.i3' to make GCC happy */
llvm_cbe__2e_lr_2e_ph_2e_i3:
if (AESL_DEBUG_TRACE)
printf("\n  %%i.01.i1 = phi i64 [ %%92, %%.lr.ph.i3 ], [ 0, %%84  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_i_2e_01_2e_i1_count);
  llvm_cbe_i_2e_01_2e_i1 = (unsigned long long )llvm_cbe_i_2e_01_2e_i1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i1 = 0x%I64X",llvm_cbe_i_2e_01_2e_i1);
printf("\n = 0x%I64X",llvm_cbe_tmp__87);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%88 = getelementptr inbounds [48 x i8]* %%ct, i64 0, i64 %%i.01.i1, !dbg !24 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_237_count);
  llvm_cbe_tmp__83 = ( char *)(&llvm_cbe_ct[(((signed long long )llvm_cbe_i_2e_01_2e_i1))
#ifdef AESL_BC_SIM
 % 48
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\ni.01.i1 = 0x%I64X",((signed long long )llvm_cbe_i_2e_01_2e_i1));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_i_2e_01_2e_i1) < 48)) fprintf(stderr, "%s:%d: warning: Read access out of array 'ct' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%89 = load i8* %%88, align 1, !dbg !242, !tbaa !13 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__84 = (unsigned char )*llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__84);
if (AESL_DEBUG_TRACE)
printf("\n  %%90 = zext i8 %%89 to i32, !dbg !24 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_239_count);
  llvm_cbe_tmp__85 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__84&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n  %%91 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp.0, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str16, i64 0, i64 0), i32 %%90) nounwind, !dbg !24 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_240_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_fp_2e_0, ( char *)((&aesl_internal__OC_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__85);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__86);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%92 = add i64 %%i.01.i1, 1, !dbg !24 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_241_count);
  llvm_cbe_tmp__87 = (unsigned long long )((unsigned long long )(llvm_cbe_i_2e_01_2e_i1&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__87&18446744073709551615ull)));
  if (((llvm_cbe_tmp__87&18446744073709551615ULL) == (llvm_cbe_tmp__81&18446744073709551615ULL))) {
    goto llvm_cbe_fprint_bstr_2e_exit;
  } else {
    llvm_cbe_i_2e_01_2e_i1__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__87;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph_2e_i3;
  }

  } while (1); /* end of syntactic loop '.lr.ph.i3' */
  } while (1); /* end of syntactic loop '' */
  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe_tmp__108:
if (AESL_DEBUG_TRACE)
printf("\n  %%83 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp.0, i8* getelementptr inbounds ([35 x i8]* @aesl_internal_.str9, i64 0, i64 0), i32 %%80) nounwind, !dbg !22 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_214_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_fp_2e_0, ( char *)((&aesl_internal__OC_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 35
#endif
])), llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__79);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__80);
}
  llvm_cbe_ret_val_2e_171__PHI_TEMPORARY = (unsigned int )4294967292u;   /* for PHI node */
  goto llvm_cbe__2e_critedge;

llvm_cbe_tmp__106:
if (AESL_DEBUG_TRACE)
printf("\n  %%97 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp.0, i8* getelementptr inbounds ([35 x i8]* @aesl_internal_.str12, i64 0, i64 0), i32 %%94) nounwind, !dbg !24 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_260_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_fp_2e_0, ( char *)((&aesl_internal__OC_str12[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 35
#endif
])), llvm_cbe_tmp__89);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__89);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__90);
}
  llvm_cbe_ret_val_2e_171__PHI_TEMPORARY = (unsigned int )4294967292u;   /* for PHI node */
  goto llvm_cbe__2e_critedge;

llvm_cbe_tmp__105:
if (AESL_DEBUG_TRACE)
printf("\n  %%102 = call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp.0, i8* getelementptr inbounds ([72 x i8]* @aesl_internal_.str13, i64 0, i64 0), i64 %%99, i64 %%mlen.054) nounwind, !dbg !25 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_277_count);
  fprintf((l_struct_OC__iobuf *)llvm_cbe_fp_2e_0, ( char *)((&aesl_internal__OC_str13[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 72
#endif
])), llvm_cbe_tmp__91, llvm_cbe_mlen_2e_054);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__91);
printf("\nArgument mlen.054 = 0x%I64X",llvm_cbe_mlen_2e_054);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__92);
}
  llvm_cbe_ret_val_2e_171__PHI_TEMPORARY = (unsigned int )4294967292u;   /* for PHI node */
  goto llvm_cbe__2e_critedge;

llvm_cbe_tmp__103:
if (AESL_DEBUG_TRACE)
printf("\n  %%108 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @aesl_internal_.str14, i64 0, i64 0), i64 50, i64 1, %%struct._iobuf* %%fp.0), !dbg !25 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_285_count);
  fwrite(( char *)((&aesl_internal__OC_str14[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 51
#endif
])), 50ull, 1ull, (l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",50ull);
printf("\nArgument  = 0x%I64X",1ull);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__95);
}
  llvm_cbe_ret_val_2e_171__PHI_TEMPORARY = (unsigned int )4294967292u;   /* for PHI node */
  goto llvm_cbe__2e_critedge;

llvm_cbe__2e_critedge:
if (AESL_DEBUG_TRACE)
printf("\n  %%ret_val.171 = phi i32 [ -4, %%82 ], [ -4, %%96 ], [ -4, %%101 ], [ -4, %%107 ], [ 0, %%.loopexit  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_ret_val_2e_171_count);
  llvm_cbe_ret_val_2e_171 = (unsigned int )llvm_cbe_ret_val_2e_171__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nret_val.171 = 0x%X",llvm_cbe_ret_val_2e_171);
printf("\n = 0x%X",4294967292u);
printf("\n = 0x%X",4294967292u);
printf("\n = 0x%X",4294967292u);
printf("\n = 0x%X",4294967292u);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%111 = call i32 @fclose(%%struct._iobuf* %%fp.0) nounwind, !dbg !26 for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe_291_count);
  fclose((l_struct_OC__iobuf *)llvm_cbe_fp_2e_0);
if (AESL_DEBUG_TRACE) {
printf("\nReturn  = 0x%X",llvm_cbe_tmp__97);
}
  llvm_cbe__2e_0__PHI_TEMPORARY = (unsigned int )llvm_cbe_ret_val_2e_171;   /* for PHI node */
  goto llvm_cbe_tmp__99;

llvm_cbe_tmp__99:
if (AESL_DEBUG_TRACE)
printf("\n  %%.0 = phi i32 [ -1, %%45 ], [ %%ret_val.171, %%.critedge  for 0x%I64xth hint within @generate_test_vectors  --> \n", ++aesl_llvm_cbe__2e_0_count);
  llvm_cbe__2e_0 = (unsigned int )llvm_cbe__2e_0__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.0 = 0x%X",llvm_cbe__2e_0);
printf("\n = 0x%X",4294967295u);
printf("\nret_val.171 = 0x%X",llvm_cbe_ret_val_2e_171);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @generate_test_vectors}\n");
  return llvm_cbe__2e_0;
}


void init_buffer( char *llvm_cbe_buffer, signed long long llvm_cbe_numbytes) {
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_i_2e_01_count = 0;
  unsigned long long llvm_cbe_i_2e_01;
  unsigned long long llvm_cbe_i_2e_01__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  unsigned char llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
   char *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  unsigned long long llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @init_buffer\n");
  if (((llvm_cbe_numbytes&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_i_2e_01__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%i.01 = phi i64 [ %%4, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_i_2e_01_count);
  llvm_cbe_i_2e_01 = (unsigned long long )llvm_cbe_i_2e_01__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ni.01 = 0x%I64X",llvm_cbe_i_2e_01);
printf("\n = 0x%I64X",llvm_cbe_tmp__111);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = trunc i64 %%i.01 to i8, !dbg !11 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_299_count);
  llvm_cbe_tmp__109 = (unsigned char )((unsigned char )llvm_cbe_i_2e_01&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%buffer, i64 %%i.01, !dbg !11 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_300_count);
  llvm_cbe_tmp__110 = ( char *)(&llvm_cbe_buffer[(((signed long long )llvm_cbe_i_2e_01))]);
if (AESL_DEBUG_TRACE) {
printf("\ni.01 = 0x%I64X",((signed long long )llvm_cbe_i_2e_01));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%2, i8* %%3, align 1, !dbg !116, !tbaa !11 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_301_count);
  *llvm_cbe_tmp__110 = llvm_cbe_tmp__109;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = add i64 %%i.01, 1, !dbg !11 for 0x%I64xth hint within @init_buffer  --> \n", ++aesl_llvm_cbe_302_count);
  llvm_cbe_tmp__111 = (unsigned long long )((unsigned long long )(llvm_cbe_i_2e_01&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__111&18446744073709551615ull)));
  if (((llvm_cbe_tmp__111&18446744073709551615ULL) == (llvm_cbe_numbytes&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_i_2e_01__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__111;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @init_buffer}\n");
  return;
}


void fprint_bstr(l_struct_OC__iobuf *llvm_cbe_fp,  char *llvm_cbe_label,  char *llvm_cbe_data, signed long long llvm_cbe_length) {
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputs_count = 0;
  unsigned int llvm_cbe_fputs;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_i_2e_01_count = 0;
  unsigned long long llvm_cbe_i_2e_01;
  unsigned long long llvm_cbe_i_2e_01__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
   char *llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  unsigned char llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  unsigned int llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  unsigned int llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  unsigned long long llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_fputc_count = 0;
  unsigned int llvm_cbe_fputc;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fprint_bstr\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%fputs = tail call i32 @fputs(i8* %%label, %%struct._iobuf* %%fp), !dbg !11 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_fputs_count);
   /*tail*/ fputs(( char *)llvm_cbe_label, (l_struct_OC__iobuf *)llvm_cbe_fp);
if (AESL_DEBUG_TRACE) {
printf("\nReturn fputs = 0x%X",llvm_cbe_fputs);
}
  if (((llvm_cbe_length&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_i_2e_01__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%i.01 = phi i64 [ %%6, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_i_2e_01_count);
  llvm_cbe_i_2e_01 = (unsigned long long )llvm_cbe_i_2e_01__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\ni.01 = 0x%I64X",llvm_cbe_i_2e_01);
printf("\n = 0x%I64X",llvm_cbe_tmp__116);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds i8* %%data, i64 %%i.01, !dbg !11 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_313_count);
  llvm_cbe_tmp__112 = ( char *)(&llvm_cbe_data[(((signed long long )llvm_cbe_i_2e_01))]);
if (AESL_DEBUG_TRACE) {
printf("\ni.01 = 0x%I64X",((signed long long )llvm_cbe_i_2e_01));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i8* %%2, align 1, !dbg !119, !tbaa !12 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_314_count);
  llvm_cbe_tmp__113 = (unsigned char )*llvm_cbe_tmp__112;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i8 %%3 to i32, !dbg !11 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_315_count);
  llvm_cbe_tmp__114 = (unsigned int )((unsigned int )(unsigned char )llvm_cbe_tmp__113&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = tail call i32 (%%struct._iobuf*, i8*, ...)* @fprintf(%%struct._iobuf* %%fp, i8* getelementptr inbounds ([5 x i8]* @aesl_internal_.str16, i64 0, i64 0), i32 %%4) nounwind, !dbg !11 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_316_count);
   /*tail*/ fprintf((l_struct_OC__iobuf *)llvm_cbe_fp, ( char *)((&aesl_internal__OC_str16[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
])), llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__114);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__115);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = add i64 %%i.01, 1, !dbg !12 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_317_count);
  llvm_cbe_tmp__116 = (unsigned long long )((unsigned long long )(llvm_cbe_i_2e_01&18446744073709551615ull)) + ((unsigned long long )(1ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__116&18446744073709551615ull)));
  if (((llvm_cbe_tmp__116&18446744073709551615ULL) == (llvm_cbe_length&18446744073709551615ULL))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_i_2e_01__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__116;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%fputc = tail call i32 @fputc(i32 10, %%struct._iobuf* %%fp), !dbg !12 for 0x%I64xth hint within @fprint_bstr  --> \n", ++aesl_llvm_cbe_fputc_count);
   /*tail*/ fputc(10u, (l_struct_OC__iobuf *)llvm_cbe_fp);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",10u);
printf("\nReturn fputc = 0x%X",llvm_cbe_fputc);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fprint_bstr}\n");
  return;
}

