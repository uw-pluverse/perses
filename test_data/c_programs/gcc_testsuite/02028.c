






void abort (void);
void link_failure (void);

volatile int v;

void
foo (int var)
{
  if (!(var <= 0
        || ((long unsigned) (unsigned) (var - 1) < (2147483647 *2U +1U))))
    link_failure ();
}

int
main (int argc, char **argv)
{
  foo (v);
  return 0;
}


void
link_failure (void)
{
  abort ();
}
