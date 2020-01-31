

__attribute__ ((noinline))
int foo()
{
  return 0;
}

__attribute__ ((noinline))
int bar()
{
  return 1;
}

int main ()
{
  return foo ();
}
