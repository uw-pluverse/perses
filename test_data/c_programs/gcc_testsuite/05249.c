


extern void abort (void);
struct X {
  int *p;
  int *q;
  int *r;
};
int __attribute__((noinline))
foo(int i, int j, int k, int off)
{
  struct X x;
  int **p, *q;
  x.p = &i;
  x.q = &j;
  x.r = &k;
  p = &x.q;
  p -= 1;

  q = *p;
  return *q;
}
