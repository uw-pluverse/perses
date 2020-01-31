


struct A { int x; double y; };
void f (struct A *a) {
  *a = *a;
}
