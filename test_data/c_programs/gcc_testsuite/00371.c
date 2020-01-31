







long ne0(long a)
{
  return a != 0;
}

long plus_ne0(long a, long b)
{
  return (a != 0) + b;
}

void dummy(void);

void cmp_plus_ne0(long a, long b)
{
  if ((a != 0) + b)
    dummy();
}

long plus_ne0_cmp(long a, long b)
{
  a = (a != 0) + b;
  if (a)
    dummy();
  return a;
}
