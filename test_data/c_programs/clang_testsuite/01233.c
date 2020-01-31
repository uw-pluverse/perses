
extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

int div(int numerator, int denominator)
{
    return numerator / denominator;
}
void div_test()
{
    int i = 0;
    for (i = 0; i < 2; ++i)
        ((div(2 * i, i) == 2) ? (void) (0) : __assert_fail ("div(2 * i, i) == 2", "/tmp/llvm-builder/llvm-source-trunk/tools/clang/tools/scan-build-py/tests/functional/src/emit-one.c", 12, __PRETTY_FUNCTION__));
}
int do_nothing()
{
    unsigned int i = 0;
    int k = 100;
    int j = k + 1;
    return j;
}
