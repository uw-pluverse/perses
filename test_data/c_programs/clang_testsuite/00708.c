unsigned char align = 1;
void bar(const char *);
void f0() {
  bar("hello");
}
void f1() {
  static char *x = "hello";
  bar(x);
}
void f2() {
  static char x[] = "hello";
  bar(x);
}
void f3() {
  static char x[8] = "hello";
  bar(x);
}
void gaz(void *);
void f4() {
  static struct s {
    char *name;
  } x = { "hello" };
  gaz(&x);
}
char x[3] = "ola";
