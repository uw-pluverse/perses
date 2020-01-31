



extern void abort (void);




void
f1 (unsigned int s)
{
  if ((s & (7U << ((sizeof (int) * 8 - 1) - 2))) != 0)
    {
      if (s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == -1U || s == -15U
   || s == -15550U || s == -15552U || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (1 << ((sizeof (int) * 8 - 1) - 2))
   || s == 1U + 2147483647 || s == -32U
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == -5U || s == -63U
   || s == -64U || s == -65U || s == 6U + 2147483647 || s == -8189U
   || s == -8191U || s == -8192U || s == -8193U || s == -8250U
   || s == -8255U || s == -8256U || s == -8257U || s == 2147483647
   || s == 2147483647 + 9U)
 return;
    }
  else
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f || s == 1
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1 || s == 2 || s == 24 || s == 5)
 return;
    }
  abort ();
}

void
f2 (int s)
{
  if ((s & (7U << ((sizeof (int) * 8 - 1) - 2))) == 0)
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f || s == 1
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1 || s == 2 || s == 24 || s == 5)
 return;
    }
  else
    {
      if (s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == -1 || s == -15 || s == -15550
   || s == -15552 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (1 << ((sizeof (int) * 8 - 1) - 2))
   || s == -2147483647 - 1 || s == -32 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2
   || s == -5 || s == -63 || s == -64 || s == -65
   || s == -2147483647 + 4 || s == -8189 || s == -8191 || s == -8192
   || s == -8193 || s == -8250 || s == -8255 || s == -8256
   || s == -8257 || s == 2147483647 || s == -2147483647 + 7)
 return;
    }
  abort ();
}

void
f3 (unsigned int s)
{
  if ((s & 0x3cc0) == 0)
    {
      if (s == 0 || s == 0x20 || s == 0x3f || s == (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (1 << ((sizeof (int) * 8 - 1) - 2))
   || s == 1U + 2147483647 || s == 2 || s == 24
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == 6U + 2147483647
   || s == 2147483647 + 9U)
 return;
    }
  else
    {
      if (s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x3cbf || s == 0x3cc0 || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == -1U || s == -15U
   || s == -15550U || s == -15552U || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1 || s == -32U || s == -5U
   || s == -63U || s == -64U || s == -65U || s == -8189U || s == -8191U
   || s == -8192U || s == -8193U || s == -8250U || s == -8255U
   || s == -8256U || s == -8257U || s == 2147483647)
 return;
    }
  abort ();
}

void
f4 (int s)
{
  if ((s & 0x3cc0) == 0)
    {
      if (s == 0 || s == 0x20 || s == 0x3f || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (1 << ((sizeof (int) * 8 - 1) - 2))
   || s == -2147483647 - 1 || s == 2 || s == 24
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -2147483647 + 4
   || s == -2147483647 + 7)
 return;
    }
  else
    {
      if (s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x3cbf || s == 0x3cc0 || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == -1 || s == -15 || s == -15550
   || s == -15552 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1 || s == -32 || s == -5 || s == -63
   || s == -64 || s == -65 || s == -8189 || s == -8191 || s == -8192
   || s == -8193 || s == -8250 || s == -8255 || s == -8256
   || s == -8257 || s == 2147483647)
 return;
    }
  abort ();
}

void
f5 (int s)
{
  if ((s & 0x3cc0U) == 0)
    {
      if (s == 0 || s == 0x20 || s == 0x3f || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (1 << ((sizeof (int) * 8 - 1) - 2))
   || s == -2147483647 - 1 || s == 2 || s == 24
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -2147483647 + 4
   || s == -2147483647 + 7)
 return;
    }
  else
    {
      if (s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x3cbf || s == 0x3cc0 || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == -1 || s == -15 || s == -15550
   || s == -15552 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1 || s == -32 || s == -5 || s == -63
   || s == -64 || s == -65 || s == -8189 || s == -8191 || s == -8192
   || s == -8193 || s == -8250 || s == -8255 || s == -8256
   || s == -8257 || s == 2147483647)
 return;
    }
  abort ();
}

void
f6 (unsigned int s)
{
  if ((s & 0x3cc0) == 0x3cc0)
    {
      if (s == 0x3cc0 || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == -1U || s == -15U
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == -32U || s == -5U || s == -63U || s == -64U
   || s == 2147483647)
 return;
    }
  else
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3f || s == (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == -15550U || s == -15552U || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == 1U + 2147483647 || s == 2
   || s == 24 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -65U
   || s == 6U + 2147483647 || s == -8189U || s == -8191U
   || s == -8192U || s == -8193U || s == -8250U || s == -8255U
   || s == -8256U || s == -8257U || s == 2147483647 + 9U)
 return;
    }
  abort ();
}

