static const int i = 1;
void g(const int *, int);
void f() {
  g(&i, i);
}
