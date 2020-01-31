int getInt();
int test1(int i1, int i2) {
  int ret;
  ret = !i1 == i2;
  ret = !i1 != i2;
  ret = !i1 < i2;
  ret = !i1 > i2;
  ret = !i1 <= i2;
  ret = !i1 >= i2;
  ret = i1 == i2;
  ret = i1 != i2;
  ret = i1 < i2;
  ret = i1 > i2;
  ret = i1 <= i2;
  ret = i1 >= i2;
  ret = (!i1) == i2;
  ret = (!i1) != i2;
  ret = (!i1) < i2;
  ret = (!i1) > i2;
  ret = (!i1) <= i2;
  ret = (!i1) >= i2;
  ret = !getInt() == i1;
  ret = (!getInt()) == i1;
  return ret;
}
enum E {e1, e2};
enum E getE();
int test2 (enum E e) {
  int ret;
  ret = e == e1;
  ret = e == getE();
  ret = getE() == e1;
  ret = getE() == getE();
  ret = !e == e1;
  ret = !e == getE();
  ret = !getE() == e1;
  ret = !getE() == getE();
  ret = !(e == e1);
  ret = !(e == getE());
  ret = !(getE() == e1);
  ret = !(getE() == getE());
  ret = (!e) == e1;
  ret = (!e) == getE();
  ret = (!getE()) == e1;
  ret = (!getE()) == getE();
  return ret;
}
int PR16673(int x) {
  int ret;
  ret = !x == 1 && 1;
  return ret;
}
int compare_pointers(int* a, int* b) {
  int ret;
  ret = !!a == !!b;
  ret = !!a != !!b;
  return ret;
}
