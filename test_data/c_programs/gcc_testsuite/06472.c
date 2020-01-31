



volatile int *p;

void
foo (int x)
{
  *p = 1;
  if (x)
    *p = 2;
}
