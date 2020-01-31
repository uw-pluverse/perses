


struct A { char c[4]; } a, b;

void
f1 (void)
{
  a.c[2] = '\0';
  __builtin_memset (&a.c[1], 1, 2);
}

void
f2 (void)
{
  __builtin_memcpy (&a.c[0], "a", 1);
  __builtin_memcpy (&a, &b, 3);
}
