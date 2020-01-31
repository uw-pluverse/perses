






void link_error (void);

void
f (void)
{
  int a[10];
  int *p = &a[5];
  int *q = p - 1;
  if (q != &a[4])
    link_error ();
}
