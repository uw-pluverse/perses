struct A
{
  int a;
};

int foo (struct A *a)
{
  static int c = 30;
  int x;

  a->a = c;




  x = a->a;
  return x;
}
