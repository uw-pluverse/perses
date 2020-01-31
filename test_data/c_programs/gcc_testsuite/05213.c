




void eshup8 (unsigned short *);

void
enormlz (x)
     unsigned short x[];
{
  register unsigned short *p;
  p = &x[2];
  while ((*p & 0xff00) == 0)
    {
      eshup8 (x);
    }
}
