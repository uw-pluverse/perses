


int
foo (int i)
{
  switch (i)
    {
    case 0:
    case 2:
    case 5:
      return 0;
    case 7:
    case 11:
    case 13:
      return 1;
    }
  return -1;
}
