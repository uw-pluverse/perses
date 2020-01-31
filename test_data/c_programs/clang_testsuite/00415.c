int check_char() {
  return sizeof(char);
}
int check_short() {
  return sizeof(short);
}
int check_int() {
  return sizeof(int);
}
int check_long() {
  return sizeof(long);
}
int check_longlong() {
  return sizeof(long long);
}
int check_fp16() {
  return sizeof(__fp16);
}
int check_float() {
  return sizeof(float);
}
int check_double() {
  return sizeof(double);
}
int check_longdouble() {
  return sizeof(long double);
}
int check_floatComplex() {
  return sizeof(float _Complex);
}
int check_doubleComplex() {
  return sizeof(double _Complex);
}
int check_longdoubleComplex() {
  return sizeof(long double _Complex);
}
int check_bool() {
  return sizeof(_Bool);
}
int check_wchar() {
  return sizeof(int);
}
int check_wchar_is_unsigned() {
  return (int)-1 > (int)0;
}
int check_ptr() {
  return sizeof(void *);
}
