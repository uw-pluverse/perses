











extern void abort (void);

int __attribute__((noinline))
foo (const char *s)
{
  if (!s)
    return 1;
  if (s[0] != 'a')
    abort ();
  s += 0x10000000000UL - 1;
  if (s[0] != 'b')
    abort ();
  return 0;
}

int (*fn) (const char *) = foo;

int __attribute__((noinline))
bar (void)
{
  char s[0x10000000000UL];
  s[0] = 'a';
  s[0x10000000000UL - 1] = 'b';
  foo (s);
  foo (s);
  return 0;
}

int __attribute__((noinline))
baz (long i)
{
  if (i)
    return fn (0);
  else
    {
      char s[0x10000000000UL];
      s[0] = 'a';
      s[0x10000000000UL - 1] = 'b';
      foo (s);
      foo (s);
      return fn (0);
    }
}

int
main (void)
{
  if (bar ())
    abort ();
  if (baz (0) != 1)
    abort ();
  if (baz (1) != 1)
    abort ();
  return 0;
}
