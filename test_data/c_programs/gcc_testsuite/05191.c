





extern void link_error (void);
void foo()
{
  int i;
  char *p = (char *)&i;
  long *q = (long *)p;
  if (q == 0)
    link_error ();
}
