


void foo (float **a, float **b, float *c, int n, int m, int l)
{
  int i,j,k;
  float s;
  for (i=0; i<l; i++)
    for (j=0; j<n; j++)
      for (k=0; k<m; k++)
 c[i] += a[i][k] * b[k][j];
}
