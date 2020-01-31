



int
foo (int *p)
{
  return *p;
}

int
main (void)
{
  int **p = 0;
  return foo (*p);
}
