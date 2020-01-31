struct s {
  int data;
  int data_array[10];
};
typedef struct {
  int data;
} STYPE;
void g(char *p);
void g1(struct s* p);
void f(void) {
  int a[10];
  int (*p)[10];
  p = &a;
  (*p)[3] = 1;
  struct s d;
  struct s *q;
  q = &d;
  q->data = 3;
  d.data_array[9] = 17;
}
void f2() {
  char *p = "/usr/local";
  char (*q)[4];
  q = &"abc";
}
void f3() {
  STYPE s;
}
void f4() {
  int a[] = { 1, 2, 3};
  int b[3] = { 1, 2 };
  struct s c[] = {{1,{1}}};
}
void f5() {
  struct s data;
  g1(&data);
}
void f6() {
  char *p;
  p = __builtin_alloca(10);
  g(p);
  char c = *p;
  p[1] = 'a';
  p += 2;
}
struct s2;
void g2(struct s2 *p);
void f7() {
  struct s2 *p = __builtin_alloca(10);
  g2(p);
}
void f8() {
  int a[10];
  a[sizeof(a)/sizeof(int) - 1] = 1;
}
void f9() {
  struct s a[10];
}
void f10() {
  char a1[4] = "abc";
  char a3[6] = "abc";
}
void f11() {
  struct s a;
  g1(&a);
  if (a.data == 0)
    a.data = 1;
}
void f12(int *list) {
  unsigned i = 0;
  list[i] = 1;
}
struct s1 {
  struct s2 {
    int d;
  } e;
};
void f13(double timeout) {
  struct s1 a;
  a.e.d = (int) timeout;
  if (a.e.d == 10)
    a.e.d = 4;
}
struct s3 {
  int a[2];
};
static struct s3 opt;
void f14() {
  struct s3 my_opt = opt;
}
void bar(int*);
struct s3 gets3() {
  struct s3 s;
  return s;
}
void accessArrayFieldNoCrash() {
  bar(gets3().a);
  bar((gets3().a));
  bar(((gets3().a)));
}
void f15() {
  int a[10];
  bar(a);
  if (a[1])
    (void)1;
}
struct s3 p[1];
void f16(struct s3 *p) {
  struct s3 a = *((struct s3*) ((char*) &p[0]));
}
void inv(struct s1 *);
void f17() {
  struct s1 t;
  int x;
  inv(&t);
  if (t.e.d)
    x = 1;
}
void read(char*);
void f18() {
  char *q;
  char *p = (char *) __builtin_alloca(10);
  read(p);
  q = p;
  q++;
  if (*q) {
  }
}
int offset_of_data_array(void)
{
  return ((char *)&(((struct s*)0)->data_array)) - ((char *)0);
}
int testPointerArithmeticOnVoid(void *bytes) {
  int p = 0;
  if (&bytes[0] == &bytes[1])
    return 6/p;
  return 0;
}
int testRValueArraySubscriptExpr(void *bytes) {
  int *p = (int*)&bytes[0];
  *p = 0;
  if (*(int*)&bytes[0] == 0)
    return 0;
  return 5/(*p);
}
