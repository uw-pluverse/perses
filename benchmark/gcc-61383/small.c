
typedef unsigned long size_t;

extern void *memcpy (void * __dest, const void * __src,
       size_t __n) ;
extern void *memmove (void *__dest, const void *__src, size_t __n)
     ;


extern void *memset (void *__s, int __c, size_t __n) ;
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     ;
extern void *memchr (const void *__s, int __c, size_t __n)
      ;


extern char *strcpy (char * __dest, const char * __src)
     ;
extern char *strncpy (char * __dest,
        const char * __src, size_t __n)
     ;
extern char *strcat (char * __dest, const char * __src)
     ;
extern char *strncat (char * __dest, const char * __src,
        size_t __n) ;
extern int strcmp (const char *__s1, const char *__s2)
     ;
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     ;
extern int strcoll (const char *__s1, const char *__s2)
     ;
extern size_t strxfrm (char * __dest,
         const char * __src, size_t __n)
     ;


extern char *strchr (const char *__s, int __c)
     ;
extern char *strrchr (const char *__s, int __c)
     ;


extern size_t strcspn (const char *__s, const char *__reject)
     ;
extern size_t strspn (const char *__s, const char *__accept)
     ;
extern char *strpbrk (const char *__s, const char *__accept)
     ;
extern char *strstr (const char *__haystack, const char *__needle)
     ;
extern char *strtok (char * __s, const char * __delim)
     ;

extern char *__strtok_r (char * __s,
    const char * __delim,
    char ** __save_ptr)
     ;

extern size_t strlen (const char *__s)
     ;


extern char *strerror (int __errnum) ;

extern void __bzero (void *__s, size_t __n) ;


typedef union { unsigned char __c[8]; double __d; } __huge_val_t;
static __huge_val_t __huge_val = { { 0, 0, 0, 0, 0, 0, 0xf0, 0x7f } };
typedef union { unsigned char __c[4]; float __f; } __huge_valf_t;
static __huge_valf_t __huge_valf = { { 0, 0, 0x80, 0x7f } };
static union { unsigned char __c[12]; long double __ld; } __huge_vall = { { 0, 0, 0, 0, 0, 0, 0, 0x80, 0xff, 0x7f, 0, 0 } };
static union { unsigned char __c[4]; float __d; } __qnan_union
  = { { 0, 0, 0xc0, 0x7f } };
typedef long double float_t;
typedef long double double_t;

extern double acos (double __x) ; extern double __acos (double __x) ;
extern double asin (double __x) ; extern double __asin (double __x) ;
extern double atan (double __x) ; extern double __atan (double __x) ;
extern double atan2 (double __y, double __x) ; extern double __atan2 (double __y, double __x) ;
extern double cos (double __x) ; extern double __cos (double __x) ;
extern double sin (double __x) ; extern double __sin (double __x) ;
extern double tan (double __x) ; extern double __tan (double __x) ;
extern double cosh (double __x) ; extern double __cosh (double __x) ;
extern double sinh (double __x) ; extern double __sinh (double __x) ;
extern double tanh (double __x) ; extern double __tanh (double __x) ;


extern double acosh (double __x) ; extern double __acosh (double __x) ;
extern double asinh (double __x) ; extern double __asinh (double __x) ;
extern double atanh (double __x) ; extern double __atanh (double __x) ;


extern double exp (double __x) ; extern double __exp (double __x) ;
extern double frexp (double __x, int *__exponent) ; extern double __frexp (double __x, int *__exponent) ;
extern double ldexp (double __x, int __exponent) ; extern double __ldexp (double __x, int __exponent) ;
extern double log (double __x) ; extern double __log (double __x) ;
extern double log10 (double __x) ; extern double __log10 (double __x) ;
extern double modf (double __x, double *__iptr) ; extern double __modf (double __x, double *__iptr) ;


extern double expm1 (double __x) ; extern double __expm1 (double __x) ;
extern double log1p (double __x) ; extern double __log1p (double __x) ;
extern double logb (double __x) ; extern double __logb (double __x) ;


extern double exp2 (double __x) ; extern double __exp2 (double __x) ;
extern double log2 (double __x) ; extern double __log2 (double __x) ;


extern double pow (double __x, double __y) ; extern double __pow (double __x, double __y) ;
extern double sqrt (double __x) ; extern double __sqrt (double __x) ;


extern double hypot (double __x, double __y) ; extern double __hypot (double __x, double __y) ;


extern double cbrt (double __x) ; extern double __cbrt (double __x) ;


extern double ceil (double __x) ; extern double __ceil (double __x) ;
extern double fabs (double __x) ; extern double __fabs (double __x) ;
extern double floor (double __x) ; extern double __floor (double __x) ;
extern double fmod (double __x, double __y) ; extern double __fmod (double __x, double __y) ;
extern int __isinf (double __value) ;
extern int __finite (double __value) ;


extern double copysign (double __x, double __y) ; extern double __copysign (double __x, double __y) ;


extern double nan (const char *__tagb) ; extern double __nan (const char *__tagb) ;

extern int __isnan (double __value) ;

extern double erf (double) ; extern double __erf (double) ;
extern double erfc (double) ; extern double __erfc (double) ;
extern double lgamma (double) ; extern double __lgamma (double) ;


extern double tgamma (double) ; extern double __tgamma (double) ;


extern double rint (double __x) ; extern double __rint (double __x) ;
extern double nextafter (double __x, double __y) ; extern double __nextafter (double __x, double __y) ;
extern double nexttoward (double __x, long double __y) ; extern double __nexttoward (double __x, long double __y) ;
extern double remainder (double __x, double __y) ; extern double __remainder (double __x, double __y) ;
extern double scalbn (double __x, int __n) ; extern double __scalbn (double __x, int __n) ;
extern int ilogb (double __x) ; extern int __ilogb (double __x) ;
extern double scalbln (double __x, long int __n) ; extern double __scalbln (double __x, long int __n) ;
extern double nearbyint (double __x) ; extern double __nearbyint (double __x) ;
extern double round (double __x) ; extern double __round (double __x) ;
extern double trunc (double __x) ; extern double __trunc (double __x) ;
extern double remquo (double __x, double __y, int *__quo) ; extern double __remquo (double __x, double __y, int *__quo) ;
extern long int lrint (double __x) ; extern long int __lrint (double __x) ;

extern long long int llrint (double __x) ; extern long long int __llrint (double __x) ;
extern long int lround (double __x) ; extern long int __lround (double __x) ;

extern long long int llround (double __x) ; extern long long int __llround (double __x) ;
extern double fdim (double __x, double __y) ; extern double __fdim (double __x, double __y) ;
extern double fmax (double __x, double __y) ; extern double __fmax (double __x, double __y) ;
extern double fmin (double __x, double __y) ; extern double __fmin (double __x, double __y) ;
extern int __fpclassify (double __value)
     ;
extern int __signbit (double __value)
     ;
extern double fma (double __x, double __y, double __z) ; extern double __fma (double __x, double __y, double __z) ;


extern float acosf (float __x) ; extern float __acosf (float __x) ;
extern float asinf (float __x) ; extern float __asinf (float __x) ;
extern float atanf (float __x) ; extern float __atanf (float __x) ;
extern float atan2f (float __y, float __x) ; extern float __atan2f (float __y, float __x) ;
extern float cosf (float __x) ; extern float __cosf (float __x) ;
extern float sinf (float __x) ; extern float __sinf (float __x) ;
extern float tanf (float __x) ; extern float __tanf (float __x) ;
extern float coshf (float __x) ; extern float __coshf (float __x) ;
extern float sinhf (float __x) ; extern float __sinhf (float __x) ;
extern float tanhf (float __x) ; extern float __tanhf (float __x) ;


extern float acoshf (float __x) ; extern float __acoshf (float __x) ;
extern float asinhf (float __x) ; extern float __asinhf (float __x) ;
extern float atanhf (float __x) ; extern float __atanhf (float __x) ;


extern float expf (float __x) ; extern float __expf (float __x) ;
extern float frexpf (float __x, int *__exponent) ; extern float __frexpf (float __x, int *__exponent) ;
extern float ldexpf (float __x, int __exponent) ; extern float __ldexpf (float __x, int __exponent) ;
extern float logf (float __x) ; extern float __logf (float __x) ;
extern float log10f (float __x) ; extern float __log10f (float __x) ;
extern float modff (float __x, float *__iptr) ; extern float __modff (float __x, float *__iptr) ;


extern float expm1f (float __x) ; extern float __expm1f (float __x) ;
extern float log1pf (float __x) ; extern float __log1pf (float __x) ;
extern float logbf (float __x) ; extern float __logbf (float __x) ;


extern float exp2f (float __x) ; extern float __exp2f (float __x) ;
extern float log2f (float __x) ; extern float __log2f (float __x) ;


extern float powf (float __x, float __y) ; extern float __powf (float __x, float __y) ;
extern float sqrtf (float __x) ; extern float __sqrtf (float __x) ;


extern float hypotf (float __x, float __y) ; extern float __hypotf (float __x, float __y) ;


extern float cbrtf (float __x) ; extern float __cbrtf (float __x) ;


extern float ceilf (float __x) ; extern float __ceilf (float __x) ;
extern float fabsf (float __x) ; extern float __fabsf (float __x) ;
extern float floorf (float __x) ; extern float __floorf (float __x) ;
extern float fmodf (float __x, float __y) ; extern float __fmodf (float __x, float __y) ;
extern int __isinff (float __value) ;
extern int __finitef (float __value) ;


extern float copysignf (float __x, float __y) ; extern float __copysignf (float __x, float __y) ;


extern float nanf (const char *__tagb) ; extern float __nanf (const char *__tagb) ;

extern int __isnanf (float __value) ;

extern float erff (float) ; extern float __erff (float) ;
extern float erfcf (float) ; extern float __erfcf (float) ;
extern float lgammaf (float) ; extern float __lgammaf (float) ;


extern float tgammaf (float) ; extern float __tgammaf (float) ;


extern float rintf (float __x) ; extern float __rintf (float __x) ;
extern float nextafterf (float __x, float __y) ; extern float __nextafterf (float __x, float __y) ;
extern float nexttowardf (float __x, long double __y) ; extern float __nexttowardf (float __x, long double __y) ;
extern float remainderf (float __x, float __y) ; extern float __remainderf (float __x, float __y) ;
extern float scalbnf (float __x, int __n) ; extern float __scalbnf (float __x, int __n) ;
extern int ilogbf (float __x) ; extern int __ilogbf (float __x) ;
extern float scalblnf (float __x, long int __n) ; extern float __scalblnf (float __x, long int __n) ;
extern float nearbyintf (float __x) ; extern float __nearbyintf (float __x) ;
extern float roundf (float __x) ; extern float __roundf (float __x) ;
extern float truncf (float __x) ; extern float __truncf (float __x) ;
extern float remquof (float __x, float __y, int *__quo) ; extern float __remquof (float __x, float __y, int *__quo) ;
extern long int lrintf (float __x) ; extern long int __lrintf (float __x) ;

extern long long int llrintf (float __x) ; extern long long int __llrintf (float __x) ;
extern long int lroundf (float __x) ; extern long int __lroundf (float __x) ;

extern long long int llroundf (float __x) ; extern long long int __llroundf (float __x) ;
extern float fdimf (float __x, float __y) ; extern float __fdimf (float __x, float __y) ;
extern float fmaxf (float __x, float __y) ; extern float __fmaxf (float __x, float __y) ;
extern float fminf (float __x, float __y) ; extern float __fminf (float __x, float __y) ;
extern int __fpclassifyf (float __value)
     ;
extern int __signbitf (float __value)
     ;
extern float fmaf (float __x, float __y, float __z) ; extern float __fmaf (float __x, float __y, float __z) ;


extern long double acosl (long double __x) ; extern long double __acosl (long double __x) ;
extern long double asinl (long double __x) ; extern long double __asinl (long double __x) ;
extern long double atanl (long double __x) ; extern long double __atanl (long double __x) ;
extern long double atan2l (long double __y, long double __x) ; extern long double __atan2l (long double __y, long double __x) ;
extern long double cosl (long double __x) ; extern long double __cosl (long double __x) ;
extern long double sinl (long double __x) ; extern long double __sinl (long double __x) ;
extern long double tanl (long double __x) ; extern long double __tanl (long double __x) ;
extern long double coshl (long double __x) ; extern long double __coshl (long double __x) ;
extern long double sinhl (long double __x) ; extern long double __sinhl (long double __x) ;
extern long double tanhl (long double __x) ; extern long double __tanhl (long double __x) ;


extern long double acoshl (long double __x) ; extern long double __acoshl (long double __x) ;
extern long double asinhl (long double __x) ; extern long double __asinhl (long double __x) ;
extern long double atanhl (long double __x) ; extern long double __atanhl (long double __x) ;


extern long double expl (long double __x) ; extern long double __expl (long double __x) ;
extern long double frexpl (long double __x, int *__exponent) ; extern long double __frexpl (long double __x, int *__exponent) ;
extern long double ldexpl (long double __x, int __exponent) ; extern long double __ldexpl (long double __x, int __exponent) ;
extern long double logl (long double __x) ; extern long double __logl (long double __x) ;
extern long double log10l (long double __x) ; extern long double __log10l (long double __x) ;
extern long double modfl (long double __x, long double *__iptr) ; extern long double __modfl (long double __x, long double *__iptr) ;


extern long double expm1l (long double __x) ; extern long double __expm1l (long double __x) ;
extern long double log1pl (long double __x) ; extern long double __log1pl (long double __x) ;
extern long double logbl (long double __x) ; extern long double __logbl (long double __x) ;


extern long double exp2l (long double __x) ; extern long double __exp2l (long double __x) ;
extern long double log2l (long double __x) ; extern long double __log2l (long double __x) ;


extern long double powl (long double __x, long double __y) ; extern long double __powl (long double __x, long double __y) ;
extern long double sqrtl (long double __x) ; extern long double __sqrtl (long double __x) ;


extern long double hypotl (long double __x, long double __y) ; extern long double __hypotl (long double __x, long double __y) ;


extern long double cbrtl (long double __x) ; extern long double __cbrtl (long double __x) ;


extern long double ceill (long double __x) ; extern long double __ceill (long double __x) ;
extern long double fabsl (long double __x) ; extern long double __fabsl (long double __x) ;
extern long double floorl (long double __x) ; extern long double __floorl (long double __x) ;
extern long double fmodl (long double __x, long double __y) ; extern long double __fmodl (long double __x, long double __y) ;
extern int __isinfl (long double __value) ;
extern int __finitel (long double __value) ;


extern long double copysignl (long double __x, long double __y) ; extern long double __copysignl (long double __x, long double __y) ;


extern long double nanl (const char *__tagb) ; extern long double __nanl (const char *__tagb) ;

extern int __isnanl (long double __value) ;

extern long double erfl (long double) ; extern long double __erfl (long double) ;
extern long double erfcl (long double) ; extern long double __erfcl (long double) ;
extern long double lgammal (long double) ; extern long double __lgammal (long double) ;


extern long double tgammal (long double) ; extern long double __tgammal (long double) ;


extern long double rintl (long double __x) ; extern long double __rintl (long double __x) ;
extern long double nextafterl (long double __x, long double __y) ; extern long double __nextafterl (long double __x, long double __y) ;
extern long double nexttowardl (long double __x, long double __y) ; extern long double __nexttowardl (long double __x, long double __y) ;
extern long double remainderl (long double __x, long double __y) ; extern long double __remainderl (long double __x, long double __y) ;
extern long double scalbnl (long double __x, int __n) ; extern long double __scalbnl (long double __x, int __n) ;
extern int ilogbl (long double __x) ; extern int __ilogbl (long double __x) ;
extern long double scalblnl (long double __x, long int __n) ; extern long double __scalblnl (long double __x, long int __n) ;
extern long double nearbyintl (long double __x) ; extern long double __nearbyintl (long double __x) ;
extern long double roundl (long double __x) ; extern long double __roundl (long double __x) ;
extern long double truncl (long double __x) ; extern long double __truncl (long double __x) ;
extern long double remquol (long double __x, long double __y, int *__quo) ; extern long double __remquol (long double __x, long double __y, int *__quo) ;
extern long int lrintl (long double __x) ; extern long int __lrintl (long double __x) ;

extern long long int llrintl (long double __x) ; extern long long int __llrintl (long double __x) ;
extern long int lroundl (long double __x) ; extern long int __lroundl (long double __x) ;

extern long long int llroundl (long double __x) ; extern long long int __llroundl (long double __x) ;
extern long double fdiml (long double __x, long double __y) ; extern long double __fdiml (long double __x, long double __y) ;
extern long double fmaxl (long double __x, long double __y) ; extern long double __fmaxl (long double __x, long double __y) ;
extern long double fminl (long double __x, long double __y) ; extern long double __fminl (long double __x, long double __y) ;
extern int __fpclassifyl (long double __value)
     ;
extern int __signbitl (long double __value)
     ;
extern long double fmal (long double __x, long double __y, long double __z) ; extern long double __fmal (long double __x, long double __y, long double __z) ;

enum
  {
    FP_NAN =
      0,
    FP_INFINITE =
      1,
    FP_ZERO =
      2,
    FP_SUBNORMAL =
      3,
    FP_NORMAL =
      4
  };

typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;

typedef long long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;

typedef unsigned long long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;

typedef long long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;

typedef unsigned long long int uint_least64_t;
typedef signed char int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;

typedef long long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;

typedef unsigned long long int uint_fast64_t;
typedef int intptr_t;
typedef unsigned int uintptr_t;

typedef long long int intmax_t;

typedef unsigned long long int uintmax_t;

extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     ;
extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     ;
extern void __assert (const char *__assertion, const char *__file, int __line)
     ;


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
 typedef signed long long int __int64_t;
 typedef unsigned long long int __uint64_t;
 typedef long long int __quad_t;
 typedef unsigned long long int __u_quad_t;
 typedef __u_quad_t __dev_t;
 typedef unsigned int __uid_t;
 typedef unsigned int __gid_t;
 typedef unsigned long int __ino_t;
 typedef __u_quad_t __ino64_t;
 typedef unsigned int __mode_t;
 typedef unsigned int __nlink_t;
 typedef long int __off_t;
 typedef __quad_t __off64_t;
 typedef int __pid_t;
 typedef struct { int __val[2]; } __fsid_t;
 typedef long int __clock_t;
 typedef unsigned long int __rlim_t;
 typedef __u_quad_t __rlim64_t;
 typedef unsigned int __id_t;
 typedef long int __time_t;
 typedef unsigned int __useconds_t;
 typedef long int __suseconds_t;
 typedef int __daddr_t;
 typedef int __key_t;
 typedef int __clockid_t;
 typedef void * __timer_t;
 typedef long int __blksize_t;
 typedef long int __blkcnt_t;
 typedef __quad_t __blkcnt64_t;
 typedef unsigned long int __fsblkcnt_t;
 typedef __u_quad_t __fsblkcnt64_t;
 typedef unsigned long int __fsfilcnt_t;
 typedef __u_quad_t __fsfilcnt64_t;
 typedef int __fsword_t;
 typedef int __ssize_t;
 typedef long int __syscall_slong_t;
 typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
 typedef int __intptr_t;
 typedef unsigned int __socklen_t;
struct _IO_FILE;

typedef struct _IO_FILE FILE;


typedef struct _IO_FILE __FILE;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t; struct _IO_FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};
enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
struct _IO_FILE {
  int _flags;
  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
     size_t __n);
typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn (void *__cookie);
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) ;
extern int _IO_ferror (_IO_FILE *__fp) ;
extern int _IO_peekc_locked (_IO_FILE *__fp);
extern void _IO_flockfile (_IO_FILE *) ;
extern void _IO_funlockfile (_IO_FILE *) ;
extern int _IO_ftrylockfile (_IO_FILE *) ;
extern int _IO_vfscanf (_IO_FILE * , const char * ,
   __gnuc_va_list, int *);
extern int _IO_vfprintf (_IO_FILE *, const char *,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area (_IO_FILE *) ;

typedef _G_fpos_t fpos_t;

extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int remove (const char *__filename) ;
extern int rename (const char *__old, const char *__new) ;


extern FILE *tmpfile (void) ;
extern char *tmpnam (char *__s) ;


extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);


extern FILE *fopen (const char * __filename,
      const char * __modes) ;
extern FILE *freopen (const char * __filename,
        const char * __modes,
        FILE * __stream) ;


extern void setbuf (FILE * __stream, char * __buf) ;
extern int setvbuf (FILE * __stream, char * __buf,
      int __modes, size_t __n) ;


extern int fprintf (FILE * __stream,
      const char * __format, ...);
extern int printf (const char * __format, ...);
extern int sprintf (char * __s,
      const char * __format, ...) ;
extern int vfprintf (FILE * __s, const char * __format,
       __gnuc_va_list __arg);
extern int vprintf (const char * __format, __gnuc_va_list __arg);
extern int vsprintf (char * __s, const char * __format,
       __gnuc_va_list __arg) ;


extern int snprintf (char * __s, size_t __maxlen,
       const char * __format, ...)
     ;
extern int vsnprintf (char * __s, size_t __maxlen,
        const char * __format, __gnuc_va_list __arg)
     ;


extern int fscanf (FILE * __stream,
     const char * __format, ...) ;
extern int scanf (const char * __format, ...) ;
extern int sscanf (const char * __s,
     const char * __format, ...) ;
extern int __isoc99_fscanf (FILE * __stream,
       const char * __format, ...) ;
extern int __isoc99_scanf (const char * __format, ...) ;
extern int __isoc99_sscanf (const char * __s,
       const char * __format, ...) ;


extern int vfscanf (FILE * __s, const char * __format,
      __gnuc_va_list __arg)
     ;
extern int vscanf (const char * __format, __gnuc_va_list __arg)
     ;
extern int vsscanf (const char * __s,
      const char * __format, __gnuc_va_list __arg)
     ;
extern int __isoc99_vfscanf (FILE * __s,
        const char * __format,
        __gnuc_va_list __arg) ;
extern int __isoc99_vscanf (const char * __format,
       __gnuc_va_list __arg) ;
extern int __isoc99_vsscanf (const char * __s,
        const char * __format,
        __gnuc_va_list __arg) ;


extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);


extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);


extern char *fgets (char * __s, int __n, FILE * __stream)
     ;
extern char *gets (char *__s) ;


extern int fputs (const char * __s, FILE * __stream);
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void * __ptr, size_t __size,
       size_t __n, FILE * __stream) ;
extern size_t fwrite (const void * __ptr, size_t __size,
        size_t __n, FILE * __s);


extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);


extern int fgetpos (FILE * __stream, fpos_t * __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);


extern void clearerr (FILE *__stream) ;
extern int feof (FILE *__stream) ;
extern int ferror (FILE *__stream) ;


extern void perror (const char *__s);


