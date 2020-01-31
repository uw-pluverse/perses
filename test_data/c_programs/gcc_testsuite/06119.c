


int glob1, glob2;

int foo1 (void)
{
  glob1 = 0;
  glob2 = 1;
  glob1 = 2;
  glob2 = 3;
  return glob1 + glob2;
}
