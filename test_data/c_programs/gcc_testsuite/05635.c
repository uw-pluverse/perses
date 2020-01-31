


int foo (_Bool x)
{
  _Bool t = 1;
  _Bool xx = !x;
  _Bool y = xx == t;
  _Bool z = y == x;
  return z ? 1 : 0;
}
