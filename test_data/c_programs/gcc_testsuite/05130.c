

void
cleanup (int a, int b)
{
  if (a)
    if (b)
      a = 1;
    else
      b = 1;
  else if (a)
    a = 1;
  else
    b = 1;
  return;
}
