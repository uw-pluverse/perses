





extern void bar (float);

void
foo (float *p, float a, int n)
{
  do
    bar (*p++ + a);
  while (n--);
}
