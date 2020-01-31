



typedef long unsigned int size_t;
extern void *memcpy (void *, const void *, size_t);

void
cpy128 (void *x, void *y)
{
  memcpy (x, y, 128);
}
