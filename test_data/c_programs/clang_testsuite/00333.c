void foo() __attribute__((constructor));
void foo() {
  bar();
}
