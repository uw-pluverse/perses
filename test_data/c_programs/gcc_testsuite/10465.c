




struct foo {
  char a;
};

extern void abort (void);
extern void exit (int);

int
sfoo (void)
{
  if (sizeof (struct foo { int a; double b; char *c; void *d; }))
    (void) 0;
  return sizeof (struct foo);
}

int
main (void)
{
  int t, u;
  t = sfoo ();
  u = sizeof (struct foo);



  if (t == u)
    exit (0);
  else
    abort ();
}
