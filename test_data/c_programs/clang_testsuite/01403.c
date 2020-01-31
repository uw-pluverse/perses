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
 Fcomplex
__mulsc3(float __a, float __b, float __c, float __d)
{
    float __ac = __a * __c;
    float __bd = __b * __d;
    float __ad = __a * __d;
    float __bc = __b * __c;
    Fcomplex z;
    __real__(z) = __ac - __bd;
    __imag__(z) = __ad + __bc;
    if (__builtin_isnan((__real__(z))) && __builtin_isnan((__imag__(z))))
    {
        int __recalc = 0;
        if (__builtin_isinf((__a)) || __builtin_isinf((__b)))
        {
            __a = __builtin_copysignf((__builtin_isinf((__a)) ? 1 : 0), (__a));
            __b = __builtin_copysignf((__builtin_isinf((__b)) ? 1 : 0), (__b));
            if (__builtin_isnan((__c)))
                __c = __builtin_copysignf((0), (__c));
            if (__builtin_isnan((__d)))
                __d = __builtin_copysignf((0), (__d));
            __recalc = 1;
        }
        if (__builtin_isinf((__c)) || __builtin_isinf((__d)))
        {
            __c = __builtin_copysignf((__builtin_isinf((__c)) ? 1 : 0), (__c));
            __d = __builtin_copysignf((__builtin_isinf((__d)) ? 1 : 0), (__d));
            if (__builtin_isnan((__a)))
                __a = __builtin_copysignf((0), (__a));
            if (__builtin_isnan((__b)))
                __b = __builtin_copysignf((0), (__b));
            __recalc = 1;
        }
        if (!__recalc && (__builtin_isinf((__ac)) || __builtin_isinf((__bd)) ||
                          __builtin_isinf((__ad)) || __builtin_isinf((__bc))))
        {
            if (__builtin_isnan((__a)))
                __a = __builtin_copysignf((0), (__a));
            if (__builtin_isnan((__b)))
                __b = __builtin_copysignf((0), (__b));
            if (__builtin_isnan((__c)))
                __c = __builtin_copysignf((0), (__c));
            if (__builtin_isnan((__d)))
                __d = __builtin_copysignf((0), (__d));
            __recalc = 1;
        }
        if (__recalc)
        {
            __real__(z) = __builtin_huge_valf() * (__a * __c - __b * __d);
            __imag__(z) = __builtin_huge_valf() * (__a * __d + __b * __c);
        }
    }
    return z;
}
