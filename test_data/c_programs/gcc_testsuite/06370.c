


unsigned a[100], b[100];
inline void bar()
{
 a[10] = b[10];
}

int foo(void)
{
  int i;
  bar();
  for (i = 0; i < 2; i++)
  {
     a[i]= b[i] + 1;
  }
  return 1;
}

int foo2(void)
{
  int i;
  for (i = 0; i < 2; i++)
  {
     a[i]= b[i] + 1;
  }
  return 1;
}
