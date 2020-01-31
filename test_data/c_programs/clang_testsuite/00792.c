inline int dont_inline_me(int a, int b) { return(a+b); }
inline __attribute__ ((__always_inline__)) int inline_me(int a, int b) { return(a*b); }
volatile int *pa = (int*) 0x1000;
void foo() {
    pa[0] = dont_inline_me(pa[1],pa[2]);
    pa[3] = inline_me(pa[4],pa[5]);
}
