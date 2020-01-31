




int f(int *a)
{
  int t = *a;
  unsigned *b = (unsigned *)a;
  int *c = (int*)b;
  return *c + t;
}
