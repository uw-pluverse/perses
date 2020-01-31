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
typedef double src_t;
typedef uint64_t src_rep_t;
static const int srcSigBits = 52;
typedef uint16_t dst_t;
typedef uint16_t dst_rep_t;
static const int dstSigBits = 10;
static __inline src_rep_t srcToRep(src_t x) {
    const union { src_t f; src_rep_t i; } rep = {.f = x};
    return rep.i;
}
static __inline dst_t dstFromRep(dst_rep_t x) {
    const union { dst_t f; dst_rep_t i; } rep = {.i = x};
    return rep.f;
}
static __inline dst_t __truncXfYf2__(src_t a) {
    const int srcBits = sizeof(src_t)*8;
    const int srcExpBits = srcBits - srcSigBits - 1;
    const int srcInfExp = (1 << srcExpBits) - 1;
    const int srcExpBias = srcInfExp >> 1;
    const src_rep_t srcMinNormal = 1UL << srcSigBits;
    const src_rep_t srcSignificandMask = srcMinNormal - 1;
    const src_rep_t srcInfinity = (src_rep_t)srcInfExp << srcSigBits;
    const src_rep_t srcSignMask = 1UL << (srcSigBits + srcExpBits);
    const src_rep_t srcAbsMask = srcSignMask - 1;
    const src_rep_t roundMask = (1UL << (srcSigBits - dstSigBits)) - 1;
    const src_rep_t halfway = 1UL << (srcSigBits - dstSigBits - 1);
    const src_rep_t srcQNaN = 1UL << (srcSigBits - 1);
    const src_rep_t srcNaNCode = srcQNaN - 1;
    const int dstBits = sizeof(dst_t)*8;
    const int dstExpBits = dstBits - dstSigBits - 1;
    const int dstInfExp = (1 << dstExpBits) - 1;
    const int dstExpBias = dstInfExp >> 1;
    const int underflowExponent = srcExpBias + 1 - dstExpBias;
    const int overflowExponent = srcExpBias + dstInfExp - dstExpBias;
    const src_rep_t underflow = (src_rep_t)underflowExponent << srcSigBits;
    const src_rep_t overflow = (src_rep_t)overflowExponent << srcSigBits;
    const dst_rep_t dstQNaN = 1 << (dstSigBits - 1);
    const dst_rep_t dstNaNCode = dstQNaN - 1;
    const src_rep_t aRep = srcToRep(a);
    const src_rep_t aAbs = aRep & srcAbsMask;
    const src_rep_t sign = aRep & srcSignMask;
    dst_rep_t absResult;
    if (aAbs - underflow < aAbs - overflow) {
        absResult = aAbs >> (srcSigBits - dstSigBits);
        absResult -= (dst_rep_t)(srcExpBias - dstExpBias) << dstSigBits;
        const src_rep_t roundBits = aAbs & roundMask;
        if (roundBits > halfway)
            absResult++;
        else if (roundBits == halfway)
            absResult += absResult & 1;
    }
    else if (aAbs > srcInfinity) {
        absResult = (dst_rep_t)dstInfExp << dstSigBits;
        absResult |= dstQNaN;
        absResult |= ((aAbs & srcNaNCode) >> (srcSigBits - dstSigBits)) & dstNaNCode;
    }
    else if (aAbs >= overflow) {
        absResult = (dst_rep_t)dstInfExp << dstSigBits;
    }
    else {
        const int aExp = aAbs >> srcSigBits;
        const int shift = srcExpBias - dstExpBias - aExp + 1;
        const src_rep_t significand = (aRep & srcSignificandMask) | srcMinNormal;
        if (shift > srcSigBits) {
            absResult = 0;
        } else {
            const _Bool sticky = significand << (srcBits - shift);
            src_rep_t denormalizedSignificand = significand >> shift | sticky;
            absResult = denormalizedSignificand >> (srcSigBits - dstSigBits);
            const src_rep_t roundBits = denormalizedSignificand & roundMask;
            if (roundBits > halfway)
                absResult++;
            else if (roundBits == halfway)
                absResult += absResult & 1;
        }
    }
    const dst_rep_t result = absResult | sign >> (srcBits - dstBits);
    return dstFromRep(result);
}
 uint16_t __truncdfhf2(double a) {
    return __truncXfYf2__(a);
}
