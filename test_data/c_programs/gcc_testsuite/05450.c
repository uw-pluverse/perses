


extern void f(char *const *);
void g (char **o)
{
  static const char *const multilib_exclusions_raw[] = { 0 };
  const char *const *q = multilib_exclusions_raw;

  f (o);
  while (*q++)
    f (o);
}
