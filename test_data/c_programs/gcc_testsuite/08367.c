extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ )) __attribute__ ((__noreturn__));





int
main()
{
  int L20 = 20; ((L20 == 20) ? (void) (0) : __assert_fail ("L20 == 20", "../gcc-seed-programs/gcc.dg/cpp/builtin-macro-1.c", 20, __PRETTY_FUNCTION__));;


  ((L20 == 20) ? (void) (0) : __assert_fail ("L20 == 20", "../gcc-seed-programs/gcc.dg/cpp/builtin-macro-1.c", 22, __PRETTY_FUNCTION__));




  return 0;
}
