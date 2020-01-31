




extern void f () __attribute__ ((weak));
extern void g () __attribute__ ((weak)) __attribute__ ((noinline));

void g ()
{
}

int main ()
{
  f ();
  g ();
}
