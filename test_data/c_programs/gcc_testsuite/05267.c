





extern void link_error (void);
int i;
int foo(int b, int c)
{
  i = b + 1;
  int j = i - 1;
  if (b != j)
    link_error ();
}
