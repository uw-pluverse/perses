






struct test_a { volatile int a; };

int func_a(struct test_a *a)
{
        return a->a;
}
