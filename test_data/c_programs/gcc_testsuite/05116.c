


int
foo ()
{
  volatile int *p;
  volatile int x;

  p = &x;
  *p = 3;
  return *p + 1;
}
