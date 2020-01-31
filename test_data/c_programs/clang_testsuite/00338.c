typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
extern void abort() __attribute__((noreturn));
struct tiny {
  char c;
};
union data {
  char c;
};
void fstr(int n, ...) {
  struct tiny x;
  va_list ap;
  __builtin_va_start(ap,n);
  x = __builtin_va_arg(ap,struct tiny);
  if (x.c != 10)
    abort();
  __builtin_va_end(ap);
}
void funi(int n, ...) {
  union data x;
  va_list ap;
  __builtin_va_start(ap,n);
  x = __builtin_va_arg(ap,union data);
  if (x.c != 10)
    abort();
  __builtin_va_end(ap);
}
void foo() {
  struct tiny x[3];
  union data y;
  x[0].c = 10;
  fstr(1, x[0]);
  funi(1, y);
}
