

extern void abort (void);
extern void exit (int);
float __attribute__((noinline)) float_min1(float a, float b) { return ((a) < (b) ? (a) : (b)); }
float __attribute__((noinline)) float_min2(float a, float b) { return ((a) <= (b) ? (a) : (b)); }
float __attribute__((noinline)) float_max1(float a, float b) { return ((a) > (b) ? (a) : (b)); }
float __attribute__((noinline)) float_max2(float a, float b) { return ((a) >= (b) ? (a) : (b)); }

double __attribute__((noinline)) double_min1(double a, double b) { return ((a) < (b) ? (a) : (b)); }
double __attribute__((noinline)) double_min2(double a, double b) { return ((a) <= (b) ? (a) : (b)); }
double __attribute__((noinline)) double_max1(double a, double b) { return ((a) > (b) ? (a) : (b)); }
double __attribute__((noinline)) double_max2(double a, double b) { return ((a) >= (b) ? (a) : (b)); }

int main()
{
  if (float_min1(0.f, -1.f) != -1.f) abort();
  if (float_min1(-1.f, 0.f) != -1.f) abort();
  if (float_min1(0.f, 1.f) != 0.f) abort();
  if (float_min1(1.f, 0.f) != 0.f) abort();
  if (float_min1(-1.f, 1.f) != -1.f) abort();
  if (float_min1(1.f, -1.f) != -1.f) abort();

  if (float_max1(0.f, -1.f) != 0.f) abort();
  if (float_max1(-1.f, 0.f) != 0.f) abort();
  if (float_max1(0.f, 1.f) != 1.f) abort();
  if (float_max1(1.f, 0.f) != 1.f) abort();
  if (float_max1(-1.f, 1.f) != 1.f) abort();
  if (float_max1(1.f, -1.f) != 1.f) abort();

  if (float_min2(0.f, -1.f) != -1.f) abort();
  if (float_min2(-1.f, 0.f) != -1.f) abort();
  if (float_min2(0.f, 1.f) != 0.f) abort();
  if (float_min2(1.f, 0.f) != 0.f) abort();
  if (float_min2(-1.f, 1.f) != -1.f) abort();
  if (float_min2(1.f, -1.f) != -1.f) abort();

  if (float_max2(0.f, -1.f) != 0.f) abort();
  if (float_max2(-1.f, 0.f) != 0.f) abort();
  if (float_max2(0.f, 1.f) != 1.f) abort();
  if (float_max2(1.f, 0.f) != 1.f) abort();
  if (float_max2(-1.f, 1.f) != 1.f) abort();
  if (float_max2(1.f, -1.f) != 1.f) abort();

  if (double_min1(0., -1.) != -1.) abort();
  if (double_min1(-1., 0.) != -1.) abort();
  if (double_min1(0., 1.) != 0.) abort();
  if (double_min1(1., 0.) != 0.) abort();
  if (double_min1(-1., 1.) != -1.) abort();
  if (double_min1(1., -1.) != -1.) abort();

  if (double_max1(0., -1.) != 0.) abort();
  if (double_max1(-1., 0.) != 0.) abort();
  if (double_max1(0., 1.) != 1.) abort();
  if (double_max1(1., 0.) != 1.) abort();
  if (double_max1(-1., 1.) != 1.) abort();
  if (double_max1(1., -1.) != 1.) abort();

  if (double_min2(0., -1.) != -1.) abort();
  if (double_min2(-1., 0.) != -1.) abort();
  if (double_min2(0., 1.) != 0.) abort();
  if (double_min2(1., 0.) != 0.) abort();
  if (double_min2(-1., 1.) != -1.) abort();
  if (double_min2(1., -1.) != -1.) abort();

  if (double_max2(0., -1.) != 0.) abort();
  if (double_max2(-1., 0.) != 0.) abort();
  if (double_max2(0., 1.) != 1.) abort();
  if (double_max2(1., 0.) != 1.) abort();
  if (double_max2(-1., 1.) != 1.) abort();
  if (double_max2(1., -1.) != 1.) abort();

  exit(0);
}
