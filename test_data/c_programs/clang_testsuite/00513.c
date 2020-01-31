inline int inline_hint(int a, int b) { return(a+b); }
int inline_no_hint(int a, int b) { return (a/b); }
inline __attribute__ ((__always_inline__)) int inline_always(int a, int b) { return(a*b); }
volatile int *pa = (int*) 0x1000;
void foo() {
    pa[0] = inline_hint(pa[1],pa[2]);
    pa[3] = inline_always(pa[4],pa[5]);
    pa[6] = inline_no_hint(pa[7], pa[8]);
}
