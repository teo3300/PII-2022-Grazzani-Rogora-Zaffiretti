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
typedef struct l_struct_OC_state_t l_struct_OC_state_t;

/* Structure contents */
struct l_struct_OC_state_t {
  unsigned long long field0;
  unsigned long long field1;
  unsigned long long field2;
  unsigned long long field3;
  unsigned long long field4;
};


/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
signed int crypto_aead_encrypt( char *llvm_cbe_c, signed long long *llvm_cbe_clen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_ad, signed long long llvm_cbe_adlen,  char *llvm_cbe_nsec,  char *llvm_cbe_npub,  char *llvm_cbe_k);
static signed long long aesl_internal_LOADBYTES( char *llvm_cbe_bytes, signed int llvm_cbe_n);
static void aesl_internal_P12(l_struct_OC_state_t *llvm_cbe_s);
static void aesl_internal_P6(l_struct_OC_state_t *llvm_cbe_s);
static void aesl_internal_STOREBYTES( char *llvm_cbe_bytes, signed long long llvm_cbe_x, signed int llvm_cbe_n);
static void aesl_internal_ROUND(l_struct_OC_state_t *llvm_cbe_s,  char llvm_cbe_C);
static signed long long aesl_internal_ROR(signed long long llvm_cbe_x, signed int llvm_cbe_n);


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

signed int crypto_aead_encrypt( char *llvm_cbe_c, signed long long *llvm_cbe_clen,  char *llvm_cbe_m, signed long long llvm_cbe_mlen,  char *llvm_cbe_ad, signed long long llvm_cbe_adlen,  char *llvm_cbe_nsec,  char *llvm_cbe_npub,  char *llvm_cbe_k) {
  static  unsigned long long aesl_llvm_cbe_s_count = 0;
  l_struct_OC_state_t llvm_cbe_s;    /* Address-exposed local */
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
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
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
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
   char *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned long long llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  signed long long *llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  signed long long *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  signed long long *llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  signed long long *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  signed long long *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned long long llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned long long llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned long long llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec19_count = 0;
  unsigned long long llvm_cbe__2e_rec19;
  unsigned long long llvm_cbe__2e_rec19__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  unsigned long long llvm_cbe_tmp__17__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
   char *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  unsigned long long llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  unsigned long long llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec20_count = 0;
  unsigned long long llvm_cbe__2e_rec20;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
   char *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  unsigned long long llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa6_count = 0;
   char *llvm_cbe__2e_lcssa6;
   char *llvm_cbe__2e_lcssa6__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa5_count = 0;
  unsigned long long llvm_cbe__2e_lcssa5;
  unsigned long long llvm_cbe__2e_lcssa5__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  unsigned long long llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  unsigned long long llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  unsigned long long llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  unsigned long long llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  unsigned long long llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  unsigned long long llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  unsigned long long llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned long long llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec_count = 0;
  unsigned long long llvm_cbe__2e_rec;
  unsigned long long llvm_cbe__2e_rec__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  unsigned long long llvm_cbe_tmp__34;
  unsigned long long llvm_cbe_tmp__34__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
   char *llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
   char *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  unsigned long long llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  unsigned long long llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  unsigned long long llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_rec14_count = 0;
  unsigned long long llvm_cbe__2e_rec14;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
   char *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
   char *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  unsigned long long llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa2_count = 0;
   char *llvm_cbe__2e_lcssa2;
   char *llvm_cbe__2e_lcssa2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa1_count = 0;
   char *llvm_cbe__2e_lcssa1;
   char *llvm_cbe__2e_lcssa1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned long long llvm_cbe__2e_lcssa;
  unsigned long long llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned long long llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned long long llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  unsigned long long llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  unsigned long long llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  unsigned long long llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  unsigned long long llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  unsigned long long llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  unsigned long long llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
   char *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  unsigned long long llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  unsigned long long llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  unsigned long long llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  unsigned long long llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  unsigned long long llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  unsigned long long llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  unsigned long long llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  unsigned long long llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_sum_count = 0;
  unsigned long long llvm_cbe__2e_sum;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
   char *llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @crypto_aead_encrypt\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = add i64 %%mlen, 16, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__1 = (unsigned long long )((unsigned long long )(llvm_cbe_mlen&18446744073709551615ull)) + ((unsigned long long )(16ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__1&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%1, i64* %%clen, align 8, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_41_count);
  *llvm_cbe_clen = llvm_cbe_tmp__1;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%k, i32 8), !dbg !12 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__2 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe_k, 8u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",8u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = getelementptr inbounds i8* %%k, i64 8, !dbg !12 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__3 = ( char *)(&llvm_cbe_k[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%3, i32 8), !dbg !12 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__4 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe_tmp__3, 8u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",8u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%npub, i32 8), !dbg !12 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__5 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe_npub, 8u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",8u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__5);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds i8* %%npub, i64 8, !dbg !12 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__6 = ( char *)(&llvm_cbe_npub[(((signed long long )8ull))]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%6, i32 8), !dbg !12 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__7 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe_tmp__6, 8u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",8u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__7);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds %%struct.state_t* %%s, i64 0, i32 0, !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__8 = (signed long long *)(&llvm_cbe_s.field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 -9205344418435956736, i64* %%8, align 8, !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_64_count);
  *llvm_cbe_tmp__8 = 9241399655273594880ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", 9241399655273594880ull);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = getelementptr inbounds %%struct.state_t* %%s, i64 0, i32 1, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__9 = (signed long long *)(&llvm_cbe_s.field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%2, i64* %%9, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_66_count);
  *llvm_cbe_tmp__9 = llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.state_t* %%s, i64 0, i32 2, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_67_count);
  llvm_cbe_tmp__10 = (signed long long *)(&llvm_cbe_s.field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%4, i64* %%10, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_68_count);
  *llvm_cbe_tmp__10 = llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds %%struct.state_t* %%s, i64 0, i32 3, !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_69_count);
  llvm_cbe_tmp__11 = (signed long long *)(&llvm_cbe_s.field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%5, i64* %%11, align 8, !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_70_count);
  *llvm_cbe_tmp__11 = llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds %%struct.state_t* %%s, i64 0, i32 4, !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_71_count);
  llvm_cbe_tmp__12 = (signed long long *)(&llvm_cbe_s.field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%7, i64* %%12, align 8, !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_72_count);
  *llvm_cbe_tmp__12 = llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_P12(%%struct.state_t* %%s), !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_73_count);
  aesl_internal_P12((l_struct_OC_state_t *)(&llvm_cbe_s));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i64* %%11, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__13 = (unsigned long long )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = xor i64 %%13, %%2, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__14 = (unsigned long long )llvm_cbe_tmp__13 ^ llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%14, i64* %%11, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_76_count);
  *llvm_cbe_tmp__11 = llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i64* %%12, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__15 = (unsigned long long )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = xor i64 %%15, %%4, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__16 = (unsigned long long )llvm_cbe_tmp__15 ^ llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__16);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%16, i64* %%12, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_79_count);
  *llvm_cbe_tmp__12 = llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__16);
  if (((llvm_cbe_adlen&18446744073709551615ULL) == (0ull&18446744073709551615ULL))) {
    goto llvm_cbe_tmp__63;
  } else {
    goto llvm_cbe__2e_preheader;
  }

