




struct A
{
  int a;
  char b[32];
} a, b;

__attribute__((noinline, noclone))
struct A
bar (int x)
{
  struct A r;
  static int n;
  r.a = ++n;
  __builtin_memset (r.b, 0, sizeof (r.b));
  r.b[0] = x;
  return r;
}

int
main ()
{
  a = bar (3);
  b = bar (4);
  if (a.a != 1 || a.b[0] != 3 || b.a != 2 || b.b[0] != 4)
    __builtin_abort ();
  return 0;
}
