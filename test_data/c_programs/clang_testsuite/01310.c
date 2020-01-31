void f(_Atomic(int) a, _Atomic(int) b) {
  if (a > b) {}
  if (a < b) {}
  if (a >= b) {}
  if (a <= b) {}
  if (a == b) {}
  if (a != b) {}
  if (a == 0) {}
  if (a > 0) {}
  if (a > 1) {}
  if (a > 2) {}
  if (!a > 0) {}
  if (!a > 1) {}
  if (!a > 2) {}
  if (!a > b) {}
  if (!a > -1) {}
}
typedef _Atomic(int) Ty;
void PR23638(Ty *a) {
  if (*a == 1) {}
}
