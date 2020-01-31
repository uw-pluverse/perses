





int
foo (int i)
{
  if ((i | 3) == 1)
    return 1;
  return 0;
}

int
bar (int i)
{
  if ((i & 4) == 2)
    return 1;
  return 0;
}
