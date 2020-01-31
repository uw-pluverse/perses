


extern int posix_memalign(void **memptr,
     long unsigned int alignment, long unsigned int size);

int foo (float *p)
{
  int res = *p;
  int *q;
  void *tem;
  if (posix_memalign (&tem, 128, 128 * sizeof (int)) != 0)
    return 0;
  q = (int *)tem;
  *q = 1;
  return res + *p;
}
