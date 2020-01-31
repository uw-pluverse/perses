


void abort (void);

void parloop (int N)
{
  int i, j;
  int x[500][500];

  for (i = 0; i < N; i++)
    for (j = 0; j < i; j++)
      x[i][j] = i + j + 3;

  for (i = 0; i < N; i++)
    for (j = 0; j < i; j++)
      if (x[i][j] != i + j + 3)
 abort ();
}

int main(void)
{
  parloop(500);

  return 0;
}
