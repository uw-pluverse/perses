



volatile int x;

int main ()
{
  volatile int *vip;
  vip = &x;
  volatile int *cvip;
  cvip = vip;

  if (vip != cvip) return -1;
  return 0;
}
