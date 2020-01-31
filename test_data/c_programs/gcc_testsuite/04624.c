



__attribute__((noinline, noclone)) void
foo (void *p, const void *q)
{
  *(long int *) p = *(const long int *) q;
}

int
main ()
{
  struct S { long c; char f[64]; char d; char e[2 * sizeof (long)]; char g[64]; } s;
  __builtin_memset (&s, '\0', sizeof s);
  foo (&s.e[0], &s.e[sizeof (long)]);
  return 0;
}
