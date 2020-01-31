


int foo(int a)
{
  int t;
  *(volatile int *)&t = a;
}