static void
platform_main_begin(void)
{
}
static void
platform_main_end(uint32_t crc, int flag)
{
 printf ("checksum = %X\n", crc);
}
static int8_t
(safe_unary_minus_func_int8_t_s)(int8_t si )
{
 
  return
    -si;
}
static int8_t
(safe_add_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{
 
  return
    (si1 + si2);
}
static int8_t
(safe_sub_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{
 
  return
    (si1 - si2);
}
static int8_t
(safe_mul_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{
 
  return
    si1 * si2;
}
static int8_t
(safe_mod_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int8_t
(safe_div_func_int8_t_s_s)(int8_t si1, int8_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == (-128)) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int8_t
(safe_lshift_func_int8_t_s_s)(int8_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > ((127) >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int8_t
(safe_lshift_func_int8_t_s_u)(int8_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > ((127) >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static int8_t
(safe_rshift_func_int8_t_s_s)(int8_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :
    (left >> ((int)right));
}
static int8_t
(safe_rshift_func_int8_t_s_u)(int8_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static int16_t
(safe_unary_minus_func_int16_t_s)(int16_t si )
{
 
  return
    -si;
}
static int16_t
(safe_add_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{
 
  return
    (si1 + si2);
}
static int16_t
(safe_sub_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{
 
  return
    (si1 - si2);
}
static int16_t
(safe_mul_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{
 
  return
    si1 * si2;
}
static int16_t
(safe_mod_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == (-32767-1)) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int16_t
(safe_div_func_int16_t_s_s)(int16_t si1, int16_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == (-32767-1)) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int16_t
(safe_lshift_func_int16_t_s_s)(int16_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > ((32767) >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int16_t
(safe_lshift_func_int16_t_s_u)(int16_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > ((32767) >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static int16_t
(safe_rshift_func_int16_t_s_s)(int16_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :
    (left >> ((int)right));
}
static int16_t
(safe_rshift_func_int16_t_s_u)(int16_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static int32_t
(safe_unary_minus_func_int32_t_s)(int32_t si )
{
 
  return
    (si==(-2147483647-1)) ?
    ((si)) :
    -si;
}
static int32_t
(safe_add_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{
 
  return
    (((si1>0) && (si2>0) && (si1 > ((2147483647)-si2))) || ((si1<0) && (si2<0) && (si1 < ((-2147483647-1)-si2)))) ?
    ((si1)) :
    (si1 + si2);
}
static int32_t
(safe_sub_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{
 
  return
    (((si1^si2) & (((si1 ^ ((si1^si2) & (~(2147483647))))-si2)^si2)) < 0) ?
    ((si1)) :
    (si1 - si2);
}
static int32_t
(safe_mul_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{
 
  return
    (((si1 > 0) && (si2 > 0) && (si1 > ((2147483647) / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < ((-2147483647-1) / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < ((-2147483647-1) / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((2147483647) / si1)))) ?
    ((si1)) :
    si1 * si2;
}
static int32_t
(safe_mod_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == (-2147483647-1)) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int32_t
(safe_div_func_int32_t_s_s)(int32_t si1, int32_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == (-2147483647-1)) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int32_t
(safe_lshift_func_int32_t_s_s)(int32_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > ((2147483647) >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int32_t
(safe_lshift_func_int32_t_s_u)(int32_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > ((2147483647) >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static int32_t
(safe_rshift_func_int32_t_s_s)(int32_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :
    (left >> ((int)right));
}
static int32_t
(safe_rshift_func_int32_t_s_u)(int32_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32)) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static uint8_t
(safe_unary_minus_func_uint8_t_u)(uint8_t ui )
{
 
  return -ui;
}
static uint8_t
(safe_add_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{
 
  return ui1 + ui2;
}
static uint8_t
(safe_sub_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{
 
  return ui1 - ui2;
}
static uint8_t
(safe_mul_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{
 
  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint8_t
(safe_mod_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{
 
  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 % ui2);
}
static uint8_t
(safe_div_func_uint8_t_u_u)(uint8_t ui1, uint8_t ui2 )
{
 
  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 / ui2);
}
static uint8_t
(safe_lshift_func_uint8_t_u_s)(uint8_t left, int right )
{
 
  return
    ((((int)right) < 0) || (((int)right) >= 32) || (left > ((255) >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint8_t
(safe_lshift_func_uint8_t_u_u)(uint8_t left, unsigned int right )
{
 
  return
    ((((unsigned int)right) >= 32) || (left > ((255) >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static uint8_t
(safe_rshift_func_uint8_t_u_s)(uint8_t left, int right )
{
 
  return
    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :
    (left >> ((int)right));
}
static uint8_t
(safe_rshift_func_uint8_t_u_u)(uint8_t left, unsigned int right )
{
 
  return
    (((unsigned int)right) >= 32) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static uint16_t
(safe_unary_minus_func_uint16_t_u)(uint16_t ui )
{
 
  return -ui;
}
static uint16_t
(safe_add_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{
 
  return ui1 + ui2;
}
static uint16_t
(safe_sub_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{
 
  return ui1 - ui2;
}
static uint16_t
(safe_mul_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{
 
  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint16_t
(safe_mod_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{
 
  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 % ui2);
}
static uint16_t
(safe_div_func_uint16_t_u_u)(uint16_t ui1, uint16_t ui2 )
{
 
  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 / ui2);
}
static uint16_t
(safe_lshift_func_uint16_t_u_s)(uint16_t left, int right )
{
 
  return
    ((((int)right) < 0) || (((int)right) >= 32) || (left > ((65535) >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint16_t
(safe_lshift_func_uint16_t_u_u)(uint16_t left, unsigned int right )
{
 
  return
    ((((unsigned int)right) >= 32) || (left > ((65535) >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static uint16_t
(safe_rshift_func_uint16_t_u_s)(uint16_t left, int right )
{
 
  return
    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :
    (left >> ((int)right));
}
static uint16_t
(safe_rshift_func_uint16_t_u_u)(uint16_t left, unsigned int right )
{
 
  return
    (((unsigned int)right) >= 32) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static uint32_t
(safe_unary_minus_func_uint32_t_u)(uint32_t ui )
{
 
  return -ui;
}
static uint32_t
(safe_add_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{
 
  return ui1 + ui2;
}
static uint32_t
(safe_sub_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{
 
  return ui1 - ui2;
}
static uint32_t
(safe_mul_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{
 
  return ((unsigned int)ui1) * ((unsigned int)ui2);
}
static uint32_t
(safe_mod_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{
 
  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 % ui2);
}
static uint32_t
(safe_div_func_uint32_t_u_u)(uint32_t ui1, uint32_t ui2 )
{
 
  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 / ui2);
}
static uint32_t
(safe_lshift_func_uint32_t_u_s)(uint32_t left, int right )
{
 
  return
    ((((int)right) < 0) || (((int)right) >= 32) || (left > ((4294967295U) >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint32_t
(safe_lshift_func_uint32_t_u_u)(uint32_t left, unsigned int right )
{
 
  return
    ((((unsigned int)right) >= 32) || (left > ((4294967295U) >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static uint32_t
(safe_rshift_func_uint32_t_u_s)(uint32_t left, int right )
{
 
  return
    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :
    (left >> ((int)right));
}
static uint32_t
(safe_rshift_func_uint32_t_u_u)(uint32_t left, unsigned int right )
{
 
  return
    (((unsigned int)right) >= 32) ?
    ((left)) :
    (left >> ((unsigned int)right));
}
static float
(safe_add_func_float_f_f)(float sf1, float sf2 )
{
 
  return
    (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * 0x1.fffffep+127F)) ?
    (sf1) :
    (sf1 + sf2);
}
static float
(safe_sub_func_float_f_f)(float sf1, float sf2 )
{
 
  return
    (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * 0x1.fffffep+127F)) ?
    (sf1) :
    (sf1 - sf2);
}
static float
(safe_mul_func_float_f_f)(float sf1, float sf2 )
{
 
  return
    (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) > (0x1.0p-100f * (0x1.0p-28f * 0x1.fffffep+127F))) ?
    (sf1) :
    (sf1 * sf2);
}
static float
(safe_div_func_float_f_f)(float sf1, float sf2 )
{
 
  return
    ((fabsf(sf2) < 1.0f) && (((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) > (0x1.0p-100f * (0x1.0p-49f * 0x1.fffffep+127F))))) ?
    (sf1) :
    (sf1 / sf2);
}
static double
(safe_add_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * 0x1.fffffffffffffp+1023)) ?
    (sf1) :
    (sf1 + sf2);
}
static double
(safe_sub_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * 0x1.fffffffffffffp+1023)) ?
    (sf1) :
    (sf1 - sf2);
}
static double
(safe_mul_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) > (0x1.0p-100 * (0x1.0p-924 * 0x1.fffffffffffffp+1023))) ?
    (sf1) :
    (sf1 * sf2);
}
static double
(safe_div_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    ((fabs(sf2) < 1.0) && (((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) > (0x1.0p-100 * (0x1.0p-974 * 0x1.fffffffffffffp+1023))))) ?
    (sf1) :
    (sf1 / sf2);
}
static int32_t
(safe_convert_func_float_to_int32_t)(float sf1 )
{
 
  return
    ((sf1 <= (-2147483647-1)) || (sf1 >= (2147483647))) ?
    ((2147483647)) :
    ((int32_t)(sf1));
}
static uint32_t crc32_tab[256];
static uint32_t crc32_context = 0xFFFFFFFFUL;
static void
crc32_gentab (void)
{
 uint32_t crc;
 const uint32_t poly = 0xEDB88320UL;
 int i, j;
 for (i = 0; i < 256; i++) {
  crc = i;
  for (j = 8; j > 0; j--) {
   if (crc & 1) {
    crc = (crc >> 1) ^ poly;
   } else {
    crc >>= 1;
   }
  }
  crc32_tab[i] = crc;
 }
}
static void
crc32_byte (uint8_t b) {
 crc32_context =
  ((crc32_context >> 8) & 0x00FFFFFF) ^
  crc32_tab[(crc32_context ^ b) & 0xFF];
}
static void
crc32_8bytes (uint32_t val)
{
 crc32_byte ((val>>0) & 0xff);
 crc32_byte ((val>>8) & 0xff);
 crc32_byte ((val>>16) & 0xff);
 crc32_byte ((val>>24) & 0xff);
}
static void
transparent_crc (uint32_t val, char* vname, int flag)
{
 crc32_8bytes(val);
 if (flag) {
    printf("...checksum after hashing %s : %X\n", vname, crc32_context ^ 0xFFFFFFFFU);
 }
}
static void
transparent_crc_bytes (char *ptr, int nbytes, char* vname, int flag)
{
    int i;
    for (i=0; i<nbytes; i++) {
        crc32_byte(ptr[i]);
    }
 if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname, crc32_context ^ 0xFFFFFFFFUL);
 }
}
static
  long
  __undefined;
static
  int8_t
  g_7
  =
  (-6L);
static
  int32_t
  g_21
  =
  0L;
static
  int32_t
  g_75
  =
  0x4C99FFFBL;
static
  uint16_t
  g_94
  =
  0x8AA1L;
static
  uint32_t
  g_96
  =
  0x7709B807L;
static
  uint32_t
  g_101
  =
  0xA66BE80DL;
static
  uint32_t
  g_129
  =
  9UL;
static
  uint8_t
  g_176
  =
  0x44L;
static
  int8_t
  g_181
  =
  0L;
static
  uint32_t
  g_244
  =
  0x01B28DB7L;
static
  int16_t
  g_245
  =
  (-5L);
static
  uint8_t
  g_276
  =
  0UL;
static
  int32_t
  g_304
  =
  4L;
static
  uint32_t
  g_370
  =
  0x31730F26L;
static
  uint8_t
  g_387
  =
  0x45L;
static
  int32_t
  g_758
  =
  0L;
static
  uint32_t
  g_801
  =
  0x98978E78L;
static
  const
  uint32_t
  g_833
  =
  5UL;
static
  uint8_t
  g_985
  =
  0x87L;
static
  int32_t
  g_1039
  =
  0x6D312621L;
static
  uint32_t
  g_1238
  =
  8UL;
static
  uint32_t
  g_1272
  =
  0xCB2B4AAEL;
static
  uint32_t
  g_1309
  =
  4294967295UL;
static
  int16_t
  g_1473
  =
  0x7267L;
static
  uint32_t
  g_1504
  =
  4294967295UL;
static volatile uint32_t g_1578 = 4294967291UL;
static
  uint32_t
  g_1638
  =
  0xAC38FC42L;
static
  uint32_t
  g_1670
  =
  1UL;
static
  uint32_t
  g_1671
  =
  0UL;
static volatile uint16_t g_1747 = 7UL;
static
  uint32_t
  g_1812
  =
  4294967295UL;
static
  int8_t
  g_1902
  =
  (-5L);
static
  int32_t
  g_1920
  =
  3L;
static
  uint32_t
  g_1957
  =
  0UL;
static
  uint8_t
  g_1958
  =
  5UL;
static
  int8_t
  g_2005
  =
  (-1L);
static
  uint32_t
  g_2111
  =
  0xA8EDD176L;
static
  uint32_t
  g_2112
  =
  0UL;
static
  uint32_t
  g_2189
  =
  0x0108E6C1L;
static
  uint32_t
  g_2285
  =
  0xF02DEBC4L;
static
  int8_t
  g_2286
  =
  0x58L;
static
  uint16_t
func_1
(void
);
static
  int32_t
func_2
(int8_t
p_3,
uint8_t
p_4,
uint32_t
p_5
);
static
  uint16_t
func_22
(const
int32_t
p_23,
int8_t
p_24,
int8_t
p_25,
int8_t
p_26,
uint16_t
p_27
);
static
  const
  uint8_t
func_30
(int16_t
p_31,
const
int16_t
p_32
);
static
  int16_t
func_33
(uint16_t
p_34,
uint32_t
p_35,
const
int8_t
p_36
);
static
  uint16_t
func_39
(int8_t
p_40
);
static
  uint16_t
func_41
(int32_t
p_42,
const
int32_t
p_43,
const
int16_t
p_44,
int32_t
p_45
);
static
  int32_t
func_46
(uint32_t
p_47
);
static
  uint16_t
func_50
(uint16_t
p_51,
uint8_t
p_52,
uint16_t
p_53,
int32_t
p_54
);
static
  uint8_t
func_55
(uint32_t
p_56,
int16_t
p_57,
const
uint32_t
p_58
);
static uint16_t
func_1 (void
)
{
  int16_t
    l_6
    =
    0L;
  int32_t
    l_1502
    =
    0x744250C5L;
  uint16_t
    l_1503
    =
    0x4FC1L;
  uint16_t
    l_1528
    =
    0x75C0L;
  int32_t
    l_1536
    =
    7L;
  uint16_t
    l_1621
    =
    0UL;
  int32_t
    l_1846
    =
    0x7D2D61A3L;
  int8_t
    l_1870
    =
    0L;
  int16_t
    l_1887
    =
    0xF0ACL;
  int8_t
    l_1942
    =
    (-5L);
  uint32_t
    l_1974
    =
    4294967287UL;
  int32_t
    l_2034
    =
    0x39E574E9L;
  int8_t
    l_2119
    =
    (-1L);
  uint32_t
    l_2138
    =
    7UL;
  uint16_t
    l_2162
    =
    0x10EEL;
  uint8_t
    l_2188
    =
    251UL;
  uint32_t
    l_2192
    =
    0x7FB453E7L;
  int32_t
    l_2281
    =
    0L;
  const
    int32_t
    l_2284
    =
    0xE9CCD730L;
  int32_t
    l_2393
    =
    0xA9726CB7L;
  uint16_t
    l_2394
    =
    65535UL;
  if (((!(~(func_2 (l_6, g_7, l_6) < ((g_1504 = ((0xB8B13202L < g_1039) ^ ((0x498EL != (safe_lshift_func_int8_t_s_s ((safe_mod_func_uint8_t_u_u (((((l_1503 = (safe_add_func_uint8_t_u_u ((l_1502 = (safe_add_func_int16_t_s_s ((g_1309 <= (safe_rshift_func_int16_t_s_s ((safe_rshift_func_int8_t_s_u ((-1L), 2)), 9))), l_6))), g_1039))) != (-1L)) && 0x53L) ^ 1L), g_1039)), 6))) < l_6))) == 0xBBEAEAA1L)))) >= 0xE521L))
  {
    int16_t
      l_1517
      =
      0xD1BDL;
    int32_t
      l_1522
      =
      7L;
    int32_t
      l_1527
      =
      0L;
    int16_t
      l_1529
      =
      0xA4E3L;
    int8_t
      l_1817
      =
      (-7L);
    int16_t
      l_1838
      =
      5L;
    uint32_t
      l_1871
      =
      0x32A0289AL;
    int16_t
      l_2003
      =
      0x34BEL;
    uint8_t
      l_2004
      =
      255UL;
    uint8_t
      l_2037
      =
      247UL;
    uint8_t
      l_2044
      =
      1UL;
    uint16_t
      l_2045
      =
      1UL;
    int32_t
      l_2046
      =
      (-7L);
    uint16_t
      l_2085
      =
      65531UL;
    uint32_t
      l_2201
      =
      0xFD4EF55FL;
    uint32_t
      l_2244
      =
      4294967288UL;
    uint8_t
      l_2283
      =
      0UL;
    int32_t
      l_2289
      =
      1L;
    if ((l_1522 = (((0x8BL & (safe_sub_func_uint16_t_u_u ((g_1238 && (safe_rshift_func_int8_t_s_s ((((safe_sub_func_int8_t_s_s ((((safe_sub_func_uint16_t_u_u (g_21, (((safe_rshift_func_uint16_t_u_u ((safe_sub_func_uint32_t_u_u ((!((l_1517 = g_1238) | (g_304 || ((safe_lshift_func_int8_t_s_u ((safe_add_func_int8_t_s_s (l_1522, ((safe_mul_func_int8_t_s_s ((!(g_304 && l_1522)), ((((l_1527 = (safe_mod_func_int16_t_s_s (((((g_758 & 0x7432L) <= g_96) >= l_1522) | 7UL), g_101))) ^ l_1503) != 0x8D906F36L) & l_1528))) < l_1502))), l_1503)) == l_6)))), 0x6AB2CB5FL)), g_1039)) ^ g_245) < l_1522))) > g_1504) < g_129), l_1502)) <= l_1529) & l_1522), 1))), 0xFE2CL))) < l_1522) < l_1529)))
    {
      uint8_t
 l_1535
 =
 0x97L;
      for
 (l_1502
  =
  26;
  (l_1502
   !=
   5);
  --l_1502)
      {
 g_21
   =
   ((safe_unary_minus_func_int16_t_s ((safe_add_func_uint8_t_u_u (l_1535, (g_244 != 0UL))))) || (g_1473 = (l_1536 = 0xB0CCL)));
 return
   l_1535;
      }
    }
    else
    {
      int8_t
 l_1554
 =
 1L;
      uint32_t
 l_1604
 =
 0x62760975L;
      int8_t
 l_1619
 =
 0xA4L;
      const
 uint8_t
 l_1620
 =
 247UL;
      int32_t
 l_1648
 =
 0x9F4E52CAL;
      int8_t
 l_1731
 =
 0x34L;
      uint32_t
 l_1952
 =
 0x1C97D71FL;
    lbl_1924:
      if (l_1527)
      {
 uint16_t
   l_1553
   =
   65535UL;
 int32_t
   l_1561
   =
   2L;
 uint16_t
   l_1639
   =
   1UL;
 int16_t
   l_1743
   =
   0x6B6BL;
 uint8_t
   l_1744
   =
   255UL;
 g_21
   =
   (((l_1529 == g_387) || ((safe_rshift_func_int8_t_s_u ((safe_add_func_uint8_t_u_u (0xD1L, (l_1528 || ((safe_add_func_uint16_t_u_u (((safe_add_func_uint16_t_u_u ((safe_mod_func_int16_t_s_s (g_244, (safe_sub_func_uint32_t_u_u ((safe_mod_func_int16_t_s_s ((g_1504 <= (g_94 = (g_758 > (safe_add_func_uint16_t_u_u (1UL, (-1L)))))), l_1553)), g_244)))), l_1554)) | g_370), 1UL)) ^ g_801)))), 0)) == 65529UL)) && g_370);
      lbl_1643:
 if (((safe_lshift_func_int16_t_s_u (g_7, (safe_mul_func_int16_t_s_s ((safe_mul_func_int8_t_s_s (0L, (((l_1561 = (-2L)) <= (safe_mod_func_int8_t_s_s (((safe_lshift_func_int16_t_s_s ((((safe_rshift_func_uint8_t_u_s (((l_1553 ^ ((safe_lshift_func_int8_t_s_u ((g_176 < (((safe_rshift_func_uint8_t_u_s (8UL, g_1473)) && (safe_sub_func_int16_t_s_s ((safe_lshift_func_int16_t_s_s (((g_1039 ^ l_1554) == 0x2529A8C9L), g_181)), 1UL))) ^ 0xA7L)), 1)) || g_94)) > g_801), 4)) && l_1554) <= g_1238), l_1554)) ^ 1L), g_276))) | l_1553))), l_1517)))) != 1UL))
 {
   uint16_t
     l_1601
     =
     65535UL;
   int32_t
     l_1602
     =
     1L;
   uint32_t
     l_1603
     =
     0x7726A56AL;
   l_1604
     =
     ((safe_lshift_func_uint16_t_u_u (g_1578, ((((-1L) >= (((safe_rshift_func_int16_t_s_s ((safe_sub_func_int32_t_s_s ((safe_mul_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_u (0x0BL, 5)), ((safe_lshift_func_uint16_t_u_s ((g_94 = 0UL), (safe_sub_func_uint8_t_u_u (0UL, (safe_mul_func_int16_t_s_s (((l_1554 || ((safe_rshift_func_int16_t_s_s ((safe_lshift_func_int8_t_s_u ((((safe_mul_func_int16_t_s_s ((((safe_lshift_func_int8_t_s_s (l_1601, l_1554)) || 0x5A39249EL) != 0xF9L), 0x974CL)) && 0x3DL) || 0x0DL), g_101)), l_1529)) < 1L)) ^ l_1602), l_1603)))))) > 0x13A97634L))), g_985)), 2)) >= 4UL) <= l_1503)) > 0x7E64L) > g_21))) ^ l_1561);
 }
 else
 {
   uint16_t
     l_1605
     =
     0x013AL;
   g_21
     =
     (0UL
      !=
      2L);
   g_21
     =
     g_1238;
   l_1522
     =
     ((((l_1605 <= ((-6L) | g_21)) & (safe_rshift_func_int16_t_s_s (((safe_mul_func_uint16_t_u_u (((l_6 & (safe_mod_func_int32_t_s_s ((((((safe_unary_minus_func_int32_t_s (((safe_lshift_func_uint8_t_u_s (0x60L, l_1605)) && 0x48F780EBL))) < ((safe_rshift_func_uint8_t_u_s ((g_276 = (safe_mod_func_int32_t_s_s (l_1619, l_1605))), l_1528)) ^ 0x468EL)) >= l_1527) > l_1529) ^ l_1554), g_245))) && l_1620), l_1621)) || l_1619), 8))) & l_6) >= l_1604);
   return
     g_833;
 }
 if ((1L >= (l_1536 == ((safe_mod_func_int32_t_s_s ((((safe_mul_func_int8_t_s_s ((l_1639 = ((safe_mul_func_uint8_t_u_u ((g_387 = l_1553), ((safe_mul_func_int8_t_s_s (0L, (+l_1561))) >= (g_1638 = (((safe_mod_func_int16_t_s_s ((safe_mul_func_int16_t_s_s ((l_1619 < (((safe_lshift_func_uint16_t_u_u (((g_370 = 4294967295UL) || (((l_1502 = g_176) >= (g_94 = (safe_sub_func_int16_t_s_s (1L, l_1517)))) || (-7L))), 0)) >= l_1554) || l_1620)), g_1238)), g_304)) & g_1473) != 0x97L))))) <= g_176)), l_1553)) >= 0xAAL) & 0x95L), l_1604)) > g_1039))))
 {
   uint32_t
     l_1642
     =
     0x970DDDBAL;
   int32_t
     l_1666
     =
     0x58BDEDA6L;
   for
     (l_6
      =
      0;
      (l_6
       <
       (-26));
      l_6
      =
      safe_sub_func_int32_t_s_s
      (l_6,
       1))
   {
     if (l_1642)
       break;
     if (l_1536)
       goto
  lbl_1643;
     l_1648
       =
       (safe_lshift_func_int8_t_s_s
        (((safe_lshift_func_uint8_t_u_s (253UL, 0)) < l_1528), 2));
   }
   l_1648
     =
     (l_1666
      =
      (safe_mod_func_int32_t_s_s
       (((safe_lshift_func_int16_t_s_s (((((g_7 = (((0x46L != ((1UL & (safe_sub_func_int32_t_s_s ((!l_1554), (safe_sub_func_uint32_t_u_u (l_1503, (g_1638 <= (+g_181))))))) <= (g_276 = (safe_unary_minus_func_int32_t_s ((l_1522 = (safe_add_func_int16_t_s_s (((safe_rshift_func_uint8_t_u_u ((l_1527 = (((safe_rshift_func_int16_t_s_s (g_75, 9)) > (safe_lshift_func_uint8_t_u_s (((g_181 == (((-4L) ^ g_101) | l_1553)) && l_1502), 6))) <= l_1619)), 3)) | l_1620), g_96)))))))) && 0x2CL) <= 0L)) || g_1473) != g_1309) & 0xD6L), 1)) | g_1504), g_387)));
   return
     g_245;
 }
 else
 {
   uint16_t
     l_1669
     =
     0UL;
   for
     (g_1039
      =
      0;
      (g_1039
       ==
       (-19));
      g_1039
      =
      safe_sub_func_int32_t_s_s
      (g_1039,
       8))
   {
     int16_t
       l_1688
       =
       (-10L);
     g_1671
       =
       (g_1670
        =
        (g_21
  =
  (((+(g_1473 > ((-1L) || ((((g_181 && 0x97E2L) < ((g_21 < 4294967290UL) | l_1669)) < g_1272) > g_96)))) | l_1522) != l_1554)));
     g_21
       =
       ((((safe_add_func_uint32_t_u_u (((1L >= ((safe_sub_func_int16_t_s_s ((safe_sub_func_int8_t_s_s ((((g_181 = 0L) > (l_1648 = ((safe_mul_func_uint8_t_u_u (((-6L) > (l_1529 == l_1619)), l_1561)) < (((((safe_lshift_func_uint8_t_u_u ((safe_add_func_uint16_t_u_u ((safe_lshift_func_uint16_t_u_s (l_1669, (safe_rshift_func_int16_t_s_u ((((0x22L & 0x57L) ^ 0x3C5BL) < l_1669), 2)))), 0xC115L)), l_1621)) > g_1272) <= 4294967295UL) <= 1L) && g_1670)))) && g_1504), g_1272)), g_1272)) ^ l_1688)) <= g_1238), 0x71032C88L)) > g_758) & g_1238) != l_1669);
     l_1502
       =
       ((-1L) == (g_21 = (l_1522 = (((safe_mul_func_uint8_t_u_u (((-4L) || ((safe_mul_func_uint8_t_u_u ((((safe_mul_func_int16_t_s_s (g_304, l_1688)) || (safe_add_func_uint16_t_u_u (g_129, (((safe_mod_func_int8_t_s_s (((safe_sub_func_int16_t_s_s ((((((safe_rshift_func_uint16_t_u_u ((safe_mod_func_int32_t_s_s ((l_1527 = (safe_add_func_uint16_t_u_u (((safe_rshift_func_uint8_t_u_u (((safe_sub_func_int32_t_s_s (0xCD3E3375L, (safe_mul_func_uint16_t_u_u (l_1688, (l_1553 && (((0UL <= l_1639) || g_1039) >= g_1670)))))) < l_1688), 2)) & 1L), 0x87E4L))), g_129)), l_1688)) & l_1561) | 0UL) == g_176) | l_1517), l_1522)) != g_245), l_1528)) != 0UL) & l_1502)))) || (-9L)), 1UL)) ^ g_245)), 0xFDL)) | 0xFF52L) ^ l_1688))));
     g_21
       =
       l_1554;
   }
   for
     (g_304
      =
      13;
      (g_304
       >
       14);
      g_304
      =
      safe_add_func_uint16_t_u_u
      (g_304,
       6))
   {
     uint16_t
       l_1742
       =
       65529UL;
     l_1744
       =
       (safe_add_func_uint32_t_u_u
        ((safe_mod_func_int8_t_s_s ((0UL & (g_181 = ((safe_rshift_func_uint8_t_u_u ((((safe_mod_func_uint16_t_u_u (g_94, ((safe_unary_minus_func_int8_t_s ((g_1272 ^ (g_176 = (g_387 = (safe_add_func_uint32_t_u_u (0UL, ((((((safe_lshift_func_uint16_t_u_s ((safe_lshift_func_uint8_t_u_s ((safe_unary_minus_func_int16_t_s (l_1731)), 5)), 2)) && 0x72L) < (safe_lshift_func_int16_t_s_u ((((((0UL >= (safe_mod_func_uint32_t_u_u (8UL, (safe_mul_func_uint16_t_u_u (((safe_lshift_func_uint8_t_u_u ((safe_lshift_func_int16_t_s_s ((((g_21 = (g_801 | l_1517)) && (-9L)) != (-3L)), 6)), 4)) >= g_1039), g_1671))))) == l_1648) > 0x8568C14AL) | g_1238) > l_1742), 12))) ^ g_1670) || g_7) && 0x92L)))))))) | l_1639))) == 1UL) | g_245), l_1743)) < g_94))), l_6)), l_1743));
   }
   g_21
     =
     ((l_1561 <= (0x47E5L && (l_1527 = 0x495CL))) < (g_1473 = l_1669));
 }
      }
      else
      {
 uint8_t
   l_1758
   =
   0x24L;
 int32_t
   l_1759
   =
   0x81109A3AL;
 int8_t
   l_1791
   =
   0x4FL;
 if ((safe_add_func_int32_t_s_s (1L, (l_1529 > (g_94 = l_1502)))))
 {
   return
     g_1238;
 }
 else
 {
   int8_t
     l_1753
     =
     (-7L);
   if (l_1621)
   {
     uint8_t
       l_1748
       =
       4UL;
     int32_t
       l_1760
       =
       0xEF03ED9BL;
     l_1748
       =
       (0x3F653466L
        &&
        g_1747);
     g_21
       =
       (((safe_add_func_int32_t_s_s (((254UL ^ (((1UL > g_1309) <= (65535UL <= (l_1760 = ((+(((safe_sub_func_uint16_t_u_u (l_1753, l_1748)) <= ((safe_sub_func_int8_t_s_s ((safe_add_func_int32_t_s_s (l_1753, 0x4BB4BCE3L)), (l_1648 = (l_1759 = (((g_75 >= l_1758) != 0x7CC56111L) >= g_1671))))) || g_176)) | l_1529)) && l_1748)))) < 9UL)) >= 0x8126D403L), 0xF5D62B3DL)) && g_304) > 0x1AL);
   }
   else
   {
     return
       g_181;
   }
 }
 g_21
   =
   ((safe_mul_func_int16_t_s_s ((!(safe_add_func_int8_t_s_s ((g_7 = (!(((((((safe_lshift_func_int16_t_s_s (l_1528, (((g_985 ^ (g_129 = (safe_mod_func_int16_t_s_s ((((safe_add_func_int8_t_s_s (0x2DL, (safe_mod_func_uint8_t_u_u ((safe_rshift_func_int8_t_s_u ((g_181 = ((safe_sub_func_int16_t_s_s (((safe_rshift_func_int16_t_s_u ((((g_94 = (safe_lshift_func_int16_t_s_u ((l_1528 == ((g_1473 > 252UL) < (((safe_add_func_uint8_t_u_u ((((l_1528 < (safe_mod_func_int32_t_s_s (((safe_add_func_int32_t_s_s (l_1619, ((((safe_add_func_int8_t_s_s ((!((safe_sub_func_uint32_t_u_u ((l_1731 < 0L), g_96)) & 0x4D969BF6L)), (-1L))) >= l_1791) == 0x9CL) < g_985))) || 0x68L), g_276))) || g_7) <= l_1522), g_387)) ^ 65535UL) < 0xD449L))), 0))) < g_1578) || 0UL), 13)) ^ g_304), 65535UL)) < 4294967295UL)), 7)), g_387)))) ^ 65531UL) > 0x488E960EL), g_833)))) <= g_1638) >= 0xDA28721CL))) ^ g_1473) >= g_387) == l_1791) ^ g_1272) & 0x06L) <= g_244))), g_1473))), l_1536)) < g_1473);
      }
      if (((safe_mod_func_int16_t_s_s ((l_1621 != (safe_mul_func_uint16_t_u_u (l_1527, (safe_mod_func_int8_t_s_s ((((9UL ^ ((4294967294UL & ((safe_mul_func_int8_t_s_s (0x2DL, (safe_unary_minus_func_uint8_t_u (0UL)))) & ((safe_unary_minus_func_int32_t_s ((safe_lshift_func_uint8_t_u_s (((safe_lshift_func_uint16_t_u_s ((l_1502 = (safe_rshift_func_int8_t_s_u (((safe_add_func_int16_t_s_s ((g_276 && l_1731), (safe_mul_func_uint16_t_u_u (l_1528, g_1638)))) >= l_1604), 2))), g_304)) > l_6), 3)))) & g_387))) < l_1619)) > l_1621) && g_1812), 0x0AL))))), l_1648)) ^ g_1504))
      {
 uint8_t
   l_1831
   =
   0UL;
 int32_t
   l_1856
   =
   (-1L);
 const
   int8_t
   l_1919
   =
   0x6BL;
 if ((l_1648 = (safe_lshift_func_uint16_t_u_s ((safe_sub_func_uint16_t_u_u (l_1817, (((safe_mul_func_int16_t_s_s ((safe_sub_func_int8_t_s_s ((((l_1527 = (((-3L) <= (safe_rshift_func_int8_t_s_u ((~(g_181 = (safe_sub_func_uint8_t_u_u ((((-1L) && (g_7 = ((l_1604 < (safe_lshift_func_uint16_t_u_u (l_1648, (0x9D570F2DL ^ (safe_rshift_func_uint16_t_u_s ((safe_unary_minus_func_int16_t_s (0xE43FL)), 15)))))) > g_96))) <= 0x2270127BL), 247UL)))), 0))) > l_1522)) >= l_1619) | 0xEC0AD06AL), g_1272)), 0x2B5AL)) < g_1578) || l_1831))), 3))))
 {
   return
     l_1502;
 }
 else
 {
   uint32_t
     l_1836
     =
     0xEAA8B7A6L;
   if (((((safe_add_func_uint8_t_u_u (((safe_add_func_int16_t_s_s ((l_1836 = g_985), (l_1536 ^ ((g_181 <= ((safe_unary_minus_func_int8_t_s (l_1502)) | (g_7 = l_1838))) ^ (safe_lshift_func_int8_t_s_u ((l_1648 = (safe_add_func_int8_t_s_s (g_176, (2L || ((l_1846 = (safe_unary_minus_func_int8_t_s ((l_1522 = (l_1831 > (safe_mul_func_uint8_t_u_u (7UL, g_387))))))) && l_1517))))), g_94)))))) ^ g_94), 255UL)) ^ (-5L)) != l_1536) >= 0x3D63C029L))
   {
     uint8_t
       l_1851
       =
       251UL;
     l_1856
       =
       (safe_add_func_uint16_t_u_u
        ((g_1670 > (+(safe_add_func_uint16_t_u_u (l_1517, (l_1851 < (l_1836 | ((g_7 = ((safe_add_func_uint32_t_u_u (l_1620, l_1831)) > g_304)) >= (0xA8L <= ((0xE141A503L | 0x997BBC64L) >= g_176))))))))), g_1272));
     return
       l_1851;
   }
   else
   {
     int16_t
       l_1859
       =
       0L;
     g_21
       =
       ((safe_lshift_func_uint8_t_u_u ((!0xC5L), l_1859)) | 0UL);
   }
   g_21
     =
     (+0xCB4D4C90L);
 }
 l_1856
   =
   g_1670;
 if (((g_758 || (g_129 && (((l_1527 == (safe_rshift_func_uint8_t_u_s (((g_94 = ((((((((safe_add_func_uint32_t_u_u (2UL, 0x363E41E8L)) >= ((safe_mod_func_uint32_t_u_u ((safe_mul_func_uint16_t_u_u (g_1578, (g_245 = l_1831))), (safe_sub_func_uint32_t_u_u (l_1517, (((l_1870 && l_1871) != l_1604) == l_1529))))) >= 0UL)) != 0xFEL) || 0x1B23CA96L) && g_181) ^ g_1671) == 0x19CC77BAL) | g_387)) < g_181), 0))) | l_1856) && g_1309))) && g_1747))
 {
   uint16_t
     l_1872
     =
     4UL;
   l_1846
     =
     (l_1870
      &
      l_1872);
 }
 else
 {
   uint8_t
     l_1885
     =
     0x63L;
   for
     (g_758
      =
      22;
      (g_758
       >=
       (-17));
      g_758
      =
      safe_sub_func_uint8_t_u_u
      (g_758,
       3))
   {
     uint16_t
       l_1886
       =
       65531UL;
     l_1887
       =
       (+
        (((g_304 != (((l_1648 = l_1648) ^ l_1604) != (g_370 = (g_1747 ^ (g_1504 == ((safe_sub_func_int16_t_s_s ((((safe_add_func_int8_t_s_s (g_129, (safe_rshift_func_uint8_t_u_u (((safe_mod_func_int32_t_s_s ((-4L), (safe_rshift_func_uint16_t_u_s (0xC844L, 9)))) != g_96), g_94)))) | l_6) != l_1871), l_1885)) && l_1886)))))) != 0xEE93L) | 0UL));
     l_1846
       =
       (l_1856
        =
        ((((g_1902 = ((safe_mul_func_uint16_t_u_u (((safe_mul_func_int16_t_s_s ((l_1731 != (g_94 = (safe_sub_func_int8_t_s_s (0x93L, (l_1522 = ((l_1886 <= (g_7 = ((g_181 = ((safe_mul_func_int8_t_s_s (((safe_mod_func_int16_t_s_s ((g_1670 & (g_244 == (((safe_rshift_func_int16_t_s_s (l_1886, 2)) >= l_1817) >= g_101))), (safe_rshift_func_int8_t_s_s ((+(0x28L != l_1887)), 1)))) & g_96), 0xABL)) || l_1502)) == g_129))) != 250UL)))))), (-10L))) < l_1838), 0x3528L)) >= 4294967290UL)) >= l_1886) ^ 0L) >= 0xD59B8F57L));
     l_1522
       =
       l_1856;
   }
 }
 for
   (g_75
    =
    0;
    (g_75
     !=
     22);
    g_75++)
 {
   uint32_t
     l_1923
     =
     0x8E25F55BL;
   g_21
     =
     (g_75
      &&
      (4294967287UL
       &
       ((0x53BDA693L | l_6) >= (l_1517 || (safe_add_func_uint8_t_u_u ((g_1670 < (safe_lshift_func_int8_t_s_u (((safe_lshift_func_uint16_t_u_u (g_21, ((safe_sub_func_uint32_t_u_u (((((safe_mod_func_int8_t_s_s ((((safe_lshift_func_int8_t_s_s ((((((safe_rshift_func_uint8_t_u_s ((l_1817 >= g_176), 5)) > l_1871) ^ l_1856) | (-10L)) != g_304), g_1671)) || l_1919) != 0xE0F3L), l_1817)) | g_129) > g_7) > g_1638), g_1504)) & g_1671))) && l_6), 3))), 0xD4L))))));
   g_1920
     =
     (g_21
      =
      (!l_1831));
   for
     (l_1648
      =
      2;
      (l_1648
       <
       (-5));
      --l_1648)
   {
     l_1923
       =
       g_245;
     g_21
       =
       1L;
   }
 }
      }
      else
      {
 if (g_244)
   goto
     lbl_1924;
      }
      l_1522
 =
 ((-7L) | (((l_1648 = (g_1238 || 0xA08CL)) <= g_1638) > (0xC5EBBF60L & (safe_rshift_func_int8_t_s_s (2L, ((l_1731 != (g_370 = 0x2B6C37A4L)) < (((g_304 > g_1309) > 7L) ^ 0x90CBL)))))));
      for
 (g_245
  =
  20;
  (g_245
   >
   8);
  --g_245)
      {
 int32_t
   l_1937
   =
   0L;
 int32_t
   l_1943
   =
   0x741DAB63L;
 int32_t
   l_1996
   =
   1L;
 if (((safe_lshift_func_uint8_t_u_s ((g_985 = ((safe_add_func_uint8_t_u_u ((g_244 == (safe_mul_func_uint8_t_u_u ((safe_rshift_func_int8_t_s_s ((g_1272 == (((4294967295UL < 1UL) > ((l_1846 | (l_1943 = (((((0x2A9C94E6L < l_1937) < g_101) && (safe_lshift_func_uint8_t_u_u (((((+(l_1536 = (safe_sub_func_uint16_t_u_u ((0x3AL != g_1039), g_176)))) && g_1920) || g_985) <= g_21), 6))) <= l_1522) & l_1942))) != 0x78L)) ^ g_1578)), 1)), l_1838))), 250UL)) | l_1554)), l_1517)) ^ g_245))
 {
   uint16_t
     l_1944
     =
     1UL;
   l_1944
     =
     g_304;
   l_1648
     =
     (safe_unary_minus_func_uint16_t_u
      ((g_1958 = (safe_sub_func_int16_t_s_s ((safe_lshift_func_int8_t_s_u ((g_1473 >= (safe_sub_func_uint32_t_u_u (1UL, ((((+(~(g_985 = 0x41L))) && (((g_21 >= (((1UL != (g_1957 = ((g_304 && 0x31CBL) <= ((l_1952 = (g_94 = l_1937)) || (safe_mod_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_s (l_1952, 14)) == g_244), 0x2DL)))))) < 0xDAL) >= l_1937)) & g_1578) == g_176)) ^ g_96) & g_96)))), 4)), l_1944)))));
   if (g_1504)
     continue;
 }
 else
 {
   int16_t
     l_1963
     =
     0L;
   if ((safe_add_func_int32_t_s_s ((safe_add_func_int32_t_s_s (l_1963, (g_1504 = (g_1812 = l_1619)))), (g_21 = (g_96 | ((g_1473 == (safe_rshift_func_int8_t_s_s (l_1937, 3))) && (l_1648 = (((((safe_mod_func_uint16_t_u_u (((safe_mul_func_uint16_t_u_u (0xAAD0L, ((g_129 = (safe_mod_func_uint8_t_u_u ((l_1619 & (safe_mod_func_int8_t_s_s (((g_1902 = (g_7 = (g_181 = ((l_1974 >= g_1309) <= l_1937)))) || 1L), l_1963))), l_1527))) ^ l_1522))) > 65535UL), 65535UL)) >= l_1528) < g_304) > g_21) && l_1963))))))))
   {
     int32_t
       l_1979
       =
       9L;
     g_2005
       =
       (((g_1309 | (safe_rshift_func_uint16_t_u_s ((l_1522 ^ (safe_add_func_int16_t_s_s (((g_21 = (l_1979 & (safe_mod_func_int32_t_s_s ((safe_sub_func_int8_t_s_s ((safe_sub_func_int8_t_s_s (g_181, (safe_sub_func_int32_t_s_s (((safe_add_func_int32_t_s_s ((safe_rshift_func_int8_t_s_s (0x5AL, 6)), (safe_sub_func_int32_t_s_s ((safe_add_func_uint8_t_u_u (((((l_1996 = g_1504) || ((l_1648 = (safe_lshift_func_int8_t_s_u (((safe_sub_func_uint16_t_u_u (65534UL, ((safe_mod_func_int8_t_s_s (0L, l_2003)) || g_985))) & 8UL), 0))) && g_96)) == g_1671) <= l_1963), 0x8DL)), g_833)))) & l_1943), l_2004)))), 0x4EL)), g_21)))) & 8L), g_1504))), l_1937))) | l_1943) == l_1554);
     l_1522
       =
       ((safe_sub_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u ((safe_mul_func_int16_t_s_s ((safe_lshift_func_uint8_t_u_u (((safe_mod_func_uint8_t_u_u ((0x5888L >= (6L > (l_1517 > (+(safe_mul_func_uint16_t_u_u (1UL, g_1812)))))), (safe_rshift_func_int8_t_s_u (l_1963, (g_758 > l_1621))))) || (0x3EC5L ^ 0x71F6L)), g_21)), l_1648)), 0xF4CD11F9L)), l_1963)) > g_1902);
   }
   else
   {
     l_1536
       =
       g_387;
   }
 }
 g_21
   =
   l_1870;
      }
    }
    l_1522
      =
      ((g_21 = 1L) ^ g_1309);
    l_1846
      =
      ((((safe_mod_func_int16_t_s_s ((((0x141BL != 0x44A5L) && (safe_mod_func_uint16_t_u_u (((-1L) > 5L), (safe_mul_func_int8_t_s_s (l_1522, (0x60L > ((safe_mul_func_int8_t_s_s (((safe_mul_func_uint8_t_u_u (255UL, (safe_rshift_func_uint16_t_u_s ((!l_1529), 3)))) ^ g_1638), g_96)) & l_6))))))) == g_21), g_94)) < g_96) || l_1817) | l_1503);
    if ((l_1536 = (l_2034 != (((((g_21 = (safe_add_func_uint16_t_u_u (l_2037, 0xE4ACL))) && (l_2046 = (safe_lshift_func_int8_t_s_s ((l_2045 = (l_2044 = (g_2005 = ((safe_mul_func_int8_t_s_s (l_2037, ((safe_sub_func_int8_t_s_s (0xC7L, 255UL)) < 8UL))) ^ (0xFA1AL < (g_1309 & l_1529)))))), l_1838)))) || g_1671) < 0xA396L) <= l_6))))
    {
      uint16_t
 l_2066
 =
 0x5265L;
      int32_t
 l_2067
 =
 6L;
      const
 int32_t
 l_2087
 =
 (-1L);
      const
 uint32_t
 l_2108
 =
 0x6617DF59L;
      int32_t
 l_2110
 =
 0xCAD847A7L;
      uint8_t
 l_2156
 =
 255UL;
      uint16_t
 l_2274
 =
 0UL;
      l_2067
 =
 ((((4294967292UL || (g_21 || (safe_rshift_func_int16_t_s_s (((safe_mod_func_uint8_t_u_u (((safe_sub_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u ((safe_mul_func_uint8_t_u_u ((((safe_rshift_func_int8_t_s_s (((((safe_mul_func_int16_t_s_s (((g_94 = ((safe_unary_minus_func_int8_t_s ((3UL ^ g_1902))) >= (-5L))) <= ((safe_add_func_uint32_t_u_u (0x680410C2L, (0xD6FCL != l_2066))) < g_181)), 1UL)) <= 0UL) != 0xA90A359CL) || l_1846), l_2045)) | l_2066) < 0x09F6L), l_2066)), g_370)), g_2005)) < l_1942), 0x15L)) != l_1536), 6)))) ^ 0x948A2E85L) < g_985) | 0L);
      for
 (l_1528
  =
  20;
  (l_1528
   >
   19);
  l_1528--)
      {
 int8_t
   l_2086
   =
   (-3L);
 int32_t
   l_2139
   =
   0xDEB09B4FL;
 int32_t
   l_2157
   =
   (-1L);
 int8_t
   l_2187
   =
   1L;
 g_21
   =
   (safe_add_func_uint32_t_u_u
    ((safe_rshift_func_uint16_t_u_s ((safe_add_func_uint16_t_u_u (l_2066, g_1957)), ((safe_unary_minus_func_int8_t_s (g_1473)) != (247UL || (safe_lshift_func_uint16_t_u_s ((safe_mod_func_int8_t_s_s (0x1EL, (safe_mod_func_uint32_t_u_u (g_7, (safe_add_func_uint16_t_u_u (l_2085, g_1902)))))), ((l_2067 & l_2086) >= l_1871))))))), l_2087));
 if ((65533UL | (g_96 <= 0xE601L)))
 {
   const
     uint16_t
     l_2109
     =
     0xEE42L;
   int32_t
     l_2158
     =
     (-1L);
   g_2112
     =
     (safe_mul_func_int16_t_s_s
      ((g_1039 & 0x1AL), (safe_rshift_func_uint8_t_u_u ((safe_rshift_func_int8_t_s_u ((g_181 > g_370), (safe_unary_minus_func_uint8_t_u ((safe_rshift_func_int16_t_s_u ((((l_1536 = 0x92L) ^ ((safe_rshift_func_int8_t_s_u (l_2066, 1)) == (safe_mod_func_uint8_t_u_u ((((l_2067 = ((g_1504 = (g_129 = (safe_unary_minus_func_uint32_t_u ((((g_21 = 0x3B437B13L) && l_2086) ^ ((safe_rshift_func_int8_t_s_u ((((safe_add_func_uint8_t_u_u ((safe_mod_func_uint8_t_u_u (9UL, g_96)), l_2108)) < l_2109) | g_1671), g_370)) && 0x65E77BA1L)))))) != 0x81D890C4L)) || l_2109) != l_2110), g_2111)))) | g_75), g_1671)))))), 7))));
   if ((safe_mod_func_uint8_t_u_u ((7L < (g_304 > (l_1846 = (safe_rshift_func_int8_t_s_s ((l_2139 = (safe_sub_func_uint32_t_u_u ((l_2119 < (l_1522 = ((((safe_mul_func_int8_t_s_s ((safe_mod_func_int8_t_s_s (((!((safe_add_func_int8_t_s_s (((safe_mul_func_uint16_t_u_u (l_1503, (l_2003 != (safe_lshift_func_int16_t_s_s (l_2034, (safe_sub_func_int8_t_s_s ((safe_mul_func_uint8_t_u_u (((safe_lshift_func_uint8_t_u_u (g_176, ((((+(safe_mod_func_uint16_t_u_u ((g_276 & (9UL | g_1671)), l_2086))) > l_2086) == g_985) <= 0xB7C7L))) > l_2045), l_2138)), 0xE7L))))))) && g_2005), 255UL)) > 4294967293UL)) >= l_1942), g_75)), 1UL)) <= g_1958) <= l_2108) != g_1638))), g_1920))), l_2037))))), 1UL)))
   {
     int8_t
       l_2140
       =
       (-1L);
     l_2140
       =
       g_75;
     if (g_1958)
       break;
     l_2139
       =
       (safe_add_func_uint8_t_u_u
        ((((l_1527 = (safe_mul_func_int16_t_s_s (l_2140, (safe_mul_func_int16_t_s_s (g_75, l_1522))))) ^ (l_2108 ^ (l_2044 > (safe_unary_minus_func_uint16_t_u ((safe_sub_func_uint8_t_u_u (l_2139, (l_2157 = (l_2110 >= (safe_rshift_func_int8_t_s_u ((safe_add_func_int32_t_s_s (((7UL || ((safe_mod_func_uint16_t_u_u (l_1522, l_2140)) & g_801)) | l_2156), l_2140)), 0))))))))))) == l_2086), 1L));
   }
   else
   {
     l_2158
       =
       0x5028AC37L;
   }
   for
     (g_1812
      =
      0;
      (g_1812
       <=
       50);
      g_1812++)
   {
     uint32_t
       l_2161
       =
       0x76B62AABL;
     if (l_2161)
       break;
     l_2188
       =
       ((l_2162 ^ (safe_mod_func_int32_t_s_s (l_2108, 4294967286UL))) != (safe_mod_func_uint32_t_u_u (l_1502, ((+(safe_rshift_func_int8_t_s_s ((safe_mod_func_int32_t_s_s ((g_21 = ((l_2158 = (0x5351L >= g_96)) < g_1957)), (l_6 ^ (safe_sub_func_uint8_t_u_u (((+(safe_add_func_int16_t_s_s ((safe_sub_func_uint32_t_u_u ((((safe_mul_func_uint8_t_u_u (((safe_lshift_func_uint16_t_u_s ((safe_mul_func_uint16_t_u_u ((((((((safe_mod_func_uint32_t_u_u ((safe_rshift_func_uint16_t_u_s (g_1638, l_2187)), (-1L))) & l_2109) && l_2187) < 0UL) < g_129) != l_1621) <= 3UL), g_1812)), 9)) && l_2067), g_1638)) >= g_1504) ^ l_2066), l_2087)), l_1522))) != 1UL), l_2087))))), g_1958))) && g_2111))));
     g_2189
       =
       (g_21
        =
        g_304);
     g_21
       =
       ((!(safe_lshift_func_int16_t_s_u ((!g_244), (((0x00L > (l_2192 && (safe_mul_func_uint8_t_u_u (l_2108, (4L && (g_387 = 9UL)))))) ^ (safe_sub_func_uint32_t_u_u (((safe_add_func_uint16_t_u_u (l_2108, (safe_rshift_func_uint16_t_u_u ((l_1621 > (l_2067 & l_2161)), 12)))) || g_1902), l_2201))) != (-1L))))) <= 0x52B7L);
   }
 }
 else
 {
   uint32_t
     l_2210
     =
     6UL;
   int16_t
     l_2217
     =
     3L;
   for
     (l_1846
      =
      27;
      (l_1846
       ==
       20);
      l_1846--)
   {
     l_1502
       =
       g_2189;
     g_21
       =
       (-10L);
   }
   if (g_1958)
     continue;
   if (((safe_mod_func_uint8_t_u_u ((l_2004 != (safe_mul_func_int16_t_s_s ((l_2156 != (safe_add_func_int32_t_s_s (((l_2046 || l_2045) | g_1670), ((g_1473 = 0x3E82L) & ((l_2210 >= ((safe_lshift_func_uint16_t_u_s ((safe_mul_func_uint16_t_u_u ((((safe_mul_func_uint16_t_u_u ((g_1958 > (0xFE46L | g_129)), l_2217)) < 65534UL) >= 0x51L), 0x2272L)), 13)) == l_2187)) && g_1309))))), 0xB512L))), l_2086)) <= 0x49L))
   {
     int32_t
       l_2230
       =
       (-1L);
     int32_t
       l_2241
       =
       0xBAEB9065L;
     g_21
       =
       l_2210;
     g_21
       =
       (safe_add_func_uint8_t_u_u
        ((safe_add_func_int16_t_s_s ((g_370 != (safe_sub_func_uint32_t_u_u ((safe_mod_func_int8_t_s_s (((safe_sub_func_int8_t_s_s (((safe_mod_func_uint16_t_u_u (g_1957, g_304)) != l_2004), (l_2230 = 255UL))) <= ((safe_mul_func_int16_t_s_s ((safe_sub_func_int8_t_s_s ((l_2244 = (((safe_rshift_func_int16_t_s_u (((safe_lshift_func_int8_t_s_u ((-4L), 2)) || (safe_mul_func_int16_t_s_s (l_2241, l_2241))), (safe_lshift_func_uint16_t_u_u ((l_2241 > g_94), 2)))) >= 0x22FDC024L) != g_1671)), l_2108)), 65535UL)) > g_304)), 0x95L)), (-10L)))), 1UL)), 249UL));
   }
   else
   {
     int16_t
       l_2257
       =
       0x48C6L;
     int32_t
       l_2282
       =
       0x841DDE02L;
     l_2067
       =
       ((safe_add_func_uint32_t_u_u ((l_2157 = ((g_7 = (safe_lshift_func_uint8_t_u_u (l_2087, 2))) ^ (g_1473 | ((g_1957 >= ((g_2111 = (((((g_245 = (l_1502 = (l_1846 = (safe_rshift_func_int16_t_s_u ((g_1578 > (g_1504 = (safe_add_func_int32_t_s_s (g_2111, (!g_245))))), 0))))) & 0xE10DL) <= ((safe_mod_func_int8_t_s_s (((-6L) >= (safe_add_func_int8_t_s_s ((l_2210 == l_2110), l_2192))), g_833)) || g_1902)) & l_2110) >= g_75)) != l_2257)) || 0xA8L)))), 0x7D79DBC0L)) != l_2257);
     g_2286
       =
       (l_1527
        =
        (((~0xC9E6L) <= ((safe_sub_func_int16_t_s_s ((safe_lshift_func_int8_t_s_s ((((((((l_2210 != (safe_mod_func_int16_t_s_s (((g_2285 = (safe_sub_func_int8_t_s_s ((safe_sub_func_int32_t_s_s (((safe_rshift_func_uint8_t_u_u ((safe_sub_func_int32_t_s_s (((((safe_sub_func_int16_t_s_s ((g_1473 = l_1870), l_2257)) | (l_2274 == l_2066)) == ((g_21 = ((safe_rshift_func_int16_t_s_s ((g_245 = (l_2282 = (252UL > ((safe_rshift_func_int16_t_s_u (g_2189, (safe_mod_func_uint32_t_u_u ((((l_2257 <= g_304) > l_2086) == l_2281), g_96)))) != g_2112)))), 15)) == l_2283)) && l_2217)) < l_2284), 0x9C195391L)), l_2257)) >= l_2156), 4294967295UL)), l_2139))) ^ (-9L)), g_7))) ^ g_1238) || 0x6745L) < 2UL) || l_2157) | g_181) & 0x3CL), g_1671)), g_181)) ^ g_2189)) && 0xABCBL));
   }
 }
 l_2289
   =
   (l_2110
    =
    (safe_mod_func_int8_t_s_s
     ((g_2286 = l_2162), g_94)));
      }
      for
 (g_370
  =
  0;
  (g_370
   ==
   36);
  ++g_370)
      {
 uint16_t
   l_2296
   =
   1UL;
 g_21
   =
   g_1670;
 g_21
   =
   ((~(7L <= (safe_rshift_func_int8_t_s_s ((0xB9ECL & g_1638), (l_2162 <= (l_1529 <= l_1528)))))) >= (0xB7L == (0xCBD0L > (l_2296 > l_2110))));
 l_1536
   =
   ((safe_rshift_func_int16_t_s_u (0xFE65L, 6)) != l_1838);
      }
    }
    else
    {
      int32_t
 l_2326
 =
 1L;
      for
 (l_2085
  =
  (-15);
  (l_2085
   >=
   60);
  l_2085++)
      {
 int8_t
   l_2311
   =
   0x05L;
 int32_t
   l_2323
   =
   2L;
 l_2323
   =
   (g_21
    =
    ((+(safe_sub_func_int8_t_s_s ((safe_mul_func_uint16_t_u_u ((safe_rshift_func_int8_t_s_u (l_2192, (g_985 = (l_2046 = ((safe_lshift_func_uint8_t_u_u (((safe_add_func_int8_t_s_s (((g_801 || g_2286) | l_1503), (((((l_2311 = g_1670) >= (safe_mod_func_int16_t_s_s (((safe_unary_minus_func_uint32_t_u ((safe_add_func_uint16_t_u_u ((((g_1902 = (safe_sub_func_uint16_t_u_u ((0xDC91L | ((0x63A9L == ((safe_mod_func_int32_t_s_s ((((0x80L ^ ((safe_mod_func_uint32_t_u_u (0x3A9168D1L, (-10L))) | l_2289)) ^ 0xA966L) || 0x1917L), l_2323)) == 4294967295UL)) < l_2323)), 1UL))) >= g_75) | 0x34L), 65535UL)))) < 65532UL), 5UL))) >= l_1528) | 1L) != g_94))) >= g_2005), 7)) > 255UL))))), g_94)), g_7))) < l_1942));
 l_2323
   =
   (-2L);
      }
      g_21
 =
 (safe_mod_func_uint32_t_u_u
  ((0x60L == (l_2326 || l_2326)), l_2192));
    }
  }
  else
  {
    int32_t
      l_2339
      =
      (-1L);
    const
      int32_t
      l_2344
      =
      0x91B14262L;
    int8_t
      l_2345
      =
      0x58L;
    int32_t
      l_2346
      =
      1L;
    int32_t
      l_2347
      =
      1L;
    uint32_t
      l_2354
      =
      1UL;
    int32_t
      l_2365
      =
      0xC9C45AC9L;
    uint16_t
      l_2372
      =
      0xC846L;
    l_1846
      =
      (safe_sub_func_uint8_t_u_u
       (l_2188,
 (safe_mul_func_int8_t_s_s
  (((safe_rshift_func_int8_t_s_s (((safe_mod_func_int8_t_s_s ((safe_mod_func_uint8_t_u_u (g_801, 1L)), g_1812)) == 0x3BCE84F1L), 1)) ^ ((safe_sub_func_int32_t_s_s (l_2339, 0x7C597C89L)) >= (safe_add_func_uint16_t_u_u (((((((g_245 = (((safe_sub_func_int32_t_s_s (((((l_2346 = ((g_276 = (g_1812 < ((l_2344 ^ g_244) == l_2281))) < l_2345)) || g_245) >= 0x70EEL) & 0x67L), l_1528)) ^ (-1L)) | g_1812)) && 9UL) || l_2188) == l_2347) != g_96) <= l_1502), g_101)))), 1UL))));
    for
      (l_6
       =
       (-10);
       (l_6
 <=
 13);
       l_6
       =
       safe_add_func_int32_t_s_s
       (l_6,
 1))
    {
      const
 uint16_t
 l_2357
 =
 65530UL;
      int32_t
 l_2358
 =
 0L;
      g_21
 =
 ((safe_sub_func_int8_t_s_s ((g_1504 & ((((safe_sub_func_int8_t_s_s (l_2354, (safe_add_func_int16_t_s_s ((l_2339 ^ ((l_2358 = (l_2357 == g_1671)) || 65535UL)), ((g_1902 = (0xBEL & g_370)) && (safe_add_func_int8_t_s_s (l_2347, 0L))))))) || 0xB869A9F5L) ^ g_7) == l_2357)), 0x7AL)) || g_1238);
      l_2358
 =
 (l_2344
  !=
  ((safe_lshift_func_uint8_t_u_u (g_2112, g_75)) == g_2112));
    }
    l_2365
      =
      (safe_rshift_func_int8_t_s_s
       ((l_2365 | 4L), (((g_1039 != (((((((((l_2346 = l_2119) <= (safe_mod_func_int32_t_s_s (((((0UL <= (((g_21 = ((g_370 = (safe_add_func_int8_t_s_s ((g_7 = (safe_add_func_uint32_t_u_u (l_2372, (g_129 & 8L)))), ((((l_1536 = g_1902) != 254UL) >= g_96) && 0x9DL)))) <= 0x7479A5BEL)) && g_985) ^ g_1902)) & 0x8EL) <= 0xDD6A8718L) | 0xA3CE6513L), l_2345))) | 1UL) & l_2365) | l_2345) && g_1504) == g_176) <= l_1528) <= l_2372)) <= g_244) & g_758)));
  }
  g_21
    =
    ((l_2281 < l_2284) || ((g_245 = (g_1902 < (g_1671 | ((g_370 = (safe_mod_func_uint32_t_u_u ((safe_rshift_func_uint16_t_u_u (((g_181 = (g_1504 == ((((!((l_1503 != ((safe_lshift_func_int8_t_s_s (((safe_rshift_func_int16_t_s_s ((safe_lshift_func_uint8_t_u_s (((1L | (safe_add_func_int8_t_s_s ((l_2119 | 0x4466B2CBL), 0xA6L))) < l_1887), g_1670)), g_1578)) <= g_1039), l_2192)) || 0x5850L)) >= l_1942)) == 4294967290UL) > l_1887) & g_2189))) & l_2192), l_2188)), g_75))) && l_1870)))) || 0xC351L));
  g_21
    =
    (((!(safe_rshift_func_uint16_t_u_u ((l_1536 = ((safe_mul_func_int8_t_s_s ((((safe_rshift_func_int16_t_s_u ((+((g_2189 = l_2138) && 0xD62FA49CL)), (l_2394 = (safe_lshift_func_uint16_t_u_u (l_2393, 8))))) <= (l_1502 = g_244)) && 0xFE35FCECL), ((safe_mod_func_uint8_t_u_u ((g_1670 && ((safe_unary_minus_func_uint16_t_u (l_2192)) == ((safe_mod_func_int8_t_s_s ((g_1812 > g_2005), l_2119)) ^ l_2138))), 0x9EL)) && g_21))) && l_1846)), g_1670))) & g_2112) != 0x07L);
  return
    g_1920;
}
static int32_t
func_2
  (int8_t
   p_3,
   uint8_t
   p_4,
   uint32_t
   p_5
)
{
  uint32_t
    l_8
    =
    0x4F147909L;
  int32_t
    l_12
    =
    0x29989D22L;
  int16_t
    l_880
    =
    2L;
  int8_t
    l_903
    =
    1L;
  uint8_t
    l_1006
    =
    0xD0L;
  int16_t
    l_1032
    =
    0x2A1AL;
  uint16_t
    l_1100
    =
    0UL;
  int16_t
    l_1111
    =
    0x0728L;
  int32_t
    l_1164
    =
    1L;
  int32_t
    l_1195
    =
    0xEF0BEB06L;
  uint8_t
    l_1444
    =
    253UL;
  int16_t
    l_1445
    =
    0x929EL;
  int32_t
    l_1472
    =
    0xDEC28B43L;
  int32_t
    l_1474
    =
    0x8B42333CL;
  uint16_t
    l_1485
    =
    0UL;
lbl_988:
  l_8 = g_7;
  for
    (p_4
     =
     (-8);
     (p_4
      >=
      53);
     ++p_4)
  {
    uint8_t
      l_11
      =
      0xE0L;
    int32_t
      l_180
      =
      0x6BF4A85DL;
    int32_t
      l_881
      =
      (-10L);
    uint32_t
      l_902
      =
      0x6670702EL;
    uint8_t
      l_924
      =
      0xA9L;
    int8_t
      l_1023
      =
      (-1L);
    int8_t
      l_1351
      =
      0x1BL;
    l_12
      =
      (l_11
       =
       2L);
    g_21
      =
      (safe_mul_func_uint16_t_u_u
       ((safe_lshift_func_uint8_t_u_s (0x12L, 0)), (safe_mul_func_uint16_t_u_u (p_4, (safe_rshift_func_int16_t_s_u (g_7, 0))))));
    if ((func_22 (p_4, (((1L & l_8) || ((((safe_sub_func_uint8_t_u_u (func_30 (func_33 ((safe_lshift_func_uint16_t_u_u (65535UL, (l_12 = func_39 (((func_41 (func_46 (g_7), p_5, (l_180 = (safe_rshift_func_uint16_t_u_u (l_8, 6))), g_181) ^ 4UL) & g_181))))), l_11, p_5), g_833), p_3)) && g_94) && l_8) >= p_4)) & 0L), l_8, l_8, g_833) && 0xBE6DL))
    {
      uint8_t
 l_867
 =
 1UL;
      l_180
 =
 0x383FC3BAL;
      return
 l_867;
    }
    else
    {
      uint32_t
 l_875
 =
 1UL;
      int8_t
 l_901
 =
 0L;
      int32_t
 l_954
 =
 0xD29443E5L;
      int32_t
 l_987
 =
 0xAA200D6AL;
      const
 uint32_t
 l_1077
 =
 0x585E1491L;
      int32_t
 l_1078
 =
 0x178F79C8L;
      uint32_t
 l_1166
 =
 3UL;
      if ((safe_rshift_func_int16_t_s_s (g_75, 8)))
      {
 int32_t
   l_872
   =
   0x5CA30D54L;
 int32_t
   l_916
   =
   0x794D6A80L;
 uint32_t
   l_1079
   =
   0x60947BDFL;
 uint32_t
   l_1080
   =
   4294967287UL;
 int32_t
   l_1135
   =
   0L;
 l_12
   =
   (0xE8L
    >
    (((l_8 >= 0x70A81F96L) >= (l_872 != ((safe_rshift_func_int16_t_s_s ((l_180 = (l_875 = 0xD1FCL)), 14)) && 0x25C8L))) == ((safe_add_func_uint8_t_u_u (g_94, (safe_add_func_uint16_t_u_u ((l_881 = ((g_245 = (+(l_880 >= (l_11 & l_11)))) >= 65535UL)), p_5)))) < g_801)));
l_12
      =
      (l_11
       =
       2L);
 if ((((l_872 & (safe_lshift_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u ((g_304 == (((safe_add_func_uint32_t_u_u (l_881, (safe_mul_func_int8_t_s_s (p_5, ((safe_mul_func_uint8_t_u_u ((safe_mod_func_uint8_t_u_u (((l_901 = ((0UL ^ ((p_3 & g_244) ^ (safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u (((safe_rshift_func_uint16_t_u_u (g_801, (safe_unary_minus_func_uint16_t_u (g_387)))) > 0x01CC121CL), 1UL)), p_3)))) & p_5)) > l_902), l_903)), g_181)) != g_96))))) > 4294967289UL) == g_7)), l_902)), g_181))) >= g_245) ^ p_3))
 {
   uint16_t
     l_923
     =
     0x8F5EL;
   int32_t
     l_925
     =
     (-1L);
{
      uint8_t
 l_867
 =
 1UL;
      l_180
 =
 0x383FC3BAL;
      return
 l_867;
    }
   l_916
     =
     l_903;
   l_916
     =
     (g_21
      =
      (0L
       >
       ((safe_mul_func_int16_t_s_s ((safe_mul_func_uint16_t_u_u ((g_7 < g_129), (safe_mod_func_int32_t_s_s ((safe_mul_func_uint8_t_u_u ((g_833 > (((safe_rshift_func_uint8_t_u_u (g_21, 6)) >= (g_801 || (safe_lshift_func_uint16_t_u_s (g_101, 14)))) <= l_12)), l_872)), l_8)))), g_94)) ^ 0x7096L)));
   l_12
     =
     (((((safe_mul_func_uint8_t_u_u (0UL, (safe_mod_func_uint16_t_u_u (p_4, (safe_rshift_func_uint8_t_u_s ((((l_925 = (g_758 & (g_304 & (((safe_mod_func_uint8_t_u_u (g_7, (safe_mul_func_int8_t_s_s (p_3, (l_916 = g_101))))) > ((safe_lshift_func_uint8_t_u_s ((((l_954 = ((safe_rshift_func_uint16_t_u_s (p_3, (((((0x9DACL | l_872) | l_923) || g_129) <= 0x34L) == l_872))) >= 0UL)) && p_3) >= 7UL), 4)) >= l_925)) != 0x9CL)))) & g_96) != g_276), 7)))))) ^ p_5) && 0x18433684L) < 0L) >= 0xB1EF5C0FL);
 }
 else
 {
   uint32_t
     l_986
     =
     0x0CCA817DL;
   for
     (p_5
      =
      0;
      (p_5
       <=
       60);
      p_5
      =
      safe_add_func_uint16_t_u_u
      (p_5,
       1))
   {
     int32_t
       l_971
       =
       0L;
     int32_t
       l_972
       =
       (-1L);
for
     (p_5
      =
      0;
      (p_5
       <=
       60);
      p_5
      =
      safe_add_func_uint16_t_u_u
      (p_5,
       1))
   {
     int32_t
       l_971
       =
       0L;
     int32_t
       l_972
       =
       (-1L);
     l_12
       =
       (g_96
        ^
        (safe_add_func_uint16_t_u_u
  ((safe_lshift_func_uint16_t_u_s (l_901, 7)), p_3)));
     l_916
       =
       (safe_add_func_uint8_t_u_u
        ((((((safe_add_func_int8_t_s_s ((safe_rshift_func_int16_t_s_u ((g_245 = 0x3C92L), (g_94 = 65535UL))), (safe_mod_func_uint16_t_u_u ((safe_mod_func_int32_t_s_s (0xD9FC3466L, (l_972 = l_971))), (safe_sub_func_uint32_t_u_u (((((1L & (l_916 <= 0UL)) && (((safe_rshift_func_int16_t_s_s (p_5, ((safe_mod_func_int16_t_s_s ((((safe_add_func_int16_t_s_s ((g_985 = ((safe_mul_func_int8_t_s_s (((safe_add_func_int32_t_s_s (p_3, g_176)) >= 0L), l_971)) >= p_3)), g_758)) <= 0x8D42L) == g_96), 65529UL)) ^ l_903))) || p_5) & l_986)) && l_12) ^ l_987), 0x6972FE86L)))))) & g_387) != 0x9D45F9D8L) != 0x29F0L) || p_4), l_971));
   }
     l_916
       =
       (safe_add_func_uint8_t_u_u
        ((((((safe_add_func_int8_t_s_s ((safe_rshift_func_int16_t_s_u ((g_245 = 0x3C92L), (g_94 = 65535UL))), (safe_mod_func_uint16_t_u_u ((safe_mod_func_int32_t_s_s (0xD9FC3466L, (l_972 = l_971))), (safe_sub_func_uint32_t_u_u (((((1L & (l_916 <= 0UL)) && (((safe_rshift_func_int16_t_s_s (p_5, ((safe_mod_func_int16_t_s_s ((((safe_add_func_int16_t_s_s ((g_985 = ((safe_mul_func_int8_t_s_s (((safe_add_func_int32_t_s_s (p_3, g_176)) >= 0L), l_971)) >= p_3)), g_758)) <= 0x8D42L) == g_96), 65529UL)) ^ l_903))) || p_5) & l_986)) && l_12) ^ l_987), 0x6972FE86L)))))) & g_387) != 0x9D45F9D8L) != 0x29F0L) || p_4), l_971));
   }
   if (l_901)
     ;
 }
{
      uint8_t
 l_867
 =
 1UL;
      l_180
 =
 0x383FC3BAL;
      return
 l_867;
    }
{
   uint16_t
     l_923
     =
     0x8F5EL;
   int32_t
     l_925
     =
     (-1L);
   l_925
     =
     (safe_mod_func_int16_t_s_s
      ((safe_add_func_int8_t_s_s (p_4, (((0x3DA89BD6L <= ((safe_lshift_func_uint8_t_u_u ((((l_923 = (p_4 <= ((safe_lshift_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u (((safe_rshift_func_uint16_t_u_s (p_3, 6)) & ((l_916 = g_75) > (safe_mul_func_uint8_t_u_u (p_3, (safe_mod_func_uint16_t_u_u (l_12, (safe_mul_func_uint16_t_u_u (l_901, 0x8840L)))))))), g_94)), 8)) < l_902))) == g_94) > p_4), l_924)) > 8UL)) ^ g_276) >= l_901))), p_4));
   l_916
     =
     l_903;
   l_916
     =
     (g_21
      =
      (0L
       >
       ((safe_mul_func_int16_t_s_s ((safe_mul_func_uint16_t_u_u ((g_7 < g_129), (safe_mod_func_int32_t_s_s ((safe_mul_func_uint8_t_u_u ((g_833 > (((safe_rshift_func_uint8_t_u_u (g_21, 6)) >= (g_801 || (safe_lshift_func_uint16_t_u_s (g_101, 14)))) <= l_12)), l_872)), l_8)))), g_94)) ^ 0x7096L)));
   l_12
     =
     (((((safe_mul_func_uint8_t_u_u (0UL, (safe_mod_func_uint16_t_u_u (p_4, (safe_rshift_func_uint8_t_u_s ((((l_925 = (g_758 & (g_304 & (((safe_mod_func_uint8_t_u_u (g_7, (safe_mul_func_int8_t_s_s (p_3, (l_916 = g_101))))) > ((safe_lshift_func_uint8_t_u_s ((((l_954 = ((safe_rshift_func_uint16_t_u_s (p_3, (((((0x9DACL | l_872) | l_923) || g_129) <= 0x34L) == l_872))) >= 0UL)) && p_3) >= 7UL), 4)) >= l_925)) != 0x9CL)))) & g_96) != g_276), 7)))))) ^ p_5) && 0x18433684L) < 0L) >= 0xB1EF5C0FL);
 }
      }
      else
      {
 int32_t
   l_1138
   =
   (-1L);
      }
      l_1166
 =
 (((safe_rshift_func_uint16_t_u_u (g_801, 10)) != (((((safe_rshift_func_uint8_t_u_u ((safe_lshift_func_uint16_t_u_u (((safe_sub_func_int8_t_s_s ((!(-9L)), (-1L))) ^ (((safe_add_func_uint32_t_u_u ((safe_sub_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u ((g_370 = (safe_sub_func_int16_t_s_s (((safe_unary_minus_func_int16_t_s ((l_1164 = ((l_12 = 0xF8L) != ((safe_rshift_func_int16_t_s_s (l_1100, (p_3 > 4294967295UL))) <= p_5))))) ^ (safe_unary_minus_func_uint32_t_u (g_176))), g_96))), p_5)), l_901)), g_304)) || 0xF432DF52L) >= l_902)), g_1039)), 4)) <= 255UL) <= 1UL) == (-1L)) && 0xC3L)) | p_4);
    }
  }
  l_1474
    =
    (safe_mul_func_int8_t_s_s
     ((~p_5), (((p_4 = (p_4 & ((((~(g_1473 = (+(l_1006 <= (0x23E1L & (((((safe_add_func_int32_t_s_s ((safe_sub_func_uint16_t_u_u ((1L || (safe_lshift_func_uint16_t_u_s ((safe_sub_func_int16_t_s_s ((l_1472 = (((safe_lshift_func_int16_t_s_u (p_3, 7)) & (safe_rshift_func_uint8_t_u_u ((l_1195 = ((((l_12 = (safe_lshift_func_int16_t_s_s ((safe_rshift_func_uint16_t_u_u ((safe_sub_func_uint8_t_u_u (((safe_mod_func_int8_t_s_s ((((safe_rshift_func_int16_t_s_s ((safe_mod_func_uint32_t_u_u ((g_129 = (l_1164 = g_387)), p_4)), (g_245 = (g_181 & 0x9360L)))) || 0xA9EE2D53L) && 0xADL), 0xE8L)) && l_1445), p_5)), g_21)), g_801))) < p_5) < l_8) && 0x8A53L)), 4))) || 0x8AA32183L)), l_1032)), g_758))), l_903)), 1UL)) > p_4) != 0UL) < 0x419BB00BL) == g_758)))))) >= 1UL) <= 5UL) ^ p_4))) > g_96) | 1L)));
  g_21
    =
    ((0xB0503962L ^ ((l_1195 < ((safe_lshift_func_uint8_t_u_u (0xE6L, (safe_mod_func_int32_t_s_s ((safe_sub_func_int8_t_s_s ((safe_add_func_int16_t_s_s (l_1195, 0xB80FL)), (l_1485 | (((safe_rshift_func_int16_t_s_u (l_1445, (l_1100 > (safe_sub_func_int32_t_s_s (g_1272, p_5))))) >= 0xA26DC6CBL) <= l_1195)))), p_3)))) == 0UL)) > g_1473)) && p_4);
  return
    p_4;
}
static uint16_t
func_22
  (const
   int32_t
   p_23,
   int8_t
   p_24,
   int8_t
   p_25,
   int8_t
   p_26,
   uint16_t
   p_27
)
{
  uint32_t
    l_841
    =
    0xE58D9DE8L;
  int32_t
    l_857
    =
    0x4A8B6334L;
  int8_t
    l_858
    =
    6L;
  int32_t
    l_859
    =
    0x6C57F8F2L;
  uint32_t
    l_860
    =
    0xA5A63E45L;
  int32_t
    l_861
    =
    0x4D5EF804L;
  int16_t
    l_862
    =
    9L;
  l_861
    =
    (0x9C5E4B1FL
     >
     ((l_859 = (safe_unary_minus_func_int32_t_s (((safe_rshift_func_uint16_t_u_u ((p_27 = ((safe_mod_func_uint16_t_u_u ((((g_370 = (g_181 < l_841)) != p_27) && l_841), (safe_sub_func_uint16_t_u_u ((safe_sub_func_uint8_t_u_u (p_24, ((((4294967295UL >= (safe_add_func_uint8_t_u_u ((safe_lshift_func_int16_t_s_u (((((safe_unary_minus_func_int32_t_s ((l_857 = (2UL != ((safe_sub_func_int8_t_s_s ((safe_sub_func_int8_t_s_s ((((!(+((safe_rshift_func_uint8_t_u_u (g_304, l_841)) == 5L))) > p_23) > 250UL), l_841)), g_101)) ^ 1L))))) != g_304) == p_23) >= g_181), l_858)), p_24))) | (-1L)) != p_23) & 0L))), 0x1A8DL)))) < g_94)), 0)) ^ l_858)))) ^ l_860));
  l_859
    =
    ((l_857 = l_861) || (g_833 && ((g_176 < (l_861 = ((g_758 <= 0x3306L) > ((l_862 | (safe_mod_func_int16_t_s_s ((safe_mul_func_int16_t_s_s (((((l_861 == ((0x5CA5L < (0UL && 0xEBL)) && g_75)) < p_25) && p_24) <= 0x8ED1L), l_857)), l_862))) <= g_304)))) ^ 0xD0EB130EL)));
  return
    p_26;
}
static const uint8_t
func_30
  (int16_t
   p_31,
   const
   int16_t
   p_32
)
{
  const
    int16_t
    l_834
    =
    0xAF9DL;
  int32_t
    l_835
    =
    0xCCA57B9AL;
  g_21
    =
    l_834;
  g_21
    =
    0x2D84DA33L;
  l_835
    =
    (0x0175L
     &&
     (g_94
      =
      p_31));
  return
    l_835;
}
static int16_t
func_33
  (uint16_t
   p_34,
   uint32_t
   p_35,
   const
   int8_t
   p_36
)
{
  int8_t
    l_815
    =
    0x0FL;
  int32_t
    l_831
    =
    0x0C3C9363L;
  int32_t
    l_832
    =
    (-1L);
  l_832
    =
    (+
     (l_815
      &&
      ((safe_sub_func_uint32_t_u_u ((!0x88EA4A2EL), 0xEFEB5ECAL)) && (safe_sub_func_int32_t_s_s (g_758, (+(p_35 != ((safe_mul_func_int16_t_s_s (l_815, (safe_add_func_uint16_t_u_u (((safe_mul_func_uint8_t_u_u ((safe_rshift_func_int16_t_s_u ((((safe_mod_func_int16_t_s_s ((((safe_unary_minus_func_uint32_t_u (0UL)) && (l_831 = ((-1L) != (p_36 | 4L)))) || 0x3411L), p_34)) <= 0xF0E1L) >= 1L), 6)), l_815)) ^ p_35), p_34)))) && l_831))))))));
  l_831
    =
    l_831;
  return
    p_34;
}
static uint16_t
func_39
  (int8_t
   p_40
)
{
  uint8_t
    l_211
    =
    255UL;
  int32_t
    l_219
    =
    (-7L);
  int32_t
    l_224
    =
    1L;
  int32_t
    l_226
    =
    (-1L);
  int16_t
    l_246
    =
    0x10F7L;
  uint16_t
    l_609
    =
    3UL;
  int16_t
    l_757
    =
    (-1L);
  int32_t
    l_769
    =
    0L;
  int32_t
    l_796
    =
    0xE01073E5L;
  int32_t
    l_806
    =
    0L;
  uint16_t
    l_814
    =
    65535UL;
  for
    (g_176
     =
     0;
     (g_176
      <
      12);
     g_176
     =
     safe_add_func_int32_t_s_s
     (g_176,
      3))
  {
    int32_t
      l_218
      =
      (-5L);
    int32_t
      l_220
      =
      0xFB97F931L;
    int32_t
      l_223
      =
      9L;
    const
      uint32_t
      l_225
      =
      0xE18E7CC0L;
    int32_t
      l_227
      =
      0xEB7A0ED4L;
    uint32_t
      l_371
      =
      0x0BFBFA90L;
    uint32_t
      l_692
      =
      0x93C4C162L;
    const
      int16_t
      l_759
      =
      0xA995L;
    l_227
      =
      (safe_add_func_uint16_t_u_u
       (((l_226 = (0L | (safe_rshift_func_int16_t_s_u ((safe_rshift_func_int8_t_s_u ((((l_224 = (safe_lshift_func_int16_t_s_u ((l_211 && (g_96 != ((safe_add_func_int8_t_s_s ((7L >= g_181), (((safe_add_func_uint16_t_u_u ((safe_mod_func_uint32_t_u_u ((((l_219 = (l_218 = l_211)) > ((l_220 = 0UL) & (safe_lshift_func_uint16_t_u_s (g_7, 0)))) < ((((l_223 = l_223) & g_94) >= l_211) != 0xF820L)), l_211)), 0xE52FL)) | l_211) & p_40))) >= g_21))), 9))) && g_94) <= l_225), p_40)), p_40)))) == l_211), 0x33C0L));
    g_21
      =
      ((safe_mod_func_uint32_t_u_u ((l_220 & ((0xB885A690L || ((g_129 && ((0UL && (safe_sub_func_uint8_t_u_u (((safe_sub_func_int8_t_s_s (((safe_mod_func_int32_t_s_s (p_40, 0x05C23366L)) | p_40), (l_246 = ((safe_rshift_func_uint8_t_u_u (((safe_rshift_func_int8_t_s_u ((safe_lshift_func_int16_t_s_u (0L, 9)), 1)) >= (l_226 = (g_245 = (g_244 = (safe_sub_func_int8_t_s_s ((0xB6L < g_176), 2L)))))), g_21)) > l_219)))) ^ l_224), 2L))) ^ 0x1BDDL)) | p_40)) ^ 1L)), 9L)) > g_101);
    if ((0x4F92L < (safe_lshift_func_int16_t_s_s ((((p_40 != (safe_lshift_func_uint16_t_u_u ((p_40 != (((safe_rshift_func_int8_t_s_s (g_244, 2)) | ((safe_add_func_int8_t_s_s (((((l_220 = (safe_mod_func_int8_t_s_s ((((safe_rshift_func_int16_t_s_u ((-2L), ((((((safe_mul_func_int8_t_s_s ((l_227 = ((safe_sub_func_uint16_t_u_u ((l_223 = (safe_rshift_func_int16_t_s_u (((((safe_rshift_func_int8_t_s_s ((((((g_96 != ((safe_mul_func_int16_t_s_s (p_40, ((l_226 = ((0xFDL | ((safe_add_func_int8_t_s_s (0xC0L, g_7)) && 0x1EL)) & (-1L))) || 0xF3F102FCL))) | g_96)) || l_223) || 6UL) > l_219) != l_227), 0)) > 0x68B3L) > 1L) || p_40), 7))), l_211)) == l_227)), g_181)) || p_40) & 1L) > 0UL) || p_40) != 7L))) == 0xC58CL) == p_40), p_40))) == (-3L)) != p_40) ^ p_40), g_96)) >= g_94)) <= (-10L))), l_218))) || 0x282EL) != l_218), 6))))
    {
      uint16_t
 l_271
 =
 65530UL;
      int32_t
 l_303
 =
 (-6L);
      uint16_t
 l_309
 =
 0x1B94L;
if ((0x4F92L < (safe_lshift_func_int16_t_s_s ((((p_40 != (safe_lshift_func_uint16_t_u_u ((p_40 != (((safe_rshift_func_int8_t_s_s (g_244, 2)) | ((safe_add_func_int8_t_s_s (((((l_220 = (safe_mod_func_int8_t_s_s ((((safe_rshift_func_int16_t_s_u ((-2L), ((((((safe_mul_func_int8_t_s_s ((l_227 = ((safe_sub_func_uint16_t_u_u ((l_223 = (safe_rshift_func_int16_t_s_u (((((safe_rshift_func_int8_t_s_s ((((((g_96 != ((safe_mul_func_int16_t_s_s (p_40, ((l_226 = ((0xFDL | ((safe_add_func_int8_t_s_s (0xC0L, g_7)) && 0x1EL)) & (-1L))) || 0xF3F102FCL))) | g_96)) || l_223) || 6UL) > l_219) != l_227), 0)) > 0x68B3L) > 1L) || p_40), 7))), l_211)) == l_227)), g_181)) || p_40) & 1L) > 0UL) || p_40) != 7L))) == 0xC58CL) == p_40), p_40))) == (-3L)) != p_40) ^ p_40), g_96)) >= g_94)) <= (-10L))), l_218))) || 0x282EL) != l_218), 6))))
    {
      uint16_t
 l_271
 =
 65530UL;
      int32_t
 l_303
 =
 (-6L);
      uint16_t
 l_309
 =
 0x1B94L;
      if (l_220)
 break;
      if (l_271)
 continue;
      l_220
 =
 (l_227
  =
  (g_304
   =
   ((l_226 = (safe_mod_func_int32_t_s_s ((safe_mul_func_int16_t_s_s (((g_276 = 5UL) | (((safe_mod_func_uint16_t_u_u (((safe_sub_func_int8_t_s_s (p_40, (l_223 = (safe_mod_func_int8_t_s_s ((((safe_lshift_func_int16_t_s_u ((safe_mod_func_int32_t_s_s ((safe_add_func_int16_t_s_s (g_129, (l_224 = (safe_add_func_int8_t_s_s ((((g_245 && (g_245 = (((safe_rshift_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u (((safe_lshift_func_int8_t_s_u (0x14L, 7)) < 0x7EL), (safe_rshift_func_int16_t_s_u ((0x22L > g_75), 14)))), 5)) >= ((((safe_mod_func_int8_t_s_s ((l_303 = (safe_sub_func_int8_t_s_s (g_129, 1UL))), 0xBBL)) & g_244) | p_40) < p_40)) <= p_40))) | l_219) ^ 1L), p_40))))), l_271)), 8)) ^ l_271) == g_101), g_75))))) && 0x32686C91L), g_181)) > l_211) == 1UL)), 0x68DEL)), l_271))) ^ p_40)));
      l_303
 =
 (safe_mul_func_int16_t_s_s
  ((+(l_309 <= ((l_226 = ((safe_lshift_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u (p_40, ((((safe_sub_func_int32_t_s_s (((safe_unary_minus_func_int16_t_s ((g_276 == ((l_227 = p_40) && (l_224 = g_244))))) >= (safe_mod_func_uint32_t_u_u (l_211, (g_21 = 8L)))), p_40)) & g_129) && p_40) & 0UL))), 0)) || p_40)) >= g_96))), p_40));
    }
    else
    {
      int8_t
 l_319
 =
 0xE3L;
      const
 uint16_t
 l_334
 =
 65535UL;
      int32_t
 l_372
 =
 0L;
      int32_t
 l_408
 =
 0xCAB86EAAL;
      int8_t
 l_570
 =
 0xD9L;
      int32_t
 l_571
 =
 0xD60B8108L;
      uint32_t
 l_691
 =
 1UL;
      uint32_t
 l_737
 =
 0UL;
      uint32_t
 l_750
 =
 8UL;
      if ((p_40 <= ((!(l_227 = (!l_319))) || (safe_lshift_func_int8_t_s_s ((((+(safe_add_func_int8_t_s_s ((l_219 = (-1L)), (l_220 = (g_101 != (safe_sub_func_uint16_t_u_u (0x2827L, (safe_add_func_uint8_t_u_u ((g_75 == ((safe_sub_func_int16_t_s_s (((g_304 > (l_319 ^ (safe_rshift_func_uint8_t_u_u ((safe_rshift_func_int16_t_s_s ((p_40 >= g_304), g_244)), g_276)))) && p_40), p_40)) > l_218)), l_334))))))))) ^ (-4L)) >= 1L), p_40)))))
      {
 uint8_t
   l_337
   =
   1UL;
 int32_t
   l_406
   =
   (-1L);
 int32_t
   l_407
   =
   0xA6ED00A5L;
 uint32_t
   l_464
   =
   0xC71FC3AEL;
 int16_t
   l_490
   =
   0x758BL;
 const
   uint8_t
   l_556
   =
   8UL;
 if (g_245)
   break;
 g_21
   =
   l_225;
 if (((safe_rshift_func_int8_t_s_s (l_337, 7)) | (safe_sub_func_int32_t_s_s ((safe_lshift_func_uint16_t_u_s (0xC8F5L, 9)), 0x9B8D13D5L))))
 {
   int32_t
     l_344
     =
     0L;
   int32_t
     l_345
     =
     7L;
   for
     (l_319
      =
      0;
      (l_319
       <=
       4);
      l_319++)
   {
     g_21
       =
       (g_75
        >
        l_344);
   }
   l_345
     =
     l_218;
   l_372
     =
     ((safe_add_func_uint32_t_u_u ((safe_lshift_func_int8_t_s_u ((safe_mod_func_uint8_t_u_u (((safe_sub_func_uint8_t_u_u ((safe_sub_func_int8_t_s_s ((safe_lshift_func_int8_t_s_u (p_40, 0)), (g_276 = ((l_371 = (safe_rshift_func_uint16_t_u_u ((g_370 = (safe_add_func_uint8_t_u_u (254UL, (safe_mul_func_uint8_t_u_u (((((safe_add_func_uint32_t_u_u ((safe_lshift_func_int8_t_s_s (g_176, (p_40 < (g_181 > ((((!l_319) > (l_226 = (((((p_40 || (-1L)) && (1L || p_40)) > 6L) || l_218) != g_101))) > g_7) == (-9L)))))), g_181)) | l_345) & g_276) ^ (-1L)), g_176))))), 0))) >= 1UL)))), 1UL)) && 3L), l_344)), g_181)), 0xC7B7FF88L)) & p_40);
 }
 else
 {
   uint32_t
     l_403
     =
     4294967286UL;
   int32_t
     l_456
     =
     0x85F900EBL;
   uint8_t
     l_463
     =
     0x0EL;
   int32_t
     l_489
     =
     0x6596DC5AL;
   uint32_t
     l_493
     =
     0x168999CCL;
   uint16_t
     l_504
     =
     0x9ECCL;
   for
     (l_223
      =
      9;
      (l_223
       >
       15);
      ++l_223)
   {
     uint32_t
       l_377
       =
       0x75E894C7L;
     int32_t
       l_380
       =
       1L;
     l_224
       =
       (safe_sub_func_int8_t_s_s
        ((5L | g_21), (l_377 = l_319)));
     l_380
       =
       (safe_add_func_uint16_t_u_u
        (g_101,
  (-5L)));
     l_408
       =
       ((safe_rshift_func_int8_t_s_s ((g_101 > (((+((safe_sub_func_int32_t_s_s ((safe_mod_func_int8_t_s_s ((g_387 != (safe_rshift_func_uint16_t_u_u (((safe_sub_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_u ((safe_mod_func_int16_t_s_s ((-2L), (safe_add_func_uint32_t_u_u ((((p_40 && (l_407 = (~((l_319 | g_370) >= (safe_mul_func_uint8_t_u_u (((safe_unary_minus_func_int16_t_s ((l_406 = (((safe_sub_func_uint8_t_u_u ((g_276 = 255UL), (((l_403 = g_75) >= (l_372 = (safe_mod_func_int16_t_s_s (0x5BA9L, g_96)))) > p_40))) >= p_40) ^ (-1L))))) != g_244), (-1L))))))) || l_403) & l_371), g_244)))), l_246)), p_40)) <= 0L), 0))), p_40)), 6UL)) | g_94)) >= 0x41F8L) || p_40)), 1)) >= 8L);
     l_224
       =
       (((safe_rshift_func_uint8_t_u_s ((safe_add_func_uint8_t_u_u (p_40, (((safe_mul_func_int16_t_s_s (p_40, ((0x50L && (safe_mul_func_int8_t_s_s ((safe_rshift_func_uint8_t_u_u (g_370, (g_276 = (safe_rshift_func_uint16_t_u_u ((g_94 = ((((safe_mod_func_uint32_t_u_u (((g_21 = ((4294967288UL >= (safe_sub_func_int16_t_s_s (((safe_unary_minus_func_int16_t_s ((safe_sub_func_uint16_t_u_u (g_244, (safe_mod_func_int8_t_s_s ((safe_mul_func_int16_t_s_s ((((safe_sub_func_int8_t_s_s (((l_227 = (safe_sub_func_int16_t_s_s ((l_219 = ((safe_sub_func_uint16_t_u_u (65535UL, (safe_rshift_func_uint8_t_u_u ((safe_mul_func_uint8_t_u_u ((65528UL || (((!(((((safe_add_func_uint8_t_u_u ((l_403 > 0x71L), g_370)) == 3L) >= l_227) && 0xD7A1L) ^ g_244)) <= p_40) == g_304)), g_21)), 4)))) & g_75)), 0x5C18L))) & p_40), l_403)) > p_40) || 0x0DDBL), g_176)), 0x39L)))))) | 0UL), g_244))) || g_75)) && p_40), 0x6C258254L)) && l_407) == 0x80996939L) | g_276)), 5))))), 0x1CL))) < l_246))) && g_387) & g_370))), l_403)) || 0UL) == 0UL);
   }
   for
     (l_406
      =
      0;
      (l_406
       >
       (-22));
      --l_406)
   {
     l_220
       =
       (safe_add_func_uint32_t_u_u
        ((65529UL | (l_224 = (safe_mul_func_int8_t_s_s ((((0x6B9A1A24L || (safe_lshift_func_int16_t_s_u (l_403, 7))) || 4294967287UL) | (safe_mod_func_int32_t_s_s ((safe_mod_func_uint8_t_u_u ((l_456 = (g_387 = (l_408 == g_181))), (safe_rshift_func_uint8_t_u_s ((g_276 = ((0x5E7A8B45L && l_408) > (((((safe_add_func_uint8_t_u_u ((safe_mul_func_int8_t_s_s (g_245, p_40)), l_463)) == 0x8FE4L) & l_464) ^ 0xEAL) && g_304))), p_40)))), g_244))), g_244)))), 0xFA39C599L));
     if (p_40)
       break;
   }
   l_490
     =
     ((((safe_add_func_uint8_t_u_u (g_370, 249UL)) < g_96) > l_463) < (l_489 = (safe_lshift_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_u (((l_407 = (l_246 == (l_227 = ((l_337 == ((safe_sub_func_int8_t_s_s ((safe_lshift_func_int16_t_s_s ((((g_21 = (safe_lshift_func_uint16_t_u_s ((g_94 = (safe_mod_func_int16_t_s_s ((safe_mul_func_int16_t_s_s ((safe_lshift_func_uint8_t_u_u ((((l_456 = ((((l_219 = (safe_sub_func_int8_t_s_s (l_456, (safe_sub_func_uint8_t_u_u (0x92L, (safe_add_func_int16_t_s_s ((l_223 = ((1UL & 0x1FD5L) || g_176)), p_40))))))) < p_40) == 0x81B0L) == l_319)) == g_7) <= 4294967290UL), g_245)), l_407)), g_21))), 8))) >= p_40) != l_372), l_218)), p_40)) | (-10L))) <= 0x08B89549L)))) && p_40), 1)) >= l_334), 7))));
   for
     (l_403
      =
      9;
      (l_403
       !=
       32);
      l_403++)
   {
     uint32_t
       l_494
       =
       0xE0D74FEBL;
     l_493
       =
       g_387;
     l_489
       =
       (l_494
        =
        p_40);
     g_21
       =
       (safe_add_func_int32_t_s_s
        ((!g_244), ((((g_387 = ((safe_unary_minus_func_int16_t_s ((g_176 || ((l_494 | g_101) && (l_246 & (safe_mul_func_int16_t_s_s ((safe_add_func_int16_t_s_s ((l_489 = (safe_mod_func_uint8_t_u_u (l_464, l_504))), ((((p_40 == g_387) && 1UL) ^ p_40) > 246UL))), p_40))))))) > p_40)) >= p_40) | 0UL) || 0xCB4754EAL)));
     g_21
       =
       p_40;
   }
 }
 if ((safe_sub_func_uint16_t_u_u ((l_406 = (((safe_sub_func_int16_t_s_s ((((+((safe_lshift_func_int16_t_s_s ((-9L), g_94)) >= (l_218 > (safe_mod_func_uint16_t_u_u (((l_226 = (5L < (safe_rshift_func_uint8_t_u_u ((((((g_7 = g_245) != (((7UL >= ((g_96 > p_40) == (l_372 && p_40))) < p_40) == g_370)) & 0xCBEBB16FL) > g_370) < 0x10A4L), g_245)))) & l_464), p_40))))) | l_372) || 0x425D473EL), 0L)) > 3UL) & 0x2FB1L)), 0xC419L)))
 {
   uint16_t
     l_537
     =
     0x783CL;
   int32_t
     l_540
     =
     (-1L);
   int32_t
     l_557
     =
     0x5B5812A0L;
   if (g_75)
   {
     int16_t
       l_541
       =
       0xC5F7L;
     l_224
       =
       (safe_mul_func_int16_t_s_s
        ((safe_rshift_func_uint8_t_u_u ((safe_add_func_int8_t_s_s (((l_557 = (safe_add_func_int16_t_s_s (((safe_lshift_func_uint8_t_u_u (p_40, 0)) ^ (l_407 = (safe_rshift_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_s ((p_40 & ((1L && ((safe_add_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u ((safe_rshift_func_int16_t_s_u (((safe_sub_func_int32_t_s_s (((l_537 != (safe_add_func_uint32_t_u_u ((l_541 = (l_540 = l_224)), (safe_lshift_func_int16_t_s_s (p_40, 10))))) && (safe_lshift_func_int16_t_s_s (((safe_sub_func_uint32_t_u_u ((g_304 >= (safe_rshift_func_int8_t_s_s ((safe_add_func_uint8_t_u_u ((l_226 = (l_406 = l_319)), ((l_219 = (+((safe_add_func_uint32_t_u_u ((((safe_rshift_func_int8_t_s_u (1L, g_276)) | l_556) < (-1L)), 0x652A5139L)) == g_96))) & 0x5244L))), 4))), l_372)) != 0xFE5AL), g_94))), 0xA2226192L)) & p_40), 15)), 5)), 0xFAB9L)) && l_371)) != 0xC001L)), g_244)), 7)))), 0x1FFEL))) != 1UL), l_537)), 5)), l_337));
   }
   else
   {
     l_220
       =
       (safe_mul_func_uint8_t_u_u
        (p_40,
  (p_40
   |
   g_244)));
     if (g_96)
       break;
     l_540
       =
       0x8A84BF4CL;
     if (l_227)
       break;
   }
   if (p_40)
     break;
   for
     (g_245
      =
      (-26);
      (g_245
       <
       (-30));
      g_245--)
   {
     if (p_40)
       break;
     l_224
       =
       (+
        ((safe_mul_func_int8_t_s_s (0xEFL, 0UL)) >= (safe_lshift_func_uint8_t_u_u (((l_571 = ((safe_add_func_uint32_t_u_u ((safe_sub_func_int8_t_s_s (l_540, (p_40 <= (0x1C78L & (0xE739L || (l_570 = 0xFA64L)))))), (l_372 = ((l_408 = (l_218 | ((-1L) != 0UL))) == l_537)))) < 0xA5L)) || p_40), l_246))));
   }
   l_408
     =
     (safe_lshift_func_int16_t_s_s
      (5L,
       ((+((((0xC2L | 0x19L) == l_537) >= p_40) & g_176)) != ((l_406 = (safe_lshift_func_uint16_t_u_s ((((g_129 ^ (safe_mod_func_uint8_t_u_u ((p_40 < (safe_rshift_func_uint8_t_u_s (((p_40 < 247UL) <= l_218), l_319))), 0x50L))) || g_387) > p_40), l_537))) || 0L))));
 }
 else
 {
   int16_t
     l_584
     =
     0xFCADL;
   int8_t
     l_587
     =
     0L;
   int32_t
     l_628
     =
     0x99FC9820L;
   if ((((l_220 == (l_227 = (safe_mul_func_int16_t_s_s (l_227, ((((safe_mul_func_uint8_t_u_u (p_40, (g_75 | (g_129 ^ ((!g_245) <= p_40))))) || l_584) < ((safe_rshift_func_uint8_t_u_s (g_129, l_587)) > (-7L))) <= 0x3D2D6B36L))))) >= l_371) <= p_40))
   {
     g_21
       =
       g_387;
     l_227
       =
       p_40;
     if (g_276)
       continue;
     l_571
       =
       ((~(safe_lshift_func_int16_t_s_u ((safe_mod_func_int32_t_s_s ((safe_mul_func_int16_t_s_s ((((l_372 = (safe_mul_func_uint16_t_u_u (0x949BL, (l_587 & (((l_406 = (safe_mod_func_int32_t_s_s (g_75, 0x152DB58FL))) <= (((g_96 && (0xE9C8L <= g_176)) || (safe_mul_func_uint8_t_u_u ((safe_unary_minus_func_uint32_t_u ((!4294967295UL))), ((safe_lshift_func_int16_t_s_s ((safe_mul_func_uint8_t_u_u ((!0xC8L), p_40)), 2)) ^ 0x53F7L)))) | l_211)) && 1L))))) && 0L) & l_219), l_556)), g_96)), 5))) & 0x99686D7CL);
   }
   else
   {
     l_609
       =
       ((g_245 = g_101) ^ ((+l_220) >= (l_334 | p_40)));
     return
       l_408;
   }
   if (g_101)
     continue;
   l_224
     =
     (l_628
      =
      (l_371
       ==
       (safe_mul_func_int16_t_s_s
        ((((-1L) == (l_220 = p_40)) & p_40), ((safe_unary_minus_func_uint8_t_u ((l_571 == (safe_add_func_int16_t_s_s (((safe_lshift_func_uint16_t_u_s ((safe_add_func_uint16_t_u_u (0UL, 9L)), (((safe_mod_func_int32_t_s_s (((safe_unary_minus_func_int32_t_s ((((safe_sub_func_uint32_t_u_u ((p_40 >= (((safe_add_func_uint16_t_u_u ((l_223 = ((((((safe_lshift_func_int8_t_s_u ((l_227 = l_334), l_556)) == 0L) | g_176) || p_40) & l_319) & (-1L))), p_40)) > (-1L)) == 0xB9L)), p_40)) || 0x5559F4D5L) ^ 0x3913D021L))) <= l_464), 8UL)) >= 1L) ^ g_94))) <= p_40), p_40))))) > (-8L))))));
 }
      }
      else
      {
 uint32_t
   l_633
   =
   4294967295UL;
 int16_t
   l_654
   =
   7L;
 int32_t
   l_657
   =
   6L;
 int32_t
   l_666
   =
   0x17F9480FL;
 int32_t
   l_712
   =
   (-10L);
 if (p_40)
   break;
 if (((p_40 = (+(safe_mul_func_int16_t_s_s (g_94, (5L <= (l_633 >= (safe_mul_func_uint16_t_u_u ((safe_mul_func_int8_t_s_s ((safe_sub_func_int16_t_s_s (0L, (safe_lshift_func_int8_t_s_u ((safe_sub_func_uint16_t_u_u ((safe_mod_func_uint32_t_u_u ((safe_mod_func_int16_t_s_s ((((safe_rshift_func_uint16_t_u_u (((((((safe_mod_func_uint8_t_u_u (g_304, p_40)) ^ ((l_372 = ((((safe_mod_func_uint32_t_u_u (4294967287UL, l_319)) != (l_319 < l_225)) || p_40) && 4UL)) <= g_245)) >= p_40) | g_101) & g_101) != g_304), 14)) ^ 0xDADCEC21L) != l_218), g_387)), 0x5D77AFF9L)), 0xE2E0L)), 5)))), l_654)), l_223)))))))) || l_654))
 {
   uint16_t
     l_667
     =
     0x76DCL;
   g_21
     =
     (safe_sub_func_int8_t_s_s
      ((l_219 = ((l_657 = (+((g_21 < p_40) > (g_7 = p_40)))) || 5UL)), (safe_add_func_uint32_t_u_u ((safe_sub_func_uint8_t_u_u (p_40, ((((p_40 < (safe_add_func_uint8_t_u_u (0xAFL, 0x54L))) & (l_666 = (((l_226 = (safe_sub_func_uint16_t_u_u ((l_408 = l_372), p_40))) >= 0x10F9L) != p_40))) == 0xD98AL) & p_40))), l_667))));
 }
 else
 {
   uint16_t
     l_705
     =
     0x84BBL;
   for
     (l_609
      =
      16;
      (l_609
       !=
       36);
      l_609
      =
      safe_add_func_int32_t_s_s
      (l_609,
       7))
   {
     uint8_t
       l_690
       =
       250UL;
     g_21
       =
       (l_226
        =
        (((((safe_rshift_func_int8_t_s_u ((safe_add_func_uint8_t_u_u ((safe_lshift_func_uint16_t_u_s (((safe_rshift_func_uint16_t_u_u (((safe_sub_func_int16_t_s_s ((1UL != (((((p_40 = (p_40 >= (safe_add_func_uint16_t_u_u (l_372, g_129)))) == (l_224 = (safe_lshift_func_uint16_t_u_s (0UL, 3)))) < (safe_mul_func_int8_t_s_s ((((g_245 = (safe_mul_func_int8_t_s_s (((l_690 && (((l_654 || l_408) || g_75) < g_245)) | 0xE336L), g_21))) < 0UL) ^ l_690), 1L))) & 0x5CD401BCL) <= 0x3CF5L)), 0x97B5L)) >= 0x55BD7198L), l_690)) >= l_211), 4)), 0x72L)), l_219)) & 0x11L) ^ 0xA21118B3L) != l_691) < g_21));
   }
   g_21
     =
     ((l_692 = 1L) & p_40);
   if (g_176)
     continue;
   l_372
     =
     (safe_sub_func_uint16_t_u_u
      (((l_226 = (safe_sub_func_uint8_t_u_u ((safe_mod_func_int8_t_s_s (p_40, (l_712 = (g_7 = ((safe_mod_func_int16_t_s_s (((safe_sub_func_uint8_t_u_u (((l_666 = g_176) | ((safe_mod_func_uint32_t_u_u (((-1L) < (p_40 < ((l_705 ^ (safe_mul_func_uint16_t_u_u ((g_276 < l_657), (safe_rshift_func_uint8_t_u_u ((p_40 <= (safe_mod_func_uint32_t_u_u (l_571, l_570))), 7))))) >= 65528UL))), p_40)) <= 0L)), g_276)) > l_371), p_40)) ^ g_75))))), 0xADL))) != g_94), p_40));
 }
 g_21
   =
   g_7;
      }
      if ((l_218 || l_691))
      {
 uint32_t
   l_713
   =
   0x4B1B1B57L;
 int32_t
   l_714
   =
   0xC05B540AL;
 l_714
   =
   (l_713
    =
    0x7FB13204L);
      }
      else
      {
 uint32_t
   l_715
   =
   0UL;
 int32_t
   l_724
   =
   (-7L);
 l_571
   =
   l_715;
 if (g_245)
 {
   uint32_t
     l_736
     =
     0x100C9E40L;
   for
     (g_245
      =
      0;
      (g_245
       <=
       (-18));
      g_245
      =
      safe_sub_func_uint32_t_u_u
      (g_245,
       4))
   {
     int32_t
       l_735
       =
       0x4456E1EDL;
     l_220
       =
       ((((safe_add_func_uint32_t_u_u ((safe_sub_func_uint8_t_u_u (p_40, 0xF1L)), (3UL <= 0L))) != (((safe_lshift_func_uint8_t_u_u (((l_724 = l_408) >= (safe_sub_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (((safe_sub_func_int16_t_s_s (l_223, (g_94 = ((((safe_lshift_func_uint16_t_u_s ((((l_372 ^ l_692) != (((!(safe_sub_func_uint32_t_u_u ((g_129 = l_735), p_40))) || 0x2E2FL) == l_319)) || 0xD853L), p_40)) ^ l_736) <= 0x11822A2BL) && g_370)))) > l_223), 8UL)), 0x08F4L))), g_387)) != g_96) < 0x88L)) ^ 0x4023C49BL) <= p_40);
     if (p_40)
       continue;
     return
       p_40;
   }
   if (g_176)
     break;
 }
 else
 {
   if (l_737)
     break;
 }
      }
      if ((safe_rshift_func_uint8_t_u_u ((safe_mul_func_uint16_t_u_u ((g_758 = (safe_add_func_int8_t_s_s (((l_220 = (safe_mod_func_uint16_t_u_u ((safe_rshift_func_int8_t_s_u (((0L < l_570) && l_223), (0UL == (safe_add_func_int8_t_s_s ((((l_750 = g_129) & (((((p_40 >= ((((safe_sub_func_uint16_t_u_u ((g_94 = (safe_mul_func_uint8_t_u_u ((l_219 = (~((p_40 < ((safe_mul_func_int8_t_s_s ((~(g_181 = g_244)), p_40)) || (-1L))) | p_40))), (-1L)))), l_757)) & l_691) > 0xDFL) == (-10L))) < 3L) == 0L) < 1L) == p_40)) > 4294967295UL), 0xA4L))))), 0x8C43L))) || 249UL), l_372))), 7UL)), 7)))
      {
 g_21
   =
   l_759;
      }
      else
      {
 int8_t
   l_766
   =
   0xDFL;
 l_408
   =
   (safe_mul_func_uint8_t_u_u
    ((l_224 = l_371), (((0x8A9FB8DBL != l_609) != g_7) == (-7L))));
 g_21
   =
   (((safe_mod_func_int32_t_s_s ((l_227 = (-1L)), (safe_add_func_uint32_t_u_u (l_219, (l_766 & (((l_759 >= g_387) ^ (safe_mul_func_int8_t_s_s (((l_224 = (0x9F25L <= p_40)) != (((!(l_769 = ((((l_226 = 0xF7312319L) < ((-4L) != 0x12L)) & l_691) ^ 0UL))) & 2UL) ^ 0xC0L)), g_21))) <= 255UL)))))) & l_750) > 0x96F8255EL);
      }
      if (g_101)
 continue;
    }
      if (l_271)
 ;
g_21
      =
      ((safe_mod_func_uint32_t_u_u ((l_220 & ((0xB885A690L || ((g_129 && ((0UL && (safe_sub_func_uint8_t_u_u (((safe_sub_func_int8_t_s_s (((safe_mod_func_int32_t_s_s (p_40, 0x05C23366L)) | p_40), (l_246 = ((safe_rshift_func_uint8_t_u_u (((safe_rshift_func_int8_t_s_u ((safe_lshift_func_int16_t_s_u (0L, 9)), 1)) >= (l_226 = (g_245 = (g_244 = (safe_sub_func_int8_t_s_s ((0xB6L < g_176), 2L)))))), g_21)) > l_219)))) ^ l_224), 2L))) ^ 0x1BDDL)) | p_40)) ^ 1L)), 9L)) > g_101);
      l_220
 =
 (l_227
  =
  (g_304
   =
   ((l_226 = (safe_mod_func_int32_t_s_s ((safe_mul_func_int16_t_s_s (((g_276 = 5UL) | (((safe_mod_func_uint16_t_u_u (((safe_sub_func_int8_t_s_s (p_40, (l_223 = (safe_mod_func_int8_t_s_s ((((safe_lshift_func_int16_t_s_u ((safe_mod_func_int32_t_s_s ((safe_add_func_int16_t_s_s (g_129, (l_224 = (safe_add_func_int8_t_s_s ((((g_245 && (g_245 = (((safe_rshift_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u (((safe_lshift_func_int8_t_s_u (0x14L, 7)) < 0x7EL), (safe_rshift_func_int16_t_s_u ((0x22L > g_75), 14)))), 5)) >= ((((safe_mod_func_int8_t_s_s ((l_303 = (safe_sub_func_int8_t_s_s (g_129, 1UL))), 0xBBL)) & g_244) | p_40) < p_40)) <= p_40))) | l_219) ^ 1L), p_40))))), l_271)), 8)) ^ l_271) == g_101), g_75))))) && 0x32686C91L), g_181)) > l_211) == 1UL)), 0x68DEL)), l_271))) ^ p_40)));
      l_303
 =
 (safe_mul_func_int16_t_s_s
  ((+(l_309 <= ((l_226 = ((safe_lshift_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u (p_40, ((((safe_sub_func_int32_t_s_s (((safe_unary_minus_func_int16_t_s ((g_276 == ((l_227 = p_40) && (l_224 = g_244))))) >= (safe_mod_func_uint32_t_u_u (l_211, (g_21 = 8L)))), p_40)) & g_129) && p_40) & 0UL))), 0)) || p_40)) >= g_96))), p_40));
    }
    else
    {
      int8_t
 l_319
 =
 0xE3L;
      const
 uint16_t
 l_334
 =
 65535UL;
      int32_t
 l_372
 =
 0L;
      int32_t
 l_408
 =
 0xCAB86EAAL;
      int8_t
 l_570
 =
 0xD9L;
      int32_t
 l_571
 =
 0xD60B8108L;
      uint32_t
 l_691
 =
 1UL;
      uint32_t
 l_737
 =
 0UL;
      uint32_t
 l_750
 =
 8UL;
      if ((p_40 <= ((!(l_227 = (!l_319))) || (safe_lshift_func_int8_t_s_s ((((+(safe_add_func_int8_t_s_s ((l_219 = (-1L)), (l_220 = (g_101 != (safe_sub_func_uint16_t_u_u (0x2827L, (safe_add_func_uint8_t_u_u ((g_75 == ((safe_sub_func_int16_t_s_s (((g_304 > (l_319 ^ (safe_rshift_func_uint8_t_u_u ((safe_rshift_func_int16_t_s_s ((p_40 >= g_304), g_244)), g_276)))) && p_40), p_40)) > l_218)), l_334))))))))) ^ (-4L)) >= 1L), p_40)))))
      {
 uint8_t
   l_337
   =
   1UL;
 int32_t
   l_406
   =
   (-1L);
 int32_t
   l_407
   =
   0xA6ED00A5L;
 uint32_t
   l_464
   =
   0xC71FC3AEL;
 int16_t
   l_490
   =
   0x758BL;
 const
   uint8_t
   l_556
   =
   8UL;
 if (g_245)
   break;
 g_21
   =
   l_225;
g_21
      =
      ((safe_mod_func_uint32_t_u_u ((l_220 & ((0xB885A690L || ((g_129 && ((0UL && (safe_sub_func_uint8_t_u_u (((safe_sub_func_int8_t_s_s (((safe_mod_func_int32_t_s_s (p_40, 0x05C23366L)) | p_40), (l_246 = ((safe_rshift_func_uint8_t_u_u (((safe_rshift_func_int8_t_s_u ((safe_lshift_func_int16_t_s_u (0L, 9)), 1)) >= (l_226 = (g_245 = (g_244 = (safe_sub_func_int8_t_s_s ((0xB6L < g_176), 2L)))))), g_21)) > l_219)))) ^ l_224), 2L))) ^ 0x1BDDL)) | p_40)) ^ 1L)), 9L)) > g_101);
g_21
   =
   l_225;
      }
      else
      {
 uint32_t
   l_633
   =
   4294967295UL;
 int16_t
   l_654
   =
   7L;
 int32_t
   l_657
   =
   6L;
 int32_t
   l_666
   =
   0x17F9480FL;
 int32_t
   l_712
   =
   (-10L);
 if (p_40)
{{
      uint16_t
 l_271
 =
 65530UL;
      int32_t
 l_303
 =
 (-6L);
      uint16_t
 l_309
 =
 0x1B94L;
      if (l_220)
 break;
      if (l_271)
 continue;
      l_220
 =
 (l_227
  =
  (g_304
   =
   ((l_226 = (safe_mod_func_int32_t_s_s ((safe_mul_func_int16_t_s_s (((g_276 = 5UL) | (((safe_mod_func_uint16_t_u_u (((safe_sub_func_int8_t_s_s (p_40, (l_223 = (safe_mod_func_int8_t_s_s ((((safe_lshift_func_int16_t_s_u ((safe_mod_func_int32_t_s_s ((safe_add_func_int16_t_s_s (g_129, (l_224 = (safe_add_func_int8_t_s_s ((((g_245 && (g_245 = (((safe_rshift_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u (((safe_lshift_func_int8_t_s_u (0x14L, 7)) < 0x7EL), (safe_rshift_func_int16_t_s_u ((0x22L > g_75), 14)))), 5)) >= ((((safe_mod_func_int8_t_s_s ((l_303 = (safe_sub_func_int8_t_s_s (g_129, 1UL))), 0xBBL)) & g_244) | p_40) < p_40)) <= p_40))) | l_219) ^ 1L), p_40))))), l_271)), 8)) ^ l_271) == g_101), g_75))))) && 0x32686C91L), g_181)) > l_211) == 1UL)), 0x68DEL)), l_271))) ^ p_40)));
      l_303
 =
 (safe_mul_func_int16_t_s_s
  ((+(l_309 <= ((l_226 = ((safe_lshift_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u (p_40, ((((safe_sub_func_int32_t_s_s (((safe_unary_minus_func_int16_t_s ((g_276 == ((l_227 = p_40) && (l_224 = g_244))))) >= (safe_mod_func_uint32_t_u_u (l_211, (g_21 = 8L)))), p_40)) & g_129) && p_40) & 0UL))), 0)) || p_40)) >= g_96))), p_40));
    }
}
 if (((p_40 = (+(safe_mul_func_int16_t_s_s (g_94, (5L <= (l_633 >= (safe_mul_func_uint16_t_u_u ((safe_mul_func_int8_t_s_s ((safe_sub_func_int16_t_s_s (0L, (safe_lshift_func_int8_t_s_u ((safe_sub_func_uint16_t_u_u ((safe_mod_func_uint32_t_u_u ((safe_mod_func_int16_t_s_s ((((safe_rshift_func_uint16_t_u_u (((((((safe_mod_func_uint8_t_u_u (g_304, p_40)) ^ ((l_372 = ((((safe_mod_func_uint32_t_u_u (4294967287UL, l_319)) != (l_319 < l_225)) || p_40) && 4UL)) <= g_245)) >= p_40) | g_101) & g_101) != g_304), 14)) ^ 0xDADCEC21L) != l_218), g_387)), 0x5D77AFF9L)), 0xE2E0L)), 5)))), l_654)), l_223)))))))) || l_654))
 {
   uint16_t
     l_667
     =
     0x76DCL;
   g_21
     =
     (safe_sub_func_int8_t_s_s
      ((l_219 = ((l_657 = (+((g_21 < p_40) > (g_7 = p_40)))) || 5UL)), (safe_add_func_uint32_t_u_u ((safe_sub_func_uint8_t_u_u (p_40, ((((p_40 < (safe_add_func_uint8_t_u_u (0xAFL, 0x54L))) & (l_666 = (((l_226 = (safe_sub_func_uint16_t_u_u ((l_408 = l_372), p_40))) >= 0x10F9L) != p_40))) == 0xD98AL) & p_40))), l_667))));
l_227
      =
      (safe_add_func_uint16_t_u_u
       (((l_226 = (0L | (safe_rshift_func_int16_t_s_u ((safe_rshift_func_int8_t_s_u ((((l_224 = (safe_lshift_func_int16_t_s_u ((l_211 && (g_96 != ((safe_add_func_int8_t_s_s ((7L >= g_181), (((safe_add_func_uint16_t_u_u ((safe_mod_func_uint32_t_u_u ((((l_219 = (l_218 = l_211)) > ((l_220 = 0UL) & (safe_lshift_func_uint16_t_u_s (g_7, 0)))) < ((((l_223 = l_223) & g_94) >= l_211) != 0xF820L)), l_211)), 0xE52FL)) | l_211) & p_40))) >= g_21))), 9))) && g_94) <= l_225), p_40)), p_40)))) == l_211), 0x33C0L));
 }
 else
 {
   uint16_t
     l_705
     =
     0x84BBL;
   for
     (l_609
      =
      16;
      (l_609
       !=
       36);
      l_609
      =
      safe_add_func_int32_t_s_s
      (l_609,
       7))
   {
     uint8_t
       l_690
       =
       250UL;
if ((p_40 <= ((!(l_227 = (!l_319))) || (safe_lshift_func_int8_t_s_s ((((+(safe_add_func_int8_t_s_s ((l_219 = (-1L)), (l_220 = (g_101 != (safe_sub_func_uint16_t_u_u (0x2827L, (safe_add_func_uint8_t_u_u ((g_75 == ((safe_sub_func_int16_t_s_s (((g_304 > (l_319 ^ (safe_rshift_func_uint8_t_u_u ((safe_rshift_func_int16_t_s_s ((p_40 >= g_304), g_244)), g_276)))) && p_40), p_40)) > l_218)), l_334))))))))) ^ (-4L)) >= 1L), p_40)))))
      {
 uint8_t
   l_337
   =
   1UL;
 int32_t
   l_406
   =
   (-1L);
 int32_t
   l_407
   =
   0xA6ED00A5L;
 uint32_t
   l_464
   =
   0xC71FC3AEL;
 int16_t
   l_490
   =
   0x758BL;
 const
   uint8_t
   l_556
   =
   8UL;
 if (g_245)
   break;
 g_21
   =
   l_225;
 if (((safe_rshift_func_int8_t_s_s (l_337, 7)) | (safe_sub_func_int32_t_s_s ((safe_lshift_func_uint16_t_u_s (0xC8F5L, 9)), 0x9B8D13D5L))))
 {
   int32_t
     l_344
     =
     0L;
   int32_t
     l_345
     =
     7L;
   for
     (l_319
      =
      0;
      (l_319
       <=
       4);
      l_319++)
   {
     g_21
       =
       (g_75
        >
        l_344);
   }
   l_345
     =
     l_218;
   l_372
     =
     ((safe_add_func_uint32_t_u_u ((safe_lshift_func_int8_t_s_u ((safe_mod_func_uint8_t_u_u (((safe_sub_func_uint8_t_u_u ((safe_sub_func_int8_t_s_s ((safe_lshift_func_int8_t_s_u (p_40, 0)), (g_276 = ((l_371 = (safe_rshift_func_uint16_t_u_u ((g_370 = (safe_add_func_uint8_t_u_u (254UL, (safe_mul_func_uint8_t_u_u (((((safe_add_func_uint32_t_u_u ((safe_lshift_func_int8_t_s_s (g_176, (p_40 < (g_181 > ((((!l_319) > (l_226 = (((((p_40 || (-1L)) && (1L || p_40)) > 6L) || l_218) != g_101))) > g_7) == (-9L)))))), g_181)) | l_345) & g_276) ^ (-1L)), g_176))))), 0))) >= 1UL)))), 1UL)) && 3L), l_344)), g_181)), 0xC7B7FF88L)) & p_40);
 }
 else
 {
   uint32_t
     l_403
     =
     4294967286UL;
   int32_t
     l_456
     =
     0x85F900EBL;
   uint8_t
     l_463
     =
     0x0EL;
   int32_t
     l_489
     =
     0x6596DC5AL;
   uint32_t
     l_493
     =
     0x168999CCL;
   uint16_t
     l_504
     =
     0x9ECCL;
   for
     (l_223
      =
      9;
      (l_223
       >
       15);
      ++l_223)
   {
     uint32_t
       l_377
       =
       0x75E894C7L;
     int32_t
       l_380
       =
       1L;
     l_224
       =
       (safe_sub_func_int8_t_s_s
        ((5L | g_21), (l_377 = l_319)));
     l_380
       =
       (safe_add_func_uint16_t_u_u
        (g_101,
  (-5L)));
     l_408
       =
       ((safe_rshift_func_int8_t_s_s ((g_101 > (((+((safe_sub_func_int32_t_s_s ((safe_mod_func_int8_t_s_s ((g_387 != (safe_rshift_func_uint16_t_u_u (((safe_sub_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_u ((safe_mod_func_int16_t_s_s ((-2L), (safe_add_func_uint32_t_u_u ((((p_40 && (l_407 = (~((l_319 | g_370) >= (safe_mul_func_uint8_t_u_u (((safe_unary_minus_func_int16_t_s ((l_406 = (((safe_sub_func_uint8_t_u_u ((g_276 = 255UL), (((l_403 = g_75) >= (l_372 = (safe_mod_func_int16_t_s_s (0x5BA9L, g_96)))) > p_40))) >= p_40) ^ (-1L))))) != g_244), (-1L))))))) || l_403) & l_371), g_244)))), l_246)), p_40)) <= 0L), 0))), p_40)), 6UL)) | g_94)) >= 0x41F8L) || p_40)), 1)) >= 8L);
     l_224
       =
       (((safe_rshift_func_uint8_t_u_s ((safe_add_func_uint8_t_u_u (p_40, (((safe_mul_func_int16_t_s_s (p_40, ((0x50L && (safe_mul_func_int8_t_s_s ((safe_rshift_func_uint8_t_u_u (g_370, (g_276 = (safe_rshift_func_uint16_t_u_u ((g_94 = ((((safe_mod_func_uint32_t_u_u (((g_21 = ((4294967288UL >= (safe_sub_func_int16_t_s_s (((safe_unary_minus_func_int16_t_s ((safe_sub_func_uint16_t_u_u (g_244, (safe_mod_func_int8_t_s_s ((safe_mul_func_int16_t_s_s ((((safe_sub_func_int8_t_s_s (((l_227 = (safe_sub_func_int16_t_s_s ((l_219 = ((safe_sub_func_uint16_t_u_u (65535UL, (safe_rshift_func_uint8_t_u_u ((safe_mul_func_uint8_t_u_u ((65528UL || (((!(((((safe_add_func_uint8_t_u_u ((l_403 > 0x71L), g_370)) == 3L) >= l_227) && 0xD7A1L) ^ g_244)) <= p_40) == g_304)), g_21)), 4)))) & g_75)), 0x5C18L))) & p_40), l_403)) > p_40) || 0x0DDBL), g_176)), 0x39L)))))) | 0UL), g_244))) || g_75)) && p_40), 0x6C258254L)) && l_407) == 0x80996939L) | g_276)), 5))))), 0x1CL))) < l_246))) && g_387) & g_370))), l_403)) || 0UL) == 0UL);
   }
   for
     (l_406
      =
      0;
      (l_406
       >
       (-22));
      --l_406)
   {
     l_220
       =
       (safe_add_func_uint32_t_u_u
        ((65529UL | (l_224 = (safe_mul_func_int8_t_s_s ((((0x6B9A1A24L || (safe_lshift_func_int16_t_s_u (l_403, 7))) || 4294967287UL) | (safe_mod_func_int32_t_s_s ((safe_mod_func_uint8_t_u_u ((l_456 = (g_387 = (l_408 == g_181))), (safe_rshift_func_uint8_t_u_s ((g_276 = ((0x5E7A8B45L && l_408) > (((((safe_add_func_uint8_t_u_u ((safe_mul_func_int8_t_s_s (g_245, p_40)), l_463)) == 0x8FE4L) & l_464) ^ 0xEAL) && g_304))), p_40)))), g_244))), g_244)))), 0xFA39C599L));
     if (p_40)
       break;
   }
   l_490
     =
     ((((safe_add_func_uint8_t_u_u (g_370, 249UL)) < g_96) > l_463) < (l_489 = (safe_lshift_func_uint8_t_u_u (((safe_rshift_func_int16_t_s_u (((l_407 = (l_246 == (l_227 = ((l_337 == ((safe_sub_func_int8_t_s_s ((safe_lshift_func_int16_t_s_s ((((g_21 = (safe_lshift_func_uint16_t_u_s ((g_94 = (safe_mod_func_int16_t_s_s ((safe_mul_func_int16_t_s_s ((safe_lshift_func_uint8_t_u_u ((((l_456 = ((((l_219 = (safe_sub_func_int8_t_s_s (l_456, (safe_sub_func_uint8_t_u_u (0x92L, (safe_add_func_int16_t_s_s ((l_223 = ((1UL & 0x1FD5L) || g_176)), p_40))))))) < p_40) == 0x81B0L) == l_319)) == g_7) <= 4294967290UL), g_245)), l_407)), g_21))), 8))) >= p_40) != l_372), l_218)), p_40)) | (-10L))) <= 0x08B89549L)))) && p_40), 1)) >= l_334), 7))));
   for
     (l_403
      =
      9;
      (l_403
       !=
       32);
      l_403++)
   {
     uint32_t
       l_494
       =
       0xE0D74FEBL;
     l_493
       =
       g_387;
     l_489
       =
       (l_494
        =
        p_40);
     g_21
       =
       (safe_add_func_int32_t_s_s
        ((!g_244), ((((g_387 = ((safe_unary_minus_func_int16_t_s ((g_176 || ((l_494 | g_101) && (l_246 & (safe_mul_func_int16_t_s_s ((safe_add_func_int16_t_s_s ((l_489 = (safe_mod_func_uint8_t_u_u (l_464, l_504))), ((((p_40 == g_387) && 1UL) ^ p_40) > 246UL))), p_40))))))) > p_40)) >= p_40) | 0UL) || 0xCB4754EAL)));
     g_21
       =
       p_40;
   }
 }
 if ((safe_sub_func_uint16_t_u_u ((l_406 = (((safe_sub_func_int16_t_s_s ((((+((safe_lshift_func_int16_t_s_s ((-9L), g_94)) >= (l_218 > (safe_mod_func_uint16_t_u_u (((l_226 = (5L < (safe_rshift_func_uint8_t_u_u ((((((g_7 = g_245) != (((7UL >= ((g_96 > p_40) == (l_372 && p_40))) < p_40) == g_370)) & 0xCBEBB16FL) > g_370) < 0x10A4L), g_245)))) & l_464), p_40))))) | l_372) || 0x425D473EL), 0L)) > 3UL) & 0x2FB1L)), 0xC419L)))
 {
   uint16_t
     l_537
     =
     0x783CL;
   int32_t
     l_540
     =
     (-1L);
   int32_t
     l_557
     =
     0x5B5812A0L;
   if (g_75)
   {
     int16_t
       l_541
       =
       0xC5F7L;
     l_224
       =
       (safe_mul_func_int16_t_s_s
        ((safe_rshift_func_uint8_t_u_u ((safe_add_func_int8_t_s_s (((l_557 = (safe_add_func_int16_t_s_s (((safe_lshift_func_uint8_t_u_u (p_40, 0)) ^ (l_407 = (safe_rshift_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_s ((p_40 & ((1L && ((safe_add_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u ((safe_rshift_func_int16_t_s_u (((safe_sub_func_int32_t_s_s (((l_537 != (safe_add_func_uint32_t_u_u ((l_541 = (l_540 = l_224)), (safe_lshift_func_int16_t_s_s (p_40, 10))))) && (safe_lshift_func_int16_t_s_s (((safe_sub_func_uint32_t_u_u ((g_304 >= (safe_rshift_func_int8_t_s_s ((safe_add_func_uint8_t_u_u ((l_226 = (l_406 = l_319)), ((l_219 = (+((safe_add_func_uint32_t_u_u ((((safe_rshift_func_int8_t_s_u (1L, g_276)) | l_556) < (-1L)), 0x652A5139L)) == g_96))) & 0x5244L))), 4))), l_372)) != 0xFE5AL), g_94))), 0xA2226192L)) & p_40), 15)), 5)), 0xFAB9L)) && l_371)) != 0xC001L)), g_244)), 7)))), 0x1FFEL))) != 1UL), l_537)), 5)), l_337));
   }
   else
   {
     l_220
       =
       (safe_mul_func_uint8_t_u_u
        (p_40,
  (p_40
   |
   g_244)));
     if (g_96)
       break;
     l_540
       =
       0x8A84BF4CL;
     if (l_227)
       break;
   }
   if (p_40)
     break;
   for
     (g_245
      =
      (-26);
      (g_245
       <
       (-30));
      g_245--)
   {
     if (p_40)
       break;
     l_224
       =
       (+
        ((safe_mul_func_int8_t_s_s (0xEFL, 0UL)) >= (safe_lshift_func_uint8_t_u_u (((l_571 = ((safe_add_func_uint32_t_u_u ((safe_sub_func_int8_t_s_s (l_540, (p_40 <= (0x1C78L & (0xE739L || (l_570 = 0xFA64L)))))), (l_372 = ((l_408 = (l_218 | ((-1L) != 0UL))) == l_537)))) < 0xA5L)) || p_40), l_246))));
   }
   l_408
     =
     (safe_lshift_func_int16_t_s_s
      (5L,
       ((+((((0xC2L | 0x19L) == l_537) >= p_40) & g_176)) != ((l_406 = (safe_lshift_func_uint16_t_u_s ((((g_129 ^ (safe_mod_func_uint8_t_u_u ((p_40 < (safe_rshift_func_uint8_t_u_s (((p_40 < 247UL) <= l_218), l_319))), 0x50L))) || g_387) > p_40), l_537))) || 0L))));
 }
 else
 {
   int16_t
     l_584
     =
     0xFCADL;
   int8_t
     l_587
     =
     0L;
   int32_t
     l_628
     =
     0x99FC9820L;
   if ((((l_220 == (l_227 = (safe_mul_func_int16_t_s_s (l_227, ((((safe_mul_func_uint8_t_u_u (p_40, (g_75 | (g_129 ^ ((!g_245) <= p_40))))) || l_584) < ((safe_rshift_func_uint8_t_u_s (g_129, l_587)) > (-7L))) <= 0x3D2D6B36L))))) >= l_371) <= p_40))
   {
     g_21
       =
       g_387;
     l_227
       =
       p_40;
     if (g_276)
       continue;
     l_571
       =
       ((~(safe_lshift_func_int16_t_s_u ((safe_mod_func_int32_t_s_s ((safe_mul_func_int16_t_s_s ((((l_372 = (safe_mul_func_uint16_t_u_u (0x949BL, (l_587 & (((l_406 = (safe_mod_func_int32_t_s_s (g_75, 0x152DB58FL))) <= (((g_96 && (0xE9C8L <= g_176)) || (safe_mul_func_uint8_t_u_u ((safe_unary_minus_func_uint32_t_u ((!4294967295UL))), ((safe_lshift_func_int16_t_s_s ((safe_mul_func_uint8_t_u_u ((!0xC8L), p_40)), 2)) ^ 0x53F7L)))) | l_211)) && 1L))))) && 0L) & l_219), l_556)), g_96)), 5))) & 0x99686D7CL);
   }
   else
   {
     l_609
       =
       ((g_245 = g_101) ^ ((+l_220) >= (l_334 | p_40)));
     return
       l_408;
   }
   if (g_101)
     continue;
   l_224
     =
     (l_628
      =
      (l_371
       ==
       (safe_mul_func_int16_t_s_s
        ((((-1L) == (l_220 = p_40)) & p_40), ((safe_unary_minus_func_uint8_t_u ((l_571 == (safe_add_func_int16_t_s_s (((safe_lshift_func_uint16_t_u_s ((safe_add_func_uint16_t_u_u (0UL, 9L)), (((safe_mod_func_int32_t_s_s (((safe_unary_minus_func_int32_t_s ((((safe_sub_func_uint32_t_u_u ((p_40 >= (((safe_add_func_uint16_t_u_u ((l_223 = ((((((safe_lshift_func_int8_t_s_u ((l_227 = l_334), l_556)) == 0L) | g_176) || p_40) & l_319) & (-1L))), p_40)) > (-1L)) == 0xB9L)), p_40)) || 0x5559F4D5L) ^ 0x3913D021L))) <= l_464), 8UL)) >= 1L) ^ g_94))) <= p_40), p_40))))) > (-8L))))));
 }
      }
      else
      {
 uint32_t
   l_633
   =
   4294967295UL;
 int16_t
   l_654
   =
   7L;
 int32_t
   l_657
   =
   6L;
 int32_t
   l_666
   =
   0x17F9480FL;
 int32_t
   l_712
   =
   (-10L);
 if (p_40)
   break;
 if (((p_40 = (+(safe_mul_func_int16_t_s_s (g_94, (5L <= (l_633 >= (safe_mul_func_uint16_t_u_u ((safe_mul_func_int8_t_s_s ((safe_sub_func_int16_t_s_s (0L, (safe_lshift_func_int8_t_s_u ((safe_sub_func_uint16_t_u_u ((safe_mod_func_uint32_t_u_u ((safe_mod_func_int16_t_s_s ((((safe_rshift_func_uint16_t_u_u (((((((safe_mod_func_uint8_t_u_u (g_304, p_40)) ^ ((l_372 = ((((safe_mod_func_uint32_t_u_u (4294967287UL, l_319)) != (l_319 < l_225)) || p_40) && 4UL)) <= g_245)) >= p_40) | g_101) & g_101) != g_304), 14)) ^ 0xDADCEC21L) != l_218), g_387)), 0x5D77AFF9L)), 0xE2E0L)), 5)))), l_654)), l_223)))))))) || l_654))
 {
   uint16_t
     l_667
     =
     0x76DCL;
   g_21
     =
     (safe_sub_func_int8_t_s_s
      ((l_219 = ((l_657 = (+((g_21 < p_40) > (g_7 = p_40)))) || 5UL)), (safe_add_func_uint32_t_u_u ((safe_sub_func_uint8_t_u_u (p_40, ((((p_40 < (safe_add_func_uint8_t_u_u (0xAFL, 0x54L))) & (l_666 = (((l_226 = (safe_sub_func_uint16_t_u_u ((l_408 = l_372), p_40))) >= 0x10F9L) != p_40))) == 0xD98AL) & p_40))), l_667))));
 }
 else
 {
   uint16_t
     l_705
     =
     0x84BBL;
   for
     (l_609
      =
      16;
      (l_609
       !=
       36);
      l_609
      =
      safe_add_func_int32_t_s_s
      (l_609,
       7))
   {
     uint8_t
       l_690
       =
       250UL;
     g_21
       =
       (l_226
        =
        (((((safe_rshift_func_int8_t_s_u ((safe_add_func_uint8_t_u_u ((safe_lshift_func_uint16_t_u_s (((safe_rshift_func_uint16_t_u_u (((safe_sub_func_int16_t_s_s ((1UL != (((((p_40 = (p_40 >= (safe_add_func_uint16_t_u_u (l_372, g_129)))) == (l_224 = (safe_lshift_func_uint16_t_u_s (0UL, 3)))) < (safe_mul_func_int8_t_s_s ((((g_245 = (safe_mul_func_int8_t_s_s (((l_690 && (((l_654 || l_408) || g_75) < g_245)) | 0xE336L), g_21))) < 0UL) ^ l_690), 1L))) & 0x5CD401BCL) <= 0x3CF5L)), 0x97B5L)) >= 0x55BD7198L), l_690)) >= l_211), 4)), 0x72L)), l_219)) & 0x11L) ^ 0xA21118B3L) != l_691) < g_21));
   }
   g_21
     =
     ((l_692 = 1L) & p_40);
   if (g_176)
     continue;
   l_372
     =
     (safe_sub_func_uint16_t_u_u
      (((l_226 = (safe_sub_func_uint8_t_u_u ((safe_mod_func_int8_t_s_s (p_40, (l_712 = (g_7 = ((safe_mod_func_int16_t_s_s (((safe_sub_func_uint8_t_u_u (((l_666 = g_176) | ((safe_mod_func_uint32_t_u_u (((-1L) < (p_40 < ((l_705 ^ (safe_mul_func_uint16_t_u_u ((g_276 < l_657), (safe_rshift_func_uint8_t_u_u ((p_40 <= (safe_mod_func_uint32_t_u_u (l_571, l_570))), 7))))) >= 65528UL))), p_40)) <= 0L)), g_276)) > l_371), p_40)) ^ g_75))))), 0xADL))) != g_94), p_40));
 }
 g_21
   =
   g_7;
      }
   }
   if (g_176)
     {
continue;
{
      uint16_t
 l_271
 =
 65530UL;
      int32_t
 l_303
 =
 (-6L);
      uint16_t
 l_309
 =
 0x1B94L;
      if (l_220)
 break;
      if (l_271)
 continue;
      l_220
 =
 (l_227
  =
  (g_304
   =
   ((l_226 = (safe_mod_func_int32_t_s_s ((safe_mul_func_int16_t_s_s (((g_276 = 5UL) | (((safe_mod_func_uint16_t_u_u (((safe_sub_func_int8_t_s_s (p_40, (l_223 = (safe_mod_func_int8_t_s_s ((((safe_lshift_func_int16_t_s_u ((safe_mod_func_int32_t_s_s ((safe_add_func_int16_t_s_s (g_129, (l_224 = (safe_add_func_int8_t_s_s ((((g_245 && (g_245 = (((safe_rshift_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u (((safe_lshift_func_int8_t_s_u (0x14L, 7)) < 0x7EL), (safe_rshift_func_int16_t_s_u ((0x22L > g_75), 14)))), 5)) >= ((((safe_mod_func_int8_t_s_s ((l_303 = (safe_sub_func_int8_t_s_s (g_129, 1UL))), 0xBBL)) & g_244) | p_40) < p_40)) <= p_40))) | l_219) ^ 1L), p_40))))), l_271)), 8)) ^ l_271) == g_101), g_75))))) && 0x32686C91L), g_181)) > l_211) == 1UL)), 0x68DEL)), l_271))) ^ p_40)));
      l_303
 =
 (safe_mul_func_int16_t_s_s
  ((+(l_309 <= ((l_226 = ((safe_lshift_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u (p_40, ((((safe_sub_func_int32_t_s_s (((safe_unary_minus_func_int16_t_s ((g_276 == ((l_227 = p_40) && (l_224 = g_244))))) >= (safe_mod_func_uint32_t_u_u (l_211, (g_21 = 8L)))), p_40)) & g_129) && p_40) & 0UL))), 0)) || p_40)) >= g_96))), p_40));
    }
}
   l_372
     =
     (safe_sub_func_uint16_t_u_u
      (((l_226 = (safe_sub_func_uint8_t_u_u ((safe_mod_func_int8_t_s_s (p_40, (l_712 = (g_7 = ((safe_mod_func_int16_t_s_s (((safe_sub_func_uint8_t_u_u (((l_666 = g_176) | ((safe_mod_func_uint32_t_u_u (((-1L) < (p_40 < ((l_705 ^ (safe_mul_func_uint16_t_u_u ((g_276 < l_657), (safe_rshift_func_uint8_t_u_u ((p_40 <= (safe_mod_func_uint32_t_u_u (l_571, l_570))), 7))))) >= 65528UL))), p_40)) <= 0L)), g_276)) > l_371), p_40)) ^ g_75))))), 0xADL))) != g_94), p_40));
{
     uint8_t
       l_690
       =
       250UL;
     g_21
       =
       (l_226
        =
        (((((safe_rshift_func_int8_t_s_u ((safe_add_func_uint8_t_u_u ((safe_lshift_func_uint16_t_u_s (((safe_rshift_func_uint16_t_u_u (((safe_sub_func_int16_t_s_s ((1UL != (((((p_40 = (p_40 >= (safe_add_func_uint16_t_u_u (l_372, g_129)))) == (l_224 = (safe_lshift_func_uint16_t_u_s (0UL, 3)))) < (safe_mul_func_int8_t_s_s ((((g_245 = (safe_mul_func_int8_t_s_s (((l_690 && (((l_654 || l_408) || g_75) < g_245)) | 0xE336L), g_21))) < 0UL) ^ l_690), 1L))) & 0x5CD401BCL) <= 0x3CF5L)), 0x97B5L)) >= 0x55BD7198L), l_690)) >= l_211), 4)), 0x72L)), l_219)) & 0x11L) ^ 0xA21118B3L) != l_691) < g_21));
   }
 }
 g_21
   =
   g_7;
      }
    }
  }
  g_801
    =
    (!
     (((safe_mul_func_uint16_t_u_u (p_40, (l_769 = (safe_sub_func_int16_t_s_s ((((safe_mod_func_int16_t_s_s (((p_40 < (safe_mul_func_uint8_t_u_u ((l_796 = (safe_lshift_func_uint16_t_u_s (((safe_mod_func_int32_t_s_s (((safe_mul_func_uint8_t_u_u ((((safe_add_func_uint16_t_u_u (l_769, l_219)) == (safe_mul_func_int16_t_s_s ((safe_add_func_uint32_t_u_u ((g_304 > p_40), (g_21 = (safe_mod_func_int16_t_s_s (((l_224 = ((l_224 != (l_796 < ((safe_rshift_func_uint8_t_u_u ((l_226 = ((g_94 = (safe_add_func_uint32_t_u_u (l_609, p_40))) ^ p_40)), l_757)) >= p_40))) & 0x3897L)) || l_609), 0xDA4CL))))), 0x8594L))) || g_304), 0xA5L)) != l_757), l_769)) ^ g_129), 15))), p_40))) | 0L), 6UL)) && g_21) & g_304), l_246))))) != 0xE0304CA0L) <= l_219));
  l_224
    =
    (g_21
     =
     (safe_mod_func_uint32_t_u_u
      (p_40,
       (~
 (((g_96 == ((~(safe_add_func_int32_t_s_s (l_806, (l_769 = l_757)))) ^ (((((safe_mul_func_uint8_t_u_u ((safe_mul_func_int8_t_s_s (((safe_unary_minus_func_uint16_t_u (p_40)) ^ (g_94 = (((safe_add_func_uint32_t_u_u ((l_226 = (((g_181 | 1UL) & (g_245 = p_40)) <= 4294967286UL)), 4294967292UL)) & g_801) && 0xFE1FD14AL))), l_609)), g_96)) > l_796) != g_244) < p_40) || 5UL))) & p_40) & l_814)))));
  return
    g_129;
}
static uint16_t
func_41
  (int32_t
   p_42,
   const
   int32_t
   p_43,
   const
   int16_t
   p_44,
   int32_t
   p_45
)
{
  int32_t
    l_192
    =
    0x3BBF1768L;
  int32_t
    l_199
    =
    (-1L);
  int32_t
    l_200
    =
    0x01793202L;
  l_200
    =
    (safe_rshift_func_int16_t_s_u
     ((safe_rshift_func_int16_t_s_u ((safe_add_func_int8_t_s_s ((l_199 = ((safe_rshift_func_uint8_t_u_u (((safe_mul_func_int8_t_s_s (l_192, (5L & p_42))) | p_44), (safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint16_t_u_u (p_42, 1)), (((l_192 ^ ((~(safe_sub_func_int8_t_s_s (0x1FL, l_192))) && ((g_96 > l_192) == l_192))) || p_45) > 1UL))))) || 1UL)), (-7L))), g_129)), l_192));
  l_200
    =
    (l_199
     =
     (~
      (g_129
       &&
       l_200)));
  return
    l_200;
}
static int32_t
func_46
  (uint32_t
   p_47
)
{
  int8_t
    l_71
    =
    (-9L);
  int32_t
    l_72
    =
    0xCA7DBC8BL;
  int32_t
    l_73
    =
    0L;
  int32_t
    l_74
    =
    (-2L);
  int8_t
    l_177
    =
    9L;
  l_177
    =
    (safe_lshift_func_uint16_t_u_s
     (func_50
      (g_21,
       func_55
       ((safe_lshift_func_uint16_t_u_u (g_7, g_21)), p_47, ((safe_add_func_int8_t_s_s ((!(safe_rshift_func_int16_t_s_s (((~0x5E60D1F2L) < ((safe_mul_func_uint16_t_u_u ((safe_lshift_func_uint8_t_u_u (255UL, 3)), (g_75 = ((((g_21 <= ((-9L) & (l_74 = (safe_sub_func_int16_t_s_s ((l_73 = (l_72 = l_71)), (-1L)))))) & (-1L)) & 0x4B4EA65DL) || 0x84L)))) ^ 0x129E5E26L)), 5))), g_7)) == l_71)), g_21, p_47), 7));
  return
    l_72;
}
static uint16_t
func_50
  (uint16_t
   p_51,
   uint8_t
   p_52,
   uint16_t
   p_53,
   int32_t
   p_54
)
{
  uint8_t
    l_109
    =
    9UL;
  int32_t
    l_110
    =
    (-1L);
  int32_t
    l_128
    =
    (-1L);
  uint32_t
    l_148
    =
    0UL;
  int16_t
    l_151
    =
    1L;
  uint32_t
    l_152
    =
    4294967289UL;
  for
    (g_96
     =
     (-23);
     (g_96
      <
      48);
     ++g_96)
  {
    uint32_t
      l_111
      =
      4294967295UL;
    for
      (g_94
       =
       (-30);
       (g_94
 >
 41);
       g_94
       =
       safe_add_func_int32_t_s_s
       (g_94,
 8))
    {
      int8_t
 l_126
 =
 0x4DL;
      uint32_t
 l_127
 =
 1UL;
{
      int8_t
 l_126
 =
 0x4DL;
      uint32_t
 l_127
 =
 1UL;
      g_129
 =
 (((safe_add_func_uint8_t_u_u ((((g_96 || ((!((l_109 = 0x0E253E14L) > (((((g_7 && p_51) ^ g_75) ^ l_110) >= (l_111 = p_54)) && ((safe_sub_func_int8_t_s_s ((safe_mod_func_uint32_t_u_u ((safe_add_func_int16_t_s_s ((((safe_mul_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u ((l_110 = ((safe_add_func_int8_t_s_s ((+((0xD861L || ((((safe_sub_func_int8_t_s_s (l_110, 0x8FL)) ^ g_7) != l_111) & p_53)) == (-9L))), 0x8BL)) <= g_75)), p_51)), g_96)) < 0x4E7F8FE0L) != l_126), 0x7CC0L)), 1L)), l_127)) || g_21)))) & g_94)) != 0UL) || 4L), l_128)) ^ l_127) < l_128);
      if (g_7)
 continue;
    }
    }
  }
  g_21
    =
    (safe_lshift_func_int16_t_s_u
     ((safe_mod_func_uint32_t_u_u ((~(((!(safe_sub_func_int32_t_s_s ((((((l_128 == (-8L)) && l_110) <= (safe_mod_func_uint8_t_u_u ((safe_sub_func_int8_t_s_s ((g_101 && (g_94 | (p_54 = (safe_mul_func_uint16_t_u_u (((((safe_rshift_func_uint8_t_u_u ((safe_sub_func_int16_t_s_s (((safe_lshift_func_uint16_t_u_s (g_96, 2)) && (l_148 = g_94)), (safe_add_func_int32_t_s_s (((g_7 = 5L) ^ p_52), g_75)))), 1)) >= 0x5F07L) && (-7L)) > 5UL), g_21))))), p_52)), l_151))) ^ l_109) <= (-1L)), l_110))) ^ 1UL) | l_152)), g_21)), 14));
  g_21
    =
    l_109;
  g_21
    =
    ((safe_mul_func_int8_t_s_s (l_152, (safe_add_func_int32_t_s_s (((safe_mul_func_uint16_t_u_u ((safe_mod_func_int8_t_s_s (((p_52 | (safe_unary_minus_func_int16_t_s ((safe_lshift_func_int8_t_s_u ((l_110 = ((~((safe_lshift_func_int8_t_s_u ((-8L), l_110)) || (g_176 = ((safe_rshift_func_uint16_t_u_s ((safe_mod_func_uint8_t_u_u ((safe_sub_func_uint16_t_u_u ((g_94 = p_54), g_21)), ((safe_mul_func_int8_t_s_s ((((((l_152 ^ 0x6FA5L) < (safe_rshift_func_int8_t_s_u (g_101, p_53))) && g_75) & l_110) && 0L), g_21)) || l_110))), 15)) & 1UL)))) >= l_128)), 3))))) != 8L), g_96)), g_21)) & g_96), 0x38FB5A0EL)))) <= p_52);
  return
    p_54;
}
static uint8_t
func_55
  (uint32_t
   p_56,
   int16_t
   p_57,
   const
   uint32_t
   p_58
)
{
  uint8_t
    l_84
    =
    0xA2L;
  int32_t
    l_85
    =
    (-6L);
  uint32_t
    l_92
    =
    0x20AFD326L;
  int32_t
    l_93
    =
    0x0F4EB953L;
  int32_t
    l_95
    =
    5L;
  int32_t
    l_102
    =
    (-1L);
  l_95
    =
    (safe_sub_func_int32_t_s_s
     ((g_94 = (safe_mod_func_uint16_t_u_u ((g_75 && ((-3L) >= (safe_add_func_int16_t_s_s (((g_7 = ((safe_rshift_func_int16_t_s_s ((l_85 = l_84), p_56)) != 6L)) == 0xB5L), (safe_mod_func_int32_t_s_s (p_56, (safe_mul_func_uint16_t_u_u ((safe_rshift_func_int16_t_s_s (l_92, (l_93 = (-1L)))), g_75)))))))), g_75))), g_21));
  g_96
    =
    l_85;
  l_102
    =
    (l_95
     =
     (l_93
      =
      (g_101
       =
       (safe_sub_func_uint16_t_u_u
 (g_75,
  (l_85
   =
   ((safe_lshift_func_int8_t_s_u ((p_57 <= p_57), 1)) == 255UL)))))));
  return
    g_7;
}
int
main
  (int
   argc,
   char
   *argv
   []
)
{
  int
    print_hash_value
    =
    0;
  if (argc == 2 && strcmp (argv[1], "1") == 0)
    print_hash_value
      =
      1;
  platform_main_begin
    ();
  crc32_gentab
    ();
  func_1
    ();
  transparent_crc
    (g_7,
     "g_7",
     print_hash_value);
  transparent_crc
    (g_21,
     "g_21",
     print_hash_value);
  transparent_crc
    (g_75,
     "g_75",
     print_hash_value);
  transparent_crc
    (g_94,
     "g_94",
     print_hash_value);
  transparent_crc
    (g_96,
     "g_96",
     print_hash_value);
  transparent_crc
    (g_101,
     "g_101",
     print_hash_value);
  transparent_crc
    (g_129,
     "g_129",
     print_hash_value);
  transparent_crc
    (g_176,
     "g_176",
     print_hash_value);
  transparent_crc
    (g_181,
     "g_181",
     print_hash_value);
  transparent_crc
    (g_244,
     "g_244",
     print_hash_value);
  transparent_crc
    (g_245,
     "g_245",
     print_hash_value);
  transparent_crc
    (g_276,
     "g_276",
     print_hash_value);
  transparent_crc
    (g_304,
     "g_304",
     print_hash_value);
  transparent_crc
    (g_370,
     "g_370",
     print_hash_value);
  transparent_crc
    (g_387,
     "g_387",
     print_hash_value);
  transparent_crc
    (g_758,
     "g_758",
     print_hash_value);
  transparent_crc
    (g_801,
     "g_801",
     print_hash_value);
  transparent_crc
    (g_833,
     "g_833",
     print_hash_value);
  transparent_crc
    (g_985,
     "g_985",
     print_hash_value);
  transparent_crc
    (g_1039,
     "g_1039",
     print_hash_value);
  transparent_crc
    (g_1238,
     "g_1238",
     print_hash_value);
  transparent_crc
    (g_1272,
     "g_1272",
     print_hash_value);
  transparent_crc
    (g_1309,
     "g_1309",
     print_hash_value);
  transparent_crc
    (g_1473,
     "g_1473",
     print_hash_value);
  transparent_crc
    (g_1504,
     "g_1504",
     print_hash_value);
  transparent_crc
    (g_1578,
     "g_1578",
     print_hash_value);
  transparent_crc
    (g_1638,
     "g_1638",
     print_hash_value);
  transparent_crc
    (g_1670,
     "g_1670",
     print_hash_value);
  transparent_crc
    (g_1671,
     "g_1671",
     print_hash_value);
  transparent_crc
    (g_1747,
     "g_1747",
     print_hash_value);
  transparent_crc
    (g_1812,
     "g_1812",
     print_hash_value);
  transparent_crc
    (g_1902,
     "g_1902",
     print_hash_value);
  transparent_crc
    (g_1920,
     "g_1920",
     print_hash_value);
  transparent_crc
    (g_1957,
     "g_1957",
     print_hash_value);
  transparent_crc
    (g_1958,
     "g_1958",
     print_hash_value);
  transparent_crc
    (g_2005,
     "g_2005",
     print_hash_value);
  transparent_crc
    (g_2111,
     "g_2111",
     print_hash_value);
  transparent_crc
    (g_2112,
     "g_2112",
     print_hash_value);
  transparent_crc
    (g_2189,
     "g_2189",
     print_hash_value);
  transparent_crc
    (g_2285,
     "g_2285",
     print_hash_value);
  transparent_crc
    (g_2286,
     "g_2286",
     print_hash_value);
  platform_main_end
    (crc32_context
     ^
     0xFFFFFFFFUL,
     print_hash_value);
  return
    0;
}
