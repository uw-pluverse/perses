





typedef const char T[1];
typedef const char T2[1];
typedef volatile char U[1];
T *p;
T2 *p2;
U *q;
void *f(void) { return 1 ? p : q; }
T *g(void) { return 1 ? p : p2; }
