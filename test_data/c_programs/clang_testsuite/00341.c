typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef __attribute__(( ext_vector_type(2) )) int __int2;
typedef __attribute__(( ext_vector_type(3) )) char __char3;
typedef __attribute__(( ext_vector_type(5) )) char __char5;
typedef __attribute__(( ext_vector_type(9) )) char __char9;
typedef __attribute__(( ext_vector_type(19) )) char __char19;
typedef __attribute__(( ext_vector_type(3) )) short __short3;
typedef __attribute__(( ext_vector_type(5) )) short __short5;
double varargs_vec_2i(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __int2 c3 = __builtin_va_arg(ap,__int2);
  sum = sum + c3.x + c3.y;
  __builtin_va_end(ap);
  return sum;
}
double test_2i(__int2 *in) {
  return varargs_vec_2i(3, *in);
}
double varargs_vec_3c(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __char3 c3 = __builtin_va_arg(ap,__char3);
  sum = sum + c3.x + c3.y;
  __builtin_va_end(ap);
  return sum;
}
double test_3c(__char3 *in) {
  return varargs_vec_3c(3, *in);
}
double varargs_vec_5c(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __char5 c5 = __builtin_va_arg(ap,__char5);
  sum = sum + c5.x + c5.y;
  __builtin_va_end(ap);
  return sum;
}
double test_5c(__char5 *in) {
  return varargs_vec_5c(5, *in);
}
double varargs_vec_9c(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __char9 c9 = __builtin_va_arg(ap,__char9);
  sum = sum + c9.x + c9.y;
  __builtin_va_end(ap);
  return sum;
}
double test_9c(__char9 *in) {
  return varargs_vec_9c(9, *in);
}
double varargs_vec_19c(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __char19 c19 = __builtin_va_arg(ap,__char19);
  sum = sum + c19.x + c19.y;
  __builtin_va_end(ap);
  return sum;
}
double test_19c(__char19 *in) {
  return varargs_vec_19c(19, *in);
}
double varargs_vec_3s(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __short3 c3 = __builtin_va_arg(ap,__short3);
  sum = sum + c3.x + c3.y;
  __builtin_va_end(ap);
  return sum;
}
double test_3s(__short3 *in) {
  return varargs_vec_3s(3, *in);
}
double varargs_vec_5s(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __short5 c5 = __builtin_va_arg(ap,__short5);
  sum = sum + c5.x + c5.y;
  __builtin_va_end(ap);
  return sum;
}
double test_5s(__short5 *in) {
  return varargs_vec_5s(5, *in);
}
typedef struct
{
  __int2 i2;
  float f;
} StructWithVec;
double varargs_struct(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  StructWithVec c3 = __builtin_va_arg(ap,StructWithVec);
  sum = sum + c3.i2.x + c3.i2.y + c3.f;
  __builtin_va_end(ap);
  return sum;
}
double test_struct(StructWithVec* d) {
  return varargs_struct(3, *d);
}
