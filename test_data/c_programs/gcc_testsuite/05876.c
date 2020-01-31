


extern void link_error (void);



void test1 (void)
{
  unsigned int l = 3 * 4 - 5 / 2;
  if (l != 10)
    link_error ();
}

void test11 (void)
{
  unsigned int l = (((((((3 / 2 + 2) * 4) & 7) ^ 3) % 8) << 2) + 1) >> 2;
  if (l != 7)
    link_error ();
}


void test111 (void)
{
  unsigned int l0 = 3 / 2 + 2;
  unsigned int l1 = l0 * 4;
  unsigned int l2 = 7;
  unsigned int l3 = l1 & l2;
  unsigned int l4 = 3;
  unsigned int l5 = l3 ^ l4;
  unsigned int l6 = 8;
  unsigned int l7 = l5 % l6;
  unsigned int l8 = 2;
  unsigned int l9 = l7 << l8;
  unsigned int l10 = l9 + 1;
  unsigned int l11 = l10 >> 2;
  if (l11 != 7)
    link_error ();
}



void test1111 (int p)
{
  int l = 53;
  if (p)
    {
      if ((67 + l - 25) != 95)
        link_error ();
    }
  else
    {
      if ((93 - l + 25) != 65)
        link_error ();
    }
}


void test11111 (int p, int q, int r)
{
  int l = 53;
  while (p < r)
    {
      if ((67 + l - 25) != 95)
        link_error ();
      p -= q;
    }
}
