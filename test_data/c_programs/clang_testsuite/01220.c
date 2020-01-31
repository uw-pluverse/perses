extern int i;
int foo2() {
  return 0;
}
int j = 1;
int foo(void) {
  return 0;
}
typedef unsigned int my_uint;
typedef void my_void;
int (*returns_fn_void_int(void))(void);
typedef int (*returns_fn_void_int_t(void))(void);
int (*returns_fn_void_int(void))(void) {
  return 0;
}
void (*(*returns_fn_returns_fn_void_void(void))(void))(void);
typedef void (*(*returns_fn_returns_fn_void_void_t(void))(void))(void);
void (*(*returns_fn_returns_fn_void_void(void))(void))(void) {
  return 0;
}
void bar() {
  int i;
  int *pi = 0;
  void *pv = (void *) pi;
  float f;
  float *fi;
  double d;
  double *pd;
}
void (*f1)(void);
void (*f2)(void) = 0;
void (*f3)(void) = bar;
void (*fa)();
void (*fb)() = 0;
void (*fc)() = bar;
typedef void (function_ptr)(void);
