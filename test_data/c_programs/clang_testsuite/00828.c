struct Test1S {
 long NumDecls;
 long X;
 long Y;
};
struct Test2S {
 long NumDecls;
 long X;
};
void test1a(struct Test1S, struct Test2S);
void test1(struct Test1S *A, struct Test2S *B) {
  test1a(*A, *B);
}
struct Test3S {
  int a,b,c,d,e,f,g,h,i,j,k,l;
};
void test2a(struct Test3S q);
void test2(struct Test3S *q) {
  test2a(*q);
}
void fooey(void);
void test3(struct Test3S a) {
  struct Test3S b = a;
  fooey();
  test2a(a);
  test2a(b);
}
