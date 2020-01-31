




struct A {
  int i[2];
} a;

int foo (void)
{
  struct A *p = &a;
  int *q = (int *)p;
  int *x = q + 1;
  return *x;
}