void
f7 (int s)
{
  if ((s & 0x3cc0) == 0x3cc0)
    {
      if (s == 0x3cc0 || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == -1 || s == -15
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == -32 || s == -5 || s == -63 || s == -64 || s == 2147483647)
 return;
    }
  else
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3f || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == -15550 || s == -15552 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == -2147483647 - 1 || s == 2
   || s == 24 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -65
   || s == -2147483647 + 4 || s == -8189 || s == -8191 || s == -8192
   || s == -8193 || s == -8250 || s == -8255 || s == -8256
   || s == -8257 || s == -2147483647 + 7)
 return;
    }
  abort ();
}

void
f8 (int s)
{
  if ((s & 0x3cc0U) == 0x3cc0)
    {
      if (s == 0x3cc0 || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == -1 || s == -15
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == -32 || s == -5 || s == -63 || s == -64 || s == 2147483647)
 return;
    }
  else
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3f || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == -15550 || s == -15552 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == -2147483647 - 1 || s == 2
   || s == 24 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -65
   || s == -2147483647 + 4 || s == -8189 || s == -8191 || s == -8192
   || s == -8193 || s == -8250 || s == -8255 || s == -8256
   || s == -8257 || s == -2147483647 + 7)
 return;
    }
  abort ();
}

void
f9 (unsigned int s)
{
  if ((s & 0x3cc0) >= 0x1cc0)
    {
      if (s == 0x1cc0 || s == 0x1fff || s == 0x2000 || s == 0x3cbf
   || s == 0x3cc0 || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == -1U || s == -15U
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == -32U || s == -5U || s == -63U || s == -64U || s == -65U
   || s == -8189U || s == -8191U || s == -8192U || s == -8193U
   || s == -8250U || s == -8255U || s == -8256U || s == 2147483647)
 return;
    }
  else
    {
      if (s == 0 || s == 0x1cbf || s == 0x20 || s == 0x3f
   || s == (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1 || s == -15550U
   || s == -15552U || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == 1U + 2147483647 || s == 2
   || s == 24 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5
   || s == 6U + 2147483647 || s == -8257U || s == 2147483647 + 9U)
 return;
    }
  abort ();
}

void
f10 (unsigned int s)
{
  if ((s & 0x3cc0) > 0x1cc0)
    {
      if (s == 0x2000 || s == 0x3cbf || s == 0x3cc0
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == -1U || s == -15U || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1 || s == -32U || s == -5U
   || s == -63U || s == -64U || s == -65U || s == -8189U || s == -8191U
   || s == -8192U || s == 2147483647)
 return;
    }
  else
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x20
   || s == 0x3f || s == (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1 || s == -15550U
   || s == -15552U || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == 1U + 2147483647 || s == 2
   || s == 24 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5
   || s == 6U + 2147483647 || s == -8193U || s == -8250U
   || s == -8255U || s == -8256U || s == -8257U
   || s == 2147483647 + 9U)
 return;
    }
  abort ();
}

void
f11 (int s)
{
  if ((s & 0x3cc0) >= 0x1cc0)
    {
      if (s == 0x1cc0 || s == 0x1fff || s == 0x2000 || s == 0x3cbf
   || s == 0x3cc0 || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == -1 || s == -15
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == -32 || s == -5 || s == -63 || s == -64 || s == -65
   || s == -8189 || s == -8191 || s == -8192 || s == -8193
   || s == -8250 || s == -8255 || s == -8256 || s == 2147483647)
 return;
    }
  else
    {
      if (s == 0 || s == 0x1cbf || s == 0x20 || s == 0x3f
   || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1 || s == -15550
   || s == -15552 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (1 << ((sizeof (int) * 8 - 1) - 2))
   || s == -2147483647 - 1 || s == 2 || s == 24
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -2147483647 + 4
   || s == -8257 || s == -2147483647 + 7)
 return;
    }
  abort ();
}

