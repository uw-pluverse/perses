void f(int x) {
  char foo[10];
  int bar[20];
  char qux[30];
  (void)sizeof(bar + 10);
  (void)sizeof(foo - 20);
  (void)sizeof(bar - x);
  (void)sizeof(foo + x);
  (void)sizeof(foo - qux);
  (void)sizeof(foo, x);
  (void)sizeof(x, foo);
}
