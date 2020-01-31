





extern void
g (void);

int
f (int c, int i)
{
  int a1, a2, a3, x1, x2, x3, x;

  a1 = i * 16;
  x1 = c + a1;

  i = i + 2;
  a2 = i * 16;
  x2 = c + a2;

  if (x2 > 6)
    {
      if (c < 200)
 i = i + 2;
      else
 i = i + 4;
      g ();
    }
  else
    i = i + 6;

  i = i + 2;
  a3 = i * 16;
  x3 = c + a3;

  x = x1 + x2 + x3;
  return x;
}
