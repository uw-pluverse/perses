typedef int __attribute__((may_alias)) aliasing_int;
void test0(aliasing_int *ai, int *i)
{
  *ai = 0;
  *i = 1;
}
struct Test1 { int x; };
struct Test1MA { int x; } __attribute__((may_alias));
void test1(struct Test1MA *p1, struct Test1 *p2) {
  p1->x = 2;
  p2->x = 3;
}
