int sfa (char *p, char *q, int a)
{
  return __atomic_fetch_nand (p, a, 4)
    + __atomic_fetch_add (q, a, 5);
}



void acen (char *ptr, char *val, char *ret)
{
  __atomic_exchange (ptr, val, ret, 5);
}
