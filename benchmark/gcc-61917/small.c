
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
  int32_t
  g_3
  =
  0x2C70BB74L;
static
  uint16_t
  g_30
  =
  8UL;
static volatile int8_t g_38 = 0xA5L;
static
  int32_t
  g_54
  =
  0x26A25A95L;
static
  int32_t
  g_71
  [9]
  =
  {
4L,
4L,
4L,
4L,
4L,
4L,
4L,
4L,
4L
};
static
  int32_t
  g_201
  =
  0x90B57F07L;
static
  int32_t
  g_300
  =
  0xA87531F4L;
static
  uint32_t
  g_329
  [2]
  [7]
  [6]
  =
  {
{{1UL, 0x86E9DE6DL, 0xA3237E1DL, 0x097B45DCL, 0xA200B0FFL, 4294967290UL}, {4294967291UL, 1UL, 0xA3237E1DL, 0x30B79297L, 0xA3237E1DL, 1UL}, {4294967293UL, 0x30B79297L, 4294967290UL, 2UL, 0xCBC3065EL, 0x58EB26F2L}, {2UL, 0xCBC3065EL, 0x58EB26F2L, 0xA3237E1DL, 3UL, 1UL}, {1UL, 0xCBC3065EL, 0xB8C5FC2AL, 0xB8C5FC2AL, 0xCBC3065EL, 1UL}, {0xCBC3065EL, 0x30B79297L, 1UL, 0x86E9DE6DL, 0xA3237E1DL, 0x097B45DCL}, {0xB8C5FC2AL, 1UL, 0x4A936E5EL, 0x30B79297L, 3UL, 0xB8C5FC2AL}}, {{1UL, 0xA3237E1DL, 0x30B79297L, 0xA3237E1DL, 1UL, 4294967291UL}, {0xA200B0FFL, 4294967291UL, 3UL, 1UL, 0xB8C5FC2AL, 0x58EB26F2L}, {0x86E9DE6DL, 1UL, 0xB8C5FC2AL, 4294967291UL, 0x58EB26F2L, 0x58EB26F2L}, {4294967293UL, 3UL, 3UL, 4294967293UL, 4294967290UL, 4294967291UL}, {0x58EB26F2L, 0x097B45DCL, 0x30B79297L, 2UL, 0xA3237E1DL, 0xB8C5FC2AL}, {0x30B79297L, 0x86E9DE6DL, 0x4A936E5EL, 1UL, 0xA3237E1DL, 1UL}, {1UL, 0x097B45DCL, 1UL, 0xCBC3065EL, 4294967290UL, 0x86E9DE6DL}} };
static
  int8_t
  g_344
  =
  1L;
static
  int16_t
  g_367
  =
  0x0D65L;
static
  uint32_t
  g_458
  =
  0xBCA3924BL;
static
  uint32_t
  g_513
  [7]
  =
  {
0x361537A8L,
0x361537A8L,
0x361537A8L,
0x361537A8L,
0x361537A8L,
0x361537A8L,
0x361537A8L
};
static
  int16_t
  g_521
  =
  (-9L);
static
  int16_t
  g_555
  =
  (-1L);
static
  uint8_t
  g_588
  =
  0xDDL;
static
  int32_t
  g_658
  =
  0x0C0C4A79L;
static volatile uint16_t g_669 = 0UL;
static
  int16_t
  g_697
  [9]
  [2]
  =
  {
{0x29D4L,
(-1L)},
{0x29D4L,
0x29D4L},
{0x29D4L,
(-1L)},
{0x29D4L,
0x29D4L},
{0x29D4L, (-1L)}, {0x29D4L,
0x29D4L},
{0x29D4L, (-1L)}, {0x29D4L,
0x29D4L},
{0x29D4L, (-1L)} };
static
  uint32_t
  g_721
  [10]
  =
  {
1UL,
0x5C7E2520L,
1UL,
0x39CBF230L,
0x39CBF230L,
1UL,
0x5C7E2520L,
1UL,
0x39CBF230L,
0x39CBF230L
};
static
  uint16_t
  g_774
  =
  0x02FDL;
static
  int32_t
  g_866
  =
  3L;
static
  uint32_t
  g_920
  =
  0UL;
static
  int8_t
  g_930
  =
  0xC4L;
static
  uint32_t
  g_978
  =
  4294967295UL;
static
  volatile
  uint32_t
  g_1265
  [5]
  [8]
  =
  {
{0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL},
{0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL,
0xDDA6101AL},
{0xDDA6101AL,
0xDDA6101AL, 0xDDA6101AL,
0xDDA6101AL, 0xDDA6101AL,
0xDDA6101AL, 0xDDA6101AL,
0xDDA6101AL}, {0xDDA6101AL,
0xDDA6101AL, 0xDDA6101AL,
0xDDA6101AL, 0xDDA6101AL,
0xDDA6101AL, 0xDDA6101AL,
0xDDA6101AL}, {0xDDA6101AL,
0xDDA6101AL, 0xDDA6101AL,
0xDDA6101AL, 0xDDA6101AL,
0xDDA6101AL, 0xDDA6101AL,
0xDDA6101AL} };
static
  uint16_t
  g_1266
  =
  0x383EL;
static
  uint32_t
  g_1281
  =
  1UL;
static volatile int32_t g_1382 = 1L;
static
  int32_t
  g_1763
  =
  0xED33F476L;
static
  int32_t
  g_1782
  =
  0xAEC5DABAL;
static
  uint8_t
  g_1810
  [1]
  =
  {
3UL
};
static
  int16_t
  g_1835
  [1]
  [7]
  [5]
  =
  {
{{(-9L), (-9L), 2L, (-9L), (-9L)}, {(-1L), (-9L), (-1L), (-1L), (-9L)}, {(-9L), (-1L), (-1L), (-9L), (-1L)}, {(-9L), (-9L), 2L, (-9L), (-9L)}, {(-1L), (-9L), (-1L), (-1L), (-9L)}, {(-9L), (-1L), (-1L), (-9L), (-1L)}, {(-9L), (-9L), 2L, (-9L), (-9L)}} };
static
  uint8_t
  g_1917
  =
  255UL;
static volatile int16_t g_1995 = 0x4CFCL;
static
  int8_t
  g_2004
  [7]
  [1]
  [10]
  =
  {
{{0L, 9L, 0L, (-1L), 0L, (-1L), (-1L), 0L, (-1L), 0L}}, {{0L, 0L, 0xD5L, 0L, 0xE5L, (-1L), 2L, (-1L), 0xE5L, 0L}}, {{0L, (-3L), 0L, (-1L), 0x7BL, 0L, 2L, 2L, 0L, 0x7BL}}, {{0xD5L, 0L, 0L, 0L, (-1L), 0L, 9L, 0L, 9L, 0L}}, {{2L, (-3L), (-1L), (-3L), 2L, 0xD5L, (-1L), 9L, 9L, (-1L)}}, {{0L, 0xD5L, 0L, 0L, 0xD5L, 0L, 0xE5L, (-1L), 2L, (-1L)}}, {{(-3L), 0L, 2L, 9L, 2L, 0L, (-3L), 0xE5L, 0L, 0L}} };
static
  int16_t
  g_2065
  =
  0xF404L;
static
  uint32_t
  g_2066
  [9]
  =
  {
0xA0898CF5L,
0xA0898CF5L,
0xA0898CF5L,
0xA0898CF5L,
0xA0898CF5L,
0xA0898CF5L,
0xA0898CF5L,
0xA0898CF5L,
0xA0898CF5L
};
static
  int32_t
  g_2248
  =
  0L;
static volatile uint32_t g_2373 = 0x23C5291CL;
static
  volatile
  uint32_t
  g_2388
  [2]
  =
  {
0UL,
0UL
};
static
  int32_t
  g_2580
  =
  (-9L);
static volatile uint16_t g_2617 = 0xB993L;
static
  int32_t
  g_3117
  =
  9L;
static
  int32_t
  g_3350
  =
  (-1L);
static
  uint8_t
  g_3691
  =
  1UL;
static
  uint32_t
  g_3847
  =
  4294967295UL;
static volatile uint16_t g_4401 = 0xBDBCL;
static
  int8_t
  g_4460
  =
  1L;
static
  uint32_t
  g_4512
  =
  4294967295UL;
static
  int8_t
  g_4614
  =
  (-9L);
static
  int32_t
  g_4663
  =
  0xD619133FL;
static
  int16_t
  g_4847
  =
  0x2A05L;
static
  uint32_t
  g_4848
  [6]
  =
  {
0xC783FEF8L,
4UL,
0xC783FEF8L,
0xC783FEF8L,
4UL,
0xC783FEF8L
};
static
  int8_t
  g_4893
  =
  (-10L);
static volatile uint8_t g_4963 = 252UL;
static
  int16_t
func_1
(void
);
static
  int32_t
func_4
(int16_t
p_5
);
static
  int16_t
func_6
(uint8_t
p_7
);
static
  uint16_t
func_14
(int8_t
p_15,
int8_t
p_16,
uint32_t
p_17,
uint16_t
p_18
);
static
  int16_t
func_22
(int8_t
p_23,
int8_t
p_24
);
static
  int32_t
func_42
(uint16_t
p_43,
int32_t
p_44
);
static
  uint8_t
func_45
(uint32_t
p_46,
int32_t
p_47,
uint32_t
p_48,
int16_t
p_49,
uint16_t
p_50
);
static
  int32_t
func_56
(int32_t
p_57,
uint16_t
p_58,
int8_t
p_59,
uint32_t
p_60
);
static
  int32_t
func_72
(uint8_t
p_73,
int8_t
p_74,
uint8_t
p_75
);
static
  uint16_t
func_77
(uint32_t
p_78
);
static int16_t
func_1 (void
)
{
  int16_t
    l_2
    [1];
  uint32_t
    l_4261
    =
    0UL;
  int32_t
    l_4276
    =
    0x302D452BL;
  uint8_t
    l_4277
    =
    0x13L;
  int32_t
    l_4279
    =
    (-1L);
  int8_t
    l_4382
    =
    1L;
  uint16_t
    l_4480
    =
    0x4A29L;
  uint8_t
    l_4511
    =
    0x7AL;
  int16_t
    l_4513
    =
    0L;
  int16_t
    l_4632
    =
    0x82A0L;
  uint32_t
    l_4661
    =
    1UL;
  int32_t
    l_4693
    =
    0L;
  int32_t
    l_4726
    =
    3L;
  int32_t
    l_4917
    =
    0xF026BA6EL;
  int
    i;
  for
    (i
     =
     0;
     i
     <
     1;
     i++)
    l_2
      [i]
      =
      0x2062L;
  for
    (g_3
     =
     0;
     (g_3
      >=
      0);
     g_3
     -=
     1)
  {
    int32_t
      l_4266
      =
      0L;
    int32_t
      l_4273
      =
      1L;
    uint16_t
      l_4286
      =
      0xF524L;
    uint16_t
      l_4445
      =
      9UL;
    int
      i;
    if (func_4 ((l_2[g_3] = func_6 (((0x9869L > (safe_lshift_func_int8_t_s_u (0x5AL, 7))) <= l_2[g_3])))))
    {
      int16_t
 l_4275
 =
 0L;
      int32_t
 l_4281
 =
 0x70A7439CL;
      uint32_t
 l_4320
 [5]
 [4]
 [8]
 =
 {
   {{4294967288UL, 4294967286UL, 0x88591B17L, 0x2DA21B14L, 0xAC8CBD14L, 4294967295UL, 0x3AF223E2L, 0xBB3A348FL}
    ,
    {0x88591B17L,
     0xC53D16DDL,
     0xB212CD3DL,
     6UL,
     0x529B4498L,
     6UL,
     0xB212CD3DL,
     0xC53D16DDL}
    ,
    {0xBD6EE877L,
     0x88591B17L,
     2UL,
     0x60B90E3AL,
     1UL,
     0x2AA60299L,
     0x6B0F5BCEL,
     0x66920C8AL}
    ,
    {0xB212CD3DL,
     0UL,
     0x60B90E3AL,
     0x529B4498L,
     0xBD6EE877L,
     4294967295UL,
     0x6B0F5BCEL,
     4294967292UL}
    }
      , {{0xDA6ED2ABL, 0x529B4498L, 2UL, 0x2AA60299L, 4294967295UL, 0x6B0F5BCEL, 0xB212CD3DL, 0xAC8CBD14L}
  ,
  {4294967295UL,
   0x6B0F5BCEL,
   0xB212CD3DL,
   0xAC8CBD14L,
   0x66920C8AL,
   0xB901ABD4L,
   0x3AF223E2L,
   0x3AF223E2L}
  ,
  {4294967292UL,
   0xBB3A348FL,
   0x88591B17L,
   0x88591B17L,
   0xBB3A348FL,
   4294967292UL,
   0xCE9D9A97L,
   0UL}
  ,
  {0UL,
   0xB40ABE1EL,
   0xBB3A348FL,
   4294967295UL,
   0UL,
   0x2ABDD0F8L,
   0xEE6A9442L,
   0xB212CD3DL}
  }
      , {{0x3AF223E2L, 0xAC8CBD14L, 0x56C35297L, 4294967295UL, 4294967288UL, 0x66920C8AL, 0xB40ABE1EL, 0UL}
  ,
  {0x60B90E3AL,
   4294967288UL,
   4294967286UL,
   0x88591B17L,
   0x2DA21B14L,
   0xAC8CBD14L,
   4294967295UL,
   0x3AF223E2L}
  ,
  {0UL,
   0UL,
   6UL,
   0xAC8CBD14L,
   0xCB0B3A06L,
   4294967286UL,
   0xCB0B3A06L,
   0xAC8CBD14L}
  ,
  {0x529B4498L,
   0UL,
   0x529B4498L,
   0x2AA60299L,
   0UL,
   0xBD6EE877L,
   0x60B90E3AL,
   4294967292UL}
  }
      , {{0x56C35297L, 0UL, 4294967295UL, 0x529B4498L, 0UL, 0xCE9D9A97L, 0UL, 0x66920C8AL}
  ,
  {0x56C35297L,
   0xEE6A9442L,
   0x2DA21B14L,
   0x60B90E3AL,
   0UL,
   1UL,
   2UL,
   0xC53D16DDL}
  ,
  {0x529B4498L,
   0xB901ABD4L,
   0x2ABDD0F8L,
   6UL,
   0xCB0B3A06L,
   0x60B90E3AL,
   0xDA6ED2ABL,
   0xBB3A348FL}
  ,
  {0UL,
   0x2ABDD0F8L,
   4294967288UL,
   0x2DA21B14L,
   0x2DA21B14L,
   4294967288UL,
   0x2ABDD0F8L,
   0UL}
  }
      , {{0x60B90E3AL, 4294967295UL, 0xCB0B3A06L, 0UL, 4294967288UL, 0UL, 4294967286UL, 0x8534AC0FL}
  ,
  {0UL,
   0xC53D16DDL,
   0x3AF223E2L,
   4294967292UL,
   0x6B0F5BCEL,
   4294967295UL,
   0xBD6EE877L,
   0x529B4498L}
  ,
  {0xB901ABD4L,
   0xB212CD3DL,
   0x60B90E3AL,
   0xC53D16DDL,
   0xAC8CBD14L,
   4294967292UL,
   0UL,
   0x8534AC0FL}
  ,
  {0x529B4498L,
   4294967295UL,
   0UL,
   0x56C35297L,
   0x2DA21B14L,
   1UL,
   6UL,
   1UL}
  }
      };
      int32_t
 l_4422
 [7]
 [6];
      int
 i,
        j,
        k;
      for
 (i
  =
  0;
  i
  <
  7;
  i++)
      {
 for
   (j
    =
    0;
    j
    <
    6;
    j++)
   l_4422
     [i]
     [j]
     =
     0L;
      }
      if ((((((((safe_add_func_uint32_t_u_u ((+(safe_rshift_func_uint8_t_u_u (g_866, 7))), g_3350)) || 0xFDL) >= g_2388[1]) & g_3847) < ((((safe_rshift_func_int16_t_s_u (l_2[0], 3)) != ((-1L) <= (safe_sub_func_int8_t_s_s (((0x9BL & l_2[0]) != 0x17L), (-1L))))) | g_1835[0][3][2]) < g_555)) < l_2[g_3]) | g_344))
      {
 int16_t
   l_4274
   [6];
 int32_t
   l_4278
   =
   0L;
 int32_t
   l_4280
   =
   (-1L);
 int
   i;
 for
   (i
    =
    0;
    i
    <
    6;
    i++)
   l_4274
     [i]
     =
     0x0103L;
 for
   (g_588
    =
    0;
    (g_588
     <
     57);
    ++g_588)
 {
   return
     l_2
     [0];
 }
 l_4281
   =
   (((l_4280 = (((((l_4279 = ((safe_mul_func_int8_t_s_s (((l_4278 = (safe_mod_func_uint16_t_u_u ((0x6864FD20L > ((safe_mul_func_uint8_t_u_u (((safe_mul_func_int16_t_s_s (0xAE7EL, 1L)) | (g_71[7] = (safe_add_func_int8_t_s_s ((l_4261 > (l_4273 = ((((safe_lshift_func_uint8_t_u_u ((((0x6E9D4E43L >= (l_4266 = 0xE639630BL)) > ((l_4276 = ((safe_add_func_int16_t_s_s (0x6308L, (safe_lshift_func_uint8_t_u_s (1UL, 2)))) || (((((((safe_add_func_uint16_t_u_u ((((+(g_721[3] != g_1266)) != 4294967289UL) > g_3350), g_697[0][0])) & l_4273) == l_4274[2]) <= g_669) >= g_3847) == l_4275) | g_2004[0][0][2]))) != g_3691)) || l_4274[2]), g_367)) ^ l_4277) && (-6L)) != 65533UL))), g_1835[0][3][2])))), g_2066[7])) <= (-9L))), l_2[g_3]))) <= l_2[g_3]), (-1L))) != 0x0EL)) & g_367) < 0xDFF6L) == l_2[g_3]) ^ 0xD8L)) != g_697[8][0]) || 0xE9FEL);
 g_2580
   =
   ((safe_mul_func_int8_t_s_s (((safe_rshift_func_uint8_t_u_u ((l_4279 = l_4274[2]), 6)) & (l_4275 && l_4261)), (g_1810[0] = ((g_555 = ((g_367 = (l_2[g_3] != g_2248)) == ((1UL && ((((g_30 < g_978) & ((l_4286 > g_3) < g_329[1][0][0])) != l_4274[2]) | (-10L))) == 0xDCL))) || l_4266)))) == g_1835[0][1][4]);
 return
   l_4275;
      }
      else
      {
 int32_t
   l_4317
   =
   0x3AC109D8L;
 int32_t
   l_4361
   =
   0L;
 uint32_t
   l_4424
   [1]
   [2];
 int8_t
   l_4442
   =
   1L;
 int
   i,
   j;
 g_71
   [7]
   =
   0xBAC947ACL;
 if ((safe_add_func_uint32_t_u_u (l_4286, g_1382)))
 {
   uint32_t
     l_4295
     [1];
   int16_t
     l_4318
     =
     0x214CL;
   uint8_t
     l_4319
     =
     247UL;
   int32_t
     l_4381
     =
     1L;
   int
     i;
g_71
   [7]
   =
   0xBAC947ACL;
 }
 else
 {
   uint32_t
     l_4384
     =
     5UL;
   int32_t
     l_4405
     [7]
     =
     {
 0L,
 0L,
 0L,
 0L,
 0L,
 0L,
 0L
      };
   int
     i;
   g_300
     =
     0x7825CE2DL;
   if (((safe_mod_func_int8_t_s_s ((safe_add_func_int32_t_s_s ((l_4384 && 5L), (l_4361 = (((1UL > (((((l_4286 | ((l_4276 = (g_513[2] && (g_774 = (safe_mod_func_uint16_t_u_u (((g_30 = (!(safe_mul_func_int8_t_s_s ((safe_add_func_uint8_t_u_u ((l_4266 = (!(+(g_3691 = (((((!(g_1810[0] = 0xEEL)) | (((g_3847 = (l_4273 & ((!l_2[0]) || (safe_lshift_func_uint8_t_u_s (((safe_mul_func_int8_t_s_s (g_866, l_2[g_3])) && l_4277), 7))))) & 3L) >= 0x7CL)) >= (-1L)) >= 65535UL) != (-1L)))))), 0xEAL)), g_2066[5])))) == g_669), g_54))))) < g_1835[0][1][1])) & 0L) > l_4261) || g_3691) <= l_4261)) < l_4317) ^ l_4320[2][2][0])))), l_4384)) >= l_4273))
   {
     int16_t
       l_4404
       =
       0L;
     g_2580
       =
       l_4384;
g_1782
     =
     l_4384;
for
    (i
     =
     0;
     i
     <
     1;
     i++)
    l_2
      [i]
      =
      0x2062L;
   }
   else
   {
     int8_t
       l_4423
       =
       0x6FL;
   }
l_2
      [i]
      =
      0x2062L;
 }
 for
   (l_4279
    =
    0;
    (l_4279
     >=
     (-1));
    l_4279--)
 {
{
    int32_t
      l_4266
      =
      0L;
    int32_t
      l_4273
      =
      1L;
    uint16_t
      l_4286
      =
      0xF524L;
    uint16_t
      l_4445
      =
      9UL;
    int
      i;
    if (func_4 ((l_2[g_3] = func_6 (((0x9869L > (safe_lshift_func_int8_t_s_u (0x5AL, 7))) <= l_2[g_3])))))
    {
      int16_t
 l_4275
 =
 0L;
      int32_t
 l_4281
 =
 0x70A7439CL;
      uint32_t
 l_4320
 [5]
 [4]
 [8]
 =
 {
   {{4294967288UL, 4294967286UL, 0x88591B17L, 0x2DA21B14L, 0xAC8CBD14L, 4294967295UL, 0x3AF223E2L, 0xBB3A348FL}
    ,
    {0x88591B17L,
     0xC53D16DDL,
     0xB212CD3DL,
     6UL,
     0x529B4498L,
     6UL,
     0xB212CD3DL,
     0xC53D16DDL}
    ,
    {0xBD6EE877L,
     0x88591B17L,
     2UL,
     0x60B90E3AL,
     1UL,
     0x2AA60299L,
     0x6B0F5BCEL,
     0x66920C8AL}
    ,
    {0xB212CD3DL,
     0UL,
     0x60B90E3AL,
     0x529B4498L,
     0xBD6EE877L,
     4294967295UL,
     0x6B0F5BCEL,
     4294967292UL}
    }
      , {{0xDA6ED2ABL, 0x529B4498L, 2UL, 0x2AA60299L, 4294967295UL, 0x6B0F5BCEL, 0xB212CD3DL, 0xAC8CBD14L}
  ,
  {4294967295UL,
   0x6B0F5BCEL,
   0xB212CD3DL,
   0xAC8CBD14L,
   0x66920C8AL,
   0xB901ABD4L,
   0x3AF223E2L,
   0x3AF223E2L}
  ,
  {4294967292UL,
   0xBB3A348FL,
   0x88591B17L,
   0x88591B17L,
   0xBB3A348FL,
   4294967292UL,
   0xCE9D9A97L,
   0UL}
  ,
  {0UL,
   0xB40ABE1EL,
   0xBB3A348FL,
   4294967295UL,
   0UL,
   0x2ABDD0F8L,
   0xEE6A9442L,
   0xB212CD3DL}
  }
      , {{0x3AF223E2L, 0xAC8CBD14L, 0x56C35297L, 4294967295UL, 4294967288UL, 0x66920C8AL, 0xB40ABE1EL, 0UL}
  ,
  {0x60B90E3AL,
   4294967288UL,
   4294967286UL,
   0x88591B17L,
   0x2DA21B14L,
   0xAC8CBD14L,
   4294967295UL,
   0x3AF223E2L}
  ,
  {0UL,
   0UL,
   6UL,
   0xAC8CBD14L,
   0xCB0B3A06L,
   4294967286UL,
   0xCB0B3A06L,
   0xAC8CBD14L}
  ,
  {0x529B4498L,
   0UL,
   0x529B4498L,
   0x2AA60299L,
   0UL,
   0xBD6EE877L,
   0x60B90E3AL,
   4294967292UL}
  }
      , {{0x56C35297L, 0UL, 4294967295UL, 0x529B4498L, 0UL, 0xCE9D9A97L, 0UL, 0x66920C8AL}
  ,
  {0x56C35297L,
   0xEE6A9442L,
   0x2DA21B14L,
   0x60B90E3AL,
   0UL,
   1UL,
   2UL,
   0xC53D16DDL}
  ,
  {0x529B4498L,
   0xB901ABD4L,
   0x2ABDD0F8L,
   6UL,
   0xCB0B3A06L,
   0x60B90E3AL,
   0xDA6ED2ABL,
   0xBB3A348FL}
  ,
  {0UL,
   0x2ABDD0F8L,
   4294967288UL,
   0x2DA21B14L,
   0x2DA21B14L,
   4294967288UL,
   0x2ABDD0F8L,
   0UL}
  }
      , {{0x60B90E3AL, 4294967295UL, 0xCB0B3A06L, 0UL, 4294967288UL, 0UL, 4294967286UL, 0x8534AC0FL}
  ,
  {0UL,
   0xC53D16DDL,
   0x3AF223E2L,
   4294967292UL,
   0x6B0F5BCEL,
   4294967295UL,
   0xBD6EE877L,
   0x529B4498L}
  ,
  {0xB901ABD4L,
   0xB212CD3DL,
   0x60B90E3AL,
   0xC53D16DDL,
   0xAC8CBD14L,
   4294967292UL,
   0UL,
   0x8534AC0FL}
  ,
  {0x529B4498L,
   4294967295UL,
   0UL,
   0x56C35297L,
   0x2DA21B14L,
   1UL,
   6UL,
   1UL}
  }
      };
      int32_t
 l_4422
 [7]
 [6];
      int
 i,
        j,
        k;
      for
 (i
  =
  0;
  i
  <
  7;
  i++)
      {
 for
   (j
    =
    0;
    j
    <
    6;
    j++)
   l_4422
     [i]
     [j]
     =
     0L;
      }
      if ((((((((safe_add_func_uint32_t_u_u ((+(safe_rshift_func_uint8_t_u_u (g_866, 7))), g_3350)) || 0xFDL) >= g_2388[1]) & g_3847) < ((((safe_rshift_func_int16_t_s_u (l_2[0], 3)) != ((-1L) <= (safe_sub_func_int8_t_s_s (((0x9BL & l_2[0]) != 0x17L), (-1L))))) | g_1835[0][3][2]) < g_555)) < l_2[g_3]) | g_344))
      {
 int16_t
   l_4274
   [6];
 int32_t
   l_4278
   =
   0L;
 int32_t
   l_4280
   =
   (-1L);
 int
   i;
 for
   (i
    =
    0;
    i
    <
    6;
    i++)
   l_4274
     [i]
     =
     0x0103L;
 for
   (g_588
    =
    0;
    (g_588
     <
     57);
    ++g_588)
 {
   return
     l_2
     [0];
 }
 l_4281
   =
   (((l_4280 = (((((l_4279 = ((safe_mul_func_int8_t_s_s (((l_4278 = (safe_mod_func_uint16_t_u_u ((0x6864FD20L > ((safe_mul_func_uint8_t_u_u (((safe_mul_func_int16_t_s_s (0xAE7EL, 1L)) | (g_71[7] = (safe_add_func_int8_t_s_s ((l_4261 > (l_4273 = ((((safe_lshift_func_uint8_t_u_u ((((0x6E9D4E43L >= (l_4266 = 0xE639630BL)) > ((l_4276 = ((safe_add_func_int16_t_s_s (0x6308L, (safe_lshift_func_uint8_t_u_s (1UL, 2)))) || (((((((safe_add_func_uint16_t_u_u ((((+(g_721[3] != g_1266)) != 4294967289UL) > g_3350), g_697[0][0])) & l_4273) == l_4274[2]) <= g_669) >= g_3847) == l_4275) | g_2004[0][0][2]))) != g_3691)) || l_4274[2]), g_367)) ^ l_4277) && (-6L)) != 65533UL))), g_1835[0][3][2])))), g_2066[7])) <= (-9L))), l_2[g_3]))) <= l_2[g_3]), (-1L))) != 0x0EL)) & g_367) < 0xDFF6L) == l_2[g_3]) ^ 0xD8L)) != g_697[8][0]) || 0xE9FEL);
 g_2580
   =
   ((safe_mul_func_int8_t_s_s (((safe_rshift_func_uint8_t_u_u ((l_4279 = l_4274[2]), 6)) & (l_4275 && l_4261)), (g_1810[0] = ((g_555 = ((g_367 = (l_2[g_3] != g_2248)) == ((1UL && ((((g_30 < g_978) & ((l_4286 > g_3) < g_329[1][0][0])) != l_4274[2]) | (-10L))) == 0xDCL))) || l_4266)))) == g_1835[0][1][4]);
 return
   l_4275;
      }
      else
      {
 int32_t
   l_4317
   =
   0x3AC109D8L;
 int32_t
   l_4361
   =
   0L;
 uint32_t
   l_4424
   [1]
   [2];
 int8_t
   l_4442
   =
   1L;
 int
   i,
   j;
 for
   (i
    =
    0;
    i
    <
    1;
    i++)
 {
   for
     (j
      =
      0;
      j
      <
      2;
      j++)
     l_4424
       [i]
       [j]
       =
       0x36C5A427L;
 }
 g_71
   [7]
   =
   0xBAC947ACL;
 if ((safe_add_func_uint32_t_u_u (l_4286, g_1382)))
 {
   uint32_t
     l_4295
     [1];
   int16_t
     l_4318
     =
     0x214CL;
   uint8_t
     l_4319
     =
     247UL;
   int32_t
     l_4381
     =
     1L;
   int
     i;
   for
     (i
      =
      0;
      i
      <
      1;
      i++)
     l_4295
       [i]
       =
       1UL;
   l_4276
     =
     ((g_367 = ((((l_4275 & ((safe_lshift_func_uint8_t_u_u ((g_1917 = ((g_329[1][3][3] = 0x9418C7CEL) != (((((safe_mul_func_int8_t_s_s ((safe_mul_func_int8_t_s_s (l_4295[0], (g_3350 ^ ((safe_rshift_func_uint8_t_u_s ((safe_add_func_uint16_t_u_u ((safe_add_func_uint32_t_u_u (g_1917, (safe_mul_func_int16_t_s_s ((safe_rshift_func_int16_t_s_u (((((safe_mod_func_int32_t_s_s ((-1L), g_1835[0][3][2])) >= (((safe_mod_func_int8_t_s_s ((safe_sub_func_int8_t_s_s ((safe_lshift_func_int16_t_s_s (((safe_unary_minus_func_int8_t_s ((safe_mul_func_uint16_t_u_u (1UL, g_721[3])))) | l_4317), 10)), 0xAEL)), g_71[0])) == 0x00L) | l_2[g_3])) && g_721[3]) <= l_4318), 8)), l_4319)))), g_669)), 3)) <= l_4317)))), l_4295[0])) >= (-1L)) || l_4276) < g_1917) & 0x6C259E8DL))), l_4320[2][2][0])) < g_721[6])) == l_4317) > g_71[1]) < g_721[8])) > 0L);
   if (((safe_mul_func_uint8_t_u_u (((safe_mul_func_int8_t_s_s ((((safe_mul_func_int8_t_s_s (((safe_mul_func_uint16_t_u_u ((g_71[3] <= (g_2004[0][0][2] || (0x6DL < (4UL == ((l_4273 = 0UL) || l_4279))))), l_4320[2][2][0])) & ((g_1763 = (g_71[0] && (safe_rshift_func_uint16_t_u_u ((safe_lshift_func_uint8_t_u_s (g_3350, l_4275)), g_367)))) <= g_2373)), g_3)) != 0x5D92F532L) != 1UL), g_2004[0][0][2])) | g_2004[0][0][2]), 0x3DL)) >= l_4277))
   {
     if (g_588)
       break;
   }
   else
   {
     uint8_t
       l_4362
       =
       0x63L;
     int32_t
       l_4383
       =
       (-8L);
     l_4266
       =
       (safe_lshift_func_uint16_t_u_u
        ((((l_4361 = ((safe_mul_func_uint16_t_u_u (((safe_add_func_uint32_t_u_u ((safe_mul_func_uint8_t_u_u (0xC5L, (safe_mul_func_int16_t_s_s (g_697[1][0], (l_4319 || (safe_add_func_uint32_t_u_u (l_4295[0], ((65527UL >= (safe_sub_func_uint32_t_u_u (g_669, ((safe_mul_func_uint16_t_u_u (((g_458 && (safe_add_func_int32_t_s_s ((l_2[0] || (safe_rshift_func_uint8_t_u_s ((safe_mul_func_uint16_t_u_u ((g_30 = (~((g_1835[0][3][2] = (g_2065 = (safe_add_func_int16_t_s_s ((safe_sub_func_int32_t_s_s (((0x452A9AFDL ^ 0xEB54E6E3L) | 0xB4L), g_2066[7])), 0x84BFL)))) == l_2[g_3]))), 0L)), 5))), g_329[1][4][3]))) == g_588), l_4286)) >= 65527UL)))) & g_1281)))))))), 0x3CA1605AL)) >= (-10L)), 9L)) ^ g_1281)) ^ (-1L)) || l_4362), 12));
     l_4273
       =
       ((safe_mul_func_uint8_t_u_u (l_4317, (((((l_4383 = (safe_mod_func_int8_t_s_s (((4294967289UL < ((((((g_1995 <= (safe_sub_func_uint8_t_u_u ((l_4317 && (g_513[1] = ((g_513[5] ^ (l_4381 = ((safe_sub_func_uint8_t_u_u (g_2004[1][0][0], (0x78L != 0x7BL))) < (safe_mod_func_uint8_t_u_u (((safe_lshift_func_uint16_t_u_s (((safe_mod_func_int32_t_s_s ((safe_mul_func_uint8_t_u_u ((g_71[7] >= g_1281), l_4295[0])), g_3350)) <= g_329[1][0][0]), 7)) && l_4266), g_30))))) > l_4261))), g_71[3]))) < g_2066[7]) || l_4382) != l_4362) || g_1995) != 1L)) ^ 0x93AA5932L), g_697[3][1]))) == 0x63DC3EFBL) <= l_4320[0][1][4]) || 1L) != l_4362))) > 0x9FL);
   }
 }
 else
 {
   uint32_t
     l_4384
     =
     5UL;
   int32_t
     l_4405
     [7]
     =
     {
 0L,
 0L,
 0L,
 0L,
 0L,
 0L,
 0L
      };
   int
     i;
   g_1782
     =
     l_4384;
   g_300
     =
     0x7825CE2DL;
   if (((safe_mod_func_int8_t_s_s ((safe_add_func_int32_t_s_s ((l_4384 && 5L), (l_4361 = (((1UL > (((((l_4286 | ((l_4276 = (g_513[2] && (g_774 = (safe_mod_func_uint16_t_u_u (((g_30 = (!(safe_mul_func_int8_t_s_s ((safe_add_func_uint8_t_u_u ((l_4266 = (!(+(g_3691 = (((((!(g_1810[0] = 0xEEL)) | (((g_3847 = (l_4273 & ((!l_2[0]) || (safe_lshift_func_uint8_t_u_s (((safe_mul_func_int8_t_s_s (g_866, l_2[g_3])) && l_4277), 7))))) & 3L) >= 0x7CL)) >= (-1L)) >= 65535UL) != (-1L)))))), 0xEAL)), g_2066[5])))) == g_669), g_54))))) < g_1835[0][1][1])) & 0L) > l_4261) || g_3691) <= l_4261)) < l_4317) ^ l_4320[2][2][0])))), l_4384)) >= l_4273))
   {
     int16_t
       l_4404
       =
       0L;
     g_2580
       =
       l_4384;
     l_4405
       [1]
       =
       (safe_rshift_func_uint16_t_u_u
        ((g_201 != (g_71[3] = (0x482E6DD3L == (g_4401 >= (l_4404 = (safe_lshift_func_uint16_t_u_u (l_4277, 7))))))), 10));
     if (g_3847)
       break;
   }
   else
   {
     int8_t
       l_4423
       =
       0x6FL;
     l_4424
       [0]
       [1]
       =
       ((((!(g_2388[1] & l_4320[2][2][0])) < (!(1L > (l_2[0] | ((safe_lshift_func_uint16_t_u_s ((safe_rshift_func_uint16_t_u_u (l_4281, 13)), (g_555 = (g_697[3][0] = (-1L))))) && ((safe_rshift_func_uint8_t_u_s ((safe_unary_minus_func_uint8_t_u ((safe_lshift_func_int8_t_s_u ((safe_mul_func_uint8_t_u_u (((safe_unary_minus_func_int8_t_s (((safe_add_func_int16_t_s_s (((l_2[g_3] && (((safe_mod_func_int16_t_s_s (g_1782, (g_697[8][0] && g_1917))) || l_4320[2][1][7]) <= l_4422[2][1])) == 1L), 0xF6F6L)) > 0x1AL))) <= 0x2E30L), 5L)), 3)))), g_3350)) == l_4423)))))) || g_658) || 0xA9L);
   }
 }
 for
   (l_4279
    =
    0;
    (l_4279
     >=
     (-1));
    l_4279--)
 {
   for
     (g_3117
      =
      3;
      (g_3117
       >=
       0);
      g_3117
      -=
      1)
   {
     int
       i,
       j,
       k;
     if (l_4320[(g_3117 + 1)][(g_3 + 1)][(g_3117 + 3)])
       break;
   }
 }
 for
   (l_4382
    =
    (-16);
    (l_4382
     <=
     (-18));
    --l_4382)
 {
   int16_t
     l_4431
     =
     0xF66EL;
   int32_t
     l_4436
     =
     (-1L);
   int32_t
     l_4439
     [9]
     =
     {
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L
      };
   int
     i;
   if (g_721[3])
     break;
   g_71
     [6]
     =
     ((safe_mul_func_int8_t_s_s ((((g_1265[0][4] || (((l_4431 = g_2004[0][0][2]) < ((safe_mod_func_uint32_t_u_u (g_2004[6][0][8], ((safe_add_func_uint8_t_u_u (((l_4436 = ((((l_4436 > (g_344 = (safe_mod_func_int16_t_s_s (((g_2065 = g_2066[7]) >= (g_30 = (l_4275 ^ 0xF27072F1L))), g_2388[0])))) < (g_658 || l_4436)) <= 0xFBL) == l_4424[0][1])) >= 4294967295UL), g_920)) || 0x4EL))) ^ l_4424[0][0])) >= l_4424[0][0])) > l_4439[8]) && l_4439[2]), l_4261)) > g_1782);
   g_71
     [4]
     =
     (l_4439
      [8]
      =
      (g_555
       &
       (l_4361
        =
        0x9DL)));
   l_4361
     =
     (g_38
      !=
      (safe_lshift_func_int16_t_s_s
       (((((0xC4L != ((((g_1810[0] | (g_3691 = (((l_4431 != g_3350) & (l_4442 = l_4266)) >= g_367))) < (0x4EL || ((safe_mod_func_uint32_t_u_u ((((((l_4320[4][3][3] == g_1266) > 0xCADD5B35L) | 0x35L) < l_4439[8]) ^ g_521), 0x7A1165F3L)) && 0x5BA991B8L))) | l_4424[0][1]) || l_4431)) <= 0UL) || l_4422[2][1]) ^ g_3117), l_4445)));
 }
      }
      l_4276
 =
 (l_4279
  =
  (safe_rshift_func_uint8_t_u_s
   (((4294967290UL <= (~(l_4422[3][0] = 0xABC520E7L))) || g_513[1]), 5)));
      l_4281
 =
 (g_71
  [0]
  =
  ((safe_mod_func_int32_t_s_s ((safe_mul_func_uint8_t_u_u ((safe_sub_func_int8_t_s_s ((l_4276 = (+((l_4422[2][2] = 0xDFL) <= (g_3 != ((g_1810[0] = (!(safe_mul_func_int16_t_s_s (g_458, (safe_rshift_func_int8_t_s_u (l_4320[2][2][3], (g_1382 && ((safe_rshift_func_uint16_t_u_s ((((g_2388[1] < (l_4276 <= (((g_1266 != (((g_300 = ((~0x5AD8L) <= 0x15E9L)) | 1L) == g_555)) > g_3) & 1UL))) >= g_4460) == l_4286), g_2004[0][0][2])) == 0xCDL)))))))) == 5UL))))), g_1917)), l_4281)), g_1835[0][3][2])) | g_1835[0][3][2]));
    }
    else
    {
      int32_t
 l_4475
 [3]
 [3]
 =
 {
    {(-1L), (-1L), (-1L)}
      , {(-1L), (-1L), (-1L)}
      , {(-1L), (-1L), (-1L)}
      };
      int32_t
 l_4481
 =
 0x766BB33FL;
      int
 i,
        j;
      if (((safe_sub_func_uint32_t_u_u ((((safe_sub_func_int8_t_s_s ((((safe_sub_func_uint16_t_u_u (g_201, (((1UL >= (safe_lshift_func_int16_t_s_s ((((((safe_sub_func_int8_t_s_s (l_4276, (0x5CE5838AL && 0xCE452925L))) == (safe_lshift_func_uint8_t_u_s ((l_4475[0][1] = (safe_rshift_func_uint8_t_u_u (l_4279, 3))), 0))) || (+(g_2004[0][0][2] = ((((((safe_sub_func_uint32_t_u_u ((l_4277 & ((!9L) & (safe_mul_func_uint8_t_u_u ((l_4286 & 0x5751L), l_4475[1][1])))), l_4445)) || g_697[8][0]) & l_4266) && g_329[1][0][0]) < 0x75L) | 0x94EC5207L)))) > 0xC7L) >= g_697[8][0]), 7))) < g_367) != g_2066[7]))) == 0xA6E1DCAAL) > l_4480), 0x6DL)) | l_4481) || 65535UL), l_4445)) < l_4481))
      {
 l_4481
   =
   (-6L);
      }
      else
      {
 int16_t
   l_4488
   =
   (-6L);
 uint16_t
   l_4514
   =
   0x3C3CL;
 g_71
   [0]
   =
   0x98671147L;
 for
   (g_1782
    =
    0;
    (g_1782
     <=
     1);
    g_1782
    +=
    1)
 {
   for
     (g_3691
      =
      0;
      (g_3691
       <=
       1);
      g_3691
      +=
      1)
   {
     int
       i,
       j;
     g_2580
       =
       g_697
       [(g_3691 + 5)][(g_3 + 1)];
   }
 }
 l_4514
   =
   ((g_1835[0][3][1] = (safe_lshift_func_int8_t_s_s (((safe_mul_func_int16_t_s_s (((1L > (safe_mul_func_int16_t_s_s ((((~l_4488) <= (safe_sub_func_uint32_t_u_u ((0UL && g_697[8][0]), l_4480))) && ((+(safe_lshift_func_int8_t_s_u ((safe_rshift_func_int16_t_s_s ((safe_mul_func_int16_t_s_s ((safe_mul_func_uint8_t_u_u ((((((((safe_mul_func_uint8_t_u_u (((safe_lshift_func_int16_t_s_s (((safe_lshift_func_uint8_t_u_u (((safe_add_func_int8_t_s_s ((~((safe_mod_func_uint16_t_u_u (65526UL, ((((g_930 = (safe_rshift_func_uint8_t_u_s (0x7BL, 4))) && ((g_697[8][0] = l_4475[0][1]) <= (g_1782 && 0x74L))) ^ 0x2DF3L) || l_4511))) < l_4488)), g_555)) >= g_30), 5)) & 4294967295UL), 3)) >= g_1995), g_4460)) & g_978) || l_4273) || 1L) != 0UL) || g_2248) | 0x6D007995L), l_4488)), g_4512)), l_4513)), g_721[3]))) < 4294967295UL)), l_4488))) != g_329[1][3][2]), l_4266)) >= g_721[3]), g_1810[0]))) | (-3L));
      }
      g_1763
 =
 (safe_mod_func_uint32_t_u_u
  ((safe_mul_func_uint16_t_u_u (65527UL, g_1266)), (l_4276 = (safe_lshift_func_int8_t_s_u (((((4UL | (safe_mod_func_int16_t_s_s ((safe_sub_func_int16_t_s_s ((safe_lshift_func_int8_t_s_s ((g_930 = (g_1917 <= (g_2580 = ((g_1810[0] ^ (safe_mod_func_int8_t_s_s (g_2617, (safe_mod_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s ((g_1835[0][3][2] || 4294967292UL), (l_4279 = (g_2065 ^ g_1917)))), g_1835[0][3][2]))))) <= 0xFDL)))), g_721[1])), 0xD457L)), g_2004[0][0][2]))) || 2UL) < g_3117) == l_4382), 0)))));
      g_2580
 =
 (((safe_lshift_func_int8_t_s_u ((safe_add_func_uint16_t_u_u (((safe_unary_minus_func_int8_t_s ((g_344 = g_2580))) <= (safe_sub_func_uint8_t_u_u (l_4475[1][2], (g_513[1] != (safe_sub_func_uint32_t_u_u (3UL, (0xBCC5178AL < (((safe_add_func_uint32_t_u_u ((safe_sub_func_int8_t_s_s ((~0xC3L), (safe_lshift_func_uint16_t_u_s (g_669, 1)))), (safe_mul_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_u ((safe_add_func_uint16_t_u_u ((g_30 = l_4475[1][0]), ((g_588 ^ g_930) || 1UL))), g_71[7])), 0xEFL)))) == l_2[g_3]) != g_71[7])))))))), l_4480)), 1)) && g_1281) >= l_4480);
      l_4279
 =
 l_4513;
    }
  }
 }
{
      int16_t
 l_4275
 =
 0L;
      int32_t
 l_4281
 =
 0x70A7439CL;
      uint32_t
 l_4320
 [5]
 [4]
 [8]
 =
 {
   {{4294967288UL, 4294967286UL, 0x88591B17L, 0x2DA21B14L, 0xAC8CBD14L, 4294967295UL, 0x3AF223E2L, 0xBB3A348FL}
    ,
    {0x88591B17L,
     0xC53D16DDL,
     0xB212CD3DL,
     6UL,
     0x529B4498L,
     6UL,
     0xB212CD3DL,
     0xC53D16DDL}
    ,
    {0xBD6EE877L,
     0x88591B17L,
     2UL,
     0x60B90E3AL,
     1UL,
     0x2AA60299L,
     0x6B0F5BCEL,
     0x66920C8AL}
    ,
    {0xB212CD3DL,
     0UL,
     0x60B90E3AL,
     0x529B4498L,
     0xBD6EE877L,
     4294967295UL,
     0x6B0F5BCEL,
     4294967292UL}
    }
      , {{0xDA6ED2ABL, 0x529B4498L, 2UL, 0x2AA60299L, 4294967295UL, 0x6B0F5BCEL, 0xB212CD3DL, 0xAC8CBD14L}
  ,
  {4294967295UL,
   0x6B0F5BCEL,
   0xB212CD3DL,
   0xAC8CBD14L,
   0x66920C8AL,
   0xB901ABD4L,
   0x3AF223E2L,
   0x3AF223E2L}
  ,
  {4294967292UL,
   0xBB3A348FL,
   0x88591B17L,
   0x88591B17L,
   0xBB3A348FL,
   4294967292UL,
   0xCE9D9A97L,
   0UL}
  ,
  {0UL,
   0xB40ABE1EL,
   0xBB3A348FL,
   4294967295UL,
   0UL,
   0x2ABDD0F8L,
   0xEE6A9442L,
   0xB212CD3DL}
  }
      , {{0x3AF223E2L, 0xAC8CBD14L, 0x56C35297L, 4294967295UL, 4294967288UL, 0x66920C8AL, 0xB40ABE1EL, 0UL}
  ,
  {0x60B90E3AL,
   4294967288UL,
   4294967286UL,
   0x88591B17L,
   0x2DA21B14L,
   0xAC8CBD14L,
   4294967295UL,
   0x3AF223E2L}
  ,
  {0UL,
   0UL,
   6UL,
   0xAC8CBD14L,
   0xCB0B3A06L,
   4294967286UL,
   0xCB0B3A06L,
   0xAC8CBD14L}
  ,
  {0x529B4498L,
   0UL,
   0x529B4498L,
   0x2AA60299L,
   0UL,
   0xBD6EE877L,
   0x60B90E3AL,
   4294967292UL}
  }
      , {{0x56C35297L, 0UL, 4294967295UL, 0x529B4498L, 0UL, 0xCE9D9A97L, 0UL, 0x66920C8AL}
  ,
  {0x56C35297L,
   0xEE6A9442L,
   0x2DA21B14L,
   0x60B90E3AL,
   0UL,
   1UL,
   2UL,
   0xC53D16DDL}
  ,
  {0x529B4498L,
   0xB901ABD4L,
   0x2ABDD0F8L,
   6UL,
   0xCB0B3A06L,
   0x60B90E3AL,
   0xDA6ED2ABL,
   0xBB3A348FL}
  ,
  {0UL,
   0x2ABDD0F8L,
   4294967288UL,
   0x2DA21B14L,
   0x2DA21B14L,
   4294967288UL,
   0x2ABDD0F8L,
   0UL}
  }
      , {{0x60B90E3AL, 4294967295UL, 0xCB0B3A06L, 0UL, 4294967288UL, 0UL, 4294967286UL, 0x8534AC0FL}
  ,
  {0UL,
   0xC53D16DDL,
   0x3AF223E2L,
   4294967292UL,
   0x6B0F5BCEL,
   4294967295UL,
   0xBD6EE877L,
   0x529B4498L}
  ,
  {0xB901ABD4L,
   0xB212CD3DL,
   0x60B90E3AL,
   0xC53D16DDL,
   0xAC8CBD14L,
   4294967292UL,
   0UL,
   0x8534AC0FL}
  ,
  {0x529B4498L,
   4294967295UL,
   0UL,
   0x56C35297L,
   0x2DA21B14L,
   1UL,
   6UL,
   1UL}
  }
      };
      int32_t
 l_4422
 [7]
 [6];
      int
 i,
        j,
        k;
      for
 (i
  =
  0;
  i
  <
  7;
  i++)
      {
 for
   (j
    =
    0;
    j
    <
    6;
    j++)
   l_4422
     [i]
     [j]
     =
     0L;
      }
      if ((((((((safe_add_func_uint32_t_u_u ((+(safe_rshift_func_uint8_t_u_u (g_866, 7))), g_3350)) || 0xFDL) >= g_2388[1]) & g_3847) < ((((safe_rshift_func_int16_t_s_u (l_2[0], 3)) != ((-1L) <= (safe_sub_func_int8_t_s_s (((0x9BL & l_2[0]) != 0x17L), (-1L))))) | g_1835[0][3][2]) < g_555)) < l_2[g_3]) | g_344))
      {
 int16_t
   l_4274
   [6];
 int32_t
   l_4278
   =
   0L;
 int32_t
   l_4280
   =
   (-1L);
 int
   i;
 for
   (i
    =
    0;
    i
    <
    6;
    i++)
   l_4274
     [i]
     =
     0x0103L;
 for
   (g_588
    =
    0;
    (g_588
     <
     57);
    ++g_588)
 {
   return
     l_2
     [0];
 }
 l_4281
   =
   (((l_4280 = (((((l_4279 = ((safe_mul_func_int8_t_s_s (((l_4278 = (safe_mod_func_uint16_t_u_u ((0x6864FD20L > ((safe_mul_func_uint8_t_u_u (((safe_mul_func_int16_t_s_s (0xAE7EL, 1L)) | (g_71[7] = (safe_add_func_int8_t_s_s ((l_4261 > (l_4273 = ((((safe_lshift_func_uint8_t_u_u ((((0x6E9D4E43L >= (l_4266 = 0xE639630BL)) > ((l_4276 = ((safe_add_func_int16_t_s_s (0x6308L, (safe_lshift_func_uint8_t_u_s (1UL, 2)))) || (((((((safe_add_func_uint16_t_u_u ((((+(g_721[3] != g_1266)) != 4294967289UL) > g_3350), g_697[0][0])) & l_4273) == l_4274[2]) <= g_669) >= g_3847) == l_4275) | g_2004[0][0][2]))) != g_3691)) || l_4274[2]), g_367)) ^ l_4277) && (-6L)) != 65533UL))), g_1835[0][3][2])))), g_2066[7])) <= (-9L))), l_2[g_3]))) <= l_2[g_3]), (-1L))) != 0x0EL)) & g_367) < 0xDFF6L) == l_2[g_3]) ^ 0xD8L)) != g_697[8][0]) || 0xE9FEL);
 g_2580
   =
   ((safe_mul_func_int8_t_s_s (((safe_rshift_func_uint8_t_u_u ((l_4279 = l_4274[2]), 6)) & (l_4275 && l_4261)), (g_1810[0] = ((g_555 = ((g_367 = (l_2[g_3] != g_2248)) == ((1UL && ((((g_30 < g_978) & ((l_4286 > g_3) < g_329[1][0][0])) != l_4274[2]) | (-10L))) == 0xDCL))) || l_4266)))) == g_1835[0][1][4]);
 return
   l_4275;
      }
      else
      {
 int32_t
   l_4317
   =
   0x3AC109D8L;
 int32_t
   l_4361
   =
   0L;
 uint32_t
   l_4424
   [1]
   [2];
 int8_t
   l_4442
   =
   1L;
 int
   i,
   j;
 for
   (i
    =
    0;
    i
    <
    1;
    i++)
 {
   for
     (j
      =
      0;
      j
      <
      2;
      j++)
     l_4424
       [i]
       [j]
       =
       0x36C5A427L;
 }
 g_71
   [7]
   =
   0xBAC947ACL;
 if ((safe_add_func_uint32_t_u_u (l_4286, g_1382)))
 {
   uint32_t
     l_4295
     [1];
   int16_t
     l_4318
     =
     0x214CL;
   uint8_t
     l_4319
     =
     247UL;
   int32_t
     l_4381
     =
     1L;
   int
     i;
   for
     (i
      =
      0;
      i
      <
      1;
      i++)
     l_4295
       [i]
       =
       1UL;
   l_4276
     =
     ((g_367 = ((((l_4275 & ((safe_lshift_func_uint8_t_u_u ((g_1917 = ((g_329[1][3][3] = 0x9418C7CEL) != (((((safe_mul_func_int8_t_s_s ((safe_mul_func_int8_t_s_s (l_4295[0], (g_3350 ^ ((safe_rshift_func_uint8_t_u_s ((safe_add_func_uint16_t_u_u ((safe_add_func_uint32_t_u_u (g_1917, (safe_mul_func_int16_t_s_s ((safe_rshift_func_int16_t_s_u (((((safe_mod_func_int32_t_s_s ((-1L), g_1835[0][3][2])) >= (((safe_mod_func_int8_t_s_s ((safe_sub_func_int8_t_s_s ((safe_lshift_func_int16_t_s_s (((safe_unary_minus_func_int8_t_s ((safe_mul_func_uint16_t_u_u (1UL, g_721[3])))) | l_4317), 10)), 0xAEL)), g_71[0])) == 0x00L) | l_2[g_3])) && g_721[3]) <= l_4318), 8)), l_4319)))), g_669)), 3)) <= l_4317)))), l_4295[0])) >= (-1L)) || l_4276) < g_1917) & 0x6C259E8DL))), l_4320[2][2][0])) < g_721[6])) == l_4317) > g_71[1]) < g_721[8])) > 0L);
   if (((safe_mul_func_uint8_t_u_u (((safe_mul_func_int8_t_s_s ((((safe_mul_func_int8_t_s_s (((safe_mul_func_uint16_t_u_u ((g_71[3] <= (g_2004[0][0][2] || (0x6DL < (4UL == ((l_4273 = 0UL) || l_4279))))), l_4320[2][2][0])) & ((g_1763 = (g_71[0] && (safe_rshift_func_uint16_t_u_u ((safe_lshift_func_uint8_t_u_s (g_3350, l_4275)), g_367)))) <= g_2373)), g_3)) != 0x5D92F532L) != 1UL), g_2004[0][0][2])) | g_2004[0][0][2]), 0x3DL)) >= l_4277))
   {
     if (g_588)
       break;
   }
   else
   {
     uint8_t
       l_4362
       =
       0x63L;
     int32_t
       l_4383
       =
       (-8L);
     l_4266
       =
       (safe_lshift_func_uint16_t_u_u
        ((((l_4361 = ((safe_mul_func_uint16_t_u_u (((safe_add_func_uint32_t_u_u ((safe_mul_func_uint8_t_u_u (0xC5L, (safe_mul_func_int16_t_s_s (g_697[1][0], (l_4319 || (safe_add_func_uint32_t_u_u (l_4295[0], ((65527UL >= (safe_sub_func_uint32_t_u_u (g_669, ((safe_mul_func_uint16_t_u_u (((g_458 && (safe_add_func_int32_t_s_s ((l_2[0] || (safe_rshift_func_uint8_t_u_s ((safe_mul_func_uint16_t_u_u ((g_30 = (~((g_1835[0][3][2] = (g_2065 = (safe_add_func_int16_t_s_s ((safe_sub_func_int32_t_s_s (((0x452A9AFDL ^ 0xEB54E6E3L) | 0xB4L), g_2066[7])), 0x84BFL)))) == l_2[g_3]))), 0L)), 5))), g_329[1][4][3]))) == g_588), l_4286)) >= 65527UL)))) & g_1281)))))))), 0x3CA1605AL)) >= (-10L)), 9L)) ^ g_1281)) ^ (-1L)) || l_4362), 12));
     l_4273
       =
       ((safe_mul_func_uint8_t_u_u (l_4317, (((((l_4383 = (safe_mod_func_int8_t_s_s (((4294967289UL < ((((((g_1995 <= (safe_sub_func_uint8_t_u_u ((l_4317 && (g_513[1] = ((g_513[5] ^ (l_4381 = ((safe_sub_func_uint8_t_u_u (g_2004[1][0][0], (0x78L != 0x7BL))) < (safe_mod_func_uint8_t_u_u (((safe_lshift_func_uint16_t_u_s (((safe_mod_func_int32_t_s_s ((safe_mul_func_uint8_t_u_u ((g_71[7] >= g_1281), l_4295[0])), g_3350)) <= g_329[1][0][0]), 7)) && l_4266), g_30))))) > l_4261))), g_71[3]))) < g_2066[7]) || l_4382) != l_4362) || g_1995) != 1L)) ^ 0x93AA5932L), g_697[3][1]))) == 0x63DC3EFBL) <= l_4320[0][1][4]) || 1L) != l_4362))) > 0x9FL);
   }
 }
 else
 {
   uint32_t
     l_4384
     =
     5UL;
   int32_t
     l_4405
     [7]
     =
     {
 0L,
 0L,
 0L,
 0L,
 0L,
 0L,
 0L
      };
   int
     i;
   g_1782
     =
     l_4384;
   g_300
     =
     0x7825CE2DL;
   if (((safe_mod_func_int8_t_s_s ((safe_add_func_int32_t_s_s ((l_4384 && 5L), (l_4361 = (((1UL > (((((l_4286 | ((l_4276 = (g_513[2] && (g_774 = (safe_mod_func_uint16_t_u_u (((g_30 = (!(safe_mul_func_int8_t_s_s ((safe_add_func_uint8_t_u_u ((l_4266 = (!(+(g_3691 = (((((!(g_1810[0] = 0xEEL)) | (((g_3847 = (l_4273 & ((!l_2[0]) || (safe_lshift_func_uint8_t_u_s (((safe_mul_func_int8_t_s_s (g_866, l_2[g_3])) && l_4277), 7))))) & 3L) >= 0x7CL)) >= (-1L)) >= 65535UL) != (-1L)))))), 0xEAL)), g_2066[5])))) == g_669), g_54))))) < g_1835[0][1][1])) & 0L) > l_4261) || g_3691) <= l_4261)) < l_4317) ^ l_4320[2][2][0])))), l_4384)) >= l_4273))
   {
     int16_t
       l_4404
       =
       0L;
     g_2580
       =
       l_4384;
     l_4405
       [1]
       =
       (safe_rshift_func_uint16_t_u_u
        ((g_201 != (g_71[3] = (0x482E6DD3L == (g_4401 >= (l_4404 = (safe_lshift_func_uint16_t_u_u (l_4277, 7))))))), 10));
     if (g_3847)
       break;
   }
   else
   {
     int8_t
       l_4423
       =
       0x6FL;
     l_4424
       [0]
       [1]
       =
       ((((!(g_2388[1] & l_4320[2][2][0])) < (!(1L > (l_2[0] | ((safe_lshift_func_uint16_t_u_s ((safe_rshift_func_uint16_t_u_u (l_4281, 13)), (g_555 = (g_697[3][0] = (-1L))))) && ((safe_rshift_func_uint8_t_u_s ((safe_unary_minus_func_uint8_t_u ((safe_lshift_func_int8_t_s_u ((safe_mul_func_uint8_t_u_u (((safe_unary_minus_func_int8_t_s (((safe_add_func_int16_t_s_s (((l_2[g_3] && (((safe_mod_func_int16_t_s_s (g_1782, (g_697[8][0] && g_1917))) || l_4320[2][1][7]) <= l_4422[2][1])) == 1L), 0xF6F6L)) > 0x1AL))) <= 0x2E30L), 5L)), 3)))), g_3350)) == l_4423)))))) || g_658) || 0xA9L);
   }
 }
 for
   (l_4279
    =
    0;
    (l_4279
     >=
     (-1));
    l_4279--)
 {
   for
     (g_3117
      =
      3;
      (g_3117
       >=
       0);
      g_3117
      -=
      1)
   {
     int
       i,
       j,
       k;
     if (l_4320[(g_3117 + 1)][(g_3 + 1)][(g_3117 + 3)])
       break;
   }
 }
 for
   (l_4382
    =
    (-16);
    (l_4382
     <=
     (-18));
    --l_4382)
 {
   int16_t
     l_4431
     =
     0xF66EL;
   int32_t
     l_4436
     =
     (-1L);
   int32_t
     l_4439
     [9]
     =
     {
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L
      };
   int
     i;
   if (g_721[3])
     break;
   g_71
     [6]
     =
     ((safe_mul_func_int8_t_s_s ((((g_1265[0][4] || (((l_4431 = g_2004[0][0][2]) < ((safe_mod_func_uint32_t_u_u (g_2004[6][0][8], ((safe_add_func_uint8_t_u_u (((l_4436 = ((((l_4436 > (g_344 = (safe_mod_func_int16_t_s_s (((g_2065 = g_2066[7]) >= (g_30 = (l_4275 ^ 0xF27072F1L))), g_2388[0])))) < (g_658 || l_4436)) <= 0xFBL) == l_4424[0][1])) >= 4294967295UL), g_920)) || 0x4EL))) ^ l_4424[0][0])) >= l_4424[0][0])) > l_4439[8]) && l_4439[2]), l_4261)) > g_1782);
   g_71
     [4]
     =
     (l_4439
      [8]
      =
      (g_555
       &
       (l_4361
        =
        0x9DL)));
   l_4361
     =
     (g_38
      !=
      (safe_lshift_func_int16_t_s_s
       (((((0xC4L != ((((g_1810[0] | (g_3691 = (((l_4431 != g_3350) & (l_4442 = l_4266)) >= g_367))) < (0x4EL || ((safe_mod_func_uint32_t_u_u ((((((l_4320[4][3][3] == g_1266) > 0xCADD5B35L) | 0x35L) < l_4439[8]) ^ g_521), 0x7A1165F3L)) && 0x5BA991B8L))) | l_4424[0][1]) || l_4431)) <= 0UL) || l_4422[2][1]) ^ g_3117), l_4445)));
 }
      }
      l_4276
 =
 (l_4279
  =
  (safe_rshift_func_uint8_t_u_s
   (((4294967290UL <= (~(l_4422[3][0] = 0xABC520E7L))) || g_513[1]), 5)));
      l_4281
 =
 (g_71
  [0]
  =
  ((safe_mod_func_int32_t_s_s ((safe_mul_func_uint8_t_u_u ((safe_sub_func_int8_t_s_s ((l_4276 = (+((l_4422[2][2] = 0xDFL) <= (g_3 != ((g_1810[0] = (!(safe_mul_func_int16_t_s_s (g_458, (safe_rshift_func_int8_t_s_u (l_4320[2][2][3], (g_1382 && ((safe_rshift_func_uint16_t_u_s ((((g_2388[1] < (l_4276 <= (((g_1266 != (((g_300 = ((~0x5AD8L) <= 0x15E9L)) | 1L) == g_555)) > g_3) & 1UL))) >= g_4460) == l_4286), g_2004[0][0][2])) == 0xCDL)))))))) == 5UL))))), g_1917)), l_4281)), g_1835[0][3][2])) | g_1835[0][3][2]));
    }
      }
      l_4276
 =
 (l_4279
  =
  (safe_rshift_func_uint8_t_u_s
   (((4294967290UL <= (~(l_4422[3][0] = 0xABC520E7L))) || g_513[1]), 5)));
      l_4281
 =
 (g_71
  [0]
  =
  ((safe_mod_func_int32_t_s_s ((safe_mul_func_uint8_t_u_u ((safe_sub_func_int8_t_s_s ((l_4276 = (+((l_4422[2][2] = 0xDFL) <= (g_3 != ((g_1810[0] = (!(safe_mul_func_int16_t_s_s (g_458, (safe_rshift_func_int8_t_s_u (l_4320[2][2][3], (g_1382 && ((safe_rshift_func_uint16_t_u_s ((((g_2388[1] < (l_4276 <= (((g_1266 != (((g_300 = ((~0x5AD8L) <= 0x15E9L)) | 1L) == g_555)) > g_3) & 1UL))) >= g_4460) == l_4286), g_2004[0][0][2])) == 0xCDL)))))))) == 5UL))))), g_1917)), l_4281)), g_1835[0][3][2])) | g_1835[0][3][2]));
    }
    else
    {
      int32_t
 l_4475
 [3]
 [3]
 =
 {
    {(-1L), (-1L), (-1L)}
      , {(-1L), (-1L), (-1L)}
      , {(-1L), (-1L), (-1L)}
      };
      int32_t
 l_4481
 =
 0x766BB33FL;
      int
 i,
        j;
      if (((safe_sub_func_uint32_t_u_u ((((safe_sub_func_int8_t_s_s ((((safe_sub_func_uint16_t_u_u (g_201, (((1UL >= (safe_lshift_func_int16_t_s_s ((((((safe_sub_func_int8_t_s_s (l_4276, (0x5CE5838AL && 0xCE452925L))) == (safe_lshift_func_uint8_t_u_s ((l_4475[0][1] = (safe_rshift_func_uint8_t_u_u (l_4279, 3))), 0))) || (+(g_2004[0][0][2] = ((((((safe_sub_func_uint32_t_u_u ((l_4277 & ((!9L) & (safe_mul_func_uint8_t_u_u ((l_4286 & 0x5751L), l_4475[1][1])))), l_4445)) || g_697[8][0]) & l_4266) && g_329[1][0][0]) < 0x75L) | 0x94EC5207L)))) > 0xC7L) >= g_697[8][0]), 7))) < g_367) != g_2066[7]))) == 0xA6E1DCAAL) > l_4480), 0x6DL)) | l_4481) || 65535UL), l_4445)) < l_4481))
      {
      }
      else
      {
 int16_t
   l_4488
   =
   (-6L);
 uint16_t
   l_4514
   =
   0x3C3CL;
 g_71
   [0]
   =
   0x98671147L;
 l_4514
   =
   ((g_1835[0][3][1] = (safe_lshift_func_int8_t_s_s (((safe_mul_func_int16_t_s_s (((1L > (safe_mul_func_int16_t_s_s ((((~l_4488) <= (safe_sub_func_uint32_t_u_u ((0UL && g_697[8][0]), l_4480))) && ((+(safe_lshift_func_int8_t_s_u ((safe_rshift_func_int16_t_s_s ((safe_mul_func_int16_t_s_s ((safe_mul_func_uint8_t_u_u ((((((((safe_mul_func_uint8_t_u_u (((safe_lshift_func_int16_t_s_s (((safe_lshift_func_uint8_t_u_u (((safe_add_func_int8_t_s_s ((~((safe_mod_func_uint16_t_u_u (65526UL, ((((g_930 = (safe_rshift_func_uint8_t_u_s (0x7BL, 4))) && ((g_697[8][0] = l_4475[0][1]) <= (g_1782 && 0x74L))) ^ 0x2DF3L) || l_4511))) < l_4488)), g_555)) >= g_30), 5)) & 4294967295UL), 3)) >= g_1995), g_4460)) & g_978) || l_4273) || 1L) != 0UL) || g_2248) | 0x6D007995L), l_4488)), g_4512)), l_4513)), g_721[3]))) < 4294967295UL)), l_4488))) != g_329[1][3][2]), l_4266)) >= g_721[3]), g_1810[0]))) | (-3L));
      }
for
    (i
     =
     0;
     i
     <
     1;
     i++)
    l_2
      [i]
      =
      0x2062L;
      g_1763
 =
 (safe_mod_func_uint32_t_u_u
  ((safe_mul_func_uint16_t_u_u (65527UL, g_1266)), (l_4276 = (safe_lshift_func_int8_t_s_u (((((4UL | (safe_mod_func_int16_t_s_s ((safe_sub_func_int16_t_s_s ((safe_lshift_func_int8_t_s_s ((g_930 = (g_1917 <= (g_2580 = ((g_1810[0] ^ (safe_mod_func_int8_t_s_s (g_2617, (safe_mod_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s ((g_1835[0][3][2] || 4294967292UL), (l_4279 = (g_2065 ^ g_1917)))), g_1835[0][3][2]))))) <= 0xFDL)))), g_721[1])), 0xD457L)), g_2004[0][0][2]))) || 2UL) < g_3117) == l_4382), 0)))));
      g_2580
 =
 (((safe_lshift_func_int8_t_s_u ((safe_add_func_uint16_t_u_u (((safe_unary_minus_func_int8_t_s ((g_344 = g_2580))) <= (safe_sub_func_uint8_t_u_u (l_4475[1][2], (g_513[1] != (safe_sub_func_uint32_t_u_u (3UL, (0xBCC5178AL < (((safe_add_func_uint32_t_u_u ((safe_sub_func_int8_t_s_s ((~0xC3L), (safe_lshift_func_uint16_t_u_s (g_669, 1)))), (safe_mul_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_u ((safe_add_func_uint16_t_u_u ((g_30 = l_4475[1][0]), ((g_588 ^ g_930) || 1UL))), g_71[7])), 0xEFL)))) == l_2[g_3]) != g_71[7])))))))), l_4480)), 1)) && g_1281) >= l_4480);
      l_4279
 =
 l_4513;
    }
  }
  for
    (g_588
     =
     0;
     (g_588
      <
      19);
     g_588
     =
     safe_add_func_uint8_t_u_u
     (g_588,
      9))
  {
    int32_t
      l_4556
      =
      0x6787A757L;
    int32_t
      l_4576
      =
      0x18CCC61BL;
    uint32_t
      l_4660
      =
      0x8A0641B2L;
    uint32_t
      l_4792
      =
      0UL;
    uint8_t
      l_4918
      =
      0xA7L;
    g_1763
      =
      (((safe_unary_minus_func_uint16_t_u ((+((safe_mod_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s ((safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u ((((l_4576 = ((g_1266 = (((g_1782 = (safe_rshift_func_uint8_t_u_u ((l_4279 = g_1810[0]), (l_4556 == (l_4261 == (l_4276 = (g_3691 = (+(!0x8DL))))))))) >= (g_513[1] = 2UL)) && ((-1L) && (safe_add_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((g_774 = l_4513) >= (g_920 && (((safe_sub_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_u ((((g_555 > 0x09L) ^ g_930) > 1UL), g_329[1][0][0])), g_920)) >= l_2[0]) >= l_4261))) && l_4513), g_697[8][0])) <= l_4556), l_4576))))) <= l_4511)) || g_3350) >= l_4261), g_71[2])), l_4556)), 5)), g_1281)) ^ 7L)))) | g_669) >= l_4556);
{
    int32_t
      l_4266
      =
      0L;
    int32_t
      l_4273
      =
      1L;
    uint16_t
      l_4286
      =
      0xF524L;
    uint16_t
      l_4445
      =
      9UL;
    int
      i;
    if (func_4 ((l_2[g_3] = func_6 (((0x9869L > (safe_lshift_func_int8_t_s_u (0x5AL, 7))) <= l_2[g_3])))))
    {
      int16_t
 l_4275
 =
 0L;
      int32_t
 l_4281
 =
 0x70A7439CL;
      uint32_t
 l_4320
 [5]
 [4]
 [8]
 =
 {
   {{4294967288UL, 4294967286UL, 0x88591B17L, 0x2DA21B14L, 0xAC8CBD14L, 4294967295UL, 0x3AF223E2L, 0xBB3A348FL}
    ,
    {0x88591B17L,
     0xC53D16DDL,
     0xB212CD3DL,
     6UL,
     0x529B4498L,
     6UL,
     0xB212CD3DL,
     0xC53D16DDL}
    ,
    {0xBD6EE877L,
     0x88591B17L,
     2UL,
     0x60B90E3AL,
     1UL,
     0x2AA60299L,
     0x6B0F5BCEL,
     0x66920C8AL}
    ,
    {0xB212CD3DL,
     0UL,
     0x60B90E3AL,
     0x529B4498L,
     0xBD6EE877L,
     4294967295UL,
     0x6B0F5BCEL,
     4294967292UL}
    }
      , {{0xDA6ED2ABL, 0x529B4498L, 2UL, 0x2AA60299L, 4294967295UL, 0x6B0F5BCEL, 0xB212CD3DL, 0xAC8CBD14L}
  ,
  {4294967295UL,
   0x6B0F5BCEL,
   0xB212CD3DL,
   0xAC8CBD14L,
   0x66920C8AL,
   0xB901ABD4L,
   0x3AF223E2L,
   0x3AF223E2L}
  ,
  {4294967292UL,
   0xBB3A348FL,
   0x88591B17L,
   0x88591B17L,
   0xBB3A348FL,
   4294967292UL,
   0xCE9D9A97L,
   0UL}
  ,
  {0UL,
   0xB40ABE1EL,
   0xBB3A348FL,
   4294967295UL,
   0UL,
   0x2ABDD0F8L,
   0xEE6A9442L,
   0xB212CD3DL}
  }
      , {{0x3AF223E2L, 0xAC8CBD14L, 0x56C35297L, 4294967295UL, 4294967288UL, 0x66920C8AL, 0xB40ABE1EL, 0UL}
  ,
  {0x60B90E3AL,
   4294967288UL,
   4294967286UL,
   0x88591B17L,
   0x2DA21B14L,
   0xAC8CBD14L,
   4294967295UL,
   0x3AF223E2L}
  ,
  {0UL,
   0UL,
   6UL,
   0xAC8CBD14L,
   0xCB0B3A06L,
   4294967286UL,
   0xCB0B3A06L,
   0xAC8CBD14L}
  ,
  {0x529B4498L,
   0UL,
   0x529B4498L,
   0x2AA60299L,
   0UL,
   0xBD6EE877L,
   0x60B90E3AL,
   4294967292UL}
  }
      , {{0x56C35297L, 0UL, 4294967295UL, 0x529B4498L, 0UL, 0xCE9D9A97L, 0UL, 0x66920C8AL}
  ,
  {0x56C35297L,
   0xEE6A9442L,
   0x2DA21B14L,
   0x60B90E3AL,
   0UL,
   1UL,
   2UL,
   0xC53D16DDL}
  ,
  {0x529B4498L,
   0xB901ABD4L,
   0x2ABDD0F8L,
   6UL,
   0xCB0B3A06L,
   0x60B90E3AL,
   0xDA6ED2ABL,
   0xBB3A348FL}
  ,
  {0UL,
   0x2ABDD0F8L,
   4294967288UL,
   0x2DA21B14L,
   0x2DA21B14L,
   4294967288UL,
   0x2ABDD0F8L,
   0UL}
  }
      , {{0x60B90E3AL, 4294967295UL, 0xCB0B3A06L, 0UL, 4294967288UL, 0UL, 4294967286UL, 0x8534AC0FL}
  ,
  {0UL,
   0xC53D16DDL,
   0x3AF223E2L,
   4294967292UL,
   0x6B0F5BCEL,
   4294967295UL,
   0xBD6EE877L,
   0x529B4498L}
  ,
  {0xB901ABD4L,
   0xB212CD3DL,
   0x60B90E3AL,
   0xC53D16DDL,
   0xAC8CBD14L,
   4294967292UL,
   0UL,
   0x8534AC0FL}
  ,
  {0x529B4498L,
   4294967295UL,
   0UL,
   0x56C35297L,
   0x2DA21B14L,
   1UL,
   6UL,
   1UL}
  }
      };
      int32_t
 l_4422
 [7]
 [6];
      int
 i,
        j,
        k;
      for
 (i
  =
  0;
  i
  <
  7;
  i++)
      {
 for
   (j
    =
    0;
    j
    <
    6;
    j++)
   l_4422
     [i]
     [j]
     =
     0L;
      }
      if ((((((((safe_add_func_uint32_t_u_u ((+(safe_rshift_func_uint8_t_u_u (g_866, 7))), g_3350)) || 0xFDL) >= g_2388[1]) & g_3847) < ((((safe_rshift_func_int16_t_s_u (l_2[0], 3)) != ((-1L) <= (safe_sub_func_int8_t_s_s (((0x9BL & l_2[0]) != 0x17L), (-1L))))) | g_1835[0][3][2]) < g_555)) < l_2[g_3]) | g_344))
      {
 int16_t
   l_4274
   [6];
 int32_t
   l_4278
   =
   0L;
 int32_t
   l_4280
   =
   (-1L);
 int
   i;
 for
   (i
    =
    0;
    i
    <
    6;
    i++)
   l_4274
     [i]
     =
     0x0103L;
 for
   (g_588
    =
    0;
    (g_588
     <
     57);
    ++g_588)
 {
   return
     l_2
     [0];
 }
 l_4281
   =
   (((l_4280 = (((((l_4279 = ((safe_mul_func_int8_t_s_s (((l_4278 = (safe_mod_func_uint16_t_u_u ((0x6864FD20L > ((safe_mul_func_uint8_t_u_u (((safe_mul_func_int16_t_s_s (0xAE7EL, 1L)) | (g_71[7] = (safe_add_func_int8_t_s_s ((l_4261 > (l_4273 = ((((safe_lshift_func_uint8_t_u_u ((((0x6E9D4E43L >= (l_4266 = 0xE639630BL)) > ((l_4276 = ((safe_add_func_int16_t_s_s (0x6308L, (safe_lshift_func_uint8_t_u_s (1UL, 2)))) || (((((((safe_add_func_uint16_t_u_u ((((+(g_721[3] != g_1266)) != 4294967289UL) > g_3350), g_697[0][0])) & l_4273) == l_4274[2]) <= g_669) >= g_3847) == l_4275) | g_2004[0][0][2]))) != g_3691)) || l_4274[2]), g_367)) ^ l_4277) && (-6L)) != 65533UL))), g_1835[0][3][2])))), g_2066[7])) <= (-9L))), l_2[g_3]))) <= l_2[g_3]), (-1L))) != 0x0EL)) & g_367) < 0xDFF6L) == l_2[g_3]) ^ 0xD8L)) != g_697[8][0]) || 0xE9FEL);
 g_2580
   =
   ((safe_mul_func_int8_t_s_s (((safe_rshift_func_uint8_t_u_u ((l_4279 = l_4274[2]), 6)) & (l_4275 && l_4261)), (g_1810[0] = ((g_555 = ((g_367 = (l_2[g_3] != g_2248)) == ((1UL && ((((g_30 < g_978) & ((l_4286 > g_3) < g_329[1][0][0])) != l_4274[2]) | (-10L))) == 0xDCL))) || l_4266)))) == g_1835[0][1][4]);
 return
   l_4275;
      }
      else
      {
 int32_t
   l_4317
   =
   0x3AC109D8L;
 int32_t
   l_4361
   =
   0L;
 uint32_t
   l_4424
   [1]
   [2];
 int8_t
   l_4442
   =
   1L;
 int
   i,
   j;
 for
   (i
    =
    0;
    i
    <
    1;
    i++)
 {
   for
     (j
      =
      0;
      j
      <
      2;
      j++)
     l_4424
       [i]
       [j]
       =
       0x36C5A427L;
 }
 g_71
   [7]
   =
   0xBAC947ACL;
 if ((safe_add_func_uint32_t_u_u (l_4286, g_1382)))
 {
   uint32_t
     l_4295
     [1];
   int16_t
     l_4318
     =
     0x214CL;
   uint8_t
     l_4319
     =
     247UL;
   int32_t
     l_4381
     =
     1L;
   int
     i;
   for
     (i
      =
      0;
      i
      <
      1;
      i++)
     l_4295
       [i]
       =
       1UL;
   l_4276
     =
     ((g_367 = ((((l_4275 & ((safe_lshift_func_uint8_t_u_u ((g_1917 = ((g_329[1][3][3] = 0x9418C7CEL) != (((((safe_mul_func_int8_t_s_s ((safe_mul_func_int8_t_s_s (l_4295[0], (g_3350 ^ ((safe_rshift_func_uint8_t_u_s ((safe_add_func_uint16_t_u_u ((safe_add_func_uint32_t_u_u (g_1917, (safe_mul_func_int16_t_s_s ((safe_rshift_func_int16_t_s_u (((((safe_mod_func_int32_t_s_s ((-1L), g_1835[0][3][2])) >= (((safe_mod_func_int8_t_s_s ((safe_sub_func_int8_t_s_s ((safe_lshift_func_int16_t_s_s (((safe_unary_minus_func_int8_t_s ((safe_mul_func_uint16_t_u_u (1UL, g_721[3])))) | l_4317), 10)), 0xAEL)), g_71[0])) == 0x00L) | l_2[g_3])) && g_721[3]) <= l_4318), 8)), l_4319)))), g_669)), 3)) <= l_4317)))), l_4295[0])) >= (-1L)) || l_4276) < g_1917) & 0x6C259E8DL))), l_4320[2][2][0])) < g_721[6])) == l_4317) > g_71[1]) < g_721[8])) > 0L);
   if (((safe_mul_func_uint8_t_u_u (((safe_mul_func_int8_t_s_s ((((safe_mul_func_int8_t_s_s (((safe_mul_func_uint16_t_u_u ((g_71[3] <= (g_2004[0][0][2] || (0x6DL < (4UL == ((l_4273 = 0UL) || l_4279))))), l_4320[2][2][0])) & ((g_1763 = (g_71[0] && (safe_rshift_func_uint16_t_u_u ((safe_lshift_func_uint8_t_u_s (g_3350, l_4275)), g_367)))) <= g_2373)), g_3)) != 0x5D92F532L) != 1UL), g_2004[0][0][2])) | g_2004[0][0][2]), 0x3DL)) >= l_4277))
   {
     if (g_588)
       break;
   }
   else
   {
     uint8_t
       l_4362
       =
       0x63L;
     int32_t
       l_4383
       =
       (-8L);
     l_4266
       =
       (safe_lshift_func_uint16_t_u_u
        ((((l_4361 = ((safe_mul_func_uint16_t_u_u (((safe_add_func_uint32_t_u_u ((safe_mul_func_uint8_t_u_u (0xC5L, (safe_mul_func_int16_t_s_s (g_697[1][0], (l_4319 || (safe_add_func_uint32_t_u_u (l_4295[0], ((65527UL >= (safe_sub_func_uint32_t_u_u (g_669, ((safe_mul_func_uint16_t_u_u (((g_458 && (safe_add_func_int32_t_s_s ((l_2[0] || (safe_rshift_func_uint8_t_u_s ((safe_mul_func_uint16_t_u_u ((g_30 = (~((g_1835[0][3][2] = (g_2065 = (safe_add_func_int16_t_s_s ((safe_sub_func_int32_t_s_s (((0x452A9AFDL ^ 0xEB54E6E3L) | 0xB4L), g_2066[7])), 0x84BFL)))) == l_2[g_3]))), 0L)), 5))), g_329[1][4][3]))) == g_588), l_4286)) >= 65527UL)))) & g_1281)))))))), 0x3CA1605AL)) >= (-10L)), 9L)) ^ g_1281)) ^ (-1L)) || l_4362), 12));
     l_4273
       =
       ((safe_mul_func_uint8_t_u_u (l_4317, (((((l_4383 = (safe_mod_func_int8_t_s_s (((4294967289UL < ((((((g_1995 <= (safe_sub_func_uint8_t_u_u ((l_4317 && (g_513[1] = ((g_513[5] ^ (l_4381 = ((safe_sub_func_uint8_t_u_u (g_2004[1][0][0], (0x78L != 0x7BL))) < (safe_mod_func_uint8_t_u_u (((safe_lshift_func_uint16_t_u_s (((safe_mod_func_int32_t_s_s ((safe_mul_func_uint8_t_u_u ((g_71[7] >= g_1281), l_4295[0])), g_3350)) <= g_329[1][0][0]), 7)) && l_4266), g_30))))) > l_4261))), g_71[3]))) < g_2066[7]) || l_4382) != l_4362) || g_1995) != 1L)) ^ 0x93AA5932L), g_697[3][1]))) == 0x63DC3EFBL) <= l_4320[0][1][4]) || 1L) != l_4362))) > 0x9FL);
   }
 }
 else
 {
   uint32_t
     l_4384
     =
     5UL;
   int32_t
     l_4405
     [7]
     =
     {
 0L,
 0L,
 0L,
 0L,
 0L,
 0L,
 0L
      };
   int
     i;
   g_1782
     =
     l_4384;
   g_300
     =
     0x7825CE2DL;
   if (((safe_mod_func_int8_t_s_s ((safe_add_func_int32_t_s_s ((l_4384 && 5L), (l_4361 = (((1UL > (((((l_4286 | ((l_4276 = (g_513[2] && (g_774 = (safe_mod_func_uint16_t_u_u (((g_30 = (!(safe_mul_func_int8_t_s_s ((safe_add_func_uint8_t_u_u ((l_4266 = (!(+(g_3691 = (((((!(g_1810[0] = 0xEEL)) | (((g_3847 = (l_4273 & ((!l_2[0]) || (safe_lshift_func_uint8_t_u_s (((safe_mul_func_int8_t_s_s (g_866, l_2[g_3])) && l_4277), 7))))) & 3L) >= 0x7CL)) >= (-1L)) >= 65535UL) != (-1L)))))), 0xEAL)), g_2066[5])))) == g_669), g_54))))) < g_1835[0][1][1])) & 0L) > l_4261) || g_3691) <= l_4261)) < l_4317) ^ l_4320[2][2][0])))), l_4384)) >= l_4273))
   {
     int16_t
       l_4404
       =
       0L;
     g_2580
       =
       l_4384;
     l_4405
       [1]
       =
       (safe_rshift_func_uint16_t_u_u
        ((g_201 != (g_71[3] = (0x482E6DD3L == (g_4401 >= (l_4404 = (safe_lshift_func_uint16_t_u_u (l_4277, 7))))))), 10));
     if (g_3847)
       break;
   }
   else
   {
     int8_t
       l_4423
       =
       0x6FL;
     l_4424
       [0]
       [1]
       =
       ((((!(g_2388[1] & l_4320[2][2][0])) < (!(1L > (l_2[0] | ((safe_lshift_func_uint16_t_u_s ((safe_rshift_func_uint16_t_u_u (l_4281, 13)), (g_555 = (g_697[3][0] = (-1L))))) && ((safe_rshift_func_uint8_t_u_s ((safe_unary_minus_func_uint8_t_u ((safe_lshift_func_int8_t_s_u ((safe_mul_func_uint8_t_u_u (((safe_unary_minus_func_int8_t_s (((safe_add_func_int16_t_s_s (((l_2[g_3] && (((safe_mod_func_int16_t_s_s (g_1782, (g_697[8][0] && g_1917))) || l_4320[2][1][7]) <= l_4422[2][1])) == 1L), 0xF6F6L)) > 0x1AL))) <= 0x2E30L), 5L)), 3)))), g_3350)) == l_4423)))))) || g_658) || 0xA9L);
   }
 }
 for
   (l_4279
    =
    0;
    (l_4279
     >=
     (-1));
    l_4279--)
 {
   for
     (g_3117
      =
      3;
      (g_3117
       >=
       0);
      g_3117
      -=
      1)
   {
     int
       i,
       j,
       k;
     if (l_4320[(g_3117 + 1)][(g_3 + 1)][(g_3117 + 3)])
       break;
   }
 }
 for
   (l_4382
    =
    (-16);
    (l_4382
     <=
     (-18));
    --l_4382)
 {
   int16_t
     l_4431
     =
     0xF66EL;
   int32_t
     l_4436
     =
     (-1L);
   int32_t
     l_4439
     [9]
     =
     {
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L,
 0x8EE43301L
      };
   int
     i;
   if (g_721[3])
     break;
   g_71
     [6]
     =
     ((safe_mul_func_int8_t_s_s ((((g_1265[0][4] || (((l_4431 = g_2004[0][0][2]) < ((safe_mod_func_uint32_t_u_u (g_2004[6][0][8], ((safe_add_func_uint8_t_u_u (((l_4436 = ((((l_4436 > (g_344 = (safe_mod_func_int16_t_s_s (((g_2065 = g_2066[7]) >= (g_30 = (l_4275 ^ 0xF27072F1L))), g_2388[0])))) < (g_658 || l_4436)) <= 0xFBL) == l_4424[0][1])) >= 4294967295UL), g_920)) || 0x4EL))) ^ l_4424[0][0])) >= l_4424[0][0])) > l_4439[8]) && l_4439[2]), l_4261)) > g_1782);
   g_71
     [4]
     =
     (l_4439
      [8]
      =
      (g_555
       &
       (l_4361
        =
        0x9DL)));
   l_4361
     =
     (g_38
      !=
      (safe_lshift_func_int16_t_s_s
       (((((0xC4L != ((((g_1810[0] | (g_3691 = (((l_4431 != g_3350) & (l_4442 = l_4266)) >= g_367))) < (0x4EL || ((safe_mod_func_uint32_t_u_u ((((((l_4320[4][3][3] == g_1266) > 0xCADD5B35L) | 0x35L) < l_4439[8]) ^ g_521), 0x7A1165F3L)) && 0x5BA991B8L))) | l_4424[0][1]) || l_4431)) <= 0UL) || l_4422[2][1]) ^ g_3117), l_4445)));
 }
      }
      l_4276
 =
 (l_4279
  =
  (safe_rshift_func_uint8_t_u_s
   (((4294967290UL <= (~(l_4422[3][0] = 0xABC520E7L))) || g_513[1]), 5)));
      l_4281
 =
 (g_71
  [0]
  =
  ((safe_mod_func_int32_t_s_s ((safe_mul_func_uint8_t_u_u ((safe_sub_func_int8_t_s_s ((l_4276 = (+((l_4422[2][2] = 0xDFL) <= (g_3 != ((g_1810[0] = (!(safe_mul_func_int16_t_s_s (g_458, (safe_rshift_func_int8_t_s_u (l_4320[2][2][3], (g_1382 && ((safe_rshift_func_uint16_t_u_s ((((g_2388[1] < (l_4276 <= (((g_1266 != (((g_300 = ((~0x5AD8L) <= 0x15E9L)) | 1L) == g_555)) > g_3) & 1UL))) >= g_4460) == l_4286), g_2004[0][0][2])) == 0xCDL)))))))) == 5UL))))), g_1917)), l_4281)), g_1835[0][3][2])) | g_1835[0][3][2]));
    }
    else
    {
      int32_t
 l_4475
 [3]
 [3]
 =
 {
    {(-1L), (-1L), (-1L)}
      , {(-1L), (-1L), (-1L)}
      , {(-1L), (-1L), (-1L)}
      };
      int32_t
 l_4481
 =
 0x766BB33FL;
      int
 i,
        j;
      if (((safe_sub_func_uint32_t_u_u ((((safe_sub_func_int8_t_s_s ((((safe_sub_func_uint16_t_u_u (g_201, (((1UL >= (safe_lshift_func_int16_t_s_s ((((((safe_sub_func_int8_t_s_s (l_4276, (0x5CE5838AL && 0xCE452925L))) == (safe_lshift_func_uint8_t_u_s ((l_4475[0][1] = (safe_rshift_func_uint8_t_u_u (l_4279, 3))), 0))) || (+(g_2004[0][0][2] = ((((((safe_sub_func_uint32_t_u_u ((l_4277 & ((!9L) & (safe_mul_func_uint8_t_u_u ((l_4286 & 0x5751L), l_4475[1][1])))), l_4445)) || g_697[8][0]) & l_4266) && g_329[1][0][0]) < 0x75L) | 0x94EC5207L)))) > 0xC7L) >= g_697[8][0]), 7))) < g_367) != g_2066[7]))) == 0xA6E1DCAAL) > l_4480), 0x6DL)) | l_4481) || 65535UL), l_4445)) < l_4481))
      {
 l_4481
   =
   (-6L);
      }
      else
      {
 int16_t
   l_4488
   =
   (-6L);
 uint16_t
   l_4514
   =
   0x3C3CL;
 g_71
   [0]
   =
   0x98671147L;
 for
   (g_1782
    =
    0;
    (g_1782
     <=
     1);
    g_1782
    +=
    1)
 {
   for
     (g_3691
      =
      0;
      (g_3691
       <=
       1);
      g_3691
      +=
      1)
   {
     int
       i,
       j;
     g_2580
       =
       g_697
       [(g_3691 + 5)][(g_3 + 1)];
   }
 }
 l_4514
   =
   ((g_1835[0][3][1] = (safe_lshift_func_int8_t_s_s (((safe_mul_func_int16_t_s_s (((1L > (safe_mul_func_int16_t_s_s ((((~l_4488) <= (safe_sub_func_uint32_t_u_u ((0UL && g_697[8][0]), l_4480))) && ((+(safe_lshift_func_int8_t_s_u ((safe_rshift_func_int16_t_s_s ((safe_mul_func_int16_t_s_s ((safe_mul_func_uint8_t_u_u ((((((((safe_mul_func_uint8_t_u_u (((safe_lshift_func_int16_t_s_s (((safe_lshift_func_uint8_t_u_u (((safe_add_func_int8_t_s_s ((~((safe_mod_func_uint16_t_u_u (65526UL, ((((g_930 = (safe_rshift_func_uint8_t_u_s (0x7BL, 4))) && ((g_697[8][0] = l_4475[0][1]) <= (g_1782 && 0x74L))) ^ 0x2DF3L) || l_4511))) < l_4488)), g_555)) >= g_30), 5)) & 4294967295UL), 3)) >= g_1995), g_4460)) & g_978) || l_4273) || 1L) != 0UL) || g_2248) | 0x6D007995L), l_4488)), g_4512)), l_4513)), g_721[3]))) < 4294967295UL)), l_4488))) != g_329[1][3][2]), l_4266)) >= g_721[3]), g_1810[0]))) | (-3L));
      }
      g_1763
 =
 (safe_mod_func_uint32_t_u_u
  ((safe_mul_func_uint16_t_u_u (65527UL, g_1266)), (l_4276 = (safe_lshift_func_int8_t_s_u (((((4UL | (safe_mod_func_int16_t_s_s ((safe_sub_func_int16_t_s_s ((safe_lshift_func_int8_t_s_s ((g_930 = (g_1917 <= (g_2580 = ((g_1810[0] ^ (safe_mod_func_int8_t_s_s (g_2617, (safe_mod_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s ((g_1835[0][3][2] || 4294967292UL), (l_4279 = (g_2065 ^ g_1917)))), g_1835[0][3][2]))))) <= 0xFDL)))), g_721[1])), 0xD457L)), g_2004[0][0][2]))) || 2UL) < g_3117) == l_4382), 0)))));
      g_2580
 =
 (((safe_lshift_func_int8_t_s_u ((safe_add_func_uint16_t_u_u (((safe_unary_minus_func_int8_t_s ((g_344 = g_2580))) <= (safe_sub_func_uint8_t_u_u (l_4475[1][2], (g_513[1] != (safe_sub_func_uint32_t_u_u (3UL, (0xBCC5178AL < (((safe_add_func_uint32_t_u_u ((safe_sub_func_int8_t_s_s ((~0xC3L), (safe_lshift_func_uint16_t_u_s (g_669, 1)))), (safe_mul_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_u ((safe_add_func_uint16_t_u_u ((g_30 = l_4475[1][0]), ((g_588 ^ g_930) || 1UL))), g_71[7])), 0xEFL)))) == l_2[g_3]) != g_71[7])))))))), l_4480)), 1)) && g_1281) >= l_4480);
      l_4279
 =
 l_4513;
    }
  }
    l_4279
      =
      l_4576;
g_1763
      =
      (((safe_unary_minus_func_uint16_t_u ((+((safe_mod_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s ((safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u ((((l_4576 = ((g_1266 = (((g_1782 = (safe_rshift_func_uint8_t_u_u ((l_4279 = g_1810[0]), (l_4556 == (l_4261 == (l_4276 = (g_3691 = (+(!0x8DL))))))))) >= (g_513[1] = 2UL)) && ((-1L) && (safe_add_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((g_774 = l_4513) >= (g_920 && (((safe_sub_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_u ((((g_555 > 0x09L) ^ g_930) > 1UL), g_329[1][0][0])), g_920)) >= l_2[0]) >= l_4261))) && l_4513), g_697[8][0])) <= l_4556), l_4576))))) <= l_4511)) || g_3350) >= l_4261), g_71[2])), l_4556)), 5)), g_1281)) ^ 7L)))) | g_669) >= l_4556);
    for
      (g_367
       =
       0;
       (g_367
 <=
 1);
       g_367
       +=
       1)
    {
      uint32_t
 l_4581
 [1];
      uint16_t
 l_4642
 =
 65530UL;
      int32_t
 l_4775
 =
 0L;
      int16_t
 l_4776
 [9];
      int32_t
 l_4777
 [8]
 [6]
 =
 {
    {1L,
     4L,
     4L,
     1L,
     (-3L),
     0x92B5B022L}
      , {0x92B5B022L, 1L, 1L, 1L, 0x92B5B022L, (-1L)}
      , {1L, 0x92B5B022L, (-1L), (-1L), 0x92B5B022L, 1L}
      , {4L, 1L, (-3L), 0x92B5B022L, (-3L), 1L}
      , {(-3L), 4L, (-1L), 1L, 1L, (-1L)}
      , {(-3L), (-3L), 1L, 0x92B5B022L, 0x56D2AD28L, 0x92B5B022L}
      , {4L, (-3L), 4L, (-1L), 1L, 1L}
      , {1L, 4L, 4L, 1L, (-3L), 0x92B5B022L}
      };
      int32_t
 l_4807
 =
 (-4L);
      int32_t
 l_4808
 [2]
 [6]
 [8]
 =
 {
    {{9L, (-1L), (-1L), 9L, 9L, (-1L), (-1L), 9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     }
      , {{9L, (-1L), (-1L), 9L, 9L, (-1L), (-1L), 9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  }
      };
      int8_t
 l_4932
 =
 1L;
      int
 i,
        j,
        k;
{
    int32_t
      l_4556
      =
      0x6787A757L;
    int32_t
      l_4576
      =
      0x18CCC61BL;
    uint32_t
      l_4660
      =
      0x8A0641B2L;
    uint32_t
      l_4792
      =
      0UL;
    uint8_t
      l_4918
      =
      0xA7L;
    l_4556
      =
      (l_4276
       =
       g_2373);
    g_1763
      =
      (((safe_unary_minus_func_uint16_t_u ((+((safe_mod_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s ((safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u ((((l_4576 = ((g_1266 = (((g_1782 = (safe_rshift_func_uint8_t_u_u ((l_4279 = g_1810[0]), (l_4556 == (l_4261 == (l_4276 = (g_3691 = (+(!0x8DL))))))))) >= (g_513[1] = 2UL)) && ((-1L) && (safe_add_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((g_774 = l_4513) >= (g_920 && (((safe_sub_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_u ((((g_555 > 0x09L) ^ g_930) > 1UL), g_329[1][0][0])), g_920)) >= l_2[0]) >= l_4261))) && l_4513), g_697[8][0])) <= l_4556), l_4576))))) <= l_4511)) || g_3350) >= l_4261), g_71[2])), l_4556)), 5)), g_1281)) ^ 7L)))) | g_669) >= l_4556);
    l_4279
      =
      l_4576;
    for
      (g_367
       =
       0;
       (g_367
 <=
 1);
       g_367
       +=
       1)
    {
      uint32_t
 l_4581
 [1];
      uint16_t
 l_4642
 =
 65530UL;
      int32_t
 l_4775
 =
 0L;
      int16_t
 l_4776
 [9];
      int32_t
 l_4777
 [8]
 [6]
 =
 {
    {1L,
     4L,
     4L,
     1L,
     (-3L),
     0x92B5B022L}
      , {0x92B5B022L, 1L, 1L, 1L, 0x92B5B022L, (-1L)}
      , {1L, 0x92B5B022L, (-1L), (-1L), 0x92B5B022L, 1L}
      , {4L, 1L, (-3L), 0x92B5B022L, (-3L), 1L}
      , {(-3L), 4L, (-1L), 1L, 1L, (-1L)}
      , {(-3L), (-3L), 1L, 0x92B5B022L, 0x56D2AD28L, 0x92B5B022L}
      , {4L, (-3L), 4L, (-1L), 1L, 1L}
      , {1L, 4L, 4L, 1L, (-3L), 0x92B5B022L}
      };
      int32_t
 l_4807
 =
 (-4L);
      int32_t
 l_4808
 [2]
 [6]
 [8]
 =
 {
    {{9L, (-1L), (-1L), 9L, 9L, (-1L), (-1L), 9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     }
      , {{9L, (-1L), (-1L), 9L, 9L, (-1L), (-1L), 9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  }
      };
      int8_t
 l_4932
 =
 1L;
      int
 i,
        j,
        k;
      for
 (i
  =
  0;
  i
  <
  1;
  i++)
 l_4581
   [i]
   =
   4294967295UL;
      for
 (i
  =
  0;
  i
  <
  9;
  i++)
 l_4776
   [i]
   =
   0L;
      for
 (g_521
  =
  0;
  (g_521
   <=
   8);
  g_521
  +=
  1)
      {
 uint16_t
   l_4662
   =
   65535UL;
 int
   i;
 g_71
   [(g_367 + 6)] = (safe_lshift_func_int16_t_s_s (((safe_mul_func_uint16_t_u_u (g_721[(g_367 + 1)], g_721[g_521])) | (g_4460 = (0x9FL == l_4581[0]))), (safe_mul_func_uint16_t_u_u ((safe_unary_minus_func_uint32_t_u ((g_3847 = l_4382))), ((((safe_rshift_func_int8_t_s_s ((((l_4279 = g_721[g_521]) > l_4513) ^ g_721[(g_367 + 1)]), l_4382)) | g_2617) != 0xFFL) <= 0xF0ECL)))));
 if ((safe_add_func_int8_t_s_s ((((safe_add_func_uint16_t_u_u (((g_697[8][0] = (safe_rshift_func_uint16_t_u_u (g_71[7], (((safe_mul_func_uint16_t_u_u ((((g_329[1][0][0] = (0UL || (safe_add_func_uint8_t_u_u ((safe_add_func_uint16_t_u_u ((safe_unary_minus_func_int32_t_s (g_2373)), ((-1L) < ((g_2065 = l_4261) > (-1L))))), (~g_2004[0][0][2]))))) > (safe_sub_func_uint16_t_u_u ((((g_920 = (safe_lshift_func_uint16_t_u_u ((g_774 = ((safe_rshift_func_uint8_t_u_s ((safe_mul_func_int8_t_s_s (((safe_rshift_func_int8_t_s_s ((g_4460 = (safe_rshift_func_uint8_t_u_u ((((l_4279 && (0x22CDF452L > g_1835[0][1][0])) <= 0xBE08C71AL) <= 0xAC129E78L), g_71[0]))), 3)) == l_4556), l_4576)), g_978)) != l_4261)), g_521))) <= g_1917) >= 0xD6L), 65526UL))) || l_4382), 9L)) | l_4556) > (-1L))))) == g_721[g_521]), 0UL)) >= g_1835[0][2][2]) < l_4581[0]), g_721[(g_367 + 1)])))
 {
   uint8_t
     l_4617
     =
     6UL;
   int32_t
     l_4634
     =
     1L;
   int32_t
     l_4635
     =
     0L;
   if (((safe_rshift_func_int8_t_s_s (((-6L) >= g_4614), 4)) < (g_2004[0][0][2] = 0L)))
   {
     uint8_t
       l_4618
       =
       0x01L;
     l_4618
       =
       (l_4617
        =
        (safe_rshift_func_int16_t_s_u
  (7L,
   13)));
   }
   else
   {
     return
       g_2373;
   }
   g_300
     =
     (safe_mod_func_uint8_t_u_u
      (8UL,
       (safe_add_func_uint32_t_u_u
        (((l_4276 = (g_458 > g_555)) <= l_4279), g_30))));
   for
     (g_1266
      =
      0;
      (g_1266
       <=
       1);
      g_1266
      +=
      1)
   {
     int32_t
       l_4633
       =
       (-8L);
     if (l_4277)
       break;
     if (l_4617)
       continue;
     l_4635
       =
       (g_71
        [7]
        =
        ((((l_4634 = (!(safe_add_func_int8_t_s_s (l_4581[0], (((safe_mod_func_int16_t_s_s (l_4576, (l_4576 ^ l_4556))) != (l_4617 > ((((safe_mod_func_uint32_t_u_u (((safe_unary_minus_func_int32_t_s ((safe_mul_func_uint8_t_u_u (g_71[(g_367 + 6)], g_555)))) >= l_4632), l_4633)) || 0x5405DB9DL) ^ g_30) > l_4617))) >= l_4633))))) || l_4617) != g_1382) != g_721[8]));
     g_1763
       =
       l_4581
       [0];
   }
 }
 else
 {
   uint32_t
     l_4647
     =
     0xD428E22EL;
   if ((safe_lshift_func_uint8_t_u_u ((4294967288UL <= (g_1810[0] < (safe_sub_func_uint8_t_u_u ((((+((0x5C358E21L > ((safe_mul_func_uint8_t_u_u (((g_4512 < (l_4642 = 0L)) & g_721[(g_367 + 1)]), ((safe_add_func_uint32_t_u_u ((safe_rshift_func_int16_t_s_s (l_4576, 14)), (g_2580 = ((g_930 = (l_4556 = (g_1266 ^ (g_697[7][0] = (g_2065 = l_4647))))) < 0UL)))) && 3UL))) == 0x984EL)) & 253UL)) ^ g_721[(g_367 + 1)]) | 0x12CCB0D5L), 0xAFL)))), g_721[g_521])))
   {
     return
       g_2065;
   }
   else
   {
     l_4576
       =
       g_513
       [5];
     return
       g_513
       [6];
   }
 }
 g_3
   =
   (safe_sub_func_int8_t_s_s
    (((((g_71[(g_367 + 6)] = (safe_mul_func_int16_t_s_s (l_4581[0], (safe_mod_func_int16_t_s_s (g_30, (((safe_mul_func_uint8_t_u_u (g_3847, ((g_4401 <= ((l_4261 >= (((0x7CA4L > (safe_lshift_func_int8_t_s_u ((!(!g_300)), ((safe_rshift_func_uint8_t_u_s (g_329[1][2][5], 7)) | (l_4660 = g_774))))) > l_4661) >= 0x421625CCL)) != l_4662)) < g_71[(g_367 + 6)]))) & 0x38431C89L) | 0L)))))) != 7L) != l_4576) >= 0x2A6EAC5BL), g_2066[7]));
      }
      for
 (g_4460
  =
  0;
  (g_4460
   <=
   1);
  g_4460
  +=
  1)
      {
 uint32_t
   l_4666
   =
   0xF0D0EFCCL;
 int32_t
   l_4690
   =
   0x1027F16CL;
 uint8_t
   l_4727
   =
   0UL;
 int32_t
   l_4806
   [3];
 int
   i;
 for
   (i
    =
    0;
    i
    <
    3;
    i++)
   l_4806
     [i]
     =
     0L;
 l_4279
   =
   (g_4663
    =
    (((g_4663 < ((safe_add_func_int32_t_s_s ((l_4642 & l_4642), l_4666)) < ((safe_mul_func_int8_t_s_s (g_1835[0][5][2], ((safe_add_func_int8_t_s_s (l_4666, ((safe_sub_func_int8_t_s_s (7L, (safe_sub_func_uint8_t_u_u (0xCAL, ((safe_unary_minus_func_int16_t_s (g_2004[0][0][2])) >= g_71[7]))))) && 0x37A2L))) || (-1L)))) <= l_4666))) & (-1L)) <= g_2617));
 if (((g_555 | (safe_add_func_int16_t_s_s ((0x5CB7L >= ((~l_4666) & (l_4576 = (safe_sub_func_int32_t_s_s (((safe_add_func_uint8_t_u_u ((l_4693 = ((0x9F77A192L && l_4576) || (((safe_sub_func_int32_t_s_s (((safe_mod_func_uint32_t_u_u ((safe_sub_func_int16_t_s_s ((safe_rshift_func_uint16_t_u_u ((g_367 > (!(g_2388[1] & ((((l_4690 = l_4277) <= ((l_4556 = (safe_sub_func_int16_t_s_s ((0xBCL <= l_4556), 1UL))) >= 0x9A4BBC0FL)) | 0x6475L) < g_1266)))), g_3)), g_697[8][0])), g_866)) && 0x7F72261DL), g_1281)) & l_4642) && g_71[5]))), g_458)) > 249UL), l_4666))))), l_4660))) == g_866))
 {
   uint8_t
     l_4706
     =
     0xDDL;
   int8_t
     l_4713
     [10]
     =
     {
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L
       };
   int
     i;
   g_71
     [7]
     =
     (safe_add_func_int32_t_s_s
      (0xE8FC7F13L,
       (safe_mul_func_uint16_t_u_u
        (g_2248,
  ((g_774 & 3UL) < l_4556)))));
   g_1782
     =
     (safe_sub_func_int8_t_s_s
      (((((safe_rshift_func_uint8_t_u_s (l_4576, 0)) != g_4512) | l_4642) & (safe_add_func_uint32_t_u_u ((0L != ((safe_sub_func_uint8_t_u_u (g_2248, (l_4706 ^ (((~(-7L)) < (((g_71[7] = ((safe_mul_func_int16_t_s_s (((g_3691 | ((safe_mul_func_uint16_t_u_u ((l_4556 = (safe_rshift_func_uint8_t_u_s (((((l_4706 != g_3350) < 4294967295UL) < g_2248) & g_71[7]), 1))), (-1L))) >= g_4401)) < l_4690), g_2066[3])) >= l_4713[5])) || 0xAD3DCE01L) > g_697[6][1])) ^ g_774)))) & l_4632)), g_201))), l_4642));
   for
     (g_3117
      =
      0;
      (g_3117
       <=
       1);
      g_3117
      +=
      1)
   {
     int8_t
       l_4720
       =
       0xF6L;
     int32_t
       l_4725
       =
       0x507E5A08L;
     g_71
       [5]
       =
       g_1266;
     g_71
       [7]
       =
       ((((safe_mod_func_uint32_t_u_u ((((l_4279 & ((((safe_sub_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_s ((((l_4726 = (l_4720 && (l_4706 & (l_4725 = (safe_add_func_int16_t_s_s ((safe_add_func_int16_t_s_s (0x9C19L, ((((0xAF8158EEL >= (l_4276 = (((!l_4666) == 0x5CL) ^ (g_3847 = (+(g_3691 && (g_1810[0] = ((l_4690 = 8UL) & l_4720)))))))) > 1UL) == g_2065) <= 0xE6L))), 0UL)))))) >= (-4L)) <= l_4713[6]), 4)) & l_4720), l_4642)) ^ g_669) <= (-1L)) | g_71[0])) >= 0x928DF89BL) == 0x12L), g_1281)) | 254UL) <= l_4727) ^ l_4642);
     if (g_4512)
       continue;
     if (g_3350)
       break;
   }
   g_71
     [7]
     =
     ((((255UL | ((safe_lshift_func_int8_t_s_s (9L, 1)) == (g_344 = (((safe_rshift_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u (g_1810[0], (1L != ((l_4581[0] >= ((0x447EL == ((-1L) <= g_38)) | (safe_lshift_func_int16_t_s_s (g_2004[0][0][2], l_4690)))) && 0xE0L)))), 13)) <= g_54) && g_697[8][0])))) ^ (-1L)) & l_4576) ^ g_201);
 }
 else
 {
   int8_t
     l_4738
     =
     5L;
   int32_t
     l_4739
     =
     0L;
   if (l_4480)
     break;
   g_4663
     =
     (0x61CEL
      ^
      (safe_mul_func_uint8_t_u_u
       (((l_4279 = (l_4642 & (l_4276 = ((((((l_4739 = (~l_4738)) <= (g_30 = (safe_lshift_func_int16_t_s_u (4L, 12)))) != (safe_mul_func_int8_t_s_s (((safe_mod_func_int8_t_s_s (((safe_mul_func_uint16_t_u_u ((((safe_mod_func_uint32_t_u_u (l_4642, 0x6056CDD7L)) ^ (0xF54BL && (safe_add_func_int8_t_s_s ((safe_sub_func_uint16_t_u_u ((safe_add_func_uint16_t_u_u ((g_697[8][0] ^ (((~(safe_add_func_uint16_t_u_u (g_3847, g_774))) && 0xCDL) == 1L)), (-1L))), g_1763)), g_521)))) ^ 0UL), l_4666)) && g_513[1]), l_4642)) & g_458), g_588))) & g_697[8][0]) | l_4690) > l_4581[0])))) < 3UL), 3L)));
   for
     (l_4693
      =
      0;
      (l_4693
       <=
       1);
      l_4693
      +=
      1)
   {
     int16_t
       l_4760
       =
       0xBA9EL;
     g_1763
       =
       (safe_mod_func_uint16_t_u_u
        (g_588,
  0xA221L));
     l_4777
       [2]
       [3]
       =
       (l_4760
        ==
        (g_300
  >=
  ((+0x2213L) && (safe_add_func_uint16_t_u_u ((g_774 = (safe_rshift_func_int8_t_s_u ((safe_lshift_func_uint8_t_u_s (((safe_mul_func_uint16_t_u_u (l_4581[0], ((safe_rshift_func_uint16_t_u_u (6UL, ((safe_mod_func_int32_t_s_s ((safe_mod_func_uint32_t_u_u ((g_920 = (l_4576 == l_4739)), g_4460)), l_4775)) != g_300))) == 1UL))) != 1L), 5)), 3))), l_4776[5])))));
   }
 }
 for
   (g_1917
    =
    0;
    (g_1917
     <=
     1);
    g_1917
    +=
    1)
 {
   int8_t
     l_4778
     =
     8L;
   l_4279
     =
     ((l_4778 == 0L) || (safe_sub_func_uint32_t_u_u (((+(l_4726 = (safe_rshift_func_int8_t_s_s (g_1281, 0)))) ^ ((safe_mul_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s (0x01L, l_4727)), ((g_30 = (safe_unary_minus_func_int8_t_s (g_1382))) | g_3117))) > ((safe_rshift_func_int8_t_s_u (((g_1266 = (safe_mod_func_uint16_t_u_u (l_4576, g_300))) <= 0x303FL), l_4792)) & g_521))), g_71[7])));
 }
 if (((g_1266 = (0x90L | 0xC0L)) >= ((safe_mod_func_int32_t_s_s (((l_4690 = ((safe_unary_minus_func_uint16_t_u ((safe_sub_func_uint16_t_u_u (65535UL, l_4279)))) < (l_4777[7][5] ^ (g_300 != l_4727)))) >= ((safe_unary_minus_func_int8_t_s ((safe_unary_minus_func_uint16_t_u ((safe_rshift_func_uint8_t_u_s (((((((0x8A25F2B6L && ((safe_lshift_func_int16_t_s_s (((l_4807 = (g_329[1][0][0] = (safe_rshift_func_int8_t_s_u ((l_4806[2] = l_4727), 2)))) & g_1265[2][5]), 9)) > 249UL)) ^ l_4808[1][4][1]) <= g_1782) & 3L) == g_71[7]) >= g_866), 5)))))) <= 0xAED4EAB5L)), l_4808[0][5][6])) != l_4576)))
 {
   int8_t
     l_4854
     =
     (-4L);
   if (g_4401)
   {
     l_4806
       [2]
       =
       ((g_201 > (g_4663 == (((safe_add_func_uint8_t_u_u ((+((safe_sub_func_uint16_t_u_u ((l_4777[2][5] = (g_774 = (safe_mul_func_int8_t_s_s (((g_2004[0][0][2] = ((safe_mod_func_uint16_t_u_u (g_978, (safe_lshift_func_uint16_t_u_s (g_774, (safe_sub_func_int32_t_s_s ((safe_rshift_func_int8_t_s_u ((safe_sub_func_uint16_t_u_u ((safe_lshift_func_uint16_t_u_u (0x8535L, 7)), ((l_4690 = (g_4663 > ((g_1266 = 0x3242L) ^ (+g_1835[0][6][4])))) | (g_2248 != g_2004[0][0][2])))), 7)), 0x5725F8BEL)))))) && l_4576)) <= 1UL), g_4401)))), l_4792)) != 0UL)), g_555)) >= 0x8CL) > g_697[8][0]))) != (-1L));
     g_1763
       =
       (safe_add_func_uint32_t_u_u
        ((((g_4460 > (safe_lshift_func_int8_t_s_s ((safe_mul_func_int8_t_s_s (0xDFL, (g_3117 <= (l_4576 = (g_978 > (((safe_lshift_func_int16_t_s_s ((safe_lshift_func_int16_t_s_s ((safe_add_func_uint32_t_u_u ((safe_add_func_int8_t_s_s (g_1810[0], (safe_add_func_uint8_t_u_u (0x62L, 0x86L)))), 0xC818CFB4L)), (safe_add_func_uint8_t_u_u (g_2388[1], 0xF8L)))), g_1266)) | 1L) > g_4847)))))), 7))) || 0xA2L) & 1UL), g_513[1]));
     l_4556
       =
       (l_4276
        =
        0x602EBE76L);
   }
   else
   {
     int8_t
       l_4849
       =
       0L;
     l_4849
       =
       g_4848
       [2];
     l_4854
       =
       (l_4576
        =
        ((safe_rshift_func_int8_t_s_s (l_4776[5], 7)) & (8UL & ((g_30 = g_300) > (safe_lshift_func_int16_t_s_s ((-8L), 10))))));
     l_4806
       [2]
       =
       (((safe_mul_func_int8_t_s_s (l_4660, (!(safe_mul_func_int16_t_s_s (l_4849, g_658))))) ^ (((0xC5L == (~2UL)) >= (safe_rshift_func_int16_t_s_s ((safe_rshift_func_uint8_t_u_s ((safe_mod_func_int8_t_s_s ((g_4614 = (safe_sub_func_uint16_t_u_u (((safe_lshift_func_int16_t_s_s (0x8868L, ((safe_mod_func_uint8_t_u_u ((safe_add_func_uint16_t_u_u (((safe_mul_func_int8_t_s_s (((safe_lshift_func_int8_t_s_u ((safe_mul_func_uint8_t_u_u ((((g_2065 = (g_697[4][0] > ((0x9E60L | (safe_lshift_func_int16_t_s_u (l_4854, 1))) ^ l_4513))) && l_4849) < g_4401), g_300)), l_4777[2][3])) & l_4382), 0L)) ^ l_4581[0]), 0UL)), 0xD8L)) & l_4693))) < 0x9AL), g_344))), l_4693)), g_1281)), 15))) != g_555)) | g_2066[5]);
     g_300
       =
       l_4849;
   }
 }
 else
 {
   int32_t
     l_4886
     =
     0x9877833CL;
   uint8_t
     l_4894
     =
     0xE8L;
   int32_t
     l_4919
     =
     0xB9D29664L;
   uint32_t
     l_4930
     =
     1UL;
   l_4807
     =
     (l_4660
      |
      ((safe_unary_minus_func_int32_t_s (((g_930 = (safe_rshift_func_int16_t_s_s ((!(!g_4848[4])), (g_1835[0][5][4] = ((safe_mul_func_uint16_t_u_u (((((((((l_4886 == (safe_mul_func_uint16_t_u_u ((g_774 = (safe_rshift_func_int16_t_s_u ((g_4893 = (((safe_mod_func_uint16_t_u_u ((g_2066[6] <= l_4666), 1UL)) | g_2066[7]) || (l_4556 || (+(((((((~(g_2004[0][0][2] & 0x1AC637C7L)) <= 0xCF45E29BL) <= g_2066[6]) == 0x1EL) == g_2004[1][0][0]) <= l_4693) >= 1UL))))), l_4480))), 1UL))) > 1UL) ^ g_521) <= l_4666) != g_866) >= l_4777[1][3]) && l_4808[1][4][1]) | l_4382), g_4401)) <= 0x6D75L))))) && l_4894))) & 0xB931A8B1L));
   l_4886
     =
     ((safe_mod_func_uint8_t_u_u (((0xE986L != g_4460) > ((safe_mod_func_int8_t_s_s (((+(safe_mul_func_uint8_t_u_u ((safe_rshift_func_uint8_t_u_s ((safe_mod_func_uint32_t_u_u ((l_4808[1][4][1] ^ (((l_4690 = (safe_rshift_func_int16_t_s_u ((g_1835[0][3][2] = (+(l_4513 == (safe_rshift_func_int8_t_s_s ((-1L), 3))))), (g_774 = (safe_add_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_s ((65527UL | 0xCDDEL), (l_4918 = ((!g_458) & (g_4848[2] = (safe_sub_func_int32_t_s_s (((+(safe_add_func_int16_t_s_s (l_4917, l_4727))) ^ g_367), g_1810[0]))))))), l_4792)))))) >= g_3350) >= 0x7E0FL)), 0xE7B6B0F0L)), 5)), g_300))) != l_4919), g_555)) | 4294967295UL)), 0x51L)) && l_4727);
   if (l_4480)
     continue;
   l_4932
     =
     (g_4663
      =
      ((safe_add_func_uint16_t_u_u (l_4792, ((safe_mod_func_int32_t_s_s ((l_4576 = (((g_774 = g_588) ^ ((safe_add_func_uint32_t_u_u (((safe_lshift_func_int16_t_s_u (l_4581[0], ((g_344 < g_3691) || (l_4930 = (safe_lshift_func_uint16_t_u_s (l_4918, g_721[5])))))) < (g_588 || (safe_unary_minus_func_uint16_t_u (g_978)))), 5L)) | 1L)) > 0xF168L)), l_4806[2])) ^ 0x85L))) >= 0xD9L));
 }
      }
    }
  }
l_2
      [i]
      =
      0x2062L;
      for
 (g_4460
  =
  0;
  (g_4460
   <=
   1);
  g_4460
  +=
  1)
      {
 uint32_t
   l_4666
   =
   0xF0D0EFCCL;
 int32_t
   l_4690
   =
   0x1027F16CL;
 uint8_t
   l_4727
   =
   0UL;
 int32_t
   l_4806
   [3];
 int
   i;
for
 (i
  =
  0;
  i
  <
  1;
  i++)
 l_4581
   [i]
   =
   4294967295UL;
 if (((g_555 | (safe_add_func_int16_t_s_s ((0x5CB7L >= ((~l_4666) & (l_4576 = (safe_sub_func_int32_t_s_s (((safe_add_func_uint8_t_u_u ((l_4693 = ((0x9F77A192L && l_4576) || (((safe_sub_func_int32_t_s_s (((safe_mod_func_uint32_t_u_u ((safe_sub_func_int16_t_s_s ((safe_rshift_func_uint16_t_u_u ((g_367 > (!(g_2388[1] & ((((l_4690 = l_4277) <= ((l_4556 = (safe_sub_func_int16_t_s_s ((0xBCL <= l_4556), 1UL))) >= 0x9A4BBC0FL)) | 0x6475L) < g_1266)))), g_3)), g_697[8][0])), g_866)) && 0x7F72261DL), g_1281)) & l_4642) && g_71[5]))), g_458)) > 249UL), l_4666))))), l_4660))) == g_866))
 {
   uint8_t
     l_4706
     =
     0xDDL;
   int8_t
     l_4713
     [10]
     =
     {
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L
       };
   int
     i;
   g_1782
     =
     (safe_sub_func_int8_t_s_s
      (((((safe_rshift_func_uint8_t_u_s (l_4576, 0)) != g_4512) | l_4642) & (safe_add_func_uint32_t_u_u ((0L != ((safe_sub_func_uint8_t_u_u (g_2248, (l_4706 ^ (((~(-7L)) < (((g_71[7] = ((safe_mul_func_int16_t_s_s (((g_3691 | ((safe_mul_func_uint16_t_u_u ((l_4556 = (safe_rshift_func_uint8_t_u_s (((((l_4706 != g_3350) < 4294967295UL) < g_2248) & g_71[7]), 1))), (-1L))) >= g_4401)) < l_4690), g_2066[3])) >= l_4713[5])) || 0xAD3DCE01L) > g_697[6][1])) ^ g_774)))) & l_4632)), g_201))), l_4642));
{
    int32_t
      l_4556
      =
      0x6787A757L;
    int32_t
      l_4576
      =
      0x18CCC61BL;
    uint32_t
      l_4660
      =
      0x8A0641B2L;
    uint32_t
      l_4792
      =
      0UL;
    uint8_t
      l_4918
      =
      0xA7L;
    l_4556
      =
      (l_4276
       =
       g_2373);
    g_1763
      =
      (((safe_unary_minus_func_uint16_t_u ((+((safe_mod_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s ((safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u ((((l_4576 = ((g_1266 = (((g_1782 = (safe_rshift_func_uint8_t_u_u ((l_4279 = g_1810[0]), (l_4556 == (l_4261 == (l_4276 = (g_3691 = (+(!0x8DL))))))))) >= (g_513[1] = 2UL)) && ((-1L) && (safe_add_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((g_774 = l_4513) >= (g_920 && (((safe_sub_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_u ((((g_555 > 0x09L) ^ g_930) > 1UL), g_329[1][0][0])), g_920)) >= l_2[0]) >= l_4261))) && l_4513), g_697[8][0])) <= l_4556), l_4576))))) <= l_4511)) || g_3350) >= l_4261), g_71[2])), l_4556)), 5)), g_1281)) ^ 7L)))) | g_669) >= l_4556);
    l_4279
      =
      l_4576;
    for
      (g_367
       =
       0;
       (g_367
 <=
 1);
       g_367
       +=
       1)
    {
      uint32_t
 l_4581
 [1];
      uint16_t
 l_4642
 =
 65530UL;
      int32_t
 l_4775
 =
 0L;
      int16_t
 l_4776
 [9];
      int32_t
 l_4777
 [8]
 [6]
 =
 {
    {1L,
     4L,
     4L,
     1L,
     (-3L),
     0x92B5B022L}
      , {0x92B5B022L, 1L, 1L, 1L, 0x92B5B022L, (-1L)}
      , {1L, 0x92B5B022L, (-1L), (-1L), 0x92B5B022L, 1L}
      , {4L, 1L, (-3L), 0x92B5B022L, (-3L), 1L}
      , {(-3L), 4L, (-1L), 1L, 1L, (-1L)}
      , {(-3L), (-3L), 1L, 0x92B5B022L, 0x56D2AD28L, 0x92B5B022L}
      , {4L, (-3L), 4L, (-1L), 1L, 1L}
      , {1L, 4L, 4L, 1L, (-3L), 0x92B5B022L}
      };
      int32_t
 l_4807
 =
 (-4L);
      int32_t
 l_4808
 [2]
 [6]
 [8]
 =
 {
    {{9L, (-1L), (-1L), 9L, 9L, (-1L), (-1L), 9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     ,
     {9L,
      (-1L),
      (-1L),
      9L,
      9L,
      (-1L),
      (-1L),
      9L}
     }
      , {{9L, (-1L), (-1L), 9L, 9L, (-1L), (-1L), 9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  ,
  {9L,
   (-1L),
   (-1L),
   9L,
   9L,
   (-1L),
   (-1L),
   9L}
  }
      };
      int8_t
 l_4932
 =
 1L;
      int
 i,
        j,
        k;
      for
 (i
  =
  0;
  i
  <
  1;
  i++)
 l_4581
   [i]
   =
   4294967295UL;
      for
 (i
  =
  0;
  i
  <
  9;
  i++)
 l_4776
   [i]
   =
   0L;
      for
 (g_521
  =
  0;
  (g_521
   <=
   8);
  g_521
  +=
  1)
      {
 uint16_t
   l_4662
   =
   65535UL;
 int
   i;
 g_71
   [(g_367 + 6)] = (safe_lshift_func_int16_t_s_s (((safe_mul_func_uint16_t_u_u (g_721[(g_367 + 1)], g_721[g_521])) | (g_4460 = (0x9FL == l_4581[0]))), (safe_mul_func_uint16_t_u_u ((safe_unary_minus_func_uint32_t_u ((g_3847 = l_4382))), ((((safe_rshift_func_int8_t_s_s ((((l_4279 = g_721[g_521]) > l_4513) ^ g_721[(g_367 + 1)]), l_4382)) | g_2617) != 0xFFL) <= 0xF0ECL)))));
 if ((safe_add_func_int8_t_s_s ((((safe_add_func_uint16_t_u_u (((g_697[8][0] = (safe_rshift_func_uint16_t_u_u (g_71[7], (((safe_mul_func_uint16_t_u_u ((((g_329[1][0][0] = (0UL || (safe_add_func_uint8_t_u_u ((safe_add_func_uint16_t_u_u ((safe_unary_minus_func_int32_t_s (g_2373)), ((-1L) < ((g_2065 = l_4261) > (-1L))))), (~g_2004[0][0][2]))))) > (safe_sub_func_uint16_t_u_u ((((g_920 = (safe_lshift_func_uint16_t_u_u ((g_774 = ((safe_rshift_func_uint8_t_u_s ((safe_mul_func_int8_t_s_s (((safe_rshift_func_int8_t_s_s ((g_4460 = (safe_rshift_func_uint8_t_u_u ((((l_4279 && (0x22CDF452L > g_1835[0][1][0])) <= 0xBE08C71AL) <= 0xAC129E78L), g_71[0]))), 3)) == l_4556), l_4576)), g_978)) != l_4261)), g_521))) <= g_1917) >= 0xD6L), 65526UL))) || l_4382), 9L)) | l_4556) > (-1L))))) == g_721[g_521]), 0UL)) >= g_1835[0][2][2]) < l_4581[0]), g_721[(g_367 + 1)])))
 {
   uint8_t
     l_4617
     =
     6UL;
   int32_t
     l_4634
     =
     1L;
   int32_t
     l_4635
     =
     0L;
   if (((safe_rshift_func_int8_t_s_s (((-6L) >= g_4614), 4)) < (g_2004[0][0][2] = 0L)))
   {
     uint8_t
       l_4618
       =
       0x01L;
     l_4618
       =
       (l_4617
        =
        (safe_rshift_func_int16_t_s_u
  (7L,
   13)));
   }
   else
   {
     return
       g_2373;
   }
   g_300
     =
     (safe_mod_func_uint8_t_u_u
      (8UL,
       (safe_add_func_uint32_t_u_u
        (((l_4276 = (g_458 > g_555)) <= l_4279), g_30))));
   for
     (g_1266
      =
      0;
      (g_1266
       <=
       1);
      g_1266
      +=
      1)
   {
     int32_t
       l_4633
       =
       (-8L);
     if (l_4277)
       break;
     if (l_4617)
       continue;
     l_4635
       =
       (g_71
        [7]
        =
        ((((l_4634 = (!(safe_add_func_int8_t_s_s (l_4581[0], (((safe_mod_func_int16_t_s_s (l_4576, (l_4576 ^ l_4556))) != (l_4617 > ((((safe_mod_func_uint32_t_u_u (((safe_unary_minus_func_int32_t_s ((safe_mul_func_uint8_t_u_u (g_71[(g_367 + 6)], g_555)))) >= l_4632), l_4633)) || 0x5405DB9DL) ^ g_30) > l_4617))) >= l_4633))))) || l_4617) != g_1382) != g_721[8]));
     g_1763
       =
       l_4581
       [0];
   }
 }
 else
 {
   uint32_t
     l_4647
     =
     0xD428E22EL;
   if ((safe_lshift_func_uint8_t_u_u ((4294967288UL <= (g_1810[0] < (safe_sub_func_uint8_t_u_u ((((+((0x5C358E21L > ((safe_mul_func_uint8_t_u_u (((g_4512 < (l_4642 = 0L)) & g_721[(g_367 + 1)]), ((safe_add_func_uint32_t_u_u ((safe_rshift_func_int16_t_s_s (l_4576, 14)), (g_2580 = ((g_930 = (l_4556 = (g_1266 ^ (g_697[7][0] = (g_2065 = l_4647))))) < 0UL)))) && 3UL))) == 0x984EL)) & 253UL)) ^ g_721[(g_367 + 1)]) | 0x12CCB0D5L), 0xAFL)))), g_721[g_521])))
   {
     return
       g_2065;
   }
   else
   {
     l_4576
       =
       g_513
       [5];
     return
       g_513
       [6];
   }
 }
 g_3
   =
   (safe_sub_func_int8_t_s_s
    (((((g_71[(g_367 + 6)] = (safe_mul_func_int16_t_s_s (l_4581[0], (safe_mod_func_int16_t_s_s (g_30, (((safe_mul_func_uint8_t_u_u (g_3847, ((g_4401 <= ((l_4261 >= (((0x7CA4L > (safe_lshift_func_int8_t_s_u ((!(!g_300)), ((safe_rshift_func_uint8_t_u_s (g_329[1][2][5], 7)) | (l_4660 = g_774))))) > l_4661) >= 0x421625CCL)) != l_4662)) < g_71[(g_367 + 6)]))) & 0x38431C89L) | 0L)))))) != 7L) != l_4576) >= 0x2A6EAC5BL), g_2066[7]));
      }
      for
 (g_4460
  =
  0;
  (g_4460
   <=
   1);
  g_4460
  +=
  1)
      {
 uint32_t
   l_4666
   =
   0xF0D0EFCCL;
 int32_t
   l_4690
   =
   0x1027F16CL;
 uint8_t
   l_4727
   =
   0UL;
 int32_t
   l_4806
   [3];
 int
   i;
 for
   (i
    =
    0;
    i
    <
    3;
    i++)
   l_4806
     [i]
     =
     0L;
 l_4279
   =
   (g_4663
    =
    (((g_4663 < ((safe_add_func_int32_t_s_s ((l_4642 & l_4642), l_4666)) < ((safe_mul_func_int8_t_s_s (g_1835[0][5][2], ((safe_add_func_int8_t_s_s (l_4666, ((safe_sub_func_int8_t_s_s (7L, (safe_sub_func_uint8_t_u_u (0xCAL, ((safe_unary_minus_func_int16_t_s (g_2004[0][0][2])) >= g_71[7]))))) && 0x37A2L))) || (-1L)))) <= l_4666))) & (-1L)) <= g_2617));
 if (((g_555 | (safe_add_func_int16_t_s_s ((0x5CB7L >= ((~l_4666) & (l_4576 = (safe_sub_func_int32_t_s_s (((safe_add_func_uint8_t_u_u ((l_4693 = ((0x9F77A192L && l_4576) || (((safe_sub_func_int32_t_s_s (((safe_mod_func_uint32_t_u_u ((safe_sub_func_int16_t_s_s ((safe_rshift_func_uint16_t_u_u ((g_367 > (!(g_2388[1] & ((((l_4690 = l_4277) <= ((l_4556 = (safe_sub_func_int16_t_s_s ((0xBCL <= l_4556), 1UL))) >= 0x9A4BBC0FL)) | 0x6475L) < g_1266)))), g_3)), g_697[8][0])), g_866)) && 0x7F72261DL), g_1281)) & l_4642) && g_71[5]))), g_458)) > 249UL), l_4666))))), l_4660))) == g_866))
 {
   uint8_t
     l_4706
     =
     0xDDL;
   int8_t
     l_4713
     [10]
     =
     {
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L
       };
   int
     i;
   g_71
     [7]
     =
     (safe_add_func_int32_t_s_s
      (0xE8FC7F13L,
       (safe_mul_func_uint16_t_u_u
        (g_2248,
  ((g_774 & 3UL) < l_4556)))));
   g_1782
     =
     (safe_sub_func_int8_t_s_s
      (((((safe_rshift_func_uint8_t_u_s (l_4576, 0)) != g_4512) | l_4642) & (safe_add_func_uint32_t_u_u ((0L != ((safe_sub_func_uint8_t_u_u (g_2248, (l_4706 ^ (((~(-7L)) < (((g_71[7] = ((safe_mul_func_int16_t_s_s (((g_3691 | ((safe_mul_func_uint16_t_u_u ((l_4556 = (safe_rshift_func_uint8_t_u_s (((((l_4706 != g_3350) < 4294967295UL) < g_2248) & g_71[7]), 1))), (-1L))) >= g_4401)) < l_4690), g_2066[3])) >= l_4713[5])) || 0xAD3DCE01L) > g_697[6][1])) ^ g_774)))) & l_4632)), g_201))), l_4642));
   for
     (g_3117
      =
      0;
      (g_3117
       <=
       1);
      g_3117
      +=
      1)
   {
     int8_t
       l_4720
       =
       0xF6L;
     int32_t
       l_4725
       =
       0x507E5A08L;
     g_71
       [5]
       =
       g_1266;
     g_71
       [7]
       =
       ((((safe_mod_func_uint32_t_u_u ((((l_4279 & ((((safe_sub_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_s ((((l_4726 = (l_4720 && (l_4706 & (l_4725 = (safe_add_func_int16_t_s_s ((safe_add_func_int16_t_s_s (0x9C19L, ((((0xAF8158EEL >= (l_4276 = (((!l_4666) == 0x5CL) ^ (g_3847 = (+(g_3691 && (g_1810[0] = ((l_4690 = 8UL) & l_4720)))))))) > 1UL) == g_2065) <= 0xE6L))), 0UL)))))) >= (-4L)) <= l_4713[6]), 4)) & l_4720), l_4642)) ^ g_669) <= (-1L)) | g_71[0])) >= 0x928DF89BL) == 0x12L), g_1281)) | 254UL) <= l_4727) ^ l_4642);
     if (g_4512)
       continue;
     if (g_3350)
       break;
   }
   g_71
     [7]
     =
     ((((255UL | ((safe_lshift_func_int8_t_s_s (9L, 1)) == (g_344 = (((safe_rshift_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u (g_1810[0], (1L != ((l_4581[0] >= ((0x447EL == ((-1L) <= g_38)) | (safe_lshift_func_int16_t_s_s (g_2004[0][0][2], l_4690)))) && 0xE0L)))), 13)) <= g_54) && g_697[8][0])))) ^ (-1L)) & l_4576) ^ g_201);
 }
 else
 {
   int8_t
     l_4738
     =
     5L;
   int32_t
     l_4739
     =
     0L;
   if (l_4480)
     break;
   g_4663
     =
     (0x61CEL
      ^
      (safe_mul_func_uint8_t_u_u
       (((l_4279 = (l_4642 & (l_4276 = ((((((l_4739 = (~l_4738)) <= (g_30 = (safe_lshift_func_int16_t_s_u (4L, 12)))) != (safe_mul_func_int8_t_s_s (((safe_mod_func_int8_t_s_s (((safe_mul_func_uint16_t_u_u ((((safe_mod_func_uint32_t_u_u (l_4642, 0x6056CDD7L)) ^ (0xF54BL && (safe_add_func_int8_t_s_s ((safe_sub_func_uint16_t_u_u ((safe_add_func_uint16_t_u_u ((g_697[8][0] ^ (((~(safe_add_func_uint16_t_u_u (g_3847, g_774))) && 0xCDL) == 1L)), (-1L))), g_1763)), g_521)))) ^ 0UL), l_4666)) && g_513[1]), l_4642)) & g_458), g_588))) & g_697[8][0]) | l_4690) > l_4581[0])))) < 3UL), 3L)));
   for
     (l_4693
      =
      0;
      (l_4693
       <=
       1);
      l_4693
      +=
      1)
   {
     int16_t
       l_4760
       =
       0xBA9EL;
     g_1763
       =
       (safe_mod_func_uint16_t_u_u
        (g_588,
  0xA221L));
     l_4777
       [2]
       [3]
       =
       (l_4760
        ==
        (g_300
  >=
  ((+0x2213L) && (safe_add_func_uint16_t_u_u ((g_774 = (safe_rshift_func_int8_t_s_u ((safe_lshift_func_uint8_t_u_s (((safe_mul_func_uint16_t_u_u (l_4581[0], ((safe_rshift_func_uint16_t_u_u (6UL, ((safe_mod_func_int32_t_s_s ((safe_mod_func_uint32_t_u_u ((g_920 = (l_4576 == l_4739)), g_4460)), l_4775)) != g_300))) == 1UL))) != 1L), 5)), 3))), l_4776[5])))));
   }
 }
 for
   (g_1917
    =
    0;
    (g_1917
     <=
     1);
    g_1917
    +=
    1)
 {
   int8_t
     l_4778
     =
     8L;
   l_4279
     =
     ((l_4778 == 0L) || (safe_sub_func_uint32_t_u_u (((+(l_4726 = (safe_rshift_func_int8_t_s_s (g_1281, 0)))) ^ ((safe_mul_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s (0x01L, l_4727)), ((g_30 = (safe_unary_minus_func_int8_t_s (g_1382))) | g_3117))) > ((safe_rshift_func_int8_t_s_u (((g_1266 = (safe_mod_func_uint16_t_u_u (l_4576, g_300))) <= 0x303FL), l_4792)) & g_521))), g_71[7])));
 }
 if (((g_1266 = (0x90L | 0xC0L)) >= ((safe_mod_func_int32_t_s_s (((l_4690 = ((safe_unary_minus_func_uint16_t_u ((safe_sub_func_uint16_t_u_u (65535UL, l_4279)))) < (l_4777[7][5] ^ (g_300 != l_4727)))) >= ((safe_unary_minus_func_int8_t_s ((safe_unary_minus_func_uint16_t_u ((safe_rshift_func_uint8_t_u_s (((((((0x8A25F2B6L && ((safe_lshift_func_int16_t_s_s (((l_4807 = (g_329[1][0][0] = (safe_rshift_func_int8_t_s_u ((l_4806[2] = l_4727), 2)))) & g_1265[2][5]), 9)) > 249UL)) ^ l_4808[1][4][1]) <= g_1782) & 3L) == g_71[7]) >= g_866), 5)))))) <= 0xAED4EAB5L)), l_4808[0][5][6])) != l_4576)))
 {
   int8_t
     l_4854
     =
     (-4L);
   if (g_4401)
   {
     l_4806
       [2]
       =
       ((g_201 > (g_4663 == (((safe_add_func_uint8_t_u_u ((+((safe_sub_func_uint16_t_u_u ((l_4777[2][5] = (g_774 = (safe_mul_func_int8_t_s_s (((g_2004[0][0][2] = ((safe_mod_func_uint16_t_u_u (g_978, (safe_lshift_func_uint16_t_u_s (g_774, (safe_sub_func_int32_t_s_s ((safe_rshift_func_int8_t_s_u ((safe_sub_func_uint16_t_u_u ((safe_lshift_func_uint16_t_u_u (0x8535L, 7)), ((l_4690 = (g_4663 > ((g_1266 = 0x3242L) ^ (+g_1835[0][6][4])))) | (g_2248 != g_2004[0][0][2])))), 7)), 0x5725F8BEL)))))) && l_4576)) <= 1UL), g_4401)))), l_4792)) != 0UL)), g_555)) >= 0x8CL) > g_697[8][0]))) != (-1L));
     g_1763
       =
       (safe_add_func_uint32_t_u_u
        ((((g_4460 > (safe_lshift_func_int8_t_s_s ((safe_mul_func_int8_t_s_s (0xDFL, (g_3117 <= (l_4576 = (g_978 > (((safe_lshift_func_int16_t_s_s ((safe_lshift_func_int16_t_s_s ((safe_add_func_uint32_t_u_u ((safe_add_func_int8_t_s_s (g_1810[0], (safe_add_func_uint8_t_u_u (0x62L, 0x86L)))), 0xC818CFB4L)), (safe_add_func_uint8_t_u_u (g_2388[1], 0xF8L)))), g_1266)) | 1L) > g_4847)))))), 7))) || 0xA2L) & 1UL), g_513[1]));
     l_4556
       =
       (l_4276
        =
        0x602EBE76L);
   }
   else
   {
     int8_t
       l_4849
       =
       0L;
     l_4849
       =
       g_4848
       [2];
     l_4854
       =
       (l_4576
        =
        ((safe_rshift_func_int8_t_s_s (l_4776[5], 7)) & (8UL & ((g_30 = g_300) > (safe_lshift_func_int16_t_s_s ((-8L), 10))))));
     l_4806
       [2]
       =
       (((safe_mul_func_int8_t_s_s (l_4660, (!(safe_mul_func_int16_t_s_s (l_4849, g_658))))) ^ (((0xC5L == (~2UL)) >= (safe_rshift_func_int16_t_s_s ((safe_rshift_func_uint8_t_u_s ((safe_mod_func_int8_t_s_s ((g_4614 = (safe_sub_func_uint16_t_u_u (((safe_lshift_func_int16_t_s_s (0x8868L, ((safe_mod_func_uint8_t_u_u ((safe_add_func_uint16_t_u_u (((safe_mul_func_int8_t_s_s (((safe_lshift_func_int8_t_s_u ((safe_mul_func_uint8_t_u_u ((((g_2065 = (g_697[4][0] > ((0x9E60L | (safe_lshift_func_int16_t_s_u (l_4854, 1))) ^ l_4513))) && l_4849) < g_4401), g_300)), l_4777[2][3])) & l_4382), 0L)) ^ l_4581[0]), 0UL)), 0xD8L)) & l_4693))) < 0x9AL), g_344))), l_4693)), g_1281)), 15))) != g_555)) | g_2066[5]);
     g_300
       =
       l_4849;
   }
 }
 else
 {
   int32_t
     l_4886
     =
     0x9877833CL;
   uint8_t
     l_4894
     =
     0xE8L;
   int32_t
     l_4919
     =
     0xB9D29664L;
   uint32_t
     l_4930
     =
     1UL;
   l_4807
     =
     (l_4660
      |
      ((safe_unary_minus_func_int32_t_s (((g_930 = (safe_rshift_func_int16_t_s_s ((!(!g_4848[4])), (g_1835[0][5][4] = ((safe_mul_func_uint16_t_u_u (((((((((l_4886 == (safe_mul_func_uint16_t_u_u ((g_774 = (safe_rshift_func_int16_t_s_u ((g_4893 = (((safe_mod_func_uint16_t_u_u ((g_2066[6] <= l_4666), 1UL)) | g_2066[7]) || (l_4556 || (+(((((((~(g_2004[0][0][2] & 0x1AC637C7L)) <= 0xCF45E29BL) <= g_2066[6]) == 0x1EL) == g_2004[1][0][0]) <= l_4693) >= 1UL))))), l_4480))), 1UL))) > 1UL) ^ g_521) <= l_4666) != g_866) >= l_4777[1][3]) && l_4808[1][4][1]) | l_4382), g_4401)) <= 0x6D75L))))) && l_4894))) & 0xB931A8B1L));
   l_4886
     =
     ((safe_mod_func_uint8_t_u_u (((0xE986L != g_4460) > ((safe_mod_func_int8_t_s_s (((+(safe_mul_func_uint8_t_u_u ((safe_rshift_func_uint8_t_u_s ((safe_mod_func_uint32_t_u_u ((l_4808[1][4][1] ^ (((l_4690 = (safe_rshift_func_int16_t_s_u ((g_1835[0][3][2] = (+(l_4513 == (safe_rshift_func_int8_t_s_s ((-1L), 3))))), (g_774 = (safe_add_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_s ((65527UL | 0xCDDEL), (l_4918 = ((!g_458) & (g_4848[2] = (safe_sub_func_int32_t_s_s (((+(safe_add_func_int16_t_s_s (l_4917, l_4727))) ^ g_367), g_1810[0]))))))), l_4792)))))) >= g_3350) >= 0x7E0FL)), 0xE7B6B0F0L)), 5)), g_300))) != l_4919), g_555)) | 4294967295UL)), 0x51L)) && l_4727);
   if (l_4480)
     continue;
   l_4932
     =
     (g_4663
      =
      ((safe_add_func_uint16_t_u_u (l_4792, ((safe_mod_func_int32_t_s_s ((l_4576 = (((g_774 = g_588) ^ ((safe_add_func_uint32_t_u_u (((safe_lshift_func_int16_t_s_u (l_4581[0], ((g_344 < g_3691) || (l_4930 = (safe_lshift_func_uint16_t_u_s (l_4918, g_721[5])))))) < (g_588 || (safe_unary_minus_func_uint16_t_u (g_978)))), 5L)) | 1L)) > 0xF168L)), l_4806[2])) ^ 0x85L))) >= 0xD9L));
 }
      }
    }
  }
g_71
     [7]
     =
     (safe_add_func_int32_t_s_s
      (0xE8FC7F13L,
       (safe_mul_func_uint16_t_u_u
        (g_2248,
  ((g_774 & 3UL) < l_4556)))));
 }
 else
 {
   int8_t
     l_4738
     =
     5L;
   int32_t
     l_4739
     =
     0L;
{
 uint32_t
   l_4666
   =
   0xF0D0EFCCL;
 int32_t
   l_4690
   =
   0x1027F16CL;
 uint8_t
   l_4727
   =
   0UL;
 int32_t
   l_4806
   [3];
 int
   i;
 for
   (i
    =
    0;
    i
    <
    3;
    i++)
   l_4806
     [i]
     =
     0L;
 l_4279
   =
   (g_4663
    =
    (((g_4663 < ((safe_add_func_int32_t_s_s ((l_4642 & l_4642), l_4666)) < ((safe_mul_func_int8_t_s_s (g_1835[0][5][2], ((safe_add_func_int8_t_s_s (l_4666, ((safe_sub_func_int8_t_s_s (7L, (safe_sub_func_uint8_t_u_u (0xCAL, ((safe_unary_minus_func_int16_t_s (g_2004[0][0][2])) >= g_71[7]))))) && 0x37A2L))) || (-1L)))) <= l_4666))) & (-1L)) <= g_2617));
 if (((g_555 | (safe_add_func_int16_t_s_s ((0x5CB7L >= ((~l_4666) & (l_4576 = (safe_sub_func_int32_t_s_s (((safe_add_func_uint8_t_u_u ((l_4693 = ((0x9F77A192L && l_4576) || (((safe_sub_func_int32_t_s_s (((safe_mod_func_uint32_t_u_u ((safe_sub_func_int16_t_s_s ((safe_rshift_func_uint16_t_u_u ((g_367 > (!(g_2388[1] & ((((l_4690 = l_4277) <= ((l_4556 = (safe_sub_func_int16_t_s_s ((0xBCL <= l_4556), 1UL))) >= 0x9A4BBC0FL)) | 0x6475L) < g_1266)))), g_3)), g_697[8][0])), g_866)) && 0x7F72261DL), g_1281)) & l_4642) && g_71[5]))), g_458)) > 249UL), l_4666))))), l_4660))) == g_866))
 {
   uint8_t
     l_4706
     =
     0xDDL;
   int8_t
     l_4713
     [10]
     =
     {
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L,
  5L
       };
   int
     i;
   g_71
     [7]
     =
     (safe_add_func_int32_t_s_s
      (0xE8FC7F13L,
       (safe_mul_func_uint16_t_u_u
        (g_2248,
  ((g_774 & 3UL) < l_4556)))));
   g_1782
     =
     (safe_sub_func_int8_t_s_s
      (((((safe_rshift_func_uint8_t_u_s (l_4576, 0)) != g_4512) | l_4642) & (safe_add_func_uint32_t_u_u ((0L != ((safe_sub_func_uint8_t_u_u (g_2248, (l_4706 ^ (((~(-7L)) < (((g_71[7] = ((safe_mul_func_int16_t_s_s (((g_3691 | ((safe_mul_func_uint16_t_u_u ((l_4556 = (safe_rshift_func_uint8_t_u_s (((((l_4706 != g_3350) < 4294967295UL) < g_2248) & g_71[7]), 1))), (-1L))) >= g_4401)) < l_4690), g_2066[3])) >= l_4713[5])) || 0xAD3DCE01L) > g_697[6][1])) ^ g_774)))) & l_4632)), g_201))), l_4642));
   for
     (g_3117
      =
      0;
      (g_3117
       <=
       1);
      g_3117
      +=
      1)
   {
     int8_t
       l_4720
       =
       0xF6L;
     int32_t
       l_4725
       =
       0x507E5A08L;
     g_71
       [5]
       =
       g_1266;
     g_71
       [7]
       =
       ((((safe_mod_func_uint32_t_u_u ((((l_4279 & ((((safe_sub_func_uint32_t_u_u (((safe_lshift_func_int8_t_s_s ((((l_4726 = (l_4720 && (l_4706 & (l_4725 = (safe_add_func_int16_t_s_s ((safe_add_func_int16_t_s_s (0x9C19L, ((((0xAF8158EEL >= (l_4276 = (((!l_4666) == 0x5CL) ^ (g_3847 = (+(g_3691 && (g_1810[0] = ((l_4690 = 8UL) & l_4720)))))))) > 1UL) == g_2065) <= 0xE6L))), 0UL)))))) >= (-4L)) <= l_4713[6]), 4)) & l_4720), l_4642)) ^ g_669) <= (-1L)) | g_71[0])) >= 0x928DF89BL) == 0x12L), g_1281)) | 254UL) <= l_4727) ^ l_4642);
     if (g_4512)
       continue;
     if (g_3350)
       break;
   }
   g_71
     [7]
     =
     ((((255UL | ((safe_lshift_func_int8_t_s_s (9L, 1)) == (g_344 = (((safe_rshift_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u (g_1810[0], (1L != ((l_4581[0] >= ((0x447EL == ((-1L) <= g_38)) | (safe_lshift_func_int16_t_s_s (g_2004[0][0][2], l_4690)))) && 0xE0L)))), 13)) <= g_54) && g_697[8][0])))) ^ (-1L)) & l_4576) ^ g_201);
 }
 else
 {
   int8_t
     l_4738
     =
     5L;
   int32_t
     l_4739
     =
     0L;
   if (l_4480)
     break;
   g_4663
     =
     (0x61CEL
      ^
      (safe_mul_func_uint8_t_u_u
       (((l_4279 = (l_4642 & (l_4276 = ((((((l_4739 = (~l_4738)) <= (g_30 = (safe_lshift_func_int16_t_s_u (4L, 12)))) != (safe_mul_func_int8_t_s_s (((safe_mod_func_int8_t_s_s (((safe_mul_func_uint16_t_u_u ((((safe_mod_func_uint32_t_u_u (l_4642, 0x6056CDD7L)) ^ (0xF54BL && (safe_add_func_int8_t_s_s ((safe_sub_func_uint16_t_u_u ((safe_add_func_uint16_t_u_u ((g_697[8][0] ^ (((~(safe_add_func_uint16_t_u_u (g_3847, g_774))) && 0xCDL) == 1L)), (-1L))), g_1763)), g_521)))) ^ 0UL), l_4666)) && g_513[1]), l_4642)) & g_458), g_588))) & g_697[8][0]) | l_4690) > l_4581[0])))) < 3UL), 3L)));
   for
     (l_4693
      =
      0;
      (l_4693
       <=
       1);
      l_4693
      +=
      1)
   {
     int16_t
       l_4760
       =
       0xBA9EL;
     g_1763
       =
       (safe_mod_func_uint16_t_u_u
        (g_588,
  0xA221L));
     l_4777
       [2]
       [3]
       =
       (l_4760
        ==
        (g_300
  >=
  ((+0x2213L) && (safe_add_func_uint16_t_u_u ((g_774 = (safe_rshift_func_int8_t_s_u ((safe_lshift_func_uint8_t_u_s (((safe_mul_func_uint16_t_u_u (l_4581[0], ((safe_rshift_func_uint16_t_u_u (6UL, ((safe_mod_func_int32_t_s_s ((safe_mod_func_uint32_t_u_u ((g_920 = (l_4576 == l_4739)), g_4460)), l_4775)) != g_300))) == 1UL))) != 1L), 5)), 3))), l_4776[5])))));
   }
 }
 for
   (g_1917
    =
    0;
    (g_1917
     <=
     1);
    g_1917
    +=
    1)
 {
   int8_t
     l_4778
     =
     8L;
   l_4279
     =
     ((l_4778 == 0L) || (safe_sub_func_uint32_t_u_u (((+(l_4726 = (safe_rshift_func_int8_t_s_s (g_1281, 0)))) ^ ((safe_mul_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s (0x01L, l_4727)), ((g_30 = (safe_unary_minus_func_int8_t_s (g_1382))) | g_3117))) > ((safe_rshift_func_int8_t_s_u (((g_1266 = (safe_mod_func_uint16_t_u_u (l_4576, g_300))) <= 0x303FL), l_4792)) & g_521))), g_71[7])));
 }
 if (((g_1266 = (0x90L | 0xC0L)) >= ((safe_mod_func_int32_t_s_s (((l_4690 = ((safe_unary_minus_func_uint16_t_u ((safe_sub_func_uint16_t_u_u (65535UL, l_4279)))) < (l_4777[7][5] ^ (g_300 != l_4727)))) >= ((safe_unary_minus_func_int8_t_s ((safe_unary_minus_func_uint16_t_u ((safe_rshift_func_uint8_t_u_s (((((((0x8A25F2B6L && ((safe_lshift_func_int16_t_s_s (((l_4807 = (g_329[1][0][0] = (safe_rshift_func_int8_t_s_u ((l_4806[2] = l_4727), 2)))) & g_1265[2][5]), 9)) > 249UL)) ^ l_4808[1][4][1]) <= g_1782) & 3L) == g_71[7]) >= g_866), 5)))))) <= 0xAED4EAB5L)), l_4808[0][5][6])) != l_4576)))
 {
   int8_t
     l_4854
     =
     (-4L);
   if (g_4401)
   {
     l_4806
       [2]
       =
       ((g_201 > (g_4663 == (((safe_add_func_uint8_t_u_u ((+((safe_sub_func_uint16_t_u_u ((l_4777[2][5] = (g_774 = (safe_mul_func_int8_t_s_s (((g_2004[0][0][2] = ((safe_mod_func_uint16_t_u_u (g_978, (safe_lshift_func_uint16_t_u_s (g_774, (safe_sub_func_int32_t_s_s ((safe_rshift_func_int8_t_s_u ((safe_sub_func_uint16_t_u_u ((safe_lshift_func_uint16_t_u_u (0x8535L, 7)), ((l_4690 = (g_4663 > ((g_1266 = 0x3242L) ^ (+g_1835[0][6][4])))) | (g_2248 != g_2004[0][0][2])))), 7)), 0x5725F8BEL)))))) && l_4576)) <= 1UL), g_4401)))), l_4792)) != 0UL)), g_555)) >= 0x8CL) > g_697[8][0]))) != (-1L));
     g_1763
       =
       (safe_add_func_uint32_t_u_u
        ((((g_4460 > (safe_lshift_func_int8_t_s_s ((safe_mul_func_int8_t_s_s (0xDFL, (g_3117 <= (l_4576 = (g_978 > (((safe_lshift_func_int16_t_s_s ((safe_lshift_func_int16_t_s_s ((safe_add_func_uint32_t_u_u ((safe_add_func_int8_t_s_s (g_1810[0], (safe_add_func_uint8_t_u_u (0x62L, 0x86L)))), 0xC818CFB4L)), (safe_add_func_uint8_t_u_u (g_2388[1], 0xF8L)))), g_1266)) | 1L) > g_4847)))))), 7))) || 0xA2L) & 1UL), g_513[1]));
     l_4556
       =
       (l_4276
        =
        0x602EBE76L);
   }
   else
   {
     int8_t
       l_4849
       =
       0L;
     l_4849
       =
       g_4848
       [2];
     l_4854
       =
       (l_4576
        =
        ((safe_rshift_func_int8_t_s_s (l_4776[5], 7)) & (8UL & ((g_30 = g_300) > (safe_lshift_func_int16_t_s_s ((-8L), 10))))));
     l_4806
       [2]
       =
       (((safe_mul_func_int8_t_s_s (l_4660, (!(safe_mul_func_int16_t_s_s (l_4849, g_658))))) ^ (((0xC5L == (~2UL)) >= (safe_rshift_func_int16_t_s_s ((safe_rshift_func_uint8_t_u_s ((safe_mod_func_int8_t_s_s ((g_4614 = (safe_sub_func_uint16_t_u_u (((safe_lshift_func_int16_t_s_s (0x8868L, ((safe_mod_func_uint8_t_u_u ((safe_add_func_uint16_t_u_u (((safe_mul_func_int8_t_s_s (((safe_lshift_func_int8_t_s_u ((safe_mul_func_uint8_t_u_u ((((g_2065 = (g_697[4][0] > ((0x9E60L | (safe_lshift_func_int16_t_s_u (l_4854, 1))) ^ l_4513))) && l_4849) < g_4401), g_300)), l_4777[2][3])) & l_4382), 0L)) ^ l_4581[0]), 0UL)), 0xD8L)) & l_4693))) < 0x9AL), g_344))), l_4693)), g_1281)), 15))) != g_555)) | g_2066[5]);
     g_300
       =
       l_4849;
   }
 }
 else
 {
   int32_t
     l_4886
     =
     0x9877833CL;
   uint8_t
     l_4894
     =
     0xE8L;
   int32_t
     l_4919
     =
     0xB9D29664L;
   uint32_t
     l_4930
     =
     1UL;
   l_4807
     =
     (l_4660
      |
      ((safe_unary_minus_func_int32_t_s (((g_930 = (safe_rshift_func_int16_t_s_s ((!(!g_4848[4])), (g_1835[0][5][4] = ((safe_mul_func_uint16_t_u_u (((((((((l_4886 == (safe_mul_func_uint16_t_u_u ((g_774 = (safe_rshift_func_int16_t_s_u ((g_4893 = (((safe_mod_func_uint16_t_u_u ((g_2066[6] <= l_4666), 1UL)) | g_2066[7]) || (l_4556 || (+(((((((~(g_2004[0][0][2] & 0x1AC637C7L)) <= 0xCF45E29BL) <= g_2066[6]) == 0x1EL) == g_2004[1][0][0]) <= l_4693) >= 1UL))))), l_4480))), 1UL))) > 1UL) ^ g_521) <= l_4666) != g_866) >= l_4777[1][3]) && l_4808[1][4][1]) | l_4382), g_4401)) <= 0x6D75L))))) && l_4894))) & 0xB931A8B1L));
   l_4886
     =
     ((safe_mod_func_uint8_t_u_u (((0xE986L != g_4460) > ((safe_mod_func_int8_t_s_s (((+(safe_mul_func_uint8_t_u_u ((safe_rshift_func_uint8_t_u_s ((safe_mod_func_uint32_t_u_u ((l_4808[1][4][1] ^ (((l_4690 = (safe_rshift_func_int16_t_s_u ((g_1835[0][3][2] = (+(l_4513 == (safe_rshift_func_int8_t_s_s ((-1L), 3))))), (g_774 = (safe_add_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_s ((65527UL | 0xCDDEL), (l_4918 = ((!g_458) & (g_4848[2] = (safe_sub_func_int32_t_s_s (((+(safe_add_func_int16_t_s_s (l_4917, l_4727))) ^ g_367), g_1810[0]))))))), l_4792)))))) >= g_3350) >= 0x7E0FL)), 0xE7B6B0F0L)), 5)), g_300))) != l_4919), g_555)) | 4294967295UL)), 0x51L)) && l_4727);
   if (l_4480)
     continue;
   l_4932
     =
     (g_4663
      =
      ((safe_add_func_uint16_t_u_u (l_4792, ((safe_mod_func_int32_t_s_s ((l_4576 = (((g_774 = g_588) ^ ((safe_add_func_uint32_t_u_u (((safe_lshift_func_int16_t_s_u (l_4581[0], ((g_344 < g_3691) || (l_4930 = (safe_lshift_func_uint16_t_u_s (l_4918, g_721[5])))))) < (g_588 || (safe_unary_minus_func_uint16_t_u (g_978)))), 5L)) | 1L)) > 0xF168L)), l_4806[2])) ^ 0x85L))) >= 0xD9L));
 }
      }
   g_4663
     =
     (0x61CEL
      ^
      (safe_mul_func_uint8_t_u_u
       (((l_4279 = (l_4642 & (l_4276 = ((((((l_4739 = (~l_4738)) <= (g_30 = (safe_lshift_func_int16_t_s_u (4L, 12)))) != (safe_mul_func_int8_t_s_s (((safe_mod_func_int8_t_s_s (((safe_mul_func_uint16_t_u_u ((((safe_mod_func_uint32_t_u_u (l_4642, 0x6056CDD7L)) ^ (0xF54BL && (safe_add_func_int8_t_s_s ((safe_sub_func_uint16_t_u_u ((safe_add_func_uint16_t_u_u ((g_697[8][0] ^ (((~(safe_add_func_uint16_t_u_u (g_3847, g_774))) && 0xCDL) == 1L)), (-1L))), g_1763)), g_521)))) ^ 0UL), l_4666)) && g_513[1]), l_4642)) & g_458), g_588))) & g_697[8][0]) | l_4690) > l_4581[0])))) < 3UL), 3L)));
 }
 for
   (g_1917
    =
    0;
    (g_1917
     <=
     1);
    g_1917
    +=
    1)
 {
   int8_t
     l_4778
     =
     8L;
   l_4279
     =
     ((l_4778 == 0L) || (safe_sub_func_uint32_t_u_u (((+(l_4726 = (safe_rshift_func_int8_t_s_s (g_1281, 0)))) ^ ((safe_mul_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s (0x01L, l_4727)), ((g_30 = (safe_unary_minus_func_int8_t_s (g_1382))) | g_3117))) > ((safe_rshift_func_int8_t_s_u (((g_1266 = (safe_mod_func_uint16_t_u_u (l_4576, g_300))) <= 0x303FL), l_4792)) & g_521))), g_71[7])));
 }
      }
    }
g_1763
      =
      (((safe_unary_minus_func_uint16_t_u ((+((safe_mod_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s ((safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u ((((l_4576 = ((g_1266 = (((g_1782 = (safe_rshift_func_uint8_t_u_u ((l_4279 = g_1810[0]), (l_4556 == (l_4261 == (l_4276 = (g_3691 = (+(!0x8DL))))))))) >= (g_513[1] = 2UL)) && ((-1L) && (safe_add_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((g_774 = l_4513) >= (g_920 && (((safe_sub_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_u ((((g_555 > 0x09L) ^ g_930) > 1UL), g_329[1][0][0])), g_920)) >= l_2[0]) >= l_4261))) && l_4513), g_697[8][0])) <= l_4556), l_4576))))) <= l_4511)) || g_3350) >= l_4261), g_71[2])), l_4556)), 5)), g_1281)) ^ 7L)))) | g_669) >= l_4556);
  }
for
    (i
     =
     0;
     i
     <
     1;
     i++)
    l_2
      [i]
      =
      0x2062L;
l_2
      [i]
      =
      0x2062L;
  for
    (l_4277
     =
     0;
     (l_4277
      <=
      43);
     l_4277++)
  {
    int16_t
      l_5022
      =
      (-2L);
    int32_t
      l_5049
      [7]
      =
      {
  0L,
  0L,
  (-1L),
  0L,
  0L,
  (-1L),
  0L
};
    uint16_t
      l_5050
      [9]
      [6];
    int32_t
      l_5051
      =
      0xB9A8668BL;
    int16_t
      l_5052
      [4]
      [10]
      =
      {
  {0x2FA1L,
   0x8D3FL,
   0xB591L,
   0x9880L,
   0x7DB5L,
   0x9880L,
   0xB591L,
   0x8D3FL,
   0x2FA1L,
   0x2404L}
    , {0x7DB5L, 0xD3D0L, 0xE0F0L, 0xCBE8L, (-7L), 0x2FA1L, 0x5DD0L, 0x2404L, 0xB591L, 0xB591L}
    , {0xE0F0L, 8L, 0xD460L, 0xCBE8L, 0xCBE8L, 0xD460L, 8L, 0xE0F0L, 0x2FA1L, 0x3212L}
    , {8L, 0x2404L, (-4L), 0x9880L, 0x6A6FL, 0xB591L, (-5L), 0xCBE8L, 0xB156L, 0xCBE8L}
    };
    int
      i,
      j;
    for
      (i
       =
       0;
       i
       <
       9;
       i++)
    {
l_2
      [i]
      =
      0x2062L;
    }
for
      (i
       =
       0;
       i
       <
       9;
       i++)
    {
      for
 (j
  =
  0;
  j
  <
  6;
  j++)
 l_5050
   [i]
   [j]
   =
   65526UL;
    }
    return
      g_4848
      [2];
  }
  return
    g_697
    [8]
    [0];
}
static int32_t
func_4
  (int16_t
   p_5
)
{
  uint32_t
    l_3986
    =
    0x8E20F312L;
  int32_t
    l_4005
    =
    (-1L);
  int32_t
    l_4008
    =
    0xB7D9FB5BL;
  int8_t
    l_4138
    =
    0x6FL;
  uint8_t
    l_4151
    =
    0x5DL;
  int32_t
    l_4193
    =
    (-3L);
  uint32_t
    l_4204
    =
    0UL;
  int16_t
    l_4235
    =
    7L;
  int16_t
    l_4240
    [5]
    [7]
    =
    {
{0x7D80L,
 0xF1FCL,
 0x7D80L,
 0x4157L,
 2L,
 2L,
 0x4157L},
  {0xEFF1L,
0x075BL,
0xEFF1L,
(-5L),
0xFFD1L,
0xFFD1L,
(-5L)},
  {0x7D80L,
0xF1FCL, 0x7D80L, 0x4157L, 2L, 2L, 0x4157L}, {0xEFF1L, 0x075BL, 0xEFF1L, (-5L), 0xFFD1L, 0xFFD1L, (-5L)}, {0x7D80L, 0xF1FCL, 0x7D80L, 0x4157L, 2L, 2L, 0x4157L} };
  int
    i,
    j;
  for
    (g_1782
     =
     0;
     (g_1782
      <=
      (-10));
     --g_1782)
  {
    uint8_t
      l_4006
      =
      0UL;
    int32_t
      l_4007
      [6]
      =
      {
  0x3060CD64L,
  0L,
  0L,
  0x3060CD64L,
  0L,
  0L
};
    int32_t
      l_4009
      =
      1L;
    int32_t
      l_4010
      [10]
      =
      {
  1L,
  1L,
  1L,
  1L,
  1L,
  1L,
  1L,
  1L,
  1L,
  1L
};
    int16_t
      l_4014
      =
      (-5L);
    int32_t
      l_4022
      =
      (-1L);
    int8_t
      l_4083
      =
      (-1L);
    uint32_t
      l_4222
      =
      0xBBC64855L;
    uint16_t
      l_4224
      =
      65535UL;
    int
      i;
    l_4010
      [2]
      =
      ((l_4009 = (g_2004[1][0][8] = (safe_lshift_func_uint16_t_u_u ((((0xCAL > (safe_lshift_func_int8_t_s_u (((((g_774 | (safe_add_func_int32_t_s_s (((p_5 <= (((g_344 = (safe_rshift_func_int16_t_s_u ((l_4007[1] = (l_4008 = (safe_add_func_int16_t_s_s ((safe_rshift_func_int8_t_s_s ((safe_add_func_uint32_t_u_u ((p_5 > ((l_3986 >= ((safe_add_func_uint8_t_u_u ((l_4006 = (((g_774 != (safe_mul_func_int8_t_s_s (((safe_add_func_uint8_t_u_u (((safe_rshift_func_int8_t_s_s (p_5, 3)) > (((l_4005 = (safe_mul_func_int16_t_s_s ((safe_sub_func_int8_t_s_s ((safe_mod_func_uint8_t_u_u (l_3986, (safe_sub_func_uint8_t_u_u (((safe_mul_func_int16_t_s_s ((0xCE23L > g_697[0][1]), 0xD3CCL)) <= p_5), g_71[2])))), p_5)), 5UL))) == (-1L)) >= p_5)), (-1L))) != 0x16E25C30L), p_5))) <= 0x34L) ^ g_344)), g_2580)) | g_2066[3])) | 0x0FL)), p_5)), p_5)), l_4007[1])))), 11))) > g_920) || p_5)) & l_4009), 1L))) > g_930) || p_5) == 0x12E7L), 2))) && 0x37L) && 0UL), 11)))) & 3L);
    for
      (g_920
       =
       0;
       g_920
       <
       2;
       g_920
       +=
       1)
    {
      g_2388
 [g_920]
 =
 0UL;
{
      g_2388
 [g_920]
 =
 0UL;
    }
    }
{
    uint8_t
      l_4006
      =
      0UL;
    int32_t
      l_4007
      [6]
      =
      {
  0x3060CD64L,
  0L,
  0L,
  0x3060CD64L,
  0L,
  0L
};
    int32_t
      l_4009
      =
      1L;
    int32_t
      l_4010
      [10]
      =
      {
  1L,
  1L,
  1L,
  1L,
  1L,
  1L,
  1L,
  1L,
  1L,
  1L
};
    int16_t
      l_4014
      =
      (-5L);
    int32_t
      l_4022
      =
      (-1L);
    int8_t
      l_4083
      =
      (-1L);
    uint32_t
      l_4222
      =
      0xBBC64855L;
    uint16_t
      l_4224
      =
      65535UL;
    int
      i;
    l_4010
      [2]
      =
      ((l_4009 = (g_2004[1][0][8] = (safe_lshift_func_uint16_t_u_u ((((0xCAL > (safe_lshift_func_int8_t_s_u (((((g_774 | (safe_add_func_int32_t_s_s (((p_5 <= (((g_344 = (safe_rshift_func_int16_t_s_u ((l_4007[1] = (l_4008 = (safe_add_func_int16_t_s_s ((safe_rshift_func_int8_t_s_s ((safe_add_func_uint32_t_u_u ((p_5 > ((l_3986 >= ((safe_add_func_uint8_t_u_u ((l_4006 = (((g_774 != (safe_mul_func_int8_t_s_s (((safe_add_func_uint8_t_u_u (((safe_rshift_func_int8_t_s_s (p_5, 3)) > (((l_4005 = (safe_mul_func_int16_t_s_s ((safe_sub_func_int8_t_s_s ((safe_mod_func_uint8_t_u_u (l_3986, (safe_sub_func_uint8_t_u_u (((safe_mul_func_int16_t_s_s ((0xCE23L > g_697[0][1]), 0xD3CCL)) <= p_5), g_71[2])))), p_5)), 5UL))) == (-1L)) >= p_5)), (-1L))) != 0x16E25C30L), p_5))) <= 0x34L) ^ g_344)), g_2580)) | g_2066[3])) | 0x0FL)), p_5)), p_5)), l_4007[1])))), 11))) > g_920) || p_5)) & l_4009), 1L))) > g_930) || p_5) == 0x12E7L), 2))) && 0x37L) && 0UL), 11)))) & 3L);
    for
      (g_920
       =
       0;
       g_920
       <
       2;
       g_920
       +=
       1)
    {
      g_2388
 [g_920]
 =
 0UL;
    }
    if (((safe_rshift_func_uint8_t_u_s (l_4008, 4)) > (safe_unary_minus_func_uint32_t_u ((l_4007[1] = l_4014)))))
    {
      g_1763
 =
 g_1917;
    }
    else
    {
      int8_t
 l_4042
 =
 (-6L);
      int32_t
 l_4045
 =
 4L;
      int32_t
 l_4063
 =
 0xAD967815L;
      int8_t
 l_4064
 =
 9L;
      int8_t
 l_4203
 =
 (-1L);
      int16_t
 l_4205
 =
 0xAFDCL;
      if (p_5)
 break;
      for
 (g_458
  =
  2;
  (g_458
   !=
   18);
  g_458++)
      {
 uint32_t
   l_4033
   [4];
 int32_t
   l_4046
   =
   1L;
 int32_t
   l_4167
   =
   (-1L);
 int32_t
   l_4169
   =
   1L;
 uint32_t
   l_4188
   =
   0x855A4FADL;
 int
   i;
 for
   (i
    =
    0;
    i
    <
    4;
    i++)
   l_4033
     [i]
     =
     0xDF371472L;
 for
   (g_930
    =
    8;
    (g_930
     >=
     0);
    g_930
    -=
    1)
 {
   int32_t
     l_4017
     [8]
     [3]
     [3];
   int32_t
     l_4084
     =
     0x27695EDFL;
   int
     i,
     j,
     k;
   for
     (i
      =
      0;
      i
      <
      8;
      i++)
   {
     for
       (j
        =
        0;
        j
        <
        3;
        j++)
     {
       for
  (k
   =
   0;
   k
   <
   3;
   k++)
  l_4017
    [i]
    [j]
    [k]
    =
    (-6L);
     }
   }
   if (l_4017[6][0][0])
   {
     if (g_1995)
       break;
     l_4033
       [0]
       =
       ((safe_add_func_int8_t_s_s (((safe_mul_func_uint8_t_u_u (((0UL > l_4022) <= (((((safe_rshift_func_int8_t_s_u ((safe_lshift_func_uint8_t_u_u ((5L <= ((0x5FDB9509L | (safe_sub_func_int16_t_s_s ((g_697[8][0] = (((p_5 & 0x44L) != (((l_4017[6][0][0] & (safe_mod_func_uint8_t_u_u (((p_5 && (safe_mul_func_uint16_t_u_u (((((+4294967292UL) == 0UL) && l_3986) >= 0x54L), 2UL))) & 0xBBL), g_930))) > g_2066[1]) & l_4017[6][0][0])) == g_1835[0][3][2])), p_5))) > 0x3B96E009L)), l_4017[1][0][1])), 5)) & p_5) < g_344) ^ (-9L)) | l_4017[7][1][1])), p_5)) & p_5), l_4017[6][0][0])) <= l_4017[7][2][1]);
     l_4046
       =
       ((((p_5 <= l_4033[0]) || (g_588 = (safe_mod_func_uint32_t_u_u ((g_513[5] = ((l_4005 = ((l_4008 = (~(g_344 <= (l_4045 = (safe_add_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_u (l_4006, g_329[1][1][4])), (safe_mul_func_uint16_t_u_u ((+((((g_1763 || (l_4042 > (g_774 > (safe_add_func_int32_t_s_s (p_5, 0xC4C83DA6L))))) || 0L) ^ l_4017[6][0][0]) >= 0x9FL)), 0x0726L)))))))) <= g_978)) & g_555)), g_38)))) <= l_4033[0]) == p_5);
     l_4017
       [2]
       [2]
       [2]
       =
       0xB79115FFL;
   }
   else
   {
     uint32_t
       l_4053
       [3]
       [10]
       [8]
       =
       {
  {{0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL}
   ,
   {0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL}
   ,
   {0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL}
   ,
   {0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL}
   ,
   {0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL}
   ,
   {0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL}
   ,
   {0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL}
   ,
   {0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL}
   ,
   {0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL}
   ,
   {0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL,
    0xFED14B5AL}
   }
     , {{0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        }
     , {{0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL, 0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        ,
        {0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL,
  0xFED14B5AL}
        }
     };
     int32_t
       l_4054
       =
       0L;
     int16_t
       l_4081
       =
       2L;
     int32_t
       l_4082
       =
       0x2FF91C92L;
     int
       i,
       j,
       k;
     l_4017
       [6]
       [0]
       [0]
       =
       (safe_lshift_func_int8_t_s_s
        ((1L >= ((p_5 || (g_697[8][0] = (safe_mod_func_int32_t_s_s (p_5, l_4033[3])))) > ((safe_mod_func_uint16_t_u_u (l_4008, (-1L))) ^ (l_4054 = l_4053[2][7][2])))), ((safe_sub_func_int8_t_s_s (((-3L) != ((safe_mul_func_int8_t_s_s ((safe_mod_func_int8_t_s_s ((safe_lshift_func_uint16_t_u_u (((g_1810[0] = (g_3117 == p_5)) || l_4045), 15)), 1L)), l_4063)) | l_4064)), g_1265[0][2])) & l_4033[0])));
     g_71
       [7]
       =
       (l_4005
        =
        ((p_5 > (g_2004[0][0][5] = p_5)) || (g_30 = (safe_mod_func_int8_t_s_s ((!((((p_5 < (l_4054 = p_5)) && 0xBA35L) ^ ((p_5 <= (l_4017[6][0][0] = 247UL)) | (((safe_mod_func_int32_t_s_s ((l_4084 = ((((safe_mul_func_int8_t_s_s (((((l_4082 = ((safe_mod_func_int32_t_s_s ((((safe_lshift_func_int8_t_s_u (((safe_mul_func_uint8_t_u_u ((safe_sub_func_uint8_t_u_u ((safe_sub_func_int8_t_s_s (g_2065, ((l_4081 = 0x8AL) | l_4014))), g_329[1][0][0])), p_5)) != l_4046), p_5)) != p_5) ^ p_5), l_4008)) < l_4008)) >= 0UL) | l_4083) ^ l_4014), p_5)) == p_5) > 4294967293UL) <= p_5)), 4294967294UL)) != l_4083) || p_5))) & 0UL)), g_1265[2][5])))));
     return
       p_5;
   }
   for
     (g_2580
      =
      0;
      (g_2580
       <=
       1);
      g_2580
      +=
      1)
   {
     int
       i;
     l_4017
       [2]
       [0]
       [0]
       =
       ((l_4045 = (safe_rshift_func_int16_t_s_s (0x7D82L, ((safe_sub_func_uint8_t_u_u ((4UL <= ((safe_mod_func_int16_t_s_s (((g_513[(g_2580 + 1)] || 0x71FD9DE7L) || ((g_71[1] | g_1763) | (safe_mod_func_int32_t_s_s ((safe_mod_func_int32_t_s_s ((+((((g_2004[0][0][2] && (((l_4046 = (safe_mod_func_int8_t_s_s (g_2066[7], (safe_add_func_uint16_t_u_u ((safe_rshift_func_uint8_t_u_u ((safe_rshift_func_uint16_t_u_s ((l_4009 = 6UL), 12)), g_3847)), p_5))))) ^ l_4084) < l_4033[0])) || g_513[(g_2580 + 1)]) == l_4033[0]) | 0xF4C2L)), g_367)), g_300)))), l_4017[2][2][1])) ^ p_5)), p_5)) != 0xBE8DL)))) == g_2617);
   }
   for
     (g_866
      =
      0;
      (g_866
       <=
       6);
      g_866
      +=
      1)
   {
     int32_t
       l_4129
       [7];
     int32_t
       l_4136
       =
       0x497990BEL;
     uint8_t
       l_4137
       =
       254UL;
     int
       i;
     for
       (i
        =
        0;
        i
        <
        7;
        i++)
       l_4129
  [i]
  =
  0L;
     g_71
       [0]
       =
       (g_513
        [g_866]
        <
        (((safe_lshift_func_int8_t_s_u (((safe_mul_func_uint8_t_u_u (0x92L, (((safe_lshift_func_uint8_t_u_s (((safe_sub_func_uint16_t_u_u (((((safe_sub_func_uint32_t_u_u (g_513[g_866], g_1835[0][3][2])) == (((safe_lshift_func_int8_t_s_u ((((safe_sub_func_int8_t_s_s (((safe_mul_func_uint8_t_u_u ((l_4063 = (safe_mul_func_uint16_t_u_u (((safe_mod_func_uint8_t_u_u ((safe_rshift_func_uint8_t_u_s ((l_4008 = 0x18L), (safe_sub_func_uint16_t_u_u ((l_4129[3] = p_5), ((l_4136 = (((((safe_rshift_func_int16_t_s_u (g_329[1][0][0], (g_774 = ((safe_rshift_func_int16_t_s_s (0L, ((safe_mod_func_uint16_t_u_u (0UL, g_978)) || l_4136))) <= l_4022)))) | 3L) || p_5) <= p_5) && p_5)) == p_5))))), p_5)) && g_3691), 6L))), 0UL)) < g_3847), l_4137)) || l_4138) && 0xB164F870L), p_5)) <= l_4033[0]) <= 0xF83D0C7EL)) != p_5) == 246UL), p_5)) <= g_513[g_866]), 0)) & g_201) || 0x6D063ED2L))) & 0xB747141DL), 1)) & l_4042) > g_1782));
     if (g_2004[0][0][2])
       break;
     g_71
       [7]
       =
       (safe_add_func_uint16_t_u_u
        (l_4046,
  p_5));
     if (p_5)
       continue;
   }
   if (((safe_mul_func_int8_t_s_s (g_920, (safe_add_func_int32_t_s_s ((safe_lshift_func_uint8_t_u_u (((6UL > l_4008) >= (((((-9L) >= ((safe_lshift_func_uint16_t_u_u (p_5, (l_4063 > l_4017[1][2][0]))) == g_1763)) ^ (l_3986 >= 0x6FL)) <= l_4017[6][0][0]) <= 1L)), p_5)), l_4151)))) != 4294967289UL))
   {
     uint32_t
       l_4168
       =
       0xC022E5A9L;
     l_4169
       =
       (safe_add_func_int8_t_s_s
        (((g_588 & 1L) == ((safe_unary_minus_func_uint32_t_u (((safe_lshift_func_int8_t_s_s ((l_4084 = (((safe_mod_func_uint32_t_u_u (((g_1810[0] = p_5) & (safe_sub_func_uint32_t_u_u (l_4005, (((safe_mul_func_uint8_t_u_u ((l_4167 = (safe_mod_func_uint8_t_u_u (p_5, (safe_lshift_func_uint8_t_u_s ((l_4046 = (l_4008 = (g_2388[0] | (g_2004[0][0][2] ^ g_1763)))), g_721[3]))))), g_920)) | 0xB9L) || 0xAB89L)))), 2UL)) != l_4168) == l_4168)), 5)) == p_5))) && g_329[1][0][0])), 0xDAL));
     g_300
       =
       p_5;
   }
   else
   {
     g_300
       =
       (g_1763
        =
        (safe_mul_func_uint8_t_u_u
  (((safe_sub_func_int32_t_s_s (((safe_lshift_func_uint16_t_u_s (l_4042, 15)) >= (safe_sub_func_int32_t_s_s ((-3L), p_5))), (safe_sub_func_int32_t_s_s ((l_4063 = 9L), g_2066[7])))) >= (safe_mul_func_int8_t_s_s (((safe_sub_func_int16_t_s_s ((l_4017[6][0][0] = (p_5 != ((l_4005 != 0x422DL) && (((((safe_rshift_func_uint8_t_u_s ((safe_rshift_func_int16_t_s_u (l_4033[0], 13)), 7)) <= p_5) || 4294967286UL) == g_1782) && 7L)))), g_978)) != p_5), g_1281))), l_4188)));
     g_71
       [4]
       =
       g_71
       [7];
     if (g_669)
       continue;
   }
 }
 g_71
   [7]
   =
   ((!(safe_add_func_uint32_t_u_u (1UL, ((safe_mod_func_uint32_t_u_u ((l_4014 == ((l_4193 < 0xE4L) & ((l_4045 = (safe_mul_func_int16_t_s_s (g_2004[2][0][0], (safe_lshift_func_int8_t_s_u (((l_4005 = (!g_930)) >= p_5), 1))))) >= (l_4204 = (g_1835[0][2][4] != (safe_mod_func_int8_t_s_s ((safe_unary_minus_func_uint32_t_u ((((l_4063 = (safe_mod_func_uint32_t_u_u (0xE37BCFD8L, p_5))) != 0L) && g_2580))), l_4203))))))), p_5)) == l_4033[0])))) | l_4205);
      }
      if (l_4022)
 continue;
      for
 (g_3117
  =
  0;
  (g_3117
   <=
   1);
  g_3117
  +=
  1)
      {
 uint16_t
   l_4225
   =
   1UL;
 int32_t
   l_4226
   [6]
   [10]
   [4]
   =
   {
      {{0x868658D9L, 0xC234D509L, 0xF598642EL, 0xF598642EL}
       ,
       {0xC0D2EDD5L,
 0xC0D2EDD5L,
 1L,
 0xC234D509L}
       ,
       {0xC234D509L,
 0x868658D9L,
 1L,
 0x868658D9L}
       ,
       {0xC0D2EDD5L,
 (-1L),
 0xF598642EL,
 1L}
       ,
       {0x868658D9L,
 (-1L),
 (-1L),
 0x868658D9L}
       ,
       {(-1L), 0x868658D9L, 0xC0D2EDD5L, 0xC234D509L}
       ,
       {(-1L), 0xC0D2EDD5L, (-1L), 0xF598642EL}
       ,
       {0x868658D9L,
 0xC234D509L,
 0xF598642EL,
 0xF598642EL}
       ,
       {0xC0D2EDD5L,
 0xC0D2EDD5L,
 1L,
 0xC234D509L}
       ,
       {0xC234D509L,
 0x868658D9L,
 1L,
 0x868658D9L}
       }
 , {{0xC0D2EDD5L, (-1L), 0xF598642EL, 1L}
    ,
    {0x868658D9L,
     (-1L),
     (-1L),
     0x868658D9L}
    ,
    {(-1L), 0x868658D9L, 0xC0D2EDD5L, 0xC234D509L}
    ,
    {(-1L), 0xC0D2EDD5L, (-1L), 0xF598642EL}
    ,
    {0x868658D9L,
     0xC234D509L,
     0xF598642EL,
     0xF598642EL}
    ,
    {0xC0D2EDD5L,
     0xC0D2EDD5L,
     1L,
     0xC234D509L}
    ,
    {0xC234D509L,
     0x868658D9L,
     1L,
     0x868658D9L}
    ,
    {0xC0D2EDD5L,
     (-1L),
     0xF598642EL,
     1L}
    ,
    {0x868658D9L,
     (-1L),
     (-1L),
     0x868658D9L}
    ,
    {(-1L), 0x868658D9L, 0xC0D2EDD5L, 0xC234D509L}
    }
 , {{(-1L), 0xC0D2EDD5L, (-1L), 0xF598642EL}
    ,
    {0x868658D9L,
     0xC234D509L,
     1L,
     1L}
    ,
    {0x592F2378L,
     0x592F2378L,
     0xC0D2EDD5L,
     0xF598642EL}
    ,
    {0xF598642EL,
     (-1L),
     0xC0D2EDD5L,
     (-1L)}
    ,
    {0x592F2378L,
     0xC234D509L,
     1L,
     0xC0D2EDD5L}
    ,
    {(-1L), 0xC234D509L, 0xC234D509L, (-1L)}
    ,
    {0xC234D509L,
     (-1L),
     0x592F2378L,
     0xF598642EL}
    ,
    {0xC234D509L,
     0x592F2378L,
     0xC234D509L,
     1L}
    ,
    {(-1L), 0xF598642EL, 1L, 1L}
    ,
    {0x592F2378L,
     0x592F2378L,
     0xC0D2EDD5L,
     0xF598642EL}
    }
 , {{0xF598642EL, (-1L), 0xC0D2EDD5L, (-1L)}
    ,
    {0x592F2378L,
     0xC234D509L,
     1L,
     0xC0D2EDD5L}
    ,
    {(-1L), 0xC234D509L, 0xC234D509L, (-1L)}
    ,
    {0xC234D509L,
     (-1L),
     0x592F2378L,
     0xF598642EL}
    ,
    {0xC234D509L,
     0x592F2378L,
     0xC234D509L,
     1L}
    ,
    {(-1L), 0xF598642EL, 1L, 1L}
    ,
    {0x592F2378L,
     0x592F2378L,
     0xC0D2EDD5L,
     0xF598642EL}
    ,
    {0xF598642EL,
     (-1L),
     0xC0D2EDD5L,
     (-1L)}
    ,
    {0x592F2378L,
     0xC234D509L,
     1L,
     0xC0D2EDD5L}
    ,
    {(-1L), 0xC234D509L, 0xC234D509L, (-1L)}
    }
 , {{0xC234D509L, (-1L), 0x592F2378L, 0xF598642EL}
    ,
    {0xC234D509L,
     0x592F2378L,
     0xC234D509L,
     1L}
    ,
    {(-1L), 0xF598642EL, 1L, 1L}
    ,
    {0x592F2378L,
     0x592F2378L,
     0xC0D2EDD5L,
     0xF598642EL}
    ,
    {0xF598642EL,
     (-1L),
     0xC0D2EDD5L,
     (-1L)}
    ,
    {0x592F2378L,
     0xC234D509L,
     1L,
     0xC0D2EDD5L}
    ,
    {(-1L), 0xC234D509L, 0xC234D509L, (-1L)}
    ,
    {0xC234D509L,
     (-1L),
     0x592F2378L,
     0xF598642EL}
    ,
    {0xC234D509L,
     0x592F2378L,
     0xC234D509L,
     1L}
    ,
    {(-1L), 0xF598642EL, 1L, 1L}
    }
 , {{0x592F2378L, 0x592F2378L, 0xC0D2EDD5L, 0xF598642EL}
    ,
    {0xF598642EL,
     (-1L),
     0xC0D2EDD5L,
     (-1L)}
    ,
    {0x592F2378L,
     0xC234D509L,
     1L,
     0xC0D2EDD5L}
    ,
    {(-1L), 0xC234D509L, 0xC234D509L, (-1L)}
    ,
    {0xC234D509L,
     (-1L),
     0x592F2378L,
     0xF598642EL}
    ,
    {0xC234D509L,
     0x592F2378L,
     0xC234D509L,
     1L}
    ,
    {(-1L), 0xF598642EL, 1L, 1L}
    ,
    {0x592F2378L,
     0x592F2378L,
     0xC0D2EDD5L,
     0xF598642EL}
    ,
    {0xF598642EL,
     (-1L),
     0xC0D2EDD5L,
     (-1L)}
    ,
    {0x592F2378L,
     0xC234D509L,
     1L,
     0xC0D2EDD5L}
    }
 };
 int
   i,
   j,
   k;
 for
   (g_2580
    =
    5;
    (g_2580
     >=
     0);
    g_2580
    -=
    1)
 {
   uint32_t
     l_4223
     =
     0x17D9F348L;
   int
     i,
     j,
     k;
   l_4226
     [3]
     [4]
     [2]
     =
     (l_4225
      =
      (safe_mod_func_uint8_t_u_u
       ((((safe_sub_func_uint8_t_u_u (g_329[g_3117][g_2580][(g_3117 + 3)], (g_329[g_3117][(g_2580 + 1)][g_2580] <= (safe_mul_func_uint8_t_u_u (((safe_mul_func_int8_t_s_s ((safe_rshift_func_int8_t_s_u ((safe_add_func_uint16_t_u_u ((((l_4007[(g_3117 + 1)] != (safe_mul_func_int16_t_s_s ((p_5 = l_3986), l_4022))) > ((g_2065 || ((l_4010[g_3117] = l_4007[(g_3117 + 1)]) < (l_4006 != l_4222))) || l_4223)) || (-1L)), g_658)), 3)), l_4014)) <= l_4224), 0x3CL))))) == 1L) < 7L), l_4151)));
 }
 return
   g_669;
      }
    }
  }
  }
  l_4193
    =
    (safe_rshift_func_uint16_t_u_s
     ((safe_mod_func_uint16_t_u_u (((g_513[1] > ((0UL >= ((1L & (g_1266 = g_201)) & (safe_lshift_func_int8_t_s_s ((safe_sub_func_int32_t_s_s ((l_4235 || ((safe_mul_func_uint16_t_u_u (65535UL, ((((((safe_mod_func_int16_t_s_s (g_920, l_4240[3][4])) == l_4240[4][6]) == g_38) < g_458) <= 0x2EL) < l_3986))) ^ 0xC1L)), p_5)), l_4193)))) != (-9L))) <= p_5), 0xFF14L)), g_2580));
  return
    g_588;
}
static int16_t
func_6
  (uint8_t
   p_7
)
{
  int32_t
    l_19
    =
    0xD0176DF7L;
  int8_t
    l_3776
    =
    0xD9L;
  int32_t
    l_3826
    [3];
  int32_t
    l_3827
    =
    1L;
  uint32_t
    l_3969
    =
    0xC6B29A57L;
  int
    i;
  for
    (i
     =
     0;
     i
     <
     3;
     i++)
    l_3826
      [i]
      =
      (-1L);
  if (g_3)
  {
    uint8_t
      l_29
      =
      9UL;
    int32_t
      l_37
      =
      (-2L);
    l_37
      =
      (safe_lshift_func_int16_t_s_u
       ((0x673E7ED6L > (g_71[7] = (!(safe_mul_func_int16_t_s_s (p_7, func_14 (p_7, (l_19 & (safe_mod_func_uint16_t_u_u (0x3C1DL, func_22 ((safe_mod_func_int32_t_s_s (0x004DDE9AL, (safe_rshift_func_uint8_t_u_u ((g_30 = (l_29 = 0xE5L)), (safe_lshift_func_int8_t_s_s (((safe_lshift_func_uint16_t_u_u ((safe_rshift_func_int8_t_s_s (p_7, 1)), (p_7 == l_37))) != g_38), 0)))))), l_19)))), p_7, l_37)))))), 10));
  }
  else
  {
    uint8_t
      l_3775
      =
      0xA7L;
    int32_t
      l_3777
      =
      0x2BF1DB03L;
    int8_t
      l_3786
      =
      3L;
    int32_t
      l_3834
      =
      1L;
    uint16_t
      l_3858
      =
      65535UL;
    if ((safe_add_func_int32_t_s_s ((safe_sub_func_uint8_t_u_u ((safe_add_func_int32_t_s_s ((g_300 = p_7), ((l_3775 & 0x9C9AL) < p_7))), (0x86CE1C01L ^ (p_7 & (l_3777 = ((p_7 | 0xE7L) | l_3776)))))), l_3775)))
    {
      return
 p_7;
    }
    else
    {
      int16_t
 l_3785
 =
 4L;
      int32_t
 l_3791
 =
 (-1L);
      int32_t
 l_3874
 =
 (-3L);
      for
 (g_344
  =
  3;
  (g_344
   >=
   0);
  g_344
  -=
  1)
      {
 int16_t
   l_3780
   =
   0xFA24L;
 int32_t
   l_3792
   =
   0x14868E69L;
 uint8_t
   l_3795
   =
   0x59L;
{
 int16_t
   l_3780
   =
   0xFA24L;
 int32_t
   l_3792
   =
   0x14868E69L;
 uint8_t
   l_3795
   =
   0x59L;
 l_3791
   =
   (l_19
    <
    ((safe_mod_func_uint8_t_u_u ((l_3780 || (safe_lshift_func_int8_t_s_s ((l_3785 = (safe_mul_func_uint8_t_u_u ((g_588 = 251UL), 0xD5L))), 6))), l_3786)) ^ ((safe_lshift_func_int16_t_s_s ((g_978 == (safe_mul_func_int8_t_s_s ((l_3792 = (0x18EDL != l_3791)), (l_3777 = ((safe_lshift_func_int8_t_s_s ((0x0DD6895FL < g_920), l_3795)) > 0x01L))))), p_7)) || g_1995)));
 for
   (l_3776
    =
    4;
    (l_3776
     >=
     1);
    l_3776
    -=
    1)
 {
   for
     (g_3117
      =
      0;
      (g_3117
       <=
       0);
      g_3117
      +=
      1)
   {
     int
       i,
       j,
       k;
     g_1782
       =
       (0xAAE6L
        &
        (safe_mul_func_uint16_t_u_u
  (((g_1835[g_3117][l_3776][(g_344 + 1)] != 0x32L) || (g_1835[g_3117][l_3776][l_3776] != (((g_1810[g_3117] = (g_1835[g_3117][(g_3117 + 1)][l_3776] <= (safe_add_func_uint16_t_u_u (((((safe_sub_func_uint32_t_u_u (g_1810[g_3117], 0xBDB1D715L)) & (safe_rshift_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u (((safe_lshift_func_uint8_t_u_s ((g_1265[(g_344 + 1)][(g_344 + 2)] && (safe_rshift_func_uint8_t_u_u (g_521, 1))), g_344)) | l_3776), 0UL)), p_7))) > p_7) != p_7), 65530UL)))) && g_1835[g_3117][l_3776][l_3776]) ^ l_3776))), g_697[5][1])));
     g_71
       [7]
       =
       p_7;
   }
 }
      }
 for
   (l_3776
    =
    4;
    (l_3776
     >=
     1);
    l_3776
    -=
    1)
 {
   for
     (g_3117
      =
      0;
      (g_3117
       <=
       0);
      g_3117
      +=
      1)
   {
     int
       i,
       j,
       k;
     g_1782
       =
       (0xAAE6L
        &
        (safe_mul_func_uint16_t_u_u
  (((g_1835[g_3117][l_3776][(g_344 + 1)] != 0x32L) || (g_1835[g_3117][l_3776][l_3776] != (((g_1810[g_3117] = (g_1835[g_3117][(g_3117 + 1)][l_3776] <= (safe_add_func_uint16_t_u_u (((((safe_sub_func_uint32_t_u_u (g_1810[g_3117], 0xBDB1D715L)) & (safe_rshift_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u (((safe_lshift_func_uint8_t_u_s ((g_1265[(g_344 + 1)][(g_344 + 2)] && (safe_rshift_func_uint8_t_u_u (g_521, 1))), g_344)) | l_3776), 0UL)), p_7))) > p_7) != p_7), 65530UL)))) && g_1835[g_3117][l_3776][l_3776]) ^ l_3776))), g_697[5][1])));
   }
{
    uint8_t
      l_29
      =
      9UL;
    int32_t
      l_37
      =
      (-2L);
    l_37
      =
      (safe_lshift_func_int16_t_s_u
       ((0x673E7ED6L > (g_71[7] = (!(safe_mul_func_int16_t_s_s (p_7, func_14 (p_7, (l_19 & (safe_mod_func_uint16_t_u_u (0x3C1DL, func_22 ((safe_mod_func_int32_t_s_s (0x004DDE9AL, (safe_rshift_func_uint8_t_u_u ((g_30 = (l_29 = 0xE5L)), (safe_lshift_func_int8_t_s_s (((safe_lshift_func_uint16_t_u_u ((safe_rshift_func_int8_t_s_s (p_7, 1)), (p_7 == l_37))) != g_38), 0)))))), l_19)))), p_7, l_37)))))), 10));
  }
 }
      }
{
    uint8_t
      l_29
      =
      9UL;
    int32_t
      l_37
      =
      (-2L);
    l_37
      =
      (safe_lshift_func_int16_t_s_u
       ((0x673E7ED6L > (g_71[7] = (!(safe_mul_func_int16_t_s_s (p_7, func_14 (p_7, (l_19 & (safe_mod_func_uint16_t_u_u (0x3C1DL, func_22 ((safe_mod_func_int32_t_s_s (0x004DDE9AL, (safe_rshift_func_uint8_t_u_u ((g_30 = (l_29 = 0xE5L)), (safe_lshift_func_int8_t_s_s (((safe_lshift_func_uint16_t_u_u ((safe_rshift_func_int8_t_s_s (p_7, 1)), (p_7 == l_37))) != g_38), 0)))))), l_19)))), p_7, l_37)))))), 10));
  }
l_3826
      [i]
      =
      (-1L);
      return
 g_2580;
    }
  }
  return
    l_3969;
}
static uint16_t
func_14
  (int8_t
   p_15,
   int8_t
   p_16,
   uint32_t
   p_17,
   uint16_t
   p_18
)
{
  uint32_t
    l_3614
    =
    0x682B5945L;
  int32_t
    l_3635
    =
    6L;
  int32_t
    l_3638
    =
    0L;
  uint16_t
    l_3647
    =
    0x0533L;
  int32_t
    l_3768
    =
    0xCC60DBF6L;
  l_3614
    =
    p_18;
  for
    (g_458
     =
     0;
     (g_458
      <=
      4);
     g_458
     +=
     1)
  {
    uint16_t
      l_3640
      =
      65535UL;
    int32_t
      l_3642
      [3]
      [5];
    int32_t
      l_3672
      =
      (-1L);
    int32_t
      l_3694
      [10]
      =
      {
  (-8L),
  (-8L),
  (-8L),
  (-8L),
  (-8L),
  (-8L),
  (-8L),
  (-8L),
  (-8L),
  (-8L)
};
    int32_t
      l_3738
      =
      0x7F69D9B0L;
    int32_t
      l_3755
      =
      0x4831048BL;
    int
      i,
      j;
l_3614
    =
    p_18;
    if (l_3614)
      break;
l_3614
    =
    p_18;
for
      (g_1763
       =
       1;
       (g_1763
 <=
 6);
       g_1763
       +=
       1)
    {
      uint8_t
 l_3639
 =
 255UL;
      int32_t
 l_3641
 =
 0x139CD152L;
      int32_t
 l_3652
 [3]
 [8]
 =
 {
    {0xDE3E1FD3L,
     0x26F14F79L,
     0xF7FF7380L,
     0xF7FF7380L,
     0x26F14F79L,
     0xDE3E1FD3L,
     0x26F14F79L,
     0xF7FF7380L}
      , {1L, 0x26F14F79L, 1L, 0xDE3E1FD3L, 0xDE3E1FD3L, 1L, 0x26F14F79L, 1L}
      , {1L, 0xDE3E1FD3L, 0xF7FF7380L, 0xDE3E1FD3L, 1L, 1L, 0xDE3E1FD3L, 0xF7FF7380L}
      };
      int32_t
 l_3671
 =
 3L;
      uint32_t
 l_3716
 =
 1UL;
      int16_t
 l_3721
 =
 0x0525L;
      int32_t
 l_3737
 [8]
 =
 {
    1L,
    1L,
    1L,
    1L,
    1L,
    1L,
    1L,
    1L
  };
      int
 i,
        j;
      l_3642
 [1]
 [4]
 =
 (((safe_sub_func_int16_t_s_s (p_16, ((l_3641 = (safe_lshift_func_int8_t_s_s (((p_18 = (((0xFA2FL <= 0x1C4DL) > ((((g_555 = 0xC524L) > ((safe_sub_func_uint32_t_u_u (((safe_sub_func_int8_t_s_s ((safe_add_func_int16_t_s_s (5L, ((safe_sub_func_int16_t_s_s ((l_3614 && (((safe_rshift_func_uint16_t_u_u ((safe_sub_func_int32_t_s_s ((safe_lshift_func_uint8_t_u_u (p_17, 6)), (safe_mul_func_int16_t_s_s (l_3635, (safe_sub_func_int8_t_s_s (((l_3638 = 0xE6BC05B6L) <= 4294967295UL), p_18)))))), 1)) && g_774) < 0UL)), 0x0AD4L)) | p_17))), l_3639)) ^ l_3639), p_17)) > g_930)) >= l_3640) <= 0xF8BFL)) <= g_2004[6][0][7])) <= p_15), p_17))) <= 0xE77DB131L))) == g_866) != 0UL);
      if (p_18)
      {
 int32_t
   l_3653
   =
   0L;
 for
   (p_16
    =
    4;
    (p_16
     >=
     0);
    p_16
    -=
    1)
 {
   int32_t
     l_3670
     =
     0xF2834046L;
   int8_t
     l_3675
     =
     0L;
   int
     i;
   if ((safe_add_func_int16_t_s_s ((safe_lshift_func_uint8_t_u_u (p_18, 0)), (p_15 == (((g_513[(g_458 + 1)] = ((((l_3647 = (!((l_3639 ^ p_15) | 0x20L))) || (safe_add_func_int16_t_s_s (((safe_add_func_int32_t_s_s ((l_3641 = (((((!(g_2065 = ((((g_344 = 0x7EL) ^ (0xEC88L ^ p_17)) | (l_3652[0][4] = g_1995)) & p_18))) && 0L) == g_978) < l_3653) == 0xD8D7L)), p_17)) >= 65531UL), p_18))) & 0UL) | 0xB4L)) == 4UL) < (-1L))))))
   {
     int16_t
       l_3664
       [7];
     int32_t
       l_3665
       =
       1L;
     int32_t
       l_3668
       [2]
       [3]
       =
       {
   {0x7D02AEDCL,
    0x7D02AEDCL,
    0x7D02AEDCL}
     , {0x67DB47F5L, 0x67DB47F5L, 0x67DB47F5L}
     };
     int32_t
       l_3669
       =
       0xC04C170DL;
     int
       i,
       j;
     for
       (i
        =
        0;
        i
        <
        7;
        i++)
       l_3664
  [i]
  =
  0L;
     l_3672
       =
       (safe_lshift_func_uint8_t_u_u
        ((0xA33A6990L <= (((l_3670 = ((+((l_3669 = (safe_mul_func_int8_t_s_s ((((safe_add_func_uint8_t_u_u ((p_16 <= ((safe_rshift_func_int8_t_s_u ((safe_mul_func_int16_t_s_s (((l_3665 = (l_3664[6] = g_344)) == p_18), 65535UL)), (p_15 > (p_15 || (l_3642[1][4] = (p_17 & (safe_lshift_func_int8_t_s_s (l_3668[0][2], 7)))))))) != 1UL)), p_15)) == 0x76F0L) != l_3652[0][4]), 255UL))) > g_1835[0][4][3])) == g_658)) ^ 1UL) <= l_3671)), g_513[4]));
     l_3670
       =
       l_3641;
     l_3653
       =
       g_458;
   }
   else
   {
     l_3675
       =
       (safe_sub_func_uint32_t_u_u
        (p_17,
  l_3647));
     if (p_16)
       continue;
   }
 }
 for
   (g_1281
    =
    0;
    (g_1281
     <=
     4);
    g_1281
    +=
    1)
 {
   uint16_t
     l_3690
     =
     65535UL;
   int16_t
     l_3723
     =
     0L;
   int32_t
     l_3734
     =
     0x1358498BL;
   if (((1UL | ((((g_513[1] = (g_658 ^ (safe_sub_func_int16_t_s_s ((0x0842L || (safe_add_func_uint32_t_u_u ((p_17 > (safe_rshift_func_int8_t_s_s (((((safe_mul_func_int8_t_s_s ((safe_sub_func_int16_t_s_s ((g_1265[0][4] || (safe_mul_func_int16_t_s_s (l_3672, (safe_mul_func_uint16_t_u_u (((l_3641 == (l_3638 = p_15)) && l_3635), g_1382))))), l_3690)), 0UL)) | p_16) != 0L) > 0xD4L), l_3653))), l_3671))), p_15)))) & p_16) > 255UL) ^ g_3691)) ^ 0x493BL))
   {
     g_71
       [7]
       =
       p_17;
   }
   else
   {
     if (l_3638)
       break;
     l_3653
       =
       (0UL
        !=
        (p_18
  =
  (safe_add_func_int16_t_s_s
   (g_344,
    l_3635))));
   }
   if ((((l_3694[4] | g_3691) ^ (p_18 <= ((safe_mod_func_int8_t_s_s (1L, p_17)) >= (p_18 && (+(g_697[8][1] && (safe_sub_func_uint16_t_u_u (65526UL, (safe_add_func_uint32_t_u_u (((((safe_add_func_int16_t_s_s ((safe_mul_func_uint8_t_u_u (l_3652[0][4], 0xACL)), g_721[8])) != g_458) >= g_866) | g_201), g_2066[7])))))))))) > g_920))
   {
     int16_t
       l_3709
       =
       (-3L);
     int32_t
       l_3722
       =
       (-6L);
     l_3653
       =
       (l_3723
        =
        (((0x4787L >= (~(((safe_lshift_func_uint8_t_u_s ((p_17 ^ g_30), ((safe_add_func_uint32_t_u_u ((l_3709 = (g_920 = p_17)), g_2065)) || (safe_add_func_uint16_t_u_u ((g_774 = (l_3722 = ((l_3638 = (safe_mul_func_int8_t_s_s (((l_3642[0][1] = l_3639) | (((safe_rshift_func_uint8_t_u_s (l_3716, 5)) <= (safe_sub_func_uint32_t_u_u ((safe_sub_func_uint8_t_u_u (g_866, l_3721)), l_3635))) || 0xD8110DA4L)), p_18))) <= p_16))), l_3614))))) >= l_3614) > 1L))) > l_3640) ^ 0x4AL));
     if (p_15)
       continue;
     l_3738
       =
       (p_17
        >
        (g_978
  =
  ((((l_3638 = (p_18 = ((p_16 = (((g_2004[3][0][6] | g_521) != ((safe_mul_func_int16_t_s_s ((safe_mul_func_uint8_t_u_u (((l_3672 = (0x3D0740EDL > 1UL)) == (l_3642[1][4] = (safe_lshift_func_int16_t_s_u ((l_3641 > ((((((safe_sub_func_uint32_t_u_u (((safe_mod_func_uint32_t_u_u ((l_3734 = g_721[6]), 0x21AACA16L)) >= (safe_add_func_int8_t_s_s ((((l_3737[5] <= g_930) && l_3653) && 0xC9A2L), p_17))), g_521)) >= p_17) < 0x6EECL) >= l_3653) > p_16) == l_3690)), g_669)))), p_16)), 0x27CFL)) != 0x45CDD01DL)) < 0x42A7L)) & p_17))) <= 7UL) || 0x20L) && l_3640)));
   }
   else
   {
     int16_t
       l_3766
       =
       1L;
     uint16_t
       l_3767
       =
       0xB26AL;
     l_3768
       =
       ((l_3641 = (p_16 || (~((safe_mul_func_uint16_t_u_u ((safe_lshift_func_uint8_t_u_s ((safe_add_func_int16_t_s_s ((safe_rshift_func_uint8_t_u_s (((safe_add_func_int32_t_s_s ((246UL == 0xC1L), (safe_rshift_func_uint8_t_u_u ((safe_mod_func_int32_t_s_s (p_18, ((g_513[1] = (l_3638 = g_3117)) & (l_3755 >= 255UL)))), 6)))) | (((safe_sub_func_int16_t_s_s ((safe_lshift_func_int8_t_s_u (((((0xD47B57BEL ^ (((safe_mod_func_uint32_t_u_u ((((safe_sub_func_int8_t_s_s ((l_3653 = (safe_lshift_func_uint8_t_u_u (l_3766, 2))), p_15)) < p_18) < p_15), 2UL)) == g_3117) <= g_1995)) & g_344) < 0L) < g_588), 0)), g_2004[3][0][8])) == 6L) == g_1917)), l_3767)), p_18)), l_3647)), l_3672)) & g_2066[7])))) ^ g_1835[0][3][2]);
   }
   g_71
     [7]
     =
     0x0330735FL;
 }
      }
      else
      {
 return
   p_18;
      }
    }
  }
l_3614
    =
    p_18;
  return
    l_3647;
}
static int16_t
func_22
  (int8_t
   p_23,
   int8_t
   p_24
)
{
  int32_t
    l_39
    =
    0xE69CD17CL;
  int32_t
    l_3290
    =
    0xD1937A4EL;
  int8_t
    l_3351
    =
    (-1L);
  int32_t
    l_3352
    =
    0L;
  int32_t
    l_3429
    =
    0xE665EB51L;
  int32_t
    l_3484
    =
    (-1L);
  uint32_t
    l_3601
    [1];
  uint8_t
    l_3612
    =
    0x31L;
  uint32_t
    l_3613
    [9]
    =
    {
0x89002F36L,
0x89002F36L,
0x89002F36L,
0x89002F36L,
0x89002F36L,
0x89002F36L,
0x89002F36L,
0x89002F36L,
0x89002F36L
};
  int
    i;
  l_39
    =
    (p_24
     ||
     0xC7L);
  if ((1L ^ (safe_lshift_func_int16_t_s_s (p_23, l_39))))
  {
    int32_t
      l_53
      =
      (-5L);
    int32_t
      l_55
      =
      0x094BF7D6L;
    int32_t
      l_2017
      =
      5L;
    if (((g_71[7] = func_42 ((p_24 & func_45 ((safe_add_func_int16_t_s_s (p_23, g_30)), (g_54 = ((l_53 = g_30) ^ g_3)), g_3, (l_55 > (l_2017 = ((g_71[7] = func_56 ((safe_add_func_uint8_t_u_u (0x16L, ((safe_add_func_uint8_t_u_u ((safe_mod_func_int16_t_s_s (0x6D98L, 0x5C25L)), g_38)) != 253UL))), g_3, l_55, p_24)) >= g_2004[1][0][4]))), g_1810[0])), g_2066[5])) >= 1UL))
    {
      uint32_t
 l_3283
 =
 0x3D3C162DL;
      int32_t
 l_3296
 [1]
 [8]
 =
 {
    {0xC5C04A52L,
     0xC5C04A52L,
     0xC5C04A52L,
     0xC5C04A52L,
     0xC5C04A52L,
     0xC5C04A52L,
     0xC5C04A52L,
     0xC5C04A52L}
      };
      int8_t
 l_3373
 =
 6L;
      int32_t
 l_3374
 =
 0x73FCFB24L;
      int32_t
 l_3474
 =
 0xCA427643L;
      int
 i,
        j;
for
    (i
     =
     0;
     i
     <
     1;
     i++)
    l_3601
      [i]
      =
      0xA07D2E31L;
    }
    else
    {
      int32_t
 l_3560
 =
 0xD81A3106L;
for
    (i
     =
     0;
     i
     <
     1;
     i++)
    l_3601
      [i]
      =
      0xA07D2E31L;
l_39
    =
    (p_24
     ||
     0xC7L);
    }
  }
  else
  {
    int16_t
      l_3575
      [9]
      =
      {
  0x0A84L,
  0x0A84L,
  0x0A84L,
  0x0A84L,
  0x0A84L,
  0x0A84L,
  0x0A84L,
  0x0A84L,
  0x0A84L
};
    uint16_t
      l_3588
      =
      65526UL;
    int32_t
      l_3592
      =
      0L;
    int
      i;
for
      (g_1782
       =
       11;
       (g_1782
 <
 23);
       ++g_1782)
    {
      uint32_t
 l_3576
 =
 0x0B8E159CL;
      int32_t
 l_3577
 [5];
      int32_t
 l_3591
 =
 5L;
      int
 i;
      for
 (i
  =
  0;
  i
  <
  5;
  i++)
 l_3577
   [i]
   =
   0L;
      g_2580
 =
 (safe_mod_func_int32_t_s_s
  (((l_3577[1] = (((safe_rshift_func_int8_t_s_s ((-1L), (safe_add_func_int32_t_s_s ((((((safe_mul_func_uint8_t_u_u ((safe_add_func_int32_t_s_s (p_24, g_555)), ((l_3575[3] = 0xB2L) & l_3576))) || ((g_344 = g_1782) > g_329[1][0][0])) && p_24) <= (g_521 ^ 1L)) > g_2388[1]), 6L)))) || g_513[6]) & p_24)) || p_24), l_3351));
      g_2580
 =
 (l_3592
  =
  (((safe_mod_func_int32_t_s_s (((safe_lshift_func_uint16_t_u_s (l_3290, ((safe_sub_func_uint32_t_u_u ((+((safe_mod_func_int8_t_s_s ((l_3577[4] = l_3588), 1UL)) <= (246UL <= ((safe_sub_func_int8_t_s_s (0x11L, l_3591)) | p_24)))), (g_71[7] = 0x8AEA7E00L))) & l_3588))) || 0UL), 3L)) > p_23) == 0x49DFL));
    }
  }
  g_300
    =
    (l_3484
     &
     (safe_mul_func_uint8_t_u_u
      (p_24,
       ((safe_sub_func_uint16_t_u_u (((safe_sub_func_int8_t_s_s ((((((l_3290 = (safe_sub_func_int16_t_s_s ((g_1835[0][3][2] = (l_3601[0] != l_3601[0])), (safe_lshift_func_int8_t_s_u (p_23, (safe_add_func_uint8_t_u_u (((((safe_sub_func_int16_t_s_s (g_329[1][0][0], (((((((l_3352 > (safe_mul_func_int8_t_s_s (((safe_rshift_func_uint8_t_u_s (p_24, 4)) > ((p_24 == g_721[2]) && l_3612)), 0x44L))) && p_23) >= 0xA997E5A0L) <= g_71[7]) & g_697[1][1]) <= l_3290) & 4294967289UL))) | g_513[1]) & 0x6964L) && l_3612), p_23))))))) < g_930) == l_3613[7]) >= 0xE6B1B2DDL) == p_24), l_3601[0])) & 1UL), 0x6F95L)) & g_2617))));
  l_3290
    =
    g_521;
  return
    l_3351;
}
static int32_t
func_42
  (uint16_t
   p_43,
   int32_t
   p_44
)
{
  int16_t
    l_2846
    [10]
    [6]
    =
    {
{0x181DL,
 0x7AEEL,
 0xCD22L,
 0xCD22L,
 0x7AEEL,
 0x181DL},
  {4L,
0xD06AL,
0x682AL,
0x9ED8L,
0x181DL,
(-7L)},
  {0x7AEEL,
(-1L), 0xBE9FL, 0x181DL, 0xBE9FL, (-1L)}, {0x7AEEL, (-7L), 0x181DL, 0x9ED8L, 0x682AL, 0xD06AL}, {4L, 0x181DL, 0x7AEEL, 0xCD22L, 0xCD22L, 0x7AEEL}, {0x181DL, 0x181DL, 8L, 4L, 0x682AL, 0xCD22L}, {(-1L), (-7L), 0x9ED8L, 8L, 0xBE9FL, 8L}, {0x9ED8L, (-1L), 0x9ED8L, 0xD06AL, 0x181DL, 0xCD22L}, {(-5L), 0xD06AL, 8L, 0x1752L, 0x7AEEL, 0x7AEEL}, {0x1752L, 0x7AEEL, 0x7AEEL, 0x1752L, 8L, 0xD06AL} };
  uint32_t
    l_2874
    =
    0x3729C858L;
  int32_t
    l_2880
    =
    0x55A52D41L;
  int32_t
    l_2889
    =
    0xA5FF1CC4L;
  int32_t
    l_2891
    =
    7L;
  uint16_t
    l_2989
    =
    65535UL;
  uint32_t
    l_3008
    =
    4294967295UL;
  int
    i,
    j;
  l_2889
    =
    (8L
     ||
     1UL);
  return
    l_3008;
}
static uint8_t
func_45
  (uint32_t
   p_46,
   int32_t
   p_47,
   uint32_t
   p_48,
   int16_t
   p_49,
   uint16_t
   p_50
)
{
  int32_t
    l_2018
    =
    5L;
  uint32_t
    l_2064
    =
    0x2D09995EL;
  int32_t
    l_2068
    [5]
    [4]
    =
    {
{0L,
 1L,
 1L,
 0L},
  {(-1L), 1L, 0xBFECDBAFL, 1L}, {1L, 0x3A6E6068L, 0xBFECDBAFL, 0xBFECDBAFL}, {(-1L), (-1L), 1L, 0xBFECDBAFL}, {0L, 0x3A6E6068L, 0L, 1L} };
  int32_t
    l_2069
    [9]
    =
    {
0L,
7L,
0L,
7L,
0L,
7L,
0L,
7L,
0L
  };
  int16_t
    l_2166
    =
    0x85C1L;
  int8_t
    l_2274
    =
    0x2CL;
  int16_t
    l_2501
    [7]
    [9]
    [4]
    =
    {
{{0xDF98L, (-6L), 1L, 0x0E1AL}, {2L, (-4L), 1L, 2L}, {1L, 6L, 1L, (-6L)}, {0x1F58L, 0x41E0L, 2L, 0x41E0L}, {0xCF53L, 1L, 9L, (-6L)}, {0xB64AL, (-1L), 2L, 1L}, {1L, 0x1A61L, (-6L), 1L}, {1L, 1L, 2L, 4L}, {0xB64AL, 1L, 9L, (-10L)}}, {{0xCF53L, 2L, 2L, 0x93FCL}, {0x1F58L, (-3L), 1L, (-3L)}, {1L, 0xB1D0L, 1L, 0x0042L}, {2L, 0xCC50L, 1L, 1L}, {0xDF98L, 0xDF98L, 6L, 0x1A61L}, {0xB1D0L, 4L, 0xCC50L, 0x1F58L}, {(-1L), (-3L), 1L, 0xCC50L}, {1L, (-3L), 0x93FCL, 0x1F58L}, {(-3L), 4L, 0x4C9AL, 0x1A61L}}, {{(-6L), 0xDF98L, (-6L), 1L}, {0L, 0xCC50L, 0xDF98L, 0x0042L}, {1L, 0xB1D0L, (-6L), (-3L)}, {9L, (-3L), (-4L), 0x93FCL}, {1L, 2L, 1L, (-10L)}, {(-1L), 1L, 0x0E1AL, 4L}, {0x93FCL, 1L, 0x1F58L, 1L}, {1L, 0x1A61L, 0x1F58L, 1L}, {0x93FCL, (-1L), 0x0E1AL, (-6L)}}, {{(-1L), 1L, 1L, 0x41E0L}, {1L, 0x41E0L, (-4L), (-6L)}, {9L, 6L, (-6L), 2L}, {1L, (-4L), 0xDF98L, 0x0E1AL}, {0L, (-6L), (-6L), 0L}, {(-6L), 0x1F58L, 0x4C9AL, 2L}, {(-3L), 1L, 0x93FCL, 0xB64AL}, {1L, 0L, 1L, 0xB64AL}, {(-1L), 1L, 0xCC50L, 2L}}, {{0xB1D0L, 0x1F58L, 6L, 0L}, {0xDF98L, (-6L), 1L, 0x0E1AL}, {2L, (-4L), 1L, 2L}, {1L, 6L, 1L, (-6L)}, {0x1F58L, 0x41E0L, 2L, 0x41E0L}, {0xCF53L, 1L, 9L, (-6L)}, {0xB64AL, (-1L), 2L, 1L}, {1L, 0x1A61L, (-6L), 1L}, {1L, 1L, 2L, 4L}}, {{0xB64AL, 1L, 9L, (-10L)}, {0xCF53L, 2L, 2L, 0x93FCL}, {1L, (-6L), 9L, (-4L)}, {0L, 0x41E0L, 1L, 0x1A61L}, {1L, (-3L), 0L, 0L}, {2L, 2L, (-6L), 0x45E9L}, {0x41E0L, 0xB33EL, (-3L), 1L}, {(-10L), (-4L), 1L, (-3L)}, {2L, (-4L), (-1L), 1L}}, {{(-4L), 0xB33EL, 0xB1D0L, 0x45E9L}, {1L, 2L, 0xDF98L, 0L}, {6L, (-3L), 2L, 0x1A61L}, {2L, 0x41E0L, 1L, (-4L)}, {(-1L), (-6L), 0x1F58L, (-1L)}, {0xCF53L, (-3L), 0xCF53L, 0xCC50L}, {4L, 0xCF53L, 0xB64AL, 0xB33EL}, {(-1L), 2L, 1L, 0xCF53L}, {1L, 0x45E9L, 1L, 9L}} };
  uint16_t
    l_2599
    =
    0x2574L;
  int8_t
    l_2600
    [10]
    [4]
    =
    {
 {0xF2L,
  0x85L,
  0x6FL,
  0x71L},
{0x6FL,
0x71L,
(-1L),
0x71L},
{(-1L), 0x85L, 1L, 0x6FL}, {1L, (-1L), 0x71L, (-1L)}, {1L, (-1L), 0x14L, 0x14L}, {1L, 1L, 0x71L, 1L}, {1L, 0x14L, 1L, (-1L)}, {(-1L), 0xF2L, (-1L), 1L}, {0x6FL, 0xF2L, 0x6FL, (-1L)}, {0xF2L, 0x14L, 0L, 1L} };
  int32_t
    l_2618
    =
    3L;
  int32_t
    l_2665
    =
    4L;
  int32_t
    l_2688
    [8]
    [7]
    =
    {
{0x9075B5A3L,
 0xF546954EL,
 0x9075B5A3L,
 6L,
 0xC461791EL,
 0xC461791EL,
 6L},
  {0x762CC935L,
(-1L),
0x762CC935L,
0x6B31F81EL,
0xC10E19FDL,
0x0C874AF4L,
0x0EFC9720L},
  {0x9075B5A3L,
0xF546954EL,
0x9075B5A3L,
6L, 0xC461791EL, 0xC461791EL, 6L}, {0x762CC935L, (-1L), 0x762CC935L, 0x6B31F81EL, 0xC10E19FDL, 0x0C874AF4L, 0x0EFC9720L}, {0x9075B5A3L, 0xF546954EL, 0x9075B5A3L, 6L, 0xC461791EL, 0xC461791EL, 6L}, {0x762CC935L, (-1L), 0x762CC935L, 0x6B31F81EL, 0xC10E19FDL, 0x0C874AF4L, 0x0EFC9720L}, {0x9075B5A3L, 0xF546954EL, 0x9075B5A3L, 6L, 0xC461791EL, 0xC461791EL, 6L}, {0x762CC935L, (-1L), 0x762CC935L, 0x6B31F81EL, 0xC10E19FDL, 0x0C874AF4L, 0x0EFC9720L} };
  uint8_t
    l_2773
    [1]
    [8]
    [9]
    =
    {
{{0x22L, 0x22L, 1UL, 255UL, 1UL, 0x22L, 0x22L, 1UL, 255UL}, {249UL, 0x7BL, 249UL, 1UL, 1UL, 249UL, 0x7BL, 249UL, 1UL}, {249UL, 1UL, 1UL, 249UL, 0x7BL, 249UL, 1UL, 1UL, 249UL}, {0x22L, 1UL, 255UL, 249UL, 1UL, 1UL, 249UL, 0x7BL, 249UL}, {249UL, 0x22L, 0x7BL, 0x7BL, 0x22L, 249UL, 0x22L, 0x7BL, 0x7BL}, {1UL, 1UL, 249UL, 0x7BL, 249UL, 1UL, 1UL, 249UL, 0x7BL}, {255UL, 0x22L, 255UL, 249UL, 249UL, 255UL, 0x22L, 255UL, 249UL}, {255UL, 249UL, 249UL, 255UL, 0x22L, 255UL, 249UL, 249UL, 255UL}} };
  int
    i,
    j,
    k;
  if (p_50)
  {
    int32_t
      l_2029
      =
      0x53590018L;
{
    int32_t
      l_2029
      =
      0x53590018L;
    l_2018
      =
      (1UL
       <
       0x6500EECCL);
    g_71
      [4]
      =
      ((((l_2018 = g_1835[0][3][2]) == (safe_add_func_int32_t_s_s (((0x90A70237L || (g_930 <= (4294967295UL == ((0L <= (safe_sub_func_int16_t_s_s ((safe_sub_func_int16_t_s_s (((g_329[1][0][0] | (p_49 = (-5L))) && (((l_2029 = p_50) || (safe_rshift_func_int16_t_s_s (((safe_lshift_func_int16_t_s_u (1L, 6)) <= g_513[1]), 11))) >= p_46)), g_1835[0][1][3])), (-1L)))) ^ p_50)))) || 0UL), 0xF3D5CFC5L))) != 0L) < 0x0CB6L);
  }
    g_71
      [4]
      =
      ((((l_2018 = g_1835[0][3][2]) == (safe_add_func_int32_t_s_s (((0x90A70237L || (g_930 <= (4294967295UL == ((0L <= (safe_sub_func_int16_t_s_s ((safe_sub_func_int16_t_s_s (((g_329[1][0][0] | (p_49 = (-5L))) && (((l_2029 = p_50) || (safe_rshift_func_int16_t_s_s (((safe_lshift_func_int16_t_s_u (1L, 6)) <= g_513[1]), 11))) >= p_46)), g_1835[0][1][3])), (-1L)))) ^ p_50)))) || 0UL), 0xF3D5CFC5L))) != 0L) < 0x0CB6L);
{
    int32_t
      l_2029
      =
      0x53590018L;
    l_2018
      =
      (1UL
       <
       0x6500EECCL);
    g_71
      [4]
      =
      ((((l_2018 = g_1835[0][3][2]) == (safe_add_func_int32_t_s_s (((0x90A70237L || (g_930 <= (4294967295UL == ((0L <= (safe_sub_func_int16_t_s_s ((safe_sub_func_int16_t_s_s (((g_329[1][0][0] | (p_49 = (-5L))) && (((l_2029 = p_50) || (safe_rshift_func_int16_t_s_s (((safe_lshift_func_int16_t_s_u (1L, 6)) <= g_513[1]), 11))) >= p_46)), g_1835[0][1][3])), (-1L)))) ^ p_50)))) || 0UL), 0xF3D5CFC5L))) != 0L) < 0x0CB6L);
  }
  }
  else
  {
    uint16_t
      l_2038
      [5]
      [4]
      =
      {
 {1UL,
  0xAA75L,
  1UL,
  1UL}
    , {0xAA75L, 0xAA75L, 65530UL, 0xAA75L}
    , {0xAA75L, 1UL, 1UL, 0xAA75L}
    , {1UL, 0xAA75L, 1UL, 1UL}
    , {0xAA75L, 0xAA75L, 65530UL, 0xAA75L}
    };
    int32_t
      l_2041
      [4]
      [2]
      =
      {
  {0xE3388646L,
   1L}
    , {0xE3388646L, 0xE3388646L}
    , {1L, 0xE3388646L}
    , {0xE3388646L, 1L}
    };
    uint8_t
      l_2067
      =
      251UL;
    int32_t
      l_2174
      =
      (-1L);
    int16_t
      l_2229
      [8]
      =
      {
  0x8CA6L,
  0x8CA6L,
  0x8CA6L,
  0x8CA6L,
  0x8CA6L,
  0x8CA6L,
  0x8CA6L,
  0x8CA6L
};
    int16_t
      l_2231
      =
      0xCA11L;
    uint8_t
      l_2269
      =
      8UL;
    int
      i,
      j;
g_1763
      =
      ((safe_mod_func_int32_t_s_s (((g_866 & (l_2038[4][1] = l_2018)) > ((safe_mod_func_uint32_t_u_u ((247UL >= 0xDFL), g_866)) == (l_2041[0][0] = 0xF2L))), p_48)) & (safe_sub_func_uint8_t_u_u (l_2018, (0xF8L & l_2018))));
{
    int32_t
      l_2029
      =
      0x53590018L;
    l_2018
      =
      (1UL
       <
       0x6500EECCL);
    g_71
      [4]
      =
      ((((l_2018 = g_1835[0][3][2]) == (safe_add_func_int32_t_s_s (((0x90A70237L || (g_930 <= (4294967295UL == ((0L <= (safe_sub_func_int16_t_s_s ((safe_sub_func_int16_t_s_s (((g_329[1][0][0] | (p_49 = (-5L))) && (((l_2029 = p_50) || (safe_rshift_func_int16_t_s_s (((safe_lshift_func_int16_t_s_u (1L, 6)) <= g_513[1]), 11))) >= p_46)), g_1835[0][1][3])), (-1L)))) ^ p_50)))) || 0UL), 0xF3D5CFC5L))) != 0L) < 0x0CB6L);
  }
    l_2041
      [2]
      [0]
      =
      p_49;
  }
  if ((0UL && (l_2068[4][0] = (safe_lshift_func_int8_t_s_u (0x5BL, g_1835[0][3][2])))))
  {
    l_2069
      [1]
      =
      g_1265
      [4]
      [6];
  }
  else
  {
    int8_t
      l_2275
      =
      0x4FL;
    int16_t
      l_2286
      =
      0xE996L;
    int32_t
      l_2307
      =
      (-9L);
    int16_t
      l_2390
      =
      (-7L);
    int32_t
      l_2541
      =
      6L;
    int32_t
      l_2687
      =
      0xFA5AF561L;
    uint32_t
      l_2751
      [10]
      [6]
      [4]
      =
      {
 {{4294967295UL, 4294967286UL, 0xF2705C3FL, 4294967289UL}
  ,
  {4294967288UL,
   4294967294UL,
   0x6EA099C9L,
   4294967291UL}
  ,
  {4294967294UL,
   4294967286UL,
   4294967286UL,
   4294967294UL}
  ,
  {0xF2705C3FL,
   4294967295UL,
   1UL,
   0x5257FFECL}
  ,
  {1UL,
   0x8536B1B9L,
   0x6EA099C9L,
   4294967288UL}
  ,
  {1UL,
   0xC43BF8C1L,
   0x86AB77E4L,
   4294967288UL}
  }
    , {{4294967295UL, 0x8536B1B9L, 4294967289UL, 0x5257FFECL}
       ,
       {4294967291UL,
 4294967295UL,
 4294967288UL,
 4294967294UL}
       ,
       {1UL,
 4294967286UL,
 0x5257FFECL,
 4294967291UL}
       ,
       {4294967295UL,
 4294967294UL,
 4294967295UL,
 4294967289UL}
       ,
       {0x8536B1B9L,
 4294967286UL,
 0x6EA099C9L,
 1UL}
       ,
       {4294967286UL,
 4294967286UL,
 0xC43BF8C1L,
 4294967286UL}
       }
    , {{0xF2705C3FL, 4294967291UL, 0xC43BF8C1L, 0x5257FFECL}
       ,
       {4294967286UL,
 4294967288UL,
 0x6EA099C9L,
 0x8536B1B9L}
       ,
       {0x8536B1B9L,
 0xC43BF8C1L,
 4294967295UL,
 1UL}
       ,
       {4294967295UL,
 1UL,
 0x5257FFECL,
 0x5257FFECL}
       ,
       {1UL,
 1UL,
 4294967288UL,
 1UL}
       ,
       {4294967291UL,
 4294967286UL,
 4294967289UL,
 4294967295UL}
       }
    , {{4294967295UL, 1UL, 0x86AB77E4L, 4294967289UL}
       ,
       {1UL,
 1UL,
 0x6EA099C9L,
 4294967295UL}
       ,
       {1UL,
 4294967286UL,
 1UL,
 1UL}
       ,
       {0xF2705C3FL,
 1UL,
 0x3541CA9AL,
 0x9732D57AL}
       ,
       {1UL,
 0x1B14A3E0L,
 4294967295UL,
 0x1B14A3E0L}
       ,
       {0x5257FFECL,
 0x6EA099C9L,
 4294967292UL,
 4294967289UL}
       }
    , {{0x31982B39L, 0x5257FFECL, 4294967288UL, 0x9732D57AL}
       ,
       {4294967295UL,
 0xF2705C3FL,
 4294967291UL,
 0xC43BF8C1L}
       ,
       {4294967295UL,
 0x3541CA9AL,
 4294967288UL,
 0x86AB77E4L}
       ,
       {0x31982B39L,
 0xC43BF8C1L,
 4294967292UL,
 0x609A3784L}
       ,
       {0x5257FFECL,
 1UL,
 4294967295UL,
 0xF2705C3FL}
       ,
       {1UL,
 0x3541CA9AL,
 0x3541CA9AL,
 1UL}
       }
    , {{4294967292UL, 4294967295UL, 4294967288UL, 0x9732D57AL}
       ,
       {4294967286UL,
 4294967289UL,
 4294967295UL,
 0x5257FFECL}
       ,
       {0x1B14A3E0L,
 0x6EA099C9L,
 0x36F5171BL,
 0x5257FFECL}
       ,
       {0x31982B39L,
 4294967289UL,
 0x609A3784L,
 0x9732D57AL}
       ,
       {0xF2705C3FL,
 4294967295UL,
 4294967291UL,
 1UL}
       ,
       {0x86AB77E4L,
 0x3541CA9AL,
 0x9732D57AL,
 0xF2705C3FL}
       }
    , {{0x31982B39L, 1UL, 0x31982B39L, 0x609A3784L}
       ,
       {4294967289UL,
 0xC43BF8C1L,
 4294967295UL,
 0x86AB77E4L}
       ,
       {0xC43BF8C1L,
 0x3541CA9AL,
 0x6EA099C9L,
 0xC43BF8C1L}
       ,
       {4294967292UL,
 0xF2705C3FL,
 0x6EA099C9L,
 0x9732D57AL}
       ,
       {0xC43BF8C1L,
 0x5257FFECL,
 4294967295UL,
 4294967289UL}
       ,
       {4294967289UL,
 0x6EA099C9L,
 0x31982B39L,
 0x1B14A3E0L}
       }
    , {{0x31982B39L, 0x1B14A3E0L, 0x9732D57AL, 0x9732D57AL}
       ,
       {0x86AB77E4L,
 0x86AB77E4L,
 4294967291UL,
 4294967286UL}
       ,
       {0xF2705C3FL,
 0x3541CA9AL,
 0x609A3784L,
 4294967295UL}
       ,
       {0x31982B39L,
 4294967286UL,
 0x36F5171BL,
 0x609A3784L}
       ,
       {0x1B14A3E0L,
 4294967286UL,
 4294967295UL,
 4294967295UL}
       ,
       {4294967286UL,
 0x3541CA9AL,
 4294967288UL,
 4294967286UL}
       }
    , {{4294967292UL, 0x86AB77E4L, 0x3541CA9AL, 0x9732D57AL}
       ,
       {1UL,
 0x1B14A3E0L,
 4294967295UL,
 0x1B14A3E0L}
       ,
       {0x5257FFECL,
 0x6EA099C9L,
 4294967292UL,
 4294967289UL}
       ,
       {0x31982B39L,
 0x5257FFECL,
 4294967288UL,
 0x9732D57AL}
       ,
       {4294967295UL,
 0xF2705C3FL,
 4294967291UL,
 0xC43BF8C1L}
       ,
       {4294967295UL,
 0x3541CA9AL,
 4294967288UL,
 0x86AB77E4L}
       }
    , {{0x31982B39L, 0xC43BF8C1L, 4294967292UL, 0x609A3784L}
       ,
       {0x5257FFECL,
 1UL,
 4294967295UL,
 0xF2705C3FL}
       ,
       {1UL,
 0x3541CA9AL,
 0x3541CA9AL,
 1UL}
       ,
       {4294967292UL,
 4294967295UL,
 4294967288UL,
 0x9732D57AL}
       ,
       {4294967286UL,
 4294967289UL,
 4294967295UL,
 0x5257FFECL}
       ,
       {0x1B14A3E0L,
 0x6EA099C9L,
 0x36F5171BL,
 0x5257FFECL}
       }
    };
    int
      i,
      j,
      k;
    l_2275
      =
      l_2274;
    for
      (p_49
       =
       0;
       (p_49
 !=
 (-23));
       p_49
       =
       safe_sub_func_uint8_t_u_u
       (p_49,
 1))
    {
      uint32_t
 l_2284
 =
 4294967294UL;
      int32_t
 l_2285
 =
 0x23D170B6L;
      uint16_t
 l_2592
 =
 65534UL;
      int32_t
 l_2620
 =
 0x829167AAL;
      uint32_t
 l_2705
 =
 0xCFCFF65DL;
      uint32_t
 l_2750
 [1]
 [4]
 =
 {
   {0xFAF1AE15L,
    0xFAF1AE15L,
    0xFAF1AE15L,
    0xFAF1AE15L}
      };
      int32_t
 l_2804
 =
 0x6AB7DBD1L;
      int
 i,
        j;
      for
 (g_774
  =
  0;
  (g_774
   <
   20);
  g_774++)
      {
 uint16_t
   l_2291
   =
   0x6398L;
 int32_t
   l_2356
   =
   0xD1E4E71CL;
 int32_t
   l_2391
   =
   0xE260C856L;
 for
   (g_201
    =
    0;
    (g_201
     >=
     (-27));
    g_201
    =
    safe_sub_func_int16_t_s_s
    (g_201,
     6))
 {
   int8_t
     l_2305
     =
     0x14L;
   int32_t
     l_2306
     =
     (-1L);
   l_2307
     =
     (safe_unary_minus_func_int32_t_s
      ((safe_mod_func_uint8_t_u_u (((p_46 = (l_2306 = (safe_sub_func_uint32_t_u_u ((safe_add_func_int8_t_s_s ((((((254UL & 1UL) == (safe_lshift_func_int8_t_s_u (0xF8L, 6))) && 0xCDL) && ((safe_lshift_func_int16_t_s_u (g_38, 7)) ^ (g_329[1][2][1] > (l_2305 = l_2275)))) | l_2275), g_2065)), p_46)))) == l_2064), p_47))));
 }
      }
{
    int32_t
      l_2029
      =
      0x53590018L;
    l_2018
      =
      (1UL
       <
       0x6500EECCL);
    g_71
      [4]
      =
      ((((l_2018 = g_1835[0][3][2]) == (safe_add_func_int32_t_s_s (((0x90A70237L || (g_930 <= (4294967295UL == ((0L <= (safe_sub_func_int16_t_s_s ((safe_sub_func_int16_t_s_s (((g_329[1][0][0] | (p_49 = (-5L))) && (((l_2029 = p_50) || (safe_rshift_func_int16_t_s_s (((safe_lshift_func_int16_t_s_u (1L, 6)) <= g_513[1]), 11))) >= p_46)), g_1835[0][1][3])), (-1L)))) ^ p_50)))) || 0UL), 0xF3D5CFC5L))) != 0L) < 0x0CB6L);
  }
      g_1763
 =
 (((0UL <= ((g_930 = ((safe_mod_func_uint8_t_u_u ((safe_mod_func_int8_t_s_s (((g_697[1][1] = (safe_mod_func_int8_t_s_s (((safe_sub_func_uint32_t_u_u ((l_2068[3][1] & (safe_sub_func_uint8_t_u_u (p_47, (g_1265[2][5] < ((safe_mod_func_int16_t_s_s (((((safe_unary_minus_func_int8_t_s ((l_2541 >= (safe_mul_func_uint8_t_u_u (p_48, 254UL))))) <= (((l_2307 = 0x5A01L) & (safe_rshift_func_uint8_t_u_u (g_71[8], 4))) && l_2068[1][2])) >= l_2541) < (-8L)), p_46)) | p_50))))), (-1L))) || p_47), g_2004[0][0][2]))) == g_721[7]), l_2166)), p_50)) >= l_2284)) < 1UL)) != g_2004[0][0][2]) == 0xDFL);
for
 (g_774
  =
  0;
  (g_774
   <
   20);
  g_774++)
      {
 uint16_t
   l_2291
   =
   0x6398L;
 int32_t
   l_2356
   =
   0xD1E4E71CL;
 int32_t
   l_2391
   =
   0xE260C856L;
 g_71
   [7]
   =
   ((safe_sub_func_int16_t_s_s ((safe_add_func_uint16_t_u_u ((0x02D3L | ((g_2004[0][0][2] = (l_2284 = g_697[8][0])) | (((g_1266 ^ g_329[1][1][0]) != ((65528UL && (l_2275 < (((((l_2286 = l_2285) || (safe_sub_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (l_2291, 65535UL)), g_2248))) == g_1810[0]) == p_50) && g_201))) && 65532UL)) >= p_48))), (-5L))), g_521)) > p_50);
 for
   (g_201
    =
    0;
    (g_201
     >=
     (-27));
    g_201
    =
    safe_sub_func_int16_t_s_s
    (g_201,
     6))
 {
   int8_t
     l_2305
     =
     0x14L;
   int32_t
     l_2306
     =
     (-1L);
   l_2307
     =
     (safe_unary_minus_func_int32_t_s
      ((safe_mod_func_uint8_t_u_u (((p_46 = (l_2306 = (safe_sub_func_uint32_t_u_u ((safe_add_func_int8_t_s_s ((((((254UL & 1UL) == (safe_lshift_func_int8_t_s_u (0xF8L, 6))) && 0xCDL) && ((safe_lshift_func_int16_t_s_u (g_38, 7)) ^ (g_329[1][2][1] > (l_2305 = l_2275)))) | l_2275), g_2065)), p_46)))) == l_2064), p_47))));
 }
 l_2069
   [7]
   =
   (((safe_mul_func_int8_t_s_s ((safe_lshift_func_uint8_t_u_s (l_2274, (safe_add_func_uint8_t_u_u (p_46, ((((g_2004[6][0][8] && ((safe_mod_func_uint32_t_u_u (p_46, l_2307)) || ((((safe_rshift_func_int8_t_s_u ((l_2285 = (safe_mul_func_int16_t_s_s (((safe_rshift_func_int16_t_s_u (((safe_add_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_s (((l_2018 ^ (p_48 == ((!((safe_add_func_uint8_t_u_u ((((safe_mul_func_uint8_t_u_u (((((safe_add_func_uint8_t_u_u ((safe_add_func_uint32_t_u_u ((safe_unary_minus_func_int16_t_s (6L)), ((((-2L) < p_48) > g_71[7]) < p_46))), p_48)) && g_3) > p_49) > 0xB3L), p_47)) >= g_1265[2][5]) > 0L), 0x7FL)) && l_2291)) >= l_2018))) & p_48), 3)), 0x855FL)) || 4294967288UL), 6)) != 0UL), p_50))), p_49)) >= p_49) == l_2284) == g_1835[0][3][2]))) <= 0x7D15L) >= g_458) < g_2004[6][0][1]))))), 0x18L)) && p_50) & g_2066[8]);
 for
   (l_2291
    =
    0;
    (l_2291
     >=
     29);
    l_2291++)
 {
   uint32_t
     l_2353
     =
     0xF86D6531L;
   int32_t
     l_2354
     =
     0x780498DDL;
   int32_t
     l_2355
     =
     1L;
   if ((l_2069[4] = ((g_329[1][0][0] = (l_2355 = (((safe_add_func_uint16_t_u_u (p_48, ((l_2307 = (g_697[8][0] = l_2064)) == (safe_rshift_func_int8_t_s_u ((p_49 | (safe_lshift_func_uint8_t_u_u ((safe_lshift_func_uint16_t_u_u ((safe_sub_func_int32_t_s_s ((safe_lshift_func_uint16_t_u_s ((((4L == p_50) >= 255UL) < (safe_rshift_func_int16_t_s_u (((p_50 < (safe_mod_func_int16_t_s_s ((0xF9L | (p_48 <= 0xC3L)), 5UL))) < l_2353), p_50))), p_47)), g_669)), p_48)), 0))), 6))))) != 0UL) | l_2354))) ^ g_513[3])))
   {
     l_2355
       =
       p_49;
   }
   else
   {
     uint16_t
       l_2389
       =
       1UL;
     l_2356
       =
       p_49;
     l_2307
       =
       ((safe_add_func_int8_t_s_s (p_48, ((4294967295UL ^ g_1917) || ((safe_mul_func_uint16_t_u_u (((safe_rshift_func_int8_t_s_u (0xB7L, 1)) >= 0x889CL), (l_2355 = (p_47 ^ 0xEF84L)))) && (safe_rshift_func_uint8_t_u_s (l_2286, ((safe_mul_func_int8_t_s_s ((safe_mod_func_uint32_t_u_u ((safe_mod_func_int16_t_s_s (((safe_mul_func_uint16_t_u_u ((g_1266 = (l_2307 != g_1763)), g_866)) > l_2285), g_2373)), g_521)), 0xD7L)) < p_49))))))) == 3UL);
     l_2069
       [4]
       =
       (safe_sub_func_uint32_t_u_u
        ((safe_lshift_func_int8_t_s_u ((g_2004[0][0][2] = ((l_2356 = (-1L)) < (safe_lshift_func_int16_t_s_u (((((safe_add_func_uint8_t_u_u (((0x1515L || (l_2285 = 0UL)) == (l_2391 = (((safe_mod_func_uint32_t_u_u ((((p_47 != (0UL || (p_50 == (safe_lshift_func_uint16_t_u_s ((((safe_rshift_func_uint8_t_u_u (g_2388[1], 3)) > ((4294967295UL & ((0x730A2E1BL || g_513[2]) < g_1782)) && g_1266)) & p_48), l_2389))))) != p_47) || l_2390), l_2284)) | 0xDFL) && 0x57D4L))), p_47)) < 0xB6042B58L) ^ g_697[8][0]) || 3UL), 3)))), g_1763)), g_329[1][0][0]));
   }
 }
      }
    }
  }
  return
    l_2600
    [9]
    [3];
}
static int32_t
func_56
  (int32_t
   p_57,
   uint16_t
   p_58,
   int8_t
   p_59,
   uint32_t
   p_60
)
{
  uint8_t
    l_67
    =
    0xB9L;
  int8_t
    l_70
    [6]
    [7]
    [1]
    =
    {
 {{1L}, {(-3L)}, {0x4AL}, {1L}, {0x63L}, {0x63L}, {1L}}, {{0x4AL}, {(-3L)}, {1L}, {1L}, {9L}, {1L}, {1L}}, {{(-3L)}, {0x4AL}, {1L}, {0x63L}, {0x63L}, {1L}, {0x4AL}}, {{(-3L)}, {1L}, {1L}, {9L}, {1L}, {1L}, {(-3L)}}, {{0x4AL}, {1L}, {0x63L}, {0x63L}, {1L}, {0x4AL}, {(-3L)}}, {{1L}, {1L}, {9L}, {1L}, {1L}, {(-3L)}, {0x4AL}} };
  int32_t
    l_609
    [1];
  int32_t
    l_799
    =
    0x1C79E083L;
  int32_t
    l_800
    =
    (-4L);
  uint32_t
    l_1005
    =
    4294967295UL;
  int32_t
    l_1188
    [8]
    =
    {
0x6ABF1D7CL,
(-1L),
(-1L),
0x6ABF1D7CL,
(-1L),
(-1L),
0x6ABF1D7CL,
(-1L)
  };
  uint8_t
    l_1250
    =
    0xEFL;
  uint32_t
    l_1341
    =
    0x247F7062L;
  uint16_t
    l_1453
    =
    0x3BE5L;
  uint16_t
    l_1570
    =
    2UL;
  uint32_t
    l_1586
    =
    0xCC4ED126L;
  int32_t
    l_1833
    =
    0x648F05D7L;
  int32_t
    l_1834
    =
    (-3L);
  uint16_t
    l_1837
    =
    0UL;
  uint32_t
    l_2003
    =
    0UL;
  int
    i,
    j,
    k;
  for
    (i
     =
     0;
     i
     <
     1;
     i++)
    l_609
      [i]
      =
      (-3L);
for
    (i
     =
     0;
     i
     <
     1;
     i++)
    l_609
      [i]
      =
      (-3L);
  l_609
    [0]
    =
    g_329
    [1]
    [0]
    [5];
  for
    (g_300
     =
     0;
     (g_300
      <=
      4);
     g_300
     +=
     1)
  {
    int8_t
      l_1384
      [9]
      =
      {
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L)
 };
    int32_t
      l_1403
      [10]
      =
      {
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L
};
    int32_t
      l_1438
      [10]
      [1]
      [2]
      =
      {
  {{0x1D3F6542L, 9L}
   }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    };
    int32_t
      l_1441
      =
      0x0BC2D57BL;
    uint32_t
      l_1502
      [4]
      =
      {
 0xDC6A9CBAL,
 0xDC6A9CBAL,
 0xDC6A9CBAL,
 0xDC6A9CBAL
};
    int32_t
      l_1534
      =
      0x7453318EL;
    uint16_t
      l_1601
      [3];
    int16_t
      l_1744
      =
      0x6254L;
    int
      i,
      j,
      k;
    for
      (i
       =
       0;
       i
       <
       3;
       i++)
      {
l_1601
 [i]
 =
 0xB24DL;
{
    int8_t
      l_1384
      [9]
      =
      {
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L)
 };
    int32_t
      l_1403
      [10]
      =
      {
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L
};
    int32_t
      l_1438
      [10]
      [1]
      [2]
      =
      {
  {{0x1D3F6542L, 9L}
   }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    };
    int32_t
      l_1441
      =
      0x0BC2D57BL;
    uint32_t
      l_1502
      [4]
      =
      {
 0xDC6A9CBAL,
 0xDC6A9CBAL,
 0xDC6A9CBAL,
 0xDC6A9CBAL
};
    int32_t
      l_1534
      =
      0x7453318EL;
    uint16_t
      l_1601
      [3];
    int16_t
      l_1744
      =
      0x6254L;
    int
      i,
      j,
      k;
    for
      (i
       =
       0;
       i
       <
       3;
       i++)
      l_1601
 [i]
 =
 0xB24DL;
    for
      (l_1341
       =
       0;
       (l_1341
 <=
 4);
       l_1341
       +=
       1)
    {
      uint16_t
 l_1364
 =
 65535UL;
      int32_t
 l_1379
 [10]
 [7]
 =
 {
    {0x64CD1FA4L,
     9L,
     0x6F22B797L,
     9L,
     0x64CD1FA4L,
     (-1L),
     0x6F22B797L}
      , {0x4AF1F542L, 0xDD5DAFA3L, 0L, 0L, 0xDD5DAFA3L, 0x4AF1F542L, 0xF78852C5L}
      , {0L, 1L, 8L, (-1L), 8L, 1L, 0L}
      , {0x4AF1F542L, 0L, 0xF78852C5L, 0xE476DB24L, 0xE476DB24L, 0xF78852C5L, 0L}
      , {0x64CD1FA4L, 1L, 4L, 0x349346A9L, 0x64CD1FA4L, 0x349346A9L, 4L}
      , {0xE476DB24L, 0xDD5DAFA3L, 0xF78852C5L, 6L, 0x4AF1F542L, 0x4AF1F542L, 6L}
      , {8L, 9L, 8L, 0x349346A9L, 0L, 9L, 0L}
      , {0xDD5DAFA3L, 6L, 0L, 0xE476DB24L, 0x4AF1F542L, (-1L), (-1L)}
      , {0x64CD1FA4L, (-1L), 0x6F22B797L, (-1L), 0x64CD1FA4L, 9L, 0x6F22B797L}
      , {(-6L), 0xDD5DAFA3L, 6L, 0L, 0xE476DB24L, 0x4AF1F542L, (-1L)}
      };
      uint32_t
 l_1431
 =
 4294967293UL;
      int32_t
 l_1578
 =
 0xF5ADD8F0L;
      uint8_t
 l_1616
 =
 0UL;
      int
 i,
        j;
      for
 (g_458
  =
  0;
  (g_458
   <=
   7);
  g_458
  +=
  1)
      {
 int32_t
   l_1383
   =
   0xCC80471DL;
 int32_t
   l_1422
   =
   0L;
 int32_t
   l_1423
   [9]
   [4]
   =
   {
      {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0x0542477FL}
 , {0x7D6DFEFEL, (-1L), 0xB7D78E3EL, (-1L)}
 , {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0xB7D78E3EL}
 };
 int32_t
   l_1444
   =
   0xE4F95524L;
 uint32_t
   l_1470
   =
   0x087273C0L;
 int32_t
   l_1475
   =
   3L;
 int16_t
   l_1488
   =
   (-6L);
 int32_t
   l_1497
   =
   0xD570C473L;
 int
   i,
   j;
 l_1364
   =
   l_1188
   [g_458];
 if ((g_71[1] = (safe_mul_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u (p_59, (g_774 = (((safe_add_func_uint8_t_u_u (l_1364, ((safe_lshift_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((-1L) | (safe_sub_func_uint32_t_u_u (((!((-1L) <= ((1L || ((l_1379[2][3] = (l_1188[g_458] == (0x10L & g_30))) < (~(safe_lshift_func_uint16_t_u_s ((p_58 = (((l_1383 = (((0x2EL && g_71[2]) == g_1382) > l_1364)) || g_930) != l_1188[g_458])), 12))))) & (-2L)))) | l_1188[g_458]), g_344))) | g_721[3]), 249UL)) != g_1266), 11)) < 0UL))) ^ 9UL) ^ l_1384[4])))), 0xC5F3L))))
 {
   int32_t
     l_1440
     =
     0L;
   int32_t
     l_1454
     =
     1L;
   int32_t
     l_1457
     [1];
   int
     i;
   for
     (i
      =
      0;
      i
      <
      1;
      i++)
     l_1457
       [i]
       =
       0xC6483828L;
   for
     (g_521
      =
      1;
      (g_521
       <=
       4);
      g_521
      +=
      1)
   {
     uint8_t
       l_1402
       =
       255UL;
     int32_t
       l_1424
       =
       5L;
     g_71
       [3]
       =
       (l_1383
        =
        l_1383);
     l_1403
       [1]
       =
       ((safe_mod_func_int32_t_s_s ((safe_rshift_func_int8_t_s_s ((safe_sub_func_uint8_t_u_u (g_367, g_3)), (safe_sub_func_int8_t_s_s ((g_930 = g_978), (safe_add_func_uint8_t_u_u (g_367, g_1266)))))), (safe_unary_minus_func_int32_t_s ((l_609[0] = (0x39L || (safe_rshift_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u (((safe_sub_func_int8_t_s_s (l_1379[2][3], (l_1402 = ((g_300 && p_59) == g_344)))) || 0x5D37L), p_59)), p_58)))))))) == g_344);
     l_1424
       =
       ((safe_add_func_uint16_t_u_u (((l_1423[3][1] = (l_1383 = (l_1379[2][3] = ((((safe_lshift_func_int16_t_s_u (((safe_add_func_int8_t_s_s (((((g_555 = g_201) == (safe_sub_func_uint8_t_u_u ((p_57 & p_60), (+(safe_add_func_uint16_t_u_u (((!65531UL) == (l_1402 && (l_1379[1][6] <= ((safe_mul_func_int16_t_s_s (p_59, 0x6A1EL)) ^ (safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u (((safe_sub_func_int32_t_s_s ((g_3 ^ 7UL), 9L)) == p_59), 4294967295UL)), g_930)))))), l_1384[4])))))) < l_1422) != p_57), l_1402)) ^ l_1422), g_367)) && g_1265[2][5]) > g_71[5]) >= 7L)))) & 0L), l_1364)) <= p_59);
     return
       l_1379
       [7]
       [5];
   }
   for
     (p_59
      =
      0;
      (p_59
       <=
       7);
      p_59
      +=
      1)
   {
     uint32_t
       l_1439
       =
       0x7C99E9CAL;
     l_1379
       [2]
       [3]
       =
       g_513
       [1];
     l_799
       =
       g_697
       [8]
       [0];
     l_1441
       =
       (safe_add_func_int32_t_s_s
        ((l_1440 = (safe_mod_func_int32_t_s_s ((((safe_mod_func_int16_t_s_s (l_1431, g_697[7][1])) ^ (safe_add_func_int16_t_s_s ((safe_sub_func_int32_t_s_s (g_1281, (safe_rshift_func_uint8_t_u_u (((g_513[3] & (l_1438[5][0][1] = (g_344 ^ (l_1403[9] = 0xB097F462L)))) == (0UL | (-1L))), 3)))), (l_1384[4] == p_58)))) < l_1439), l_1423[3][1]))), g_458));
   }
   l_1383
     =
     ((l_1457[0] = ((l_1444 = (safe_rshift_func_uint8_t_u_u ((l_1438[5][0][1] = l_1383), 2))) & (l_1379[2][3] = (l_1250 || ((0L <= (((safe_mul_func_uint16_t_u_u ((g_774 = (g_1265[2][5] || l_1440)), (!(l_1423[3][1] = (safe_mod_func_int16_t_s_s ((safe_add_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s (g_30, l_1453)), (l_1454 = 1L))), ((safe_sub_func_int16_t_s_s ((g_697[5][0] = p_57), 4UL)) ^ l_1441))))))) < g_71[3]) ^ l_1379[8][1])) < 1UL))))) ^ l_1403[0]);
 }
 else
 {
   uint32_t
     l_1468
     [4];
   int32_t
     l_1469
     =
     (-1L);
   int32_t
     l_1583
     [1]
     [9]
     [1]
     =
     {
 {{0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  }
   };
   int
     i,
     j,
     k;
   for
     (i
      =
      0;
      i
      <
      4;
      i++)
     l_1468
       [i]
       =
       0UL;
   l_1423
     [3]
     [1]
     =
     ((l_1441 = p_60) > (safe_add_func_int8_t_s_s ((g_344 = (safe_add_func_uint16_t_u_u (0UL, ((6UL || (l_1383 > p_58)) == (((safe_mul_func_uint8_t_u_u (g_866, 0x91L)) != ((safe_add_func_int8_t_s_s ((safe_sub_func_uint16_t_u_u ((l_1468[0] = (p_60 | p_60)), l_1469)), 0xBEL)) || g_1266)) < p_58))))), 0L)));
   if ((l_1470 & (safe_sub_func_int32_t_s_s (((((safe_sub_func_uint8_t_u_u (l_1475, l_609[0])) == p_59) ^ (safe_lshift_func_int16_t_s_u ((((safe_sub_func_int16_t_s_s ((safe_mod_func_int32_t_s_s (((g_555 = (0x0B1DL == p_60)) && g_71[7]), (safe_mul_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u ((g_344 = (p_60 != ((+(((safe_lshift_func_uint16_t_u_s (0xB105L, p_57)) >= p_57) < g_71[7])) && l_1441))), 2)), g_588)))), g_1281)) || g_697[8][0]) ^ p_59), g_920))) || l_1488), g_521))))
   {
     int8_t
       l_1503
       =
       0xE6L;
     l_1383
       =
       (safe_mul_func_uint8_t_u_u
        (p_60,
  p_57));
     l_1423
       [3]
       [1]
       =
       (+
        (!
  (safe_rshift_func_uint8_t_u_s
   (l_1468
    [0],
    ((g_513[2] < p_59) <= (safe_mul_func_int16_t_s_s (9L, (0x8FL < (l_1469 = (safe_sub_func_uint16_t_u_u (l_1497, ((safe_sub_func_int16_t_s_s ((g_697[8][0] = p_58), (g_521 = (-7L)))) != (safe_lshift_func_int16_t_s_u ((l_1502[1] & 8L), l_1502[1]))))))))))))));
     g_71
       [6]
       =
       (l_1503
        =
        g_588);
     if (g_697[8][0])
       break;
   }
   else
   {
     int32_t
       l_1524
       =
       0x6DC5B83AL;
     l_1441
       =
       l_1468
       [0];
     l_1469
       =
       ((p_58 = (safe_add_func_int32_t_s_s (((((((safe_mod_func_int8_t_s_s (((safe_lshift_func_uint8_t_u_u ((0x3CE0A1BCL < l_1188[7]), (safe_add_func_int8_t_s_s ((0x37L >= (((safe_add_func_int16_t_s_s ((+(!((safe_rshift_func_int16_t_s_u (((safe_sub_func_int16_t_s_s ((l_800 = ((safe_add_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_s ((l_609[0] | ((safe_lshift_func_uint16_t_u_s (l_1384[4], g_201)) | 0x06C8L)), 0)), 255UL)) || (((0x0530L == g_329[1][0][0]) >= 1UL) ^ g_1281))), g_721[5])) && 255UL), p_60)) < l_1524))), l_1438[1][0][1])) > l_1469) || p_59)), p_59)))) <= p_60), 0x7FL)) & g_721[3]) <= g_329[1][4][2]) == (-9L)) | p_58) & g_1266), l_1379[6][0]))) & p_57);
     if (g_458)
       continue;
     g_71
       [7]
       =
       g_978;
   }
   if ((safe_sub_func_uint32_t_u_u (p_57, ((g_329[1][0][0] = 1UL) > 0x4F799D86L))))
   {
     uint32_t
       l_1527
       =
       0x90FEEB0CL;
     g_71
       [7]
       =
       l_1527;
     l_1438
       [5]
       [0]
       [1]
       =
       (p_59
        >=
        (safe_mod_func_uint16_t_u_u
  (((safe_add_func_uint32_t_u_u (((safe_add_func_int16_t_s_s (l_1534, (g_555 >= (safe_rshift_func_uint8_t_u_u ((((l_1379[3][3] = (g_920 = ((l_1469 = (p_59 > (safe_rshift_func_uint16_t_u_s (((g_697[8][0] = (l_1423[0][1] < p_58)) ^ (safe_sub_func_uint32_t_u_u (0xC6944EA8L, 0x231AE895L))), (safe_mul_func_int16_t_s_s (((g_1266 = (safe_mul_func_uint16_t_u_u (0x4B84L, p_58))) == l_1468[1]), 0x7211L)))))) || l_1453))) > p_57) ^ g_669), l_1431))))) == p_60), 0UL)) ^ l_1384[4]), 0xEAF0L)));
     g_71
       [2]
       =
       ((p_57 <= ((safe_sub_func_int16_t_s_s ((l_1379[1][5] = 0x41B3L), (((0x44B3AF87L | g_30) && l_1431) == g_1382))) ^ (l_799 = (safe_sub_func_int16_t_s_s (g_721[3], ((0x8FL ^ p_60) == g_344)))))) || g_367);
     l_800
       =
       (g_71
        [7]
        =
        ((l_609[0] = (g_329[0][0][1] = ((safe_sub_func_int32_t_s_s ((safe_unary_minus_func_uint8_t_u (((safe_mul_func_int16_t_s_s (((safe_sub_func_int16_t_s_s (g_38, (l_1527 > ((safe_mod_func_int8_t_s_s ((g_344 = p_58), (safe_add_func_uint32_t_u_u (p_57, l_1527)))) >= 0xD928L)))) < ((safe_unary_minus_func_uint32_t_u ((safe_mod_func_uint8_t_u_u ((safe_mod_func_uint16_t_u_u (((~((((safe_unary_minus_func_uint16_t_u (l_1527)) > (~l_70[1][5][0])) || (safe_lshift_func_int8_t_s_s (((((((safe_add_func_uint32_t_u_u (((g_1266 < (-1L)) || p_59), 0xA3200367L)) > p_59) <= l_1364) & l_1527) != 0x2212L) && g_513[2]), l_1379[2][3]))) <= p_58)) <= p_58), g_329[0][6][2])), p_58)))) ^ l_1570)), p_57)) > l_1438[9][0][1]))), 0x19F76790L)) != 0L))) || p_58));
   }
   else
   {
     int32_t
       l_1571
       [3];
     int
       i;
     for
       (i
        =
        0;
        i
        <
        3;
        i++)
       l_1571
  [i]
  =
  1L;
     if (g_329[1][2][5])
       break;
     l_1475
       =
       (l_1571
        [0]
        =
        g_774);
     if (g_978)
       continue;
     l_1438
       [8]
       [0]
       [1]
       =
       ((safe_sub_func_uint8_t_u_u (((safe_lshift_func_int16_t_s_u (((safe_sub_func_uint8_t_u_u (((g_329[1][0][0] || (g_344 = l_1488)) == p_59), (l_1578 = g_3))) > 1UL), ((!((l_1188[g_458] | (((safe_rshift_func_uint8_t_u_u (l_1583[0][6][0], 2)) ^ p_59) >= (safe_sub_func_uint32_t_u_u (p_57, 0xF62CE792L)))) && l_1571[0])) == 0xC20AL))) < l_1453), p_59)) | l_70[1][2][0]);
   }
 }
 l_1379
   [7]
   [4]
   =
   l_1586;
 l_1379
   [2]
   [3]
   =
   (((0x463CL < (safe_mod_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u ((!(safe_sub_func_int8_t_s_s (p_58, (safe_rshift_func_int8_t_s_u (l_1502[2], 0))))), (safe_mul_func_uint16_t_u_u ((safe_mul_func_uint8_t_u_u ((safe_rshift_func_uint8_t_u_s ((l_1578 != l_1423[3][1]), 4)), l_1601[1])), 65527UL)))), 0xF6L))) < ((((safe_mod_func_int8_t_s_s ((p_59 = ((safe_mod_func_int8_t_s_s (((g_588 && l_1422) >= g_201), l_1601[2])) <= p_58)), g_697[8][0])) & l_1364) < 0xA8L) || l_1384[6])) <= g_458);
      }
      for
 (l_1578
  =
  7;
  (l_1578
   >=
   0);
  l_1578
  -=
  1)
      {
 int32_t
   l_1622
   [4]
   =
   {
      (-9L),
      (-9L),
      (-9L),
      (-9L)
    };
 int
   i;
 if (p_57)
 {
   uint32_t
     l_1621
     =
     0x90FD25AAL;
   l_1379
     [1]
     [0]
     =
     g_697
     [8]
     [0];
   for
     (p_60
      =
      0;
      (p_60
       <=
       7);
      p_60
      +=
      1)
   {
     g_71
       [3]
       =
       (safe_sub_func_int32_t_s_s
        ((safe_mod_func_int16_t_s_s ((safe_mul_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_s ((((g_588 = (g_329[1][0][0] ^ (safe_mod_func_int32_t_s_s (l_1616, 4294967295UL)))) | (((safe_rshift_func_int16_t_s_s (((safe_mod_func_uint8_t_u_u (5UL, (0x7FD0L && (l_1570 < l_1621)))) >= g_978), (0x1D61L || g_1265[3][4]))) & p_59) ^ g_721[0])) || (-5L)), p_60)), l_1622[1])), p_57)), g_1281));
     if (p_58)
       continue;
     if (l_1621)
       break;
     return
       l_1250;
   }
 }
 else
 {
   uint32_t
     l_1655
     =
     4294967295UL;
   int32_t
     l_1668
     =
     0x8E80973DL;
   if ((safe_sub_func_uint16_t_u_u ((((safe_mod_func_uint8_t_u_u (g_513[1], 1UL)) != l_1341) | (safe_add_func_int16_t_s_s ((safe_add_func_int8_t_s_s ((safe_rshift_func_int16_t_s_s (((safe_mul_func_uint16_t_u_u (((((safe_mod_func_int8_t_s_s ((safe_add_func_int16_t_s_s ((safe_mul_func_uint16_t_u_u (((+(((0xBC28A63EL <= ((g_329[1][0][0] || ((safe_rshift_func_uint8_t_u_u ((g_588 = (safe_mul_func_int8_t_s_s (((safe_lshift_func_int8_t_s_u ((safe_rshift_func_uint16_t_u_s ((safe_lshift_func_int8_t_s_u ((((0xC86CL & (safe_add_func_uint16_t_u_u (((((p_60 <= 2UL) < (((safe_add_func_int8_t_s_s ((!p_57), g_513[1])) | 0x25L) < g_38)) && (-1L)) < 0x351E1285L), 65535UL))) && 3L) < g_71[7]), 2)), 11)), l_1622[1])) <= (-3L)), p_57))), 0)) != g_367)) >= 0xAF39FF41L)) >= 1L) < p_58)) & (-8L)), l_1403[1])), p_58)), 0xECL)) < g_329[1][0][0]) < (-3L)) || g_721[3]), (-1L))) != l_1655), 7)), 1L)), p_57))), 0x4FDFL)))
   {
     int32_t
       l_1660
       =
       0L;
     int32_t
       l_1661
       [9]
       [5]
       =
       {
   {0xF3EECE38L,
    6L,
    0L,
    (-10L),
    0L}
     , {(-10L), (-10L), 0xB8A18AEDL, (-8L), 4L}
     , {0x7ED8E6F0L, 0x4FFD6CFCL, 0xB8A18AEDL, 0L, 0xF3EECE38L}
     , {(-1L), 0xB8A18AEDL, 0L, 0xB8A18AEDL, (-1L)}
     , {(-8L), 0x4FFD6CFCL, 4L, (-1L), (-10L)}
     , {(-8L), (-10L), 0xF3EECE38L, 0x5F042651L, 0x5F042651L}
     , {(-1L), 6L, (-1L), 0x4FFD6CFCL, (-10L)}
     , {0x7ED8E6F0L, 0x5F042651L, (-10L), 0x4FFD6CFCL, (-1L)}
     , {(-10L), 0xF3EECE38L, 0x5F042651L, 0x5F042651L, 0xF3EECE38L}
     };
     int
       i,
       j;
     l_1668
       =
       ((l_1438[5][0][1] != (l_1622[1] = ((l_800 = (l_1661[8][1] = (safe_lshift_func_uint8_t_u_s ((safe_mod_func_uint32_t_u_u (g_930, l_1660)), 7)))) && (+l_1379[2][3])))) ^ ((safe_lshift_func_int16_t_s_u (((safe_add_func_int32_t_s_s (g_658, (g_513[1] <= ((g_697[5][1] <= (((((-3L) || (safe_lshift_func_uint8_t_u_u (g_920, p_57))) < 0x61L) && g_555) ^ p_57)) < l_1616)))) > l_1403[1]), 4)) | 0x1AL));
     l_1622
       [1]
       =
       p_58;
   }
   else
   {
     uint8_t
       l_1685
       =
       1UL;
     g_71
       [7]
       =
       9L;
     g_71
       [7]
       =
       ((p_59 || (safe_mul_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u (((((g_513[1] ^ (l_1685 = ((+((~(0xD9D52541L & (safe_add_func_int16_t_s_s (g_521, (safe_add_func_int32_t_s_s ((safe_mul_func_int16_t_s_s ((safe_mod_func_uint32_t_u_u ((((safe_sub_func_uint32_t_u_u (((0xA7L < (~(((-7L) & ((safe_rshift_func_uint8_t_u_u (((p_60 <= p_59) & l_1622[3]), 4)) && g_201)) ^ g_721[2]))) | p_58), l_1441)) < l_1379[2][3]) != 0UL), l_799)), p_57)), g_774)))))) || 0xCBC7BAA7L)) == 1UL))) <= l_1616) < 0xFCAE371CL) | p_60), p_60)), 0x22L))) | 0x96L);
   }
   if (((safe_rshift_func_int8_t_s_s (((safe_add_func_uint16_t_u_u ((g_1281 & p_57), (safe_rshift_func_int8_t_s_s (((safe_add_func_uint8_t_u_u ((((l_67 || (((safe_add_func_uint8_t_u_u (((p_60 ^ (safe_lshift_func_int8_t_s_s ((safe_add_func_uint32_t_u_u ((safe_rshift_func_uint8_t_u_s (g_329[1][0][0], (g_930 = (safe_lshift_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u (l_1431, (safe_mul_func_uint16_t_u_u (((safe_mul_func_int16_t_s_s ((safe_rshift_func_int16_t_s_u ((l_1601[2] == ((safe_add_func_int8_t_s_s (((!g_300) || ((g_555 < g_3) ^ 0x16L)), 0xDAL)) & p_59)), g_329[1][0][0])), 7UL)) ^ p_57), p_57)))), l_1622[0]))))), p_60)), p_58))) ^ l_1622[2]), l_1578)) != 3L) & 0xCC7C2B67L)) < p_59) != 0x96F0A4A3L), g_866)) > (-1L)), 1)))) < 4UL), 7)) != 0x913DE694L))
   {
     int16_t
       l_1732
       =
       0x0AABL;
     int32_t
       l_1733
       =
       1L;
     l_1733
       =
       ((safe_mod_func_int16_t_s_s ((safe_add_func_int8_t_s_s ((safe_mod_func_uint32_t_u_u ((safe_mod_func_uint16_t_u_u ((l_1379[9][0] = ((safe_mod_func_int32_t_s_s ((safe_sub_func_int16_t_s_s (0L, g_1265[2][5])), (((((0xDADA1386L != (0UL != ((g_71[3] = (safe_sub_func_int32_t_s_s (g_774, (safe_rshift_func_int16_t_s_s ((g_300 != (((g_344 = (((safe_sub_func_uint16_t_u_u (p_58, g_920)) > (p_59 || g_697[5][0])) <= g_920)) < p_57) || g_521)), 9))))) && p_60))) || g_71[7]) ^ l_1586) == l_1622[1]) & p_59))) || l_1732)), l_1622[1])), 7UL)), l_1534)), 0x2CAFL)) != 0x663D3C7BL);
   }
   else
   {
     if (p_57)
       break;
   }
 }
 g_71
   [4]
   =
   (safe_mod_func_uint16_t_u_u
    ((((p_60 & ((safe_lshift_func_int16_t_s_u ((((safe_mod_func_uint8_t_u_u (((((safe_add_func_int16_t_s_s ((g_513[1] || (safe_mul_func_int16_t_s_s ((((l_799 = (g_329[1][0][0] = (l_1744 = p_59))) < (l_1438[5][0][0] = ((p_60 > ((safe_rshift_func_uint16_t_u_s ((g_513[5] <= (safe_lshift_func_uint8_t_u_u ((g_588 = (safe_rshift_func_uint16_t_u_s (((safe_sub_func_uint8_t_u_u ((((l_800 = p_60) & (safe_mul_func_uint16_t_u_u ((safe_mul_func_int8_t_s_s ((safe_mul_func_int8_t_s_s (((p_57 == ((safe_rshift_func_uint8_t_u_u (g_38, p_57)) >= p_60)) < p_58), g_920)), p_60)), g_521))) & p_60), 0x5CL)) || 0x8BL), 2))), p_60))), 8)) | p_59)) < p_58))) ^ l_1570), 0xD07CL))), 0x282FL)) == l_1364) ^ 0xF4L) != 0x0542L), 0xA2L)) <= 1UL) | 0xE807L), 2)) & 4L)) == g_513[1]) || l_1431), g_866));
      }
    }
    for
      (g_555
       =
       4;
       (g_555
 >=
 0);
       g_555
       -=
       1)
    {
      uint8_t
 l_1779
 =
 0x2BL;
      int32_t
 l_1809
 =
 0x544162F4L;
      int32_t
 l_1836
 =
 0L;
      for
 (g_658
  =
  0;
  (g_658
   <=
   4);
  g_658
  +=
  1)
      {
 int32_t
   l_1772
   =
   (-2L);
 int32_t
   l_1780
   =
   (-8L);
 int
   i;
 for
   (l_800
    =
    0;
    (l_800
     <=
     4);
    l_800
    +=
    1)
 {
   for
     (l_1441
      =
      8;
      (l_1441
       >=
       0);
      l_1441
      -=
      1)
   {
     int32_t
       l_1781
       =
       0x3D9E8289L;
     int
       i;
     g_71
       [(g_555 + 1)] = (safe_rshift_func_uint8_t_u_s (0xF9L, 6));
     g_1763
       =
       (g_71
        [l_1441]
        =
        (l_1188
  [(l_800 + 3)] | g_71[(l_800 + 1)]));
     g_1782
       =
       (l_1781
        =
        (g_1763
  =
  (safe_add_func_uint8_t_u_u
   (250UL,
    (l_1780
     =
     (safe_mod_func_int32_t_s_s
      (((safe_lshift_func_uint16_t_u_u ((l_1438[9][0][0] = (1UL < (safe_lshift_func_uint8_t_u_u (((l_1772 = 0x601044F6L) < 0xFB6A6C17L), l_1403[1])))), 15)) <= (((3UL == ((g_71[(g_555 + 1)] = (g_588 = g_71[l_1441])) & (g_920 != ((safe_lshift_func_int8_t_s_s (((safe_mod_func_int8_t_s_s ((safe_mod_func_int16_t_s_s (g_930, g_201)), l_1779)) <= p_60), 1)) <= 0x98597F36L)))) && p_59) >= p_60)), p_60)))))));
   }
 }
 l_1780
   =
   l_1188
   [(g_555 + 1)];
 if (l_1188[(g_555 + 1)])
   continue;
      }
      for
 (l_799
  =
  1;
  (l_799
   <=
   9);
  l_799
  +=
  1)
      {
 int
   i;
 g_71
   [7]
   =
   (safe_mul_func_int16_t_s_s
    (g_721
     [(g_300 + 5)], (((l_1384[g_555] ^ (safe_sub_func_uint32_t_u_u ((safe_rshift_func_uint16_t_u_s ((safe_lshift_func_uint8_t_u_u ((safe_mod_func_uint16_t_u_u ((safe_rshift_func_int16_t_s_s ((((safe_rshift_func_uint8_t_u_s (((safe_sub_func_int16_t_s_s ((safe_add_func_int32_t_s_s (((((safe_mul_func_int8_t_s_s ((l_1809 = ((((1L == (0x264CL ^ ((g_367 > (!((l_1502[1] < (((safe_mul_func_int8_t_s_s (g_1281, ((safe_sub_func_int8_t_s_s ((-8L), (safe_add_func_uint32_t_u_u (((-1L) ^ p_59), g_697[3][1])))) < p_59))) <= 0xD3L) == g_30)) ^ 1UL))) || g_1782))) < (-1L)) & p_60) && p_59)), l_1601[2])) > p_58) > p_57) & 0x07L), l_1403[4])), p_60)) < 1L), l_1601[1])) ^ g_1810[0]) || 0x6DB63905L), 1)), g_1265[0][7])), l_1384[g_555])), 9)), 0x3ADD4C1FL))) | p_57) >= 0xFB8058A3L)));
 return
   l_67;
      }
      l_1836
 =
 ((((l_1809 = (((safe_rshift_func_uint8_t_u_u (3UL, 5)) <= (safe_add_func_int32_t_s_s ((l_800 = (p_57 ^ l_1570)), g_588))) != (safe_rshift_func_int16_t_s_u ((g_1835[0][3][2] = (safe_sub_func_uint32_t_u_u ((safe_add_func_int16_t_s_s ((~(l_799 = l_609[0])), ((safe_rshift_func_uint8_t_u_s ((l_1834 = (0L | (safe_add_func_int16_t_s_s ((safe_rshift_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u (l_1586, 1)), (0x70L != (((((l_1833 = ((((safe_mod_func_uint16_t_u_u (l_1779, p_58)) & 4294967290UL) || p_57) < l_1809)) || g_458) < l_609[0]) == l_1809) >= 0xFEBCL)))), l_1438[7][0][0])), 0xF83DL)))), 2)) | g_3))), 0x0384F0ABL))), 9)))) > g_1281) && g_721[4]) <= g_555);
    }
    if (l_1837)
      continue;
    l_1441
      =
      (safe_add_func_int32_t_s_s
       ((safe_lshift_func_int16_t_s_s ((-8L), 11)), ((!(((l_1438[4][0][0] | ((safe_mul_func_uint8_t_u_u (0xA2L, l_1586)) || (((0xAA39DF63L >= (safe_mod_func_int32_t_s_s (0L, g_555))) > (g_1835[0][3][2] = ((((g_930 < ((-5L) && p_60)) > 7UL) == g_1810[0]) >= l_1005))) != p_58))) > l_1384[4]) >= g_329[1][0][0])) >= (-1L))));
    for
      (l_1250
       =
       2;
       (l_1250
 <=
 7);
       l_1250
       +=
       1)
    {
      uint32_t
 l_1852
 [6]
 [8]
 =
 {
   {0x581A6F4DL,
    1UL,
    1UL,
    0x581A6F4DL,
    0UL,
    4UL,
    0UL,
    4294967291UL}
      , {0UL, 0x492D247CL, 0x36109862L, 1UL, 4UL, 1UL, 0xFE55C8BFL, 1UL}
      , {1UL, 0x492D247CL, 0xBCE9244FL, 0x10EA97E1L, 0x36109862L, 4UL, 0x36109862L, 0x10EA97E1L}
      , {0xAE0CAB6DL, 1UL, 0xAE0CAB6DL, 0x6E6D3266L, 0xCD5D87ACL, 0x10EA97E1L, 0x581A6F4DL, 0x36109862L}
      , {0UL, 0x36109862L, 0UL, 4294967295UL, 1UL, 8UL, 0xCD5D87ACL, 0x492D247CL}
      , {0UL, 0xBCE9244FL, 8UL, 0x66C191B3L, 0xCD5D87ACL, 0xCD5D87ACL, 0x66C191B3L, 8UL}
      };
      int32_t
 l_1874
 [3];
      int8_t
 l_1988
 =
 1L;
      int
 i,
        j;
      for
 (i
  =
  0;
  i
  <
  3;
  i++)
 l_1874
   [i]
   =
   0x494C9DE3L;
      for
 (p_58
  =
  1;
  (p_58
   <=
   7);
  p_58
  +=
  1)
      {
 uint16_t
   l_1851
   =
   0xC774L;
 int32_t
   l_1885
   =
   (-1L);
 int32_t
   l_1931
   =
   0xC09AA10AL;
 int32_t
   l_1998
   =
   0x8EBFCBCBL;
 if ((g_1763 = (((safe_lshift_func_int16_t_s_s ((p_59 && 253UL), g_458)) < p_59) ^ p_59)))
 {
   uint8_t
     l_1850
     [6]
     =
     {
 3UL,
 3UL,
 0x2CL,
 3UL,
 3UL,
 0x2CL
      };
   int32_t
     l_1887
     =
     0xFE3DFA66L;
   int
     i;
   for
     (g_555
      =
      1;
      (g_555
       <=
       7);
      g_555
      +=
      1)
   {
     int
       i;
     l_1850
       [0]
       =
       (~
        (safe_add_func_int32_t_s_s
  (g_721
   [(l_1250 + 1)], 4294967291UL)));
     l_1833
       =
       (l_1851
        =
        g_1265
        [2]
        [3]);
     l_1852
       [5]
       [7]
       =
       (g_920
        &
        0UL);
   }
   if (p_59)
   {
     int8_t
       l_1875
       =
       0xCBL;
     int32_t
       l_1876
       =
       7L;
     l_1876
       =
       (safe_mul_func_int16_t_s_s
        ((safe_add_func_int16_t_s_s ((safe_rshift_func_uint8_t_u_u (((p_57 ^ ((safe_sub_func_int8_t_s_s ((g_930 = ((l_1850[4] || (safe_rshift_func_uint16_t_u_s (p_57, 8))) & ((p_57 || ((safe_rshift_func_uint16_t_u_s ((l_1341 ^ (safe_lshift_func_int16_t_s_u (p_60, g_458))), ((safe_unary_minus_func_uint8_t_u ((safe_mod_func_int8_t_s_s ((p_59 = (safe_mul_func_uint8_t_u_u (((safe_lshift_func_uint8_t_u_s ((0x1DC9L != ((l_1874[1] = (p_58 >= p_60)) || p_60)), g_1763)) > p_58), 0x59L))), p_58)))) > l_1875))) >= g_300)) == l_1850[0]))), p_60)) & l_1341)) > l_1850[0]), l_1852[5][7])), g_300)), p_60));
     return
       g_300;
   }
   else
   {
     uint16_t
       l_1886
       =
       0xA075L;
     l_1885
       =
       (g_1835
        [0]
        [4]
        [1]
        |
        ((safe_add_func_int8_t_s_s (g_1382, l_67)) > (g_521 = ((safe_mul_func_int8_t_s_s (((safe_lshift_func_int8_t_s_s ((safe_lshift_func_int8_t_s_u (g_774, 4)), 5)) <= (p_58 > g_658)), g_329[1][0][0])) ^ 0x231BL))));
     l_1886
       =
       p_59;
     l_1887
       =
       p_60;
   }
   if ((safe_sub_func_uint32_t_u_u (((safe_add_func_int32_t_s_s (0x0C94DF4DL, ((g_71[8] <= 0x2A2FD7B7L) > (((safe_mod_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u (p_58, (p_58 || g_1281))), l_1441)) == (p_60 <= (safe_lshift_func_uint16_t_u_s (((((safe_rshift_func_uint16_t_u_s (((safe_mul_func_int16_t_s_s ((safe_mul_func_uint8_t_u_u ((l_1438[5][0][1] = 9UL), l_609[0])), l_1502[1])) | l_1885), l_1887)) && 0L) <= g_866) ^ 0x1EL), 2)))) > 0x16DAL)))) | g_930), 0x0FE39029L)))
   {
     uint16_t
       l_1910
       =
       65535UL;
     l_1874
       [0]
       =
       l_1852
       [3]
       [0];
     l_1887
       =
       (l_799
        =
        (g_71
  [4]
  =
  ((safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint8_t_u_u ((safe_lshift_func_uint16_t_u_u (1UL, 8)), 4)), l_1887)) > p_57)));
     return
       l_1910;
   }
   else
   {
     uint16_t
       l_1930
       =
       0x5864L;
     g_1917
       =
       (p_60
        >
        (safe_sub_func_uint8_t_u_u
  ((g_588 = 0xB1L), (safe_mul_func_int8_t_s_s (1L, ((g_344 = (safe_mod_func_int8_t_s_s (g_71[8], 255UL))) <= 0x12L))))));
     l_1931
       =
       (((g_201 ^ 0x44L) | (safe_sub_func_int8_t_s_s ((safe_lshift_func_uint16_t_u_s ((safe_mod_func_uint32_t_u_u (((safe_lshift_func_int16_t_s_u ((((safe_rshift_func_int16_t_s_s ((l_1887 = (g_521 & (l_1885 = ((safe_rshift_func_int8_t_s_u (g_658, (g_1917 = 8UL))) < (p_60 < l_1930))))), 5)) ^ 0x95167045L) || (p_58 != p_57)), 2)) < 0x093B234CL), 8L)), p_58)), 0xA0L))) ^ 0x0BL);
   }
 }
 else
 {
   int16_t
     l_1956
     =
     2L;
   if ((g_1782 = ((0x45L || ((safe_sub_func_uint16_t_u_u ((safe_mod_func_int32_t_s_s ((p_57 < ((safe_mul_func_int8_t_s_s ((!g_1810[0]), p_60)) > ((safe_lshift_func_int8_t_s_s ((safe_unary_minus_func_int16_t_s ((((((((0x47AAL > (l_1931 = (l_800 = ((safe_mul_func_int8_t_s_s (l_1851, g_721[8])) > (l_1438[5][0][1] = g_721[3]))))) == l_1851) && g_774) | p_57) && p_59) && p_57) || p_59))), p_58)) != g_38))), 0x3FBAB0A6L)), 2L)) || 0x35047D49L)) >= g_555)))
   {
     uint32_t
       l_1969
       =
       7UL;
     l_1969
       =
       ((l_1403[1] = ((safe_add_func_int8_t_s_s ((safe_lshift_func_int8_t_s_u ((safe_sub_func_uint32_t_u_u ((safe_add_func_uint32_t_u_u ((g_38 | (safe_rshift_func_int16_t_s_u (((safe_unary_minus_func_int16_t_s ((safe_add_func_uint8_t_u_u (((-6L) ^ ((l_1438[3][0][1] = (((p_59 > (0xCEL <= 7UL)) && l_1956) > (safe_mul_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (65527UL, (g_555 = ((safe_rshift_func_int16_t_s_u ((safe_sub_func_uint32_t_u_u ((safe_add_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (g_1266, ((p_57 || p_58) && 1UL))), l_1885)), g_721[3])), g_721[3])) > 65535UL)))), p_59)))) > l_1834)), g_920)))) ^ (-6L)), g_721[3]))), p_60)), l_1341)), 5)), g_920)) ^ p_59)) ^ (-1L));
   }
   else
   {
     uint16_t
       l_1987
       =
       0xDE63L;
     g_1782
       =
       (safe_rshift_func_uint8_t_u_u
        (((safe_rshift_func_uint16_t_u_s ((safe_lshift_func_uint8_t_u_u ((safe_mul_func_int16_t_s_s ((g_521 = (((((((safe_lshift_func_uint8_t_u_u (g_1810[0], (l_1885 = (g_1917 = 0x68L)))) != l_1931) ^ (safe_rshift_func_uint8_t_u_s ((g_300 < ((((safe_rshift_func_uint16_t_u_s ((((safe_add_func_int32_t_s_s (g_1382, (0x6C6CE11BL && (g_71[6] = l_1851)))) ^ (0UL == (safe_unary_minus_func_uint16_t_u (1UL)))) < l_1852[5][7]), p_59)) | l_1987) == p_57) >= 0x3D2E901BL)), l_1403[1]))) == l_1987) == l_1956) != 0xB9A4CA4FL) && 0x32072BDCL)), p_59)), p_59)), l_1987)) < l_1988), 1));
   }
 }
 l_1931
   =
   (safe_rshift_func_uint8_t_u_u
    (((((safe_add_func_int8_t_s_s ((safe_mul_func_int8_t_s_s ((p_58 == ((g_1995 && (safe_rshift_func_int16_t_s_u ((0UL == (((l_1998 = l_1874[2]) == ((((safe_rshift_func_int16_t_s_s ((((g_344 = (((((p_59 = ((0x2FL | (l_1874[1] || (g_513[1] | l_1851))) > ((safe_rshift_func_int16_t_s_s ((l_1885 < l_1885), 13)) != l_2003))) >= (-1L)) != g_721[3]) ^ p_57) & g_1763)) && p_57) == l_1834), g_367)) > 0L) || p_57) ^ g_201)) | l_1250)), p_57))) || 65535UL)), p_58)), g_1810[0])) && g_588) ^ g_2004[0][0][2]) >= p_57), p_58));
      }
      g_1763
 =
 (g_71
  [1]
  =
  (safe_sub_func_uint8_t_u_u
   ((g_367 < 0x72D05B16L), (g_344 = (((l_800 = ((safe_mul_func_uint16_t_u_u ((l_609[0] = ((safe_add_func_int16_t_s_s ((0xF771L ^ (p_58 = ((safe_sub_func_int32_t_s_s ((p_59 | (safe_mul_func_uint16_t_u_u (((l_1833 = ((0L & p_57) & p_59)) & ((g_513[1] = (safe_add_func_uint16_t_u_u (l_1852[5][7], p_59))) < (-1L))), 0x8011L))), l_1570)) && l_1384[4]))), 0x3F64L)) | p_59)), l_1852[5][7])) != p_57)) | l_1874[1]) & l_1988)))));
    }
  }
}
    for
      (l_1341
       =
       0;
       (l_1341
 <=
 4);
       l_1341
       +=
       1)
    {
      uint16_t
 l_1364
 =
 65535UL;
      int32_t
 l_1379
 [10]
 [7]
 =
 {
    {0x64CD1FA4L,
     9L,
     0x6F22B797L,
     9L,
     0x64CD1FA4L,
     (-1L),
     0x6F22B797L}
      , {0x4AF1F542L, 0xDD5DAFA3L, 0L, 0L, 0xDD5DAFA3L, 0x4AF1F542L, 0xF78852C5L}
      , {0L, 1L, 8L, (-1L), 8L, 1L, 0L}
      , {0x4AF1F542L, 0L, 0xF78852C5L, 0xE476DB24L, 0xE476DB24L, 0xF78852C5L, 0L}
      , {0x64CD1FA4L, 1L, 4L, 0x349346A9L, 0x64CD1FA4L, 0x349346A9L, 4L}
      , {0xE476DB24L, 0xDD5DAFA3L, 0xF78852C5L, 6L, 0x4AF1F542L, 0x4AF1F542L, 6L}
      , {8L, 9L, 8L, 0x349346A9L, 0L, 9L, 0L}
      , {0xDD5DAFA3L, 6L, 0L, 0xE476DB24L, 0x4AF1F542L, (-1L), (-1L)}
      , {0x64CD1FA4L, (-1L), 0x6F22B797L, (-1L), 0x64CD1FA4L, 9L, 0x6F22B797L}
      , {(-6L), 0xDD5DAFA3L, 6L, 0L, 0xE476DB24L, 0x4AF1F542L, (-1L)}
      };
      uint32_t
 l_1431
 =
 4294967293UL;
      int32_t
 l_1578
 =
 0xF5ADD8F0L;
      uint8_t
 l_1616
 =
 0UL;
      int
 i,
        j;
      for
 (g_458
  =
  0;
  (g_458
   <=
   7);
  g_458
  +=
  1)
      {
 int32_t
   l_1383
   =
   0xCC80471DL;
 int32_t
   l_1422
   =
   0L;
 int32_t
   l_1423
   [9]
   [4]
   =
   {
      {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0x0542477FL}
 , {0x7D6DFEFEL, (-1L), 0xB7D78E3EL, (-1L)}
 , {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0xB7D78E3EL}
 };
 int32_t
   l_1444
   =
   0xE4F95524L;
 uint32_t
   l_1470
   =
   0x087273C0L;
 int32_t
   l_1475
   =
   3L;
 int16_t
   l_1488
   =
   (-6L);
 int32_t
   l_1497
   =
   0xD570C473L;
 int
   i,
   j;
{
 int32_t
   l_1383
   =
   0xCC80471DL;
 int32_t
   l_1422
   =
   0L;
 int32_t
   l_1423
   [9]
   [4]
   =
   {
      {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0x0542477FL}
 , {0x7D6DFEFEL, (-1L), 0xB7D78E3EL, (-1L)}
 , {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0xB7D78E3EL}
 };
 int32_t
   l_1444
   =
   0xE4F95524L;
 uint32_t
   l_1470
   =
   0x087273C0L;
 int32_t
   l_1475
   =
   3L;
 int16_t
   l_1488
   =
   (-6L);
 int32_t
   l_1497
   =
   0xD570C473L;
 int
   i,
   j;
 l_1364
   =
   l_1188
   [g_458];
 if ((g_71[1] = (safe_mul_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u (p_59, (g_774 = (((safe_add_func_uint8_t_u_u (l_1364, ((safe_lshift_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((-1L) | (safe_sub_func_uint32_t_u_u (((!((-1L) <= ((1L || ((l_1379[2][3] = (l_1188[g_458] == (0x10L & g_30))) < (~(safe_lshift_func_uint16_t_u_s ((p_58 = (((l_1383 = (((0x2EL && g_71[2]) == g_1382) > l_1364)) || g_930) != l_1188[g_458])), 12))))) & (-2L)))) | l_1188[g_458]), g_344))) | g_721[3]), 249UL)) != g_1266), 11)) < 0UL))) ^ 9UL) ^ l_1384[4])))), 0xC5F3L))))
 {
   int32_t
     l_1440
     =
     0L;
   int32_t
     l_1454
     =
     1L;
   int32_t
     l_1457
     [1];
   int
     i;
   for
     (i
      =
      0;
      i
      <
      1;
      i++)
     l_1457
       [i]
       =
       0xC6483828L;
   for
     (g_521
      =
      1;
      (g_521
       <=
       4);
      g_521
      +=
      1)
   {
     uint8_t
       l_1402
       =
       255UL;
     int32_t
       l_1424
       =
       5L;
     g_71
       [3]
       =
       (l_1383
        =
        l_1383);
     l_1403
       [1]
       =
       ((safe_mod_func_int32_t_s_s ((safe_rshift_func_int8_t_s_s ((safe_sub_func_uint8_t_u_u (g_367, g_3)), (safe_sub_func_int8_t_s_s ((g_930 = g_978), (safe_add_func_uint8_t_u_u (g_367, g_1266)))))), (safe_unary_minus_func_int32_t_s ((l_609[0] = (0x39L || (safe_rshift_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u (((safe_sub_func_int8_t_s_s (l_1379[2][3], (l_1402 = ((g_300 && p_59) == g_344)))) || 0x5D37L), p_59)), p_58)))))))) == g_344);
     l_1424
       =
       ((safe_add_func_uint16_t_u_u (((l_1423[3][1] = (l_1383 = (l_1379[2][3] = ((((safe_lshift_func_int16_t_s_u (((safe_add_func_int8_t_s_s (((((g_555 = g_201) == (safe_sub_func_uint8_t_u_u ((p_57 & p_60), (+(safe_add_func_uint16_t_u_u (((!65531UL) == (l_1402 && (l_1379[1][6] <= ((safe_mul_func_int16_t_s_s (p_59, 0x6A1EL)) ^ (safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u (((safe_sub_func_int32_t_s_s ((g_3 ^ 7UL), 9L)) == p_59), 4294967295UL)), g_930)))))), l_1384[4])))))) < l_1422) != p_57), l_1402)) ^ l_1422), g_367)) && g_1265[2][5]) > g_71[5]) >= 7L)))) & 0L), l_1364)) <= p_59);
     return
       l_1379
       [7]
       [5];
   }
   for
     (p_59
      =
      0;
      (p_59
       <=
       7);
      p_59
      +=
      1)
   {
     uint32_t
       l_1439
       =
       0x7C99E9CAL;
     l_1379
       [2]
       [3]
       =
       g_513
       [1];
     l_799
       =
       g_697
       [8]
       [0];
     l_1441
       =
       (safe_add_func_int32_t_s_s
        ((l_1440 = (safe_mod_func_int32_t_s_s ((((safe_mod_func_int16_t_s_s (l_1431, g_697[7][1])) ^ (safe_add_func_int16_t_s_s ((safe_sub_func_int32_t_s_s (g_1281, (safe_rshift_func_uint8_t_u_u (((g_513[3] & (l_1438[5][0][1] = (g_344 ^ (l_1403[9] = 0xB097F462L)))) == (0UL | (-1L))), 3)))), (l_1384[4] == p_58)))) < l_1439), l_1423[3][1]))), g_458));
   }
   l_1383
     =
     ((l_1457[0] = ((l_1444 = (safe_rshift_func_uint8_t_u_u ((l_1438[5][0][1] = l_1383), 2))) & (l_1379[2][3] = (l_1250 || ((0L <= (((safe_mul_func_uint16_t_u_u ((g_774 = (g_1265[2][5] || l_1440)), (!(l_1423[3][1] = (safe_mod_func_int16_t_s_s ((safe_add_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s (g_30, l_1453)), (l_1454 = 1L))), ((safe_sub_func_int16_t_s_s ((g_697[5][0] = p_57), 4UL)) ^ l_1441))))))) < g_71[3]) ^ l_1379[8][1])) < 1UL))))) ^ l_1403[0]);
 }
 else
 {
   uint32_t
     l_1468
     [4];
   int32_t
     l_1469
     =
     (-1L);
   int32_t
     l_1583
     [1]
     [9]
     [1]
     =
     {
 {{0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  }
   };
   int
     i,
     j,
     k;
   for
     (i
      =
      0;
      i
      <
      4;
      i++)
     l_1468
       [i]
       =
       0UL;
   l_1423
     [3]
     [1]
     =
     ((l_1441 = p_60) > (safe_add_func_int8_t_s_s ((g_344 = (safe_add_func_uint16_t_u_u (0UL, ((6UL || (l_1383 > p_58)) == (((safe_mul_func_uint8_t_u_u (g_866, 0x91L)) != ((safe_add_func_int8_t_s_s ((safe_sub_func_uint16_t_u_u ((l_1468[0] = (p_60 | p_60)), l_1469)), 0xBEL)) || g_1266)) < p_58))))), 0L)));
   if ((l_1470 & (safe_sub_func_int32_t_s_s (((((safe_sub_func_uint8_t_u_u (l_1475, l_609[0])) == p_59) ^ (safe_lshift_func_int16_t_s_u ((((safe_sub_func_int16_t_s_s ((safe_mod_func_int32_t_s_s (((g_555 = (0x0B1DL == p_60)) && g_71[7]), (safe_mul_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u ((g_344 = (p_60 != ((+(((safe_lshift_func_uint16_t_u_s (0xB105L, p_57)) >= p_57) < g_71[7])) && l_1441))), 2)), g_588)))), g_1281)) || g_697[8][0]) ^ p_59), g_920))) || l_1488), g_521))))
   {
     int8_t
       l_1503
       =
       0xE6L;
     l_1383
       =
       (safe_mul_func_uint8_t_u_u
        (p_60,
  p_57));
     l_1423
       [3]
       [1]
       =
       (+
        (!
  (safe_rshift_func_uint8_t_u_s
   (l_1468
    [0],
    ((g_513[2] < p_59) <= (safe_mul_func_int16_t_s_s (9L, (0x8FL < (l_1469 = (safe_sub_func_uint16_t_u_u (l_1497, ((safe_sub_func_int16_t_s_s ((g_697[8][0] = p_58), (g_521 = (-7L)))) != (safe_lshift_func_int16_t_s_u ((l_1502[1] & 8L), l_1502[1]))))))))))))));
     g_71
       [6]
       =
       (l_1503
        =
        g_588);
     if (g_697[8][0])
       break;
   }
   else
   {
     int32_t
       l_1524
       =
       0x6DC5B83AL;
     l_1441
       =
       l_1468
       [0];
     l_1469
       =
       ((p_58 = (safe_add_func_int32_t_s_s (((((((safe_mod_func_int8_t_s_s (((safe_lshift_func_uint8_t_u_u ((0x3CE0A1BCL < l_1188[7]), (safe_add_func_int8_t_s_s ((0x37L >= (((safe_add_func_int16_t_s_s ((+(!((safe_rshift_func_int16_t_s_u (((safe_sub_func_int16_t_s_s ((l_800 = ((safe_add_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_s ((l_609[0] | ((safe_lshift_func_uint16_t_u_s (l_1384[4], g_201)) | 0x06C8L)), 0)), 255UL)) || (((0x0530L == g_329[1][0][0]) >= 1UL) ^ g_1281))), g_721[5])) && 255UL), p_60)) < l_1524))), l_1438[1][0][1])) > l_1469) || p_59)), p_59)))) <= p_60), 0x7FL)) & g_721[3]) <= g_329[1][4][2]) == (-9L)) | p_58) & g_1266), l_1379[6][0]))) & p_57);
     if (g_458)
       continue;
     g_71
       [7]
       =
       g_978;
   }
   if ((safe_sub_func_uint32_t_u_u (p_57, ((g_329[1][0][0] = 1UL) > 0x4F799D86L))))
   {
     uint32_t
       l_1527
       =
       0x90FEEB0CL;
     g_71
       [7]
       =
       l_1527;
     l_1438
       [5]
       [0]
       [1]
       =
       (p_59
        >=
        (safe_mod_func_uint16_t_u_u
  (((safe_add_func_uint32_t_u_u (((safe_add_func_int16_t_s_s (l_1534, (g_555 >= (safe_rshift_func_uint8_t_u_u ((((l_1379[3][3] = (g_920 = ((l_1469 = (p_59 > (safe_rshift_func_uint16_t_u_s (((g_697[8][0] = (l_1423[0][1] < p_58)) ^ (safe_sub_func_uint32_t_u_u (0xC6944EA8L, 0x231AE895L))), (safe_mul_func_int16_t_s_s (((g_1266 = (safe_mul_func_uint16_t_u_u (0x4B84L, p_58))) == l_1468[1]), 0x7211L)))))) || l_1453))) > p_57) ^ g_669), l_1431))))) == p_60), 0UL)) ^ l_1384[4]), 0xEAF0L)));
     g_71
       [2]
       =
       ((p_57 <= ((safe_sub_func_int16_t_s_s ((l_1379[1][5] = 0x41B3L), (((0x44B3AF87L | g_30) && l_1431) == g_1382))) ^ (l_799 = (safe_sub_func_int16_t_s_s (g_721[3], ((0x8FL ^ p_60) == g_344)))))) || g_367);
     l_800
       =
       (g_71
        [7]
        =
        ((l_609[0] = (g_329[0][0][1] = ((safe_sub_func_int32_t_s_s ((safe_unary_minus_func_uint8_t_u (((safe_mul_func_int16_t_s_s (((safe_sub_func_int16_t_s_s (g_38, (l_1527 > ((safe_mod_func_int8_t_s_s ((g_344 = p_58), (safe_add_func_uint32_t_u_u (p_57, l_1527)))) >= 0xD928L)))) < ((safe_unary_minus_func_uint32_t_u ((safe_mod_func_uint8_t_u_u ((safe_mod_func_uint16_t_u_u (((~((((safe_unary_minus_func_uint16_t_u (l_1527)) > (~l_70[1][5][0])) || (safe_lshift_func_int8_t_s_s (((((((safe_add_func_uint32_t_u_u (((g_1266 < (-1L)) || p_59), 0xA3200367L)) > p_59) <= l_1364) & l_1527) != 0x2212L) && g_513[2]), l_1379[2][3]))) <= p_58)) <= p_58), g_329[0][6][2])), p_58)))) ^ l_1570)), p_57)) > l_1438[9][0][1]))), 0x19F76790L)) != 0L))) || p_58));
   }
   else
   {
     int32_t
       l_1571
       [3];
     int
       i;
     for
       (i
        =
        0;
        i
        <
        3;
        i++)
       l_1571
  [i]
  =
  1L;
     if (g_329[1][2][5])
       break;
     l_1475
       =
       (l_1571
        [0]
        =
        g_774);
     if (g_978)
       continue;
     l_1438
       [8]
       [0]
       [1]
       =
       ((safe_sub_func_uint8_t_u_u (((safe_lshift_func_int16_t_s_u (((safe_sub_func_uint8_t_u_u (((g_329[1][0][0] || (g_344 = l_1488)) == p_59), (l_1578 = g_3))) > 1UL), ((!((l_1188[g_458] | (((safe_rshift_func_uint8_t_u_u (l_1583[0][6][0], 2)) ^ p_59) >= (safe_sub_func_uint32_t_u_u (p_57, 0xF62CE792L)))) && l_1571[0])) == 0xC20AL))) < l_1453), p_59)) | l_70[1][2][0]);
   }
 }
 l_1379
   [7]
   [4]
   =
   l_1586;
 l_1379
   [2]
   [3]
   =
   (((0x463CL < (safe_mod_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u ((!(safe_sub_func_int8_t_s_s (p_58, (safe_rshift_func_int8_t_s_u (l_1502[2], 0))))), (safe_mul_func_uint16_t_u_u ((safe_mul_func_uint8_t_u_u ((safe_rshift_func_uint8_t_u_s ((l_1578 != l_1423[3][1]), 4)), l_1601[1])), 65527UL)))), 0xF6L))) < ((((safe_mod_func_int8_t_s_s ((p_59 = ((safe_mod_func_int8_t_s_s (((g_588 && l_1422) >= g_201), l_1601[2])) <= p_58)), g_697[8][0])) & l_1364) < 0xA8L) || l_1384[6])) <= g_458);
      }
 if ((g_71[1] = (safe_mul_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u (p_59, (g_774 = (((safe_add_func_uint8_t_u_u (l_1364, ((safe_lshift_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((-1L) | (safe_sub_func_uint32_t_u_u (((!((-1L) <= ((1L || ((l_1379[2][3] = (l_1188[g_458] == (0x10L & g_30))) < (~(safe_lshift_func_uint16_t_u_s ((p_58 = (((l_1383 = (((0x2EL && g_71[2]) == g_1382) > l_1364)) || g_930) != l_1188[g_458])), 12))))) & (-2L)))) | l_1188[g_458]), g_344))) | g_721[3]), 249UL)) != g_1266), 11)) < 0UL))) ^ 9UL) ^ l_1384[4])))), 0xC5F3L))))
 {
   int32_t
     l_1440
     =
     0L;
   int32_t
     l_1454
     =
     1L;
   int32_t
     l_1457
     [1];
   int
     i;
   for
     (i
      =
      0;
      i
      <
      1;
      i++)
     {
l_1457
       [i]
       =
       0xC6483828L;
for
    (i
     =
     0;
     i
     <
     1;
     i++)
    l_609
      [i]
      =
      (-3L);
}
{
 int32_t
   l_1383
   =
   0xCC80471DL;
 int32_t
   l_1422
   =
   0L;
 int32_t
   l_1423
   [9]
   [4]
   =
   {
      {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0x0542477FL}
 , {0x7D6DFEFEL, (-1L), 0xB7D78E3EL, (-1L)}
 , {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0xB7D78E3EL}
 };
 int32_t
   l_1444
   =
   0xE4F95524L;
 uint32_t
   l_1470
   =
   0x087273C0L;
 int32_t
   l_1475
   =
   3L;
 int16_t
   l_1488
   =
   (-6L);
 int32_t
   l_1497
   =
   0xD570C473L;
 int
   i,
   j;
 l_1364
   =
   l_1188
   [g_458];
 if ((g_71[1] = (safe_mul_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u (p_59, (g_774 = (((safe_add_func_uint8_t_u_u (l_1364, ((safe_lshift_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((-1L) | (safe_sub_func_uint32_t_u_u (((!((-1L) <= ((1L || ((l_1379[2][3] = (l_1188[g_458] == (0x10L & g_30))) < (~(safe_lshift_func_uint16_t_u_s ((p_58 = (((l_1383 = (((0x2EL && g_71[2]) == g_1382) > l_1364)) || g_930) != l_1188[g_458])), 12))))) & (-2L)))) | l_1188[g_458]), g_344))) | g_721[3]), 249UL)) != g_1266), 11)) < 0UL))) ^ 9UL) ^ l_1384[4])))), 0xC5F3L))))
 {
   int32_t
     l_1440
     =
     0L;
   int32_t
     l_1454
     =
     1L;
   int32_t
     l_1457
     [1];
   int
     i;
   for
     (i
      =
      0;
      i
      <
      1;
      i++)
     l_1457
       [i]
       =
       0xC6483828L;
   for
     (g_521
      =
      1;
      (g_521
       <=
       4);
      g_521
      +=
      1)
   {
     uint8_t
       l_1402
       =
       255UL;
     int32_t
       l_1424
       =
       5L;
     g_71
       [3]
       =
       (l_1383
        =
        l_1383);
     l_1403
       [1]
       =
       ((safe_mod_func_int32_t_s_s ((safe_rshift_func_int8_t_s_s ((safe_sub_func_uint8_t_u_u (g_367, g_3)), (safe_sub_func_int8_t_s_s ((g_930 = g_978), (safe_add_func_uint8_t_u_u (g_367, g_1266)))))), (safe_unary_minus_func_int32_t_s ((l_609[0] = (0x39L || (safe_rshift_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u (((safe_sub_func_int8_t_s_s (l_1379[2][3], (l_1402 = ((g_300 && p_59) == g_344)))) || 0x5D37L), p_59)), p_58)))))))) == g_344);
     l_1424
       =
       ((safe_add_func_uint16_t_u_u (((l_1423[3][1] = (l_1383 = (l_1379[2][3] = ((((safe_lshift_func_int16_t_s_u (((safe_add_func_int8_t_s_s (((((g_555 = g_201) == (safe_sub_func_uint8_t_u_u ((p_57 & p_60), (+(safe_add_func_uint16_t_u_u (((!65531UL) == (l_1402 && (l_1379[1][6] <= ((safe_mul_func_int16_t_s_s (p_59, 0x6A1EL)) ^ (safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u (((safe_sub_func_int32_t_s_s ((g_3 ^ 7UL), 9L)) == p_59), 4294967295UL)), g_930)))))), l_1384[4])))))) < l_1422) != p_57), l_1402)) ^ l_1422), g_367)) && g_1265[2][5]) > g_71[5]) >= 7L)))) & 0L), l_1364)) <= p_59);
     return
       l_1379
       [7]
       [5];
   }
   for
     (p_59
      =
      0;
      (p_59
       <=
       7);
      p_59
      +=
      1)
   {
     uint32_t
       l_1439
       =
       0x7C99E9CAL;
     l_1379
       [2]
       [3]
       =
       g_513
       [1];
     l_799
       =
       g_697
       [8]
       [0];
     l_1441
       =
       (safe_add_func_int32_t_s_s
        ((l_1440 = (safe_mod_func_int32_t_s_s ((((safe_mod_func_int16_t_s_s (l_1431, g_697[7][1])) ^ (safe_add_func_int16_t_s_s ((safe_sub_func_int32_t_s_s (g_1281, (safe_rshift_func_uint8_t_u_u (((g_513[3] & (l_1438[5][0][1] = (g_344 ^ (l_1403[9] = 0xB097F462L)))) == (0UL | (-1L))), 3)))), (l_1384[4] == p_58)))) < l_1439), l_1423[3][1]))), g_458));
   }
   l_1383
     =
     ((l_1457[0] = ((l_1444 = (safe_rshift_func_uint8_t_u_u ((l_1438[5][0][1] = l_1383), 2))) & (l_1379[2][3] = (l_1250 || ((0L <= (((safe_mul_func_uint16_t_u_u ((g_774 = (g_1265[2][5] || l_1440)), (!(l_1423[3][1] = (safe_mod_func_int16_t_s_s ((safe_add_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s (g_30, l_1453)), (l_1454 = 1L))), ((safe_sub_func_int16_t_s_s ((g_697[5][0] = p_57), 4UL)) ^ l_1441))))))) < g_71[3]) ^ l_1379[8][1])) < 1UL))))) ^ l_1403[0]);
 }
 else
 {
   uint32_t
     l_1468
     [4];
   int32_t
     l_1469
     =
     (-1L);
   int32_t
     l_1583
     [1]
     [9]
     [1]
     =
     {
 {{0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  }
   };
   int
     i,
     j,
     k;
   for
     (i
      =
      0;
      i
      <
      4;
      i++)
     l_1468
       [i]
       =
       0UL;
   l_1423
     [3]
     [1]
     =
     ((l_1441 = p_60) > (safe_add_func_int8_t_s_s ((g_344 = (safe_add_func_uint16_t_u_u (0UL, ((6UL || (l_1383 > p_58)) == (((safe_mul_func_uint8_t_u_u (g_866, 0x91L)) != ((safe_add_func_int8_t_s_s ((safe_sub_func_uint16_t_u_u ((l_1468[0] = (p_60 | p_60)), l_1469)), 0xBEL)) || g_1266)) < p_58))))), 0L)));
   if ((l_1470 & (safe_sub_func_int32_t_s_s (((((safe_sub_func_uint8_t_u_u (l_1475, l_609[0])) == p_59) ^ (safe_lshift_func_int16_t_s_u ((((safe_sub_func_int16_t_s_s ((safe_mod_func_int32_t_s_s (((g_555 = (0x0B1DL == p_60)) && g_71[7]), (safe_mul_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u ((g_344 = (p_60 != ((+(((safe_lshift_func_uint16_t_u_s (0xB105L, p_57)) >= p_57) < g_71[7])) && l_1441))), 2)), g_588)))), g_1281)) || g_697[8][0]) ^ p_59), g_920))) || l_1488), g_521))))
   {
     int8_t
       l_1503
       =
       0xE6L;
     l_1383
       =
       (safe_mul_func_uint8_t_u_u
        (p_60,
  p_57));
     l_1423
       [3]
       [1]
       =
       (+
        (!
  (safe_rshift_func_uint8_t_u_s
   (l_1468
    [0],
    ((g_513[2] < p_59) <= (safe_mul_func_int16_t_s_s (9L, (0x8FL < (l_1469 = (safe_sub_func_uint16_t_u_u (l_1497, ((safe_sub_func_int16_t_s_s ((g_697[8][0] = p_58), (g_521 = (-7L)))) != (safe_lshift_func_int16_t_s_u ((l_1502[1] & 8L), l_1502[1]))))))))))))));
     g_71
       [6]
       =
       (l_1503
        =
        g_588);
     if (g_697[8][0])
       break;
   }
   else
   {
     int32_t
       l_1524
       =
       0x6DC5B83AL;
     l_1441
       =
       l_1468
       [0];
     l_1469
       =
       ((p_58 = (safe_add_func_int32_t_s_s (((((((safe_mod_func_int8_t_s_s (((safe_lshift_func_uint8_t_u_u ((0x3CE0A1BCL < l_1188[7]), (safe_add_func_int8_t_s_s ((0x37L >= (((safe_add_func_int16_t_s_s ((+(!((safe_rshift_func_int16_t_s_u (((safe_sub_func_int16_t_s_s ((l_800 = ((safe_add_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_s ((l_609[0] | ((safe_lshift_func_uint16_t_u_s (l_1384[4], g_201)) | 0x06C8L)), 0)), 255UL)) || (((0x0530L == g_329[1][0][0]) >= 1UL) ^ g_1281))), g_721[5])) && 255UL), p_60)) < l_1524))), l_1438[1][0][1])) > l_1469) || p_59)), p_59)))) <= p_60), 0x7FL)) & g_721[3]) <= g_329[1][4][2]) == (-9L)) | p_58) & g_1266), l_1379[6][0]))) & p_57);
     if (g_458)
       continue;
     g_71
       [7]
       =
       g_978;
   }
   if ((safe_sub_func_uint32_t_u_u (p_57, ((g_329[1][0][0] = 1UL) > 0x4F799D86L))))
   {
     uint32_t
       l_1527
       =
       0x90FEEB0CL;
     g_71
       [7]
       =
       l_1527;
     l_1438
       [5]
       [0]
       [1]
       =
       (p_59
        >=
        (safe_mod_func_uint16_t_u_u
  (((safe_add_func_uint32_t_u_u (((safe_add_func_int16_t_s_s (l_1534, (g_555 >= (safe_rshift_func_uint8_t_u_u ((((l_1379[3][3] = (g_920 = ((l_1469 = (p_59 > (safe_rshift_func_uint16_t_u_s (((g_697[8][0] = (l_1423[0][1] < p_58)) ^ (safe_sub_func_uint32_t_u_u (0xC6944EA8L, 0x231AE895L))), (safe_mul_func_int16_t_s_s (((g_1266 = (safe_mul_func_uint16_t_u_u (0x4B84L, p_58))) == l_1468[1]), 0x7211L)))))) || l_1453))) > p_57) ^ g_669), l_1431))))) == p_60), 0UL)) ^ l_1384[4]), 0xEAF0L)));
     g_71
       [2]
       =
       ((p_57 <= ((safe_sub_func_int16_t_s_s ((l_1379[1][5] = 0x41B3L), (((0x44B3AF87L | g_30) && l_1431) == g_1382))) ^ (l_799 = (safe_sub_func_int16_t_s_s (g_721[3], ((0x8FL ^ p_60) == g_344)))))) || g_367);
     l_800
       =
       (g_71
        [7]
        =
        ((l_609[0] = (g_329[0][0][1] = ((safe_sub_func_int32_t_s_s ((safe_unary_minus_func_uint8_t_u (((safe_mul_func_int16_t_s_s (((safe_sub_func_int16_t_s_s (g_38, (l_1527 > ((safe_mod_func_int8_t_s_s ((g_344 = p_58), (safe_add_func_uint32_t_u_u (p_57, l_1527)))) >= 0xD928L)))) < ((safe_unary_minus_func_uint32_t_u ((safe_mod_func_uint8_t_u_u ((safe_mod_func_uint16_t_u_u (((~((((safe_unary_minus_func_uint16_t_u (l_1527)) > (~l_70[1][5][0])) || (safe_lshift_func_int8_t_s_s (((((((safe_add_func_uint32_t_u_u (((g_1266 < (-1L)) || p_59), 0xA3200367L)) > p_59) <= l_1364) & l_1527) != 0x2212L) && g_513[2]), l_1379[2][3]))) <= p_58)) <= p_58), g_329[0][6][2])), p_58)))) ^ l_1570)), p_57)) > l_1438[9][0][1]))), 0x19F76790L)) != 0L))) || p_58));
   }
   else
   {
     int32_t
       l_1571
       [3];
     int
       i;
     for
       (i
        =
        0;
        i
        <
        3;
        i++)
       l_1571
  [i]
  =
  1L;
     if (g_329[1][2][5])
       break;
     l_1475
       =
       (l_1571
        [0]
        =
        g_774);
     if (g_978)
       continue;
     l_1438
       [8]
       [0]
       [1]
       =
       ((safe_sub_func_uint8_t_u_u (((safe_lshift_func_int16_t_s_u (((safe_sub_func_uint8_t_u_u (((g_329[1][0][0] || (g_344 = l_1488)) == p_59), (l_1578 = g_3))) > 1UL), ((!((l_1188[g_458] | (((safe_rshift_func_uint8_t_u_u (l_1583[0][6][0], 2)) ^ p_59) >= (safe_sub_func_uint32_t_u_u (p_57, 0xF62CE792L)))) && l_1571[0])) == 0xC20AL))) < l_1453), p_59)) | l_70[1][2][0]);
   }
 }
 l_1379
   [7]
   [4]
   =
   l_1586;
 l_1379
   [2]
   [3]
   =
   (((0x463CL < (safe_mod_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u ((!(safe_sub_func_int8_t_s_s (p_58, (safe_rshift_func_int8_t_s_u (l_1502[2], 0))))), (safe_mul_func_uint16_t_u_u ((safe_mul_func_uint8_t_u_u ((safe_rshift_func_uint8_t_u_s ((l_1578 != l_1423[3][1]), 4)), l_1601[1])), 65527UL)))), 0xF6L))) < ((((safe_mod_func_int8_t_s_s ((p_59 = ((safe_mod_func_int8_t_s_s (((g_588 && l_1422) >= g_201), l_1601[2])) <= p_58)), g_697[8][0])) & l_1364) < 0xA8L) || l_1384[6])) <= g_458);
      }
   l_1383
     =
     ((l_1457[0] = ((l_1444 = (safe_rshift_func_uint8_t_u_u ((l_1438[5][0][1] = l_1383), 2))) & (l_1379[2][3] = (l_1250 || ((0L <= (((safe_mul_func_uint16_t_u_u ((g_774 = (g_1265[2][5] || l_1440)), (!(l_1423[3][1] = (safe_mod_func_int16_t_s_s ((safe_add_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s (g_30, l_1453)), (l_1454 = 1L))), ((safe_sub_func_int16_t_s_s ((g_697[5][0] = p_57), 4UL)) ^ l_1441))))))) < g_71[3]) ^ l_1379[8][1])) < 1UL))))) ^ l_1403[0]);
 }
 else
 {
   uint32_t
     l_1468
     [4];
   int32_t
     l_1469
     =
     (-1L);
   int32_t
     l_1583
     [1]
     [9]
     [1]
     =
     {
 {{0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  }
   };
   int
     i,
     j,
     k;
{
    int8_t
      l_1384
      [9]
      =
      {
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L),
   (-5L)
 };
    int32_t
      l_1403
      [10]
      =
      {
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L,
  0x71192DC3L,
  0x3A0323F7L
};
    int32_t
      l_1438
      [10]
      [1]
      [2]
      =
      {
  {{0x1D3F6542L, 9L}
   }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    , {{0x1D3F6542L, 9L}
       }
    };
    int32_t
      l_1441
      =
      0x0BC2D57BL;
    uint32_t
      l_1502
      [4]
      =
      {
 0xDC6A9CBAL,
 0xDC6A9CBAL,
 0xDC6A9CBAL,
 0xDC6A9CBAL
};
    int32_t
      l_1534
      =
      0x7453318EL;
    uint16_t
      l_1601
      [3];
    int16_t
      l_1744
      =
      0x6254L;
    int
      i,
      j,
      k;
    for
      (i
       =
       0;
       i
       <
       3;
       i++)
      l_1601
 [i]
 =
 0xB24DL;
    for
      (l_1341
       =
       0;
       (l_1341
 <=
 4);
       l_1341
       +=
       1)
    {
      uint16_t
 l_1364
 =
 65535UL;
      int32_t
 l_1379
 [10]
 [7]
 =
 {
    {0x64CD1FA4L,
     9L,
     0x6F22B797L,
     9L,
     0x64CD1FA4L,
     (-1L),
     0x6F22B797L}
      , {0x4AF1F542L, 0xDD5DAFA3L, 0L, 0L, 0xDD5DAFA3L, 0x4AF1F542L, 0xF78852C5L}
      , {0L, 1L, 8L, (-1L), 8L, 1L, 0L}
      , {0x4AF1F542L, 0L, 0xF78852C5L, 0xE476DB24L, 0xE476DB24L, 0xF78852C5L, 0L}
      , {0x64CD1FA4L, 1L, 4L, 0x349346A9L, 0x64CD1FA4L, 0x349346A9L, 4L}
      , {0xE476DB24L, 0xDD5DAFA3L, 0xF78852C5L, 6L, 0x4AF1F542L, 0x4AF1F542L, 6L}
      , {8L, 9L, 8L, 0x349346A9L, 0L, 9L, 0L}
      , {0xDD5DAFA3L, 6L, 0L, 0xE476DB24L, 0x4AF1F542L, (-1L), (-1L)}
      , {0x64CD1FA4L, (-1L), 0x6F22B797L, (-1L), 0x64CD1FA4L, 9L, 0x6F22B797L}
      , {(-6L), 0xDD5DAFA3L, 6L, 0L, 0xE476DB24L, 0x4AF1F542L, (-1L)}
      };
      uint32_t
 l_1431
 =
 4294967293UL;
      int32_t
 l_1578
 =
 0xF5ADD8F0L;
      uint8_t
 l_1616
 =
 0UL;
      int
 i,
        j;
      for
 (g_458
  =
  0;
  (g_458
   <=
   7);
  g_458
  +=
  1)
      {
 int32_t
   l_1383
   =
   0xCC80471DL;
 int32_t
   l_1422
   =
   0L;
 int32_t
   l_1423
   [9]
   [4]
   =
   {
      {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0x0542477FL}
 , {0x7D6DFEFEL, (-1L), 0xB7D78E3EL, (-1L)}
 , {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0xB7D78E3EL}
 };
 int32_t
   l_1444
   =
   0xE4F95524L;
 uint32_t
   l_1470
   =
   0x087273C0L;
 int32_t
   l_1475
   =
   3L;
 int16_t
   l_1488
   =
   (-6L);
 int32_t
   l_1497
   =
   0xD570C473L;
 int
   i,
   j;
 l_1364
   =
   l_1188
   [g_458];
 if ((g_71[1] = (safe_mul_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u (p_59, (g_774 = (((safe_add_func_uint8_t_u_u (l_1364, ((safe_lshift_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((-1L) | (safe_sub_func_uint32_t_u_u (((!((-1L) <= ((1L || ((l_1379[2][3] = (l_1188[g_458] == (0x10L & g_30))) < (~(safe_lshift_func_uint16_t_u_s ((p_58 = (((l_1383 = (((0x2EL && g_71[2]) == g_1382) > l_1364)) || g_930) != l_1188[g_458])), 12))))) & (-2L)))) | l_1188[g_458]), g_344))) | g_721[3]), 249UL)) != g_1266), 11)) < 0UL))) ^ 9UL) ^ l_1384[4])))), 0xC5F3L))))
 {
   int32_t
     l_1440
     =
     0L;
   int32_t
     l_1454
     =
     1L;
   int32_t
     l_1457
     [1];
   int
     i;
   for
     (i
      =
      0;
      i
      <
      1;
      i++)
     l_1457
       [i]
       =
       0xC6483828L;
   for
     (g_521
      =
      1;
      (g_521
       <=
       4);
      g_521
      +=
      1)
   {
     uint8_t
       l_1402
       =
       255UL;
     int32_t
       l_1424
       =
       5L;
     g_71
       [3]
       =
       (l_1383
        =
        l_1383);
     l_1403
       [1]
       =
       ((safe_mod_func_int32_t_s_s ((safe_rshift_func_int8_t_s_s ((safe_sub_func_uint8_t_u_u (g_367, g_3)), (safe_sub_func_int8_t_s_s ((g_930 = g_978), (safe_add_func_uint8_t_u_u (g_367, g_1266)))))), (safe_unary_minus_func_int32_t_s ((l_609[0] = (0x39L || (safe_rshift_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u (((safe_sub_func_int8_t_s_s (l_1379[2][3], (l_1402 = ((g_300 && p_59) == g_344)))) || 0x5D37L), p_59)), p_58)))))))) == g_344);
     l_1424
       =
       ((safe_add_func_uint16_t_u_u (((l_1423[3][1] = (l_1383 = (l_1379[2][3] = ((((safe_lshift_func_int16_t_s_u (((safe_add_func_int8_t_s_s (((((g_555 = g_201) == (safe_sub_func_uint8_t_u_u ((p_57 & p_60), (+(safe_add_func_uint16_t_u_u (((!65531UL) == (l_1402 && (l_1379[1][6] <= ((safe_mul_func_int16_t_s_s (p_59, 0x6A1EL)) ^ (safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u (((safe_sub_func_int32_t_s_s ((g_3 ^ 7UL), 9L)) == p_59), 4294967295UL)), g_930)))))), l_1384[4])))))) < l_1422) != p_57), l_1402)) ^ l_1422), g_367)) && g_1265[2][5]) > g_71[5]) >= 7L)))) & 0L), l_1364)) <= p_59);
     return
       l_1379
       [7]
       [5];
   }
   for
     (p_59
      =
      0;
      (p_59
       <=
       7);
      p_59
      +=
      1)
   {
     uint32_t
       l_1439
       =
       0x7C99E9CAL;
     l_1379
       [2]
       [3]
       =
       g_513
       [1];
     l_799
       =
       g_697
       [8]
       [0];
     l_1441
       =
       (safe_add_func_int32_t_s_s
        ((l_1440 = (safe_mod_func_int32_t_s_s ((((safe_mod_func_int16_t_s_s (l_1431, g_697[7][1])) ^ (safe_add_func_int16_t_s_s ((safe_sub_func_int32_t_s_s (g_1281, (safe_rshift_func_uint8_t_u_u (((g_513[3] & (l_1438[5][0][1] = (g_344 ^ (l_1403[9] = 0xB097F462L)))) == (0UL | (-1L))), 3)))), (l_1384[4] == p_58)))) < l_1439), l_1423[3][1]))), g_458));
   }
   l_1383
     =
     ((l_1457[0] = ((l_1444 = (safe_rshift_func_uint8_t_u_u ((l_1438[5][0][1] = l_1383), 2))) & (l_1379[2][3] = (l_1250 || ((0L <= (((safe_mul_func_uint16_t_u_u ((g_774 = (g_1265[2][5] || l_1440)), (!(l_1423[3][1] = (safe_mod_func_int16_t_s_s ((safe_add_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s (g_30, l_1453)), (l_1454 = 1L))), ((safe_sub_func_int16_t_s_s ((g_697[5][0] = p_57), 4UL)) ^ l_1441))))))) < g_71[3]) ^ l_1379[8][1])) < 1UL))))) ^ l_1403[0]);
 }
 else
 {
   uint32_t
     l_1468
     [4];
   int32_t
     l_1469
     =
     (-1L);
   int32_t
     l_1583
     [1]
     [9]
     [1]
     =
     {
 {{0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  }
   };
   int
     i,
     j,
     k;
   for
     (i
      =
      0;
      i
      <
      4;
      i++)
     l_1468
       [i]
       =
       0UL;
   l_1423
     [3]
     [1]
     =
     ((l_1441 = p_60) > (safe_add_func_int8_t_s_s ((g_344 = (safe_add_func_uint16_t_u_u (0UL, ((6UL || (l_1383 > p_58)) == (((safe_mul_func_uint8_t_u_u (g_866, 0x91L)) != ((safe_add_func_int8_t_s_s ((safe_sub_func_uint16_t_u_u ((l_1468[0] = (p_60 | p_60)), l_1469)), 0xBEL)) || g_1266)) < p_58))))), 0L)));
   if ((l_1470 & (safe_sub_func_int32_t_s_s (((((safe_sub_func_uint8_t_u_u (l_1475, l_609[0])) == p_59) ^ (safe_lshift_func_int16_t_s_u ((((safe_sub_func_int16_t_s_s ((safe_mod_func_int32_t_s_s (((g_555 = (0x0B1DL == p_60)) && g_71[7]), (safe_mul_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u ((g_344 = (p_60 != ((+(((safe_lshift_func_uint16_t_u_s (0xB105L, p_57)) >= p_57) < g_71[7])) && l_1441))), 2)), g_588)))), g_1281)) || g_697[8][0]) ^ p_59), g_920))) || l_1488), g_521))))
   {
     int8_t
       l_1503
       =
       0xE6L;
     l_1383
       =
       (safe_mul_func_uint8_t_u_u
        (p_60,
  p_57));
     l_1423
       [3]
       [1]
       =
       (+
        (!
  (safe_rshift_func_uint8_t_u_s
   (l_1468
    [0],
    ((g_513[2] < p_59) <= (safe_mul_func_int16_t_s_s (9L, (0x8FL < (l_1469 = (safe_sub_func_uint16_t_u_u (l_1497, ((safe_sub_func_int16_t_s_s ((g_697[8][0] = p_58), (g_521 = (-7L)))) != (safe_lshift_func_int16_t_s_u ((l_1502[1] & 8L), l_1502[1]))))))))))))));
     g_71
       [6]
       =
       (l_1503
        =
        g_588);
     if (g_697[8][0])
       break;
   }
   else
   {
     int32_t
       l_1524
       =
       0x6DC5B83AL;
     l_1441
       =
       l_1468
       [0];
     l_1469
       =
       ((p_58 = (safe_add_func_int32_t_s_s (((((((safe_mod_func_int8_t_s_s (((safe_lshift_func_uint8_t_u_u ((0x3CE0A1BCL < l_1188[7]), (safe_add_func_int8_t_s_s ((0x37L >= (((safe_add_func_int16_t_s_s ((+(!((safe_rshift_func_int16_t_s_u (((safe_sub_func_int16_t_s_s ((l_800 = ((safe_add_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_s ((l_609[0] | ((safe_lshift_func_uint16_t_u_s (l_1384[4], g_201)) | 0x06C8L)), 0)), 255UL)) || (((0x0530L == g_329[1][0][0]) >= 1UL) ^ g_1281))), g_721[5])) && 255UL), p_60)) < l_1524))), l_1438[1][0][1])) > l_1469) || p_59)), p_59)))) <= p_60), 0x7FL)) & g_721[3]) <= g_329[1][4][2]) == (-9L)) | p_58) & g_1266), l_1379[6][0]))) & p_57);
     if (g_458)
       continue;
     g_71
       [7]
       =
       g_978;
   }
   if ((safe_sub_func_uint32_t_u_u (p_57, ((g_329[1][0][0] = 1UL) > 0x4F799D86L))))
   {
     uint32_t
       l_1527
       =
       0x90FEEB0CL;
     g_71
       [7]
       =
       l_1527;
     l_1438
       [5]
       [0]
       [1]
       =
       (p_59
        >=
        (safe_mod_func_uint16_t_u_u
  (((safe_add_func_uint32_t_u_u (((safe_add_func_int16_t_s_s (l_1534, (g_555 >= (safe_rshift_func_uint8_t_u_u ((((l_1379[3][3] = (g_920 = ((l_1469 = (p_59 > (safe_rshift_func_uint16_t_u_s (((g_697[8][0] = (l_1423[0][1] < p_58)) ^ (safe_sub_func_uint32_t_u_u (0xC6944EA8L, 0x231AE895L))), (safe_mul_func_int16_t_s_s (((g_1266 = (safe_mul_func_uint16_t_u_u (0x4B84L, p_58))) == l_1468[1]), 0x7211L)))))) || l_1453))) > p_57) ^ g_669), l_1431))))) == p_60), 0UL)) ^ l_1384[4]), 0xEAF0L)));
     g_71
       [2]
       =
       ((p_57 <= ((safe_sub_func_int16_t_s_s ((l_1379[1][5] = 0x41B3L), (((0x44B3AF87L | g_30) && l_1431) == g_1382))) ^ (l_799 = (safe_sub_func_int16_t_s_s (g_721[3], ((0x8FL ^ p_60) == g_344)))))) || g_367);
     l_800
       =
       (g_71
        [7]
        =
        ((l_609[0] = (g_329[0][0][1] = ((safe_sub_func_int32_t_s_s ((safe_unary_minus_func_uint8_t_u (((safe_mul_func_int16_t_s_s (((safe_sub_func_int16_t_s_s (g_38, (l_1527 > ((safe_mod_func_int8_t_s_s ((g_344 = p_58), (safe_add_func_uint32_t_u_u (p_57, l_1527)))) >= 0xD928L)))) < ((safe_unary_minus_func_uint32_t_u ((safe_mod_func_uint8_t_u_u ((safe_mod_func_uint16_t_u_u (((~((((safe_unary_minus_func_uint16_t_u (l_1527)) > (~l_70[1][5][0])) || (safe_lshift_func_int8_t_s_s (((((((safe_add_func_uint32_t_u_u (((g_1266 < (-1L)) || p_59), 0xA3200367L)) > p_59) <= l_1364) & l_1527) != 0x2212L) && g_513[2]), l_1379[2][3]))) <= p_58)) <= p_58), g_329[0][6][2])), p_58)))) ^ l_1570)), p_57)) > l_1438[9][0][1]))), 0x19F76790L)) != 0L))) || p_58));
   }
   else
   {
     int32_t
       l_1571
       [3];
     int
       i;
     for
       (i
        =
        0;
        i
        <
        3;
        i++)
       l_1571
  [i]
  =
  1L;
     if (g_329[1][2][5])
       break;
     l_1475
       =
       (l_1571
        [0]
        =
        g_774);
     if (g_978)
       continue;
     l_1438
       [8]
       [0]
       [1]
       =
       ((safe_sub_func_uint8_t_u_u (((safe_lshift_func_int16_t_s_u (((safe_sub_func_uint8_t_u_u (((g_329[1][0][0] || (g_344 = l_1488)) == p_59), (l_1578 = g_3))) > 1UL), ((!((l_1188[g_458] | (((safe_rshift_func_uint8_t_u_u (l_1583[0][6][0], 2)) ^ p_59) >= (safe_sub_func_uint32_t_u_u (p_57, 0xF62CE792L)))) && l_1571[0])) == 0xC20AL))) < l_1453), p_59)) | l_70[1][2][0]);
   }
 }
 l_1379
   [7]
   [4]
   =
   l_1586;
 l_1379
   [2]
   [3]
   =
   (((0x463CL < (safe_mod_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u ((!(safe_sub_func_int8_t_s_s (p_58, (safe_rshift_func_int8_t_s_u (l_1502[2], 0))))), (safe_mul_func_uint16_t_u_u ((safe_mul_func_uint8_t_u_u ((safe_rshift_func_uint8_t_u_s ((l_1578 != l_1423[3][1]), 4)), l_1601[1])), 65527UL)))), 0xF6L))) < ((((safe_mod_func_int8_t_s_s ((p_59 = ((safe_mod_func_int8_t_s_s (((g_588 && l_1422) >= g_201), l_1601[2])) <= p_58)), g_697[8][0])) & l_1364) < 0xA8L) || l_1384[6])) <= g_458);
      }
      for
 (l_1578
  =
  7;
  (l_1578
   >=
   0);
  l_1578
  -=
  1)
      {
 int32_t
   l_1622
   [4]
   =
   {
      (-9L),
      (-9L),
      (-9L),
      (-9L)
    };
 int
   i;
 if (p_57)
 {
   uint32_t
     l_1621
     =
     0x90FD25AAL;
   l_1379
     [1]
     [0]
     =
     g_697
     [8]
     [0];
   for
     (p_60
      =
      0;
      (p_60
       <=
       7);
      p_60
      +=
      1)
   {
     g_71
       [3]
       =
       (safe_sub_func_int32_t_s_s
        ((safe_mod_func_int16_t_s_s ((safe_mul_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_s ((((g_588 = (g_329[1][0][0] ^ (safe_mod_func_int32_t_s_s (l_1616, 4294967295UL)))) | (((safe_rshift_func_int16_t_s_s (((safe_mod_func_uint8_t_u_u (5UL, (0x7FD0L && (l_1570 < l_1621)))) >= g_978), (0x1D61L || g_1265[3][4]))) & p_59) ^ g_721[0])) || (-5L)), p_60)), l_1622[1])), p_57)), g_1281));
     if (p_58)
       continue;
     if (l_1621)
       break;
     return
       l_1250;
   }
 }
 else
 {
   uint32_t
     l_1655
     =
     4294967295UL;
   int32_t
     l_1668
     =
     0x8E80973DL;
   if ((safe_sub_func_uint16_t_u_u ((((safe_mod_func_uint8_t_u_u (g_513[1], 1UL)) != l_1341) | (safe_add_func_int16_t_s_s ((safe_add_func_int8_t_s_s ((safe_rshift_func_int16_t_s_s (((safe_mul_func_uint16_t_u_u (((((safe_mod_func_int8_t_s_s ((safe_add_func_int16_t_s_s ((safe_mul_func_uint16_t_u_u (((+(((0xBC28A63EL <= ((g_329[1][0][0] || ((safe_rshift_func_uint8_t_u_u ((g_588 = (safe_mul_func_int8_t_s_s (((safe_lshift_func_int8_t_s_u ((safe_rshift_func_uint16_t_u_s ((safe_lshift_func_int8_t_s_u ((((0xC86CL & (safe_add_func_uint16_t_u_u (((((p_60 <= 2UL) < (((safe_add_func_int8_t_s_s ((!p_57), g_513[1])) | 0x25L) < g_38)) && (-1L)) < 0x351E1285L), 65535UL))) && 3L) < g_71[7]), 2)), 11)), l_1622[1])) <= (-3L)), p_57))), 0)) != g_367)) >= 0xAF39FF41L)) >= 1L) < p_58)) & (-8L)), l_1403[1])), p_58)), 0xECL)) < g_329[1][0][0]) < (-3L)) || g_721[3]), (-1L))) != l_1655), 7)), 1L)), p_57))), 0x4FDFL)))
   {
     int32_t
       l_1660
       =
       0L;
     int32_t
       l_1661
       [9]
       [5]
       =
       {
   {0xF3EECE38L,
    6L,
    0L,
    (-10L),
    0L}
     , {(-10L), (-10L), 0xB8A18AEDL, (-8L), 4L}
     , {0x7ED8E6F0L, 0x4FFD6CFCL, 0xB8A18AEDL, 0L, 0xF3EECE38L}
     , {(-1L), 0xB8A18AEDL, 0L, 0xB8A18AEDL, (-1L)}
     , {(-8L), 0x4FFD6CFCL, 4L, (-1L), (-10L)}
     , {(-8L), (-10L), 0xF3EECE38L, 0x5F042651L, 0x5F042651L}
     , {(-1L), 6L, (-1L), 0x4FFD6CFCL, (-10L)}
     , {0x7ED8E6F0L, 0x5F042651L, (-10L), 0x4FFD6CFCL, (-1L)}
     , {(-10L), 0xF3EECE38L, 0x5F042651L, 0x5F042651L, 0xF3EECE38L}
     };
     int
       i,
       j;
     l_1668
       =
       ((l_1438[5][0][1] != (l_1622[1] = ((l_800 = (l_1661[8][1] = (safe_lshift_func_uint8_t_u_s ((safe_mod_func_uint32_t_u_u (g_930, l_1660)), 7)))) && (+l_1379[2][3])))) ^ ((safe_lshift_func_int16_t_s_u (((safe_add_func_int32_t_s_s (g_658, (g_513[1] <= ((g_697[5][1] <= (((((-3L) || (safe_lshift_func_uint8_t_u_u (g_920, p_57))) < 0x61L) && g_555) ^ p_57)) < l_1616)))) > l_1403[1]), 4)) | 0x1AL));
     l_1622
       [1]
       =
       p_58;
   }
   else
   {
     uint8_t
       l_1685
       =
       1UL;
     g_71
       [7]
       =
       9L;
     g_71
       [7]
       =
       ((p_59 || (safe_mul_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u (((((g_513[1] ^ (l_1685 = ((+((~(0xD9D52541L & (safe_add_func_int16_t_s_s (g_521, (safe_add_func_int32_t_s_s ((safe_mul_func_int16_t_s_s ((safe_mod_func_uint32_t_u_u ((((safe_sub_func_uint32_t_u_u (((0xA7L < (~(((-7L) & ((safe_rshift_func_uint8_t_u_u (((p_60 <= p_59) & l_1622[3]), 4)) && g_201)) ^ g_721[2]))) | p_58), l_1441)) < l_1379[2][3]) != 0UL), l_799)), p_57)), g_774)))))) || 0xCBC7BAA7L)) == 1UL))) <= l_1616) < 0xFCAE371CL) | p_60), p_60)), 0x22L))) | 0x96L);
   }
   if (((safe_rshift_func_int8_t_s_s (((safe_add_func_uint16_t_u_u ((g_1281 & p_57), (safe_rshift_func_int8_t_s_s (((safe_add_func_uint8_t_u_u ((((l_67 || (((safe_add_func_uint8_t_u_u (((p_60 ^ (safe_lshift_func_int8_t_s_s ((safe_add_func_uint32_t_u_u ((safe_rshift_func_uint8_t_u_s (g_329[1][0][0], (g_930 = (safe_lshift_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u (l_1431, (safe_mul_func_uint16_t_u_u (((safe_mul_func_int16_t_s_s ((safe_rshift_func_int16_t_s_u ((l_1601[2] == ((safe_add_func_int8_t_s_s (((!g_300) || ((g_555 < g_3) ^ 0x16L)), 0xDAL)) & p_59)), g_329[1][0][0])), 7UL)) ^ p_57), p_57)))), l_1622[0]))))), p_60)), p_58))) ^ l_1622[2]), l_1578)) != 3L) & 0xCC7C2B67L)) < p_59) != 0x96F0A4A3L), g_866)) > (-1L)), 1)))) < 4UL), 7)) != 0x913DE694L))
   {
     int16_t
       l_1732
       =
       0x0AABL;
     int32_t
       l_1733
       =
       1L;
     l_1733
       =
       ((safe_mod_func_int16_t_s_s ((safe_add_func_int8_t_s_s ((safe_mod_func_uint32_t_u_u ((safe_mod_func_uint16_t_u_u ((l_1379[9][0] = ((safe_mod_func_int32_t_s_s ((safe_sub_func_int16_t_s_s (0L, g_1265[2][5])), (((((0xDADA1386L != (0UL != ((g_71[3] = (safe_sub_func_int32_t_s_s (g_774, (safe_rshift_func_int16_t_s_s ((g_300 != (((g_344 = (((safe_sub_func_uint16_t_u_u (p_58, g_920)) > (p_59 || g_697[5][0])) <= g_920)) < p_57) || g_521)), 9))))) && p_60))) || g_71[7]) ^ l_1586) == l_1622[1]) & p_59))) || l_1732)), l_1622[1])), 7UL)), l_1534)), 0x2CAFL)) != 0x663D3C7BL);
   }
   else
   {
     if (p_57)
       break;
   }
 }
 g_71
   [4]
   =
   (safe_mod_func_uint16_t_u_u
    ((((p_60 & ((safe_lshift_func_int16_t_s_u ((((safe_mod_func_uint8_t_u_u (((((safe_add_func_int16_t_s_s ((g_513[1] || (safe_mul_func_int16_t_s_s ((((l_799 = (g_329[1][0][0] = (l_1744 = p_59))) < (l_1438[5][0][0] = ((p_60 > ((safe_rshift_func_uint16_t_u_s ((g_513[5] <= (safe_lshift_func_uint8_t_u_u ((g_588 = (safe_rshift_func_uint16_t_u_s (((safe_sub_func_uint8_t_u_u ((((l_800 = p_60) & (safe_mul_func_uint16_t_u_u ((safe_mul_func_int8_t_s_s ((safe_mul_func_int8_t_s_s (((p_57 == ((safe_rshift_func_uint8_t_u_u (g_38, p_57)) >= p_60)) < p_58), g_920)), p_60)), g_521))) & p_60), 0x5CL)) || 0x8BL), 2))), p_60))), 8)) | p_59)) < p_58))) ^ l_1570), 0xD07CL))), 0x282FL)) == l_1364) ^ 0xF4L) != 0x0542L), 0xA2L)) <= 1UL) | 0xE807L), 2)) & 4L)) == g_513[1]) || l_1431), g_866));
      }
    }
    for
      (g_555
       =
       4;
       (g_555
 >=
 0);
       g_555
       -=
       1)
    {
      uint8_t
 l_1779
 =
 0x2BL;
      int32_t
 l_1809
 =
 0x544162F4L;
      int32_t
 l_1836
 =
 0L;
      for
 (g_658
  =
  0;
  (g_658
   <=
   4);
  g_658
  +=
  1)
      {
 int32_t
   l_1772
   =
   (-2L);
 int32_t
   l_1780
   =
   (-8L);
 int
   i;
 for
   (l_800
    =
    0;
    (l_800
     <=
     4);
    l_800
    +=
    1)
 {
   for
     (l_1441
      =
      8;
      (l_1441
       >=
       0);
      l_1441
      -=
      1)
   {
     int32_t
       l_1781
       =
       0x3D9E8289L;
     int
       i;
     g_71
       [(g_555 + 1)] = (safe_rshift_func_uint8_t_u_s (0xF9L, 6));
     g_1763
       =
       (g_71
        [l_1441]
        =
        (l_1188
  [(l_800 + 3)] | g_71[(l_800 + 1)]));
     g_1782
       =
       (l_1781
        =
        (g_1763
  =
  (safe_add_func_uint8_t_u_u
   (250UL,
    (l_1780
     =
     (safe_mod_func_int32_t_s_s
      (((safe_lshift_func_uint16_t_u_u ((l_1438[9][0][0] = (1UL < (safe_lshift_func_uint8_t_u_u (((l_1772 = 0x601044F6L) < 0xFB6A6C17L), l_1403[1])))), 15)) <= (((3UL == ((g_71[(g_555 + 1)] = (g_588 = g_71[l_1441])) & (g_920 != ((safe_lshift_func_int8_t_s_s (((safe_mod_func_int8_t_s_s ((safe_mod_func_int16_t_s_s (g_930, g_201)), l_1779)) <= p_60), 1)) <= 0x98597F36L)))) && p_59) >= p_60)), p_60)))))));
   }
 }
 l_1780
   =
   l_1188
   [(g_555 + 1)];
 if (l_1188[(g_555 + 1)])
   continue;
      }
      for
 (l_799
  =
  1;
  (l_799
   <=
   9);
  l_799
  +=
  1)
      {
 int
   i;
 g_71
   [7]
   =
   (safe_mul_func_int16_t_s_s
    (g_721
     [(g_300 + 5)], (((l_1384[g_555] ^ (safe_sub_func_uint32_t_u_u ((safe_rshift_func_uint16_t_u_s ((safe_lshift_func_uint8_t_u_u ((safe_mod_func_uint16_t_u_u ((safe_rshift_func_int16_t_s_s ((((safe_rshift_func_uint8_t_u_s (((safe_sub_func_int16_t_s_s ((safe_add_func_int32_t_s_s (((((safe_mul_func_int8_t_s_s ((l_1809 = ((((1L == (0x264CL ^ ((g_367 > (!((l_1502[1] < (((safe_mul_func_int8_t_s_s (g_1281, ((safe_sub_func_int8_t_s_s ((-8L), (safe_add_func_uint32_t_u_u (((-1L) ^ p_59), g_697[3][1])))) < p_59))) <= 0xD3L) == g_30)) ^ 1UL))) || g_1782))) < (-1L)) & p_60) && p_59)), l_1601[2])) > p_58) > p_57) & 0x07L), l_1403[4])), p_60)) < 1L), l_1601[1])) ^ g_1810[0]) || 0x6DB63905L), 1)), g_1265[0][7])), l_1384[g_555])), 9)), 0x3ADD4C1FL))) | p_57) >= 0xFB8058A3L)));
 return
   l_67;
      }
      l_1836
 =
 ((((l_1809 = (((safe_rshift_func_uint8_t_u_u (3UL, 5)) <= (safe_add_func_int32_t_s_s ((l_800 = (p_57 ^ l_1570)), g_588))) != (safe_rshift_func_int16_t_s_u ((g_1835[0][3][2] = (safe_sub_func_uint32_t_u_u ((safe_add_func_int16_t_s_s ((~(l_799 = l_609[0])), ((safe_rshift_func_uint8_t_u_s ((l_1834 = (0L | (safe_add_func_int16_t_s_s ((safe_rshift_func_uint16_t_u_u ((safe_add_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u (l_1586, 1)), (0x70L != (((((l_1833 = ((((safe_mod_func_uint16_t_u_u (l_1779, p_58)) & 4294967290UL) || p_57) < l_1809)) || g_458) < l_609[0]) == l_1809) >= 0xFEBCL)))), l_1438[7][0][0])), 0xF83DL)))), 2)) | g_3))), 0x0384F0ABL))), 9)))) > g_1281) && g_721[4]) <= g_555);
    }
    if (l_1837)
      continue;
    l_1441
      =
      (safe_add_func_int32_t_s_s
       ((safe_lshift_func_int16_t_s_s ((-8L), 11)), ((!(((l_1438[4][0][0] | ((safe_mul_func_uint8_t_u_u (0xA2L, l_1586)) || (((0xAA39DF63L >= (safe_mod_func_int32_t_s_s (0L, g_555))) > (g_1835[0][3][2] = ((((g_930 < ((-5L) && p_60)) > 7UL) == g_1810[0]) >= l_1005))) != p_58))) > l_1384[4]) >= g_329[1][0][0])) >= (-1L))));
    for
      (l_1250
       =
       2;
       (l_1250
 <=
 7);
       l_1250
       +=
       1)
    {
      uint32_t
 l_1852
 [6]
 [8]
 =
 {
   {0x581A6F4DL,
    1UL,
    1UL,
    0x581A6F4DL,
    0UL,
    4UL,
    0UL,
    4294967291UL}
      , {0UL, 0x492D247CL, 0x36109862L, 1UL, 4UL, 1UL, 0xFE55C8BFL, 1UL}
      , {1UL, 0x492D247CL, 0xBCE9244FL, 0x10EA97E1L, 0x36109862L, 4UL, 0x36109862L, 0x10EA97E1L}
      , {0xAE0CAB6DL, 1UL, 0xAE0CAB6DL, 0x6E6D3266L, 0xCD5D87ACL, 0x10EA97E1L, 0x581A6F4DL, 0x36109862L}
      , {0UL, 0x36109862L, 0UL, 4294967295UL, 1UL, 8UL, 0xCD5D87ACL, 0x492D247CL}
      , {0UL, 0xBCE9244FL, 8UL, 0x66C191B3L, 0xCD5D87ACL, 0xCD5D87ACL, 0x66C191B3L, 8UL}
      };
      int32_t
 l_1874
 [3];
      int8_t
 l_1988
 =
 1L;
      int
 i,
        j;
      for
 (i
  =
  0;
  i
  <
  3;
  i++)
 l_1874
   [i]
   =
   0x494C9DE3L;
      for
 (p_58
  =
  1;
  (p_58
   <=
   7);
  p_58
  +=
  1)
      {
 uint16_t
   l_1851
   =
   0xC774L;
 int32_t
   l_1885
   =
   (-1L);
 int32_t
   l_1931
   =
   0xC09AA10AL;
 int32_t
   l_1998
   =
   0x8EBFCBCBL;
 if ((g_1763 = (((safe_lshift_func_int16_t_s_s ((p_59 && 253UL), g_458)) < p_59) ^ p_59)))
 {
   uint8_t
     l_1850
     [6]
     =
     {
 3UL,
 3UL,
 0x2CL,
 3UL,
 3UL,
 0x2CL
      };
   int32_t
     l_1887
     =
     0xFE3DFA66L;
   int
     i;
   for
     (g_555
      =
      1;
      (g_555
       <=
       7);
      g_555
      +=
      1)
   {
     int
       i;
     l_1850
       [0]
       =
       (~
        (safe_add_func_int32_t_s_s
  (g_721
   [(l_1250 + 1)], 4294967291UL)));
     l_1833
       =
       (l_1851
        =
        g_1265
        [2]
        [3]);
     l_1852
       [5]
       [7]
       =
       (g_920
        &
        0UL);
   }
   if (p_59)
   {
     int8_t
       l_1875
       =
       0xCBL;
     int32_t
       l_1876
       =
       7L;
     l_1876
       =
       (safe_mul_func_int16_t_s_s
        ((safe_add_func_int16_t_s_s ((safe_rshift_func_uint8_t_u_u (((p_57 ^ ((safe_sub_func_int8_t_s_s ((g_930 = ((l_1850[4] || (safe_rshift_func_uint16_t_u_s (p_57, 8))) & ((p_57 || ((safe_rshift_func_uint16_t_u_s ((l_1341 ^ (safe_lshift_func_int16_t_s_u (p_60, g_458))), ((safe_unary_minus_func_uint8_t_u ((safe_mod_func_int8_t_s_s ((p_59 = (safe_mul_func_uint8_t_u_u (((safe_lshift_func_uint8_t_u_s ((0x1DC9L != ((l_1874[1] = (p_58 >= p_60)) || p_60)), g_1763)) > p_58), 0x59L))), p_58)))) > l_1875))) >= g_300)) == l_1850[0]))), p_60)) & l_1341)) > l_1850[0]), l_1852[5][7])), g_300)), p_60));
     return
       g_300;
   }
   else
   {
     uint16_t
       l_1886
       =
       0xA075L;
     l_1885
       =
       (g_1835
        [0]
        [4]
        [1]
        |
        ((safe_add_func_int8_t_s_s (g_1382, l_67)) > (g_521 = ((safe_mul_func_int8_t_s_s (((safe_lshift_func_int8_t_s_s ((safe_lshift_func_int8_t_s_u (g_774, 4)), 5)) <= (p_58 > g_658)), g_329[1][0][0])) ^ 0x231BL))));
     l_1886
       =
       p_59;
     l_1887
       =
       p_60;
   }
   if ((safe_sub_func_uint32_t_u_u (((safe_add_func_int32_t_s_s (0x0C94DF4DL, ((g_71[8] <= 0x2A2FD7B7L) > (((safe_mod_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u (p_58, (p_58 || g_1281))), l_1441)) == (p_60 <= (safe_lshift_func_uint16_t_u_s (((((safe_rshift_func_uint16_t_u_s (((safe_mul_func_int16_t_s_s ((safe_mul_func_uint8_t_u_u ((l_1438[5][0][1] = 9UL), l_609[0])), l_1502[1])) | l_1885), l_1887)) && 0L) <= g_866) ^ 0x1EL), 2)))) > 0x16DAL)))) | g_930), 0x0FE39029L)))
   {
     uint16_t
       l_1910
       =
       65535UL;
     l_1874
       [0]
       =
       l_1852
       [3]
       [0];
     l_1887
       =
       (l_799
        =
        (g_71
  [4]
  =
  ((safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint8_t_u_u ((safe_lshift_func_uint16_t_u_u (1UL, 8)), 4)), l_1887)) > p_57)));
     return
       l_1910;
   }
   else
   {
     uint16_t
       l_1930
       =
       0x5864L;
     g_1917
       =
       (p_60
        >
        (safe_sub_func_uint8_t_u_u
  ((g_588 = 0xB1L), (safe_mul_func_int8_t_s_s (1L, ((g_344 = (safe_mod_func_int8_t_s_s (g_71[8], 255UL))) <= 0x12L))))));
     l_1931
       =
       (((g_201 ^ 0x44L) | (safe_sub_func_int8_t_s_s ((safe_lshift_func_uint16_t_u_s ((safe_mod_func_uint32_t_u_u (((safe_lshift_func_int16_t_s_u ((((safe_rshift_func_int16_t_s_s ((l_1887 = (g_521 & (l_1885 = ((safe_rshift_func_int8_t_s_u (g_658, (g_1917 = 8UL))) < (p_60 < l_1930))))), 5)) ^ 0x95167045L) || (p_58 != p_57)), 2)) < 0x093B234CL), 8L)), p_58)), 0xA0L))) ^ 0x0BL);
   }
 }
 else
 {
   int16_t
     l_1956
     =
     2L;
   if ((g_1782 = ((0x45L || ((safe_sub_func_uint16_t_u_u ((safe_mod_func_int32_t_s_s ((p_57 < ((safe_mul_func_int8_t_s_s ((!g_1810[0]), p_60)) > ((safe_lshift_func_int8_t_s_s ((safe_unary_minus_func_int16_t_s ((((((((0x47AAL > (l_1931 = (l_800 = ((safe_mul_func_int8_t_s_s (l_1851, g_721[8])) > (l_1438[5][0][1] = g_721[3]))))) == l_1851) && g_774) | p_57) && p_59) && p_57) || p_59))), p_58)) != g_38))), 0x3FBAB0A6L)), 2L)) || 0x35047D49L)) >= g_555)))
   {
     uint32_t
       l_1969
       =
       7UL;
     l_1969
       =
       ((l_1403[1] = ((safe_add_func_int8_t_s_s ((safe_lshift_func_int8_t_s_u ((safe_sub_func_uint32_t_u_u ((safe_add_func_uint32_t_u_u ((g_38 | (safe_rshift_func_int16_t_s_u (((safe_unary_minus_func_int16_t_s ((safe_add_func_uint8_t_u_u (((-6L) ^ ((l_1438[3][0][1] = (((p_59 > (0xCEL <= 7UL)) && l_1956) > (safe_mul_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (65527UL, (g_555 = ((safe_rshift_func_int16_t_s_u ((safe_sub_func_uint32_t_u_u ((safe_add_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (g_1266, ((p_57 || p_58) && 1UL))), l_1885)), g_721[3])), g_721[3])) > 65535UL)))), p_59)))) > l_1834)), g_920)))) ^ (-6L)), g_721[3]))), p_60)), l_1341)), 5)), g_920)) ^ p_59)) ^ (-1L));
   }
   else
   {
     uint16_t
       l_1987
       =
       0xDE63L;
     g_1782
       =
       (safe_rshift_func_uint8_t_u_u
        (((safe_rshift_func_uint16_t_u_s ((safe_lshift_func_uint8_t_u_u ((safe_mul_func_int16_t_s_s ((g_521 = (((((((safe_lshift_func_uint8_t_u_u (g_1810[0], (l_1885 = (g_1917 = 0x68L)))) != l_1931) ^ (safe_rshift_func_uint8_t_u_s ((g_300 < ((((safe_rshift_func_uint16_t_u_s ((((safe_add_func_int32_t_s_s (g_1382, (0x6C6CE11BL && (g_71[6] = l_1851)))) ^ (0UL == (safe_unary_minus_func_uint16_t_u (1UL)))) < l_1852[5][7]), p_59)) | l_1987) == p_57) >= 0x3D2E901BL)), l_1403[1]))) == l_1987) == l_1956) != 0xB9A4CA4FL) && 0x32072BDCL)), p_59)), p_59)), l_1987)) < l_1988), 1));
   }
 }
 l_1931
   =
   (safe_rshift_func_uint8_t_u_u
    (((((safe_add_func_int8_t_s_s ((safe_mul_func_int8_t_s_s ((p_58 == ((g_1995 && (safe_rshift_func_int16_t_s_u ((0UL == (((l_1998 = l_1874[2]) == ((((safe_rshift_func_int16_t_s_s ((((g_344 = (((((p_59 = ((0x2FL | (l_1874[1] || (g_513[1] | l_1851))) > ((safe_rshift_func_int16_t_s_s ((l_1885 < l_1885), 13)) != l_2003))) >= (-1L)) != g_721[3]) ^ p_57) & g_1763)) && p_57) == l_1834), g_367)) > 0L) || p_57) ^ g_201)) | l_1250)), p_57))) || 65535UL)), p_58)), g_1810[0])) && g_588) ^ g_2004[0][0][2]) >= p_57), p_58));
      }
      g_1763
 =
 (g_71
  [1]
  =
  (safe_sub_func_uint8_t_u_u
   ((g_367 < 0x72D05B16L), (g_344 = (((l_800 = ((safe_mul_func_uint16_t_u_u ((l_609[0] = ((safe_add_func_int16_t_s_s ((0xF771L ^ (p_58 = ((safe_sub_func_int32_t_s_s ((p_59 | (safe_mul_func_uint16_t_u_u (((l_1833 = ((0L & p_57) & p_59)) & ((g_513[1] = (safe_add_func_uint16_t_u_u (l_1852[5][7], p_59))) < (-1L))), 0x8011L))), l_1570)) && l_1384[4]))), 0x3F64L)) | p_59)), l_1852[5][7])) != p_57)) | l_1874[1]) & l_1988)))));
    }
  }
{
   int32_t
     l_1440
     =
     0L;
   int32_t
     l_1454
     =
     1L;
   int32_t
     l_1457
     [1];
   int
     i;
   for
     (i
      =
      0;
      i
      <
      1;
      i++)
     l_1457
       [i]
       =
       0xC6483828L;
   for
     (g_521
      =
      1;
      (g_521
       <=
       4);
      g_521
      +=
      1)
   {
     uint8_t
       l_1402
       =
       255UL;
     int32_t
       l_1424
       =
       5L;
     g_71
       [3]
       =
       (l_1383
        =
        l_1383);
     l_1403
       [1]
       =
       ((safe_mod_func_int32_t_s_s ((safe_rshift_func_int8_t_s_s ((safe_sub_func_uint8_t_u_u (g_367, g_3)), (safe_sub_func_int8_t_s_s ((g_930 = g_978), (safe_add_func_uint8_t_u_u (g_367, g_1266)))))), (safe_unary_minus_func_int32_t_s ((l_609[0] = (0x39L || (safe_rshift_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u (((safe_sub_func_int8_t_s_s (l_1379[2][3], (l_1402 = ((g_300 && p_59) == g_344)))) || 0x5D37L), p_59)), p_58)))))))) == g_344);
     l_1424
       =
       ((safe_add_func_uint16_t_u_u (((l_1423[3][1] = (l_1383 = (l_1379[2][3] = ((((safe_lshift_func_int16_t_s_u (((safe_add_func_int8_t_s_s (((((g_555 = g_201) == (safe_sub_func_uint8_t_u_u ((p_57 & p_60), (+(safe_add_func_uint16_t_u_u (((!65531UL) == (l_1402 && (l_1379[1][6] <= ((safe_mul_func_int16_t_s_s (p_59, 0x6A1EL)) ^ (safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u (((safe_sub_func_int32_t_s_s ((g_3 ^ 7UL), 9L)) == p_59), 4294967295UL)), g_930)))))), l_1384[4])))))) < l_1422) != p_57), l_1402)) ^ l_1422), g_367)) && g_1265[2][5]) > g_71[5]) >= 7L)))) & 0L), l_1364)) <= p_59);
     return
       l_1379
       [7]
       [5];
   }
   for
     (p_59
      =
      0;
      (p_59
       <=
       7);
      p_59
      +=
      1)
   {
     uint32_t
       l_1439
       =
       0x7C99E9CAL;
     l_1379
       [2]
       [3]
       =
       g_513
       [1];
     l_799
       =
       g_697
       [8]
       [0];
     l_1441
       =
       (safe_add_func_int32_t_s_s
        ((l_1440 = (safe_mod_func_int32_t_s_s ((((safe_mod_func_int16_t_s_s (l_1431, g_697[7][1])) ^ (safe_add_func_int16_t_s_s ((safe_sub_func_int32_t_s_s (g_1281, (safe_rshift_func_uint8_t_u_u (((g_513[3] & (l_1438[5][0][1] = (g_344 ^ (l_1403[9] = 0xB097F462L)))) == (0UL | (-1L))), 3)))), (l_1384[4] == p_58)))) < l_1439), l_1423[3][1]))), g_458));
   }
   l_1383
     =
     ((l_1457[0] = ((l_1444 = (safe_rshift_func_uint8_t_u_u ((l_1438[5][0][1] = l_1383), 2))) & (l_1379[2][3] = (l_1250 || ((0L <= (((safe_mul_func_uint16_t_u_u ((g_774 = (g_1265[2][5] || l_1440)), (!(l_1423[3][1] = (safe_mod_func_int16_t_s_s ((safe_add_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s (g_30, l_1453)), (l_1454 = 1L))), ((safe_sub_func_int16_t_s_s ((g_697[5][0] = p_57), 4UL)) ^ l_1441))))))) < g_71[3]) ^ l_1379[8][1])) < 1UL))))) ^ l_1403[0]);
 }
 }
 l_1379
   [2]
   [3]
   =
   (((0x463CL < (safe_mod_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u ((!(safe_sub_func_int8_t_s_s (p_58, (safe_rshift_func_int8_t_s_u (l_1502[2], 0))))), (safe_mul_func_uint16_t_u_u ((safe_mul_func_uint8_t_u_u ((safe_rshift_func_uint8_t_u_s ((l_1578 != l_1423[3][1]), 4)), l_1601[1])), 65527UL)))), 0xF6L))) < ((((safe_mod_func_int8_t_s_s ((p_59 = ((safe_mod_func_int8_t_s_s (((g_588 && l_1422) >= g_201), l_1601[2])) <= p_58)), g_697[8][0])) & l_1364) < 0xA8L) || l_1384[6])) <= g_458);
      }
for
      (i
       =
       0;
       i
       <
       3;
       i++)
      l_1601
 [i]
 =
 0xB24DL;
    }
l_609
    [0]
    =
    g_329
    [1]
    [0]
    [5];
    for
      (l_1250
       =
       2;
       (l_1250
 <=
 7);
       l_1250
       +=
       1)
    {
      uint32_t
 l_1852
 [6]
 [8]
 =
 {
   {0x581A6F4DL,
    1UL,
    1UL,
    0x581A6F4DL,
    0UL,
    4UL,
    0UL,
    4294967291UL}
      , {0UL, 0x492D247CL, 0x36109862L, 1UL, 4UL, 1UL, 0xFE55C8BFL, 1UL}
      , {1UL, 0x492D247CL, 0xBCE9244FL, 0x10EA97E1L, 0x36109862L, 4UL, 0x36109862L, 0x10EA97E1L}
      , {0xAE0CAB6DL, 1UL, 0xAE0CAB6DL, 0x6E6D3266L, 0xCD5D87ACL, 0x10EA97E1L, 0x581A6F4DL, 0x36109862L}
      , {0UL, 0x36109862L, 0UL, 4294967295UL, 1UL, 8UL, 0xCD5D87ACL, 0x492D247CL}
      , {0UL, 0xBCE9244FL, 8UL, 0x66C191B3L, 0xCD5D87ACL, 0xCD5D87ACL, 0x66C191B3L, 8UL}
      };
      int32_t
 l_1874
 [3];
      int8_t
 l_1988
 =
 1L;
      int
 i,
        j;
      for
 (i
  =
  0;
  i
  <
  3;
  i++)
{l_1441
      =
      (safe_add_func_int32_t_s_s
       ((safe_lshift_func_int16_t_s_s ((-8L), 11)), ((!(((l_1438[4][0][0] | ((safe_mul_func_uint8_t_u_u (0xA2L, l_1586)) || (((0xAA39DF63L >= (safe_mod_func_int32_t_s_s (0L, g_555))) > (g_1835[0][3][2] = ((((g_930 < ((-5L) && p_60)) > 7UL) == g_1810[0]) >= l_1005))) != p_58))) > l_1384[4]) >= g_329[1][0][0])) >= (-1L))));
}
{
      uint16_t
 l_1364
 =
 65535UL;
      int32_t
 l_1379
 [10]
 [7]
 =
 {
    {0x64CD1FA4L,
     9L,
     0x6F22B797L,
     9L,
     0x64CD1FA4L,
     (-1L),
     0x6F22B797L}
      , {0x4AF1F542L, 0xDD5DAFA3L, 0L, 0L, 0xDD5DAFA3L, 0x4AF1F542L, 0xF78852C5L}
      , {0L, 1L, 8L, (-1L), 8L, 1L, 0L}
      , {0x4AF1F542L, 0L, 0xF78852C5L, 0xE476DB24L, 0xE476DB24L, 0xF78852C5L, 0L}
      , {0x64CD1FA4L, 1L, 4L, 0x349346A9L, 0x64CD1FA4L, 0x349346A9L, 4L}
      , {0xE476DB24L, 0xDD5DAFA3L, 0xF78852C5L, 6L, 0x4AF1F542L, 0x4AF1F542L, 6L}
      , {8L, 9L, 8L, 0x349346A9L, 0L, 9L, 0L}
      , {0xDD5DAFA3L, 6L, 0L, 0xE476DB24L, 0x4AF1F542L, (-1L), (-1L)}
      , {0x64CD1FA4L, (-1L), 0x6F22B797L, (-1L), 0x64CD1FA4L, 9L, 0x6F22B797L}
      , {(-6L), 0xDD5DAFA3L, 6L, 0L, 0xE476DB24L, 0x4AF1F542L, (-1L)}
      };
      uint32_t
 l_1431
 =
 4294967293UL;
      int32_t
 l_1578
 =
 0xF5ADD8F0L;
      uint8_t
 l_1616
 =
 0UL;
      int
 i,
        j;
      for
 (g_458
  =
  0;
  (g_458
   <=
   7);
  g_458
  +=
  1)
      {
 int32_t
   l_1383
   =
   0xCC80471DL;
 int32_t
   l_1422
   =
   0L;
 int32_t
   l_1423
   [9]
   [4]
   =
   {
      {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0x0542477FL}
 , {0x7D6DFEFEL, (-1L), 0xB7D78E3EL, (-1L)}
 , {(-1L), (-1L), 0xB7D78E3EL, 0xB7D78E3EL}
 , {0x7D6DFEFEL, 0x7D6DFEFEL, (-1L), 0xB7D78E3EL}
 , {0x0542477FL, (-1L), 0x0542477FL, (-1L)}
 , {0x0542477FL, (-1L), (-1L), 0xB7D78E3EL}
 };
 int32_t
   l_1444
   =
   0xE4F95524L;
 uint32_t
   l_1470
   =
   0x087273C0L;
 int32_t
   l_1475
   =
   3L;
 int16_t
   l_1488
   =
   (-6L);
 int32_t
   l_1497
   =
   0xD570C473L;
 int
   i,
   j;
 l_1364
   =
   l_1188
   [g_458];
 if ((g_71[1] = (safe_mul_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u (p_59, (g_774 = (((safe_add_func_uint8_t_u_u (l_1364, ((safe_lshift_func_int16_t_s_s (((safe_sub_func_int8_t_s_s ((((-1L) | (safe_sub_func_uint32_t_u_u (((!((-1L) <= ((1L || ((l_1379[2][3] = (l_1188[g_458] == (0x10L & g_30))) < (~(safe_lshift_func_uint16_t_u_s ((p_58 = (((l_1383 = (((0x2EL && g_71[2]) == g_1382) > l_1364)) || g_930) != l_1188[g_458])), 12))))) & (-2L)))) | l_1188[g_458]), g_344))) | g_721[3]), 249UL)) != g_1266), 11)) < 0UL))) ^ 9UL) ^ l_1384[4])))), 0xC5F3L))))
 {
   int32_t
     l_1440
     =
     0L;
   int32_t
     l_1454
     =
     1L;
   int32_t
     l_1457
     [1];
   int
     i;
   for
     (i
      =
      0;
      i
      <
      1;
      i++)
     l_1457
       [i]
       =
       0xC6483828L;
   for
     (g_521
      =
      1;
      (g_521
       <=
       4);
      g_521
      +=
      1)
   {
     uint8_t
       l_1402
       =
       255UL;
     int32_t
       l_1424
       =
       5L;
     g_71
       [3]
       =
       (l_1383
        =
        l_1383);
     l_1403
       [1]
       =
       ((safe_mod_func_int32_t_s_s ((safe_rshift_func_int8_t_s_s ((safe_sub_func_uint8_t_u_u (g_367, g_3)), (safe_sub_func_int8_t_s_s ((g_930 = g_978), (safe_add_func_uint8_t_u_u (g_367, g_1266)))))), (safe_unary_minus_func_int32_t_s ((l_609[0] = (0x39L || (safe_rshift_func_uint16_t_u_u ((safe_lshift_func_int8_t_s_u (((safe_sub_func_int8_t_s_s (l_1379[2][3], (l_1402 = ((g_300 && p_59) == g_344)))) || 0x5D37L), p_59)), p_58)))))))) == g_344);
     l_1424
       =
       ((safe_add_func_uint16_t_u_u (((l_1423[3][1] = (l_1383 = (l_1379[2][3] = ((((safe_lshift_func_int16_t_s_u (((safe_add_func_int8_t_s_s (((((g_555 = g_201) == (safe_sub_func_uint8_t_u_u ((p_57 & p_60), (+(safe_add_func_uint16_t_u_u (((!65531UL) == (l_1402 && (l_1379[1][6] <= ((safe_mul_func_int16_t_s_s (p_59, 0x6A1EL)) ^ (safe_mod_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u (((safe_sub_func_int32_t_s_s ((g_3 ^ 7UL), 9L)) == p_59), 4294967295UL)), g_930)))))), l_1384[4])))))) < l_1422) != p_57), l_1402)) ^ l_1422), g_367)) && g_1265[2][5]) > g_71[5]) >= 7L)))) & 0L), l_1364)) <= p_59);
     return
       l_1379
       [7]
       [5];
   }
   for
     (p_59
      =
      0;
      (p_59
       <=
       7);
      p_59
      +=
      1)
   {
     uint32_t
       l_1439
       =
       0x7C99E9CAL;
     l_1379
       [2]
       [3]
       =
       g_513
       [1];
     l_799
       =
       g_697
       [8]
       [0];
     l_1441
       =
       (safe_add_func_int32_t_s_s
        ((l_1440 = (safe_mod_func_int32_t_s_s ((((safe_mod_func_int16_t_s_s (l_1431, g_697[7][1])) ^ (safe_add_func_int16_t_s_s ((safe_sub_func_int32_t_s_s (g_1281, (safe_rshift_func_uint8_t_u_u (((g_513[3] & (l_1438[5][0][1] = (g_344 ^ (l_1403[9] = 0xB097F462L)))) == (0UL | (-1L))), 3)))), (l_1384[4] == p_58)))) < l_1439), l_1423[3][1]))), g_458));
   }
   l_1383
     =
     ((l_1457[0] = ((l_1444 = (safe_rshift_func_uint8_t_u_u ((l_1438[5][0][1] = l_1383), 2))) & (l_1379[2][3] = (l_1250 || ((0L <= (((safe_mul_func_uint16_t_u_u ((g_774 = (g_1265[2][5] || l_1440)), (!(l_1423[3][1] = (safe_mod_func_int16_t_s_s ((safe_add_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s (g_30, l_1453)), (l_1454 = 1L))), ((safe_sub_func_int16_t_s_s ((g_697[5][0] = p_57), 4UL)) ^ l_1441))))))) < g_71[3]) ^ l_1379[8][1])) < 1UL))))) ^ l_1403[0]);
 }
 else
 {
   uint32_t
     l_1468
     [4];
   int32_t
     l_1469
     =
     (-1L);
   int32_t
     l_1583
     [1]
     [9]
     [1]
     =
     {
 {{0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  ,
  {0xFF290BB2L}
  ,
  {0x6A1E0353L}
  }
   };
   int
     i,
     j,
     k;
   for
     (i
      =
      0;
      i
      <
      4;
      i++)
     l_1468
       [i]
       =
       0UL;
   l_1423
     [3]
     [1]
     =
     ((l_1441 = p_60) > (safe_add_func_int8_t_s_s ((g_344 = (safe_add_func_uint16_t_u_u (0UL, ((6UL || (l_1383 > p_58)) == (((safe_mul_func_uint8_t_u_u (g_866, 0x91L)) != ((safe_add_func_int8_t_s_s ((safe_sub_func_uint16_t_u_u ((l_1468[0] = (p_60 | p_60)), l_1469)), 0xBEL)) || g_1266)) < p_58))))), 0L)));
   if ((l_1470 & (safe_sub_func_int32_t_s_s (((((safe_sub_func_uint8_t_u_u (l_1475, l_609[0])) == p_59) ^ (safe_lshift_func_int16_t_s_u ((((safe_sub_func_int16_t_s_s ((safe_mod_func_int32_t_s_s (((g_555 = (0x0B1DL == p_60)) && g_71[7]), (safe_mul_func_uint8_t_u_u ((safe_lshift_func_int8_t_s_u ((g_344 = (p_60 != ((+(((safe_lshift_func_uint16_t_u_s (0xB105L, p_57)) >= p_57) < g_71[7])) && l_1441))), 2)), g_588)))), g_1281)) || g_697[8][0]) ^ p_59), g_920))) || l_1488), g_521))))
   {
     int8_t
       l_1503
       =
       0xE6L;
     l_1383
       =
       (safe_mul_func_uint8_t_u_u
        (p_60,
  p_57));
     l_1423
       [3]
       [1]
       =
       (+
        (!
  (safe_rshift_func_uint8_t_u_s
   (l_1468
    [0],
    ((g_513[2] < p_59) <= (safe_mul_func_int16_t_s_s (9L, (0x8FL < (l_1469 = (safe_sub_func_uint16_t_u_u (l_1497, ((safe_sub_func_int16_t_s_s ((g_697[8][0] = p_58), (g_521 = (-7L)))) != (safe_lshift_func_int16_t_s_u ((l_1502[1] & 8L), l_1502[1]))))))))))))));
     g_71
       [6]
       =
       (l_1503
        =
        g_588);
     if (g_697[8][0])
       break;
   }
   else
   {
     int32_t
       l_1524
       =
       0x6DC5B83AL;
     l_1441
       =
       l_1468
       [0];
     l_1469
       =
       ((p_58 = (safe_add_func_int32_t_s_s (((((((safe_mod_func_int8_t_s_s (((safe_lshift_func_uint8_t_u_u ((0x3CE0A1BCL < l_1188[7]), (safe_add_func_int8_t_s_s ((0x37L >= (((safe_add_func_int16_t_s_s ((+(!((safe_rshift_func_int16_t_s_u (((safe_sub_func_int16_t_s_s ((l_800 = ((safe_add_func_uint8_t_u_u ((safe_lshift_func_uint8_t_u_s ((l_609[0] | ((safe_lshift_func_uint16_t_u_s (l_1384[4], g_201)) | 0x06C8L)), 0)), 255UL)) || (((0x0530L == g_329[1][0][0]) >= 1UL) ^ g_1281))), g_721[5])) && 255UL), p_60)) < l_1524))), l_1438[1][0][1])) > l_1469) || p_59)), p_59)))) <= p_60), 0x7FL)) & g_721[3]) <= g_329[1][4][2]) == (-9L)) | p_58) & g_1266), l_1379[6][0]))) & p_57);
     if (g_458)
       continue;
     g_71
       [7]
       =
       g_978;
   }
   if ((safe_sub_func_uint32_t_u_u (p_57, ((g_329[1][0][0] = 1UL) > 0x4F799D86L))))
   {
     uint32_t
       l_1527
       =
       0x90FEEB0CL;
     g_71
       [7]
       =
       l_1527;
     l_1438
       [5]
       [0]
       [1]
       =
       (p_59
        >=
        (safe_mod_func_uint16_t_u_u
  (((safe_add_func_uint32_t_u_u (((safe_add_func_int16_t_s_s (l_1534, (g_555 >= (safe_rshift_func_uint8_t_u_u ((((l_1379[3][3] = (g_920 = ((l_1469 = (p_59 > (safe_rshift_func_uint16_t_u_s (((g_697[8][0] = (l_1423[0][1] < p_58)) ^ (safe_sub_func_uint32_t_u_u (0xC6944EA8L, 0x231AE895L))), (safe_mul_func_int16_t_s_s (((g_1266 = (safe_mul_func_uint16_t_u_u (0x4B84L, p_58))) == l_1468[1]), 0x7211L)))))) || l_1453))) > p_57) ^ g_669), l_1431))))) == p_60), 0UL)) ^ l_1384[4]), 0xEAF0L)));
     g_71
       [2]
       =
       ((p_57 <= ((safe_sub_func_int16_t_s_s ((l_1379[1][5] = 0x41B3L), (((0x44B3AF87L | g_30) && l_1431) == g_1382))) ^ (l_799 = (safe_sub_func_int16_t_s_s (g_721[3], ((0x8FL ^ p_60) == g_344)))))) || g_367);
     l_800
       =
       (g_71
        [7]
        =
        ((l_609[0] = (g_329[0][0][1] = ((safe_sub_func_int32_t_s_s ((safe_unary_minus_func_uint8_t_u (((safe_mul_func_int16_t_s_s (((safe_sub_func_int16_t_s_s (g_38, (l_1527 > ((safe_mod_func_int8_t_s_s ((g_344 = p_58), (safe_add_func_uint32_t_u_u (p_57, l_1527)))) >= 0xD928L)))) < ((safe_unary_minus_func_uint32_t_u ((safe_mod_func_uint8_t_u_u ((safe_mod_func_uint16_t_u_u (((~((((safe_unary_minus_func_uint16_t_u (l_1527)) > (~l_70[1][5][0])) || (safe_lshift_func_int8_t_s_s (((((((safe_add_func_uint32_t_u_u (((g_1266 < (-1L)) || p_59), 0xA3200367L)) > p_59) <= l_1364) & l_1527) != 0x2212L) && g_513[2]), l_1379[2][3]))) <= p_58)) <= p_58), g_329[0][6][2])), p_58)))) ^ l_1570)), p_57)) > l_1438[9][0][1]))), 0x19F76790L)) != 0L))) || p_58));
   }
   else
   {
     int32_t
       l_1571
       [3];
     int
       i;
     for
       (i
        =
        0;
        i
        <
        3;
        i++)
       l_1571
  [i]
  =
  1L;
     if (g_329[1][2][5])
       break;
     l_1475
       =
       (l_1571
        [0]
        =
        g_774);
     if (g_978)
       continue;
     l_1438
       [8]
       [0]
       [1]
       =
       ((safe_sub_func_uint8_t_u_u (((safe_lshift_func_int16_t_s_u (((safe_sub_func_uint8_t_u_u (((g_329[1][0][0] || (g_344 = l_1488)) == p_59), (l_1578 = g_3))) > 1UL), ((!((l_1188[g_458] | (((safe_rshift_func_uint8_t_u_u (l_1583[0][6][0], 2)) ^ p_59) >= (safe_sub_func_uint32_t_u_u (p_57, 0xF62CE792L)))) && l_1571[0])) == 0xC20AL))) < l_1453), p_59)) | l_70[1][2][0]);
   }
 }
 l_1379
   [7]
   [4]
   =
   l_1586;
 l_1379
   [2]
   [3]
   =
   (((0x463CL < (safe_mod_func_int8_t_s_s ((safe_mod_func_uint16_t_u_u ((!(safe_sub_func_int8_t_s_s (p_58, (safe_rshift_func_int8_t_s_u (l_1502[2], 0))))), (safe_mul_func_uint16_t_u_u ((safe_mul_func_uint8_t_u_u ((safe_rshift_func_uint8_t_u_s ((l_1578 != l_1423[3][1]), 4)), l_1601[1])), 65527UL)))), 0xF6L))) < ((((safe_mod_func_int8_t_s_s ((p_59 = ((safe_mod_func_int8_t_s_s (((g_588 && l_1422) >= g_201), l_1601[2])) <= p_58)), g_697[8][0])) & l_1364) < 0xA8L) || l_1384[6])) <= g_458);
      }
      for
 (l_1578
  =
  7;
  (l_1578
   >=
   0);
  l_1578
  -=
  1)
      {
 int32_t
   l_1622
   [4]
   =
   {
      (-9L),
      (-9L),
      (-9L),
      (-9L)
    };
 int
   i;
 if (p_57)
 {
   uint32_t
     l_1621
     =
     0x90FD25AAL;
   l_1379
     [1]
     [0]
     =
     g_697
     [8]
     [0];
   for
     (p_60
      =
      0;
      (p_60
       <=
       7);
      p_60
      +=
      1)
   {
     g_71
       [3]
       =
       (safe_sub_func_int32_t_s_s
        ((safe_mod_func_int16_t_s_s ((safe_mul_func_int8_t_s_s ((safe_rshift_func_uint16_t_u_s ((((g_588 = (g_329[1][0][0] ^ (safe_mod_func_int32_t_s_s (l_1616, 4294967295UL)))) | (((safe_rshift_func_int16_t_s_s (((safe_mod_func_uint8_t_u_u (5UL, (0x7FD0L && (l_1570 < l_1621)))) >= g_978), (0x1D61L || g_1265[3][4]))) & p_59) ^ g_721[0])) || (-5L)), p_60)), l_1622[1])), p_57)), g_1281));
     if (p_58)
       continue;
     if (l_1621)
       break;
     return
       l_1250;
   }
 }
 else
 {
   uint32_t
     l_1655
     =
     4294967295UL;
   int32_t
     l_1668
     =
     0x8E80973DL;
   if ((safe_sub_func_uint16_t_u_u ((((safe_mod_func_uint8_t_u_u (g_513[1], 1UL)) != l_1341) | (safe_add_func_int16_t_s_s ((safe_add_func_int8_t_s_s ((safe_rshift_func_int16_t_s_s (((safe_mul_func_uint16_t_u_u (((((safe_mod_func_int8_t_s_s ((safe_add_func_int16_t_s_s ((safe_mul_func_uint16_t_u_u (((+(((0xBC28A63EL <= ((g_329[1][0][0] || ((safe_rshift_func_uint8_t_u_u ((g_588 = (safe_mul_func_int8_t_s_s (((safe_lshift_func_int8_t_s_u ((safe_rshift_func_uint16_t_u_s ((safe_lshift_func_int8_t_s_u ((((0xC86CL & (safe_add_func_uint16_t_u_u (((((p_60 <= 2UL) < (((safe_add_func_int8_t_s_s ((!p_57), g_513[1])) | 0x25L) < g_38)) && (-1L)) < 0x351E1285L), 65535UL))) && 3L) < g_71[7]), 2)), 11)), l_1622[1])) <= (-3L)), p_57))), 0)) != g_367)) >= 0xAF39FF41L)) >= 1L) < p_58)) & (-8L)), l_1403[1])), p_58)), 0xECL)) < g_329[1][0][0]) < (-3L)) || g_721[3]), (-1L))) != l_1655), 7)), 1L)), p_57))), 0x4FDFL)))
   {
     int32_t
       l_1660
       =
       0L;
     int32_t
       l_1661
       [9]
       [5]
       =
       {
   {0xF3EECE38L,
    6L,
    0L,
    (-10L),
    0L}
     , {(-10L), (-10L), 0xB8A18AEDL, (-8L), 4L}
     , {0x7ED8E6F0L, 0x4FFD6CFCL, 0xB8A18AEDL, 0L, 0xF3EECE38L}
     , {(-1L), 0xB8A18AEDL, 0L, 0xB8A18AEDL, (-1L)}
     , {(-8L), 0x4FFD6CFCL, 4L, (-1L), (-10L)}
     , {(-8L), (-10L), 0xF3EECE38L, 0x5F042651L, 0x5F042651L}
     , {(-1L), 6L, (-1L), 0x4FFD6CFCL, (-10L)}
     , {0x7ED8E6F0L, 0x5F042651L, (-10L), 0x4FFD6CFCL, (-1L)}
     , {(-10L), 0xF3EECE38L, 0x5F042651L, 0x5F042651L, 0xF3EECE38L}
     };
     int
       i,
       j;
     l_1668
       =
       ((l_1438[5][0][1] != (l_1622[1] = ((l_800 = (l_1661[8][1] = (safe_lshift_func_uint8_t_u_s ((safe_mod_func_uint32_t_u_u (g_930, l_1660)), 7)))) && (+l_1379[2][3])))) ^ ((safe_lshift_func_int16_t_s_u (((safe_add_func_int32_t_s_s (g_658, (g_513[1] <= ((g_697[5][1] <= (((((-3L) || (safe_lshift_func_uint8_t_u_u (g_920, p_57))) < 0x61L) && g_555) ^ p_57)) < l_1616)))) > l_1403[1]), 4)) | 0x1AL));
     l_1622
       [1]
       =
       p_58;
   }
   else
   {
     uint8_t
       l_1685
       =
       1UL;
     g_71
       [7]
       =
       9L;
     g_71
       [7]
       =
       ((p_59 || (safe_mul_func_uint8_t_u_u ((safe_sub_func_uint32_t_u_u (((((g_513[1] ^ (l_1685 = ((+((~(0xD9D52541L & (safe_add_func_int16_t_s_s (g_521, (safe_add_func_int32_t_s_s ((safe_mul_func_int16_t_s_s ((safe_mod_func_uint32_t_u_u ((((safe_sub_func_uint32_t_u_u (((0xA7L < (~(((-7L) & ((safe_rshift_func_uint8_t_u_u (((p_60 <= p_59) & l_1622[3]), 4)) && g_201)) ^ g_721[2]))) | p_58), l_1441)) < l_1379[2][3]) != 0UL), l_799)), p_57)), g_774)))))) || 0xCBC7BAA7L)) == 1UL))) <= l_1616) < 0xFCAE371CL) | p_60), p_60)), 0x22L))) | 0x96L);
   }
   if (((safe_rshift_func_int8_t_s_s (((safe_add_func_uint16_t_u_u ((g_1281 & p_57), (safe_rshift_func_int8_t_s_s (((safe_add_func_uint8_t_u_u ((((l_67 || (((safe_add_func_uint8_t_u_u (((p_60 ^ (safe_lshift_func_int8_t_s_s ((safe_add_func_uint32_t_u_u ((safe_rshift_func_uint8_t_u_s (g_329[1][0][0], (g_930 = (safe_lshift_func_int8_t_s_s ((safe_sub_func_uint32_t_u_u (l_1431, (safe_mul_func_uint16_t_u_u (((safe_mul_func_int16_t_s_s ((safe_rshift_func_int16_t_s_u ((l_1601[2] == ((safe_add_func_int8_t_s_s (((!g_300) || ((g_555 < g_3) ^ 0x16L)), 0xDAL)) & p_59)), g_329[1][0][0])), 7UL)) ^ p_57), p_57)))), l_1622[0]))))), p_60)), p_58))) ^ l_1622[2]), l_1578)) != 3L) & 0xCC7C2B67L)) < p_59) != 0x96F0A4A3L), g_866)) > (-1L)), 1)))) < 4UL), 7)) != 0x913DE694L))
   {
     int16_t
       l_1732
       =
       0x0AABL;
     int32_t
       l_1733
       =
       1L;
     l_1733
       =
       ((safe_mod_func_int16_t_s_s ((safe_add_func_int8_t_s_s ((safe_mod_func_uint32_t_u_u ((safe_mod_func_uint16_t_u_u ((l_1379[9][0] = ((safe_mod_func_int32_t_s_s ((safe_sub_func_int16_t_s_s (0L, g_1265[2][5])), (((((0xDADA1386L != (0UL != ((g_71[3] = (safe_sub_func_int32_t_s_s (g_774, (safe_rshift_func_int16_t_s_s ((g_300 != (((g_344 = (((safe_sub_func_uint16_t_u_u (p_58, g_920)) > (p_59 || g_697[5][0])) <= g_920)) < p_57) || g_521)), 9))))) && p_60))) || g_71[7]) ^ l_1586) == l_1622[1]) & p_59))) || l_1732)), l_1622[1])), 7UL)), l_1534)), 0x2CAFL)) != 0x663D3C7BL);
   }
   else
   {
     if (p_57)
       break;
   }
 }
 g_71
   [4]
   =
   (safe_mod_func_uint16_t_u_u
    ((((p_60 & ((safe_lshift_func_int16_t_s_u ((((safe_mod_func_uint8_t_u_u (((((safe_add_func_int16_t_s_s ((g_513[1] || (safe_mul_func_int16_t_s_s ((((l_799 = (g_329[1][0][0] = (l_1744 = p_59))) < (l_1438[5][0][0] = ((p_60 > ((safe_rshift_func_uint16_t_u_s ((g_513[5] <= (safe_lshift_func_uint8_t_u_u ((g_588 = (safe_rshift_func_uint16_t_u_s (((safe_sub_func_uint8_t_u_u ((((l_800 = p_60) & (safe_mul_func_uint16_t_u_u ((safe_mul_func_int8_t_s_s ((safe_mul_func_int8_t_s_s (((p_57 == ((safe_rshift_func_uint8_t_u_u (g_38, p_57)) >= p_60)) < p_58), g_920)), p_60)), g_521))) & p_60), 0x5CL)) || 0x8BL), 2))), p_60))), 8)) | p_59)) < p_58))) ^ l_1570), 0xD07CL))), 0x282FL)) == l_1364) ^ 0xF4L) != 0x0542L), 0xA2L)) <= 1UL) | 0xE807L), 2)) & 4L)) == g_513[1]) || l_1431), g_866));
      }
    }
      for
 (p_58
  =
  1;
  (p_58
   <=
   7);
  p_58
  +=
  1)
      {
 uint16_t
   l_1851
   =
   0xC774L;
 int32_t
   l_1885
   =
   (-1L);
 int32_t
   l_1931
   =
   0xC09AA10AL;
 int32_t
   l_1998
   =
   0x8EBFCBCBL;
 if ((g_1763 = (((safe_lshift_func_int16_t_s_s ((p_59 && 253UL), g_458)) < p_59) ^ p_59)))
 {
   uint8_t
     l_1850
     [6]
     =
     {
 3UL,
 3UL,
 0x2CL,
 3UL,
 3UL,
 0x2CL
      };
   int32_t
     l_1887
     =
     0xFE3DFA66L;
   int
     i;
for
      (i
       =
       0;
       i
       <
       3;
       i++)
      l_1601
 [i]
 =
 0xB24DL;
 }
 else
 {
   int16_t
     l_1956
     =
     2L;
   if ((g_1782 = ((0x45L || ((safe_sub_func_uint16_t_u_u ((safe_mod_func_int32_t_s_s ((p_57 < ((safe_mul_func_int8_t_s_s ((!g_1810[0]), p_60)) > ((safe_lshift_func_int8_t_s_s ((safe_unary_minus_func_int16_t_s ((((((((0x47AAL > (l_1931 = (l_800 = ((safe_mul_func_int8_t_s_s (l_1851, g_721[8])) > (l_1438[5][0][1] = g_721[3]))))) == l_1851) && g_774) | p_57) && p_59) && p_57) || p_59))), p_58)) != g_38))), 0x3FBAB0A6L)), 2L)) || 0x35047D49L)) >= g_555)))
   {
     uint32_t
       l_1969
       =
       7UL;
     l_1969
       =
       ((l_1403[1] = ((safe_add_func_int8_t_s_s ((safe_lshift_func_int8_t_s_u ((safe_sub_func_uint32_t_u_u ((safe_add_func_uint32_t_u_u ((g_38 | (safe_rshift_func_int16_t_s_u (((safe_unary_minus_func_int16_t_s ((safe_add_func_uint8_t_u_u (((-6L) ^ ((l_1438[3][0][1] = (((p_59 > (0xCEL <= 7UL)) && l_1956) > (safe_mul_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (65527UL, (g_555 = ((safe_rshift_func_int16_t_s_u ((safe_sub_func_uint32_t_u_u ((safe_add_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (g_1266, ((p_57 || p_58) && 1UL))), l_1885)), g_721[3])), g_721[3])) > 65535UL)))), p_59)))) > l_1834)), g_920)))) ^ (-6L)), g_721[3]))), p_60)), l_1341)), 5)), g_920)) ^ p_59)) ^ (-1L));
for
      (l_1250
       =
       2;
       (l_1250
 <=
 7);
       l_1250
       +=
       1)
    {
      uint32_t
 l_1852
 [6]
 [8]
 =
 {
   {0x581A6F4DL,
    1UL,
    1UL,
    0x581A6F4DL,
    0UL,
    4UL,
    0UL,
    4294967291UL}
      , {0UL, 0x492D247CL, 0x36109862L, 1UL, 4UL, 1UL, 0xFE55C8BFL, 1UL}
      , {1UL, 0x492D247CL, 0xBCE9244FL, 0x10EA97E1L, 0x36109862L, 4UL, 0x36109862L, 0x10EA97E1L}
      , {0xAE0CAB6DL, 1UL, 0xAE0CAB6DL, 0x6E6D3266L, 0xCD5D87ACL, 0x10EA97E1L, 0x581A6F4DL, 0x36109862L}
      , {0UL, 0x36109862L, 0UL, 4294967295UL, 1UL, 8UL, 0xCD5D87ACL, 0x492D247CL}
      , {0UL, 0xBCE9244FL, 8UL, 0x66C191B3L, 0xCD5D87ACL, 0xCD5D87ACL, 0x66C191B3L, 8UL}
      };
      int32_t
 l_1874
 [3];
      int8_t
 l_1988
 =
 1L;
      int
 i,
        j;
      for
 (i
  =
  0;
  i
  <
  3;
  i++)
 l_1874
   [i]
   =
   0x494C9DE3L;
      for
 (p_58
  =
  1;
  (p_58
   <=
   7);
  p_58
  +=
  1)
      {
 uint16_t
   l_1851
   =
   0xC774L;
 int32_t
   l_1885
   =
   (-1L);
 int32_t
   l_1931
   =
   0xC09AA10AL;
 int32_t
   l_1998
   =
   0x8EBFCBCBL;
 if ((g_1763 = (((safe_lshift_func_int16_t_s_s ((p_59 && 253UL), g_458)) < p_59) ^ p_59)))
 {
   uint8_t
     l_1850
     [6]
     =
     {
 3UL,
 3UL,
 0x2CL,
 3UL,
 3UL,
 0x2CL
      };
   int32_t
     l_1887
     =
     0xFE3DFA66L;
   int
     i;
   for
     (g_555
      =
      1;
      (g_555
       <=
       7);
      g_555
      +=
      1)
   {
     int
       i;
     l_1850
       [0]
       =
       (~
        (safe_add_func_int32_t_s_s
  (g_721
   [(l_1250 + 1)], 4294967291UL)));
     l_1833
       =
       (l_1851
        =
        g_1265
        [2]
        [3]);
     l_1852
       [5]
       [7]
       =
       (g_920
        &
        0UL);
   }
   if (p_59)
   {
     int8_t
       l_1875
       =
       0xCBL;
     int32_t
       l_1876
       =
       7L;
     l_1876
       =
       (safe_mul_func_int16_t_s_s
        ((safe_add_func_int16_t_s_s ((safe_rshift_func_uint8_t_u_u (((p_57 ^ ((safe_sub_func_int8_t_s_s ((g_930 = ((l_1850[4] || (safe_rshift_func_uint16_t_u_s (p_57, 8))) & ((p_57 || ((safe_rshift_func_uint16_t_u_s ((l_1341 ^ (safe_lshift_func_int16_t_s_u (p_60, g_458))), ((safe_unary_minus_func_uint8_t_u ((safe_mod_func_int8_t_s_s ((p_59 = (safe_mul_func_uint8_t_u_u (((safe_lshift_func_uint8_t_u_s ((0x1DC9L != ((l_1874[1] = (p_58 >= p_60)) || p_60)), g_1763)) > p_58), 0x59L))), p_58)))) > l_1875))) >= g_300)) == l_1850[0]))), p_60)) & l_1341)) > l_1850[0]), l_1852[5][7])), g_300)), p_60));
     return
       g_300;
   }
   else
   {
     uint16_t
       l_1886
       =
       0xA075L;
     l_1885
       =
       (g_1835
        [0]
        [4]
        [1]
        |
        ((safe_add_func_int8_t_s_s (g_1382, l_67)) > (g_521 = ((safe_mul_func_int8_t_s_s (((safe_lshift_func_int8_t_s_s ((safe_lshift_func_int8_t_s_u (g_774, 4)), 5)) <= (p_58 > g_658)), g_329[1][0][0])) ^ 0x231BL))));
     l_1886
       =
       p_59;
     l_1887
       =
       p_60;
   }
   if ((safe_sub_func_uint32_t_u_u (((safe_add_func_int32_t_s_s (0x0C94DF4DL, ((g_71[8] <= 0x2A2FD7B7L) > (((safe_mod_func_uint16_t_u_u ((safe_lshift_func_int16_t_s_u (p_58, (p_58 || g_1281))), l_1441)) == (p_60 <= (safe_lshift_func_uint16_t_u_s (((((safe_rshift_func_uint16_t_u_s (((safe_mul_func_int16_t_s_s ((safe_mul_func_uint8_t_u_u ((l_1438[5][0][1] = 9UL), l_609[0])), l_1502[1])) | l_1885), l_1887)) && 0L) <= g_866) ^ 0x1EL), 2)))) > 0x16DAL)))) | g_930), 0x0FE39029L)))
   {
     uint16_t
       l_1910
       =
       65535UL;
     l_1874
       [0]
       =
       l_1852
       [3]
       [0];
     l_1887
       =
       (l_799
        =
        (g_71
  [4]
  =
  ((safe_sub_func_uint32_t_u_u ((safe_lshift_func_uint8_t_u_u ((safe_lshift_func_uint16_t_u_u (1UL, 8)), 4)), l_1887)) > p_57)));
     return
       l_1910;
   }
   else
   {
     uint16_t
       l_1930
       =
       0x5864L;
     g_1917
       =
       (p_60
        >
        (safe_sub_func_uint8_t_u_u
  ((g_588 = 0xB1L), (safe_mul_func_int8_t_s_s (1L, ((g_344 = (safe_mod_func_int8_t_s_s (g_71[8], 255UL))) <= 0x12L))))));
     l_1931
       =
       (((g_201 ^ 0x44L) | (safe_sub_func_int8_t_s_s ((safe_lshift_func_uint16_t_u_s ((safe_mod_func_uint32_t_u_u (((safe_lshift_func_int16_t_s_u ((((safe_rshift_func_int16_t_s_s ((l_1887 = (g_521 & (l_1885 = ((safe_rshift_func_int8_t_s_u (g_658, (g_1917 = 8UL))) < (p_60 < l_1930))))), 5)) ^ 0x95167045L) || (p_58 != p_57)), 2)) < 0x093B234CL), 8L)), p_58)), 0xA0L))) ^ 0x0BL);
   }
 }
 else
 {
   int16_t
     l_1956
     =
     2L;
   if ((g_1782 = ((0x45L || ((safe_sub_func_uint16_t_u_u ((safe_mod_func_int32_t_s_s ((p_57 < ((safe_mul_func_int8_t_s_s ((!g_1810[0]), p_60)) > ((safe_lshift_func_int8_t_s_s ((safe_unary_minus_func_int16_t_s ((((((((0x47AAL > (l_1931 = (l_800 = ((safe_mul_func_int8_t_s_s (l_1851, g_721[8])) > (l_1438[5][0][1] = g_721[3]))))) == l_1851) && g_774) | p_57) && p_59) && p_57) || p_59))), p_58)) != g_38))), 0x3FBAB0A6L)), 2L)) || 0x35047D49L)) >= g_555)))
   {
     uint32_t
       l_1969
       =
       7UL;
     l_1969
       =
       ((l_1403[1] = ((safe_add_func_int8_t_s_s ((safe_lshift_func_int8_t_s_u ((safe_sub_func_uint32_t_u_u ((safe_add_func_uint32_t_u_u ((g_38 | (safe_rshift_func_int16_t_s_u (((safe_unary_minus_func_int16_t_s ((safe_add_func_uint8_t_u_u (((-6L) ^ ((l_1438[3][0][1] = (((p_59 > (0xCEL <= 7UL)) && l_1956) > (safe_mul_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (65527UL, (g_555 = ((safe_rshift_func_int16_t_s_u ((safe_sub_func_uint32_t_u_u ((safe_add_func_uint16_t_u_u ((safe_mul_func_uint16_t_u_u (g_1266, ((p_57 || p_58) && 1UL))), l_1885)), g_721[3])), g_721[3])) > 65535UL)))), p_59)))) > l_1834)), g_920)))) ^ (-6L)), g_721[3]))), p_60)), l_1341)), 5)), g_920)) ^ p_59)) ^ (-1L));
   }
   else
   {
     uint16_t
       l_1987
       =
       0xDE63L;
     g_1782
       =
       (safe_rshift_func_uint8_t_u_u
        (((safe_rshift_func_uint16_t_u_s ((safe_lshift_func_uint8_t_u_u ((safe_mul_func_int16_t_s_s ((g_521 = (((((((safe_lshift_func_uint8_t_u_u (g_1810[0], (l_1885 = (g_1917 = 0x68L)))) != l_1931) ^ (safe_rshift_func_uint8_t_u_s ((g_300 < ((((safe_rshift_func_uint16_t_u_s ((((safe_add_func_int32_t_s_s (g_1382, (0x6C6CE11BL && (g_71[6] = l_1851)))) ^ (0UL == (safe_unary_minus_func_uint16_t_u (1UL)))) < l_1852[5][7]), p_59)) | l_1987) == p_57) >= 0x3D2E901BL)), l_1403[1]))) == l_1987) == l_1956) != 0xB9A4CA4FL) && 0x32072BDCL)), p_59)), p_59)), l_1987)) < l_1988), 1));
   }
 }
 l_1931
   =
   (safe_rshift_func_uint8_t_u_u
    (((((safe_add_func_int8_t_s_s ((safe_mul_func_int8_t_s_s ((p_58 == ((g_1995 && (safe_rshift_func_int16_t_s_u ((0UL == (((l_1998 = l_1874[2]) == ((((safe_rshift_func_int16_t_s_s ((((g_344 = (((((p_59 = ((0x2FL | (l_1874[1] || (g_513[1] | l_1851))) > ((safe_rshift_func_int16_t_s_s ((l_1885 < l_1885), 13)) != l_2003))) >= (-1L)) != g_721[3]) ^ p_57) & g_1763)) && p_57) == l_1834), g_367)) > 0L) || p_57) ^ g_201)) | l_1250)), p_57))) || 65535UL)), p_58)), g_1810[0])) && g_588) ^ g_2004[0][0][2]) >= p_57), p_58));
      }
      g_1763
 =
 (g_71
  [1]
  =
  (safe_sub_func_uint8_t_u_u
   ((g_367 < 0x72D05B16L), (g_344 = (((l_800 = ((safe_mul_func_uint16_t_u_u ((l_609[0] = ((safe_add_func_int16_t_s_s ((0xF771L ^ (p_58 = ((safe_sub_func_int32_t_s_s ((p_59 | (safe_mul_func_uint16_t_u_u (((l_1833 = ((0L & p_57) & p_59)) & ((g_513[1] = (safe_add_func_uint16_t_u_u (l_1852[5][7], p_59))) < (-1L))), 0x8011L))), l_1570)) && l_1384[4]))), 0x3F64L)) | p_59)), l_1852[5][7])) != p_57)) | l_1874[1]) & l_1988)))));
    }
   }
   else
   {
     uint16_t
       l_1987
       =
       0xDE63L;
   }
for
      (i
       =
       0;
       i
       <
       3;
       i++)
      l_1601
 [i]
 =
 0xB24DL;
 }
      }
    }
for
    (i
     =
     0;
     i
     <
     1;
     i++)
    l_609
      [i]
      =
      (-3L);
  }
l_609
    [0]
    =
    g_329
    [1]
    [0]
    [5];
  return
    g_588;
}
static int32_t
func_72
  (uint8_t
   p_73,
   int8_t
   p_74,
   uint8_t
   p_75
)
{
  int8_t
    l_81
    =
    0xE5L;
  int32_t
    l_87
    =
    (-8L);
  int32_t
    l_90
    =
    8L;
  int32_t
    l_100
    =
    0L;
  int32_t
    l_119
    =
    0L;
  uint8_t
    l_206
    =
    1UL;
  int8_t
    l_368
    =
    (-1L);
  uint32_t
    l_396
    =
    4294967295UL;
  int32_t
    l_589
    [8]
    =
    {
0xE9ACBB18L,
0L,
0xE9ACBB18L,
0L,
0xE9ACBB18L,
0L,
0xE9ACBB18L,
0L
  };
  int
    i;
  if ((((safe_lshift_func_int8_t_s_u ((l_81 < (((safe_lshift_func_uint8_t_u_s (2UL, (safe_lshift_func_int16_t_s_u (((l_81 == (g_71[7] == (safe_unary_minus_func_int32_t_s (g_38)))) ^ (l_87 = (0x35L || 0L))), ((l_90 = ((safe_rshift_func_int16_t_s_s (l_81, p_73)) || l_81)) ^ l_81))))) | (-1L)) | p_73)), l_81)) > 5L) ^ l_81))
  {
    return
      g_30;
  }
  else
  {
    int32_t
      l_99
      =
      0xE9F33C75L;
    int16_t
      l_101
      [9]
      [7]
      =
      {
  {(-4L), 0x15E6L, 0L, 0xDD8BL, 0x2FD9L, 0x2FD9L, 0xDD8BL}
    , {1L, 0x9C18L, 1L, 0xDD8BL, 0L, 0xD316L, 0x9C18L}
    , {0xDD8BL, 0L, 0x5451L, 0xB2F3L, (-1L), 0xDD8BL, 0x143DL}
    , {0xB829L, 0xC2B2L, 0L, 1L, 0x143DL, 0xD316L, 0x15E6L}
    , {(-4L), 0x2FD9L, (-1L), 0xC8D5L, (-1L), 0x2FD9L, (-4L)}
    , {(-4L), 0L, (-1L), 0xC2B2L, 0x2FD9L, 0L, (-1L)}
    , {0xB829L, (-1L), 1L, 0x15E6L, 0xDD8BL, (-9L), (-1L)}
    , {0xDD8BL, 0x143DL, (-1L), 0L, 6L, 0xDD8BL, 6L}
    , {1L, (-1L), (-1L), 1L, 6L, (-1L), 0xC2B2L}
    };
    uint16_t
      l_106
      =
      0xCA57L;
    int32_t
      l_163
      =
      0L;
    int32_t
      l_164
      [7]
      [10]
      =
      {
  {0L,
   0L,
   0L,
   4L,
   0x2188DBB9L,
   (-7L),
   0x871B159BL,
   (-8L),
   6L,
   (-10L)}
    , {0x3AD0E752L, 0x2188DBB9L, 0x577B4CA1L, 0xC0AAE426L, 0x8632A430L, 0L, 0L, 0x8632A430L, 0xC0AAE426L, 0x577B4CA1L}
    , {0x2188DBB9L, 0x2188DBB9L, 5L, 0x9EE7A1AEL, (-10L), 0xBD9B2BB3L, 0L, 0x577B4CA1L, 0x9EE7A1AEL, (-8L)}
    , {(-1L), 0x2188DBB9L, (-10L), (-1L), 0x577B4CA1L, 0x3AD0E752L, 0L, 5L, (-1L), 5L}
    , {0L, 0x2188DBB9L, (-8L), (-1L), (-8L), 0x2188DBB9L, 0L, (-10L), (-1L), 0x8632A430L}
    , {0xBD9B2BB3L, 0x2188DBB9L, 0x8632A430L, 6L, 5L, (-1L), 0L, (-8L), 6L, (-10L)}
    , {0x3AD0E752L, 0x2188DBB9L, 0x577B4CA1L, 0xC0AAE426L, 0x8632A430L, 0L, 0L, 0x8632A430L, 0xC0AAE426L, 0x577B4CA1L}
    };
    uint16_t
      l_197
      =
      0UL;
    uint32_t
      l_229
      =
      8UL;
    uint32_t
      l_251
      [1]
      [5]
      [9]
      =
      {
 {{0UL, 0xB73B3AB4L, 0x81276FF5L, 0x70C91F96L, 0xB73B3AB4L, 0xAA67D54BL, 0x617A3C90L, 0UL, 4294967293UL}
  ,
  {0UL,
   0UL,
   0UL,
   0UL,
   4294967286UL,
   4294967293UL,
   4294967286UL,
   0UL,
   0UL}
  ,
  {4294967286UL,
   4294967286UL,
   0UL,
   0xB73B3AB4L,
   4294967295UL,
   4294967293UL,
   0x617A3C90L,
   4294967286UL,
   1UL}
  ,
  {0UL,
   0UL,
   1UL,
   0xB73B3AB4L,
   4294967286UL,
   0xAA67D54BL,
   0UL,
   0UL,
   0xAA67D54BL}
  ,
  {0xB73B3AB4L,
   0UL,
   0UL,
   0UL,
   0xB73B3AB4L,
   0x81276FF5L,
   0x70C91F96L,
   0xB73B3AB4L,
   0xAA67D54BL}
  }
    };
    int16_t
      l_297
      =
      (-1L);
    int32_t
      l_318
      =
      0xA3F3ABE0L;
    int
      i,
      j,
      k;
    l_100
      =
      ((safe_add_func_uint32_t_u_u (((safe_mul_func_int16_t_s_s (((1L < g_38) != ((((((6L < (((0xA1L ^ (safe_mul_func_uint16_t_u_u (g_71[7], g_71[2]))) < g_71[5]) <= (0x2BL == (safe_rshift_func_int16_t_s_u (g_3, g_30))))) == (-1L)) >= 0x27C38D1EL) <= p_73) != 0x76A2L) ^ l_99)), g_30)) >= g_30), g_71[7])) >= 1UL);
{
    return
      g_30;
  }
    g_71
      [8]
      =
      l_101
      [2]
      [6];
g_71
      [8]
      =
      l_101
      [2]
      [6];
    for
      (l_81
       =
       0;
       (l_81
 >
 27);
       l_81++)
    {
      int32_t
 l_117
 =
 0x5EE0523CL;
      uint16_t
 l_162
 =
 65535UL;
      int32_t
 l_166
 =
 1L;
      int32_t
 l_196
 =
 0xA00D3CD3L;
      uint16_t
 l_199
 =
 0xDA1EL;
      int32_t
 l_320
 =
 0L;
      for
 (l_90
  =
  (-4);
  (l_90
   <=
   2);
  ++l_90)
      {
 uint16_t
   l_118
   =
   0x4CEAL;
g_71
      [8]
      =
      l_101
      [2]
      [6];
 l_87
   =
   (~
    ((safe_unary_minus_func_int8_t_s (g_71[1])) == 3L));
      }
    }
g_71
      [8]
      =
      l_101
      [2]
      [6];
    l_164
      [3]
      [6]
      =
      (!
       (((safe_mod_func_int16_t_s_s ((l_90 = (((-1L) <= p_73) & (l_368 = (safe_lshift_func_uint8_t_u_s ((l_90 < (safe_add_func_uint8_t_u_u ((p_74 & (safe_sub_func_int16_t_s_s ((g_38 <= ((!(0x7FC3L || (g_367 = (safe_mod_func_int16_t_s_s ((safe_unary_minus_func_uint16_t_u ((l_99 = (l_90 == (l_100 = g_329[1][0][0]))))), ((safe_add_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s ((l_87 = (safe_sub_func_int32_t_s_s ((safe_lshift_func_uint16_t_u_u ((safe_mul_func_int16_t_s_s (0xEC5AL, 0x6C7FL)), 7)), g_201))), g_329[1][0][0])), 65535UL)) ^ g_71[4])))))) <= 4L)), 65526UL))), g_344))), g_344))))), 0x61ADL)) | l_81) || 0x3E26L));
{
    return
      g_30;
  }
  }
  l_589
    [2]
    =
    ((g_300 = (((((safe_rshift_func_int8_t_s_s ((-10L), 2)) | ((safe_add_func_uint8_t_u_u (((l_87 = (safe_mod_func_uint16_t_u_u ((g_588 = (p_75 >= ((g_71[7] = (safe_sub_func_int8_t_s_s (g_555, (safe_mul_func_int16_t_s_s (0x59CAL, (l_90 = (safe_mod_func_int16_t_s_s ((g_555 ^ (((safe_lshift_func_int16_t_s_u (g_201, 14)) > (l_100 = l_100)) || (g_367 && p_73))), l_396)))))))) ^ g_521))), 0x6CE4L))) | g_30), g_521)) >= p_75)) < 0x37L) && p_74) > l_81)) | 0x4B3B9A81L);
  return
    l_206;
}
static uint16_t
func_77
  (uint32_t
   p_78
)
{
  return
    g_71
    [7];
}
int
main (void
)
{
  int
    i,
    j,
    k;
  int
    print_hash_value
    =
    0;
  platform_main_begin
    ();
  crc32_gentab
    ();
  func_1
    ();
  transparent_crc
    (g_3,
     "g_3",
     print_hash_value);
  transparent_crc
    (g_30,
     "g_30",
     print_hash_value);
  transparent_crc
    (g_38,
     "g_38",
     print_hash_value);
  transparent_crc
    (g_54,
     "g_54",
     print_hash_value);
  for
    (i
     =
     0;
     i
     <
     9;
     i++)
  {
    transparent_crc
      (g_71
       [i],
       "g_71[i]",
       print_hash_value);
    if (print_hash_value)
      printf
 ("index = [%d]\n",
  i);
  }
  transparent_crc
    (g_201,
     "g_201",
     print_hash_value);
  transparent_crc
    (g_300,
     "g_300",
     print_hash_value);
  for
    (i
     =
     0;
     i
     <
     2;
     i++)
  {
    for
      (j
       =
       0;
       j
       <
       7;
       j++)
    {
      for
 (k
  =
  0;
  k
  <
  6;
  k++)
      {
 transparent_crc
   (g_329
    [i]
    [j]
    [k],
    "g_329[i][j][k]",
    print_hash_value);
 if (print_hash_value)
   printf
     ("index = [%d][%d][%d]\n",
      i,
      j,
      k);
      }
    }
  }
  transparent_crc
    (g_344,
     "g_344",
     print_hash_value);
  transparent_crc
    (g_367,
     "g_367",
     print_hash_value);
  transparent_crc
    (g_458,
     "g_458",
     print_hash_value);
  for
    (i
     =
     0;
     i
     <
     7;
     i++)
  {
    transparent_crc
      (g_513
       [i],
       "g_513[i]",
       print_hash_value);
    if (print_hash_value)
      printf
 ("index = [%d]\n",
  i);
  }
  transparent_crc
    (g_521,
     "g_521",
     print_hash_value);
  transparent_crc
    (g_555,
     "g_555",
     print_hash_value);
  transparent_crc
    (g_588,
     "g_588",
     print_hash_value);
  transparent_crc
    (g_658,
     "g_658",
     print_hash_value);
  transparent_crc
    (g_669,
     "g_669",
     print_hash_value);
  for
    (i
     =
     0;
     i
     <
     9;
     i++)
  {
    for
      (j
       =
       0;
       j
       <
       2;
       j++)
    {
      transparent_crc
 (g_697
  [i]
  [j],
  "g_697[i][j]",
  print_hash_value);
      if (print_hash_value)
 printf
   ("index = [%d][%d]\n",
    i,
    j);
    }
  }
  for
    (i
     =
     0;
     i
     <
     10;
     i++)
  {
    transparent_crc
      (g_721
       [i],
       "g_721[i]",
       print_hash_value);
    if (print_hash_value)
      printf
 ("index = [%d]\n",
  i);
  }
  transparent_crc
    (g_774,
     "g_774",
     print_hash_value);
  transparent_crc
    (g_866,
     "g_866",
     print_hash_value);
  transparent_crc
    (g_920,
     "g_920",
     print_hash_value);
  transparent_crc
    (g_930,
     "g_930",
     print_hash_value);
  transparent_crc
    (g_978,
     "g_978",
     print_hash_value);
  for
    (i
     =
     0;
     i
     <
     5;
     i++)
  {
    for
      (j
       =
       0;
       j
       <
       8;
       j++)
    {
      transparent_crc
 (g_1265
  [i]
  [j],
  "g_1265[i][j]",
  print_hash_value);
      if (print_hash_value)
 printf
   ("index = [%d][%d]\n",
    i,
    j);
    }
  }
  transparent_crc
    (g_1266,
     "g_1266",
     print_hash_value);
  transparent_crc
    (g_1281,
     "g_1281",
     print_hash_value);
  transparent_crc
    (g_1382,
     "g_1382",
     print_hash_value);
  transparent_crc
    (g_1763,
     "g_1763",
     print_hash_value);
  transparent_crc
    (g_1782,
     "g_1782",
     print_hash_value);
  for
    (i
     =
     0;
     i
     <
     1;
     i++)
  {
    transparent_crc
      (g_1810
       [i],
       "g_1810[i]",
       print_hash_value);
    if (print_hash_value)
      printf
 ("index = [%d]\n",
  i);
  }
  for
    (i
     =
     0;
     i
     <
     1;
     i++)
  {
    for
      (j
       =
       0;
       j
       <
       7;
       j++)
    {
      for
 (k
  =
  0;
  k
  <
  5;
  k++)
      {
 transparent_crc
   (g_1835
    [i]
    [j]
    [k],
    "g_1835[i][j][k]",
    print_hash_value);
 if (print_hash_value)
   printf
     ("index = [%d][%d][%d]\n",
      i,
      j,
      k);
      }
    }
  }
  transparent_crc
    (g_1917,
     "g_1917",
     print_hash_value);
  transparent_crc
    (g_1995,
     "g_1995",
     print_hash_value);
  for
    (i
     =
     0;
     i
     <
     7;
     i++)
  {
    for
      (j
       =
       0;
       j
       <
       1;
       j++)
    {
      for
 (k
  =
  0;
  k
  <
  10;
  k++)
      {
 transparent_crc
   (g_2004
    [i]
    [j]
    [k],
    "g_2004[i][j][k]",
    print_hash_value);
 if (print_hash_value)
   printf
     ("index = [%d][%d][%d]\n",
      i,
      j,
      k);
      }
    }
  }
  transparent_crc
    (g_2065,
     "g_2065",
     print_hash_value);
  for
    (i
     =
     0;
     i
     <
     9;
     i++)
  {
    transparent_crc
      (g_2066
       [i],
       "g_2066[i]",
       print_hash_value);
    if (print_hash_value)
      printf
 ("index = [%d]\n",
  i);
  }
  transparent_crc
    (g_2248,
     "g_2248",
     print_hash_value);
  transparent_crc
    (g_2373,
     "g_2373",
     print_hash_value);
  for
    (i
     =
     0;
     i
     <
     2;
     i++)
  {
    transparent_crc
      (g_2388
       [i],
       "g_2388[i]",
       print_hash_value);
    if (print_hash_value)
      printf
 ("index = [%d]\n",
  i);
  }
  transparent_crc
    (g_2580,
     "g_2580",
     print_hash_value);
  transparent_crc
    (g_2617,
     "g_2617",
     print_hash_value);
  transparent_crc
    (g_3117,
     "g_3117",
     print_hash_value);
  transparent_crc
    (g_3350,
     "g_3350",
     print_hash_value);
  transparent_crc
    (g_3691,
     "g_3691",
     print_hash_value);
  transparent_crc
    (g_3847,
     "g_3847",
     print_hash_value);
  transparent_crc
    (g_4401,
     "g_4401",
     print_hash_value);
  transparent_crc
    (g_4460,
     "g_4460",
     print_hash_value);
  transparent_crc
    (g_4512,
     "g_4512",
     print_hash_value);
  transparent_crc
    (g_4614,
     "g_4614",
     print_hash_value);
  transparent_crc
    (g_4663,
     "g_4663",
     print_hash_value);
  transparent_crc
    (g_4847,
     "g_4847",
     print_hash_value);
  for
    (i
     =
     0;
     i
     <
     6;
     i++)
  {
    transparent_crc
      (g_4848
       [i],
       "g_4848[i]",
       print_hash_value);
    if (print_hash_value)
      printf
 ("index = [%d]\n",
  i);
  }
  transparent_crc
    (g_4893,
     "g_4893",
     print_hash_value);
  transparent_crc
    (g_4963,
     "g_4963",
     print_hash_value);
  platform_main_end
    (crc32_context
     ^
     0xFFFFFFFFUL,
     print_hash_value);
  return
    0;
}
