




extern void f (int a, int b, int c, int d);

int g (int x, int y, int z)
{
  f (100, x, y, z);
  return -1;
}
