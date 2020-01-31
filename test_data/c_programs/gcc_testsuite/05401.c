


extern void vrp_keep (void);

void
f2 (int s, int b)
{
  if (s > 1)
    s = 1;

  b = (b & 1) + 1;

  b = s << b;

  if (b == -2)
    vrp_keep ();
}
