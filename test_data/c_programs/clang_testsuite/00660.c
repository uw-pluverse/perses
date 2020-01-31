typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef int v4i32 __attribute__ ((__vector_size__ (16)));
int test_i32(char *fmt, ...) {
  va_list va;
  __builtin_va_start(va,fmt);
  int v = __builtin_va_arg(va,int);
  __builtin_va_end(va);
  return v;
}
long long test_i64(char *fmt, ...) {
  va_list va;
  __builtin_va_start(va,fmt);
  long long v = __builtin_va_arg(va,long long);
  __builtin_va_end(va);
  return v;
}
char *test_ptr(char *fmt, ...) {
  va_list va;
  __builtin_va_start(va,fmt);
  char *v = __builtin_va_arg(va,char *);
  __builtin_va_end(va);
  return v;
}
int test_v4i32(char *fmt, ...) {
  va_list va;
  __builtin_va_start(va,fmt);
  v4i32 v = __builtin_va_arg(va,v4i32);
  __builtin_va_end(va);
  return v[0];
}
