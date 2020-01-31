int abs(int);
long int labs(long int);
long long int llabs(long long int);
float fabsf(float);
double fabs(double);
long double fabsl(long double);
float cabsf(float _Complex);
double cabs(double _Complex);
long double cabsl(long double _Complex);
void test_int(int x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
void test_long(long x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
void test_long_long(long long x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
void test_float(float x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
void test_double(double x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
void test_long_double(long double x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
void test_complex_float(_Complex float x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
void test_complex_double(_Complex double x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
void test_complex_long_double(_Complex long double x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
void test_unsigned_int(unsigned int x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
void test_unsigned_long(unsigned long x) {
  (void)abs(x);
  (void)labs(x);
  (void)llabs(x);
  (void)fabsf(x);
  (void)fabs(x);
  (void)fabsl(x);
  (void)cabsf(x);
  (void)cabs(x);
  (void)cabsl(x);
  (void)__builtin_abs(x);
  (void)__builtin_labs(x);
  (void)__builtin_llabs(x);
  (void)__builtin_fabsf(x);
  (void)__builtin_fabs(x);
  (void)__builtin_fabsl(x);
  (void)__builtin_cabsf(x);
  (void)__builtin_cabs(x);
  (void)__builtin_cabsl(x);
}
long long test_array() {
  return llabs((long long[]){1});
}
long long test_function_pointer() {
  return llabs(&test_function_pointer);
}
long long test_void_pointer(void *x) {
  return llabs(x);
}
long long test_function() {
  return llabs(test_function);
}
