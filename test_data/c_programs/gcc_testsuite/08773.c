




typedef long unsigned int size_t;
extern void *memset (void *s, int c, size_t n)
  __attribute__ ((nothrow, nonnull (1)));
extern inline
__attribute__ ((always_inline, artificial, gnu_inline, nothrow))
void *
memset (void *dest, int ch, size_t len)
{
  return __builtin___memset_chk (dest, ch, len,
     __builtin_object_size (dest, 0));
}
static inline void
__attribute__ ((always_inline))
test3 (char *p)
{
  memset (p, 0, 6);
}

int
main (void)
{
  char buf[4];
  test3 (buf);
  return 0;
}
