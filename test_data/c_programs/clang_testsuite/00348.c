long long t1(int i, ...) {
    __builtin_va_list ap;
    __builtin_va_start(ap, i);
    long long ll = __builtin_va_arg(ap, long long);
    __builtin_va_end(ap);
    return ll;
}
double t2(int i, ...) {
    __builtin_va_list ap;
    __builtin_va_start(ap, i);
    double ll = __builtin_va_arg(ap, double);
    __builtin_va_end(ap);
    return ll;
}
