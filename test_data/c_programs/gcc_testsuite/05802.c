


int loop1 (int k)
{
  unsigned int i;
  unsigned int j;
  int a[100][100], b[100][100], c[100][100], d[100][100];

  a[0][0] = k;
  for (i = 1; i < 100; i ++)
    for (j = 1; j < (100-1); j++)
      {
        a[i][j] = k * i;
        b[i][j] = a[i][j-1] + k;
        c[i][j] = b[i][j] + a[i][j+1];
        d[i][j] = c[i][j] + k + i;
      }







  return a[100-1][100-1] + b[100-1][100-1] + c[100-1][100-1] + d[100-1][100-1];
}
