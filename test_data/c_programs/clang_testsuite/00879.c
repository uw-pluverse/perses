void foo(int x)
{
  _Atomic(int) i = 0;
  _Atomic(short) j = 0;
  i *= 2;
  i /= 2;
  j /= x;
}
extern _Atomic _Bool b;
_Bool bar() {
  return b;
}
extern _Atomic(_Complex int) x;
void baz(int y) {
  x += y;
}
