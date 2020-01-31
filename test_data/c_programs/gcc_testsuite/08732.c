


struct A
{
  int a, b, c;
};

struct B
{
  int x, y;
};

__attribute__ ((noinline))
int foo(struct A *a)
{
  a->c = 1;

  return 123;
}

__attribute__ ((noinline))
int bar(struct B *b)
{
  b->y = 1;

  return 123;
}

int main()
{
  return foo(0) + bar(0);
}
