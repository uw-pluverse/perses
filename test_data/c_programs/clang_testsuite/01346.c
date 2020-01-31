void a(void *p __attribute__((pass_object_size)));
void b(void *p __attribute__((pass_object_size(1.0))));
void c(void *p __attribute__((pass_object_size(4))));
void d(void *p __attribute__((pass_object_size(-1))));
void e(void *p __attribute__((pass_object_size(1ULL<<32))));
void f(char p __attribute__((pass_object_size(0))));
void g(const char p __attribute__((pass_object_size(0))));
void h(char *p __attribute__((pass_object_size(0)))) {}
void i(char *p __attribute__((pass_object_size(0))));
void j(char *p __attribute__((pass_object_size(0), pass_object_size(1))));
void Overloaded(void *p __attribute__((pass_object_size(0)))) __attribute__((overloadable));
void Overloaded(void *p __attribute__((pass_object_size(1)))) __attribute__((overloadable));
void Overloaded2(void *p __attribute__((pass_object_size(1))), void *p2 __attribute__((pass_object_size(0)))) __attribute__((overloadable));
void Overloaded2(void *p __attribute__((pass_object_size(0))), void *p2 __attribute__((pass_object_size(1)))) __attribute__((overloadable));
void Overloaded3(void *p __attribute__((pass_object_size(0))), void *p2) __attribute__((overloadable));
void Overloaded3(void *p, void *p2 __attribute__((pass_object_size(0)))) __attribute__((overloadable));
void TakeFn(void (*)(void *));
void TakeFnOvl(void (*)(void *)) __attribute__((overloadable));
void TakeFnOvl(void (*)(int *)) __attribute__((overloadable));
void NotOverloaded(void *p __attribute__((pass_object_size(0))));
void IsOverloaded(void *p __attribute__((pass_object_size(0)))) __attribute__((overloadable));
void IsOverloaded(char *p) __attribute__((overloadable));
void FunctionPtrs() {
  void (*p)(void *) = NotOverloaded;
  void (*p2)(void *) = &NotOverloaded;
  void (*p3)(void *) = IsOverloaded;
  void (*p4)(void *) = &IsOverloaded;
  void (*p5)(char *) = IsOverloaded;
  void (*p6)(char *) = &IsOverloaded;
  TakeFn(NotOverloaded);
  TakeFn(&NotOverloaded);
  TakeFnOvl(NotOverloaded);
  TakeFnOvl(&NotOverloaded);
  int P;
  (&NotOverloaded)(&P);
  (&IsOverloaded)(&P);
}
