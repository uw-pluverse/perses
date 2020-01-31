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
#pragma GCC visibility push(default)
typedef unsigned _Unwind_Word __attribute__((__mode__(__unwind_word__)));
typedef signed _Unwind_Sword __attribute__((__mode__(__unwind_word__)));
typedef unsigned _Unwind_Ptr __attribute__((__mode__(__pointer__)));
typedef unsigned _Unwind_Internal_Ptr __attribute__((__mode__(__pointer__)));
typedef unsigned _Unwind_Exception_Class __attribute__((__mode__(__DI__)));
typedef enum
{
  _URC_NO_REASON = 0,
  _URC_FOREIGN_EXCEPTION_CAUGHT = 1,
  _URC_FATAL_PHASE2_ERROR = 2,
  _URC_FATAL_PHASE1_ERROR = 3,
  _URC_NORMAL_STOP = 4,
  _URC_END_OF_STACK = 5,
  _URC_HANDLER_FOUND = 6,
  _URC_INSTALL_CONTEXT = 7,
  _URC_CONTINUE_UNWIND = 8
} _Unwind_Reason_Code;
struct _Unwind_Exception;
typedef void (*_Unwind_Exception_Cleanup_Fn) (_Unwind_Reason_Code,
           struct _Unwind_Exception *);
struct _Unwind_Exception
{
  _Unwind_Exception_Class exception_class;
  _Unwind_Exception_Cleanup_Fn exception_cleanup;
  _Unwind_Word private_1;
  _Unwind_Word private_2;
} __attribute__((__aligned__));
typedef int _Unwind_Action;
struct _Unwind_Context;
extern _Unwind_Reason_Code
_Unwind_RaiseException (struct _Unwind_Exception *);
typedef _Unwind_Reason_Code (*_Unwind_Stop_Fn)
     (int, _Unwind_Action, _Unwind_Exception_Class,
      struct _Unwind_Exception *, struct _Unwind_Context *, void *);
extern _Unwind_Reason_Code
_Unwind_ForcedUnwind (struct _Unwind_Exception *, _Unwind_Stop_Fn, void *);
extern void _Unwind_DeleteException (struct _Unwind_Exception *);
extern void
_Unwind_Resume (struct _Unwind_Exception *);
extern _Unwind_Reason_Code
_Unwind_Resume_or_Rethrow (struct _Unwind_Exception *);
typedef _Unwind_Reason_Code (*_Unwind_Trace_Fn)
     (struct _Unwind_Context *, void *);
extern _Unwind_Reason_Code
_Unwind_Backtrace (_Unwind_Trace_Fn, void *);
extern _Unwind_Word _Unwind_GetGR (struct _Unwind_Context *, int);
extern void _Unwind_SetGR (struct _Unwind_Context *, int, _Unwind_Word);
extern _Unwind_Ptr _Unwind_GetIP (struct _Unwind_Context *);
extern _Unwind_Ptr _Unwind_GetIPInfo (struct _Unwind_Context *, int *);
extern void _Unwind_SetIP (struct _Unwind_Context *, _Unwind_Ptr);
extern _Unwind_Word _Unwind_GetCFA (struct _Unwind_Context *);
extern void *_Unwind_GetLanguageSpecificData (struct _Unwind_Context *);
extern _Unwind_Ptr _Unwind_GetRegionStart (struct _Unwind_Context *);
typedef _Unwind_Reason_Code (*_Unwind_Personality_Fn)
     (int, _Unwind_Action, _Unwind_Exception_Class,
      struct _Unwind_Exception *, struct _Unwind_Context *);
struct SjLj_Function_Context;
extern void _Unwind_SjLj_Register (struct SjLj_Function_Context *);
extern void _Unwind_SjLj_Unregister (struct SjLj_Function_Context *);
extern _Unwind_Reason_Code
_Unwind_SjLj_RaiseException (struct _Unwind_Exception *);
extern _Unwind_Reason_Code
_Unwind_SjLj_ForcedUnwind (struct _Unwind_Exception *, _Unwind_Stop_Fn, void *);
extern void
_Unwind_SjLj_Resume (struct _Unwind_Exception *);
extern _Unwind_Reason_Code
_Unwind_SjLj_Resume_or_Rethrow (struct _Unwind_Exception *);
extern _Unwind_Ptr _Unwind_GetDataRelBase (struct _Unwind_Context *);
extern _Unwind_Ptr _Unwind_GetTextRelBase (struct _Unwind_Context *);
extern void * _Unwind_FindEnclosingFunction (void *pc);
  typedef long _sleb128_t;
  typedef unsigned long _uleb128_t;
