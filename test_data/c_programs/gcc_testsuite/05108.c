


extern void link_error (void);





void test5 (int x)
{
  extern int foo (int);
  if (x == 0)
    foo (x);
  else if (x == 0 )
    link_error ();
}

void test55 (int x, int y)
{
  int u;
  if (x == 5 && y)
    {
      u = x + 22;
      if (u != 27)
        link_error ();
    }
}
