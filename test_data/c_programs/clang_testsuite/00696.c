int f0(void);
int f0(void) { return 0; }
inline int f1(void);
int f1(void) { return 0; }
int f2(void);
inline int f2(void) { return 0; }
extern inline int f3(void);
int f3(void) { return 0; }
extern inline int f5(void);
inline int f5(void) { return 0; }
inline int f6(void);
extern inline int f6(void) { return 0; }
extern inline int f7(void);
extern int f7(void) { return 0; }
inline int fA(void) { return 0; }
inline int fB() { return 0; }
int f4(void);
extern inline int f4(void) { return 0; }
extern int f8(void);
extern inline int f8(void) { return 0; }
extern inline int f9(void);
extern inline int f9(void) { return 0; }
int test_all() {
  return f0() + f1() + f2() + f3() + f4() + f5() + f6() + f7() + f8() + f9()
    + fA() + fB();
}
int fB(void);
