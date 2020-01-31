



extern double sqrt (double);
extern float sqrtf (float);
extern long double sqrtl (long double);


extern void link_error (void);
volatile float f;
volatile double d;
volatile long double ld;

void __attribute__ ((noinline, noclone)) testf (float f, int *res) { float sqrt_res = sqrtf (f); res[0] = sqrt_res < 0; if (res[0]) link_error (); res[1] = sqrt_res <= 0; if (res[1] != (f == 0)) link_error (); res[2] = (sqrt_res == 0); if (res[2] != (f == 0)) link_error (); res[3] = (sqrt_res != 0); if (res[3] != (f != 0)) link_error (); res[4] = (sqrt_res > 0); if (res[4] != (f > 0)) link_error (); res[5] = (sqrt_res >= 0); if (!res[5]) link_error (); }
void __attribute__ ((noinline, noclone)) test (double f, int *res) { double sqrt_res = sqrt (f); res[0] = sqrt_res < 0; if (res[0]) link_error (); res[1] = sqrt_res <= 0; if (res[1] != (f == 0)) link_error (); res[2] = (sqrt_res == 0); if (res[2] != (f == 0)) link_error (); res[3] = (sqrt_res != 0); if (res[3] != (f != 0)) link_error (); res[4] = (sqrt_res > 0); if (res[4] != (f > 0)) link_error (); res[5] = (sqrt_res >= 0); if (!res[5]) link_error (); }
void __attribute__ ((noinline, noclone)) testl (long double f, int *res) { long double sqrt_res = sqrtl (f); res[0] = sqrt_res < 0; if (res[0]) link_error (); res[1] = sqrt_res <= 0; if (res[1] != (f == 0)) link_error (); res[2] = (sqrt_res == 0); if (res[2] != (f == 0)) link_error (); res[3] = (sqrt_res != 0); if (res[3] != (f != 0)) link_error (); res[4] = (sqrt_res > 0); if (res[4] != (f > 0)) link_error (); res[5] = (sqrt_res >= 0); if (!res[5]) link_error (); }

int
main ()
{
  int res[6];
  testf (f, res);
  test (d, res);
  testl (ld, res);
  return 0;
}
