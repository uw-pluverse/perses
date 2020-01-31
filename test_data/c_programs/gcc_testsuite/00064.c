


static __attribute__((always_inline)) int f1 (int *p)
{
  return *p;
}

__attribute__((bnd_legacy)) int f2 (int *p)
{
  return f1 (p);
}
