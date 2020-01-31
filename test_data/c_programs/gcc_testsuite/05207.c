

extern void foo(int a);
int
main (int argc)
{
  int a;
  a = argc + 1;
  if (argc + 3)
    {
      foo (a);
    }
}
