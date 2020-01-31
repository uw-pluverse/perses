



int a[1024] = {0.0};
int b[1024] = {0.0};
int c[1024] = {0.0};
int foo (float *x)
{
  int i = 0;

  for (i = 0; i < 1024; i++)
    {
      c[i] = (x[i] > 0.0) ? a[i] : b[i];
    }

  return 0;
}
