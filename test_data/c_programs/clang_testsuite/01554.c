void g(void);
void foo(int n) {
  (void) _Generic(0,
      struct A: 0,
      void(): 0,
      int[n]: 0);
  (void) _Generic(0,
      void (*)(): 0,
      void (*)(void): 0);
  (void) _Generic((void (*)()) 0,
      void (*)(int): 0,
      void (*)(void): 0);
  (void) _Generic(0,
      char: 0, short: 0, long: 0);
  int a1[_Generic(0, int: 1, short: 2, float: 3, default: 4) == 1 ? 1 : -1];
  int a2[_Generic(0, default: 1, short: 2, float: 3, int: 4) == 4 ? 1 : -1];
  int a3[_Generic(0L, int: 1, short: 2, float: 3, default: 4) == 4 ? 1 : -1];
  int a4[_Generic(0L, default: 1, short: 2, float: 3, int: 4) == 1 ? 1 : -1];
  int a5[_Generic(0, int: 1, short: 2, float: 3) == 1 ? 1 : -1];
  int a6[_Generic(0, short: 1, float: 2, int: 3) == 3 ? 1 : -1];
  int a7[_Generic("test", char *: 1, default: 2) == 1 ? 1 : -1];
  int a8[_Generic(g, void (*)(void): 1, default: 2) == 1 ? 1 : -1];
  const int i = 12;
  int a9[_Generic(i, int: 1, default: 2) == 1 ? 1 : -1];
  (void)_Generic(*(int *)0, int: 1);
}
int __attribute__((overloadable)) test (int);
double __attribute__((overloadable)) test (double);
char testc(char);
void PR30201(void) {
  _Generic(4, char:testc, default:test)(4);
}
