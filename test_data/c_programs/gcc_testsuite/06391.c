



int foo (int) __attribute__ ((const));
const int i;

void
test (void)
{
  __typeof__ (1 ? foo (0) : 0) texpr;
  __typeof__ (1 ? i : 0) texpr2;
  texpr = 0;
  texpr2 = 0;
}
