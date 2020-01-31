



int myprintf (const char *, ...) __attribute__ ((__format__ (printf, 1, 2)));
int myprintf (const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)));

void
foo (void)
{
  myprintf ("%d\n", 0UL);

}
