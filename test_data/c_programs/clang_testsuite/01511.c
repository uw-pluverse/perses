extern int glob;
int foo(int arg) {
  int a = arg * 2;
  return a + glob;
}
int bar(int arg) {
  int a = foo(arg) * foo(arg * 2);
  return glob - foo(a);
}
