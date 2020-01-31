


int a[128];
extern int b[];

int bar (int *);

int
foo (int n)
{
  int i;

  for (i = 0; i < n; i++)
    {
      unsigned char uc = (unsigned char)i;
      a[i] = i;
      b[uc] = 0;
    }

  bar (a);
  return 0;
}
