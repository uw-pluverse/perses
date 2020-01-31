






extern int a;
extern int b;

extern int foo(void);
extern int bar(void);



const short tests[] = {
  (__builtin_constant_p(0) ? (0) : -1),
  (__builtin_constant_p(a) ? (a) : -1),
  (__builtin_constant_p(0 && a) ? (0 && a) : -1),
  (__builtin_constant_p(a && b) ? (a && b) : -1),
  (__builtin_constant_p(foo()) ? (foo()) : -1),
  (__builtin_constant_p(0 && foo()) ? (0 && foo()) : -1),
  (__builtin_constant_p(a && foo()) ? (a && foo()) : -1),
  (__builtin_constant_p(foo() && bar()) ? (foo() && bar()) : -1)
};
