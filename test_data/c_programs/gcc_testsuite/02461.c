






extern void abort (void);
typedef long unsigned int size_t;
extern size_t strcspn (const char *, const char *);
extern char *strcpy (char *, const char *);

void
main_test (void)
{
  const char *const s1 = "hello world";
  char dst[64], *d2;

  if (strcspn (s1, "hello") != 0)
    abort();
  if (strcspn (s1, "z") != 11)
    abort();
  if (strcspn (s1+4, "z") != 7)
    abort();
  if (strcspn (s1, "hello world") != 0)
    abort();
  if (strcspn (s1, "") != 11)
    abort();
  strcpy (dst, s1);
  if (strcspn (dst, "") != 11)
    abort();
  strcpy (dst, s1); d2 = dst;
  if (strcspn (++d2, "") != 10 || d2 != dst+1)
    abort();
  strcpy (dst, s1); d2 = dst;
  if (strcspn (++d2+5, "") != 5 || d2 != dst+1)
    abort();
  if (strcspn ("", s1) != 0)
    abort();
  strcpy (dst, s1);
  if (strcspn ("", dst) != 0)
    abort();
  strcpy (dst, s1); d2 = dst;
  if (strcspn ("", ++d2) != 0 || d2 != dst+1)
    abort();
  strcpy (dst, s1); d2 = dst;
  if (strcspn ("", ++d2+5) != 0 || d2 != dst+1)
    abort();



  if (__builtin_strcspn (s1, "z") != 11)
    abort();
}
