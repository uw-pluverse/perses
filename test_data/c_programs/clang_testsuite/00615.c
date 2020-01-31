struct X { int *XX; int Y;};
void foo() {
  static int nate = 0;
  struct X bob = { &nate, 14 };
  bar(&bob);
}
