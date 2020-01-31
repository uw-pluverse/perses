struct test {
   signed char a;
};
char c;
struct test s;
extern char ec;
extern struct test es;
void func (void)
{
  c = ec;
  s = es;
}
struct arg { long y __attribute__((packed, aligned(4))); };
extern struct arg x;
void f(struct arg);
void test (void)
{
  f(x);
}
