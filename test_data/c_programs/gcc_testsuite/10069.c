



void
foo (int *a, int *b, int *c)
{
  int i;
#pragma GCC ivdep
 for (i = 0; i < 64; i++)
    a[i] = b[i] * c[i];
}
