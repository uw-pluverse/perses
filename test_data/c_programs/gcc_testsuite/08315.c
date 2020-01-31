



unsigned
f1 (unsigned x)
{
  return (x % 5) % 5;
}

int
f2 (int x)
{
  return (x % 5) % 5;
}

int
f3 (int x)
{
  return (x % -5) % -5;
}

unsigned
f4 (unsigned x)
{
  return (x % 5) % 6;
}

int
f5 (int x)
{
  return (x % 5) % 6;
}

int
f6 (int x)
{
  return (x % -5) % -6;
}
