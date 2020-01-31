






int
foo (int a)
{
  int b = a & 0xff;
  if (b > 300)
    return 2;
  else
    return 1;
}
