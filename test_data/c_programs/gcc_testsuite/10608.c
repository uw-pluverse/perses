static int scanf(const char *restrict, ...);



extern int sscanf(const char *restrict, const char *restrict, int *);

void
foo (const char *s, int *p)
{
  scanf("%ld", p);
  sscanf(s, "%ld", p);
}


static int
scanf (const char *restrict fmt, ...)
{
  return 0;
}
