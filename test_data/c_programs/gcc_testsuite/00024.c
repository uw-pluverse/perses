void
test (void)
{
  do { do { volatile double a = 1.5, b; b = __builtin_rint (a); } while (0); do { volatile float a = 1.5, b; b = __builtin_rintf (a); } while (0); } while (0);
  do { do { volatile double a = 1.5, b; b = __builtin_ceil (a); } while (0); do { volatile float a = 1.5, b; b = __builtin_ceilf (a); } while (0); } while (0);
  do { do { volatile double a = 1.5, b; b = __builtin_floor (a); } while (0); do { volatile float a = 1.5, b; b = __builtin_floorf (a); } while (0); } while (0);
  do { do { volatile double a = 1.5, b; b = __builtin_trunc (a); } while (0); do { volatile float a = 1.5, b; b = __builtin_truncf (a); } while (0); } while (0);
}
