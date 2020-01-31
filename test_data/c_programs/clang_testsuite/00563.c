int bar(void) {
  return 0;
}
int foo(void) {
  return bar();
}
int main(void) {
  return foo();
}
