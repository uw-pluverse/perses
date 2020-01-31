



int printf (const char *, ...) __attribute__ ((__format__ (__printf__, 1, 2)));

void
foo (void)
{
  printf ("%d\n", 0UL);

}
