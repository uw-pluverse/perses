


int
foo (long a, unsigned long b)
{
  return (a & (a == 0)) | (b & !b);
}
