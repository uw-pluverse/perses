






extern void abort (void);
typedef long unsigned int size_t;
extern int strncmp (const char *, const char *, size_t);

void
main_test (void)
{
  const char *const s1 = "hello world";
  const char *s2, *s3;

  if (strncmp (s1, "hello world", 12) != 0)
    abort();
  if (strncmp ("hello world", s1, 12) != 0)
    abort();
  if (strncmp ("hello", "hello", 6) != 0)
    abort();
  if (strncmp ("hello", "hello", 2) != 0)
    abort();
  if (strncmp ("hello", "hello", 100) != 0)
    abort();
  if (strncmp (s1+10, "d", 100) != 0)
    abort();
  if (strncmp (10+s1, "d", 100) != 0)
    abort();
  if (strncmp ("d", s1+10, 1) != 0)
    abort();
  if (strncmp ("d", 10+s1, 1) != 0)
    abort();
  if (strncmp ("hello", "aaaaa", 100) <= 0)
    abort();
  if (strncmp ("aaaaa", "hello", 100) >= 0)
    abort();
  if (strncmp ("hello", "aaaaa", 1) <= 0)
    abort();
  if (strncmp ("aaaaa", "hello", 1) >= 0)
    abort();

  s2 = s1; s3 = s1+4;
  if (strncmp (++s2, ++s3, 0) != 0 || s2 != s1+1 || s3 != s1+5)
    abort();
  s2 = s1;
  if (strncmp (++s2, "", 1) <= 0 || s2 != s1+1)
    abort();
  if (strncmp ("", ++s2, 1) >= 0 || s2 != s1+2)
    abort();
  if (strncmp (++s2, "", 100) <= 0 || s2 != s1+3)
    abort();
  if (strncmp ("", ++s2, 100) >= 0 || s2 != s1+4)
    abort();
  if (strncmp (++s2+6, "", 100) != 0 || s2 != s1+5)
    abort();
  if (strncmp ("", ++s2+5, 100) != 0 || s2 != s1+6)
    abort();
  if (strncmp ("ozz", ++s2, 1) != 0 || s2 != s1+7)
    abort();
  if (strncmp (++s2, "rzz", 1) != 0 || s2 != s1+8)
    abort();
  s2 = s1; s3 = s1+4;
  if (strncmp (++s2, ++s3+2, 1) >= 0 || s2 != s1+1 || s3 != s1+5)
    abort();



  if (__builtin_strncmp ("hello", "a", 100) <= 0)
    abort();
}
