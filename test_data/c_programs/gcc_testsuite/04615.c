





__attribute__((no_sanitize_undefined, returns_nonnull))
char *
foo (char *x)
{
  return x;
}

__attribute__((nonnull)) void bar (char *, int, char *);

__attribute__((no_sanitize_undefined))
void
baz (char *x, int y, char *z)
{
  bar (x, y, z);
}
