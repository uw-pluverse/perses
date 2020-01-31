


int foo(int *a, int r, int *b)
{
  int ret = 0;
  *a = 1;
  if (r == 3)
    {
      *a = 5;
      *b = 3;
    }
  return ret;
}
