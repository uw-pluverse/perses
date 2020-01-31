__attribute__((always_inline))
int test2() { return 0; }
__attribute__((optnone))
int test3() { return 0; }
__attribute__((optnone)) __attribute__((cold))
int test4() { return test2(); }
