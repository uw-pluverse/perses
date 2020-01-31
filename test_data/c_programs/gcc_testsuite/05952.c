


unsigned int
foo (unsigned int eax)
{
  eax |= 4;
  eax &= 247;
  eax |= 16;
  eax &= 223;
  eax |= 64;
  eax &= 127;
  return eax;
}
