

extern int foo (int *, int *);
extern int foo2 (int);
int
main (int argc)
{
  int a, b, c;
  b = argc + 1;
  c = argc + 2;
  a = b + c;
  if (argc)
    {
      foo (&b, &c);
      a = b + c;
    }
  foo2 (a);
}
