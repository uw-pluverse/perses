extern void abort (void);

int test381 (int a, int b)
{
  if (a >= -3 && a <= -1 && b >= -2 && b <= 3)
    {
      int x = a | b;
      if (x == (-3 | -2)
   || x == (-3 | -1)
   || x == (-3 | 0)
   || x == (-3 | 1)
   || x == (-3 | 2)
   || x == (-3 | 3)
   || x == (-2 | -2)
   || x == (-2 | -1)
   || x == (-2 | 0)
   || x == (-2 | 1)
   || x == (-2 | 2)
   || x == (-2 | 3)
   || x == (-1 | -2)
   || x == (-1 | -1)
   || x == (-1 | 0)
   || x == (-1 | 1)
   || x == (-1 | 2)
   || x == (-1 | 3))
 return 0;
      abort ();
    }
  return 0;
}

int test900 (int a, int b)
{
  if (a >= -1 && a <= 2 && b >= 3 && b <= 3)
    {
      int x = a & b;
      if (x == (-1 & 3)
   || x == (0 & 3)
   || x == (1 & 3)
   || x == (2 & 3))
 return 0;
      abort ();
    }
  return 0;
}

int main()
{
  int a, b;
  for (a = -4; a < 4; ++a)
    for (b = -4; b < 4; ++b)
      {
 test381 (a, b);
 test900 (a, b);
      }

  return 0;
}
