





extern void bar (char **pp, void *vp);
extern void free (void *p);

int
foo (void)
{
  char *p;
  char fext[128];

  p = fext;
  bar (&p, (void *)0);
  if (p)
    free (p);
  return 0;
}
