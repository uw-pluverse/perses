


void foo (int);
int test ()
{
  int a[10000][10000];
  int b[10000][10000];
  int i, j;

  for (i = 0; i < 10000; i++)
    for (j = 0; j < 10000; j++)
      a[i][j] = i*j;

  for (j = 1; j < 10000; j++)
    for (i = 0; i < 10000; i++)
      a[i][j] = a[i][j-1] + b[i][j];

  for (i = 0; i < 10000; i++)
    for (j = 0; j < 10000; j++)
      foo (a[i][j]);
}
