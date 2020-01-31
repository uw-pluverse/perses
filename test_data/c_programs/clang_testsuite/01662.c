typedef struct {
 char *str;
} Class;
typedef union {
 Class *object;
} Instance __attribute__((transparent_union));
__attribute__((nonnull(1))) void Class_init(Instance this, char *str) {
 this.object->str = str;
}
int main(void) {
 Class *obj;
 Class_init(0, "Hello World");
 Class_init(obj, "Hello World");
}
void foo(const char *str) __attribute__((nonnull("foo")));
void bar(int i) __attribute__((nonnull(1)));
void baz(__attribute__((nonnull)) const char *str);
void baz2(__attribute__((nonnull(1))) const char *str);
void baz3(__attribute__((nonnull)) int x);
void test_baz() {
  baz(0);
  baz2(0);
  baz3(0);
}
void test_void_returns_nonnull(void) __attribute__((returns_nonnull));
int test_int_returns_nonnull(void) __attribute__((returns_nonnull));
void *test_ptr_returns_nonnull(void) __attribute__((returns_nonnull));
int i __attribute__((nonnull));
int j __attribute__((returns_nonnull));
void *test_no_fn_proto() __attribute__((returns_nonnull));
void *test_with_fn_proto(void) __attribute__((returns_nonnull));
__attribute__((returns_nonnull))
void *test_bad_returns_null(void) {
  return 0;
}
void PR18795(int (*g)(const char *h, ...) __attribute__((nonnull(1))) __attribute__((nonnull))) {
  g(0);
}
void PR18795_helper() {
  PR18795(0);
}
void vararg1(int n, ...) __attribute__((nonnull(2)));
void vararg1_test() {
  vararg1(0);
  vararg1(1, (void*)0);
  vararg1(2, (void*)0, (void*)0);
  vararg1(2, (void*)&vararg1, (void*)0);
}
void vararg2(int n, ...) __attribute__((nonnull, nonnull, nonnull));
void vararg2_test() {
  vararg2(0);
  vararg2(1, (void*)0);
  vararg2(2, (void*)0, (void*)0);
}
void vararg3(int n, ...) __attribute__((nonnull, nonnull(2), nonnull(3)));
void vararg3_test() {
  vararg3(0);
  vararg3(1, (void*)0);
  vararg3(2, (void*)0, (void*)0);
}
void redecl(void *, void *);
void redecl(void *, void *) __attribute__((nonnull(1)));
void redecl(void *, void *) __attribute__((nonnull(2)));
void redecl(void *, void *);
void redecl_test(void *p) {
  redecl(p, 0);
  redecl(0, p);
}
__attribute__((__nonnull__))
int evil_nonnull_func(int* pointer, void * pv)
{
   if (pointer == (void*)0) {
     return 0;
   } else {
     return *pointer;
   }
   pointer = pv;
   if (!pointer)
     return 0;
   else
     return *pointer;
   if (pv == (void*)0) {}
}
void set_param_to_null(int**);
int another_evil_nonnull_func(int* pointer, char ch, void * pv) __attribute__((nonnull(1, 3)));
int another_evil_nonnull_func(int* pointer, char ch, void * pv) {
   if (pointer == (void*)0) {
     return 0;
   } else {
     return *pointer;
   }
   set_param_to_null(&pointer);
   if (!pointer)
     return 0;
   else
     return *pointer;
   if (pv == (void*)0) {}
}
extern void *returns_null(void**);
extern void FOO();
extern void FEE();
extern void *pv;
__attribute__((__nonnull__))
void yet_another_evil_nonnull_func(int* pointer)
{
 while (pv) {
   if (pointer) {
     FOO();
   } else {
     FEE();
   }
   pointer = returns_null(&pv);
 }
}
void pr21668_1(__attribute__((nonnull)) const char *p, const char *s) {
  if (p)
    ;
  if (s)
    ;
}
void pr21668_2(__attribute__((nonnull)) const char *p) {
  p = 0;
  if (p)
    ;
}
__attribute__((returns_nonnull)) void *returns_nonnull_whee();
void returns_nonnull_warning_tests() {
  if (returns_nonnull_whee() == (void*)0) {}
  if (returns_nonnull_whee() != (void*)0) {}
  if (returns_nonnull_whee()) {}
  if (!returns_nonnull_whee()) {}
  int and_again = !returns_nonnull_whee();
  and_again = !returns_nonnull_whee();
}
void pr30828(char *p __attribute__((nonnull)));
void pr30828(char *p) {}
void call_pr30828() {
  pr30828(0);
}
