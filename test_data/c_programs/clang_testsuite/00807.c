void v(const char *f, ...);
void kr();
void f(const char *f) {
  v(f, 1, 2, 3, 0);
  kr(f, 1, 2, 3, 0);
}
