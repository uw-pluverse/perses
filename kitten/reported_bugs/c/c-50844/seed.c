




static unsigned _t = 0;

void __attribute__ ((interrupt))
foo (void)
{
  _t++;
}
