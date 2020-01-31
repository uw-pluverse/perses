int foo(int x) {
  return x == x;
}
int foo2(int x) {
  return (x) != (((x)));
}
void foo3(short s, short t) {
  if (s == s) {}
  if (s == t) {}
}
void foo4(void* v, void* w) {
  if (v == v) {}
  if (v == w) {}
}
int qux(int x) {
   return x < x;
}
int qux2(int x) {
   return x > x;
}
int bar(float x) {
  return x == x;
}
int bar2(float x) {
  return x != x;
}
int macro_comparison() {
  return (42 == 42);
}
int compare_sizeof(int x) {
  return sizeof(x == x);
}
int array_comparisons() {
  int array1[2];
  int array2[2];
  return array1 == array1;
  return array1 != array1;
  return array1 < array1;
  return array1 <= array1;
  return array1 > array1;
  return array1 >= array1;
  return array1 == array2;
  return array1 != array2;
  return array1 < array2;
  return array1 <= array2;
  return array1 > array2;
  return array1 >= array2;
}
int R8435950(int i) {
  if (i == i)
   return 0;
  return 1;
}
