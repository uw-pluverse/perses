











enum
  {
    FE_INVALID =

      0x01,
    __FE_DENORM = 0x02,
    FE_DIVBYZERO =

      0x04,
    FE_OVERFLOW =

      0x08,
    FE_UNDERFLOW =

      0x10,
    FE_INEXACT =

      0x20
  };







enum
  {
    FE_TONEAREST =

      0,
    FE_DOWNWARD =

      0x400,
    FE_UPWARD =

      0x800,
    FE_TOWARDZERO =

      0xc00
  };



typedef unsigned short int fexcept_t;






typedef struct
  {
    unsigned short int __control_word;
    unsigned short int __glibc_reserved1;
    unsigned short int __status_word;
    unsigned short int __glibc_reserved2;
    unsigned short int __tags;
    unsigned short int __glibc_reserved3;
    unsigned int __eip;
    unsigned short int __cs_selector;
    unsigned int __opcode:11;
    unsigned int __glibc_reserved4:5;
    unsigned int __data_offset;
    unsigned short int __data_selector;
    unsigned short int __glibc_reserved5;

    unsigned int __mxcsr;

  }
fenv_t;






extern int feclearexcept (int __excepts) __attribute__ ((__nothrow__ ));



extern int fegetexceptflag (fexcept_t *__flagp, int __excepts) __attribute__ ((__nothrow__ ));


extern int feraiseexcept (int __excepts) __attribute__ ((__nothrow__ ));



extern int fesetexceptflag (const fexcept_t *__flagp, int __excepts) __attribute__ ((__nothrow__ ));



extern int fetestexcept (int __excepts) __attribute__ ((__nothrow__ ));





extern int fegetround (void) __attribute__ ((__nothrow__ ));


extern int fesetround (int __rounding_direction) __attribute__ ((__nothrow__ ));






extern int fegetenv (fenv_t *__envp) __attribute__ ((__nothrow__ ));




extern int feholdexcept (fenv_t *__envp) __attribute__ ((__nothrow__ ));



extern int fesetenv (const fenv_t *__envp) __attribute__ ((__nothrow__ ));




extern int feupdateenv (const fenv_t *__envp) __attribute__ ((__nothrow__ ));
__attribute__ ((noinline, noclone)) double ceil (double x) { return x; } __attribute__ ((noinline, noclone)) float ceilf (float x) { return x; } __attribute__ ((noinline, noclone)) long double ceill (long double x) { return x; }
__attribute__ ((noinline, noclone)) double floor (double x) { return x; } __attribute__ ((noinline, noclone)) float floorf (float x) { return x; } __attribute__ ((noinline, noclone)) long double floorl (long double x) { return x; }
__attribute__ ((noinline, noclone)) double round (double x) { return x; } __attribute__ ((noinline, noclone)) float roundf (float x) { return x; } __attribute__ ((noinline, noclone)) long double roundl (long double x) { return x; }
__attribute__ ((noinline, noclone)) double trunc (double x) { return x; } __attribute__ ((noinline, noclone)) float truncf (float x) { return x; } __attribute__ ((noinline, noclone)) long double truncl (long double x) { return x; }

extern void abort (void);
extern void exit (int);
static void
main_test (void)
{
  do { do { volatile double a = 1.5, b; b = __builtin_ceil (a); if (fetestexcept (0x20)) abort (); } while (0); do { volatile float a = 1.5, b; b = __builtin_ceilf (a); if (fetestexcept (0x20)) abort (); } while (0); do { volatile long double a = 1.5, b; b = __builtin_ceill (a); if (fetestexcept (0x20)) abort (); } while (0); } while (0);
  do { do { volatile double a = 1.5, b; b = __builtin_floor (a); if (fetestexcept (0x20)) abort (); } while (0); do { volatile float a = 1.5, b; b = __builtin_floorf (a); if (fetestexcept (0x20)) abort (); } while (0); do { volatile long double a = 1.5, b; b = __builtin_floorl (a); if (fetestexcept (0x20)) abort (); } while (0); } while (0);
  do { do { volatile double a = 1.5, b; b = __builtin_round (a); if (fetestexcept (0x20)) abort (); } while (0); do { volatile float a = 1.5, b; b = __builtin_roundf (a); if (fetestexcept (0x20)) abort (); } while (0); do { volatile long double a = 1.5, b; b = __builtin_roundl (a); if (fetestexcept (0x20)) abort (); } while (0); } while (0);
  do { do { volatile double a = 1.5, b; b = __builtin_trunc (a); if (fetestexcept (0x20)) abort (); } while (0); do { volatile float a = 1.5, b; b = __builtin_truncf (a); if (fetestexcept (0x20)) abort (); } while (0); do { volatile long double a = 1.5, b; b = __builtin_truncl (a); if (fetestexcept (0x20)) abort (); } while (0); } while (0);
}





int
main (void)
{
  main_test ();
  exit (0);
}

