void f0() {
  int x, y;
  x = 1;
  y = (x = 1);
}
void f1() {
  volatile int x, y;
  x = 1;
  y = (x = 1);
}
