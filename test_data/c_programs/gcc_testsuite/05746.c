



int
main ()
{
  struct S { char s; } v;
  v.s = 47;
  int a = (int) v.s;
  int b = (27005061 + (a + 680455));
  int c = ((1207142401 * (((8 * b) + 9483541) - 230968044)) + 469069442);
  if (c != 1676211843)
    __builtin_abort ();
  return 0;
}
