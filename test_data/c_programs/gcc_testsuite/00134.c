




void foo (void) __attribute__ ((function_vector));
__attribute__((noinline)) void foo (void)
{
}

void bar (void)
{
    foo();
}
