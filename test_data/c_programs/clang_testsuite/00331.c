struct S { int A[1000]; };
int __attribute__ ((const)) f(struct S x) { x.A[1] = 0; return x.A[0]; }
int g(struct S x) __attribute__ ((pure));
int h(struct S x) { return g(x); }
