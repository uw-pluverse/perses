


int foo(int *a, int r)
{
  int ret = 0;
  *a = 1;
  if (r == 3)
    *a = 5;
  else
    ret = r + 20;
  return ret;
}
