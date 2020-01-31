

int
foo (int x)
{
  if ((x >> 31) < -1)
    x++;
  return x;
}
