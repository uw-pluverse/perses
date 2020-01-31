

int t;
static inline int cvmx_atomic_get32(int *ptr)
{
    return *(volatile int*)ptr;
}
void f(void)
{
  while (!cvmx_atomic_get32(&t))
    ;
}
