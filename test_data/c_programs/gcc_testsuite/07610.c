


char digs[] = "0123456789";
int foo (void)
{
  int xlcbug = 1 / (&(digs + 5)[-2 + (_Bool) 1] == &digs[4] ? 1 : -1);
  return xlcbug;
}
