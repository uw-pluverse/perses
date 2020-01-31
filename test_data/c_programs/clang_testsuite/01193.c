const char *func(const char *);
void foo(const char *);
int test() {
    foo("1""x()");
    foo(func("2""x()" "/tmp/llvm-builder/llvm-source-trunk/tools/clang/test/Index/complete-in-stringify.c"));
}
