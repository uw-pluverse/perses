int fn1() {
  return 1;
}
int fn2(int x) {
  return x + 1;
}
int main() {
  int a = fn1();
  a = fn2(a);
  printf("%d", a);
  return 0;
}
