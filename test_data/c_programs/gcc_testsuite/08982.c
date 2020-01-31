int x;

int f()
{
  return __atomic_fetch_and (&x, 0, 0);
}

int g()
{
  return __atomic_fetch_or (&x, -1, 0);
}
