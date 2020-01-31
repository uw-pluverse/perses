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
long double __gcc_qmul(long double x, long double y)
{
 static const uint32_t infinityHi = 0x7ff00000U;
 DD dst = { .ld = x }, src = { .ld = y };
 register double A = dst.s.hi, a = dst.s.lo,
     B = src.s.hi, b = src.s.lo;
 double aHi, aLo, bHi, bLo;
    double ab, tmp, tau;
 ab = A * B;
 if (ab == 0.0) {
  dst.s.hi = ab;
  dst.s.lo = 0.0;
  return dst.ld;
 }
 const doublebits abBits = { .d = ab };
 if (((uint32_t)(abBits.x >> 32) & infinityHi) == infinityHi) {
  dst.s.hi = ab;
  dst.s.lo = 0.0;
  return dst.ld;
 }
    aHi = high26bits(A);
    bHi = high26bits(B);
    aLo = A - aHi;
    bLo = B - bHi;
    tmp = (((((aHi)*(bHi) - (ab)) + (aHi)*(bLo)) + (aLo)*(bHi)) + (aLo)*(bLo));
    tmp += (A * b + a * B);
    tau = ab + tmp;
    dst.s.lo = (ab - tau) + tmp;
    dst.s.hi = tau;
    return dst.ld;
}
