






extern void bar (int);
extern void test (void) __attribute__((__interrupt__));

int foo;
void test()
{
  bar (foo);
  foo = 0;
}
