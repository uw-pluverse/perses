


int f (int x, int y)
{
  if (x > -1024 && x < 0 && y > -1024 && y < 0)
    {
      x = x ^ y;
      if (x < 0 || x > 1023)
 return 1234;
    }
  return x;
}
