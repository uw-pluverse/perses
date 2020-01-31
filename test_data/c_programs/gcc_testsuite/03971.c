

foo (a, b, p)
     unsigned a, b;
     int *p;
{
  p[1] = a % 95;
  p[0] = a / 95;
}

bar (a, b, p)
     unsigned a, b;
     int *p;
{
  p[0] = a / 95;
  p[1] = a % 95;
}