void
f12 (int s)
{
  if ((s & 0x3cc0) > 0x1cc0)
    {
      if (s == 0x2000 || s == 0x3cbf || s == 0x3cc0
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == -1 || s == -15 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1 || s == -32 || s == -5 || s == -63
   || s == -64 || s == -65 || s == -8189 || s == -8191 || s == -8192
   || s == 2147483647)
 return;
    }
  else
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x20
   || s == 0x3f || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1 || s == -15550
   || s == -15552 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (1 << ((sizeof (int) * 8 - 1) - 2))
   || s == -2147483647 - 1 || s == 2 || s == 24
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -2147483647 + 4
   || s == -8193 || s == -8250 || s == -8255 || s == -8256
   || s == -8257 || s == -2147483647 + 7)
 return;
    }
  abort ();
}

void
f13 (unsigned int s)
{
  if ((s & (0xe071U << ((sizeof (int) - sizeof (short)) * 8))) > (0xb030U << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) + 1
   || s == -1U || s == -15U || s == -15550U || s == -15552U
   || s == -32U || s == -5U || s == -63U || s == -64U || s == -65U
   || s == -8189U || s == -8191U || s == -8192U || s == -8193U
   || s == -8250U || s == -8255U || s == -8256U || s == -8257U)
 return;
    }
  else
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) || s == 1 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (1 << ((sizeof (int) * 8 - 1) - 2))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1 || s == 1U + 2147483647 || s == 2
   || s == 24 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5
   || s == 6U + 2147483647 || s == 2147483647
   || s == 2147483647 + 9U)
 return;
    }
  abort ();
}

void
f14 (unsigned int s)
{
  if ((s & (0xe071U << ((sizeof (int) - sizeof (short)) * 8))) > (0xa030U << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) + 1
   || s == -1U || s == -15U || s == -15550U || s == -15552U
   || s == -32U || s == -5U || s == -63U || s == -64U || s == -65U
   || s == -8189U || s == -8191U || s == -8192U || s == -8193U
   || s == -8250U || s == -8255U || s == -8256U || s == -8257U)
 return;
    }
  else
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) || s == 1 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (1 << ((sizeof (int) * 8 - 1) - 2))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1 || s == 1U + 2147483647 || s == 2
   || s == 24 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5
   || s == 6U + 2147483647 || s == 2147483647
   || s == 2147483647 + 9U)
 return;
    }
  abort ();
}

void
f15 (int s)
{
  if ((s & ((-0x1f8f) << ((sizeof (int) - sizeof (short)) * 8))) > ((-0x4fd0) << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == -1 || s == -15 || s == -15550 || s == -15552
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == 2 || s == 24 || s == -32 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2
   || s == 5 || s == -5 || s == -63 || s == -64 || s == -65
   || s == -8189 || s == -8191 || s == -8192 || s == -8193
   || s == -8250 || s == -8255 || s == -8256 || s == -8257
   || s == 2147483647)
 return;
    }
  else
    {
      if (s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == -2147483647 - 1
   || s == -2147483647 + 4 || s == -2147483647 + 7)
 return;
    }
  abort ();
}

void
f16 (int s)
{
  if ((s & ((-0x1f8f) << ((sizeof (int) - sizeof (short)) * 8))) >= ((-0x4fd0) << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == -1 || s == -15 || s == -15550 || s == -15552
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == 2 || s == 24 || s == -32 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2
   || s == 5 || s == -5 || s == -63 || s == -64 || s == -65
   || s == -8189 || s == -8191 || s == -8192 || s == -8193
   || s == -8250 || s == -8255 || s == -8256 || s == -8257
   || s == 2147483647)
 return;
    }
  else
    {
      if (s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == -2147483647 - 1
   || s == -2147483647 + 4 || s == -2147483647 + 7)
 return;
    }
  abort ();
}

void
f17 (int s)
{
  if ((s & ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1)) != -2147483647 - 1)
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1 || s == -1 || s == -15
   || s == -15550 || s == -15552 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (1 << ((sizeof (int) * 8 - 1) - 2))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1 || s == 2 || s == 24 || s == -32
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -5 || s == -63
   || s == -64 || s == -65 || s == -2147483647 + 4 || s == -8189
   || s == -8191 || s == -8192 || s == -8193 || s == -8250
   || s == -8255 || s == -8256 || s == -8257 || s == 2147483647)
 return;
    }
  else
    {
      if (s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == -2147483647 - 1 || s == -2147483647 + 7)
 return;
    }
  abort ();
}

