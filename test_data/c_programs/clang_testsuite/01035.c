void f0() {
  printf("a\n");
}
void f1() {
  exit(1);
}
char* f2(char* a, char* b) {
  return __builtin_strstr(a, b);
}
int f3(double x) {
  int e;
  __builtin_frexp(x, &e);
  __builtin_frexpf(x, &e);
  __builtin_frexpl(x, &e);
  __builtin_modf(x, &e);
  __builtin_modff(x, &e);
  __builtin_modfl(x, &e);
  __builtin_remquo(x, x, &e);
  __builtin_remquof(x, x, &e);
  __builtin_remquol(x, x, &e);
  return e;
}
