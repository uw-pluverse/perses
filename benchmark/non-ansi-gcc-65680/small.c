
typedef long unsigned int size_t;

extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));

extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

typedef struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
} *__locale_t;
typedef __locale_t locale_t;
extern int strcoll_l (const char *__s1, const char *__s2, __locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    __locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));

extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));


extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));

extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));

extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));

extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));

extern int strerror_r (int __errnum, char *__buf, size_t __buflen) __asm__ ("" "__xpg_strerror_r") __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *strerror_l (int __errnum, __locale_t __l) __attribute__ ((__nothrow__ , __leaf__));
extern void __bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void bcopy (const void *__src, void *__dest, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));


typedef float float_t;
typedef double double_t;

extern double acos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acos (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double asin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asin (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double atan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atan2 (double __y, double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double cos (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cos (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double sin (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sin (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double tan (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tan (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double cosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double sinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double tanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __tanh (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double acosh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __acosh (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double asinh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __asinh (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double atanh (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __atanh (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double exp (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __frexp (double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern double ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern double __ldexp (double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
extern double log (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double log10 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log10 (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern double __modf (double __x, double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern double expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __expm1 (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double log1p (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log1p (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double logb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __logb (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __exp2 (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double log2 (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __log2 (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __pow (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __sqrt (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __hypot (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));


extern double cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __cbrt (double __x) __attribute__ ((__nothrow__ , __leaf__));


extern double ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __ceil (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fabs (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __floor (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fmod (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __isinf (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __finite (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int isinf (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int finite (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __drem (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double significand (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __significand (double __x) __attribute__ ((__nothrow__ , __leaf__));

extern double copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __copysign (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern double nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __nan (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int __isnan (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isnan (double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double j0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double j1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __j1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double jn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __jn (int, double) __attribute__ ((__nothrow__ , __leaf__));
extern double y0 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y0 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double y1 (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __y1 (double) __attribute__ ((__nothrow__ , __leaf__));
extern double yn (int, double) __attribute__ ((__nothrow__ , __leaf__)); extern double __yn (int, double) __attribute__ ((__nothrow__ , __leaf__));

extern double erf (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erf (double) __attribute__ ((__nothrow__ , __leaf__));
extern double erfc (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __erfc (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma (double) __attribute__ ((__nothrow__ , __leaf__));


extern double tgamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __tgamma (double) __attribute__ ((__nothrow__ , __leaf__));

extern double gamma (double) __attribute__ ((__nothrow__ , __leaf__)); extern double __gamma (double) __attribute__ ((__nothrow__ , __leaf__));
extern double lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern double __lgamma_r (double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));

extern double rint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __rint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __nextafter (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __nexttoward (double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __remainder (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbn (double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogb (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalbln (double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern double nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern double __nearbyint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __round (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __trunc (double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern double __remquo (double __x, double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrint (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrint (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lround (double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llround (double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llround (double __x) __attribute__ ((__nothrow__ , __leaf__));
extern double fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)); extern double __fdim (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__));
extern double fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmax (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern double fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern double __fmin (double __x, double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __fpclassify (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbit (double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern double fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__)); extern double __fma (double __x, double __y, double __z) __attribute__ ((__nothrow__ , __leaf__));

extern double scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__)); extern double __scalb (double __x, double __n) __attribute__ ((__nothrow__ , __leaf__));

extern float acosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float asinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float atanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atan2f (float __y, float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float cosf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cosf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float sinf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float tanf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float coshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __coshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __tanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __acoshf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __asinhf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __atanhf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float expf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __frexpf (float __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern float ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern float __ldexpf (float __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
extern float logf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float log10f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log10f (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern float __modff (float __x, float *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern float expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __expm1f (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log1pf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float logbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __logbf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __exp2f (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float log2f (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __log2f (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __powf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __sqrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __hypotf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));


extern float cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __cbrtf (float __x) __attribute__ ((__nothrow__ , __leaf__));


extern float ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __ceilf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fabsf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __floorf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmodf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __isinff (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __finitef (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int isinff (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int finitef (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __dremf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float significandf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __significandf (float __x) __attribute__ ((__nothrow__ , __leaf__));

extern float copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __copysignf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern float nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __nanf (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int __isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isnanf (float __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float j0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float j1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __j1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float jnf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __jnf (int, float) __attribute__ ((__nothrow__ , __leaf__));
extern float y0f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y0f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float y1f (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __y1f (float) __attribute__ ((__nothrow__ , __leaf__));
extern float ynf (int, float) __attribute__ ((__nothrow__ , __leaf__)); extern float __ynf (int, float) __attribute__ ((__nothrow__ , __leaf__));

extern float erff (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erff (float) __attribute__ ((__nothrow__ , __leaf__));
extern float erfcf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __erfcf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf (float) __attribute__ ((__nothrow__ , __leaf__));


extern float tgammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __tgammaf (float) __attribute__ ((__nothrow__ , __leaf__));

extern float gammaf (float) __attribute__ ((__nothrow__ , __leaf__)); extern float __gammaf (float) __attribute__ ((__nothrow__ , __leaf__));
extern float lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern float __lgammaf_r (float, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));

extern float rintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __rintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __nextafterf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __nexttowardf (float __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __remainderf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbnf (float __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalblnf (float __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern float nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern float __nearbyintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __roundf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __truncf (float __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern float __remquof (float __x, float __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundf (float __x) __attribute__ ((__nothrow__ , __leaf__));
extern float fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)); extern float __fdimf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__));
extern float fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fmaxf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern float fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern float __fminf (float __x, float __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __fpclassifyf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitf (float __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern float fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__)); extern float __fmaf (float __x, float __y, float __z) __attribute__ ((__nothrow__ , __leaf__));

extern float scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__)); extern float __scalbf (float __x, float __n) __attribute__ ((__nothrow__ , __leaf__));

extern long double acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atan2l (long double __y, long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cosl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __coshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __acoshl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __asinhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __atanhl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double expl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __frexpl (long double __x, int *__exponent) __attribute__ ((__nothrow__ , __leaf__));
extern long double ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ldexpl (long double __x, int __exponent) __attribute__ ((__nothrow__ , __leaf__));
extern long double logl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log10l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)); extern long double __modfl (long double __x, long double *__iptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));


extern long double expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __expm1l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log1pl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __logbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __exp2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __log2l (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __powl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __sqrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __hypotl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));


extern long double cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __cbrtl (long double __x) __attribute__ ((__nothrow__ , __leaf__));


extern long double ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __ceill (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fabsl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __floorl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmodl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern int __isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int isinfl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int finitel (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __dreml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __significandl (long double __x) __attribute__ ((__nothrow__ , __leaf__));

extern long double copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __copysignl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));


extern long double nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __nanl (const char *__tagb) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

extern int __isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int isnanl (long double __value) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double j0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double j1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __j1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __jnl (int, long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y0l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y0l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double y1l (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __y1l (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __ynl (int, long double) __attribute__ ((__nothrow__ , __leaf__));

extern long double erfl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double erfcl (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __erfcl (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal (long double) __attribute__ ((__nothrow__ , __leaf__));


extern long double tgammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __tgammal (long double) __attribute__ ((__nothrow__ , __leaf__));

extern long double gammal (long double) __attribute__ ((__nothrow__ , __leaf__)); extern long double __gammal (long double) __attribute__ ((__nothrow__ , __leaf__));
extern long double lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__)); extern long double __lgammal_r (long double, int *__signgamp) __attribute__ ((__nothrow__ , __leaf__));

extern long double rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __rintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __nextafterl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __nexttowardl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remainderl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbnl (long double __x, int __n) __attribute__ ((__nothrow__ , __leaf__));
extern int ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern int __ilogbl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalblnl (long double __x, long int __n) __attribute__ ((__nothrow__ , __leaf__));
extern long double nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long double __nearbyintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __roundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __truncl (long double __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__)); extern long double __remquol (long double __x, long double __y, int *__quo) __attribute__ ((__nothrow__ , __leaf__));
extern long int lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llrintl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long int lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long int __lroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
__extension__
extern long long int llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__)); extern long long int __llroundl (long double __x) __attribute__ ((__nothrow__ , __leaf__));
extern long double fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fdiml (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__));
extern long double fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fmaxl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern long double fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)); extern long double __fminl (long double __x, long double __y) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int __fpclassifyl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern int __signbitl (long double __value) __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__const__));
extern long double fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__)); extern long double __fmal (long double __x, long double __y, long double __z) __attribute__ ((__nothrow__ , __leaf__));

extern long double scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__)); extern long double __scalbl (long double __x, long double __n) __attribute__ ((__nothrow__ , __leaf__));
extern int signgam;
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
typedef enum
{
  _IEEE_ = -1,
  _SVID_,
  _XOPEN_,
  _POSIX_,
  _ISOC_
} _LIB_VERSION_TYPE;
extern _LIB_VERSION_TYPE _LIB_VERSION;
struct exception
  {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
  };
extern int matherr (struct exception *__exc);

typedef signed char int8_t;
typedef short int int16_t;
typedef int int32_t;
typedef long int int64_t;
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef long int intmax_t;
typedef unsigned long int uintmax_t;

extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));


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
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
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
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
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
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_peekc_locked (_IO_FILE *__fp);
extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;

typedef _G_fpos_t fpos_t;

extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));

extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));

extern FILE *tmpfile (void) ;
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;

extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tempnam (const char *__dir, const char *__pfx)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;

extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);

extern int fflush_unlocked (FILE *__stream);

extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;

extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__)) ;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__)) ;

extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));

extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);
extern int printf (const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));


extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));

extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));

extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;
extern int scanf (const char *__restrict __format, ...) ;
extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int fscanf (FILE *__restrict __stream, const char *__restrict __format, ...) __asm__ ("" "__isoc99_fscanf") ;
extern int scanf (const char *__restrict __format, ...) __asm__ ("" "__isoc99_scanf") ;
extern int sscanf (const char *__restrict __s, const char *__restrict __format, ...) __asm__ ("" "__isoc99_sscanf") __attribute__ ((__nothrow__ , __leaf__));


extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vfscanf")
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vscanf")
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s, const char *__restrict __format, __gnuc_va_list __arg) __asm__ ("" "__isoc99_vsscanf") __attribute__ ((__nothrow__ , __leaf__))
     __attribute__ ((__format__ (__scanf__, 2, 0)));


extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);

extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);

extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);

extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);

extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
extern char *gets (char *__s) __attribute__ ((__deprecated__));

extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;

extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);

extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);

extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);

extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;

extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);


extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;

extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;

extern void perror (const char *__s);

extern int sys_nerr;
extern const char *const sys_errlist[];
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern FILE *popen (const char *__command, const char *__modes) ;
extern int pclose (FILE *__stream);
extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));

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
static int64_t
(safe_unary_minus_func_int64_t_s)(int64_t si )
{
 
  return
    (si==(-9223372036854775807L -1)) ?
    ((si)) :
    -si;
}
static int64_t
(safe_add_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return
    (((si1>0) && (si2>0) && (si1 > ((9223372036854775807L)-si2))) || ((si1<0) && (si2<0) && (si1 < ((-9223372036854775807L -1)-si2)))) ?
    ((si1)) :
    (si1 + si2);
}
static int64_t
(safe_sub_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return
    (((si1^si2) & (((si1 ^ ((si1^si2) & (~(9223372036854775807L))))-si2)^si2)) < 0) ?
    ((si1)) :
    (si1 - si2);
}
static int64_t
(safe_mul_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return
    (((si1 > 0) && (si2 > 0) && (si1 > ((9223372036854775807L) / si2))) || ((si1 > 0) && (si2 <= 0) && (si2 < ((-9223372036854775807L -1) / si1))) || ((si1 <= 0) && (si2 > 0) && (si1 < ((-9223372036854775807L -1) / si2))) || ((si1 <= 0) && (si2 <= 0) && (si1 != 0) && (si2 < ((9223372036854775807L) / si1)))) ?
    ((si1)) :
    si1 * si2;
}
static int64_t
(safe_mod_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == (-9223372036854775807L -1)) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 % si2);
}
static int64_t
(safe_div_func_int64_t_s_s)(int64_t si1, int64_t si2 )
{
 
  return
    ((si2 == 0) || ((si1 == (-9223372036854775807L -1)) && (si2 == (-1)))) ?
    ((si1)) :
    (si1 / si2);
}
static int64_t
(safe_lshift_func_int64_t_s_s)(int64_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32) || (left > ((9223372036854775807L) >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static int64_t
(safe_lshift_func_int64_t_s_u)(int64_t left, unsigned int right )
{
 
  return
    ((left < 0) || (((unsigned int)right) >= 32) || (left > ((9223372036854775807L) >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static int64_t
(safe_rshift_func_int64_t_s_s)(int64_t left, int right )
{
 
  return
    ((left < 0) || (((int)right) < 0) || (((int)right) >= 32))?
    ((left)) :
    (left >> ((int)right));
}
static int64_t
(safe_rshift_func_int64_t_s_u)(int64_t left, unsigned int right )
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
static uint64_t
(safe_unary_minus_func_uint64_t_u)(uint64_t ui )
{
 
  return -ui;
}
static uint64_t
(safe_add_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{
 
  return ui1 + ui2;
}
static uint64_t
(safe_sub_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{
 
  return ui1 - ui2;
}
static uint64_t
(safe_mul_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{
 
  return ((unsigned long long)ui1) * ((unsigned long long)ui2);
}
static uint64_t
(safe_mod_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{
 
  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 % ui2);
}
static uint64_t
(safe_div_func_uint64_t_u_u)(uint64_t ui1, uint64_t ui2 )
{
 
  return
    (ui2 == 0) ?
    ((ui1)) :
    (ui1 / ui2);
}
static uint64_t
(safe_lshift_func_uint64_t_u_s)(uint64_t left, int right )
{
 
  return
    ((((int)right) < 0) || (((int)right) >= 32) || (left > ((18446744073709551615UL) >> ((int)right)))) ?
    ((left)) :
    (left << ((int)right));
}
static uint64_t
(safe_lshift_func_uint64_t_u_u)(uint64_t left, unsigned int right )
{
 
  return
    ((((unsigned int)right) >= 32) || (left > ((18446744073709551615UL) >> ((unsigned int)right)))) ?
    ((left)) :
    (left << ((unsigned int)right));
}
static uint64_t
(safe_rshift_func_uint64_t_u_s)(uint64_t left, int right )
{
 
  return
    ((((int)right) < 0) || (((int)right) >= 32)) ?
    ((left)) :
    (left >> ((int)right));
}
static uint64_t
(safe_rshift_func_uint64_t_u_u)(uint64_t left, unsigned int right )
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
    (fabsf((0.5f * sf1) + (0.5f * sf2)) > (0.5f * 3.40282346638528859812e+38F)) ?
    (sf1) :
    (sf1 + sf2);
}
static float
(safe_sub_func_float_f_f)(float sf1, float sf2 )
{
 
  return
    (fabsf((0.5f * sf1) - (0.5f * sf2)) > (0.5f * 3.40282346638528859812e+38F)) ?
    (sf1) :
    (sf1 - sf2);
}
static float
(safe_mul_func_float_f_f)(float sf1, float sf2 )
{
 
  return
    (fabsf((0x1.0p-100f * sf1) * (0x1.0p-28f * sf2)) > (0x1.0p-100f * (0x1.0p-28f * 3.40282346638528859812e+38F))) ?
    (sf1) :
    (sf1 * sf2);
}
static float
(safe_div_func_float_f_f)(float sf1, float sf2 )
{
 
  return
    ((fabsf(sf2) < 1.0f) && (((sf2 == 0.0f) || (fabsf((0x1.0p-49f * sf1) / (0x1.0p100f * sf2))) > (0x1.0p-100f * (0x1.0p-49f * 3.40282346638528859812e+38F))))) ?
    (sf1) :
    (sf1 / sf2);
}
static double
(safe_add_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    (fabs((0.5 * sf1) + (0.5 * sf2)) > (0.5 * ((double)1.79769313486231570815e+308L))) ?
    (sf1) :
    (sf1 + sf2);
}
static double
(safe_sub_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    (fabs((0.5 * sf1) - (0.5 * sf2)) > (0.5 * ((double)1.79769313486231570815e+308L))) ?
    (sf1) :
    (sf1 - sf2);
}
static double
(safe_mul_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    (fabs((0x1.0p-100 * sf1) * (0x1.0p-924 * sf2)) > (0x1.0p-100 * (0x1.0p-924 * ((double)1.79769313486231570815e+308L)))) ?
    (sf1) :
    (sf1 * sf2);
}
static double
(safe_div_func_double_f_f)(double sf1, double sf2 )
{
 
  return
    ((fabs(sf2) < 1.0) && (((sf2 == 0.0) || (fabs((0x1.0p-974 * sf1) / (0x1.0p100 * sf2))) > (0x1.0p-100 * (0x1.0p-974 * ((double)1.79769313486231570815e+308L)))))) ?
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
crc32_8bytes (uint64_t val)
{
 crc32_byte ((val>>0) & 0xff);
 crc32_byte ((val>>8) & 0xff);
 crc32_byte ((val>>16) & 0xff);
 crc32_byte ((val>>24) & 0xff);
 crc32_byte ((val>>32) & 0xff);
 crc32_byte ((val>>40) & 0xff);
 crc32_byte ((val>>48) & 0xff);
 crc32_byte ((val>>56) & 0xff);
}
static void
transparent_crc (uint64_t val, char* vname, int flag)
{
 crc32_8bytes(val);
 if (flag) {
    printf("...checksum after hashing %s : %lX\n", vname, crc32_context ^ 0xFFFFFFFFUL);
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
static long __undefined;
struct S0 {
   uint64_t f0;
   int16_t f1;
   signed f2 : 6;
   unsigned f3 : 18;
   signed f4 : 17;
   signed f5 : 27;
};
#pragma pack(push)
#pragma pack(1)
struct S1 {
   const signed f0 : 30;
   int8_t f1;
};
#pragma pack(pop)
#pragma pack(push)
#pragma pack(1)
struct S2 {
   const signed f0 : 19;
   int64_t f1;
   signed f2 : 24;
   signed f3 : 14;
   unsigned f4 : 13;
   unsigned f5 : 9;
   signed f6 : 14;
   int32_t f7;
   signed f8 : 31;
   signed f9 : 21;
};
#pragma pack(pop)
struct S3 {
   unsigned f0 : 28;
   signed f1 : 18;
   unsigned f2 : 3;
   const signed f3 : 23;
   unsigned f4 : 20;
};
#pragma pack(push)
#pragma pack(1)
struct S4 {
   const uint16_t f0;
   unsigned f1 : 6;
   const uint32_t f2;
   uint64_t f3;
   uint32_t f4;
   int64_t f5;
};
#pragma pack(pop)
#pragma pack(push)
#pragma pack(1)
struct S5 {
   unsigned f0 : 20;
   unsigned f1 : 25;
   unsigned f2 : 21;
   unsigned f3 : 21;
};
#pragma pack(pop)
static struct S0 g_9 = {1UL,0xA5EAL,-7,389,347,6100};
static struct S1 g_10 = {6383,0x9AL};
static struct S3 g_22 = {10858,449,0,-2148,21};
static int32_t g_24 = 0x65CE17C9L;
static struct S0 g_27[6] = {{1UL,0x3FAAL,3,403,-9,-8381}, {6UL,0x393AL,-3,429,360,3800}, {1UL,0x3FAAL,3,403,-9,-8381}, {6UL,0x393AL,-3,429,360,3800}, {1UL,0x3FAAL,3,403,-9,-8381}, {6UL,0x393AL,-3,429,360,3800}};
static int32_t g_52 = 0L;
static struct S2 g_73[1] = {{-624,0xEFAAE2E0842841C1LL,-2297,-59,73,9,-53,0x287F110AL,6633,-1111}};
static int32_t g_86 = 0x8FE26F8DL;
static int32_t g_93 = (-4L);
static struct S4 g_108[1] = {{4UL,3,4294967288UL,0xC7BD3F7DA1659101LL,0xE8ACDD56L,0xCCD30ACD80C33512LL}};
static int64_t g_149 = 3L;
static uint8_t g_150 = 0x8AL;
static int8_t g_155 = 0xAEL;
static struct S5 g_203[1][6][3] = {{{{765,3144,1064,1049}, {765,3144,1064,1049}, {554,1974,465,774}}, {{765,3144,1064,1049}, {765,3144,1064,1049}, {554,1974,465,774}}, {{765,3144,1064,1049}, {765,3144,1064,1049}, {554,1974,465,774}}, {{765,3144,1064,1049}, {765,3144,1064,1049}, {554,1974,465,774}}, {{765,3144,1064,1049}, {765,3144,1064,1049}, {554,1974,465,774}}, {{765,3144,1064,1049}, {765,3144,1064,1049}, {554,1974,465,774}}}};
static int32_t g_269[2] = {0x536A53D2L, 0x536A53D2L};
static struct S5 g_273 = {537,1367,477,576};
static int8_t g_296 = 0xB9L;
static struct S0 g_339[1][2][5] = {{{{0x83F0C64C83A3CC47LL,0L,-2,13,-177,302}, {0xE68D64E3510861D3LL,0x090EL,2,126,-350,-1098}, {0x83F0C64C83A3CC47LL,0L,-2,13,-177,302}, {0xE68D64E3510861D3LL,0x090EL,2,126,-350,-1098}, {0x83F0C64C83A3CC47LL,0L,-2,13,-177,302}}, {{0x83F0C64C83A3CC47LL,0L,-2,13,-177,302}, {0xE68D64E3510861D3LL,0x090EL,2,126,-350,-1098}, {0x83F0C64C83A3CC47LL,0L,-2,13,-177,302}, {0xE68D64E3510861D3LL,0x090EL,2,126,-350,-1098}, {0x83F0C64C83A3CC47LL,0L,-2,13,-177,302}}}};
static int64_t g_483 = 3L;
static int8_t g_598 = 9L;
static uint64_t g_618 = 0xF92BD37FCF60DEF5LL;
static int64_t g_676 = (-1L);
static int32_t g_764 = 1L;
static int16_t g_765 = 4L;
static uint32_t g_781 = 1UL;
static int16_t g_889[4][3][9] = {{{0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}, {0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}, {0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}}, {{0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}, {0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}, {0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}}, {{0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}, {0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}, {0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}}, {{0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}, {0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}, {0x23BFL, 0L, (-1L), 0L, 0x97D0L, 0x332AL, 0x97D0L, 0L, (-1L)}}};
static uint8_t g_960 = 3UL;
static int8_t g_1072[10] = {0x2EL, 0x2EL, (-7L), 0x2EL, 0x2EL, (-7L), 0x2EL, 0x2EL, (-7L), 0x2EL};
static int8_t g_1210 = 1L;
static int32_t g_1327 = 0L;
static int8_t g_1501 = 0x6EL;
static int32_t g_1589 = (-5L);
static int16_t g_1674 = 0L;
static int32_t g_1685[1][2][10] = {{{4L, 0x0DE8C08EL, 1L, 0x0DE8C08EL, 4L, 0x0DE8C08EL, 1L, 0x0DE8C08EL, 4L, 0x0DE8C08EL}, {4L, 0x0DE8C08EL, 1L, 0x0DE8C08EL, 4L, 0x0DE8C08EL, 1L, 0x0DE8C08EL, 4L, 0x0DE8C08EL}}};
static int32_t g_1716[10][1][9] = {{{0x2BDD79C5L, (-7L), 0x7683E58EL, 0x99B5011CL, (-8L), 2L, 1L, 0xDE892B88L, 0x7683E58EL}}, {{0x2BDD79C5L, (-7L), 0x7683E58EL, 0x99B5011CL, (-8L), 2L, 1L, 0xDE892B88L, 0x7683E58EL}}, {{0x2BDD79C5L, (-7L), 0x7683E58EL, 0x99B5011CL, (-8L), 2L, 1L, 0xDE892B88L, 0x7683E58EL}}, {{0x2BDD79C5L, (-7L), 0x7683E58EL, 0x99B5011CL, (-8L), 2L, 1L, 0xDE892B88L, 0x7683E58EL}}, {{0x2BDD79C5L, (-7L), 0x7683E58EL, 0x99B5011CL, (-8L), 2L, 1L, 0xDE892B88L, 0x7683E58EL}}, {{0x2BDD79C5L, (-7L), 0x7683E58EL, 0x99B5011CL, (-8L), 2L, 1L, 0xDE892B88L, 0x7683E58EL}}, {{0x2BDD79C5L, (-7L), 0x7683E58EL, 0x99B5011CL, (-8L), 2L, 1L, 0xDE892B88L, 0x7683E58EL}}, {{0x2BDD79C5L, (-7L), 0x7683E58EL, 0x99B5011CL, (-8L), 2L, 1L, 0xDE892B88L, 0x7683E58EL}}, {{0x2BDD79C5L, (-7L), 0x7683E58EL, 0x99B5011CL, (-8L), 2L, 1L, 0xDE892B88L, 0x7683E58EL}}, {{0x2BDD79C5L, (-7L), 0x7683E58EL, 0x99B5011CL, (-8L), 2L, 1L, 0xDE892B88L, 0x7683E58EL}}};
static uint16_t g_1738 = 1UL;
static struct S0 g_1812[9] = {{18446744073709551612UL,0xE5D9L,2,12,178,-4269}, {0x300C51033E65B597LL,8L,7,248,123,6520}, {18446744073709551612UL,0xE5D9L,2,12,178,-4269}, {0x300C51033E65B597LL,8L,7,248,123,6520}, {18446744073709551612UL,0xE5D9L,2,12,178,-4269}, {0x300C51033E65B597LL,8L,7,248,123,6520}, {18446744073709551612UL,0xE5D9L,2,12,178,-4269}, {0x300C51033E65B597LL,8L,7,248,123,6520}, {18446744073709551612UL,0xE5D9L,2,12,178,-4269}};
static uint16_t g_1842 = 0x4376L;
static const uint16_t g_1844 = 0UL;
static uint32_t g_1923 = 0xAB9BE056L;
static uint16_t g_1945 = 4UL;
static uint64_t g_1979 = 8UL;
static struct S3 g_2006 = {7293,-477,0,578,189};
static int32_t g_2043 = 0x293935BCL;
inline static int32_t func_1(void);
static uint32_t func_13(struct S1 p_14, uint64_t p_15, int32_t p_16, int32_t p_17);
static uint64_t func_36(uint32_t p_37, const struct S1 p_38);
inline static uint32_t func_39(uint32_t p_40);
static int32_t func_63(int16_t p_64, struct S5 p_65, const uint32_t p_66);
static int16_t func_67(struct S2 p_68, int32_t p_69, struct S2 p_70, struct S4 p_71);
static int16_t func_75(struct S3 p_76, int32_t p_77, int8_t p_78, struct S3 p_79);
inline static int16_t func_81(uint16_t p_82);
static int16_t func_89(int16_t p_90, int16_t p_91);
static uint32_t func_102(struct S4 p_103, struct S3 p_104, struct S2 p_105, uint16_t p_106, struct S4 p_107);
inline static int32_t func_1(void)
{
    uint32_t l_6 = 4294967292UL;
    struct S1 l_18[2] = {{-30098,0x52L}, {-30098,0x52L}};
    struct S5 l_21[1] = {{341,4960,425,725}};
    struct S3 l_23 = {2509,-376,1,-268,548};
    int16_t l_44 = 0x9B0BL;
    int8_t l_1786 = 0x66L;
    int16_t l_1802 = 1L;
    struct S0 l_1810[1] = {{2UL,1L,0,296,-354,5500}};
    struct S0 l_1811 = {0xF229B686D73FD7C0LL,3L,5,240,168,-2209};
    uint16_t l_1849[3][6][7] = {{{0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}}, {{0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}}, {{0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}, {0x280CL, 65535UL, 0xD10EL, 0x4B54L, 65535UL, 0xD3A8L, 65534UL}}};
    uint16_t l_1883[2][3] = {{0x0187L, 1UL, 0x0187L}, {0x0187L, 1UL, 0x0187L}};
    struct S2 l_1895 = {-368,9L,-1866,76,60,12,42,0x35E45DB0L,-36459,576};
    uint16_t l_1896 = 65535UL;
    struct S5 l_1897 = {778,846,748,223};
    int32_t l_1922[7] = {0L, 0L, 0xCA31B866L, 0L, 0L, 0xCA31B866L, 0L};
    struct S0 l_1947 = {8UL,0xEC5AL,3,357,-295,8651};
    uint32_t l_1953 = 0x250544DFL;
    uint32_t l_1959[3];
    int16_t l_1970 = 1L;
    struct S4 l_1974 = {0x9A0FL,3,4UL,0x35C0580E9A89EFA3LL,0x17551DDDL,0xC5885194D58820E6LL};
    uint32_t l_2058 = 0UL;
    int32_t l_2081 = 0x6874CD0BL;
    int i, j, k;
    for (i = 0; i < 3; i++)
        l_1959[i] = 0x113C7C5AL;
    if ((g_9.f5 = (0L || (safe_rshift_func_int16_t_s_u((safe_mod_func_int8_t_s_s(l_6, (safe_mod_func_int8_t_s_s(((g_9 , g_10) , (-1L)), (safe_mod_func_int16_t_s_s((func_13(l_18[1], ((((g_10.f1 && (g_24 = (safe_rshift_func_int8_t_s_s(((((g_9.f5 , (l_21[0] , g_22)) , 18446744073709551611UL) , l_23) , l_6), l_18[1].f0)))) ^ l_21[0].f0) , l_23.f0) , g_9.f5), l_23.f1, g_22.f1) == g_22.f4), 8L)))))), l_23.f0)))))
    {
        uint16_t l_25 = 0xDF64L;
        struct S0 l_26[2] = {{0x02089CE376A95236LL,0x8F78L,1,14,-278,9804}, {0x02089CE376A95236LL,0x8F78L,1,14,-278,9804}};
        int i;
        return g_9.f3;
    }
    else
    {
        uint32_t l_28 = 18446744073709551606UL;
        int32_t l_29[4] = {8L, 0x3C6211EEL, 8L, 0x3C6211EEL};
        struct S4 l_43 = {65527UL,3,0x992D143BL,18446744073709551613UL,0xE40AA8DEL,0x8A8B9AC9426B2C3BLL};
        struct S1 l_49 = {-24500,-2L};
        int16_t l_1804 = 0xA699L;
        const uint32_t l_1843 = 2UL;
        struct S0 l_1948[8][7] = {{{0x7FF5A80FC2DDDAE5LL,1L,-3,198,178,6786}, {0x216484500A6B561CLL,1L,-0,8,182,-7073}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {0xB285FCF45A8FD6DDLL,-7L,2,388,66,3329}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}}, {{0x7FF5A80FC2DDDAE5LL,1L,-3,198,178,6786}, {0x216484500A6B561CLL,1L,-0,8,182,-7073}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {0xB285FCF45A8FD6DDLL,-7L,2,388,66,3329}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}}, {{0x7FF5A80FC2DDDAE5LL,1L,-3,198,178,6786}, {0x216484500A6B561CLL,1L,-0,8,182,-7073}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {0xB285FCF45A8FD6DDLL,-7L,2,388,66,3329}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}}, {{0x7FF5A80FC2DDDAE5LL,1L,-3,198,178,6786}, {0x216484500A6B561CLL,1L,-0,8,182,-7073}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {0xB285FCF45A8FD6DDLL,-7L,2,388,66,3329}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}}, {{0x7FF5A80FC2DDDAE5LL,1L,-3,198,178,6786}, {0x216484500A6B561CLL,1L,-0,8,182,-7073}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {0xB285FCF45A8FD6DDLL,-7L,2,388,66,3329}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}}, {{0x7FF5A80FC2DDDAE5LL,1L,-3,198,178,6786}, {0x216484500A6B561CLL,1L,-0,8,182,-7073}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {0xB285FCF45A8FD6DDLL,-7L,2,388,66,3329}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}}, {{0x7FF5A80FC2DDDAE5LL,1L,-3,198,178,6786}, {0x216484500A6B561CLL,1L,-0,8,182,-7073}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {0xB285FCF45A8FD6DDLL,-7L,2,388,66,3329}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}}, {{0x7FF5A80FC2DDDAE5LL,1L,-3,198,178,6786}, {0x216484500A6B561CLL,1L,-0,8,182,-7073}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {0xB285FCF45A8FD6DDLL,-7L,2,388,66,3329}, {0x3CC3ECA65C328A76LL,1L,-7,171,-20,8340}, {18446744073709551615UL,0x3AF2L,5,297,213,3647}}};
        int32_t l_1969 = 0x4B32DF3EL;
        struct S5 l_2071 = {549,3701,1293,1149};
        int i, j;
lbl_1928:
        g_9.f4 = ((g_27[2] = g_27[2]) , l_21[0].f2);
        if ((l_29[1] = l_28))
        {
            struct S2 l_32[10][2][6] = {{{{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}, {{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}}, {{{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}, {{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}}, {{{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}, {{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}}, {{{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}, {{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}}, {{{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}, {{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}}, {{{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}, {{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}}, {{{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}, {{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}}, {{{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}, {{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}}, {{{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}, {{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}}, {{{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}, {{60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {-117,0xB8798E375BC53ECDLL,1871,-13,86,1,-100,0x2B7F3A40L,23467,896}, {125,0x6624E94FA9F1E568LL,1397,64,4,2,33,0L,6303,1302}, {60,0x1F81FC11418CD0E5LL,-1907,-78,78,1,-27,1L,24995,-857}, {659,0xEE99B4D814858521LL,3566,-71,78,19,-48,-10L,44700,-820}}}};
            struct S1 l_1783 = {10974,1L};
            struct S0 l_1805 = {0xD1BEEF0125921B9FLL,0x9A28L,-3,399,183,-8620};
            int16_t l_1813 = 2L;
            uint64_t l_1894 = 18446744073709551607UL;
            int32_t l_1946 = 5L;
            int i, j, k;
            if (((g_10.f1 == (safe_lshift_func_int16_t_s_s((func_13((l_32[8][0][0] , ((+((((safe_rshift_func_uint16_t_u_s(func_13(g_10, g_9.f4, (((((l_29[1] = (((func_36(func_39((g_27[2].f4 ^ ((safe_add_func_int8_t_s_s(g_27[2].f4, (l_43 , (func_13((l_44 , ((safe_rshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((g_9.f3 || l_28) | g_27[2].f5), 4)), l_21[0].f1)) , l_49)), g_27[2].f4, l_18[1].f1, g_27[2].f0) ^ g_22.f0)))) == g_9.f5))), g_10) ^ l_23.f0) & 0xE006L) || l_32[8][0][0].f6)) | 18446744073709551615UL) != g_108[0].f0) >= (-1L)) && g_108[0].f2), l_32[8][0][0].f7), g_10.f0)) & 0x0D106AF6BDAE9FF2LL) ^ g_108[0].f2) , l_29[1])) , l_1783)), g_22.f2, g_108[0].f0, l_43.f0) | 9UL), g_1685[0][1][7]))) >= (-10L)))
            {
                uint32_t l_1787 = 0x02297276L;
                struct S0 l_1803 = {18446744073709551610UL,1L,2,215,-130,2049};
                if ((safe_sub_func_uint32_t_u_u((((((((0xB31BL ^ ((g_339[0][0][4] = (l_1786 , (l_1805 = (g_27[1] = (((g_676 = (l_1787 ^ (((((safe_add_func_uint8_t_u_u(((safe_mod_func_int16_t_s_s((((g_93 ^ (safe_rshift_func_uint16_t_u_s(0UL, (l_1803.f4 = ((safe_mod_func_uint16_t_u_u(((safe_sub_func_uint8_t_u_u(((safe_add_func_int8_t_s_s(g_108[0].f5, (((g_1072[8] = 0x22L) | ((g_1738 = (((safe_lshift_func_uint16_t_u_s(l_1802, 11)) != (l_1803 , g_203[0][1][0].f1)) <= 4L)) , g_339[0][0][4].f3)) && l_29[1]))) & l_23.f2), 0x9EL)) || g_86), 0xF56CL)) | l_32[8][0][0].f7))))) <= g_22.f2) >= (-8L)), 0x706CL)) <= l_1804), g_22.f3)) >= g_155) == g_108[0].f3) != l_23.f2) && 1UL))) <= 18446744073709551611UL) , g_27[2]))))) , g_9.f0)) ^ 0x42C5L) >= (-6L)) ^ 0x051A0AA4L) <= l_43.f5) && 0x1EL) <= g_1210), l_1803.f0)))
                {
                    int8_t l_1814 = 0xA1L;
                    struct S0 l_1848 = {0xB5892FA1268416BBLL,8L,3,348,-53,-11471};
                    if ((((0xD228L | (1UL == ((g_108[0].f3 & (((((g_22 , g_889[1][1][8]) > (g_73[0].f1 | (safe_lshift_func_uint8_t_u_u(((g_9.f0 = g_73[0].f9) & ((((safe_add_func_int16_t_s_s((g_27[2].f1 = g_73[0].f8), ((g_1812[8] = (l_1811 = (l_1810[0] = (g_339[0][1][0] = g_339[0][0][4])))) , l_32[8][0][0].f5))) , l_29[1]) > l_28) > 65531UL)), 4)))) >= 65526UL) , l_1813) & l_1814)) >= g_273.f1))) == g_203[0][1][0].f2) & g_203[0][1][0].f0))
                    {
                        return l_1803.f4;
                    }
                    else
                    {
                        struct S4 l_1845 = {65535UL,3,0x631256C0L,18446744073709551615UL,2UL,0L};
                        g_9.f5 = (((((~(g_10.f0 && (+(((g_203[0][1][0] = g_273) , l_1805) , ((g_22 , (((safe_add_func_int16_t_s_s((safe_sub_func_int16_t_s_s((safe_mod_func_uint8_t_u_u((safe_add_func_uint64_t_u_u(g_10.f1, g_1812[8].f4)), l_1814)), ((safe_mod_func_int64_t_s_s(l_1814, (safe_add_func_int16_t_s_s(8L, g_1685[0][1][5])))) , g_149))), g_108[0].f3)) & 0xFB5C5393L) == g_108[0].f5)) == 1L))))) < 1UL) | l_1814) || g_1685[0][1][7]) & l_1810[0].f5);
                        l_1805 = (((safe_rshift_func_uint8_t_u_u(0x88L, (((((-2L) >= (l_1810[0].f4 = g_273.f2)) ^ g_960) >= ((~((((safe_add_func_int64_t_s_s((safe_sub_func_int16_t_s_s(l_1803.f2, 0x32D1L)), (safe_lshift_func_int8_t_s_s((l_32[8][0][0].f4 == (safe_add_func_int16_t_s_s(((safe_sub_func_int8_t_s_s(((((l_1803.f0 > (g_339[0][0][4].f4 != g_1716[6][0][3])) || 2L) || g_1842) , l_1843), l_1805.f1)) != g_1844), (-8L)))), 7)))) != 0UL) , 0L) <= l_1805.f5)) <= 65526UL)) , l_1814))) , l_1845) , g_27[3]);
                    }
                    for (g_960 = 0; (g_960 <= 2); g_960 += 1)
                    {
                        l_1810[0] = (l_1805 = g_9);
                        g_339[0][0][4].f4 = l_23.f1;
                    }
                    g_339[0][0][4].f2 = ((((g_22.f0 , g_9.f0) ^ (g_339[0][0][4] , (safe_sub_func_int64_t_s_s(((((l_1802 >= (l_32[8][0][0].f3 = ((l_1848 , g_1844) == 0x95L))) <= l_1849[2][0][4]) == ((l_28 <= (-1L)) ^ l_29[1])) <= g_889[1][2][6]), g_52)))) , l_23.f4) != l_1803.f1);
                }
                else
                {
                    int16_t l_1868[6][10] = {{1L, 1L, 1L, (-2L), (-1L), (-6L), 0x6E74L, 0x6E74L, (-6L), (-1L)}, {1L, 1L, 1L, (-2L), (-1L), (-6L), 0x6E74L, 0x6E74L, (-6L), (-1L)}, {1L, 1L, 1L, (-2L), (-1L), (-6L), 0x6E74L, 0x6E74L, (-6L), (-1L)}, {1L, 1L, 1L, (-2L), (-1L), (-6L), 0x6E74L, 0x6E74L, (-6L), (-1L)}, {1L, 1L, 1L, (-2L), (-1L), (-6L), 0x6E74L, 0x6E74L, (-6L), (-1L)}, {1L, 1L, 1L, (-2L), (-1L), (-6L), 0x6E74L, 0x6E74L, (-6L), (-1L)}};
                    int i, j;
                }
            }
            else
            {
                int8_t l_1927[5][8] = {{0x2CL, 0x70L, (-9L), 0x5FL, 0x69L, 0xE2L, 0xC8L, 9L}, {0x2CL, 0x70L, (-9L), 0x5FL, 0x69L, 0xE2L, 0xC8L, 9L}, {0x2CL, 0x70L, (-9L), 0x5FL, 0x69L, 0xE2L, 0xC8L, 9L}, {0x2CL, 0x70L, (-9L), 0x5FL, 0x69L, 0xE2L, 0xC8L, 9L}, {0x2CL, 0x70L, (-9L), 0x5FL, 0x69L, 0xE2L, 0xC8L, 9L}};
                int32_t l_1944[5][9] = {{0xB9BD427AL, 0xB9BD427AL, 0x2D269A62L, (-5L), 0xC69C835AL, (-5L), 0x2D269A62L, 0xB9BD427AL, 0xB9BD427AL}, {0xB9BD427AL, 0xB9BD427AL, 0x2D269A62L, (-5L), 0xC69C835AL, (-5L), 0x2D269A62L, 0xB9BD427AL, 0xB9BD427AL}, {0xB9BD427AL, 0xB9BD427AL, 0x2D269A62L, (-5L), 0xC69C835AL, (-5L), 0x2D269A62L, 0xB9BD427AL, 0xB9BD427AL}, {0xB9BD427AL, 0xB9BD427AL, 0x2D269A62L, (-5L), 0xC69C835AL, (-5L), 0x2D269A62L, 0xB9BD427AL, 0xB9BD427AL}, {0xB9BD427AL, 0xB9BD427AL, 0x2D269A62L, (-5L), 0xC69C835AL, (-5L), 0x2D269A62L, 0xB9BD427AL, 0xB9BD427AL}};
                int i, j;
                for (l_1802 = 10; (l_1802 <= (-19)); l_1802 = safe_sub_func_int64_t_s_s(l_1802, 5))
                {
                    uint8_t l_1931 = 1UL;
                    int8_t l_1949 = 0x13L;
                    if ((g_108[0] , 0L))
                    {
                        if (g_1327)
                            break;
                        if (g_339[0][0][4].f2)
                            continue;
                        l_1927[4][7] = 0L;
                    }
                    else
                    {
                        int16_t l_1943 = 0x339FL;
                        if (l_49.f1)
                            goto lbl_1928;
                        l_1895.f8 = ((g_203[0][1][0].f1 & (((((safe_add_func_uint64_t_u_u((0L || (((l_1931 != (safe_mod_func_int64_t_s_s(((l_1897.f3 <= (safe_mod_func_int8_t_s_s(((safe_mul_func_int64_t_s_s((safe_lshift_func_int16_t_s_u(((g_22.f2 , g_598) != (0x03L <= ((g_9.f1 = (-9L)) || (+(g_1945 = (((((l_1944[0][0] = (safe_rshift_func_uint8_t_u_s((g_960 = l_1943), 4))) != g_9.f0) == 18446744073709551615UL) & g_73[0].f8) >= g_1812[8].f0)))))), g_203[0][1][0].f3)), 0UL)) || g_27[2].f3), l_1922[0]))) || l_1931), l_1943))) <= l_43.f0) > g_598)), g_339[0][0][4].f5)) | 18446744073709551613UL) < 0UL) > l_1946) , l_23.f0)) || l_43.f2);
                        l_1948[0][1] = ((g_203[0][1][0] = g_203[0][1][0]) , l_1947);
                    }
                    l_1949 = l_1802;
                }
                g_27[2] = l_1805;
            }
        }
        else
        {
            uint8_t l_1950[7] = {252UL, 252UL, 247UL, 252UL, 252UL, 247UL, 252UL};
            struct S0 l_1973 = {0UL,0xF93AL,-4,235,348,-3102};
            int8_t l_1987[9] = {0x80L, (-1L), 0x80L, (-1L), 0x80L, (-1L), 0x80L, (-1L), 0x80L};
            struct S5 l_1988 = {401,5372,1211,339};
            int i;
{
                struct S1 l_1954 = {-21756,0xDBL};
                int32_t l_1960 = 0L;
                uint32_t l_1971[5][2][5] = {{{0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}, {0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}}, {{0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}, {0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}}, {{0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}, {0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}}, {{0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}, {0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}}, {{0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}, {0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}}};
                struct S0 l_1972 = {0x0559AC6BCD61EF54LL,9L,-4,108,233,-8120};
                int i, j, k;
                return g_1072[(g_1501 + 4)];
            }
safe_rshift_func_int8_t_s_u((!(18446744073709551613UL >= g_10.f1)), 7);
safe_unary_minus_func_uint64_t_u(0x0AF2F182C2E9D129LL);
safe_sub_func_uint64_t_u_u((g_108[0].f3 = ((safe_lshift_func_int8_t_s_s((g_598 = ((((l_18[1].f0 , g_1685[0][1][7]) >= 0xC1L) != l_1811.f2) == 18446744073709551613UL)), 7)) <= 0x4EBBL)), 1UL);
safe_rshift_func_uint8_t_u_u((0x95L == g_73[0].f9), 7);
for (g_1501 = 0; (g_1501 >= 0); g_1501 -= 1)
            {
                struct S1 l_1954 = {-21756,0xDBL};
                int32_t l_1960 = 0L;
                uint32_t l_1971[5][2][5] = {{{0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}, {0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}}, {{0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}, {0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}}, {{0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}, {0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}}, {{0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}, {0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}}, {{0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}, {0x5A55B72AL, 4294967287UL, 0x7C1AF184L, 0x158D1DA8L, 0x40C694B4L}}};
                struct S0 l_1972 = {0x0559AC6BCD61EF54LL,9L,-4,108,233,-8120};
                int i, j, k;
                l_1950[4] = g_1072[(g_1501 + 4)];
                g_9.f2 = ((safe_sub_func_int16_t_s_s(g_1674, (l_1953 != ((l_1954 , (safe_sub_func_uint64_t_u_u((((g_1812[8].f0 ^ ((safe_add_func_int32_t_s_s((l_1960 = l_1959[2]), ((g_203[0][1][0].f2 = (((g_1842 = (((safe_sub_func_uint64_t_u_u(((safe_rshift_func_uint8_t_u_s(((safe_lshift_func_uint8_t_u_u((((safe_sub_func_int32_t_s_s(((g_73[0] , l_1950[4]) || g_108[0].f4), (18446744073709551615UL >= l_1954.f1))) , 0x5E69E21DL) >= g_9.f2), 5)) >= g_889[3][1][6]), 2)) , g_9.f5), l_1954.f1)) ^ l_1969) <= l_43.f3)) == 1L) && 0x5A89L)) != l_1954.f1))) || l_1948[0][1].f3)) > 0UL) <= l_1970), g_273.f2))) >= l_1971[1][0][0])))) , 0xFDA64624L);
                l_1973 = (l_1972 = (g_1812[8] = g_27[2]));
                return g_1072[(g_1501 + 4)];
            };
            if (((safe_sub_func_int16_t_s_s((0x1CE538C8CD2030A4LL || (((g_10 , 0xA264C335884F1EB2LL) >= (g_1979 = 0xE41DE62A7540F12FLL)) ^ (((safe_add_func_uint32_t_u_u(g_22.f1, ((l_1973.f2 = (safe_rshift_func_int16_t_s_u((g_52 < (1L < (~((safe_rshift_func_uint16_t_u_u((l_1948[0][1].f5 = (g_1812[8].f4 || ((g_1685[0][1][0] < 0x622381DE4584C0B3LL) > l_1849[0][4][2]))), 7)) | l_43.f1)))), l_1987[8]))) <= l_1922[2]))) ^ l_1950[4]) <= l_1947.f1))), 6UL)) >= l_1786))
            {
                uint16_t l_2008 = 0xBAC8L;
                int32_t l_2034[9][2] = {{0x89725621L, 7L}, {0x89725621L, 7L}, {0x89725621L, 7L}, {0x89725621L, 7L}, {0x89725621L, 7L}, {0x89725621L, 7L}, {0x89725621L, 7L}, {0x89725621L, 7L}, {0x89725621L, 7L}};
                int16_t l_2057 = 6L;
                uint64_t l_2082 = 1UL;
                struct S0 l_2084 = {0UL,-1L,2,374,-182,9153};
                uint32_t l_2089 = 1UL;
                int i, j;
safe_rshift_func_uint16_t_u_u(g_273.f1, 3);
safe_mod_func_int64_t_s_s(((g_889[1][2][6] = l_21[0].f2) == 8UL), g_781);
            }
            else
            {
                uint16_t l_2103 = 0xD6D3L;
                int32_t l_2111[6][5][1] = {{{(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}}, {{(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}}, {{(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}}, {{(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}}, {{(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}}, {{(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}, {(-1L)}}};
                int i, j, k;
lbl_2112:
                l_2111[2][4][0] = g_24;
{
safe_mod_func_int8_t_s_s(l_6, (safe_mod_func_int8_t_s_s(((g_9 , g_10) , (-1L)), (safe_mod_func_int16_t_s_s((func_13(l_18[1], ((((g_10.f1 && (g_24 = (safe_rshift_func_int8_t_s_s(((((g_9.f5 , (l_21[0] , g_22)) , 18446744073709551611UL) , l_23) , l_6), l_18[1].f0)))) ^ l_21[0].f0) , l_23.f0) , g_9.f5), l_23.f1, g_22.f1) == g_22.f4), 8L)))));
                    }
safe_unary_minus_func_uint64_t_u(0x0AF2F182C2E9D129LL);
if (l_49.f1)
                            goto lbl_1928;
safe_rshift_func_uint8_t_u_u((~((l_1804 >= l_1987[8]) && ((0xFCC5L >= (safe_sub_func_uint32_t_u_u(0xB89E3389L, (safe_mod_func_uint8_t_u_u(0x15L, 0x2BL))))) ^ ((g_203[0][0][2] , ((g_108[0].f5 = (safe_mod_func_uint32_t_u_u((g_27[(l_1974.f3 + 2)].f4 = l_1897.f2), g_889[1][2][6]))) , g_1812[8].f3)) > (-2L))))), g_1327);
safe_mod_func_uint8_t_u_u(0x15L, 0x2BL);
l_1969 -= 1;
safe_add_func_uint64_t_u_u(g_10.f1, g_1812[8].f4);
            }
func_13((l_44 , ((safe_rshift_func_int8_t_s_s((safe_lshift_func_int16_t_s_s(((g_9.f3 || l_28) | g_27[2].f5), 4)), l_21[0].f1)) , l_49)), g_27[2].f4, l_18[1].f1, g_27[2].f0);
safe_add_func_uint8_t_u_u((((safe_mod_func_int64_t_s_s(((g_889[1][2][6] = l_21[0].f2) == 8UL), g_781)) || 0x7A04B492L) < l_1883[0][0]), 0L);
safe_lshift_func_int8_t_s_u((safe_unary_minus_func_uint64_t_u(0x0AF2F182C2E9D129LL)), 7);
safe_rshift_func_int8_t_s_u((g_27[2].f1 < 0L), 0);
safe_lshift_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(0x6F01L, 14)), 3);
safe_lshift_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(0x6F01L, 14)), 3);
printf("index = [%d][%d][%d]\n", i, j, k);
        }
    }
    g_273 = ((l_1947.f4 = (g_22.f1 || (safe_rshift_func_uint16_t_u_u(((safe_sub_func_int64_t_s_s((safe_rshift_func_uint16_t_u_s((l_21[0].f0 < l_1883[0][0]), l_1811.f3)), (0x11L > ((safe_sub_func_int64_t_s_s(((g_108[0] , g_960) && (((g_9.f5 == ((g_150 = ((safe_unary_minus_func_uint32_t_u((((safe_rshift_func_int16_t_s_u((g_1812[8].f1 = (g_27[2].f1 = (safe_add_func_uint8_t_u_u((((safe_mod_func_int64_t_s_s(((g_889[1][2][6] = l_21[0].f2) == 8UL), g_781)) || 0x7A04B492L) < l_1883[0][0]), 0L)))), l_1895.f9)) >= 0L) , 1UL))) ^ 0x22CD79FEL)) || g_1685[0][0][3])) < 0xDD6E50475242A0BCLL) == 1UL)), l_1974.f4)) , g_203[0][1][0].f0)))) || g_73[0].f9), 9)))) , g_203[0][1][0]);
    return g_9.f4;
}
static uint32_t func_13(struct S1 p_14, uint64_t p_15, int32_t p_16, int32_t p_17)
{
    return g_24;
}
static uint64_t func_36(uint32_t p_37, const struct S1 p_38)
{
    int16_t l_1236 = 0x21FAL;
    int32_t l_1245[9] = {0x15E64C40L, (-1L), 0x15E64C40L, (-1L), 0x15E64C40L, (-1L), 0x15E64C40L, (-1L), 0x15E64C40L};
    int32_t l_1246 = (-1L);
    int32_t l_1247 = 1L;
    uint8_t l_1248 = 8UL;
    const struct S2 l_1289 = {581,-2L,-4037,23,26,13,-114,1L,-92,-235};
    struct S0 l_1384 = {0x3E63CE16D3A0AE7CLL,0xE978L,3,168,39,-5788};
    uint64_t l_1397[3][8] = {{0UL, 18446744073709551615UL, 0UL, 0x34DD779508C0F1FFLL, 1UL, 0x0EC094A69C13F5D6LL, 3UL, 3UL}, {0UL, 18446744073709551615UL, 0UL, 0x34DD779508C0F1FFLL, 1UL, 0x0EC094A69C13F5D6LL, 3UL, 3UL}, {0UL, 18446744073709551615UL, 0UL, 0x34DD779508C0F1FFLL, 1UL, 0x0EC094A69C13F5D6LL, 3UL, 3UL}};
    struct S4 l_1410 = {0x6C2FL,6,1UL,0x41A1DE21F1F3A83DLL,0x9F9B33F4L,0x10AC0DD5C2FDB38ALL};
    int32_t l_1443 = 1L;
    struct S5 l_1495 = {191,5532,1022,497};
    uint64_t l_1578[8];
    const struct S4 l_1619 = {1UL,5,7UL,0xFD874BE8D84C9FEFLL,0x280CB640L,4L};
    uint32_t l_1625 = 0x96FAC3F0L;
    int i, j;
    for (i = 0; i < 8; i++)
        l_1578[i] = 1UL;
lbl_1475:
    l_1248 = (g_24 = (((safe_mod_func_uint8_t_u_u(0x5EL, ((g_339[0][0][4].f0 , ((((safe_mod_func_uint16_t_u_u((safe_add_func_int32_t_s_s(((l_1236 | ((((l_1247 = ((safe_unary_minus_func_int8_t_s((g_73[0].f9 > g_22.f3))) , ((g_22 , (((l_1246 = (safe_rshift_func_uint16_t_u_s((safe_add_func_uint32_t_u_u(((l_1245[5] = ((+(safe_lshift_func_uint16_t_u_s((g_73[0] , (p_38.f1 ^ g_108[0].f0)), 4))) == 0xA3L)) <= 0x159AL), g_1072[6])), 0))) & p_38.f1) && 0xF19CL)) ^ g_296))) > l_1236) , l_1236) <= (-7L))) >= p_37), 0x5E275BE6L)), 0x12B2L)) < 0xA1419B5FL) != 4294967295UL) , g_22)) , p_37))) == l_1236) != p_37));
    for (g_676 = 1; (g_676 >= 0); g_676 -= 1)
    {
        int64_t l_1258 = 0L;
        int32_t l_1259[9][8] = {{(-6L), (-6L), 0xCD79E64CL, 0xCD79E64CL, (-6L), (-6L), 0L, 0L}, {(-6L), (-6L), 0xCD79E64CL, 0xCD79E64CL, (-6L), (-6L), 0L, 0L}, {(-6L), (-6L), 0xCD79E64CL, 0xCD79E64CL, (-6L), (-6L), 0L, 0L}, {(-6L), (-6L), 0xCD79E64CL, 0xCD79E64CL, (-6L), (-6L), 0L, 0L}, {(-6L), (-6L), 0xCD79E64CL, 0xCD79E64CL, (-6L), (-6L), 0L, 0L}, {(-6L), (-6L), 0xCD79E64CL, 0xCD79E64CL, (-6L), (-6L), 0L, 0L}, {(-6L), (-6L), 0xCD79E64CL, 0xCD79E64CL, (-6L), (-6L), 0L, 0L}, {(-6L), (-6L), 0xCD79E64CL, 0xCD79E64CL, (-6L), (-6L), 0L, 0L}, {(-6L), (-6L), 0xCD79E64CL, 0xCD79E64CL, (-6L), (-6L), 0L, 0L}};
        uint64_t l_1272 = 0x59E004F14C4483EALL;
        int32_t l_1325 = 0x1A903C0BL;
        int16_t l_1355 = 0x6F9CL;
        struct S0 l_1357 = {18446744073709551609UL,1L,0,154,-27,8639};
        struct S0 l_1383 = {0x1EB445EF0AC5C575LL,-7L,1,488,304,6690};
        struct S5 l_1490 = {731,652,48,59};
        int32_t l_1526[1];
        struct S3 l_1597 = {1054,-234,1,-500,513};
        int16_t l_1700 = 0x9B9EL;
        int i, j;
        for (i = 0; i < 1; i++)
            l_1526[i] = 0xF4EB568AL;
        if ((safe_unary_minus_func_int32_t_s((safe_mod_func_uint16_t_u_u((l_1247 = ((safe_add_func_uint8_t_u_u((safe_mod_func_uint8_t_u_u((l_1245[5] && ((0x9B4EC88C991F62C4LL || g_9.f5) > 0L)), (safe_rshift_func_int16_t_s_s(((l_1258 & p_38.f1) > (l_1246 = g_108[0].f3)), (0xC6B35D4BC9A802C3LL != 3UL))))), l_1259[0][5])) | 0x9ADF0D09E0C282C1LL)), g_86)))))
        {
            struct S4 l_1260[8][10][3] = {{{{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}}, {{{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}}, {{{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}}, {{{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}}, {{{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}}, {{{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}}, {{{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}}, {{{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}, {{65530UL,2,0x37EA3820L,0xB47EBC5577C01A81LL,0x3877A61DL,0x5F5E6935799693BFLL}, {65535UL,7,0x93BB7A7BL,1UL,0x59DFD26BL,1L}, {0UL,2,2UL,0x99014C1791609063LL,0xDBCA31F0L,-1L}}}};
            int8_t l_1269 = 0x08L;
            int32_t l_1286[6] = {(-10L), (-10L), (-1L), (-10L), (-10L), (-1L)};
            struct S0 l_1315 = {0x726485ADE77FDC9DLL,0xB3B2L,-5,171,335,-8011};
            struct S3 l_1409[7][8][4] = {{{{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}}, {{{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}}, {{{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}}, {{{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}}, {{{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}}, {{{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}}, {{{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}, {{724,74,0,-990,402}, {13452,118,1,1708,1018}, {313,313,1,-2825,836}, {3193,59,1,-1058,678}}}};
            struct S5 l_1411 = {245,3247,206,274};
            int i, j, k;
            g_73[0].f9 = (l_1260[2][3][1] , ((safe_lshift_func_uint16_t_u_s((g_273.f3 || (-1L)), (safe_lshift_func_uint16_t_u_u(p_37, (safe_lshift_func_int8_t_s_u((safe_sub_func_uint64_t_u_u(l_1260[2][3][1].f1, (l_1246 = l_1269))), ((g_269[g_676] = ((g_203[0][1][0].f0 == (((safe_mod_func_uint64_t_u_u(((0L | (g_73[0].f9 >= 0x6CBEL)) != l_1258), l_1272)) >= (-1L)) & p_38.f0)) || l_1247)) == l_1236))))))) < 1L));
            for (p_37 = 0; (p_37 < 2); p_37 = safe_add_func_int16_t_s_s(p_37, 8))
            {
                uint64_t l_1285 = 18446744073709551614UL;
                struct S4 l_1298 = {0UL,1,0x58F588C3L,0x0FB6280D1F569EBBLL,2UL,0xCE0BE7390D31A608LL};
                struct S3 l_1342 = {8933,-469,0,1397,771};
                g_73[0].f6 = ((0x29L > p_38.f0) ^ (((safe_unary_minus_func_uint64_t_u(((-1L) | (((0UL < (safe_sub_func_int32_t_s_s(((l_1286[4] = (((safe_unary_minus_func_uint16_t_u(((l_1245[5] = p_38.f0) == (((g_269[g_676] = (safe_rshift_func_uint8_t_u_s((safe_sub_func_uint64_t_u_u((p_38.f1 | (safe_add_func_int64_t_s_s(((((((l_1246 = (l_1285 | (l_1247 = g_269[g_676]))) && (0UL != p_38.f0)) ^ p_38.f1) | 0x13D61ED0L) == 5L) != g_108[0].f2), l_1248))), 0x4D8E0A0C55677F59LL)), l_1260[2][3][1].f5))) | l_1285) | l_1259[0][5])))) , g_339[0][0][4]) , 0UL)) > l_1285), l_1272))) <= 0x99CEL) < 0xD3L)))) >= 1UL) > l_1260[2][3][1].f2));
                for (g_9.f1 = 1; (g_9.f1 > 15); ++g_9.f1)
                {
                    uint64_t l_1316 = 0xED93FC922A25BBBALL;
                    int32_t l_1326[8] = {0x80324973L, 0x20CD451CL, 0x80324973L, 0x20CD451CL, 0x80324973L, 0x20CD451CL, 0x80324973L, 0x20CD451CL};
                    struct S0 l_1358[9] = {{0x37D70826DADEB4D9LL,-1L,-4,322,65,2375}, {0x37D70826DADEB4D9LL,-1L,-4,322,65,2375}, {0x37D70826DADEB4D9LL,-1L,-4,322,65,2375}, {0x37D70826DADEB4D9LL,-1L,-4,322,65,2375}, {0x37D70826DADEB4D9LL,-1L,-4,322,65,2375}, {0x37D70826DADEB4D9LL,-1L,-4,322,65,2375}, {0x37D70826DADEB4D9LL,-1L,-4,322,65,2375}, {0x37D70826DADEB4D9LL,-1L,-4,322,65,2375}, {0x37D70826DADEB4D9LL,-1L,-4,322,65,2375}};
                    uint32_t l_1398 = 0UL;
                    int i;
                }
            }
            l_1384 = (((((((safe_rshift_func_uint8_t_u_u((~((1L != (g_269[g_676] = (((((safe_mod_func_uint16_t_u_u((p_38.f0 <= ((((g_73[0].f9 = 0xB21AA2E2L) <= (l_1325 = (safe_mod_func_uint64_t_u_u((safe_lshift_func_int8_t_s_u((safe_unary_minus_func_uint64_t_u(0x0AF2F182C2E9D129LL)), 7)), (((9L ^ 0xE04F3848L) , l_1409[0][2][0]) , g_269[1]))))) , 0x2DL) | p_37)), l_1315.f5)) , g_10.f1) & 0x0F3C89E7L) , l_1410) , p_38.f1))) , 0x35L)), 7)) < l_1315.f0) , 0xD6E3BDA044462821LL) > g_27[2].f0) <= 7UL) == g_9.f5) , l_1357);
            l_1411 = g_203[0][5][0];
        }
        else
        {
            int8_t l_1420 = 0L;
            int32_t l_1440[9] = {1L, 1L, 5L, 1L, 1L, 5L, 1L, 1L, 5L};
            int32_t l_1441 = (-1L);
            int32_t l_1442 = 0L;
            int32_t l_1444 = 0x5BFB504CL;
            int i;
            return l_1383.f5;
        }
        for (l_1357.f0 = 0; (l_1357.f0 <= 2); l_1357.f0 += 1)
        {
            int8_t l_1472 = 0x66L;
            const struct S1 l_1476 = {1311,-4L};
            struct S5 l_1496 = {214,1554,778,892};
            int32_t l_1527 = 0x51A54300L;
            uint32_t l_1544 = 0UL;
            int64_t l_1684 = 1L;
            uint16_t l_1763 = 65528UL;
            int i, j;
            if ((safe_add_func_uint32_t_u_u((safe_sub_func_uint32_t_u_u((((((safe_lshift_func_uint8_t_u_u(0xC2L, 3)) && (safe_add_func_uint8_t_u_u(g_269[g_676], (l_1397[g_676][(g_676 + 4)] | (((((safe_rshift_func_int8_t_s_s((safe_add_func_uint64_t_u_u((safe_sub_func_uint64_t_u_u(((18446744073709551608UL == (0UL ^ (safe_rshift_func_uint16_t_u_s((safe_mod_func_uint8_t_u_u((safe_lshift_func_uint8_t_u_s((safe_add_func_int8_t_s_s((+(l_1383.f2 = (g_108[0].f5 = (safe_lshift_func_uint16_t_u_s(p_37, g_296))))), (safe_mod_func_int16_t_s_s(((l_1472 = (g_9.f2 >= p_37)) > l_1384.f4), 0x4574L)))), p_38.f1)), g_73[0].f3)), g_1072[4])))) | p_38.f0), p_38.f0)), p_38.f1)), g_339[0][0][4].f3)) < l_1410.f1) | p_38.f0) && 3UL) > p_37))))) && 6L) < 0x7CC6L) | 5UL), 0x3280AF96L)), 0xF94DD478L)))
            {
                struct S0 l_1473 = {0xC3676140B37C1A43LL,6L,-5,136,54,10833};
                struct S0 l_1474 = {0x582C400B1B838996LL,0xEAF9L,1,487,-298,2522};
                for (g_24 = 0; (g_24 >= 0); g_24 -= 1)
                {
                    return l_1384.f1;
                }
            }
            else
            {
{
                        }
            }
{
                        const struct S0 l_1502 = {4UL,0x99C1L,5,48,108,-3955};
                        int i, j, k;
                        return g_9.f3;
                    }
safe_unary_minus_func_int8_t_s((g_1072[9] = ((-1L) && (safe_sub_func_uint16_t_u_u(0UL, (safe_rshift_func_uint16_t_u_u(g_273.f1, 3)))))));
func_1();
        }
{
                    return l_1384.f1;
                }
    }
    return g_22.f2;
}
inline static uint32_t func_39(uint32_t p_40)
{
    struct S1 l_58[3][9] = {{{-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}}, {{-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}}, {{-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}, {-19812,0x0DL}, {-4199,-5L}}};
    struct S2 l_72 = {477,0x0C72D929A3F8350FLL,-16,-116,50,4,49,0x7D6D0C92L,993,-1196};
    struct S4 l_74 = {0x1FB4L,5,0xC5185D9AL,3UL,18446744073709551615UL,-9L};
    int8_t l_351 = (-1L);
    uint32_t l_371 = 8UL;
    struct S5 l_412 = {902,4933,55,707};
    uint32_t l_450 = 0xBD74A63EL;
    uint16_t l_452 = 65535UL;
    uint64_t l_481 = 0x2EA35F2C107C717ELL;
    struct S0 l_501[1] = {{0x7B3B8669B236C857LL,-3L,-5,455,-183,-4066}};
    struct S3 l_521 = {14984,-199,0,2470,689};
    int32_t l_551 = 0xEC4CE2E5L;
    int32_t l_560 = 0x94E3466BL;
    uint8_t l_679 = 0x12L;
    int8_t l_803 = 0L;
    struct S5 l_804 = {850,4776,687,23};
    int8_t l_1112 = 0x36L;
    struct S5 l_1183[8][10][3] = {{{{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}}, {{{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}}, {{{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}}, {{{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}}, {{{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}}, {{{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}}, {{{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}}, {{{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}, {{247,3326,738,691}, {309,4062,663,711}, {279,5645,966,1342}}}};
    int16_t l_1209 = 8L;
    int64_t l_1228 = 0x7DABC0E09B7569C3LL;
    int i, j, k;
    if ((safe_mod_func_uint32_t_u_u(((g_52 = ((g_22.f4 <= g_22.f2) & 0x94C91969D30BDFC5LL)) == (g_339[0][0][4].f1 = (safe_unary_minus_func_uint64_t_u((safe_add_func_int64_t_s_s(g_24, (safe_rshift_func_uint16_t_u_s(func_13(l_58[0][1], p_40, (safe_add_func_int32_t_s_s(((l_351 = ((safe_mod_func_int32_t_s_s(((l_58[0][1].f1 || func_63(func_67((p_40 , l_72), p_40, g_73[0], l_74), g_273, p_40)) <= g_108[0].f3), 0xE1A09218L)) , (-1L))) && 2UL), g_73[0].f6)), g_22.f0), p_40)))))))), p_40)))
    {
        int16_t l_376 = 0xC9CAL;
        int32_t l_377 = 1L;
        uint8_t l_392 = 0x57L;
        struct S0 l_394 = {18446744073709551615UL,1L,1,292,-143,-6686};
        struct S5 l_411 = {477,3926,1058,856};
        struct S3 l_432 = {10045,25,1,2095,996};
        uint16_t l_631[9];
        struct S0 l_694 = {0x3900934FC7FD870ELL,0L,-0,231,-130,1463};
        struct S2 l_820 = {-488,0x7DDEE4DA94D3DADCLL,1670,-87,2,6,-64,0L,21263,-1211};
        uint32_t l_906 = 4294967286UL;
        int i;
{
                        int i;
                        return g_269[p_40];
                    }
    }
    else
    {
        int16_t l_940 = 0x747CL;
        struct S5 l_976 = {752,3070,666,803};
        struct S2 l_985 = {-430,8L,-2422,123,8,8,111,9L,-33816,673};
        struct S2 l_1013 = {150,0xB9CCE7EA254471EALL,1368,-2,48,9,9,0L,-33443,1222};
        struct S0 l_1046 = {0x103F007128161B6ALL,1L,-2,155,-288,9377};
        uint8_t l_1071 = 253UL;
        int32_t l_1113 = 0x2EF80F68L;
        struct S4 l_1129 = {0x4798L,6,4294967295UL,18446744073709551606UL,0x9FE72948L,0xFF9B8353669838C4LL};
        struct S0 l_1180 = {0x12EC1330787B3344LL,0xEBA1L,-7,80,72,-8956};
        struct S3 l_1182[3][9][7] = {{{{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}}, {{{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}}, {{{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}, {{5228,-264,1,2376,658}, {8912,-117,1,386,663}, {11309,-411,1,-2212,565}, {15138,385,1,680,479}, {14833,78,0,-2230,764}, {14791,-357,1,-2122,585}, {13116,40,1,311,731}}}};
        int32_t l_1229 = 0L;
        int i, j, k;
        for (l_481 = 0; (l_481 <= 1); l_481 += 1)
        {
            uint32_t l_939 = 5UL;
            int32_t l_942 = 0L;
            int32_t l_958[2];
            uint32_t l_986 = 18446744073709551615UL;
            int32_t l_1027 = 0L;
            struct S5 l_1075[6] = {{4,3927,515,535}, {930,579,349,1086}, {4,3927,515,535}, {930,579,349,1086}, {4,3927,515,535}, {930,579,349,1086}};
            uint16_t l_1137[7][4] = {{0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}};
            int i, j;
            for (i = 0; i < 2; i++)
                l_958[i] = 0x448A3032L;
            for (l_450 = 0; (l_450 <= 1); l_450 += 1)
            {
                uint64_t l_951 = 18446744073709551613UL;
                int16_t l_959 = (-1L);
                for (l_551 = 0; (l_551 <= 0); l_551 += 1)
                {
                    int32_t l_941[3][7] = {{(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}, {(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}, {(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}};
                    int i, j;
                    g_269[l_450] = ((g_598 = ((((safe_sub_func_uint64_t_u_u((safe_lshift_func_int16_t_s_s(((safe_mod_func_uint64_t_u_u((safe_add_func_uint64_t_u_u(0xF896DED7897C5ECCLL, g_269[(l_551 + 1)])), ((((l_940 = ((safe_lshift_func_uint8_t_u_s((((g_269[l_450] < g_269[1]) | (g_273 , (((safe_rshift_func_uint8_t_u_s((p_40 >= ((g_73[0].f6 < l_939) , 0xCDL)), p_40)) & g_269[(l_551 + 1)]) > g_73[0].f2))) || p_40), 7)) > 0x0233C3EF377F199ALL)) >= l_939) | 9L) ^ 0x2504L))) & g_269[1]), 7)), g_296)) | g_339[0][0][4].f1) || p_40) <= 1L)) && l_941[0][5]);
                }
                for (g_598 = 1; (g_598 >= 0); g_598 -= 1)
                {
                    struct S0 l_961[3] = {{3UL,0x5838L,-2,359,-99,7480}, {3UL,0x5838L,-2,359,-99,7480}, {3UL,0x5838L,-2,359,-99,7480}};
                    int i;
                    for (g_150 = 0; (g_150 <= 1); g_150 += 1)
                    {
                        l_942 = 0x931AD917L;
                    }
                    l_501[0] = (g_27[(g_598 + 2)] = ((safe_lshift_func_int8_t_s_u((safe_rshift_func_uint16_t_u_s((g_960 = ((g_269[l_481] && (((safe_add_func_int16_t_s_s(((0x940D10EFL & (((l_958[1] = ((((((safe_rshift_func_int16_t_s_s((g_483 || 0xFC7FDAECL), 5)) <= (l_951 & (safe_lshift_func_int16_t_s_u(((safe_rshift_func_uint8_t_u_s((((l_72 , (l_942 = p_40)) | (((l_521.f1 = g_73[0].f6) > (g_149 = ((((safe_sub_func_int8_t_s_s(0L, l_940)) <= l_939) , p_40) ^ 0x5CC57C77L))) != p_40)) <= p_40), l_951)) ^ 0x5A0C957AL), g_269[l_481])))) & p_40) || 18446744073709551608UL) || 0UL) == l_951)) != p_40) != p_40)) != l_959), 0xE127L)) ^ (-7L)) < p_40)) > l_959)), p_40)), p_40)) , l_961[1]));
                    for (l_939 = 0; (l_939 <= 0); l_939 += 1)
                    {
                        int i, j, k;
                        l_958[1] = ((safe_rshift_func_uint8_t_u_s((g_150 = l_958[1]), (safe_sub_func_uint32_t_u_u((((((safe_mod_func_int16_t_s_s(((0UL == ((safe_rshift_func_int16_t_s_s((g_24 || (0xEAD029DCL == (0xD70FL != (g_889[(g_598 + 1)][(l_939 + 2)][(g_598 + 7)] = (0xC60DL >= (safe_rshift_func_uint8_t_u_s(((g_73[0].f1 = (safe_lshift_func_uint16_t_u_s((l_72.f6 = 0UL), ((g_203[l_939][(l_939 + 4)][(l_481 + 1)] = g_273) , ((safe_sub_func_int16_t_s_s((-1L), g_273.f0)) > p_40))))) || g_10.f0), p_40))))))), g_108[0].f4)) || 8UL)) >= 0x09FEL), 0x5B66L)) != g_149) <= 0x1CB17CB439256F3ELL) , 0x68L) >= g_764), p_40)))) < 0x0FL);
                    }
                }
                for (l_959 = 0; (l_959 <= 0); l_959 += 1)
                {
                    int i, j, k;
                    g_203[l_959][(l_959 + 1)][(l_959 + 1)] = l_976;
                    l_986 = (((safe_mod_func_int64_t_s_s(((0UL <= (3L ^ (((g_27[2].f5 = (safe_add_func_int8_t_s_s((safe_add_func_uint64_t_u_u((((l_72.f6 = p_40) >= l_501[0].f2) , p_40), ((safe_lshift_func_int16_t_s_s((g_765 = (((l_985 , l_951) && p_40) > (p_40 && g_86))), 9)) ^ g_203[l_959][(l_959 + 1)][(l_959 + 1)].f3))), g_27[2].f1))) ^ g_22.f1) , 0x8767L))) == 0xF52F4C4E0AA0DBE2LL), g_273.f1)) , p_40) , g_9.f0);
                }
            }
            l_501[0] = g_339[0][0][4];
            l_942 = g_73[0].f3;
            for (l_803 = 0; (l_803 >= 0); l_803 -= 1)
            {
                uint8_t l_1014 = 2UL;
                int32_t l_1015 = (-10L);
                struct S3 l_1026 = {16307,-177,1,1348,353};
                int64_t l_1047 = (-5L);
                struct S0 l_1073 = {0xC1E047BE1F71BE01LL,0x2F22L,-7,204,-229,-11207};
                struct S2 l_1089 = {-703,-1L,2182,-54,35,18,33,0xB1897D62L,2582,-1306};
                const struct S0 l_1115 = {0x3E9A9ED5C230EBC7LL,3L,-7,231,58,5308};
                int64_t l_1122[6][6][1];
                struct S5 l_1160[6] = {{352,1689,1349,1088}, {366,956,1128,1041}, {352,1689,1349,1088}, {366,956,1128,1041}, {352,1689,1349,1088}, {366,956,1128,1041}};
                int i, j, k;
                for (i = 0; i < 6; i++)
                {
                    for (j = 0; j < 6; j++)
                    {
                        for (k = 0; k < 1; k++)
                            l_1122[i][j][k] = (-1L);
                    }
                }
                l_985.f2 = (safe_sub_func_uint16_t_u_u((safe_rshift_func_int8_t_s_u((l_58[0][1].f1 & (((safe_rshift_func_int8_t_s_s((safe_add_func_int64_t_s_s((((l_986 == ((safe_sub_func_int16_t_s_s((safe_add_func_uint16_t_u_u((l_72.f6 = ((((((safe_sub_func_uint8_t_u_u((0x988476C713D01462LL == (l_72.f7 = 0xE771FE284BD1490DLL)), p_40)) | (safe_sub_func_uint64_t_u_u((l_1015 = ((l_985.f7 = 0UL) & ((safe_add_func_uint16_t_u_u(2UL, 0x152DL)) ^ ((safe_mod_func_uint64_t_u_u((((safe_rshift_func_int16_t_s_s((safe_add_func_int32_t_s_s(((safe_sub_func_int64_t_s_s((g_483 = ((g_781 , l_1013) , l_1014)), p_40)) , l_551), g_27[2].f3)), 9)) == 0x56E198ECL) != g_73[0].f8), p_40)) , g_93)))), l_1014))) == 18446744073709551609UL) >= l_985.f0) <= l_958[1]) != p_40)), g_296)), g_150)) != p_40)) || l_1015) && g_27[2].f3), 0x5029941ABB8E884ALL)), 6)) , l_501[0]) , p_40)), 2)), g_22.f1));
                for (p_40 = 0; (p_40 <= 0); p_40 += 1)
                {
                    const struct S1 l_1025 = {-16655,1L};
                    l_958[1] = p_40;
                    if (g_273.f3)
                        break;
{
                    int32_t l_941[3][7] = {{(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}, {(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}, {(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}};
                    int i, j;
                }
{
            uint32_t l_939 = 5UL;
            int32_t l_942 = 0L;
            int32_t l_958[2];
            uint32_t l_986 = 18446744073709551615UL;
            int32_t l_1027 = 0L;
            struct S5 l_1075[6] = {{4,3927,515,535}, {930,579,349,1086}, {4,3927,515,535}, {930,579,349,1086}, {4,3927,515,535}, {930,579,349,1086}};
            uint16_t l_1137[7][4] = {{0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}};
            int i, j;
{
                uint64_t l_951 = 18446744073709551613UL;
                int16_t l_959 = (-1L);
            }
        }
{
                uint64_t l_951 = 18446744073709551613UL;
                int16_t l_959 = (-1L);
safe_lshift_func_int8_t_s_s(g_618, 5);
{
                        int i, j, k;
                        l_958[1] = ((safe_rshift_func_uint8_t_u_s((g_150 = l_958[1]), (safe_sub_func_uint32_t_u_u((((((safe_mod_func_int16_t_s_s(((0UL == ((safe_rshift_func_int16_t_s_s((g_24 || (0xEAD029DCL == (0xD70FL != (g_889[(g_598 + 1)][(l_939 + 2)][(g_598 + 7)] = (0xC60DL >= (safe_rshift_func_uint8_t_u_s(((g_73[0].f1 = (safe_lshift_func_uint16_t_u_s((l_72.f6 = 0UL), ((g_203[l_939][(l_939 + 4)][(l_481 + 1)] = g_273) , ((safe_sub_func_int16_t_s_s((-1L), g_273.f0)) > p_40))))) || g_10.f0), p_40))))))), g_108[0].f4)) || 8UL)) >= 0x09FEL), 0x5B66L)) != g_149) <= 0x1CB17CB439256F3ELL) , 0x68L) >= g_764), p_40)))) < 0x0FL);
                    }
safe_add_func_int32_t_s_s(g_86, 1);
safe_rshift_func_int16_t_s_u(g_9.f4, p_40);
safe_rshift_func_int16_t_s_s(((!((((l_521.f3 >= l_1014) & (4294967295UL > ((-1L) && p_40))) , l_1025) , g_764)) <= l_1025.f0), 1);
{
                    int32_t l_941[3][7] = {{(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}, {(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}, {(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}};
                    int i, j;
                    g_269[l_450] = ((g_598 = ((((safe_sub_func_uint64_t_u_u((safe_lshift_func_int16_t_s_s(((safe_mod_func_uint64_t_u_u((safe_add_func_uint64_t_u_u(0xF896DED7897C5ECCLL, g_269[(l_551 + 1)])), ((((l_940 = ((safe_lshift_func_uint8_t_u_s((((g_269[l_450] < g_269[1]) | (g_273 , (((safe_rshift_func_uint8_t_u_s((p_40 >= ((g_73[0].f6 < l_939) , 0xCDL)), p_40)) & g_269[(l_551 + 1)]) > g_73[0].f2))) || p_40), 7)) > 0x0233C3EF377F199ALL)) >= l_939) | 9L) ^ 0x2504L))) & g_269[1]), 7)), g_296)) | g_339[0][0][4].f1) || p_40) <= 1L)) && l_941[0][5]);
                }
{
                        struct S5 l_1163 = {278,2076,188,666};
                        int32_t l_1164 = (-10L);
                        int i, j, k;
                        g_203[l_371][(l_1046.f0 + 1)][(l_371 + 1)] = l_1163;
                        l_1164 = ((l_985.f3 = g_889[(l_1046.f0 + 1)][(l_371 + 1)][(l_351 + 2)]) >= p_40);
                    }
for (l_959 = 0; (l_959 <= 0); l_959 += 1)
                {
                    int i, j, k;
                    g_203[l_959][(l_959 + 1)][(l_959 + 1)] = l_976;
safe_rshift_func_uint16_t_u_s(func_13(l_58[0][1], p_40, (safe_add_func_int32_t_s_s(((l_351 = ((safe_mod_func_int32_t_s_s(((l_58[0][1].f1 || func_63(func_67((p_40 , l_72), p_40, g_73[0], l_74), g_273, p_40)) <= g_108[0].f3), 0xE1A09218L)) , (-1L))) && 2UL), g_73[0].f6)), g_22.f0), p_40);
safe_rshift_func_uint16_t_u_s((l_560 = l_74.f3), 2);
                };
            }
                }
                for (g_86 = 0; (g_86 >= 0); g_86 -= 1)
                {
                    uint16_t l_1028 = 0UL;
                    int32_t l_1074 = (-1L);
                    struct S1 l_1090 = {-9728,0L};
                    int32_t l_1114[7];
                    int i;
                    for (i = 0; i < 7; i++)
                        l_1114[i] = 1L;
                    if (l_1027)
{
{
                uint8_t l_1014 = 2UL;
                int32_t l_1015 = (-10L);
                struct S3 l_1026 = {16307,-177,1,1348,353};
                int64_t l_1047 = (-5L);
                struct S0 l_1073 = {0xC1E047BE1F71BE01LL,0x2F22L,-7,204,-229,-11207};
                struct S2 l_1089 = {-703,-1L,2182,-54,35,18,33,0xB1897D62L,2582,-1306};
                const struct S0 l_1115 = {0x3E9A9ED5C230EBC7LL,3L,-7,231,58,5308};
                int64_t l_1122[6][6][1];
                struct S5 l_1160[6] = {{352,1689,1349,1088}, {366,956,1128,1041}, {352,1689,1349,1088}, {366,956,1128,1041}, {352,1689,1349,1088}, {366,956,1128,1041}};
                int i, j, k;
for (l_74.f4 = 0; (l_74.f4 <= 0); l_74.f4 += 1)
                    {
                        struct S3 l_449 = {10497,-301,1,1373,517};
                        uint32_t l_451 = 0x017DA7A8L;
                    };
{
                        uint64_t l_1143 = 0x54000CE77C3BF4DCLL;
                        int i, j, k;
                        l_1073 = g_27[2];
safe_rshift_func_uint8_t_u_s((((((safe_sub_func_uint8_t_u_u(248UL, (((l_985.f8 = (g_960 = 0x77L)) ^ (safe_add_func_int8_t_s_s((p_40 >= ((l_1228 = (safe_sub_func_int32_t_s_s(g_1072[7], 4294967295UL))) > 0x4047L)), l_1013.f8))) > (-1L)))) < 0xBDB10223AC497E10LL) ^ l_1182[1][3][2].f0) || l_1013.f5) >= g_339[0][0][4].f4), p_40);
safe_rshift_func_int16_t_s_u(g_9.f4, p_40);
l_450 += 1;
                    }
{
                        int i;
                        return g_269[p_40];
                    }
            }
{
                    const struct S1 l_1025 = {-16655,1L};
safe_add_func_int8_t_s_s((-1L), (p_40 , p_40));
safe_sub_func_int8_t_s_s(0x32L, g_27[2].f1);
printf("index = [%d]\n", i);
safe_add_func_int16_t_s_s(g_150, 6);
g_86 -= 1;
{
                        int i;
                        return g_269[p_40];
                    }
                    if (g_273.f3)
{
safe_sub_func_uint8_t_u_u(248UL, (((l_985.f8 = (g_960 = 0x77L)) ^ (safe_add_func_int8_t_s_s((p_40 >= ((l_1228 = (safe_sub_func_int32_t_s_s(g_1072[7], 4294967295UL))) > 0x4047L)), l_1013.f8))) > (-1L)));
safe_lshift_func_int8_t_s_s(((safe_rshift_func_uint8_t_u_s((safe_sub_func_uint8_t_u_u((safe_rshift_func_uint16_t_u_s(p_40, g_339[0][0][4].f2)), ((l_942 < ((safe_unary_minus_func_int32_t_s(0L)) != (((((safe_sub_func_uint64_t_u_u((safe_rshift_func_uint16_t_u_s((l_1046.f0 | p_40), g_273.f2)), l_1028)) , l_1026.f4) >= g_269[0]) | l_1071) <= 0x96EB3892L))) || 0xE0L))), 7)) > g_9.f4), g_73[0].f0);
}
for (l_551 = 0; (l_551 <= 0); l_551 += 1)
                {
                    int32_t l_941[3][7] = {{(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}, {(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}, {(-10L), 0x079A3D73L, 0x9BC1A4CFL, 0x1FC1095AL, 0x1FC1095AL, 0x9BC1A4CFL, 0x079A3D73L}};
                    int i, j;
                    g_269[l_450] = ((g_598 = ((((safe_sub_func_uint64_t_u_u((safe_lshift_func_int16_t_s_s(((safe_mod_func_uint64_t_u_u((safe_add_func_uint64_t_u_u(0xF896DED7897C5ECCLL, g_269[(l_551 + 1)])), ((((l_940 = ((safe_lshift_func_uint8_t_u_s((((g_269[l_450] < g_269[1]) | (g_273 , (((safe_rshift_func_uint8_t_u_s((p_40 >= ((g_73[0].f6 < l_939) , 0xCDL)), p_40)) & g_269[(l_551 + 1)]) > g_73[0].f2))) || p_40), 7)) > 0x0233C3EF377F199ALL)) >= l_939) | 9L) ^ 0x2504L))) & g_269[1]), 7)), g_296)) | g_339[0][0][4].f1) || p_40) <= 1L)) && l_941[0][5]);
                };
safe_rshift_func_uint16_t_u_u((l_521.f4 <= p_40), 14);
safe_lshift_func_int8_t_s_s((1L | l_1112), 6);
                }
}
                    for (l_1013.f7 = 0; (l_1013.f7 >= 0); l_1013.f7 -= 1)
                    {
                        l_1028 = l_985.f5;
                        return g_27[2].f0;
                    }
{
            uint32_t l_939 = 5UL;
            int32_t l_942 = 0L;
            int32_t l_958[2];
            uint32_t l_986 = 18446744073709551615UL;
            int32_t l_1027 = 0L;
            struct S5 l_1075[6] = {{4,3927,515,535}, {930,579,349,1086}, {4,3927,515,535}, {930,579,349,1086}, {4,3927,515,535}, {930,579,349,1086}};
            uint16_t l_1137[7][4] = {{0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}, {0x0665L, 0x1E43L, 0x752BL, 2UL}};
            int i, j;
g_24 -= 1;
safe_add_func_uint8_t_u_u(0xB1L, (safe_lshift_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(0x6F01L, 14)), 3)));
safe_sub_func_uint64_t_u_u((g_155 && g_27[2].f2), g_108[0].f0);
safe_unary_minus_func_uint64_t_u((safe_add_func_int64_t_s_s(g_24, (safe_rshift_func_uint16_t_u_s(func_13(l_58[0][1], p_40, (safe_add_func_int32_t_s_s(((l_351 = ((safe_mod_func_int32_t_s_s(((l_58[0][1].f1 || func_63(func_67((p_40 , l_72), p_40, g_73[0], l_74), g_273, p_40)) <= g_108[0].f3), 0xE1A09218L)) , (-1L))) && 2UL), g_73[0].f6)), g_22.f0), p_40)))));
func_13(l_58[0][1], p_40, (safe_add_func_int32_t_s_s(((l_351 = ((safe_mod_func_int32_t_s_s(((l_58[0][1].f1 || func_63(func_67((p_40 , l_72), p_40, g_73[0], l_74), g_273, p_40)) <= g_108[0].f3), 0xE1A09218L)) , (-1L))) && 2UL), g_73[0].f6)), g_22.f0);
{
                    const struct S1 l_1025 = {-16655,1L};
                    l_958[1] = p_40;
safe_rshift_func_uint8_t_u_s(0x69L, 6);
safe_rshift_func_uint16_t_u_s(p_40, g_339[0][0][4].f2);
                    g_73[0].f6 = (l_72.f3 = (l_976 , (((((((l_942 <= (safe_mod_func_uint16_t_u_u((safe_add_func_uint64_t_u_u((safe_add_func_uint32_t_u_u(((3L | (l_958[1] = (1L > (18446744073709551613UL | (safe_rshift_func_int16_t_s_s(((!((((l_521.f3 >= l_1014) & (4294967295UL > ((-1L) && p_40))) , l_1025) , g_764)) <= l_1025.f0), 1)))))) <= p_40), 0L)), p_40)), p_40))) , l_1026) , l_1026.f3) ^ 0xA1E36552L) <= p_40) <= l_1025.f1) <= g_27[2].f4)));
                }
g_483 -= 1;
safe_rshift_func_uint8_t_u_s((g_150 = l_958[1]), (safe_sub_func_uint32_t_u_u((((((safe_mod_func_int16_t_s_s(((0UL == ((safe_rshift_func_int16_t_s_s((g_24 || (0xEAD029DCL == (0xD70FL != (g_889[(g_598 + 1)][(l_939 + 2)][(g_598 + 7)] = (0xC60DL >= (safe_rshift_func_uint8_t_u_s(((g_73[0].f1 = (safe_lshift_func_uint16_t_u_s((l_72.f6 = 0UL), ((g_203[l_939][(l_939 + 4)][(l_481 + 1)] = g_273) , ((safe_sub_func_int16_t_s_s((-1L), g_273.f0)) > p_40))))) || g_10.f0), p_40))))))), g_108[0].f4)) || 8UL)) >= 0x09FEL), 0x5B66L)) != g_149) <= 0x1CB17CB439256F3ELL) , 0x68L) >= g_764), p_40)));
{
                        struct S3 l_449 = {10497,-301,1,1373,517};
                        uint32_t l_451 = 0x017DA7A8L;
                    }
l_74.f5 += 1;
safe_mod_func_int16_t_s_s(g_73[0].f2, g_155);
safe_rshift_func_uint16_t_u_s(p_40, 11);
safe_sub_func_int64_t_s_s((((p_40 , ((safe_lshift_func_uint16_t_u_u((safe_lshift_func_uint8_t_u_u((l_1089 , ((l_1090 , (safe_add_func_int8_t_s_s((safe_sub_func_int16_t_s_s(((safe_unary_minus_func_uint8_t_u(((safe_lshift_func_int16_t_s_u((safe_add_func_uint32_t_u_u((((l_1046.f4 = ((safe_sub_func_uint8_t_u_u(g_86, ((((safe_sub_func_uint64_t_u_u((safe_lshift_func_int16_t_s_s((g_27[(l_481 + 4)].f5 = ((safe_lshift_func_int16_t_s_s((safe_sub_func_int64_t_s_s((safe_lshift_func_int8_t_s_s((1L | l_1112), 6)), l_1046.f2)), p_40)) <= 5UL)), 10)), p_40)) || g_203[g_86][(l_481 + 2)][(l_481 + 1)].f0) || p_40) == (-1L)))) != 0x0FL)) <= 0xAA82L) > 0L), 0x2729E98CL)), 13)) == l_1013.f7))) < g_9.f0), g_27[2].f1)), 248UL))) < g_203[0][1][0].f1)), g_86)), 6)) , p_40)) || p_40) <= 0xAAL), g_22.f1);
safe_add_func_int32_t_s_s(((l_351 = ((safe_mod_func_int32_t_s_s(((l_58[0][1].f1 || func_63(func_67((p_40 , l_72), p_40, g_73[0], l_74), g_273, p_40)) <= g_108[0].f3), 0xE1A09218L)) , (-1L))) && 2UL), g_73[0].f6);
{
                        int i, j, k;
                    }
        }
{
                        return g_27[2].f0;
                    }
safe_sub_func_int16_t_s_s(((safe_unary_minus_func_uint8_t_u(((safe_lshift_func_int16_t_s_u((safe_add_func_uint32_t_u_u((((l_1046.f4 = ((safe_sub_func_uint8_t_u_u(g_86, ((((safe_sub_func_uint64_t_u_u((safe_lshift_func_int16_t_s_s((g_27[(l_481 + 4)].f5 = ((safe_lshift_func_int16_t_s_s((safe_sub_func_int64_t_s_s((safe_lshift_func_int8_t_s_s((1L | l_1112), 6)), l_1046.f2)), p_40)) <= 5UL)), 10)), p_40)) || g_203[g_86][(l_481 + 2)][(l_481 + 1)].f0) || p_40) == (-1L)))) != 0x0FL)) <= 0xAA82L) > 0L), 0x2729E98CL)), 13)) == l_1013.f7))) < g_9.f0), g_27[2].f1);
                }
            }
        }
lbl_1211:
        g_73[0].f7 = g_150;
{
    return g_24;
}
safe_add_func_uint64_t_u_u(g_73[0].f8, 0L);
    }
    return l_72.f4;
}
static int32_t func_63(int16_t p_64, struct S5 p_65, const uint32_t p_66)
{
    uint32_t l_288 = 0UL;
    struct S4 l_289 = {65532UL,6,0x35E70CFAL,0xC17FFCD7FADE429BLL,0xF84BF215L,0L};
    int32_t l_292 = 2L;
    int32_t l_293[1][8] = {{0x4F262596L, 0x4F262596L, 1L, 0x4F262596L, 0x4F262596L, 1L, 0x4F262596L, 0x4F262596L}};
    uint8_t l_298 = 0x1DL;
    int64_t l_326 = 0x2F8A94D586B5BE49LL;
    int32_t l_329 = 1L;
    int32_t l_330 = 0x627E4599L;
    struct S0 l_336 = {0xF8C14BD2D97CD9DELL,0x6A59L,-3,462,151,-5450};
    int i, j;
lbl_333:
    for (g_9.f1 = 11; (g_9.f1 != (-18)); g_9.f1 = safe_sub_func_uint64_t_u_u(g_9.f1, 6))
    {
        uint64_t l_283 = 0x2A690D6E4B812A76LL;
        int32_t l_294 = (-2L);
        int32_t l_295 = 0L;
        int32_t l_297[7][6] = {{0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}};
        int64_t l_299 = 0L;
        int i, j;
        l_299 = ((((((l_297[0][0] = ((safe_sub_func_int8_t_s_s(((((g_203[0][1][0].f2 = (((safe_rshift_func_uint16_t_u_s((((!(safe_mod_func_int16_t_s_s(l_283, (safe_lshift_func_int8_t_s_u(((g_27[2].f2 , (safe_rshift_func_int8_t_s_s(((((g_73[0].f1 = 0x13720E50DB341854LL) > ((l_288 , l_289) , (((g_296 = (l_295 = ((l_294 = ((g_149 = (g_273.f2 >= g_273.f2)) & ((safe_mod_func_int32_t_s_s(((l_292 = g_9.f2) && (g_150 <= 0xCD95L)), l_293[0][1])) ^ p_66))) > 0x57D6D14A0CEEA609LL))) & 65533UL) <= g_9.f2))) , (-1L)) > 0L), 3))) | g_269[0]), 2))))) == g_27[2].f5) <= 0UL), l_293[0][1])) ^ l_288) || g_86)) || 4294967295UL) > 0L) <= 0xC7425C81DCE8F086LL), (-1L))) ^ g_22.f0)) || 255UL) & p_65.f1) , l_298) | p_66) ^ l_293[0][1]);
    }
safe_rshift_func_uint16_t_u_u(g_1716[6][0][3], 14);
safe_rshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s(p_65.f1, (((0xF852L || ((l_292 = (safe_lshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s(0xA5A30E26L, p_65.f0)), (safe_sub_func_uint32_t_u_u((g_9.f3 = (g_273.f2 < (safe_lshift_func_int8_t_s_s(l_326, 0)))), (((((((safe_add_func_int64_t_s_s((0xBEL | p_65.f0), p_66)) & g_203[0][1][0].f2) == l_289.f5) ^ p_64) , 0x9663L) != l_293[0][5]) ^ p_66)))))) > p_66)) < 0xDD45D62814947395LL) || p_65.f1))), 11)), p_65.f3);
safe_rshift_func_uint16_t_u_s(0x7F78L, 9);
g_764 += 1;
safe_rshift_func_uint16_t_u_u(((safe_rshift_func_int8_t_s_s((8L <= (g_108[0].f5 = ((l_329 = (safe_rshift_func_int16_t_s_s((safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s(p_65.f1, (((0xF852L || ((l_292 = (safe_lshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s(0xA5A30E26L, p_65.f0)), (safe_sub_func_uint32_t_u_u((g_9.f3 = (g_273.f2 < (safe_lshift_func_int8_t_s_s(l_326, 0)))), (((((((safe_add_func_int64_t_s_s((0xBEL | p_65.f0), p_66)) & g_203[0][1][0].f2) == l_289.f5) ^ p_64) , 0x9663L) != l_293[0][5]) ^ p_66)))))) > p_66)) < 0xDD45D62814947395LL) || p_65.f1))), 11)), p_65.f3))) < g_22.f4))), g_203[0][1][0].f1)) == g_10.f1), g_155);
safe_sub_func_int8_t_s_s(0x32L, g_27[2].f1);
safe_mod_func_uint16_t_u_u(g_273.f0, g_9.f1);
safe_add_func_uint64_t_u_u(g_10.f1, g_1812[8].f4);
safe_rshift_func_uint8_t_u_s(0x69L, 6);
safe_mod_func_int64_t_s_s((safe_mod_func_int16_t_s_s(g_73[0].f2, g_155)), 0x4BD96751E06E49FELL);
safe_rshift_func_int8_t_s_u(g_203[0][1][0].f0, 5);
for (g_9.f1 = 11; (g_9.f1 != (-18)); g_9.f1 = safe_sub_func_uint64_t_u_u(g_9.f1, 6))
    {
        uint64_t l_283 = 0x2A690D6E4B812A76LL;
        int32_t l_294 = (-2L);
        int32_t l_295 = 0L;
        int32_t l_297[7][6] = {{0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}};
        int64_t l_299 = 0L;
        int i, j;
    };
safe_lshift_func_int8_t_s_u((safe_unary_minus_func_uint64_t_u(0x0AF2F182C2E9D129LL)), 7);
safe_lshift_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(0x6F01L, 14)), 3);
{
        struct S0 l_337 = {18446744073709551615UL,0xFDE8L,4,337,6,-7047};
        struct S2 l_342 = {81,0x64AEC5BDDA8C6CA8LL,-1172,-110,6,0,8,0xD32296FFL,-37006,-62};
        int32_t l_350 = 0x840EB7FAL;
    }
safe_lshift_func_int8_t_s_u(0x31L, 1);
safe_sub_func_int32_t_s_s(0xA5A30E26L, p_65.f0);
safe_sub_func_int8_t_s_s(0x32L, g_27[2].f1);
safe_rshift_func_int16_t_s_u(g_22.f0, 14);
safe_rshift_func_int8_t_s_u(g_203[0][1][0].f0, 5);
safe_sub_func_uint32_t_u_u((g_9.f3 = (g_273.f2 < (safe_lshift_func_int8_t_s_s(l_326, 0)))), (((((((safe_add_func_int64_t_s_s((0xBEL | p_65.f0), p_66)) & g_203[0][1][0].f2) == l_289.f5) ^ p_64) , 0x9663L) != l_293[0][5]) ^ p_66));
for (g_86 = 0; (g_86 < 28); g_86 = safe_add_func_int32_t_s_s(g_86, 1))
    {
        struct S0 l_337 = {18446744073709551615UL,0xFDE8L,4,337,6,-7047};
        struct S2 l_342 = {81,0x64AEC5BDDA8C6CA8LL,-1172,-110,6,0,8,0xD32296FFL,-37006,-62};
        int32_t l_350 = 0x840EB7FAL;
g_676 -= 1;
g_676 -= 1;
safe_rshift_func_int16_t_s_s((safe_add_func_int8_t_s_s(p_65.f1, (((0xF852L || ((l_292 = (safe_lshift_func_int16_t_s_u((safe_sub_func_int32_t_s_s(0xA5A30E26L, p_65.f0)), (safe_sub_func_uint32_t_u_u((g_9.f3 = (g_273.f2 < (safe_lshift_func_int8_t_s_s(l_326, 0)))), (((((((safe_add_func_int64_t_s_s((0xBEL | p_65.f0), p_66)) & g_203[0][1][0].f2) == l_289.f5) ^ p_64) , 0x9663L) != l_293[0][5]) ^ p_66)))))) > p_66)) < 0xDD45D62814947395LL) || p_65.f1))), 11);
    };
safe_rshift_func_uint16_t_u_u(g_273.f1, 3);
safe_mod_func_uint16_t_u_u(g_273.f0, g_9.f1);
g_24 -= 1;
safe_unary_minus_func_uint64_t_u(0x0AF2F182C2E9D129LL);
g_150 += 1;
g_86 -= 1;
func_1();
safe_lshift_func_uint16_t_u_u(g_1072[4], g_108[0].f3);
safe_lshift_func_uint8_t_u_s((0x5F79L > g_73[0].f9), 2);
g_765 -= 1;
g_1945 += 1;
safe_lshift_func_int8_t_s_s(l_326, 0);
safe_add_func_int16_t_s_s(g_150, 6);
{
        uint64_t l_283 = 0x2A690D6E4B812A76LL;
        int32_t l_294 = (-2L);
        int32_t l_295 = 0L;
        int32_t l_297[7][6] = {{0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}, {0L, 0L, (-6L), (-2L), 0L, 0x0F967181L}};
        int64_t l_299 = 0L;
        int i, j;
    }
    return g_273.f3;
}
static int16_t func_67(struct S2 p_68, int32_t p_69, struct S2 p_70, struct S4 p_71)
{
    int8_t l_262 = (-10L);
    int32_t l_272 = 0xB596BDCCL;
    return p_70.f4;
}
static int16_t func_75(struct S3 p_76, int32_t p_77, int8_t p_78, struct S3 p_79)
{
    uint64_t l_268 = 0x47392D7B4DC1F5D4LL;
    uint64_t l_271 = 18446744073709551615UL;
platform_main_begin();
g_1945 += 1;
safe_rshift_func_int16_t_s_u(0x6F01L, 14);
    return l_271;
}
inline static int16_t func_81(uint16_t p_82)
{
    uint32_t l_92 = 0x438A7DDCL;
    struct S0 l_228 = {0x5DC99D9228643DB2LL,-1L,2,26,341,2503};
    struct S4 l_231 = {0UL,0,0x96F064E6L,18446744073709551611UL,0xBE5C4668L,0xB365A6C28FBAF897LL};
    const struct S5 l_232 = {968,1102,1144,76};
    struct S2 l_239[10] = {{-170,0xD3031F6BE0B242C8LL,1591,-70,55,13,-17,0x3A4FACB9L,10238,-633}, {-376,0x7CD0A77BDA6F53CELL,-3972,-55,40,11,-112,-6L,7722,168}, {-170,0xD3031F6BE0B242C8LL,1591,-70,55,13,-17,0x3A4FACB9L,10238,-633}, {-376,0x7CD0A77BDA6F53CELL,-3972,-55,40,11,-112,-6L,7722,168}, {-170,0xD3031F6BE0B242C8LL,1591,-70,55,13,-17,0x3A4FACB9L,10238,-633}, {-376,0x7CD0A77BDA6F53CELL,-3972,-55,40,11,-112,-6L,7722,168}, {-170,0xD3031F6BE0B242C8LL,1591,-70,55,13,-17,0x3A4FACB9L,10238,-633}, {-376,0x7CD0A77BDA6F53CELL,-3972,-55,40,11,-112,-6L,7722,168}, {-170,0xD3031F6BE0B242C8LL,1591,-70,55,13,-17,0x3A4FACB9L,10238,-633}, {-376,0x7CD0A77BDA6F53CELL,-3972,-55,40,11,-112,-6L,7722,168}};
    uint32_t l_244[4];
    struct S3 l_245 = {4560,-492,0,2660,653};
    uint64_t l_246 = 0xA700E2B5147D163DLL;
    struct S1 l_257 = {21674,9L};
    int i;
    for (i = 0; i < 4; i++)
        {
l_244[i] = 0x706DE4CBL;
g_93 += 1;
}
lbl_230:
    for (g_86 = 0; (g_86 != 18); g_86 = safe_add_func_uint64_t_u_u(g_86, 3))
    {
        int32_t l_94[6] = {2L, 0L, 2L, 0L, 2L, 0L};
        int8_t l_227 = 7L;
        int32_t l_229 = 3L;
        int i;
        l_228.f5 = ((l_227 = func_89(l_92, ((l_94[3] = (g_93 = 0xCB60L)) | (g_73[0] , (0L < p_82))))) < (l_228 , (l_229 = g_108[0].f3)));
        if (g_22.f2)
            goto lbl_230;
    }
    l_246 = ((((((l_92 , l_231) , l_232) , ((safe_rshift_func_int16_t_s_u((((safe_rshift_func_int8_t_s_u(((safe_sub_func_uint8_t_u_u(((l_228.f4 = l_228.f4) < 1UL), (((g_10 , l_239[8]) , l_239[8]) , ((safe_lshift_func_uint8_t_u_s(((((safe_lshift_func_int8_t_s_s(0x35L, p_82)) & l_244[1]) , l_231) , g_73[0].f9), 3)) <= 0xAFEB27DD0A5689C2LL)))) != 0xEF935917L), p_82)) == 0UL) & p_82), p_82)) , l_245)) , (-7L)) >= g_108[0].f0) > 1L);
g_296 += 1;
safe_lshift_func_int8_t_s_s(g_618, 5);
    return p_82;
}
static int16_t func_89(int16_t p_90, int16_t p_91)
{
    struct S0 l_95 = {0xC01D43B640E48530LL,0L,-1,83,279,-4852};
    struct S3 l_96 = {12677,-276,0,1460,536};
    struct S5 l_97 = {404,1225,1091,858};
    struct S2 l_109 = {-119,0xFFE616AD06E79B7CLL,3333,-40,66,16,67,0L,-27793,840};
g_765 -= 1;
safe_sub_func_int16_t_s_s(g_889[2][2][5], g_108[0].f3);
safe_lshift_func_uint8_t_u_u(g_149, 1);
safe_mod_func_int16_t_s_s(g_73[0].f2, g_155);
safe_add_func_uint32_t_u_u((safe_sub_func_int16_t_s_s(((0xE2F0389D981C66F5LL <= (safe_add_func_uint8_t_u_u(0xB1L, (safe_lshift_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(0x6F01L, 14)), 3))))) < 0UL), 1L)), g_22.f3);
safe_sub_func_int16_t_s_s(((0xE2F0389D981C66F5LL <= (safe_add_func_uint8_t_u_u(0xB1L, (safe_lshift_func_uint8_t_u_u((safe_rshift_func_int16_t_s_u(0x6F01L, 14)), 3))))) < 0UL), 1L);
g_9.f1 += 1;
safe_add_func_uint64_t_u_u(g_86, 3);
g_150 += 1;
safe_lshift_func_int8_t_s_s(((safe_lshift_func_int8_t_s_s(g_27[2].f1, 0)) == g_73[0].f4), 0);
    return g_27[2].f2;
}
static uint32_t func_102(struct S4 p_103, struct S3 p_104, struct S2 p_105, uint16_t p_106, struct S4 p_107)
{
    uint32_t l_116 = 0x4FE813D7L;
    struct S0 l_124 = {18446744073709551613UL,1L,6,201,94,-6325};
    int32_t l_136 = 1L;
    struct S0 l_137 = {0UL,0x4945L,0,367,-148,5293};
    int32_t l_138 = 0xE7AA7DC9L;
    uint64_t l_139 = 18446744073709551615UL;
    uint32_t l_170 = 9UL;
    return g_73[0].f8;
}
int main (int argc, char* argv[])
{
    int i, j, k;
    int print_hash_value = 0;
    if (argc == 2 && strcmp(argv[1], "1") == 0) print_hash_value = 1;
    platform_main_begin();
    crc32_gentab();
    func_1();
    transparent_crc(g_9.f0, "g_9.f0", print_hash_value);
    transparent_crc(g_9.f1, "g_9.f1", print_hash_value);
    transparent_crc(g_9.f2, "g_9.f2", print_hash_value);
    transparent_crc(g_9.f3, "g_9.f3", print_hash_value);
    transparent_crc(g_9.f4, "g_9.f4", print_hash_value);
    transparent_crc(g_9.f5, "g_9.f5", print_hash_value);
    transparent_crc(g_10.f0, "g_10.f0", print_hash_value);
    transparent_crc(g_10.f1, "g_10.f1", print_hash_value);
    transparent_crc(g_22.f0, "g_22.f0", print_hash_value);
    transparent_crc(g_22.f1, "g_22.f1", print_hash_value);
    transparent_crc(g_22.f2, "g_22.f2", print_hash_value);
    transparent_crc(g_22.f3, "g_22.f3", print_hash_value);
    transparent_crc(g_22.f4, "g_22.f4", print_hash_value);
    transparent_crc(g_24, "g_24", print_hash_value);
    for (i = 0; i < 6; i++)
    {
        transparent_crc(g_27[i].f0, "g_27[i].f0", print_hash_value);
        transparent_crc(g_27[i].f1, "g_27[i].f1", print_hash_value);
        transparent_crc(g_27[i].f2, "g_27[i].f2", print_hash_value);
        transparent_crc(g_27[i].f3, "g_27[i].f3", print_hash_value);
        transparent_crc(g_27[i].f4, "g_27[i].f4", print_hash_value);
        transparent_crc(g_27[i].f5, "g_27[i].f5", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_52, "g_52", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_73[i].f0, "g_73[i].f0", print_hash_value);
        transparent_crc(g_73[i].f1, "g_73[i].f1", print_hash_value);
        transparent_crc(g_73[i].f2, "g_73[i].f2", print_hash_value);
        transparent_crc(g_73[i].f3, "g_73[i].f3", print_hash_value);
        transparent_crc(g_73[i].f4, "g_73[i].f4", print_hash_value);
        transparent_crc(g_73[i].f5, "g_73[i].f5", print_hash_value);
        transparent_crc(g_73[i].f6, "g_73[i].f6", print_hash_value);
        transparent_crc(g_73[i].f7, "g_73[i].f7", print_hash_value);
        transparent_crc(g_73[i].f8, "g_73[i].f8", print_hash_value);
        transparent_crc(g_73[i].f9, "g_73[i].f9", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_86, "g_86", print_hash_value);
    transparent_crc(g_93, "g_93", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        transparent_crc(g_108[i].f0, "g_108[i].f0", print_hash_value);
        transparent_crc(g_108[i].f1, "g_108[i].f1", print_hash_value);
        transparent_crc(g_108[i].f2, "g_108[i].f2", print_hash_value);
        transparent_crc(g_108[i].f3, "g_108[i].f3", print_hash_value);
        transparent_crc(g_108[i].f4, "g_108[i].f4", print_hash_value);
        transparent_crc(g_108[i].f5, "g_108[i].f5", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_149, "g_149", print_hash_value);
    transparent_crc(g_150, "g_150", print_hash_value);
    transparent_crc(g_155, "g_155", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 6; j++)
        {
            for (k = 0; k < 3; k++)
            {
                transparent_crc(g_203[i][j][k].f0, "g_203[i][j][k].f0", print_hash_value);
                transparent_crc(g_203[i][j][k].f1, "g_203[i][j][k].f1", print_hash_value);
                transparent_crc(g_203[i][j][k].f2, "g_203[i][j][k].f2", print_hash_value);
                transparent_crc(g_203[i][j][k].f3, "g_203[i][j][k].f3", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    for (i = 0; i < 2; i++)
    {
        transparent_crc(g_269[i], "g_269[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_273.f0, "g_273.f0", print_hash_value);
    transparent_crc(g_273.f1, "g_273.f1", print_hash_value);
    transparent_crc(g_273.f2, "g_273.f2", print_hash_value);
    transparent_crc(g_273.f3, "g_273.f3", print_hash_value);
    transparent_crc(g_296, "g_296", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 5; k++)
            {
                transparent_crc(g_339[i][j][k].f0, "g_339[i][j][k].f0", print_hash_value);
                transparent_crc(g_339[i][j][k].f1, "g_339[i][j][k].f1", print_hash_value);
                transparent_crc(g_339[i][j][k].f2, "g_339[i][j][k].f2", print_hash_value);
                transparent_crc(g_339[i][j][k].f3, "g_339[i][j][k].f3", print_hash_value);
                transparent_crc(g_339[i][j][k].f4, "g_339[i][j][k].f4", print_hash_value);
                transparent_crc(g_339[i][j][k].f5, "g_339[i][j][k].f5", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    transparent_crc(g_483, "g_483", print_hash_value);
    transparent_crc(g_598, "g_598", print_hash_value);
    transparent_crc(g_618, "g_618", print_hash_value);
    transparent_crc(g_676, "g_676", print_hash_value);
    transparent_crc(g_764, "g_764", print_hash_value);
    transparent_crc(g_765, "g_765", print_hash_value);
    transparent_crc(g_781, "g_781", print_hash_value);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            for (k = 0; k < 9; k++)
            {
                transparent_crc(g_889[i][j][k], "g_889[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    transparent_crc(g_960, "g_960", print_hash_value);
    for (i = 0; i < 10; i++)
    {
        transparent_crc(g_1072[i], "g_1072[i]", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1210, "g_1210", print_hash_value);
    transparent_crc(g_1327, "g_1327", print_hash_value);
    transparent_crc(g_1501, "g_1501", print_hash_value);
    transparent_crc(g_1589, "g_1589", print_hash_value);
    transparent_crc(g_1674, "g_1674", print_hash_value);
    for (i = 0; i < 1; i++)
    {
        for (j = 0; j < 2; j++)
        {
            for (k = 0; k < 10; k++)
            {
                transparent_crc(g_1685[i][j][k], "g_1685[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 1; j++)
        {
            for (k = 0; k < 9; k++)
            {
                transparent_crc(g_1716[i][j][k], "g_1716[i][j][k]", print_hash_value);
                if (print_hash_value) printf("index = [%d][%d][%d]\n", i, j, k);
            }
        }
    }
    transparent_crc(g_1738, "g_1738", print_hash_value);
    for (i = 0; i < 9; i++)
    {
        transparent_crc(g_1812[i].f0, "g_1812[i].f0", print_hash_value);
        transparent_crc(g_1812[i].f1, "g_1812[i].f1", print_hash_value);
        transparent_crc(g_1812[i].f2, "g_1812[i].f2", print_hash_value);
        transparent_crc(g_1812[i].f3, "g_1812[i].f3", print_hash_value);
        transparent_crc(g_1812[i].f4, "g_1812[i].f4", print_hash_value);
        transparent_crc(g_1812[i].f5, "g_1812[i].f5", print_hash_value);
        if (print_hash_value) printf("index = [%d]\n", i);
    }
    transparent_crc(g_1842, "g_1842", print_hash_value);
    transparent_crc(g_1844, "g_1844", print_hash_value);
    transparent_crc(g_1923, "g_1923", print_hash_value);
    transparent_crc(g_1945, "g_1945", print_hash_value);
    transparent_crc(g_1979, "g_1979", print_hash_value);
    transparent_crc(g_2006.f0, "g_2006.f0", print_hash_value);
    transparent_crc(g_2006.f1, "g_2006.f1", print_hash_value);
    transparent_crc(g_2006.f2, "g_2006.f2", print_hash_value);
    transparent_crc(g_2006.f3, "g_2006.f3", print_hash_value);
    transparent_crc(g_2006.f4, "g_2006.f4", print_hash_value);
    transparent_crc(g_2043, "g_2043", print_hash_value);
    platform_main_end(crc32_context ^ 0xFFFFFFFFUL, print_hash_value);
    return 0;
}
