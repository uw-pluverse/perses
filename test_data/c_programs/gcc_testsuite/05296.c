


struct S { float a, b; };

float
foo (int x, float y)
{
  struct S z[1024];
  z[x].a = y;
  struct S *p = &z[x];
  float *q = (float *) p;
  return *q;
}
