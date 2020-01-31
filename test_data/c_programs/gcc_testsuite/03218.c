

struct A
{
  char c[0];
};

void foo(struct A a)
{
  (a = a).c;
}
