

extern void abort (void);

struct S
{
  int s : (sizeof (int) * 8 - 2);
} s;

void
foo (void)
{
  s.s *= 2;
}

int
main ()
{
  s.s = 24;
  foo ();
  if (s.s != 48)
    abort ();
  return 0;
}
