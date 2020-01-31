



void
foo (int w, int x, int *y, int *z)
{
  float f;
  while (w--)
    {
      f = x;
      if (y)
 *y = (long int) y + w;
      if (z)
 *z = w;
    }
}
