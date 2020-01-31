


int test1(int a, int b)
{
  return (a & b) | b;
}

int test2(int c, int d)
{
  return (c & d) | c;
}

int test3(int e, int f)
{
  return e | (e & f);
}

int test4(int g, int h)
{
  return g | (h & g);
}

int test5(int i, int j)
{
  return (i | j) & j;
}

int test6(int k, int l)
{
  return (k | l) & k;
}

int test7(int m, int n)
{
  return m & (m | n);
}

int test8(int o, int p)
{
  return o & (p | o);
}
