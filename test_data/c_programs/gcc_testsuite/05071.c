


int foo (int x)
{
  int tem = x / 3;
  return tem / 5;
}
int bar (int x)
{
  int tem = x / 3;
  return tem / (2147483647 / 2);
}
