unsigned int foo(const unsigned int wvalue)
{
  const unsigned char type = (wvalue >> 8);
  unsigned int size = 0;

  if (type == 1)
  {
    size = 20;
  }
  return size;
}
