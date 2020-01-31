

volatile int t;
static inline int cvmx_atomic_get32(volatile int *ptr)
{
    return *ptr;
}
void f(void)
{
  while (!cvmx_atomic_get32(&t))
    ;
}