llvm_cbe__2e_preheader:
  if ((((unsigned long long )llvm_cbe_adlen&18446744073709551615ULL) > ((unsigned long long )7ull&18446744073709551615ULL))) {
    llvm_cbe__2e_rec19__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__17__PHI_TEMPORARY = (unsigned long long )llvm_cbe_adlen;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph7;
  } else {
    llvm_cbe__2e_lcssa6__PHI_TEMPORARY = ( char *)llvm_cbe_ad;   /* for PHI node */
    llvm_cbe__2e_lcssa5__PHI_TEMPORARY = (unsigned long long )llvm_cbe_adlen;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge8;
  }

  do {     /* Syntactic loop '.lr.ph7' to make GCC happy */
llvm_cbe__2e_lr_2e_ph7:
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec19 = phi i64 [ %%.rec20, %%.lr.ph7 ], [ 0, %%.preheader  for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe__2e_rec19_count);
  llvm_cbe__2e_rec19 = (unsigned long long )llvm_cbe__2e_rec19__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec19 = 0x%I64X",llvm_cbe__2e_rec19);
printf("\n.rec20 = 0x%I64X",llvm_cbe__2e_rec20);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = phi i64 [ %%25, %%.lr.ph7 ], [ %%adlen, %%.preheader  for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__17 = (unsigned long long )llvm_cbe_tmp__17__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__17);
printf("\n = 0x%I64X",llvm_cbe_tmp__23);
printf("\nadlen = 0x%I64X",llvm_cbe_adlen);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr i8* %%ad, i64 %%.rec1 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__18 = ( char *)(&llvm_cbe_ad[(((signed long long )llvm_cbe__2e_rec19))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec19 = 0x%I64X",((signed long long )llvm_cbe__2e_rec19));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%20, i32 8), !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__19 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe_tmp__18, 8u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",8u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__19);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load i64* %%8, align 8, !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__20 = (unsigned long long )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__20);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = xor i64 %%22, %%21, !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__21 = (unsigned long long )llvm_cbe_tmp__20 ^ llvm_cbe_tmp__19;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%23, i64* %%8, align 8, !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_89_count);
  *llvm_cbe_tmp__8 = llvm_cbe_tmp__21;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_P6(%%struct.state_t* %%s), !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_90_count);
  aesl_internal_P6((l_struct_OC_state_t *)(&llvm_cbe_s));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec20 = add i64 %%.rec19, 8, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe__2e_rec20_count);
  llvm_cbe__2e_rec20 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec19&18446744073709551615ull)) + ((unsigned long long )(8ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec20 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec20&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = getelementptr inbounds i8* %%ad, i64 %%.rec20, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__22 = ( char *)(&llvm_cbe_ad[(((signed long long )llvm_cbe__2e_rec20))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec20 = 0x%I64X",((signed long long )llvm_cbe__2e_rec20));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add i64 %%19, -8, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_96_count);
  llvm_cbe_tmp__23 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__17&18446744073709551615ull)) + ((unsigned long long )(18446744073709551608ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__23&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__23&18446744073709551615ULL) > ((unsigned long long )7ull&18446744073709551615ULL))) {
    llvm_cbe__2e_rec19__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec20;   /* for PHI node */
    llvm_cbe_tmp__17__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__23;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph7;
  } else {
    llvm_cbe__2e_lcssa6__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__22;   /* for PHI node */
    llvm_cbe__2e_lcssa5__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__23;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge8;
  }

  } while (1); /* end of syntactic loop '.lr.ph7' */
llvm_cbe__2e__crit_edge8:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa6 = phi i8* [ %%ad, %%.preheader ], [ %%24, %%.lr.ph7  for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe__2e_lcssa6_count);
  llvm_cbe__2e_lcssa6 = ( char *)llvm_cbe__2e_lcssa6__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa5 = phi i64 [ %%adlen, %%.preheader ], [ %%25, %%.lr.ph7  for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe__2e_lcssa5_count);
  llvm_cbe__2e_lcssa5 = (unsigned long long )llvm_cbe__2e_lcssa5__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa5 = 0x%I64X",llvm_cbe__2e_lcssa5);
printf("\nadlen = 0x%I64X",llvm_cbe_adlen);
printf("\n = 0x%I64X",llvm_cbe_tmp__23);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = trunc i64 %%.lcssa5 to i32, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )llvm_cbe__2e_lcssa5&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%.lcssa6, i32 %%27), !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__25 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe__2e_lcssa6, llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__24);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__25);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i64* %%8, align 8, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_107_count);
  llvm_cbe_tmp__26 = (unsigned long long )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = shl i64 %%.lcssa5, 3, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__27 = (unsigned long long )llvm_cbe__2e_lcssa5 << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = sub i64 56, %%30, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_109_count);
  llvm_cbe_tmp__28 = (unsigned long long )((unsigned long long )(56ull&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__27&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__28&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = shl i64 128, %%31, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__29 = (unsigned long long )128ull << llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = xor i64 %%28, %%32, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__30 = (unsigned long long )llvm_cbe_tmp__25 ^ llvm_cbe_tmp__29;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__30);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = xor i64 %%33, %%29, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_112_count);
  llvm_cbe_tmp__31 = (unsigned long long )llvm_cbe_tmp__30 ^ llvm_cbe_tmp__26;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%34, i64* %%8, align 8, !dbg !11 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_113_count);
  *llvm_cbe_tmp__8 = llvm_cbe_tmp__31;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_P6(%%struct.state_t* %%s), !dbg !15 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_114_count);
  aesl_internal_P6((l_struct_OC_state_t *)(&llvm_cbe_s));
