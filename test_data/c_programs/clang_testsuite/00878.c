void check__dmb(void) {
  __dmb(0);
}
void check__dsb(void) {
  __dsb(0);
}
void check__isb(void) {
  __isb(0);
}
long int check__ldrexd(void) {
  long int i64;
  return __ldrexd(&i64);
}
unsigned int check_MoveFromCoprocessor(void) {
  return _MoveFromCoprocessor(0, 0, 0, 0, 0);
}
unsigned int check_MoveFromCoprocessor2(void) {
  return _MoveFromCoprocessor2(0, 0, 0, 0, 0);
}
void check_MoveToCoprocessor(unsigned int value) {
  _MoveToCoprocessor(value, 10, 7, 1, 0, 0);
}
void check_MoveToCoprocessor2(unsigned int value) {
  _MoveToCoprocessor2(value, 10, 7, 1, 0, 0);
}
