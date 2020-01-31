

int x, *y, z, *p;

void
foo (void)
{
  p = y + (8 * (x == 1 || x == 3) + z);
}
