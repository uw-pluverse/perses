






double a[1000][1000];

double test(void)
{
  unsigned i, j;
  double sum = 0;


  for (i = 0; i < 900; i++)
    for (j = 0; j < 900; j++)
      sum += a[i][j];



  for (i = 0; i < 900; i++)
    for (j = 0; j < 900; j++)
      sum += a[i][j] * a[i + 10][j];



  for (i = 0; i < 900; i++)
    for (j = 0; j < 900; j++)
      sum += a[i][j] * a[i + 100][j];



  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      sum += a[i][j] * a[i + 100][j];




  for (i = 0; i < 1000; i++)
    for (j = 0; j < 1000; j++)
      sum += a[j][i];

  return sum;
}
