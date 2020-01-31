void t1() {
  int array[1] = { 0 };
  char subscript = 0;
  int val = array[subscript];
}
void t2() {
  int array[1] = { 0 };
  char subscript = 0;
  int val = subscript[array];
}
void t3() {
  int *array = 0;
  char subscript = 0;
  int val = array[subscript];
}
void t4() {
  int *array = 0;
  char subscript = 0;
  int val = subscript[array];
}
char returnsChar();
void t5() {
  int *array = 0;
  int val = array[returnsChar()];
}
void t6() {
  int array[1] = { 0 };
  signed char subscript = 0;
  int val = array[subscript];
}
void t7() {
  int array[1] = { 0 };
  unsigned char subscript = 0;
  int val = array[subscript];
}
typedef char CharTy;
void t8() {
  int array[1] = { 0 };
  CharTy subscript = 0;
  int val = array[subscript];
}
typedef signed char SignedCharTy;
void t9() {
  int array[1] = { 0 };
  SignedCharTy subscript = 0;
  int val = array[subscript];
}
typedef unsigned char UnsignedCharTy;
void t10() {
  int array[1] = { 0 };
  UnsignedCharTy subscript = 0;
  int val = array[subscript];
}
