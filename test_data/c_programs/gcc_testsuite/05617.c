




void
foo (float *dest, int xcount, int ycount)
{
  int x, y;

  for (y = 0; y < ycount; y++)
    for (x = 0; x < xcount; x++)
      dest[x + y] = (float) 0;
}
