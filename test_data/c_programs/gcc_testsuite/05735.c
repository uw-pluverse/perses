



int funsigned (unsigned a)
{
  return 0x1ffffffffL / a == 0;
}

int funsigned2 (unsigned a)
{
  if (a < 1) return 1;
  return (-1 * 0x1ffffffffL) / a == 0;
}
