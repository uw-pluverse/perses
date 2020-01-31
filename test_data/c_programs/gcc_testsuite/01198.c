



extern int bar ();
extern void bar2 (int);

int
foo4 ()
{
  int result = 0;
  int f = -1;
  f = bar ();
  if (f < 0)
    {
      result = 1;
      goto bail;
    }
  bar ();
 bail:
  bar2 (f);
  return result;
}
