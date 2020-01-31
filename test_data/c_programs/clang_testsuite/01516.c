int f1(float x, float y) {
  return x == y;
}
int f2(float x, float y) {
  return x != y;
}
int f3(float x) {
  return x == x;
}
int f4(float x) {
  return x == 0.0;
}
int f5(float x) {
  return x == __builtin_inf();
}
int f7(float x) {
  return x == 3.14159;
}
