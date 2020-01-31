void foo(int m) __attribute__((overloadable, enable_if(m > 0, "")));
void foo(int m) __attribute__((overloadable));
void test1() {
  void (*p)(int) = foo;
  void (*p2)(int) = &foo;
  p = foo;
  p = &foo;
  void *vp1 = (void*)&foo;
  void *vp2 = (void*)foo;
  vp1 = (void*)&foo;
  vp1 = (void*)foo;
}
void bar(int m) __attribute__((overloadable, enable_if(m > 0, "")));
void bar(int m) __attribute__((overloadable, enable_if(1, "")));
void test2() {
  void (*p)(int) = bar;
  void (*p2)(int) = &bar;
  p = bar;
  p = &bar;
  void *vp1 = (void*)&bar;
  void *vp2 = (void*)bar;
  vp1 = (void*)&bar;
  vp1 = (void*)bar;
}
void baz(int m) __attribute__((overloadable, enable_if(1, "")));
void baz(int m) __attribute__((overloadable));
void test3() {
  void (*p)(int) = baz;
  void (*p2)(int) = &baz;
  p = baz;
  p = &baz;
}
const int TRUEFACTS = 1;
void qux(int m) __attribute__((overloadable, enable_if(1, ""),
                               enable_if(TRUEFACTS, "")));
void qux(int m) __attribute__((overloadable, enable_if(1, "")));
void test4() {
  void (*p)(int) = qux;
  void (*p2)(int) = &qux;
  p = qux;
  p = &qux;
}
void test5() {
  int foo(char *i) __attribute__((enable_if(1, ""), overloadable));
  int foo(char *i __attribute__((pass_object_size(0))))
      __attribute__((enable_if(1, ""), overloadable));
  foo((void*)0);
}