if (AESL_DEBUG_TRACE) {
}
  goto llvm_cbe_tmp__63;

llvm_cbe_tmp__63:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i64* %%12, align 8, !dbg !15 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__32 = (unsigned long long )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__32);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = xor i64 %%36, 1, !dbg !15 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__33 = (unsigned long long )llvm_cbe_tmp__32 ^ 1ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__33);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%37, i64* %%12, align 8, !dbg !15 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_118_count);
  *llvm_cbe_tmp__12 = llvm_cbe_tmp__33;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__33);
  if ((((unsigned long long )llvm_cbe_mlen&18446744073709551615ULL) > ((unsigned long long )7ull&18446744073709551615ULL))) {
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    llvm_cbe_tmp__34__PHI_TEMPORARY = (unsigned long long )llvm_cbe_mlen;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa2__PHI_TEMPORARY = ( char *)llvm_cbe_c;   /* for PHI node */
    llvm_cbe__2e_lcssa1__PHI_TEMPORARY = ( char *)llvm_cbe_m;   /* for PHI node */
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_mlen;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec = phi i64 [ %%.rec14, %%.lr.ph ], [ 0, %%35  for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe__2e_rec_count);
  llvm_cbe__2e_rec = (unsigned long long )llvm_cbe__2e_rec__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",llvm_cbe__2e_rec);
printf("\n.rec14 = 0x%I64X",llvm_cbe__2e_rec14);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = phi i64 [ %%47, %%.lr.ph ], [ %%mlen, %%35  for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_121_count);
  llvm_cbe_tmp__34 = (unsigned long long )llvm_cbe_tmp__34__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__34);
printf("\n = 0x%I64X",llvm_cbe_tmp__42);
printf("\nmlen = 0x%I64X",llvm_cbe_mlen);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr i8* %%m, i64 %%.re for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_122_count);
  llvm_cbe_tmp__35 = ( char *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = getelementptr i8* %%c, i64 %%.re for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_123_count);
  llvm_cbe_tmp__36 = ( char *)(&llvm_cbe_c[(((signed long long )llvm_cbe__2e_rec))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec = 0x%I64X",((signed long long )llvm_cbe__2e_rec));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%40, i32 8), !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_124_count);
  llvm_cbe_tmp__37 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe_tmp__35, 8u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",8u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__37);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i64* %%8, align 8, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_125_count);
  llvm_cbe_tmp__38 = (unsigned long long )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__38);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = xor i64 %%43, %%42, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_126_count);
  llvm_cbe_tmp__39 = (unsigned long long )llvm_cbe_tmp__38 ^ llvm_cbe_tmp__37;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%44, i64* %%8, align 8, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_127_count);
  *llvm_cbe_tmp__8 = llvm_cbe_tmp__39;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__39);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_STOREBYTES(i8* %%41, i64 %%44, i32 8), !dbg !8 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_128_count);
  aesl_internal_STOREBYTES(( char *)llvm_cbe_tmp__36, llvm_cbe_tmp__39, 8u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__39);
printf("\nArgument  = 0x%X",8u);
}
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_P6(%%struct.state_t* %%s), !dbg !15 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_129_count);
  aesl_internal_P6((l_struct_OC_state_t *)(&llvm_cbe_s));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.rec14 = add i64 %%.rec, 8, !dbg !8 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe__2e_rec14_count);
  llvm_cbe__2e_rec14 = (unsigned long long )((unsigned long long )(llvm_cbe__2e_rec&18446744073709551615ull)) + ((unsigned long long )(8ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.rec14 = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_rec14&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = getelementptr inbounds i8* %%m, i64 %%.rec14, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_130_count);
  llvm_cbe_tmp__40 = ( char *)(&llvm_cbe_m[(((signed long long )llvm_cbe__2e_rec14))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec14 = 0x%I64X",((signed long long )llvm_cbe__2e_rec14));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds i8* %%c, i64 %%.rec14, !dbg !8 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_135_count);
  llvm_cbe_tmp__41 = ( char *)(&llvm_cbe_c[(((signed long long )llvm_cbe__2e_rec14))]);
if (AESL_DEBUG_TRACE) {
printf("\n.rec14 = 0x%I64X",((signed long long )llvm_cbe__2e_rec14));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = add i64 %%39, -8, !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_143_count);
  llvm_cbe_tmp__42 = (unsigned long long )((unsigned long long )(llvm_cbe_tmp__34&18446744073709551615ull)) + ((unsigned long long )(18446744073709551608ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__42&18446744073709551615ull)));
  if ((((unsigned long long )llvm_cbe_tmp__42&18446744073709551615ULL) > ((unsigned long long )7ull&18446744073709551615ULL))) {
    llvm_cbe__2e_rec__PHI_TEMPORARY = (unsigned long long )llvm_cbe__2e_rec14;   /* for PHI node */
    llvm_cbe_tmp__34__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__42;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa2__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__41;   /* for PHI node */
    llvm_cbe__2e_lcssa1__PHI_TEMPORARY = ( char *)llvm_cbe_tmp__40;   /* for PHI node */
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__42;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa2 = phi i8* [ %%c, %%35 ], [ %%46, %%.lr.ph  for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe__2e_lcssa2_count);
  llvm_cbe__2e_lcssa2 = ( char *)llvm_cbe__2e_lcssa2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa1 = phi i8* [ %%m, %%35 ], [ %%45, %%.lr.ph  for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe__2e_lcssa1_count);
  llvm_cbe__2e_lcssa1 = ( char *)llvm_cbe__2e_lcssa1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i64 [ %%mlen, %%35 ], [ %%47, %%.lr.ph  for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned long long )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
printf("\nmlen = 0x%I64X",llvm_cbe_mlen);
printf("\n = 0x%I64X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = trunc i64 %%.lcssa to i32, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__43 = (unsigned int )((unsigned int )llvm_cbe__2e_lcssa&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = call fastcc i64 @aesl_internal_LOADBYTES(i8* %%.lcssa1, i32 %%49), !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__44 = (unsigned long long )aesl_internal_LOADBYTES(( char *)llvm_cbe__2e_lcssa1, llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",llvm_cbe_tmp__43);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__44);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = load i64* %%8, align 8, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__45 = (unsigned long long )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__45);
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = xor i64 %%51, %%50, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_157_count);
  llvm_cbe_tmp__46 = (unsigned long long )llvm_cbe_tmp__45 ^ llvm_cbe_tmp__44;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%52, i64* %%8, align 8, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_158_count);
  *llvm_cbe_tmp__8 = llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__46);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_STOREBYTES(i8* %%.lcssa2, i64 %%52, i32 %%49), !dbg !8 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_159_count);
  aesl_internal_STOREBYTES(( char *)llvm_cbe__2e_lcssa2, llvm_cbe_tmp__46, llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__46);
