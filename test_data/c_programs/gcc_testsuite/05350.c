

int f1(int a,int b)
{
  return (a|b) ^ b;
}
int f2(int a,int b)
{
  return (b|a) ^ b;
}
int f3(int a,int b)
{
  return b^(a|b);
}
int f4(int a,int b)
{
  return b^(b|a);
}
