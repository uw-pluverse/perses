


void abort (void);

int g_sum=0;
int x[500][500];

void
parloop (int N)
{
  int i, j;
  int sum;





  sum = 0;
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      sum += x[i][j];

  g_sum = sum;
}
