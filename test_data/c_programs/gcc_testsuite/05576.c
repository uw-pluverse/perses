



int
foo (int a, int *p)
{
  int x = *p + 2;
  int y = *p - 1;
  int z = *p + 9;



  if (p)
    a = x + y + z;
  else
    a = x - y;

  return a;
}
