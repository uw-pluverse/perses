


void f(unsigned long x);

void g(long x)
{
  f((unsigned long)(-1-x)+1);
}
