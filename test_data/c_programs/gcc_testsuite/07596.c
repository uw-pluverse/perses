






void
good_cast(const void *bar)
{
  (char *const *)bar;
}

void
bad_cast(const void *bar)
{
  (const char **)bar;
}

void
good_assign(const void *bar)
{
  char *const *foo = bar;
}

void
bad_assign(const void *bar)
{
  const char **foo = bar;
}
