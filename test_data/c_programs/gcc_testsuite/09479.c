



unsigned foo (unsigned a, unsigned b)
{
  return (a & 0xff00) != (b & 0xff00);
}

unsigned bar (unsigned c, unsigned d)
{
  return (c & 0xff00) == (d & 0xff00);
}
