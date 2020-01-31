






extern void abort (void);
extern int strcmp (const char *, const char *);

int x = 7;
char *bar = "hi world";

void
main_test (void)
{
  const char *const foo = "hello world";

  if (strcmp (foo, "hello") <= 0)
    abort ();
  if (strcmp (foo + 2, "llo") <= 0)
    abort ();
  if (strcmp (foo, foo) != 0)
    abort ();
  if (strcmp (foo, "hello world ") >= 0)
    abort ();
  if (strcmp (foo + 10, "dx") >= 0)
    abort ();
  if (strcmp (10 + foo, "dx") >= 0)
    abort ();
  if (strcmp (bar, "") <= 0)
    abort ();
  if (strcmp ("", bar) >= 0)
    abort ();
  if (strcmp (bar+8, "") != 0)
    abort ();
  if (strcmp ("", bar+8) != 0)
    abort ();
  if (strcmp (bar+(--x), "") <= 0 || x != 6)
    abort ();
  if (strcmp ("", bar+(++x)) >= 0 || x != 7)
    abort ();



  if (__builtin_strcmp (foo, "hello") <= 0)
    abort ();
}
