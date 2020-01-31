



extern void link_error (void);

void
foo (unsigned int s)
{
  if (s + 0x70000000 < 0xf0000000U)
    {
      if (s >= 0x80000000U && s < 0x90000000U)
 link_error ();
    }
}

void
bar (unsigned int s)
{
  if (s + 0x70000000 >= 0xf0000000U)
    {
      if (s < 0x80000000U || s >= 0x90000000U)
 link_error ();
    }
}
