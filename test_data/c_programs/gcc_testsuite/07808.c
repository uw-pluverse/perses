





static __thread int vara;

int
foo (int b)
{
  return vara + b;
}

int
main (void)
{
  return foo (0);
}
