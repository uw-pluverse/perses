


void abort (void);

void parloop (int N)
{
  int i, j,ii;
  int x[401][10][401];

for (ii = 0; ii < N; ii++)
  for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      x[i][j][ii] = ii+i + j + 3;

for (ii = 0; ii < N; ii++)
  for (i = 0; i < N;i++)
    for (j = 0; j < N; j++)
      if (x[i][j][ii] != ii+i + j + 3)
 abort ();
}

int main(void)
{
  parloop(400);

  return 0;
}
