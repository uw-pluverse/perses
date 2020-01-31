


int *p;
int *foo (int *q, int i, int j)
{
  p = q + i;
  return p + j;
}
