





static const int a = 2;

int test (int param)
{
  int *p = (int *) &a;

  if (param)
    *p = 5;

  return a;
}
