int g_com;
int g_def = 0;
extern int g_ext;
static char g_deferred[] = "hello";
extern void f_ext(void);
static void f_deferred(void) {
}
int f_def(void) {
  f_ext();
  f_deferred();
  return g_com + g_def + g_ext + g_deferred[0];
}
struct Test1 { int field; };
void __attribute__((visibility("default"))) test1(struct Test1 *v) { }
void test2(void);
void __attribute__((visibility("default"))) test2(void) {}
extern void test3(void);
__private_extern__ void test3(void) {}
extern int test4;
__private_extern__ int test4 = 10;
__attribute__((availability(macosx,introduced=10.5,deprecated=10.6)))
__private_extern__ void test5(void) {}
