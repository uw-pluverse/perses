






int a;

int f1(int p)
{
  return __atomic_sub_fetch(&a, p, 5) == 0;
}

int f2(int p)
{
  return __atomic_fetch_sub(&a, p, 5) - p == 0;
}
