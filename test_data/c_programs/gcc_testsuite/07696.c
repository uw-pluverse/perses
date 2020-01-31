



int
foo (int x)
{

  switch (x)
    {
    case 1 >> -1:
    case -1 >> -1:
    case 1 << -1:
    case -1 << -1:
      return 1;
    }
  return 0;
}

int
bar (int x)
{

  switch (x)
    {
    case -1 >> 200:
    case 1 << 200:
      return 1;
    }
  return 0;
}
