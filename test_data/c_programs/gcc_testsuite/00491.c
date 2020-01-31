typedef long unsigned int size_t;

size_t strlen(const char *);

char s[100] __attribute__ ((aligned (8)));

size_t
strlen8(void)
{
  return strlen(s);
}
