







struct S { unsigned long a, b; };
__thread struct S s;
void bar (unsigned long *);

__attribute__((noinline)) void
foo (void)
{
  int i;
  for (i = 0; i < 10; i++)
    __sync_fetch_and_add (&s.b, 1L);
}

int
main ()
{
  s.b = 12;
  foo ();
  if (s.b != 22)
    __builtin_abort ();
  return 0;
}
