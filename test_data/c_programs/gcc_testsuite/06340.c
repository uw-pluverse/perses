


unsigned res;

void
foo (unsigned code, int len)
{
  int i;
  for (i = 0; i < len; i++)
    res |= code & 1;
}
