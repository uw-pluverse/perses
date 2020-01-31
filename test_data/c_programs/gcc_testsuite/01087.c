






int x;

static __attribute__ ((noinline)) void f ()
{
  x = 5;
}

extern void g ();

static __attribute__ ((noinline)) __attribute__((section(".init.text"))) void h ()
{
  x = 5;
}

int bar ()
{
  f ();
  g ();
  h ();
}
