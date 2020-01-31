typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef __attribute__(( ext_vector_type(2) )) char __char2;
typedef __attribute__(( ext_vector_type(3) )) char __char3;
typedef __attribute__(( ext_vector_type(4) )) char __char4;
typedef __attribute__(( ext_vector_type(5) )) char __char5;
typedef __attribute__(( ext_vector_type(9) )) char __char9;
typedef __attribute__(( ext_vector_type(19) )) char __char19;
typedef __attribute__(( ext_vector_type(3) )) short __short3;
typedef __attribute__(( ext_vector_type(5) )) short __short5;
typedef __attribute__(( ext_vector_type(3) )) int __int3;
typedef __attribute__(( ext_vector_type(5) )) int __int5;
typedef __attribute__(( ext_vector_type(3) )) double __double3;
double varargs_vec_2c(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __char2 c3 = __builtin_va_arg(ap,__char2);
  sum = sum + c3.x + c3.y;
  __builtin_va_end(ap);
  return sum;
}
double test_2c(__char2 *in) {
  return varargs_vec_2c(3, *in);
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
double varargs_vec_4c(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __char4 c4 = __builtin_va_arg(ap,__char4);
  sum = sum + c4.x + c4.y;
  __builtin_va_end(ap);
  return sum;
}
double test_4c(__char4 *in) {
  return varargs_vec_4c(4, *in);
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
double varargs_vec_3i(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __int3 c3 = __builtin_va_arg(ap,__int3);
  sum = sum + c3.x + c3.y;
  __builtin_va_end(ap);
  return sum;
}
double test_3i(__int3 *in) {
  return varargs_vec_3i(3, *in);
}
double varargs_vec_5i(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __int5 c5 = __builtin_va_arg(ap,__int5);
  sum = sum + c5.x + c5.y;
  __builtin_va_end(ap);
  return sum;
}
double test_5i(__int5 *in) {
  return varargs_vec_5i(5, *in);
}
double varargs_vec_3d(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __double3 c3 = __builtin_va_arg(ap,__double3);
  sum = sum + c3.x + c3.y;
  __builtin_va_end(ap);
  return sum;
}
double test_3d(__double3 *in) {
  return varargs_vec_3d(3, *in);
}
double varargs_vec(int fixed, ...) {
  va_list ap;
  double sum = fixed;
  __builtin_va_start(ap,fixed);
  __char3 c3 = __builtin_va_arg(ap,__char3);
  sum = sum + c3.x + c3.y;
  __char5 c5 = __builtin_va_arg(ap,__char5);
  sum = sum + c5.x + c5.y;
  __char9 c9 = __builtin_va_arg(ap,__char9);
  sum = sum + c9.x + c9.y;
  __char19 c19 = __builtin_va_arg(ap,__char19);
  sum = sum + c19.x + c19.y;
  __short3 s3 = __builtin_va_arg(ap,__short3);
  sum = sum + s3.x + s3.y;
  __short5 s5 = __builtin_va_arg(ap,__short5);
  sum = sum + s5.x + s5.y;
  __int3 i3 = __builtin_va_arg(ap,__int3);
  sum = sum + i3.x + i3.y;
  __int5 i5 = __builtin_va_arg(ap,__int5);
  sum = sum + i5.x + i5.y;
  __double3 d3 = __builtin_va_arg(ap,__double3);
  sum = sum + d3.x + d3.y;
  __builtin_va_end(ap);
  return sum;
}
double test(__char3 *c3, __char5 *c5, __char9 *c9, __char19 *c19,
            __short3 *s3, __short5 *s5, __int3 *i3, __int5 *i5,
            __double3 *d3) {
  double ret = varargs_vec(3, *c3, *c5, *c9, *c19, *s3, *s5, *i3, *i5, *d3);
  return ret;
}
__attribute__((noinline)) double args_vec_3c(int fixed, __char3 c3) {
  double sum = fixed;
  sum = sum + c3.x + c3.y;
  return sum;
}
double fixed_3c(__char3 *in) {
  return args_vec_3c(3, *in);
}
__attribute__((noinline)) double args_vec_5c(int fixed, __char5 c5) {
  double sum = fixed;
  sum = sum + c5.x + c5.y;
  return sum;
}
double fixed_5c(__char5 *in) {
  return args_vec_5c(5, *in);
}
__attribute__((noinline)) double args_vec_9c(int fixed, __char9 c9) {
  double sum = fixed;
  sum = sum + c9.x + c9.y;
  return sum;
}
double fixed_9c(__char9 *in) {
  return args_vec_9c(9, *in);
}
__attribute__((noinline)) double args_vec_19c(int fixed, __char19 c19) {
  double sum = fixed;
  sum = sum + c19.x + c19.y;
  return sum;
}
double fixed_19c(__char19 *in) {
  return args_vec_19c(19, *in);
}
__attribute__((noinline)) double args_vec_3s(int fixed, __short3 c3) {
  double sum = fixed;
  sum = sum + c3.x + c3.y;
  return sum;
}
double fixed_3s(__short3 *in) {
  return args_vec_3s(3, *in);
}
__attribute__((noinline)) double args_vec_5s(int fixed, __short5 c5) {
  double sum = fixed;
  sum = sum + c5.x + c5.y;
  return sum;
}
double fixed_5s(__short5 *in) {
  return args_vec_5s(5, *in);
}
__attribute__((noinline)) double args_vec_3i(int fixed, __int3 c3) {
  double sum = fixed;
  sum = sum + c3.x + c3.y;
  return sum;
}
double fixed_3i(__int3 *in) {
  return args_vec_3i(3, *in);
}
__attribute__((noinline)) double args_vec_5i(int fixed, __int5 c5) {
  double sum = fixed;
  sum = sum + c5.x + c5.y;
  return sum;
}
double fixed_5i(__int5 *in) {
  return args_vec_5i(5, *in);
}
__attribute__((noinline)) double args_vec_3d(int fixed, __double3 c3) {
  double sum = fixed;
  sum = sum + c3.x + c3.y;
  return sum;
}
double fixed_3d(__double3 *in) {
  return args_vec_3d(3, *in);
}
