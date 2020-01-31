int test1() {
  typedef int x[test1()];
  static int y = sizeof(x);
}
void f (unsigned int m)
{
  int e[2][m];
  e[0][0] = 0;
}
int x = sizeof(struct{char qq[x];});
void f2(unsigned int m)
{
  extern int e1[2][m];
  e1[0][0] = 0;
}
int i;
int c[][i];
int d[i];
int (*e)[i];
void f3()
{
  static int a[i];
  extern int b[i];
  extern int (*c1)[i];
  static int (*d)[i];
}
static const unsigned array[((2 * (int)((((4) / 2) + 1.0/3.0) * (4) - 1e-8)) + 1)];
int a[*];
int f4(int a[*][*]);
int pr2044(int b) {int (*c(void))[b];**c() = 2;}
int pr2044b;
int (*pr2044c(void))[pr2044b];
const int f5_ci = 1;
void f5() { char a[][f5_ci] = {""}; }
void pr5185(int a[*]);
void pr5185(int a[*])
{
}
void pr23151(int (*p1)[*])
{}
int TransformBug(int a) {
 return sizeof(*(int(*)[({ goto v; v: a;})]) 0);
}
