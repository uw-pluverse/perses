

unsigned foo1 (unsigned a, unsigned b, unsigned j, unsigned k)
{
  unsigned i;
  for (i = 0; i != a; i++)
    {
      j += 4*b;
      k += 4*a;
    }
  return j + k;
}
