




typedef int (*F) (void);

int x (F f)
{
  f ();




  return 3;
}

int y (F f)
{
  return f ();
}
