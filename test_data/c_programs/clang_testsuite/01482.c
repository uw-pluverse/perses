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
typedef int si_int;
typedef unsigned su_int;
typedef long long di_int;
typedef unsigned long long du_int;
typedef union
{
    di_int all;
    struct
    {
        su_int low;
        si_int high;
    }s;
} dwords;
typedef union
{
    du_int all;
    struct
    {
        su_int low;
        su_int high;
    }s;
} udwords;
typedef int ti_int __attribute__ ((mode (TI)));
typedef unsigned tu_int __attribute__ ((mode (TI)));
typedef union
{
    ti_int all;
    struct
    {
        du_int low;
        di_int high;
    }s;
} twords;
typedef union
{
    tu_int all;
    struct
    {
        du_int low;
        du_int high;
    }s;
} utwords;
static __inline ti_int make_ti(di_int h, di_int l) {
    twords r;
    r.s.high = h;
    r.s.low = l;
    return r.all;
}
static __inline tu_int make_tu(du_int h, du_int l) {
    utwords r;
    r.s.high = h;
    r.s.low = l;
    return r.all;
}
typedef union
{
    su_int u;
    float f;
} float_bits;
typedef union
{
    udwords u;
    double f;
} double_bits;
typedef struct
{
    udwords low;
    udwords high;
} uqwords;
typedef union
{
    uqwords u;
    long double f;
} long_double_bits;
typedef float _Complex Fcomplex;
typedef double _Complex Dcomplex;
typedef long double _Complex Lcomplex;
__attribute__((noreturn)) void compilerrt_abort_impl(const char *file, int line,
                                    const char *function);
 si_int __paritysi2(si_int a);
 si_int __paritydi2(di_int a);
 di_int __divdi3(di_int a, di_int b);
 si_int __divsi3(si_int a, si_int b);
 su_int __udivsi3(su_int n, su_int d);
 su_int __udivmodsi4(su_int a, su_int b, su_int* rem);
 du_int __udivmoddi4(du_int a, du_int b, du_int* rem);
 si_int __clzti2(ti_int a);
 tu_int __udivmodti4(tu_int a, tu_int b, tu_int* rem);
typedef union {
 long double ld;
 struct {
  double hi;
  double lo;
 }s;
} DD;
typedef union {
 double d;
 uint64_t x;
} doublebits;
static __inline __attribute__((always_inline)) double local_fabs(double x) {
  doublebits result = {.d = x};
  result.x &= 0x7fffffffffffffffUL;
  return result.d;
}
static __inline __attribute__((always_inline)) double high26bits(double x) {
  doublebits result = {.d = x};
  result.x &= 0xfffffffff8000000UL;
  return result.d;
}
static __inline __attribute__((always_inline)) int different_sign(double x, double y) {
  doublebits xsignbit = {.d = x}, ysignbit = {.d = y};
  int result = (int)(xsignbit.x >> 63) ^ (int)(ysignbit.x >> 63);
  return result;
}
long double __gcc_qadd(long double, long double);
long double __gcc_qsub(long double, long double);
long double __gcc_qmul(long double, long double);
long double __gcc_qdiv(long double, long double);
uint64_t __fixunstfdi(long double input)
{
 const DD x = { .ld = input };
 const doublebits hibits = { .d = x.s.hi };
 const uint32_t highWordMinusOne = (uint32_t)(hibits.x >> 32) - 0x3ff00000U;
 if (0x04000000U > highWordMinusOne)
 {
  const int unbiasedHeadExponent = highWordMinusOne >> 20;
  uint64_t result = hibits.x & 0x000fffffffffffffUL;
  result |= 0x0010000000000000UL;
  result <<= 11;
  if (0.0 != x.s.lo)
  {
   const doublebits lobits = { .d = x.s.lo };
   int64_t tailMantissa = lobits.x & 0x000fffffffffffffL;
   tailMantissa |= 0x0010000000000000L;
   const int64_t negationMask = ((int64_t)(lobits.x)) >> 63;
   tailMantissa = (tailMantissa ^ negationMask) - negationMask;
   const int biasedTailExponent = (int)(lobits.x >> 52) & 0x7ff;
   tailMantissa >>= (unbiasedHeadExponent - (biasedTailExponent - (1023 - 11)));
   result += tailMantissa;
  }
  result >>= (63 - unbiasedHeadExponent);
  return result;
 }
 if (1.0 > x.s.hi)
  return 0UL;
 else
  return (18446744073709551615UL);
}
