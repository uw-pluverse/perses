





struct S { int a; };

__attribute__((noinline, noclone)) struct S
f1 (int i)
{
  struct S a[20];
  struct S *p = a;
  struct S s;
  s = p[i];
  return s;
}

int
main ()
{
  f1 (20);
  return 0;
}
