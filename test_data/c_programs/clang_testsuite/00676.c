int foo() {
  return 0;
}
__attribute__((no_split_stack))
int nosplit() {
  return 0;
}
int main() {
  return foo();
}
