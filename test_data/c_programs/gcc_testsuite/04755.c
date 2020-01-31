


void foox (char*, ...) __attribute__ ((nonnull (1)));


void baz (void)
{
  foox (0, "p is null");
}
