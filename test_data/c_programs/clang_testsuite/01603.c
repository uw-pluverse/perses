void cat0(int a[static 0]) {}
void cat(int a[static 3]) {}
void vat(int i, int a[static i]) {}
void f(int *p) {
  int a[2], b[3], c[4];
  cat0(0);
  cat(0);
  cat(a);
  cat(b);
  cat(c);
  cat(p);
  vat(1, 0);
  vat(3, b);
}
typedef int td[static 3];
typedef void(*fp)(int[static 42]);
void g(void) {
  int a[static 42];
  int b[const 10];
  int c[volatile 10];
  int d[restrict 10];
  int e[static restrict 1];
}
void h(int [static const 10][42]);
void i(int [10]
       [static 42]);
void j(int [10]
       [const 42]);
void k(int (*x)[static 10]);
void l(int (x)[static 10]);
void m(int *x[static 10]);
void n(int *(x)[static 10]);
void o(int (x[static 10])(void));
void p(int (^x)[static 10]);
void q(int (^x[static 10])());
void r(x)
  int x[restrict];
{}
