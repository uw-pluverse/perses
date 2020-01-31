long double dataLD = 1.0L;
long double _Complex dataLDC = {1.0L, 1.0L};
long double TestLD(long double x) {
  return x * x;
}
long double _Complex TestLDC(long double _Complex x) {
  return x * x;
}
typedef __builtin_va_list va_list;
int TestGetVarInt(va_list ap) {
  return __builtin_va_arg(ap, int);
}
double TestGetVarDouble(va_list ap) {
  return __builtin_va_arg(ap, double);
}
long double TestGetVarLD(va_list ap) {
  return __builtin_va_arg(ap, long double);
}
long double _Complex TestGetVarLDC(va_list ap) {
  return __builtin_va_arg(ap, long double _Complex);
}
void TestVarArg(const char *s, ...);
void TestPassVarInt(int x) {
  TestVarArg("A", x);
}
void TestPassVarFloat(float x) {
  TestVarArg("A", x);
}
void TestPassVarDouble(double x) {
  TestVarArg("A", x);
}
void TestPassVarLD(long double x) {
  TestVarArg("A", x);
}
void TestPassVarLDC(long double _Complex x) {
  TestVarArg("A", x);
}
