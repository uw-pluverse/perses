


extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));

int
main ()
{
  int i, v1 = 0, n = 100;

 for (i = 0; i < n; i++)
    v1++;

  ((v1 == n) ? (void) (0) : __assert_fail ("v1 == n", "../gcc-seed-programs/c-c++-common/goacc/combined-reduction.c", 15, __PRETTY_FUNCTION__));

 for (i = 0; i < n; i++)
    v1++;

  ((v1 == n) ? (void) (0) : __assert_fail ("v1 == n", "../gcc-seed-programs/c-c++-common/goacc/combined-reduction.c", 21, __PRETTY_FUNCTION__));

  return 0;
}
