






extern int a, bar (void);

int
fn1 (void)
{
  if (a)
    return 1;
  else if (bar ())
    return 2;
  else if (a)
    return 3;
  return 0;
}

int
fn2 (int c)
{
  if (c < 0)
    return 1;
  else if (--c == 0)
    return 2;
  else if (c < 0)
    return 3;
  return 0;
}
