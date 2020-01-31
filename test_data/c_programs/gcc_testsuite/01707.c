typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

void test (int x, ...)
{
    va_list ap;
    int i;
    __builtin_va_start(ap, x);
    if (__builtin_va_arg(ap, int) != 1)
 abort ();
    if (__builtin_va_arg(ap, int) != 2)
 abort ();
    if (__builtin_va_arg(ap, int) != 3)
 abort ();
    if (__builtin_va_arg(ap, int) != 4)
 abort ();
}

double a = 40.0;

int main(int argc, char *argv[])
{
    test(0, 1, 2, 3, (int)(a / 10.0));
    exit (0);
}
