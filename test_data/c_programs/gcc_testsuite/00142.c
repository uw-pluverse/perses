int *p;

void __attribute__((interrupt))
isr (int signum)
{
  *p = 1;
  return;
}
