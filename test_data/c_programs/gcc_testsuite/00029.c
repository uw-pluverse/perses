


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));

int n1 = 30;
int n2 = 324;
void *n3 = (void *) &n2;
int n4 = 407;

int e1;
int e2;
void *e3;
int e4;

static void
__attribute__((noinline))
foo (va_list va_arglist)
{
  e2 = __builtin_va_arg(va_arglist, int);
  e3 = __builtin_va_arg(va_arglist, void *);
  e4 = __builtin_va_arg(va_arglist, int);
}

static void
__attribute__((noinline))
test (int a1, ...)
{
  e1 = a1;
  va_list va_arglist;
  __builtin_va_start(va_arglist, a1);
  foo (va_arglist);
  __builtin_va_end(va_arglist);
}

int
main ()
{
  test (n1, n2, n3, n4);
  ((n1 == e1) ? (void) (0) : __assert_fail ("n1 == e1", "../gcc-seed-programs/gcc.target/i386/amd64-abi-4.c", 41, __PRETTY_FUNCTION__));
  ((n2 == e2) ? (void) (0) : __assert_fail ("n2 == e2", "../gcc-seed-programs/gcc.target/i386/amd64-abi-4.c", 42, __PRETTY_FUNCTION__));
  ((n3 == e3) ? (void) (0) : __assert_fail ("n3 == e3", "../gcc-seed-programs/gcc.target/i386/amd64-abi-4.c", 43, __PRETTY_FUNCTION__));
  ((n4 == e4) ? (void) (0) : __assert_fail ("n4 == e4", "../gcc-seed-programs/gcc.target/i386/amd64-abi-4.c", 44, __PRETTY_FUNCTION__));
  return 0;
}
