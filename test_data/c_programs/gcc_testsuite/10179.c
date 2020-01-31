



void
foo (void)
{
  unsigned i;
  unsigned *p = 0;
  for (i = 0; i < 4; ++i)
    *p++ = 0;
  for (i = 0; i < 4; ++i)
    *p++ = 0;
}

void
bar (void)
{
  unsigned i;
  unsigned *p = (unsigned *) (long unsigned int) 0x12340000;
  for (i = 0; i < 4; ++i)
    *p++ = 0;
  for (i = 0; i < 4; ++i)
    *p++ = 0;
}
