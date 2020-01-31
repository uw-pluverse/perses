int foo1(int);
int foo2(int a) {
  return foo1(a + 2);
}
__attribute__((optnone))
int foo1(int a) {
    return a + 1;
}