printf("\nArgument  = 0x%X",llvm_cbe_tmp__43);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = shl i64 %%.lcssa, 3, !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_160_count);
  llvm_cbe_tmp__47 = (unsigned long long )llvm_cbe__2e_lcssa << 3ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = sub i64 56, %%53, !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__48 = (unsigned long long )((unsigned long long )(56ull&18446744073709551615ull)) - ((unsigned long long )(llvm_cbe_tmp__47&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__48&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = shl i64 128, %%54, !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__49 = (unsigned long long )128ull << llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = load i64* %%8, align 8, !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__50 = (unsigned long long )*llvm_cbe_tmp__8;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__50);
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = xor i64 %%56, %%55, !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__51 = (unsigned long long )llvm_cbe_tmp__50 ^ llvm_cbe_tmp__49;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%57, i64* %%8, align 8, !dbg !10 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_165_count);
  *llvm_cbe_tmp__8 = llvm_cbe_tmp__51;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__51);
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds i8* %%.lcssa2, i64 %%.lcssa, !dbg !8 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__52 = ( char *)(&llvm_cbe__2e_lcssa2[(((signed long long )llvm_cbe__2e_lcssa))]);
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",((signed long long )llvm_cbe__2e_lcssa));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i64* %%9, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_174_count);
  llvm_cbe_tmp__53 = (unsigned long long )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = xor i64 %%59, %%2, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_175_count);
  llvm_cbe_tmp__54 = (unsigned long long )llvm_cbe_tmp__53 ^ llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%60, i64* %%9, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_176_count);
  *llvm_cbe_tmp__9 = llvm_cbe_tmp__54;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__54);
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load i64* %%10, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_177_count);
  llvm_cbe_tmp__55 = (unsigned long long )*llvm_cbe_tmp__10;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = xor i64 %%61, %%4, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_178_count);
  llvm_cbe_tmp__56 = (unsigned long long )llvm_cbe_tmp__55 ^ llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%62, i64* %%10, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_179_count);
  *llvm_cbe_tmp__10 = llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__56);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_P12(%%struct.state_t* %%s), !dbg !15 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_180_count);
  aesl_internal_P12((l_struct_OC_state_t *)(&llvm_cbe_s));
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = load i64* %%11, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_181_count);
  llvm_cbe_tmp__57 = (unsigned long long )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = xor i64 %%63, %%2, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_182_count);
  llvm_cbe_tmp__58 = (unsigned long long )llvm_cbe_tmp__57 ^ llvm_cbe_tmp__2;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%64, i64* %%11, align 8, !dbg !13 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_183_count);
  *llvm_cbe_tmp__11 = llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__58);
if (AESL_DEBUG_TRACE)
printf("\n  %%65 = load i64* %%12, align 8, !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__59 = (unsigned long long )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%66 = xor i64 %%65, %%4, !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__60 = (unsigned long long )llvm_cbe_tmp__59 ^ llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%66, i64* %%12, align 8, !dbg !14 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_186_count);
  *llvm_cbe_tmp__12 = llvm_cbe_tmp__60;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__60);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_STOREBYTES(i8* %%58, i64 %%64, i32 8), !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_187_count);
  aesl_internal_STOREBYTES(( char *)llvm_cbe_tmp__52, llvm_cbe_tmp__58, 8u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__58);
printf("\nArgument  = 0x%X",8u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%.sum = add i64 %%.lcssa, 8, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe__2e_sum_count);
  llvm_cbe__2e_sum = (unsigned long long )((unsigned long long )(llvm_cbe__2e_lcssa&18446744073709551615ull)) + ((unsigned long long )(8ull&18446744073709551615ull));
