

int f1(int a,int b,int c,int d)
{
  return ((a&d)|(b&c)) ^ (b&c);
}

int f2(int a,int b,int c,int d)
{
  return (b&c) ^ ((a&d)|(b&c));
}

int f3(int a,int b,int c,int d)
{
  return ((b&c)|(a&d)) ^ (b&c);
}

int f4(int a,int b,int c,int d)
{
  return (b&c) ^ ((b&c)|(a&d));
}
