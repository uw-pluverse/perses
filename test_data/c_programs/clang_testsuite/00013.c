int a;
void f1() {
  if (1 && a)
    return;
}
void f2() {
  f1();
}
