




float
foo (float x, float y)
{
  volatile int i = 0;
  return i != 0 ? x : y;
}
