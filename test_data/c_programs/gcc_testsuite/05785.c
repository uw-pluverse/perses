



extern void link_error (void);




void
f1 (unsigned int s)
{
  if ((s & (7U << ((sizeof (int) * 8 - 1) - 2))) != 0)
    {
      if (s <= (1U << ((sizeof (int) * 8 - 1) - 2)) - 1)
 link_error ();
    }
  else
    {
      if (s >= (1U << ((sizeof (int) * 8 - 1) - 2)))
 link_error ();
    }
}

void
f2 (int s)
{
  if ((s & (7U << ((sizeof (int) * 8 - 1) - 2))) == 0)
    {
      if (s >= (1 << ((sizeof (int) * 8 - 1) - 2)) || s < 0)
 link_error ();
    }
  else
    {
      if (s >= 0 && s <= (1 << ((sizeof (int) * 8 - 1) - 2)) - 1)
 link_error ();
    }
}

void
f3 (unsigned int s)
{
  if ((s & 0x3cc0) == 0)
    {
      if (s >= -15552U)
 link_error ();
    }
  else
    {
      if (s <= 0x3f)
 link_error ();
    }
}

void
f4 (int s)
{
  if ((s & 0x3cc0) == 0)
    {
      if (s >= -15552 && s < 0)
 link_error ();
    }
  else
    {
      if ( s == 0 || s == 0x20 || s == 0x3f)
 link_error ();
    }
}

void
f5 (int s)
{
  if ((s & 0x3cc0U) == 0)
    {
      if (s >= -15552 && s < 0)
 link_error ();
    }
  else
    {
      if ( s == 0 || s == 0x20 || s == 0x3f)
 link_error ();
    }
}

void
f6 (unsigned int s)
{
  if ((s & 0x3cc0) == 0x3cc0)
    {
      if (s <= 0x3cbf)
 link_error ();
    }
  else
    {
      if (s >= -64U)
 link_error ();
    }
}

void
f7 (int s)
{
  if ((s & 0x3cc0) == 0x3cc0)
    {
      if (s >= 0 && s <= 0x3cbf)
 link_error ();
    }
  else
    {
      if (s >= -64 && s < 0)
 link_error ();
    }
}

void
f8 (int s)
{
  if ((s & 0x3cc0U) == 0x3cc0)
    {
      if (s >= 0 && s <= 0x3cbf)
 link_error ();
    }
  else
    {
      if (s >= -64 && s < 0)
 link_error ();
    }
}

void
f9 (unsigned int s)
{
  if ((s & 0x3cc0) >= 0x1cc0)
    {
      if (s <= 0x1cbf)
 link_error ();
    }
  else
    {
      if (s >= -8256U)
 link_error ();
    }
}

void
f10 (unsigned int s)
{
  if ((s & 0x3cc0) > 0x1cc0)
    {
      if (s <= 0x1fff)
 link_error ();
    }
  else
    {
      if (s >= -8192U)
 link_error ();
    }
}

void
f11 (int s)
{
  if ((s & 0x3cc0) >= 0x1cc0)
    {
      if (s >= 0 && s <= 0x1cbf)
 link_error ();
    }
  else
    {
      if (s >= -8256 && s < 0)
 link_error ();
    }
}

void
f12 (int s)
{
  if ((s & 0x3cc0) > 0x1cc0)
    {
      if (s >= 0 && s <= 0x1fff)
 link_error ();
    }
  else
    {
      if (s >= -8192 && s < 0)
 link_error ();
    }
}

void
f13 (unsigned int s)
{
  if ((s & (0xe071U << ((sizeof (int) - sizeof (short)) * 8))) > (0xb030U << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s <= ((0xc000U << ((sizeof (int) - sizeof (short)) * 8)) - 1))
 link_error ();
    }
  else
    {
      if (s >= (0xc000U << ((sizeof (int) - sizeof (short)) * 8)))
 link_error ();
    }
}

