






extern void abort (void);
typedef long unsigned int size_t;
extern char *strncat (char *, const char *, size_t);
extern char *strcpy (char *, const char *);
extern void *memset (void *, int, size_t);
extern int memcmp (const void *, const void *, size_t);
int x = 123;





void
main_test (void)
{
  const char *const s1 = "hello world";
  const char *const s2 = "";
  char dst[64], *d2;

  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (strncat (dst, "", 100) != dst || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (strncat (dst, s2, 100) != dst || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strncat (++d2, s2, 100) != dst+1 || d2 != dst+1
      || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strncat (++d2+5, s2, 100) != dst+6 || d2 != dst+1
      || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strncat (++d2+5, s1+11, 100) != dst+6 || d2 != dst+1
      || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strncat (++d2+5, s1, 0) != dst+6 || d2 != dst+1
      || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strncat (++d2+5, "", ++x) != dst+6 || d2 != dst+1 || x != 124
      || memcmp (dst, "hello world\0XXX", 15))
    abort();

  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (strncat (dst, "foo", 3) != dst || memcmp (dst, "hello worldfoo\0XXX", 18))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (strncat (dst, "foo", 100) != dst || memcmp (dst, "hello worldfoo\0XXX", 18))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (strncat (dst, s1, 100) != dst || memcmp (dst, "hello worldhello world\0XXX", 26))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strncat (++d2, s1, 100) != dst+1 || d2 != dst+1
      || memcmp (dst, "hello worldhello world\0XXX", 26))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strncat (++d2+5, s1, 100) != dst+6 || d2 != dst+1
      || memcmp (dst, "hello worldhello world\0XXX", 26))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strncat (++d2+5, s1+5, 100) != dst+6 || d2 != dst+1
      || memcmp (dst, "hello world world\0XXX", 21))
    abort();



  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (__builtin_strncat (dst, "", 100) != dst
      || memcmp (dst, "hello world\0XXX", 15))
    abort();
}
