


extern void vrp_keep (void);

void
f2 (int c, int b)
{
  int s = 0;
  if (c == 0)
    s += 1;
  else if (c < 1)
    s -= 1;

  b = (b & 1) + 1;

  b = s << b;

  if (b == -4)
    vrp_keep ();
  if (b == 4)
    vrp_keep ();
}

void
f3 (int s, int b)
{
  if (s >> 3 == -2)
    {

      b = (b & 1) + 1;

      b = s << b;



      if (b == -64)
 vrp_keep ();
      if (b == -18)
 vrp_keep ();
    }
}

void
f4 (unsigned int s, unsigned int b)
{
  s |= ~(0xffU);

  b = (b & 1) + 1;

  b = s << b;

  if (b == ~0x3ffU)
    vrp_keep ();
  if (b == ~0x1U)
    vrp_keep ();
}
