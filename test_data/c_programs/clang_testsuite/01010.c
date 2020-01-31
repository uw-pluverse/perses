typedef struct {
  short x;
} foostruct;
int foo(foostruct ic);
void test() {
  foostruct xqic;
  foo(xqic);
}
