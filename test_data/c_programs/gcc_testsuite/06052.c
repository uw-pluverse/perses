




int foo (int x, int a, int b)
{

  if (x & a)
    goto doit;
  if (x & b)
    goto doit;


  return 0;


doit:
  return 2;
}
