





int
fn1 (int i)
{
  return i == (-1 << 8);
}

int
fn2 (int i)
{
  return i == (1 << (sizeof (int) * 8));
}

int
fn3 (int i)
{
  return i == 10 << ((sizeof (int) * 8) - 1);
}

int
fn4 (int i)
{
  return i == 1 << -1;
}

int
fn5 (int i)
{
  return i == 1 >> (sizeof (int) * 8);
}

int
fn6 (int i)
{
  return i == 1 >> -1;
}
