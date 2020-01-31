extern float crealf(float _Complex);
extern double creal(double _Complex);
extern long double creall(long double _Complex);
extern float cimagf(float _Complex);
extern double cimag(double _Complex);
extern long double cimagl(long double _Complex);
double test_creal(double _Complex z) {
  return creal(z);
}
long double test_creall(double _Complex z) {
  return creall(z);
}
float test_crealf(double _Complex z) {
  return crealf(z);
}
double test_cimag(double _Complex z) {
  return cimag(z);
}
long double test_cimagl(double _Complex z) {
  return cimagl(z);
}
float test_cimagf(double _Complex z) {
  return cimagf(z);
}
