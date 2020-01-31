







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
    case 3: c = b-2; break;
    case 4: c = b*3; break;
    case 5: c = b/4; break;
    case 6: c = b<<5; break;
    case 7: c = b>>6; break;
    case 8: c = b|7; break;
    case 9: c = b^8; break;
    default: c = b&9; break;
    }

  return call (c) + 1;
}
