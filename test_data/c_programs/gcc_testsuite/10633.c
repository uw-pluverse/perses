



unsigned long modify_field (unsigned long mask, long fieldval)
{
  return (~fieldval & ~mask);
}
