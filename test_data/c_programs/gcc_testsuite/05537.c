


extern void link_error (void);

void
foo (int b)
{
  int a;
  a = b + 2;
  a--;
  a--;
  if (a != b)
    link_error ();
}
