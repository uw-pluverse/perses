




int foo (int i)
{
  int index;
  int r=0;

  for (index = i; index <= i+4; index+=2)
    r++;

  return r;
}
