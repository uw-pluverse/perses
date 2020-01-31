



extern void link_error ();

void test02(unsigned int a, unsigned int b)
{
  unsigned int x = 0x80000000;
  if (a > x)
    if (b < x)
      if (a == b)
        link_error ();
}
