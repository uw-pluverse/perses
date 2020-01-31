



int
foo1 (int a)
{
  return a | 0xffffff00;
}



int
foo2 (int a)
{
  return a & 0xffeeffee;
}



int
foo3 (int a)
{
  return a & 0xaaaaaa00;
}
