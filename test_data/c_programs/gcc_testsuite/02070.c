




long level = 0;
extern long foo (void);
extern long bar (void);







int
main (void)
{
  if (foo () == -42)
    exit (0);

  abort ();
}

long
foo (void)
{
  long tmp = ++level;
  return bar () + tmp;
}

long
bar (void)
{
  long tmp = level;
  return tmp > 500 - 1 ? -42 - tmp : foo () - tmp;
}
