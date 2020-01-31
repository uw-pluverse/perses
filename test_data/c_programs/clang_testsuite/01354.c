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
typedef uint64_t rep_t;
typedef int64_t srep_t;
typedef double fp_t;
static __inline int rep_clz(rep_t a) {
    return __builtin_clzl(a);
}
static __inline void wideMultiply(rep_t a, rep_t b, rep_t *hi, rep_t *lo) {
    const uint64_t plolo = (a & 0xffffffffU) * (b & 0xffffffffU);
    const uint64_t plohi = (a & 0xffffffffU) * (b >> 32);
    const uint64_t philo = (a >> 32) * (b & 0xffffffffU);
    const uint64_t phihi = (a >> 32) * (b >> 32);
    const uint64_t r0 = (plolo & 0xffffffffU);
    const uint64_t r1 = (plolo >> 32) + (plohi & 0xffffffffU) + (philo & 0xffffffffU);
    *lo = r0 + (r1 << 32);
    *hi = (plohi >> 32) + (philo >> 32) + (r1 >> 32) + phihi;
}
 fp_t __adddf3(fp_t a, fp_t b);
static __inline rep_t toRep(fp_t x) {
    const union { fp_t f; rep_t i; } rep = {.f = x};
    return rep.i;
}
static __inline fp_t fromRep(rep_t x) {
    const union { fp_t f; rep_t i; } rep = {.i = x};
    return rep.f;
}
static __inline int normalize(rep_t *significand) {
    const int shift = rep_clz(*significand) - rep_clz((1UL << 52));
    *significand <<= shift;
    return 1 - shift;
}
static __inline void wideLeftShift(rep_t *hi, rep_t *lo, int count) {
    *hi = *hi << count | *lo >> ((sizeof(rep_t)*8) - count);
    *lo = *lo << count;
}
static __inline void wideRightShiftWithSticky(rep_t *hi, rep_t *lo, unsigned int count) {
    if (count < (sizeof(rep_t)*8)) {
        const _Bool sticky = *lo << ((sizeof(rep_t)*8) - count);
        *lo = *hi << ((sizeof(rep_t)*8) - count) | *lo >> count | sticky;
        *hi = *hi >> count;
    }
    else if (count < 2*(sizeof(rep_t)*8)) {
        const _Bool sticky = *hi << (2*(sizeof(rep_t)*8) - count) | *lo;
        *lo = *hi >> (count - (sizeof(rep_t)*8)) | sticky;
        *hi = 0;
    } else {
        const _Bool sticky = *hi | *lo;
        *lo = sticky;
        *hi = 0;
    }
}
 fp_t
__divdf3(fp_t a, fp_t b) {
    const unsigned int aExponent = toRep(a) >> 52 & ((1 << ((sizeof(rep_t)*8) - 52 - 1)) - 1);
    const unsigned int bExponent = toRep(b) >> 52 & ((1 << ((sizeof(rep_t)*8) - 52 - 1)) - 1);
    const rep_t quotientSign = (toRep(a) ^ toRep(b)) & (1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1)));
    rep_t aSignificand = toRep(a) & ((1UL << 52) - 1U);
    rep_t bSignificand = toRep(b) & ((1UL << 52) - 1U);
    int scale = 0;
    if (aExponent-1U >= ((1 << ((sizeof(rep_t)*8) - 52 - 1)) - 1)-1U || bExponent-1U >= ((1 << ((sizeof(rep_t)*8) - 52 - 1)) - 1)-1U) {
        const rep_t aAbs = toRep(a) & ((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U);
        const rep_t bAbs = toRep(b) & ((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U);
        if (aAbs > (((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U) ^ ((1UL << 52) - 1U))) return fromRep(toRep(a) | ((1UL << 52) >> 1));
        if (bAbs > (((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U) ^ ((1UL << 52) - 1U))) return fromRep(toRep(b) | ((1UL << 52) >> 1));
        if (aAbs == (((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U) ^ ((1UL << 52) - 1U))) {
            if (bAbs == (((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U) ^ ((1UL << 52) - 1U))) return fromRep(((((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U) ^ ((1UL << 52) - 1U)) | ((1UL << 52) >> 1)));
            else return fromRep(aAbs | quotientSign);
        }
        if (bAbs == (((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U) ^ ((1UL << 52) - 1U))) return fromRep(quotientSign);
        if (!aAbs) {
            if (!bAbs) return fromRep(((((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U) ^ ((1UL << 52) - 1U)) | ((1UL << 52) >> 1)));
            else return fromRep(quotientSign);
        }
        if (!bAbs) return fromRep((((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U) ^ ((1UL << 52) - 1U)) | quotientSign);
        if (aAbs < (1UL << 52)) scale += normalize(&aSignificand);
        if (bAbs < (1UL << 52)) scale -= normalize(&bSignificand);
    }
    aSignificand |= (1UL << 52);
    bSignificand |= (1UL << 52);
    int quotientExponent = aExponent - bExponent + scale;
    const uint32_t q31b = bSignificand >> 21;
    uint32_t recip32 = 0x7504f333U - q31b;
    uint32_t correction32;
    correction32 = -((uint64_t)recip32 * q31b >> 32);
    recip32 = (uint64_t)recip32 * correction32 >> 31;
    correction32 = -((uint64_t)recip32 * q31b >> 32);
    recip32 = (uint64_t)recip32 * correction32 >> 31;
    correction32 = -((uint64_t)recip32 * q31b >> 32);
    recip32 = (uint64_t)recip32 * correction32 >> 31;
    recip32--;
    const uint32_t q63blo = bSignificand << 11;
    uint64_t correction, reciprocal;
    correction = -((uint64_t)recip32*q31b + ((uint64_t)recip32*q63blo >> 32));
    uint32_t cHi = correction >> 32;
    uint32_t cLo = correction;
    reciprocal = (uint64_t)recip32*cHi + ((uint64_t)recip32*cLo >> 32);
    reciprocal -= 2;
    rep_t quotient, quotientLo;
    wideMultiply(aSignificand << 2, reciprocal, &quotient, &quotientLo);
    rep_t residual;
    if (quotient < ((1UL << 52) << 1)) {
        residual = (aSignificand << 53) - quotient * bSignificand;
        quotientExponent--;
    } else {
        quotient >>= 1;
        residual = (aSignificand << 52) - quotient * bSignificand;
    }
    const int writtenExponent = quotientExponent + (((1 << ((sizeof(rep_t)*8) - 52 - 1)) - 1) >> 1);
    if (writtenExponent >= ((1 << ((sizeof(rep_t)*8) - 52 - 1)) - 1)) {
        return fromRep((((1UL << (52 + ((sizeof(rep_t)*8) - 52 - 1))) - 1U) ^ ((1UL << 52) - 1U)) | quotientSign);
    }
    else if (writtenExponent < 1) {
        return fromRep(quotientSign);
    }
    else {
        const _Bool round = (residual << 1) > bSignificand;
        rep_t absResult = quotient & ((1UL << 52) - 1U);
        absResult |= (rep_t)writtenExponent << 52;
        absResult += round;
        const double result = fromRep(absResult | quotientSign);
        return result;
    }
}
