







static void f0(void);
void g0(void) { f0(); }


static void f1(void);
void g1(void) { if (0) { f1(); } }


static int f2(void);
void g2(void) { 0 ? f2() : 0; }


static int f3(void);
void g3(void) { sizeof(f3()); }
