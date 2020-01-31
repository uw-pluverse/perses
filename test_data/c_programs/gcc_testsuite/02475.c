





typedef long unsigned int size_t;

extern void abort (void);
extern char *strcpy (char *, const char *);
extern char *stpcpy (char *, const char *);
extern int memcmp (const void *, const void *, size_t);

extern int inside_main;

const char s1[] = "123";
char p[32] = "";
char *s2 = "defg";
char *s3 = "FGH";
size_t l1 = 1;

void
main_test (void)
{
  int i = 8;







  if (stpcpy (p, "abcde") != p + 5 || memcmp (p, "abcde", 6))
    abort ();
  if (stpcpy (p + 16, "vwxyz" + 1) != p + 16 + 4 || memcmp (p + 16, "wxyz", 5))
    abort ();
  if (stpcpy (p + 1, "") != p + 1 + 0 || memcmp (p, "a\0cde", 6))
    abort ();
  if (stpcpy (p + 3, "fghij") != p + 3 + 5 || memcmp (p, "a\0cfghij", 9))
    abort ();

  if (stpcpy ((i++, p + 20 + 1), "23") != (p + 20 + 1 + 2)
      || i != 9 || memcmp (p + 19, "z\0""23\0", 5))
    abort ();

  if (stpcpy (stpcpy (p, "ABCD"), "EFG") != p + 7 || memcmp (p, "ABCDEFG", 8))
    abort();



  if (__builtin_stpcpy (p, "abcde") != p + 5 || memcmp (p, "abcde", 6))
    abort ();



  inside_main = 1;
  stpcpy (p + 3, s3);
  if (memcmp (p, "abcFGH", 6))
    abort ();
}
