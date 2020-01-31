


volatile int *q;
void foo(int i)
{
  volatile int a[2];
  volatile int *p = &a[i];
  q = p;
}
