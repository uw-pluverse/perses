



int c;
char *p;

void
foo (int i)
{
  char a[2];
  char b[20];
  p = __builtin___stpcpy_chk (a, "", 2);
  p = __builtin___stpcpy_chk (&b[16], i ? "e" : "jkl", 4);
  if (c)
    foo (i);
}
