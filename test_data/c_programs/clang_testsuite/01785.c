int non_diagnosable();
void test_true() {
  if (non_diagnosable()) {
    1 / 0;
  }
}
void test_false() {
  if (non_diagnosable()) {
  } else {
    1 / 0;
  }
}
void test_exclamation_mark() {
  if (!non_diagnosable()) {
    1 / 0;
  }
}
