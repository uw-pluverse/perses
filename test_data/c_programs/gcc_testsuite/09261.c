


typedef unsigned long long ptrcast;
volatile unsigned long *
sat_add(volatile unsigned long *ptr, unsigned long i, volatile unsigned long *end)
{
  if ((ptrcast)ptr + i * sizeof(*ptr) > (ptrcast)ptr)
    return ptr + i;
  else
    return end;
}
