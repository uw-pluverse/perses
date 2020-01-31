


int foo0();
void bar0() { foo0(); }
void foobar0() { bar0(); }

void foo1();
void bar1() { foo1(); }
void foobar1() { bar1(); }
int foo3();
int bar3() { return foo3(); }
int foobar3() { return bar3(); }

int bar4() { return 0; }
void foobar4() { bar4(); }

int bar5() { return 0; }
int foobar5() { return bar5(); }
