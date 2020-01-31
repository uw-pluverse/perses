


extern int posix_memalign(void **memptr,
     long unsigned int alignment, long unsigned int size);

int foo (float *p)
{
  int res = *p;
  struct { void *q1; void *q2; } q;
  if (posix_memalign (&q.q1, 128, 128 * sizeof (int)) != 0)
    return 0;
  if (posix_memalign (&q.q2, 128, 128 * sizeof (int)) != 0)
    return 0;
  *((int *)q.q1) = 1;
  *((int *)q.q2) = 2;
  return res + *p + *((int *)q.q1) + *((int *)q.q2);
}
