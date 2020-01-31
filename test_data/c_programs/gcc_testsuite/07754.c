




extern int sprintf (char *, const char *, ...);

void
foo (char *buf1, char *buf2)
{
  sprintf (buf1, "%s", "abcde");
  sprintf (buf2, "%s");
}