#pragma GCC visibility pop
static uintptr_t readULEB128(const uint8_t** data)
{
    uintptr_t result = 0;
    uintptr_t shift = 0;
    unsigned char byte;
    const uint8_t* p = *data;
    do {
        byte = *p++;
        result |= (byte & 0x7f) << shift;
        shift += 7;
    } while (byte & 0x80);
    *data = p;
    return result;
}
static uintptr_t readEncodedPointer(const uint8_t** data, uint8_t encoding)
{
    const uint8_t* p = *data;
    uintptr_t result = 0;
    if ( encoding == 0xff )
        return 0;
    switch (encoding & 0x0F) {
        case 0x00:
            result = *((const uintptr_t*)p);
            p += sizeof(uintptr_t);
            break;
        case 0x01:
            result = readULEB128(&p);
            break;
        case 0x02:
            result = *((const uint16_t*)p);
            p += sizeof(uint16_t);
            break;
        case 0x03:
            result = *((const uint32_t*)p);
            p += sizeof(uint32_t);
            break;
        case 0x04:
            result = *((const uint64_t*)p);
            p += sizeof(uint64_t);
            break;
        case 0x0A:
            result = *((const int16_t*)p);
            p += sizeof(int16_t);
            break;
        case 0x0B:
            result = *((const int32_t*)p);
            p += sizeof(int32_t);
            break;
        case 0x0C:
            result = *((const int64_t*)p);
            p += sizeof(int64_t);
            break;
        case 0x09:
        default:
            compilerrt_abort_impl("/tmp/llvm-builder/llvm-source-trunk/projects/compiler-rt/lib/builtins/gcc_personality_v0.c", 114, __func__);
            break;
    }
    switch ( encoding & 0x70 ) {
        case 0x00:
            break;
        case 0x10:
            result += (uintptr_t)(*data);
            break;
        case 0x20:
        case 0x30:
        case 0x40:
        case 0x50:
        default:
            compilerrt_abort_impl("/tmp/llvm-builder/llvm-source-trunk/projects/compiler-rt/lib/builtins/gcc_personality_v0.c", 132, __func__);
            break;
    }
    if (encoding & 0x80) {
        result = *((const uintptr_t*)result);
    }
    *data = p;
    return result;
}
static inline _Unwind_Reason_Code
continueUnwind(struct _Unwind_Exception *exceptionObject,
               struct _Unwind_Context *context) {
    return _URC_CONTINUE_UNWIND;
}
 _Unwind_Reason_Code
__gcc_personality_v0(int version, _Unwind_Action actions,
         uint64_t exceptionClass, struct _Unwind_Exception* exceptionObject,
         struct _Unwind_Context *context)
{
    if ( actions & 1 )
        return continueUnwind(exceptionObject, context);
    const uint8_t* lsda = (uint8_t*)_Unwind_GetLanguageSpecificData(context);
    if ( lsda == (uint8_t*) 0 )
        return continueUnwind(exceptionObject, context);
    uintptr_t pc = _Unwind_GetIP(context)-1;
    uintptr_t funcStart = _Unwind_GetRegionStart(context);
    uintptr_t pcOffset = pc - funcStart;
    uint8_t lpStartEncoding = *lsda++;
    if (lpStartEncoding != 0xff) {
        readEncodedPointer(&lsda, lpStartEncoding);
    }
    uint8_t ttypeEncoding = *lsda++;
    if (ttypeEncoding != 0xff) {
        readULEB128(&lsda);
    }
    uint8_t callSiteEncoding = *lsda++;
    uint32_t callSiteTableLength = readULEB128(&lsda);
    const uint8_t* callSiteTableStart = lsda;
    const uint8_t* callSiteTableEnd = callSiteTableStart + callSiteTableLength;
    const uint8_t* p=callSiteTableStart;
    while (p < callSiteTableEnd) {
        uintptr_t start = readEncodedPointer(&p, callSiteEncoding);
        uintptr_t length = readEncodedPointer(&p, callSiteEncoding);
        uintptr_t landingPad = readEncodedPointer(&p, callSiteEncoding);
        readULEB128(&p);
        if ( landingPad == 0 )
            continue;
        if ( (start <= pcOffset) && (pcOffset < (start+length)) ) {
            _Unwind_SetGR(context, __builtin_eh_return_data_regno(0),
                          (uintptr_t)exceptionObject);
            _Unwind_SetGR(context, __builtin_eh_return_data_regno(1), 0);
            _Unwind_SetIP(context, (funcStart + landingPad));
            return _URC_INSTALL_CONTEXT;
        }
    }
    return continueUnwind(exceptionObject, context);
}
