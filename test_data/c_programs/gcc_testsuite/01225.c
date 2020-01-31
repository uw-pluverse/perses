




void
test (unsigned short *x, signed char *y)
{
  int i;
  for (i = 0; i < 32; i++)
    x[i] = (short) (y[i] << 5);
}
