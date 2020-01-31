typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
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
struct S {
    int x;
    int y;
    int z;
};
struct S test_struct(char *fmt, ...) {
  va_list va;
  __builtin_va_start(va,fmt);
  struct S v = __builtin_va_arg(va,struct S);
  __builtin_va_end(va);
  return v;
}
