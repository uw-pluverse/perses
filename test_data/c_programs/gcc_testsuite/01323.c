



extern int foo ();
extern int bar ();

void f(unsigned a, unsigned b, unsigned c, unsigned d)
{
  if (a <= b || c > d)
    foo();
  else
    bar();
}
