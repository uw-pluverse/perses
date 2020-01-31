



int foo (int i, int b, int result)
{
  int mask;
  if (b)
    mask = -2;
  else
    mask = 0;
  result = i + 1;
  result = result & mask;
  return result;
}
