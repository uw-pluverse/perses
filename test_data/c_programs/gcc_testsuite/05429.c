




int foo (int x, int a)
{

  if (x > a)
    goto doit;
  if (x == a)
    goto doit;


  return 0;


doit:
  return 2;
}
