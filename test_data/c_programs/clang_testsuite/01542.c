float ReturnFloatFromDouble(double d) {
  return d;
}
float ReturnFloatFromLongDouble(long double ld) {
  return ld;
}
double ReturnDoubleFromLongDouble(long double ld) {
  return ld;
}
double ReturnDoubleFromFloat(float f) {
  return f;
}
long double ReturnLongDoubleFromFloat(float f) {
  return f;
}
long double ReturnLongDoubleFromDouble(double d) {
  return d;
}
void Assignment(float f, double d, long double ld) {
  d = f;
  ld = f;
  ld = d;
  f = d;
  f = ld;
  d = ld;
}
extern void DoubleParameter(double);
extern void LongDoubleParameter(long double);
void ArgumentPassing(float f, double d) {
  DoubleParameter(f);
  LongDoubleParameter(f);
  LongDoubleParameter(d);
}
void BinaryOperator(float f, double d, long double ld) {
  f = f * d;
  f = d * f;
  f = f * ld;
  f = ld * f;
  d = d * ld;
  d = ld * d;
}
void MultiplicationAssignment(float f, double d, long double ld) {
  d *= f;
  ld *= f;
  ld *= d;
  f *= d;
  f *= ld;
  d *= ld;
}
void ConditionalOperator(float f, double d, long double ld, int i) {
  f = i ? f : d;
  f = i ? d : f;
  f = i ? f : ld;
  f = i ? ld : f;
  d = i ? d : ld;
  d = i ? ld : d;
}
