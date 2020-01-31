




extern void foo(void *) __attribute__ ((__nonnull__ (1)));

int z;

void
com (int a)
{
    foo (a == 42 ? &z : (void *) 0);
}

void
bar (void)
{
  foo ((void *)0);
}
