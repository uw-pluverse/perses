


extern void bar(unsigned *, char *);

void foo(char *s)
{
  unsigned i;
  char t[2];

  bar(&i, t);

  for (i = 0; i < 2; i++)
    s[i] = t[i];
}
