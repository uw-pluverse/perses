

float A[1000][1000], B[1000][1000], C[1000][1000];



void matmult (int n)
{
  int i,j,k;

  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      for (k = 0; k < n; k++)
        A[i][j] += B[i][k] * C[k][j];
}
