


int x[4092];
int y[1024];

void foo (int s)
{
  int i, j;
  for (i = 0, j = 0; j < 1023; i += s, j++)
    y[j] += x[i];
}
