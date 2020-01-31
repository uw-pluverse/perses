



int f(int *p)
{
  int a = *p;
  int *null = 0;
  *null = 5;
  return *p == a;
}