if (AESL_DEBUG_TRACE)
printf("\n.sum = 0x%I64X\n", ((unsigned long long )(llvm_cbe__2e_sum&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%67 = getelementptr inbounds i8* %%.lcssa2, i64 %%.sum, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_188_count);
  llvm_cbe_tmp__61 = ( char *)(&llvm_cbe__2e_lcssa2[(((signed long long )llvm_cbe__2e_sum))]);
if (AESL_DEBUG_TRACE) {
printf("\n.sum = 0x%I64X",((signed long long )llvm_cbe__2e_sum));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%68 = load i64* %%12, align 8, !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__62 = (unsigned long long )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  call fastcc void @aesl_internal_STOREBYTES(i8* %%67, i64 %%68, i32 8), !dbg !9 for 0x%I64xth hint within @crypto_aead_encrypt  --> \n", ++aesl_llvm_cbe_190_count);
  aesl_internal_STOREBYTES(( char *)llvm_cbe_tmp__61, llvm_cbe_tmp__62, 8u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__62);
printf("\nArgument  = 0x%X",8u);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @crypto_aead_encrypt}\n");
  return 0u;
}


static signed long long aesl_internal_LOADBYTES( char *llvm_cbe_bytes, signed int llvm_cbe_n) {
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
  unsigned long long llvm_cbe_tmp__64;
  unsigned long long llvm_cbe_tmp__64__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  unsigned long long llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
   char *llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
  unsigned char llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  unsigned long long llvm_cbe_tmp__68;
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  unsigned int llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  unsigned int llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  unsigned long long llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  unsigned long long llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  unsigned long long llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  unsigned int llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe__2e_lcssa_count = 0;
  unsigned long long llvm_cbe__2e_lcssa;
  unsigned long long llvm_cbe__2e_lcssa__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_LOADBYTES\n");
  if ((((signed int )llvm_cbe_n) > ((signed int )0u))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__64__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )0ull;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%12, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__74);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = phi i64 [ %%11, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_206_count);
  llvm_cbe_tmp__64 = (unsigned long long )llvm_cbe_tmp__64__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",llvm_cbe_tmp__64);
printf("\n = 0x%I64X",llvm_cbe_tmp__73);
printf("\n = 0x%I64X",0ull);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%storemerge1 to i64, !dbg !8 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_207_count);
  llvm_cbe_tmp__65 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__65);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds i8* %%bytes, i64 %%3, !dbg !8 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__66 = ( char *)(&llvm_cbe_bytes[(((signed long long )llvm_cbe_tmp__65))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__65));
}
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load i8* %%4, align 1, !dbg !8 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_209_count);
  llvm_cbe_tmp__67 = (unsigned char )*llvm_cbe_tmp__66;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__67);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i8 %%5 to i64, !dbg !8 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__68 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_tmp__67&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__68);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = shl nsw i32 %%storemerge1, 3, !dbg !8 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__69 = (unsigned int )llvm_cbe_storemerge1 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = sub nsw i32 56, %%7, !dbg !8 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__70 = (unsigned int )((unsigned int )(56u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__69&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__70&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = zext i32 %%8 to i64, !dbg !8 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_213_count);
  llvm_cbe_tmp__71 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__70&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = shl i64 %%6, %%9, !dbg !8 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_214_count);
  llvm_cbe_tmp__72 = (unsigned long long )llvm_cbe_tmp__68 << llvm_cbe_tmp__71;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__72);
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = or i64 %%10, %%2, !dbg !8 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_215_count);
  llvm_cbe_tmp__73 = (unsigned long long )llvm_cbe_tmp__72 | llvm_cbe_tmp__64;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = add nsw i32 %%storemerge1, 1, !dbg !9 for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe_219_count);
  llvm_cbe_tmp__74 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__74&4294967295ull)));
  if (((llvm_cbe_tmp__74&4294967295U) == (llvm_cbe_n&4294967295U))) {
    llvm_cbe__2e_lcssa__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__73;   /* for PHI node */
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__74;   /* for PHI node */
    llvm_cbe_tmp__64__PHI_TEMPORARY = (unsigned long long )llvm_cbe_tmp__73;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
if (AESL_DEBUG_TRACE)
printf("\n  %%.lcssa = phi i64 [ 0, %%0 ], [ %%11, %%.lr.ph  for 0x%I64xth hint within @aesl_internal_LOADBYTES  --> \n", ++aesl_llvm_cbe__2e_lcssa_count);
  llvm_cbe__2e_lcssa = (unsigned long long )llvm_cbe__2e_lcssa__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n.lcssa = 0x%I64X",llvm_cbe__2e_lcssa);
printf("\n = 0x%I64X",0ull);
printf("\n = 0x%I64X",llvm_cbe_tmp__73);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_LOADBYTES}\n");
  return llvm_cbe__2e_lcssa;
}


static void aesl_internal_P12(l_struct_OC_state_t *llvm_cbe_s) {
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_P12\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext -16), !dbg !8 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_240_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )-16));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )-16));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext -31), !dbg !8 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_241_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )-31));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )-31));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext -46), !dbg !8 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_242_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )-46));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )-46));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext -61), !dbg !8 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_243_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )-61));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )-61));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext -76), !dbg !8 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_244_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )-76));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )-76));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext -91), !dbg !9 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_245_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )-91));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )-91));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext -106), !dbg !9 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_246_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )-106));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )-106));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext -121), !dbg !9 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_247_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )-121));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )-121));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext 120), !dbg !9 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_248_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )120));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )120));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext 105), !dbg !9 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_249_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )105));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )105));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext 90), !dbg !9 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_250_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )90));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )90));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext 75), !dbg !9 for 0x%I64xth hint within @aesl_internal_P12  --> \n", ++aesl_llvm_cbe_251_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )75));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )75));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_P12}\n");
  return;
}


static void aesl_internal_P6(l_struct_OC_state_t *llvm_cbe_s) {
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_P6\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext -106), !dbg !8 for 0x%I64xth hint within @aesl_internal_P6  --> \n", ++aesl_llvm_cbe_260_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )-106));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )-106));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext -121), !dbg !8 for 0x%I64xth hint within @aesl_internal_P6  --> \n", ++aesl_llvm_cbe_261_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )-121));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )-121));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext 120), !dbg !8 for 0x%I64xth hint within @aesl_internal_P6  --> \n", ++aesl_llvm_cbe_262_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )120));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )120));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext 105), !dbg !8 for 0x%I64xth hint within @aesl_internal_P6  --> \n", ++aesl_llvm_cbe_263_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )105));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )105));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext 90), !dbg !8 for 0x%I64xth hint within @aesl_internal_P6  --> \n", ++aesl_llvm_cbe_264_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )90));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )90));
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call fastcc void @aesl_internal_ROUND(%%struct.state_t* %%s, i8 zeroext 75), !dbg !9 for 0x%I64xth hint within @aesl_internal_P6  --> \n", ++aesl_llvm_cbe_265_count);
   /*tail*/ aesl_internal_ROUND((l_struct_OC_state_t *)llvm_cbe_s, ((unsigned char )75));
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",((unsigned char )75));
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_P6}\n");
  return;
}


