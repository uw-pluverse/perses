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
long double _Complex
__multc3(long double a, long double b, long double c, long double d)
{
 long double ac = __gcc_qmul(a,c);
 long double bd = __gcc_qmul(b,d);
 long double ad = __gcc_qmul(a,d);
 long double bc = __gcc_qmul(b,c);
 DD real = { .ld = __gcc_qsub(ac,bd) };
 DD imag = { .ld = __gcc_qadd(ad,bc) };
 if (__builtin_isnan((real.s.hi)) && __builtin_isnan((imag.s.hi)))
 {
  int recalc = 0;
  DD aDD = { .ld = a };
  DD bDD = { .ld = b };
  DD cDD = { .ld = c };
  DD dDD = { .ld = d };
  if (__builtin_isinf((aDD.s.hi)) || __builtin_isinf((bDD.s.hi)))
  {
   { (aDD).s.hi = __builtin_copysign((__builtin_isinf(((aDD).s.hi)) ? 1.0 : 0.0), ((aDD).s.hi)); (aDD).s.lo = 0.0; };
   { (bDD).s.hi = __builtin_copysign((__builtin_isinf(((bDD).s.hi)) ? 1.0 : 0.0), ((bDD).s.hi)); (bDD).s.lo = 0.0; };
   { if (__builtin_isnan(((cDD).s.hi))) { (cDD).s.hi = __builtin_copysign((0.0), ((cDD).s.hi)); (cDD).s.lo = 0.0; } };
   { if (__builtin_isnan(((dDD).s.hi))) { (dDD).s.hi = __builtin_copysign((0.0), ((dDD).s.hi)); (dDD).s.lo = 0.0; } };
   recalc = 1;
  }
  if (__builtin_isinf((cDD.s.hi)) || __builtin_isinf((dDD.s.hi)))
  {
   { (cDD).s.hi = __builtin_copysign((__builtin_isinf(((cDD).s.hi)) ? 1.0 : 0.0), ((cDD).s.hi)); (cDD).s.lo = 0.0; };
   { (dDD).s.hi = __builtin_copysign((__builtin_isinf(((dDD).s.hi)) ? 1.0 : 0.0), ((dDD).s.hi)); (dDD).s.lo = 0.0; };
   { if (__builtin_isnan(((aDD).s.hi))) { (aDD).s.hi = __builtin_copysign((0.0), ((aDD).s.hi)); (aDD).s.lo = 0.0; } };
   { if (__builtin_isnan(((bDD).s.hi))) { (bDD).s.hi = __builtin_copysign((0.0), ((bDD).s.hi)); (bDD).s.lo = 0.0; } };
   recalc = 1;
  }
  if (!recalc)
  {
   DD acDD = { .ld = ac };
   DD bdDD = { .ld = bd };
   DD adDD = { .ld = ad };
   DD bcDD = { .ld = bc };
   if (__builtin_isinf((acDD.s.hi)) || __builtin_isinf((bdDD.s.hi)) ||
                            __builtin_isinf((adDD.s.hi)) || __builtin_isinf((bcDD.s.hi)))
   {
    { if (__builtin_isnan(((aDD).s.hi))) { (aDD).s.hi = __builtin_copysign((0.0), ((aDD).s.hi)); (aDD).s.lo = 0.0; } };
    { if (__builtin_isnan(((bDD).s.hi))) { (bDD).s.hi = __builtin_copysign((0.0), ((bDD).s.hi)); (bDD).s.lo = 0.0; } };
    { if (__builtin_isnan(((cDD).s.hi))) { (cDD).s.hi = __builtin_copysign((0.0), ((cDD).s.hi)); (cDD).s.lo = 0.0; } };
    { if (__builtin_isnan(((dDD).s.hi))) { (dDD).s.hi = __builtin_copysign((0.0), ((dDD).s.hi)); (dDD).s.lo = 0.0; } };
    recalc = 1;
   }
  }
  if (recalc)
  {
   real.s.hi = __builtin_huge_valf() * (aDD.s.hi*cDD.s.hi - bDD.s.hi*dDD.s.hi);
   real.s.lo = 0.0;
   imag.s.hi = __builtin_huge_valf() * (aDD.s.hi*dDD.s.hi + bDD.s.hi*cDD.s.hi);
   imag.s.lo = 0.0;
  }
 }
 long double _Complex z;
 __real__ z = real.ld;
 __imag__ z = imag.ld;
 return z;
}