void
f18 (int s)
{
  if ((s & ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1)) != ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1))
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == 1 || s == -15550 || s == -15552
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == -2147483647 - 1 || s == 2 || s == 24 || s == -32
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -64
   || s == -2147483647 + 4 || s == -8192 || s == -8250 || s == -8256
   || s == 2147483647 || s == -2147483647 + 7)
 return;
    }
  else
    {
      if (s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1
   || s == -1 || s == -15 || s == -5 || s == -63 || s == -65
   || s == -8189 || s == -8191 || s == -8193 || s == -8255
   || s == -8257)
 return;
    }
  abort ();
}

void
f19 (int s)
{
  if ((s & ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1)) != ((0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1))
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1 || s == -1 || s == -15
   || s == -15550 || s == -15552 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == -2147483647 - 1 || s == 2 || s == 24 || s == -32
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -5 || s == -63
   || s == -64 || s == -65 || s == -2147483647 + 4 || s == -8189
   || s == -8191 || s == -8192 || s == -8193 || s == -8250
   || s == -8255 || s == -8256 || s == -8257 || s == -2147483647 + 7)
 return;
    }
  else
    {
      if (s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == 2147483647)
 return;
    }
  abort ();
}

void
f20 (int s)
{
  if ((s & (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))) != -2147483647 - 1)
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == -1 || s == -15 || s == -15550 || s == -15552
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == 2 || s == 24 || s == -32 || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2
   || s == 5 || s == -5 || s == -63 || s == -64 || s == -65
   || s == -8189 || s == -8191 || s == -8192 || s == -8193
   || s == -8250 || s == -8255 || s == -8256 || s == -8257
   || s == 2147483647)
 return;
    }
  else
    {
      if (s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == -2147483647 - 1
   || s == -2147483647 + 4 || s == -2147483647 + 7)
 return;
    }
  abort ();
}

void
f21 (int s)
{
  if ((s & (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))) != (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == -2147483647 - 1 || s == 2 || s == 24
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -2147483647 + 4
   || s == 2147483647 || s == -2147483647 + 7)
 return;
    }
  else
    {
      if (s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) || s == -1 || s == -15 || s == -15550
   || s == -15552 || s == -32 || s == -5 || s == -63 || s == -64
   || s == -65 || s == -8189 || s == -8191 || s == -8192 || s == -8193
   || s == -8250 || s == -8255 || s == -8256 || s == -8257)
 return;
    }
  abort ();
}

void
f22 (int s)
{
  if ((s & (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))) != (0x7000 << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (-0x4041 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) || s == (-0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1 || s == -1 || s == -15
   || s == -15550 || s == -15552 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == -2147483647 - 1 || s == 2 || s == 24 || s == -32
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -5 || s == -63
   || s == -64 || s == -65 || s == -2147483647 + 4 || s == -8189
   || s == -8191 || s == -8192 || s == -8193 || s == -8250
   || s == -8255 || s == -8256 || s == -8257 || s == -2147483647 + 7)
 return;
    }
  else
    {
      if (s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == 2147483647)
 return;
    }
  abort ();
}

void
f23 (unsigned int s)
{
  if ((s & (0xf000U << ((sizeof (int) - sizeof (short)) * 8))) != (0x7000 << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1 || s == -1U || s == -15U
   || s == -15550U || s == -15552U || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == 1U + 2147483647 || s == 2 || s == 24 || s == -32U
   || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2 || s == 5 || s == -5U || s == -63U
   || s == -64U || s == -65U || s == 6U + 2147483647 || s == -8189U
   || s == -8191U || s == -8192U || s == -8193U || s == -8250U
   || s == -8255U || s == -8256U || s == -8257U
   || s == 2147483647 + 9U)
 return;
    }
  else
    {
      if (s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == 2147483647)
 return;
    }
  abort ();
}

