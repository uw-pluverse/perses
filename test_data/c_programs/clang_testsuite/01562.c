struct s;
struct s* t (struct s z[]) {
  return z;
}
void ff() {
  struct s v, *p;
  p = &v;
}
void *k (void l[2]) {
  return l;
}
struct vari {
  int a;
  int b[];
};
struct vari *func(struct vari a[]) {
  return a;
}
int foo[](void);
int foo2[1](void);
typedef int (*pfunc)(void);
pfunc xx(int f[](void)) {
  return f;
}
void check_size() {
  float f;
  int size_not_int[f];
  int negative_size[1-2];
  int zero_size[0];
}
static int I;
typedef int TA[I];
void strFunc(char *);
const char staticAry[] = "test";
void checkStaticAry() {
  strFunc(staticAry);
}
