





void foo (const char *, ...) __attribute__ ((noreturn));
int bar (const char *, ...);
extern long unsigned int strlen (const char *);
int baz (char *, char *, int, void *);

void
test (char *w, int x, char *y, char *z)
{
  char *p, b[32];
  for (p = y; *p; p += strlen (p) + 1)
    {
      baz (w, p, x, z);
      foo ("msg1 %s", b);
    }
  for (p = y; *p; p += strlen (p) + 1)
    bar (" %s", p);
  foo ("msg2 %s", b);
}
