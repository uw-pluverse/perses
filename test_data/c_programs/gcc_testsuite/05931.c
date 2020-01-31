


int foo(int i, int j)
{
 char g[16];
 if (&g[i] == &g[j])
  return 1;
 return 0;
}
