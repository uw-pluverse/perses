extern void abort (void);
typedef long unsigned int size_t;
extern int memcmp (const void *, const void *, size_t);
extern char *strcpy (char *, const char *);
extern void link_error (void);

void
main_test (void)
{
  char str[8];

  strcpy (str, "3141");

  if ( memcmp (str, str+2, 0) != 0 )
    abort ();
  if ( memcmp (str+1, str+3, 0) != 0 )
    abort ();

  if ( memcmp (str+1, str+3, 1) != 0 )
    abort ();
  if ( memcmp (str, str+2, 1) >= 0 )
    abort ();
  if ( memcmp (str+2, str, 1) <= 0 )
    abort ();

  if (memcmp ("abcd", "efgh", 4) >= 0)
    link_error ();
  if (memcmp ("abcd", "abcd", 4) != 0)
    link_error ();
  if (memcmp ("efgh", "abcd", 4) <= 0)
    link_error ();
}
