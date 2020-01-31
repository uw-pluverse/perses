



extern int a[13][13][13][13], k, l, m;

void
foo (int *q, float *p)
{
  int i, j, n, o;
 for (i = 0; i < 13; i++)
    for (j = 0; j < 13; j++)
      for (n = 0; n < 13; n++)
 for (o = 0; o < 13; o += 2)
   q[k] *= p[k] + 7 * i + 14 * j + 21 * n + 28 * o, k += m + 1;
}

void
bar (float *p)
{
  int i, j, n, o;
 for (i = 0; i < 13; i++)
    for (j = 0; j < 13; j++)
      for (n = 0; n < 13; n++)
 for (o = 0; o < 13; o += 2)
   a[i][j][n][o] *= p[k], k += m + 1;
}
