



void
foo (unsigned int ui, int i)
{
  const unsigned char uc = 0;
  _Bool b;
  b = 0 != ~uc;
  b = 2 != ~uc;
  b = uc == ~uc;
  b = i == ui;
}
