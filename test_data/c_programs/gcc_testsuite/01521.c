


void *memcpy (void *dest, const void *src, unsigned int n);

void foo (char *dst, int i)
{
  memcpy (dst, &i, sizeof (i));
}
