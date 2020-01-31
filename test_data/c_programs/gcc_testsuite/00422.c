extern long call (long);

long
test_switch (long a, long b)
{
  long c;

  switch (a)
    {
    case 0: c = -b; break;
    case 1: c = ~b; break;
    case 2: c = b+1; break;
    default: c = b & 9; break;
    }

  return call (c) + 1;
}
