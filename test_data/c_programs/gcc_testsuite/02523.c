






extern void abort (void);
typedef long unsigned int size_t;
extern size_t strspn (const char *, const char *);
extern char *strcpy (char *, const char *);

void
main_test (void)
{
  const char *const s1 = "hello world";
  char dst[64], *d2;

  if (strspn (s1, "hello") != 5)
    abort();
  if (strspn (s1+4, "hello") != 1)
    abort();
  if (strspn (s1, "z") != 0)
    abort();
  if (strspn (s1, "hello world") != 11)
    abort();
  if (strspn (s1, "") != 0)
    abort();
  strcpy (dst, s1);
  if (strspn (dst, "") != 0)
    abort();
  strcpy (dst, s1); d2 = dst;
  if (strspn (++d2, "") != 0 || d2 != dst+1)
    abort();
  strcpy (dst, s1); d2 = dst;
  if (strspn (++d2+5, "") != 0 || d2 != dst+1)
    abort();
  if (strspn ("", s1) != 0)
    abort();
  strcpy (dst, s1);
  if (strspn ("", dst) != 0)
    abort();
  strcpy (dst, s1); d2 = dst;
  if (strspn ("", ++d2) != 0 || d2 != dst+1)
    abort();
  strcpy (dst, s1); d2 = dst;
  if (strspn ("", ++d2+5) != 0 || d2 != dst+1)
    abort();



  if (__builtin_strspn (s1, "hello") != 5)
    abort();
}
