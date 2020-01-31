signed char f0(int x) { return x; }
unsigned char f1(int x) { return x; }
void f2(signed char x) { }
void f3(unsigned char x) { }
signed short f4(int x) { return x; }
unsigned short f5(int x) { return x; }
void f6(signed short x) { }
void f7(unsigned short x) { }
void __attribute__((always_inline)) f8(void) { }
void __attribute__((noreturn)) f9_t(void);
void f9(void) { f9_t(); }
_Noreturn void f9a(void);
void f9b(void) { f9a(); }
int __attribute__((const)) f10_t(void);
int f10(void) { return f10_t(); }
int f11(void) {
 exit:
  return f10_t();
}
int f12(int arg) {
  return arg ? 0 : f10_t();
}
void f13(void) __attribute__((pure)) __attribute__((const));
void f13(void){}
void f15(void) {
}
void __attribute__((force_align_arg_pointer)) f16(void) {
}
__attribute__ ((returns_twice)) void f17(void);
__attribute__ ((returns_twice)) void f18(void) {
        f17();
}
typedef int jmp_buf[((9 * 2) + 3 + 16)];
int setjmp(jmp_buf);
void f19(void) {
  setjmp(0);
}
int _setjmp(jmp_buf);
void f20(void) {
  _setjmp(0);
}
