






extern void abort(void);
extern char *strpbrk (const char *, const char *);
extern int strcmp (const char *, const char *);

void fn (const char *foo, const char *const *bar)
{
  if (strcmp(strpbrk ("hello world", "lrooo"), "llo world") != 0)
    abort();
  if (strpbrk (foo, "") != 0)
    abort();
  if (strpbrk (foo + 4, "") != 0)
    abort();
  if (strpbrk (*bar--, "") != 0)
    abort();
  if (strpbrk (*bar, "h") != foo)
    abort();
  if (strpbrk (foo, "h") != foo)
    abort();
  if (strpbrk (foo, "w") != foo + 6)
    abort();
  if (strpbrk (foo + 6, "o") != foo + 7)
    abort();



  if (__builtin_strpbrk (foo + 6, "o") != foo + 7)
    abort();
}

void
main_test (void)
{
  const char *const foo[] = { "hello world", "bye bye world" };
  fn (foo[0], foo + 1);
}
