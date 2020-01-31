



foo (a)
     unsigned a;
{
  return (a >> 31) & ((1 << 17) - 1);
}

main ()
{
  printf ("%d%d\n", foo (-1), foo (0));
}
