


void f (const char *c, int *i)
{
  *i = 42;
  __builtin_memcpy (i + 1, c, sizeof (int));
  if (*i != 42) __builtin_abort();
}

extern void keepit ();
void g (const char *c, int *i)
{
  *i = 33;
  __builtin_memcpy (i - 1, c, 3 * sizeof (int));
  if (*i != 33) keepit();
}
