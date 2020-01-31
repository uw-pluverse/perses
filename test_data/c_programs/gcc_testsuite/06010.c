


struct S { float f; };
int __attribute__((noinline))
foo (float *r, struct S *p)
{
  int *q = (int *)&p->f;
  int i = *q;
  *r = 0.0;
  return i + *q;
}
