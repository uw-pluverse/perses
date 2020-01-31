static void e0();
void f0() { e0(); }
inline void e1();
void f1() { e1(); }
void e2() __attribute__((weak));
void f2() { e2(); }
