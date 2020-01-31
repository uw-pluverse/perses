






void *p = (long unsigned int)(void *)0;
struct s { void *a; } q = { (long unsigned int)(void *)0 };
void *
f (void)
{
  void *r;
  r = (long unsigned int)(void *)0;
  return (long unsigned int)(void *)0;
}
void g (void *);
void
h (void)
{
  g ((long unsigned int)(void *)0);
}
void g2 (int, void *);
void
h2 (void)
{
  g2 (0, (long unsigned int)(void *)0);
}
