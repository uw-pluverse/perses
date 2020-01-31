struct t1 {
  char t1[10];
};
struct t2 {
  char t2[20];
};
struct t3 {
  char t3[65];
};
extern struct t1 g1;
extern struct t2 g2;
extern struct t3 g3;
extern void f1(struct t1);
extern void f2(struct t2);
extern void f3(struct t3);
void f() {
  f1(g1);
  f2(g2);
  f3(g3);
}
