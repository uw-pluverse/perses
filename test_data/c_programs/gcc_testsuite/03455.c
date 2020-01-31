





void foo (int *x, unsigned int y)
{
  int a = y >> -13;
  if (a)
    *x = a;
}
