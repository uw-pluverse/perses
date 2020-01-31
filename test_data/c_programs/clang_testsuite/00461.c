_Static_assert(sizeof(long long) == 8, "sizeof long long is wrong");
_Static_assert(_Alignof(long long) == 4, "alignof long long is wrong");
_Static_assert(sizeof(double) == 8, "sizeof double is wrong");
_Static_assert(_Alignof(double) == 4, "alignof double is wrong");
extern const int cgx;
int fcgx() { return cgx;}
int g1;
const int cg1;
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
struct x { int a[5]; };
void f(void*);
void testva (int n, ...) {
  va_list ap;
  __builtin_va_start(ap,n);
  char* v1 = __builtin_va_arg(ap,char*);
  f(v1);
  char v2 = __builtin_va_arg(ap,char);
  f(&v2);
  int v3 = __builtin_va_arg(ap,int);
  f(&v3);
  long long int v4 = __builtin_va_arg(ap,long long int);
  f(&v4);
  struct x v5 = __builtin_va_arg(ap,struct x);
  f(&v5);
  int* v6 = __builtin_va_arg(ap,int[4]);
  f(v6);
  double v7 = __builtin_va_arg(ap,double);
  f(&v7);
}
void testbuiltin (void) {
  volatile int i = __builtin_getid();
  volatile unsigned int ui = __builtin_getps(i);
  ui = __builtin_bitrev(ui);
  __builtin_setps(i,ui);
  volatile int res;
  res = __builtin_eh_return_data_regno(0);
  res = __builtin_eh_return_data_regno(1);
  res = __builtin_eh_return_data_regno(2);
}
char testchar (void) {
  return (char)-1;
}
