const int x __attribute((weak)) = 123;
int* f(void) {
  return &x;
}
int g(void) {
  return *f();
}
