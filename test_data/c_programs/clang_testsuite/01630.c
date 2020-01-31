unsigned int test_MoveFromCoprocessor(const unsigned int value) {
  return _MoveFromCoprocessor(value, 1, 2, 3, 4);
}
void test_MoveToCoprocessor(const unsigned int value) {
  _MoveToCoprocessor(1, 2, value, 3, 4, 5);
}
