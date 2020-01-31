


int foo(int *a, int r, short *b)
{
  int ret = 0;
  *a = 1;
  if (r == 3)
    *a = 5;
  else
    ret = r + 20;
  *b = 9;
  return ret;
}
