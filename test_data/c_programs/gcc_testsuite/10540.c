



int
main ()
{
  int v = 1;
  (void) (1 == 2 ? (void) 0 : (v = 0));
  return v;
}
