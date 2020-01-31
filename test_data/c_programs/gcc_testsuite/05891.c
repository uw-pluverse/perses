


extern void link_error (void);

int
foo (int i)
{
  int x;

  x = i;
  if (i < -10)
    {
      x = __builtin_abs (i);

      if (x < 0)
 link_error ();
    }

  return x;
}

int
main()
{
  foo (-30);
}
