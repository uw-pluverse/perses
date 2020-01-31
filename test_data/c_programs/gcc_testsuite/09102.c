




void foo (void);

int
f (int i)
{
  if (i > 1)
    __builtin_unreachable();
  if (i > 1)
    foo ();
  return 1;
}
