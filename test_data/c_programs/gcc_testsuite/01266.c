


int foo(int a, int b, int* p, int *q)
{
  a = p[2] + p[3];
  *q = a;
  *p = a;
  return a;
}
