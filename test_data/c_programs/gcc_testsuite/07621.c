




void foo (short *);

void
bar (short x, int y)
{
  if (y)
    x = x << 8 | (unsigned short) x >> 8;
  foo (&x);
}
