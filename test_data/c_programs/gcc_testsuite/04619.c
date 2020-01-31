



short x;

int
main (void)
{
  short *p = 0, *u = &x;
  *(u + *p) = 23;
  return 0;
}
