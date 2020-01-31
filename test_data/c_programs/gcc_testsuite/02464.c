






extern int inside_main;
extern void abort (void);
typedef long unsigned int size_t;
extern char *strcat (char *, const char *);
extern char *strcpy (char *, const char *);
extern void *memset (void *, int, size_t);
extern int memcmp (const void *, const void *, size_t);



void main_test (void)
{
  const char *const s1 = "hello world";
  const char *const s2 = "";
  char dst[64], *d2;

  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (strcat (dst, "") != dst || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (strcat (dst, s2) != dst || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strcat (++d2, s2) != dst+1 || d2 != dst+1
      || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strcat (++d2+5, s2) != dst+6 || d2 != dst+1
      || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strcat (++d2+5, s1+11) != dst+6 || d2 != dst+1
      || memcmp (dst, "hello world\0XXX", 15))
    abort();
  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (strcat (dst, " 1111") != dst
      || memcmp (dst, "hello world 1111\0XXX", 20))
    abort();

  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (strcat (dst+5, " 2222") != dst+5
      || memcmp (dst, "hello world 2222\0XXX", 20))
    abort();

  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0); d2 = dst;
  if (strcat (++d2+5, " 3333") != dst+6 || d2 != dst+1
      || memcmp (dst, "hello world 3333\0XXX", 20))
    abort();

  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  strcat (strcat (strcat (strcat (strcat (strcat (dst, ": this "), ""),
      "is "), "a "), "test"), ".");
  if (memcmp (dst, "hello world: this is a test.\0X", 30))
    abort();


  inside_main = 1;




  do { memset (dst, 'X', sizeof (dst)); strcpy (dst, (s1)); } while (0);
  if (__builtin_strcat (dst, "") != dst || memcmp (dst, "hello world\0XXX", 15))
    abort();
}
