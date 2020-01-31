


typedef int v4si __attribute__ ((vector_size (16)));

__attribute__ ((noinline))
int foo(void)
{
  v4si a = {1,2,3,4};
  v4si b = {3,2,1,4};
  v4si c;

  return 54;
}

__attribute__ ((noinline))
int bar(void)
{
  v4si a = {1,2,3,4};
  v4si b = {3,2,5,4};
  v4si c;

  return 54;
}

int main()
{
  foo();
  bar();

  return 0;
}
