

enum { E0 = 0, E1 = 1, E2 = 2 } e;

int
foo (void)
{
  return __builtin_popcount ((int) e);
}
