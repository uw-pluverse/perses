typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

void foo(va_list v)
{
    unsigned long long x = __builtin_va_arg(v, unsigned long long);
    if (x != 16LL)
 abort();
}

void bar(char c, char d, ...)
{
    va_list v;
    __builtin_va_start(v, d);
    foo(v);
    __builtin_va_end(v);
}

int main(void)
{
    bar(0, 0, 16LL);
    exit(0);
}
