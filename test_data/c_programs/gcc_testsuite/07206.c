


int a[10];
int *foo1 (int i)
{
  return &a[10];
}
int *foo2 (int i)
{
  return &a[11];
}
int foo3 (int i)
{
  return a[9];
}
int foo4 (int i)
{
  return a[10];
}
