



int
main ()
{
  struct S { char s; } v;
  v.s = 47;
  unsigned int a = (unsigned int) v.s;
  unsigned int b = (27005061 + (a + 680455));
  unsigned int c
    = ((1207142401u * (((8u * b) + 9483541u) - 230968044u)) + 469069442u);
  if (c != 1676211843u)
    __builtin_abort ();
  return 0;
}
