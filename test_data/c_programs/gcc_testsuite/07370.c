



int a[2048];

void
f1 (int x, int y)
{
  int i;
  x &= -256;
  y &= -256;
  for (i = x + 256; i < y; i++)
    a[i]++;
}

void
f2 (int x, int y)
{
  int i;
  if (x & 31)
    __builtin_unreachable ();
  if (y & 31)
    __builtin_unreachable ();
  for (i = x + 256; i < x + y; i++)
    a[i]++;
}

void
f3 (int x, int y)
{
  int i;
  if (x % 256)
    __builtin_unreachable ();
  if (y % 256)
    __builtin_unreachable ();
  for (i = x + 256; i < x + y; i++)
    a[i]++;
}

void
f4 (int x, int y)
{
  int i;
  if ((x % 256) != 0)
    __builtin_unreachable ();
  if ((y % 256) != 0)
    __builtin_unreachable ();
  for (i = x + 256; i < x + y; i++)
    a[i]++;
}
