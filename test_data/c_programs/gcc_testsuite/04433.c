



int
f1 (void)
{
  return 1 / (sizeof (char) - 1);
}

int
f2 (void)
{
  const int x = sizeof (char) - 1;
  return 1 / x;
}

int
f3 (void)
{
  return 1 / (sizeof (int) / 3 - 1);
}

int
f4 (void)
{
  const int x = sizeof (int) / 3 - 1;
  return 1 / x;
}
