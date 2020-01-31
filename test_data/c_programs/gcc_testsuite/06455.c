



void
foo (long *w, long *x, unsigned char *y, int z)
{
  for (; z < 429; z++)
    w[z] = (-19 ^ y[z]) & x[z];
}
