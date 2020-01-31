struct S;
void __attribute__((weak)) foo1(struct S);
void (*foo2)(struct S) = foo1;
