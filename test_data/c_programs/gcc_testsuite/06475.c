



int i, a;
unsigned long long b;

void f(void)
{
    for(i = 0; i < 15; i++)
        b *= b;

    b *= a ? 0 : b;
}
