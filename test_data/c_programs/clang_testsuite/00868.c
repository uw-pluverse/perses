int rhs();
void foo() {
  __block int i;
  i = rhs();
  i += rhs();
}
