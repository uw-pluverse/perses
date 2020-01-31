







int
plus (int a, int b)
{
  return (a * 64) + b;
}



int
minus (int a, int b)
{
  return a - (b * 64);
}



int
ior (int a, int b)
{
  return (a * 64) | b;
}



int
xor (int a, int b)
{
  return (a * 64) ^ b;
}



int
and (int a, int b)
{
  return (a * 64) & b;
}



int
rsb (int a, int b)
{
  return (a * 64) - b;
}



int
mvn (int a, int b)
{
  return ~(a * 64);
}
