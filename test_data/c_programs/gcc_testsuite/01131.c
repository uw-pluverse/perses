





unsigned int too_big (unsigned int *p)
{
  return *(p + 0x400);
}

unsigned int small_enough (unsigned int *p)
{
  return *(p + 0x100);
}
