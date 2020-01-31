




extern void abort (void);

static inline short
f1 (short x, short y)
{
  if (x > 0)
    {
      if (y > 0)
 {
   if (x > 32767 / y)
     return x;
 }
      else if (y < (-32767 - 1) / x)
 return x;
    }
  else
    {
      if (y > 0)
 {
   if (x < (-32767 - 1) / y)
     return x;
 }
      else if (x != 0 && y < 32767 / x)
 return x;
    }
  return x * y;
}

static inline signed char
f2 (signed char x, signed char y)
{
  if (((x ^ y) & (((x ^ ((x ^ y) & (1 << (8 - 1)))) - y) ^ y)) < 0)
    return x;
  return x - y;
}

unsigned int v;

int
f3 (int x, unsigned int y)
{
  f1 (1, 1);
  return 1;
}

int
f4 (unsigned short x)
{
  v = x;
  return 1;
}

int
f5 (int x)
{
  if (f2 (x, 1))
    f1 (1, f4 (1));
  return x;
}

int
f6 (unsigned int x)
{
  f4 (x < (1 != f5 (0)));
  return x;
}

int
main (void)
{
  f6 (1);
  if (v != 0)
    abort ();
  return 0;
}
