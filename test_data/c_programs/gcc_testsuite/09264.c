



int
foo ()
{
  long unsigned int s = __builtin_expect ((long unsigned int)&&L, 0);
L:
  return 0;
}
