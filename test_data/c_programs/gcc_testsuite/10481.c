



const volatile int v = 1;
int i = 0;

void
foo (void)
{
  i = v;
}

int
main (void)
{
  foo ();
  return 0;
}
