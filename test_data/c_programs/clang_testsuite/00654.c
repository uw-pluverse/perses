typedef char jmp_buf[1];
jmp_buf jb;
int test_setjmp() {
  return _setjmp(jb);
}
int test_setjmpex() {
  return _setjmpex(jb);
}
