





int *
foo (int a, int *b, int *c, int *d)
{
  int i, *r = __builtin_alloca (a * sizeof (int));
  __builtin_memcpy (r, d, a * sizeof (int));
  for (i = 0; i < 64; i++)
    c[i] += b[i];
  for (i = 0; i < a; i++)
    if (r[i] == 0)
      r[i] = 1;
  return r;
}