static void aesl_internal_STOREBYTES( char *llvm_cbe_bytes, signed long long llvm_cbe_x, signed int llvm_cbe_n) {
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  unsigned int llvm_cbe_tmp__75;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  unsigned int llvm_cbe_tmp__76;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  unsigned long long llvm_cbe_tmp__77;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  unsigned long long llvm_cbe_tmp__78;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  unsigned char llvm_cbe_tmp__79;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  unsigned long long llvm_cbe_tmp__80;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
   char *llvm_cbe_tmp__81;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  unsigned int llvm_cbe_tmp__82;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_STOREBYTES\n");
  if ((((signed int )llvm_cbe_n) > ((signed int )0u))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  } else {
    goto llvm_cbe__2e__crit_edge;
  }

  do {     /* Syntactic loop '.lr.ph' to make GCC happy */
llvm_cbe__2e_lr_2e_ph:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%9, %%.lr.ph ], [ 0, %%0  for 0x%I64xth hint within @aesl_internal_STOREBYTES  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__82);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = shl nsw i32 %%storemerge1, 3, !dbg !8 for 0x%I64xth hint within @aesl_internal_STOREBYTES  --> \n", ++aesl_llvm_cbe_280_count);
  llvm_cbe_tmp__75 = (unsigned int )llvm_cbe_storemerge1 << 3u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__75);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sub nsw i32 56, %%2, !dbg !8 for 0x%I64xth hint within @aesl_internal_STOREBYTES  --> \n", ++aesl_llvm_cbe_281_count);
  llvm_cbe_tmp__76 = (unsigned int )((unsigned int )(56u&4294967295ull)) - ((unsigned int )(llvm_cbe_tmp__75&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__76&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%3 to i64, !dbg !8 for 0x%I64xth hint within @aesl_internal_STOREBYTES  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__77 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__76&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__77);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = lshr i64 %%x, %%4, !dbg !8 for 0x%I64xth hint within @aesl_internal_STOREBYTES  --> \n", ++aesl_llvm_cbe_283_count);
  llvm_cbe_tmp__78 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_x&18446744073709551615ull)) >> ((unsigned long long )(llvm_cbe_tmp__77&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__78&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = trunc i64 %%5 to i8, !dbg !8 for 0x%I64xth hint within @aesl_internal_STOREBYTES  --> \n", ++aesl_llvm_cbe_284_count);
  llvm_cbe_tmp__79 = (unsigned char )((unsigned char )llvm_cbe_tmp__78&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = sext i32 %%storemerge1 to i64, !dbg !8 for 0x%I64xth hint within @aesl_internal_STOREBYTES  --> \n", ++aesl_llvm_cbe_285_count);
  llvm_cbe_tmp__80 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__80);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds i8* %%bytes, i64 %%7, !dbg !8 for 0x%I64xth hint within @aesl_internal_STOREBYTES  --> \n", ++aesl_llvm_cbe_286_count);
  llvm_cbe_tmp__81 = ( char *)(&llvm_cbe_bytes[(((signed long long )llvm_cbe_tmp__80))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__80));
}
if (AESL_DEBUG_TRACE)
printf("\n  store i8 %%6, i8* %%8, align 1, !dbg !8 for 0x%I64xth hint within @aesl_internal_STOREBYTES  --> \n", ++aesl_llvm_cbe_287_count);
  *llvm_cbe_tmp__81 = llvm_cbe_tmp__79;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__79);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = add nsw i32 %%storemerge1, 1, !dbg !9 for 0x%I64xth hint within @aesl_internal_STOREBYTES  --> \n", ++aesl_llvm_cbe_288_count);
  llvm_cbe_tmp__82 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__82&4294967295ull)));
  if (((llvm_cbe_tmp__82&4294967295U) == (llvm_cbe_n&4294967295U))) {
    goto llvm_cbe__2e__crit_edge;
  } else {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__82;   /* for PHI node */
    goto llvm_cbe__2e_lr_2e_ph;
  }

  } while (1); /* end of syntactic loop '.lr.ph' */
llvm_cbe__2e__crit_edge:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_STOREBYTES}\n");
  return;
}


