






int
plus (int x, int y)
{
  if (x != 0)
    if (y != 0)
      {
        int z = x + y;
        if (z != 0)
          return 1;
      }
  return 0;
}

int
minus (int x, int y)
{
  if (x != 0)
    if (y != 0)
      {
        int z = x - y;
        if (z != 0)
          return 1;
      }
  return 0;
}

int
mult (unsigned x, unsigned y)
{
  if (x != 0)
    if (y != 0)
      {
 unsigned z = x * y;
 if (z != 0)
   return 1;
      }
  return 0;
}
