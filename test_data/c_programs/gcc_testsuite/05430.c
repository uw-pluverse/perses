


struct S { int a; char b; char c; short d; };

int
foo (int x)
{
  struct S s = { x + 1, x + 2, x + 3, x + 4 };
  char *p = &s.c;
  return x;
}
