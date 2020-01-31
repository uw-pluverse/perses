




float g (void *a, void *b, int e, int c, float d)
{
  return d;
}

float f (void *a, void *b, int c, float d)
{
  return g (a, b, 0, c, d);
}

int main ()
{
  f (0, 0, 1, 1);
  return 0;
}
