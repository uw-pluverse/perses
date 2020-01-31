int baz(int);
int g;
void foo(int n) {
  for (int i = 0; i < n; i++)
    g += baz(i);
}
void bar(int n) {
  for (int i = 0; i < n; i++)
    foo(i);
}
void unroll() {
  for (int i = 0; i < 2; i++)
    baz(i);
}
void icp(void (*p)()) {
  p();
}