static void aesl_internal_ROUND(l_struct_OC_state_t *llvm_cbe_s,  char llvm_cbe_C) {
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  unsigned long long llvm_cbe_tmp__83;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  signed long long *llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  unsigned long long llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  unsigned long long llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  signed long long *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  unsigned long long llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  signed long long *llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  unsigned long long llvm_cbe_tmp__90;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  unsigned long long llvm_cbe_tmp__91;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  signed long long *llvm_cbe_tmp__92;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  unsigned long long llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  unsigned long long llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  signed long long *llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  unsigned long long llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  unsigned long long llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  unsigned long long llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  unsigned long long llvm_cbe_tmp__99;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  unsigned long long llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  unsigned long long llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  unsigned long long llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned long long llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  unsigned long long llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  unsigned long long llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  unsigned long long llvm_cbe_tmp__106;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  unsigned long long llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  unsigned long long llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  unsigned long long llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  unsigned long long llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  unsigned long long llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  unsigned long long llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  unsigned long long llvm_cbe_tmp__113;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  unsigned long long llvm_cbe_tmp__114;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  unsigned long long llvm_cbe_tmp__115;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  unsigned long long llvm_cbe_tmp__116;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  unsigned long long llvm_cbe_tmp__117;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  unsigned long long llvm_cbe_tmp__118;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  unsigned long long llvm_cbe_tmp__119;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  unsigned long long llvm_cbe_tmp__120;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  unsigned long long llvm_cbe_tmp__121;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  unsigned long long llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  unsigned long long llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  unsigned long long llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  unsigned long long llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  unsigned long long llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  unsigned long long llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  unsigned long long llvm_cbe_tmp__128;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  unsigned long long llvm_cbe_tmp__129;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  unsigned long long llvm_cbe_tmp__130;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;
  unsigned long long llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  unsigned long long llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  unsigned long long llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
  unsigned long long llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
  unsigned long long llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  unsigned long long llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_ROUND\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = zext i8 %%C to i64, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__83 = (unsigned long long )((unsigned long long )(unsigned char )llvm_cbe_C&255U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__83);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = getelementptr inbounds %%struct.state_t* %%s, i64 0, i32 2, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_327_count);
  llvm_cbe_tmp__84 = (signed long long *)(&llvm_cbe_s->field2);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = load i64* %%2, align 8, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__85 = (unsigned long long )*llvm_cbe_tmp__84;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__85);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = xor i64 %%3, %%1, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_329_count);
  llvm_cbe_tmp__86 = (unsigned long long )llvm_cbe_tmp__85 ^ llvm_cbe_tmp__83;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__86);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds %%struct.state_t* %%s, i64 0, i32 4, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_330_count);
  llvm_cbe_tmp__87 = (signed long long *)(&llvm_cbe_s->field4);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i64* %%5, align 8, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_331_count);
  llvm_cbe_tmp__88 = (unsigned long long )*llvm_cbe_tmp__87;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__88);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds %%struct.state_t* %%s, i64 0, i32 0, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_332_count);
  llvm_cbe_tmp__89 = (signed long long *)(&llvm_cbe_s->field0);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i64* %%7, align 8, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_333_count);
  llvm_cbe_tmp__90 = (unsigned long long )*llvm_cbe_tmp__89;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__90);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = xor i64 %%8, %%6, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_334_count);
  llvm_cbe_tmp__91 = (unsigned long long )llvm_cbe_tmp__90 ^ llvm_cbe_tmp__88;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__91);
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = getelementptr inbounds %%struct.state_t* %%s, i64 0, i32 3, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_335_count);
  llvm_cbe_tmp__92 = (signed long long *)(&llvm_cbe_s->field3);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = load i64* %%10, align 8, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_336_count);
  llvm_cbe_tmp__93 = (unsigned long long )*llvm_cbe_tmp__92;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__93);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = xor i64 %%6, %%11, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_337_count);
  llvm_cbe_tmp__94 = (unsigned long long )llvm_cbe_tmp__88 ^ llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__94);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds %%struct.state_t* %%s, i64 0, i32 1, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_338_count);
  llvm_cbe_tmp__95 = (signed long long *)(&llvm_cbe_s->field1);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i64* %%13, align 8, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_339_count);
  llvm_cbe_tmp__96 = (unsigned long long )*llvm_cbe_tmp__95;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__96);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = xor i64 %%4, %%14, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_340_count);
  llvm_cbe_tmp__97 = (unsigned long long )llvm_cbe_tmp__86 ^ llvm_cbe_tmp__96;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = xor i64 %%14, -1, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_341_count);
  llvm_cbe_tmp__98 = (unsigned long long )llvm_cbe_tmp__96 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__98);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = and i64 %%15, %%16, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_342_count);
  llvm_cbe_tmp__99 = (unsigned long long )llvm_cbe_tmp__97 & llvm_cbe_tmp__98;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__99);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = xor i64 %%17, %%9, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_343_count);
  llvm_cbe_tmp__100 = (unsigned long long )llvm_cbe_tmp__99 ^ llvm_cbe_tmp__91;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = xor i64 %%15, -1, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_345_count);
  llvm_cbe_tmp__101 = (unsigned long long )llvm_cbe_tmp__97 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__101);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = and i64 %%11, %%19, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_346_count);
  llvm_cbe_tmp__102 = (unsigned long long )llvm_cbe_tmp__93 & llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = xor i64 %%11, -1, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__103 = (unsigned long long )llvm_cbe_tmp__93 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__103);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = and i64 %%12, %%21, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__104 = (unsigned long long )llvm_cbe_tmp__94 & llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = xor i64 %%22, %%15, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__105 = (unsigned long long )llvm_cbe_tmp__104 ^ llvm_cbe_tmp__97;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__105);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = xor i64 %%12, -1, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__106 = (unsigned long long )llvm_cbe_tmp__94 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__106);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = and i64 %%9, %%24, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_352_count);
  llvm_cbe_tmp__107 = (unsigned long long )llvm_cbe_tmp__91 & llvm_cbe_tmp__106;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = xor i64 %%9, -1, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__108 = (unsigned long long )llvm_cbe_tmp__91 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__108);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = and i64 %%14, %%26, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_354_count);
  llvm_cbe_tmp__109 = (unsigned long long )llvm_cbe_tmp__96 & llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = xor i64 %%12, %%27, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_355_count);
  llvm_cbe_tmp__110 = (unsigned long long )llvm_cbe_tmp__94 ^ llvm_cbe_tmp__109;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__110);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = xor i64 %%18, %%14, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_357_count);
  llvm_cbe_tmp__111 = (unsigned long long )llvm_cbe_tmp__100 ^ llvm_cbe_tmp__96;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = xor i64 %%29, %%20, !dbg !11 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_358_count);
  llvm_cbe_tmp__112 = (unsigned long long )llvm_cbe_tmp__111 ^ llvm_cbe_tmp__102;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__112);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = xor i64 %%28, %%18, !dbg !11 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_360_count);
  llvm_cbe_tmp__113 = (unsigned long long )llvm_cbe_tmp__110 ^ llvm_cbe_tmp__100;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__113);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = xor i64 %%25, %%11, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_362_count);
  llvm_cbe_tmp__114 = (unsigned long long )llvm_cbe_tmp__107 ^ llvm_cbe_tmp__93;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__114);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = xor i64 %%32, %%23, !dbg !11 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_363_count);
  llvm_cbe_tmp__115 = (unsigned long long )llvm_cbe_tmp__114 ^ llvm_cbe_tmp__105;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__115);
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = xor i64 %%23, -1, !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_365_count);
  llvm_cbe_tmp__116 = (unsigned long long )llvm_cbe_tmp__105 ^ 18446744073709551615ull;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__116);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = tail call fastcc i64 @aesl_internal_ROR(i64 %%31, i32 19), !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_367_count);
  llvm_cbe_tmp__117 = (unsigned long long ) /*tail*/ aesl_internal_ROR(llvm_cbe_tmp__113, 19u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__113);
printf("\nArgument  = 0x%X",19u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__117);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = tail call fastcc i64 @aesl_internal_ROR(i64 %%31, i32 28), !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_368_count);
  llvm_cbe_tmp__118 = (unsigned long long ) /*tail*/ aesl_internal_ROR(llvm_cbe_tmp__113, 28u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__113);
printf("\nArgument  = 0x%X",28u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__118);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = xor i64 %%36, %%35, !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__119 = (unsigned long long )llvm_cbe_tmp__118 ^ llvm_cbe_tmp__117;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__119);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = xor i64 %%37, %%31, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__120 = (unsigned long long )llvm_cbe_tmp__119 ^ llvm_cbe_tmp__113;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%38, i64* %%7, align 8, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_371_count);
  *llvm_cbe_tmp__89 = llvm_cbe_tmp__120;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__120);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = tail call fastcc i64 @aesl_internal_ROR(i64 %%30, i32 61), !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__121 = (unsigned long long ) /*tail*/ aesl_internal_ROR(llvm_cbe_tmp__112, 61u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__112);
printf("\nArgument  = 0x%X",61u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__121);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = tail call fastcc i64 @aesl_internal_ROR(i64 %%30, i32 39), !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_373_count);
  llvm_cbe_tmp__122 = (unsigned long long ) /*tail*/ aesl_internal_ROR(llvm_cbe_tmp__112, 39u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__112);
