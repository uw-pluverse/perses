





int foo (const char *, ...) __attribute__ ((format (printf, 1, 2)));

void
bar (unsigned int x)
{
  foo ("%x", __builtin_bswap32 (x));
}
