


void test (int x, int **pp)
{
  while (x)
    {
      int *ip = *pp;
      int *op = *pp;
      while (*ip)
 {
   int v = *ip++;
   *op++ = v + 1;
 }
    }
}
