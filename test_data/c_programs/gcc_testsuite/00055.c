void
test (void)
{
  do { do { volatile double a = 1.5, b; b = __builtin_rint (a); } while (0); do { volatile float a = 1.5, b; b = __builtin_rintf (a); } while (0); } while (0);
}
