typedef void *jmp_buf;
jmp_buf buf;
void do_jump(void) {
  __builtin_longjmp(buf, 1);
}
void f(void);
void do_setjmp(void) {
  if (!__builtin_setjmp(buf))
    f();
}