printf("\nArgument  = 0x%X",39u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__122);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = xor i64 %%39, %%30, !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_374_count);
  llvm_cbe_tmp__123 = (unsigned long long )llvm_cbe_tmp__121 ^ llvm_cbe_tmp__112;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__123);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = xor i64 %%41, %%40, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__124 = (unsigned long long )llvm_cbe_tmp__123 ^ llvm_cbe_tmp__122;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%42, i64* %%13, align 8, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_376_count);
  *llvm_cbe_tmp__95 = llvm_cbe_tmp__124;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__124);
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = tail call fastcc i64 @aesl_internal_ROR(i64 %%34, i32 1), !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_377_count);
  llvm_cbe_tmp__125 = (unsigned long long ) /*tail*/ aesl_internal_ROR(llvm_cbe_tmp__116, 1u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__116);
printf("\nArgument  = 0x%X",1u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__125);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = tail call fastcc i64 @aesl_internal_ROR(i64 %%34, i32 6), !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_378_count);
  llvm_cbe_tmp__126 = (unsigned long long ) /*tail*/ aesl_internal_ROR(llvm_cbe_tmp__116, 6u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__116);
printf("\nArgument  = 0x%X",6u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__126);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = xor i64 %%43, %%34, !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_379_count);
  llvm_cbe_tmp__127 = (unsigned long long )llvm_cbe_tmp__125 ^ llvm_cbe_tmp__116;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__127);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = xor i64 %%45, %%44, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_380_count);
  llvm_cbe_tmp__128 = (unsigned long long )llvm_cbe_tmp__127 ^ llvm_cbe_tmp__126;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__128);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%46, i64* %%2, align 8, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_381_count);
  *llvm_cbe_tmp__84 = llvm_cbe_tmp__128;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__128);
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = tail call fastcc i64 @aesl_internal_ROR(i64 %%33, i32 10), !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_382_count);
  llvm_cbe_tmp__129 = (unsigned long long ) /*tail*/ aesl_internal_ROR(llvm_cbe_tmp__115, 10u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__115);
printf("\nArgument  = 0x%X",10u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__129);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = tail call fastcc i64 @aesl_internal_ROR(i64 %%33, i32 17), !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_383_count);
  llvm_cbe_tmp__130 = (unsigned long long ) /*tail*/ aesl_internal_ROR(llvm_cbe_tmp__115, 17u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__115);
printf("\nArgument  = 0x%X",17u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__130);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = xor i64 %%47, %%33, !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_384_count);
  llvm_cbe_tmp__131 = (unsigned long long )llvm_cbe_tmp__129 ^ llvm_cbe_tmp__115;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__131);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = xor i64 %%49, %%48, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_385_count);
  llvm_cbe_tmp__132 = (unsigned long long )llvm_cbe_tmp__131 ^ llvm_cbe_tmp__130;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%50, i64* %%10, align 8, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_386_count);
  *llvm_cbe_tmp__92 = llvm_cbe_tmp__132;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__132);
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = tail call fastcc i64 @aesl_internal_ROR(i64 %%28, i32 7), !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_387_count);
  llvm_cbe_tmp__133 = (unsigned long long ) /*tail*/ aesl_internal_ROR(llvm_cbe_tmp__110, 7u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__110);
printf("\nArgument  = 0x%X",7u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__133);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = tail call fastcc i64 @aesl_internal_ROR(i64 %%28, i32 41), !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_388_count);
  llvm_cbe_tmp__134 = (unsigned long long ) /*tail*/ aesl_internal_ROR(llvm_cbe_tmp__110, 41u);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",llvm_cbe_tmp__110);
printf("\nArgument  = 0x%X",41u);
printf("\nReturn  = 0x%I64X",llvm_cbe_tmp__134);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = xor i64 %%51, %%28, !dbg !12 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_389_count);
  llvm_cbe_tmp__135 = (unsigned long long )llvm_cbe_tmp__133 ^ llvm_cbe_tmp__110;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = xor i64 %%53, %%52, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_390_count);
  llvm_cbe_tmp__136 = (unsigned long long )llvm_cbe_tmp__135 ^ llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__136);
if (AESL_DEBUG_TRACE)
printf("\n  store i64 %%54, i64* %%5, align 8, !dbg !9 for 0x%I64xth hint within @aesl_internal_ROUND  --> \n", ++aesl_llvm_cbe_391_count);
  *llvm_cbe_tmp__87 = llvm_cbe_tmp__136;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__136);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_ROUND}\n");
  return;
}


static signed long long aesl_internal_ROR(signed long long llvm_cbe_x, signed int llvm_cbe_n) {
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  unsigned int llvm_cbe_tmp__137;
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  unsigned long long llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  unsigned long long llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  unsigned long long llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  unsigned long long llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  unsigned long long llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @aesl_internal_ROR\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sub nsw i32 64, %%n, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROR  --> \n", ++aesl_llvm_cbe_397_count);
  llvm_cbe_tmp__137 = (unsigned int )((unsigned int )(64u&4294967295ull)) - ((unsigned int )(llvm_cbe_n&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__137&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = zext i32 %%1 to i64, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROR  --> \n", ++aesl_llvm_cbe_398_count);
  llvm_cbe_tmp__138 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__137&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__138);
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = shl i64 %%x, %%2, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROR  --> \n", ++aesl_llvm_cbe_399_count);
  llvm_cbe_tmp__139 = (unsigned long long )llvm_cbe_x << llvm_cbe_tmp__138;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__139);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = zext i32 %%n to i64, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROR  --> \n", ++aesl_llvm_cbe_402_count);
  llvm_cbe_tmp__140 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_n&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = lshr i64 %%x, %%4, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROR  --> \n", ++aesl_llvm_cbe_403_count);
  llvm_cbe_tmp__141 = (unsigned long long )((unsigned long long )(((unsigned long long )(llvm_cbe_x&18446744073709551615ull)) >> ((unsigned long long )(llvm_cbe_tmp__140&18446744073709551615ull))));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", ((unsigned long long )(llvm_cbe_tmp__141&18446744073709551615ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = or i64 %%3, %%5, !dbg !8 for 0x%I64xth hint within @aesl_internal_ROR  --> \n", ++aesl_llvm_cbe_404_count);
  llvm_cbe_tmp__142 = (unsigned long long )llvm_cbe_tmp__139 | llvm_cbe_tmp__141;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__142);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @aesl_internal_ROR}\n");
  return llvm_cbe_tmp__142;
}

