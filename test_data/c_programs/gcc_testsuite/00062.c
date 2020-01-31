



void
foo (char *x, char *y, char *z, int a)
{
  int i;
  for (i = a; i > 0; i--)
    *x++ = *y++ = *z++;
}
