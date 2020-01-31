


int posix_memalign(void **memptr, long unsigned int alignment, long unsigned int size);
void bar (int *);

int *foo (int n)
{
  int *p;
  int *q;
  void *tem;
  if (posix_memalign (&tem, 256, n * sizeof (int)) != 0)
    return (void *)0;
  p = (int *)tem;
  if (posix_memalign (&tem, 256, n * sizeof (int)) != 0)
    return (void *)0;
  q = (int *)tem;
  bar (q);
  int i;
  for (i = 0; i < n; ++i)
    p[i] = q[i] + q[i];
  return p;
}
