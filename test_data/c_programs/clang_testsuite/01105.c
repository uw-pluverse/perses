void test_sqrt(float a0, double a1, long double a2) {
  float l0 = sqrtf(a0);
  double l1 = sqrt(a1);
  long double l2 = sqrtl(a2);
}
void test_pow(float a0, double a1, long double a2) {
  float l0 = powf(a0, a0);
  double l1 = pow(a1, a1);
  long double l2 = powl(a2, a2);
}
void test_fma(float a0, double a1, long double a2) {
    float l0 = fmaf(a0, a0, a0);
    double l1 = fma(a1, a1, a1);
    long double l2 = fmal(a2, a2, a2);
}
void test_builtins(double d, float f, long double ld) {
  double atan_ = atan(d);
  long double atanl_ = atanl(ld);
  float atanf_ = atanf(f);
  double atan2_ = atan2(d, 2);
  long double atan2l_ = atan2l(ld, ld);
  float atan2f_ = atan2f(f, f);
  double exp_ = exp(d);
  long double expl_ = expl(ld);
  float expf_ = expf(f);
  double log_ = log(d);
  long double logl_ = logl(ld);
  float logf_ = logf(f);
}
