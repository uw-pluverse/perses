typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
void f_void(void) {}
int f_int_1(int x) { return x; }
unsigned f_int_2(unsigned x) { return x; }
long long f_int_3(long long x) { return x; }
char f_int_4(char x) { return x; }
long double f_ld(long double x) { return x; }
struct small {
  int *a, *b;
};
struct small f_small(struct small x) {
  x.a += *x.b;
  x.b = 0;
  return x;
}
struct medium {
  int *a, *b;
  int *c, *d;
};
struct medium f_medium(struct medium x) {
  x.a += *x.b;
  x.b = 0;
  return x;
}
struct large {
  int *a, *b;
  int *c, *d;
  int x;
};
struct large f_large(struct large x) {
  x.a += *x.b;
  x.b = 0;
  return x;
}
struct reg {
  int a, b;
};
struct reg f_reg(struct reg x) {
  x.a += x.b;
  return x;
}
struct mixed {
  int a;
  float b;
};
struct mixed f_mixed(struct mixed x) {
  x.a += 1;
  return x;
}
struct mixed2 {
  int a;
  double b;
};
struct mixed2 f_mixed2(struct mixed2 x) {
  x.a += 1;
  return x;
}
struct tiny {
  char a;
};
struct tiny f_tiny(struct tiny x) {
  x.a += 1;
  return x;
}
void call_tiny() {
  struct tiny x = { 1 };
  f_tiny(x);
}
int f_variable(char *f, ...) {
  int s = 0;
  char c;
  va_list ap;
  __builtin_va_start(ap,f);
  while ((c = *f++)) switch (c) {
  case 'i':
    s += __builtin_va_arg(ap,int);
    break;
  case 'l':
    s += __builtin_va_arg(ap,long);
    break;
  case 't':
    s += __builtin_va_arg(ap,struct tiny).a;
    break;
  case 's':
    s += *__builtin_va_arg(ap,struct small).a;
    break;
  case 'm':
    s += *__builtin_va_arg(ap,struct medium).a;
    break;
  }
  return s;
}