void
f14 (unsigned int s)
{
  if ((s & (0xe071U << ((sizeof (int) - sizeof (short)) * 8))) > (0xa030U << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s <= ((0xa031U << ((sizeof (int) - sizeof (short)) * 8)) - 1))
 link_error ();
    }
  else
    {
      if (s >= (0xbfbfU << ((sizeof (int) - sizeof (short)) * 8)))
 link_error ();
    }
}

void
f15 (int s)
{
  if ((s & ((-0x1f8f) << ((sizeof (int) - sizeof (short)) * 8))) > ((-0x4fd0) << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s <= ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1))
 link_error ();
    }
  else
    {
      if (s > ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1))
 link_error ();
    }
}

void
f16 (int s)
{
  if ((s & ((-0x1f8f) << ((sizeof (int) - sizeof (short)) * 8))) >= ((-0x4fd0) << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s <= ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1))
 link_error ();
    }
  else
    {
      if (s > ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1))
 link_error ();
    }
}

void
f17 (int s)
{
  if ((s & ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1)) != -2147483647 - 1)
    {
      if (s == -2147483647 - 1)
 link_error ();
    }
  else
    {
      if (s >= (-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) - 1)
 link_error ();
    }
}

void
f18 (int s)
{
  if ((s & ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1)) != ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1))
    {
      if (s == -1)
 link_error ();
    }
  else
    {
      if (s < ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1) || s >= 0)
 link_error ();
    }
}

void
f19 (int s)
{
  if ((s & ((-0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1)) != ((0x4000 << ((sizeof (int) - sizeof (short)) * 8)) | 1))
    {
      if (s == 2147483647)
 link_error ();
    }
  else
    {
      if (s <= (0x4000 << ((sizeof (int) - sizeof (short)) * 8)))
 link_error ();
    }
}

void
f20 (int s)
{
  if ((s & (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))) != -2147483647 - 1)
    {
      if (s < (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)))
 link_error ();
    }
  else
    {
      if (s >= (-0x7000 << ((sizeof (int) - sizeof (short)) * 8)))
 link_error ();
    }
}

void
f21 (int s)
{
  if ((s & (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))) != (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s >= (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) && s < 0)
 link_error ();
    }
  else
    {
      if (s < (-0x1000 << ((sizeof (int) - sizeof (short)) * 8)) || s >= 0)
 link_error ();
    }
}

void
f22 (int s)
{
  if ((s & (-0x1000 << ((sizeof (int) - sizeof (short)) * 8))) != (0x7000 << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (s >= (0x7000 << ((sizeof (int) - sizeof (short)) * 8)))
 link_error ();
    }
  else
    {
      if (s < (0x7000 << ((sizeof (int) - sizeof (short)) * 8)))
 link_error ();
    }
}

void
f23 (unsigned int s)
{
  if ((s & (0xf000U << ((sizeof (int) - sizeof (short)) * 8))) != (0x7000 << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (
   s == (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s == 2147483647)
 link_error ();
    }
  else
    {
      if (s < (0x7000 << ((sizeof (int) - sizeof (short)) * 8)) || s >= (0x8000U << ((sizeof (int) - sizeof (short)) * 8)))
 link_error ();
    }
}

void
f24 (unsigned int s)
{
  if ((s & (0xf000U << ((sizeof (int) - sizeof (short)) * 8))) != (0x8000U << ((sizeof (int) - sizeof (short)) * 8)))
    {
      if (
   s == (0x8000U << ((sizeof (int) - sizeof (short)) * 8)) || s == (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) - 1)
 link_error ();
    }
  else
    {
      if (s >= (0x9000U << ((sizeof (int) - sizeof (short)) * 8)) || s < (0x8000U << ((sizeof (int) - sizeof (short)) * 8)))
 link_error ();
    }
}

int
main ()
{
  return 0;
}
