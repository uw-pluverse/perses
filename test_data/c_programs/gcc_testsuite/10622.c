







extern int bigtime_test (int);
int
foo ()
{
  int j;
  for (j = 1; 0 < j; j *= 2)
    if (! bigtime_test (j))
      return 1;
  return 0;
}
