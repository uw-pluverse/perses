



extern void link_error(void);
int main()
{
  int i0, i1;
  if (!(i0 + 1 < i1 + 1 == i0 < i1))
    link_error ();
  if (!(i0 + (-2147483647 -1) < i1 - 2147483647 == i0 < i1 - -1))
    link_error ();
  return 0;
}
