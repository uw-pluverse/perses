






extern void abort (void);
typedef long unsigned int size_t;
extern char *strncpy (char *, const char *, size_t);
extern int memcmp (const void *, const void *, size_t);
extern void *memset (void *, int, size_t);




int i;

void
main_test (void)
{
  const char *const src = "hello world";
  const char *src2;
  char dst[64], *dst2;

  memset(dst, 'X', sizeof(dst));
  if (strncpy (dst, src, 4) != dst || memcmp (dst, "hellXXX", 7))
    abort();

  memset(dst, 'X', sizeof(dst));
  if (strncpy (dst+16, src, 4) != dst+16 || memcmp (dst+16, "hellXXX", 7))
    abort();

  memset(dst, 'X', sizeof(dst));
  if (strncpy (dst+32, src+5, 4) != dst+32 || memcmp (dst+32, " worXXX", 7))
    abort();

  memset(dst, 'X', sizeof(dst));
  dst2 = dst;
  if (strncpy (++dst2, src+5, 4) != dst+1 || memcmp (dst2, " worXXX", 7)
      || dst2 != dst+1)
    abort();

  memset(dst, 'X', sizeof(dst));
  if (strncpy (dst, src, 0) != dst || memcmp (dst, "XXX", 3))
    abort();

  memset(dst, 'X', sizeof(dst));
  dst2 = dst; src2 = src;
  if (strncpy (++dst2, ++src2, 0) != dst+1 || memcmp (dst2, "XXX", 3)
      || dst2 != dst+1 || src2 != src+1)
    abort();

  memset(dst, 'X', sizeof(dst));
  dst2 = dst; src2 = src;
  if (strncpy (++dst2+5, ++src2+5, 0) != dst+6 || memcmp (dst2+5, "XXX", 3)
      || dst2 != dst+1 || src2 != src+1)
    abort();

  memset(dst, 'X', sizeof(dst));
  if (strncpy (dst, src, 12) != dst || memcmp (dst, "hello world\0XXX", 15))
    abort();



  memset(dst, 'X', sizeof(dst));
  if (__builtin_strncpy (dst, src, 4) != dst || memcmp (dst, "hellXXX", 7))
    abort();

  memset(dst, 'X', sizeof(dst));
  if (strncpy (dst, i++ ? "xfoo" + 1 : "bar", 4) != dst
      || memcmp (dst, "bar\0XXX", 7)
      || i != 1)
    abort ();
}
