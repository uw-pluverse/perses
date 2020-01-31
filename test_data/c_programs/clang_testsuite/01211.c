__thread int t1;
__thread extern int t2;
__thread static int t3;
__thread __private_extern__ int t4;
struct t5 { __thread int x; };
__thread int t6();
int f(__thread int t7) {
  __thread int t8;
  extern __thread int t9;
  static __thread int t10;
  __thread __private_extern__ int t11;
  __thread auto int t12a;
  auto __thread int t12b;
  __thread register int t13a;
  register __thread int t13b;
}
__thread typedef int t14;
__thread int t15;
extern int t15;
extern int t16;
__thread int t16;
__thread int thread_int;
int *thread_int_ptr = &thread_int;
void g() {
  int *p = &thread_int;
}
int non_const();
__thread int non_const_init = non_const();
__thread int aggregate[10] = {0};
