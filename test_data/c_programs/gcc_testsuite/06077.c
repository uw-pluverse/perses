


int f(int i)
{
  _Bool t = !i;
  int g = !t && i;
  int h = g == 3;
  return h;
}
