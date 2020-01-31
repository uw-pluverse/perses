void foo1(void*);
void foo2(void* const);
void bar() {
  foo1(0);
  foo2(0);
}
