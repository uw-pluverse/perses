


int f(int y, int x)
{
  return x | ((~x) & y);
}
int f1(int y, int x)
{
  return x | (y & (~x));
}
int f2(int y, int x)
{
  return ((~x) & y) | x;
}
int f3(int y, int x)
{
  return (y & (~x)) | x;
}
