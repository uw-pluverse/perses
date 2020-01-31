





extern void bar (double);

void
foo (double *p, double a, int n)
{
  do
    bar (*p++ + a);
  while (n--);
}
