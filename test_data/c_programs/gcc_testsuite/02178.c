

void abort (void);

static
long long min ()
{
  return -9223372036854775807LL - 1;
}

void
foo (long long j)
{
  if (j > 10 || j < min ())
    abort ();
}

int
main (void)
{
  foo (10);
  return 0;
}
