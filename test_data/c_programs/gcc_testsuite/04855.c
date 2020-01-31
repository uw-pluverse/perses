



int
foo (int x, int y, int z)
{
  int i;
 for (i = 0; i < 256; ++i)
    x += 16, y += x & 15, z += x & 15;
  return x + y + z;
}
