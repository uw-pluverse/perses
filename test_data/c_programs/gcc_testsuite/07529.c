



void foo(int j, int *A)
{
  int i;
  for (i = 0; i < j; i ++) A[i] = i;
  for (; i < 4096; i ++) A[i] = 0;
}
