






union vx {short f[8]; int v;};
int vec;

void
foo5 (int vec)
{
  ((union vx) vec).f[5] = 1;
}
