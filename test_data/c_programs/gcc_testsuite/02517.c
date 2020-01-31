extern void abort (void);
extern int abs_called;
extern int inside_main;




int
abs (int x)
{
  if (inside_main)
    abs_called = 1;
  return (x < 0 ? -x : x);
}

long
labs (long x)
{
  if (inside_main)
    abort ();
  return (x < 0 ? -x : x);
}
