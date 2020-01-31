void fn1call (void);
void fn2call (void);

void
foo (unsigned __int128 x)
{
  if (x > (unsigned __int128) -3)
    return;
  unsigned __int128 y = 2 * x;
  if (y == 42)
    fn1call ();
  else
    fn2call ();
}
