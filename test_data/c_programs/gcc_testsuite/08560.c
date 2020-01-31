




inline int __attribute__((always_inline))
foo (int i)
{
    if (i) return 1;
    return 0;
}

void baz();

void bar()
{
    int j;
    for (; foo(j); ++j)
        baz();
}
