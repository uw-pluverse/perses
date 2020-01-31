


void link_error (void);

struct A
{
  int a;
  int b;
};

struct A a;
const int B = 42;

void foo (int i)
{
  if (i > 10)
    a.a = 42;
  else
    {
      a.b = 21;
      a.a = a.b + 21;
    }


  if (a.a != B)
    link_error ();
}

int
main ()
{
  foo (3);
  return 0;
}
