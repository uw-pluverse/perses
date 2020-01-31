extern int a;
extern int b;

extern int foo(void);
extern int bar(void);



const short tests[] = {
  (__builtin_choose_expr(1, __builtin_constant_p(0), 1) ? (0) : -1),
  (__builtin_choose_expr(1, __builtin_constant_p(a), 1) ? (a) : -1),
  (__builtin_choose_expr(1, __builtin_constant_p(0 && a), 1) ? (0 && a) : -1),
  (__builtin_choose_expr(1, __builtin_constant_p(a && b), 1) ? (a && b) : -1),
  (__builtin_choose_expr(1, __builtin_constant_p(foo()), 1) ? (foo()) : -1),
  (__builtin_choose_expr(1, __builtin_constant_p(0 && foo()), 1) ? (0 && foo()) : -1),
  (__builtin_choose_expr(1, __builtin_constant_p(a && foo()), 1) ? (a && foo()) : -1),
  (__builtin_choose_expr(1, __builtin_constant_p(foo() && bar()), 1) ? (foo() && bar()) : -1)
};
