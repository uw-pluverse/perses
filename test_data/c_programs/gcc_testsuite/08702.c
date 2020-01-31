


struct A
{
  int a;
  int b;
};

__attribute__ ((noinline))
int foo(struct A *a)
{
  return 123;
}

__attribute__ ((noinline))
int bar(struct A *b)
{
  return 123;
}

int main()
{
  return foo(0) + bar(0);
}
