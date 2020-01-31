extern void exit (int);

static inline int
foo (void)
{




  return 0;

}

static inline int
bar (void)
{
  if (foo == foo)
    return 1;
  else
    return foo ();
}

int main (void)
{
  exit (0);
}
