


int
foo (unsigned char a, _Bool b)
{
  return (!a & a) | (b & !b);
}
