






void foo (_Complex double *self, _Complex double *a, _Complex double *b,
   int a1, int a2)
{
  int i, j;
  for (i = 0; i < a1; ++i)
    for (j = 0; j < a2; ++j)
      self[i] = self[i] + a[i,j] * b[j];
}
