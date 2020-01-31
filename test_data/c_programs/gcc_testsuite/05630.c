

int foo(int k, int *x)
{
  int j=0;
  int res = 0;

  do {
    for (int n=0;n<3;++n);
    res = *x;
  } while (++j<k);
  return res;
}
