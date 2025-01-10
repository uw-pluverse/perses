

int __attribute__((target("sse4.2"))) foo(int i, ...) { return 0; }
int __attribute__((target("arch=sandybridge"))) foo(int i, ...);
int __attribute__((target("arch=ivybridge"))) foo(int i, ...) {return 1;}
int __attribute__((target("default"))) foo(int i, ...) { return 2; }

int bar() {
  return foo(1, 'a', 1.1) + foo(2, 2.2, "asdf");
}
