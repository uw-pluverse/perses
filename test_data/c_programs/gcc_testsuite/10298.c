int
foo ()
{
  int i, bits;
  for (i = 1, bits = 1; i > 0; i += i)
    ++bits;
  return bits - sizeof(int) * 8;
}
