


int i;
int foo(void)
{
  volatile int *p = (volatile int *)&i;
  return *p + *p;
}
