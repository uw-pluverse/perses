typedef double vector8double __attribute__((__vector_size__(64)));
typedef float vector8float __attribute__((__vector_size__(32)));
typedef long vector8long __attribute__((__vector_size__(64)));
typedef short vector8short __attribute__((__vector_size__(16)));
typedef unsigned long vector8ulong __attribute__((__vector_size__(64)));
typedef unsigned short vector8ushort __attribute__((__vector_size__(16)));
vector8float flt_trunc(vector8double x) {
  return __builtin_convertvector(x, vector8float);
}
vector8double flt_ext(vector8float x) {
  return __builtin_convertvector(x, vector8double);
}
vector8long flt_tosi(vector8float x) {
  return __builtin_convertvector(x, vector8long);
}
vector8ulong flt_toui(vector8float x) {
  return __builtin_convertvector(x, vector8ulong);
}
vector8ulong fltd_toui(vector8double x) {
  return __builtin_convertvector(x, vector8ulong);
}
vector8ulong int_zext(vector8ushort x) {
  return __builtin_convertvector(x, vector8ulong);
}
vector8long int_sext(vector8short x) {
  return __builtin_convertvector(x, vector8long);
}
vector8float int_tofp(vector8short x) {
  return __builtin_convertvector(x, vector8float);
}
vector8float uint_tofp(vector8ushort x) {
  return __builtin_convertvector(x, vector8float);
}
vector8double int_toT_fp(vector8long x) {
  return __builtin_convertvector(x, vector8double);
}
