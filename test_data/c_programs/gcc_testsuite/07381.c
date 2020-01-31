



void foo(unsigned *p1, unsigned short *p2)
{
  int n;
  for (n = 0; n < 320; n++)
    p1[n] = p2[n * 2];
}
