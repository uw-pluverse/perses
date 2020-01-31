





struct S { int x[10]; };
extern __thread struct S s;
int *foo() { return &s.x[2]; }