void
f24 (unsigned int s)
{
  if ((s & (0xf000U << ((sizeof (int) - sizeof (short)) * 8))) != (0x8000U << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s == 0 || s == 0x1cbf || s == 0x1cc0 || s == 0x1fff || s == 0x2000
   || s == 0x20 || s == 0x3cbf || s == 0x3cc0 || s == 0x3f
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) - 1
   || s == (0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xf000U << ((sizeof (int) - sizeof (short)) * 8))
   || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) + 1 || s == 1
   || s == -1U || s == -15U || s == -15550U || s == -15552U
   || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8))
   || s == (1 << ((sizeof (int) * 8 - 1) - 2)) || s == (1 << ((sizeof (int) * 8 - 1) - 2)) - 1
   || s == 2 || s == 24 || s == -32U || s == (3 << ((sizeof (int) * 8 - 1) - 2)) + 2
   || s == 5 || s == -5U || s == -63U || s == -64U || s == -65U
   || s == -8189U || s == -8191U || s == -8192U || s == -8193U
   || s == -8250U || s == -8255U || s == -8256U || s == -8257U
   || s == 2147483647)
 return;
    }
  else
    {
      if (s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1 || s == 1U + 2147483647
   || s == 6U + 2147483647 || s == 2147483647 + 9U)
 return;
    }
  abort ();
}

int svals[] = {
  0,
  0x1cbf,
  0x1cc0,
  0x1fff,
  0x2000,
  0x20,
  0x3cbf,
  0x3cc0,
  0x3f,
  (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1,
  (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) - 1,
  (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1,
  (-0x5fcf << ((sizeof (int) - sizeof (short)) * 8)) - 1,
  (-0x4041 << ((sizeof (int) - sizeof (short)) * 8)),
  (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)),
  (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)),
  (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)),
  (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) + 1,
  1,
  -1,
  -15,
  -15550,
  -15552,
  (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1,
  (0x7000 << ((sizeof (int) - sizeof (short)) * 8)),
  (1 << ((sizeof (int) * 8 - 1) - 2)),
  (1 << ((sizeof (int) * 8 - 1) - 2)) - 1,
  -2147483647 - 1,
  2,
  24,
  -32,
  (3 << ((sizeof (int) * 8 - 1) - 2)) + 2,
  5,
  -5,
  -63,
  -64,
  -65,
  -2147483647 + 4,
  -8189,
  -8191,
  -8192,
  -8193,
  -8250,
  -8255,
  -8256,
  -8257,
  2147483647,
  -2147483647 + 7,
};

unsigned int uvals[] = {
  0,
  0x1cbf,
  0x1cc0,
  0x1fff,
  0x2000,
  0x20,
  0x3cbf,
  0x3cc0,
  0x3f,
  (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1,
  (0xf000U << ((sizeof (int) - sizeof (short)) * 8)) - 1,
  (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1,
  (0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1,
  (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8)),
  (0xc000U << ((sizeof (int) - sizeof (short)) * 8)),
  (0xf000U << ((sizeof (int) - sizeof (short)) * 8)),
  (0x9000U << ((sizeof (int) - sizeof (short)) * 8)),
  (0xc000U << ((sizeof (int) - sizeof (short)) * 8)) + 1,
  1,
  -1U,
  -15U,
  -15550U,
  -15552U,
  (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) - 1,
  (0x7000 << ((sizeof (int) - sizeof (short)) * 8)),
  (1 << ((sizeof (int) * 8 - 1) - 2)),
  (1 << ((sizeof (int) * 8 - 1) - 2)) - 1,
  1U + 2147483647,
  2,
  24,
  -32U,
  (3 << ((sizeof (int) * 8 - 1) - 2)) + 2,
  5,
  -5U,
  -63U,
  -64U,
  -65U,
  6U + 2147483647,
  -8189U,
  -8191U,
  -8192U,
  -8193U,
  -8250U,
  -8255U,
  -8256U,
  -8257U,
  2147483647,
  2147483647 + 9U,
};

int
main ()
{
  int i;
  for (i = 0; i < sizeof (svals) / sizeof (svals[0]); i++)
    {
      f2 (svals[i]);
      f4 (svals[i]);
      f5 (svals[i]);
      f7 (svals[i]);
      f8 (svals[i]);
      f11 (svals[i]);
      f12 (svals[i]);
      f15 (svals[i]);
      f16 (svals[i]);
      f17 (svals[i]);
      f18 (svals[i]);
      f19 (svals[i]);
      f20 (svals[i]);
      f21 (svals[i]);
      f22 (svals[i]);
    }
  for (i = 0; i < sizeof (uvals) / sizeof (uvals[0]); i++)
    {
      f1 (uvals[i]);
      f3 (uvals[i]);
      f6 (uvals[i]);
      f9 (uvals[i]);
      f10 (uvals[i]);
      f13 (uvals[i]);
      f14 (uvals[i]);
      f23 (uvals[i]);
      f24 (uvals[i]);
    }
  return 0;
}
