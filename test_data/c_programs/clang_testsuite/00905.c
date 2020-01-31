int flags(int a, int b, ...) {
        __builtin_va_list args;
        __builtin_va_start(args,a);
        foo(args);
}
