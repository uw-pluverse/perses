


int
foo (int align)
{
  int off = 0 % align;
  return off ? align - off : 0;
}
