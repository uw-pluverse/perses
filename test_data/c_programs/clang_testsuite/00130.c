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
