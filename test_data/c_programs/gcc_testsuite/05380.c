

static int a;
int f;
void bar (void) __attribute__((noinline));
void bar (void)
{
  f = 9;
}

void link_error ();

int foo()
{
  int b, c;
  a = 5;
  b = a;
  bar ();
  b = b + a;
  if (b != 10)
    link_error ();
  return b;
}
