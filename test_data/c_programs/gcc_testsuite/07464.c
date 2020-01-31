



int fun1(int *x, int *y, unsigned int n)
{
  int i, j;
  int dot = 0;

  for (i = 0; i < n; i++)
    dot += *(x++) * *(y++);

  return dot;
}

int fun2(int *x, int *y, unsigned int n)
{
  int i, j;
  int dot = 0;

  for (i = 0; i < n / 8; i++)
    for (j = 0; j < 8; j++)
      dot += *(x++) * *(y++);

  return dot;
}
