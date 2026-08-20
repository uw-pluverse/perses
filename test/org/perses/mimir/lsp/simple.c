int ga = 1;
int f1() {
  float a = 0;
  int b = (int)a + 1;
  return (int)a + b;
}
int f2() {
  int a2 = 0;
  int b2 = a2 + 2;
  return a2 + b2 + f1() + ga;
}
int f3() {
  int a = 0;
  int b3 = 0;
return f1() + f2() + a + b3;
}