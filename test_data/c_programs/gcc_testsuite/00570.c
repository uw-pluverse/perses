extern void abort(void);

typedef unsigned long long uint64_t;
typedef unsigned int size_t;


void to_octal (uint64_t value, char *where, size_t size)
{
  uint64_t v = value;
  size_t i = size;

  do
    {
      where[--i] = '0' + (v & ((1 << 3) - 1));
      v >>= 3;
    }
  while (i);
}


int main (void)
{
  char buf[8];

  to_octal(010644, buf, 6);

  if (buf[1] != '1')
     abort();

  return 0;
}
