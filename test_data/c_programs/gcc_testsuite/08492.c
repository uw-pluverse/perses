

void bar( char *);
int foo()
{
  int i=0;
  {
    char a[8000];
    bar(a);
    i += a[0];
  }
  {
    char a[8192];
    char b[32];
    bar(a);
    i += a[0];
    bar(b);
    i += a[0];
  }
  return i;
}
