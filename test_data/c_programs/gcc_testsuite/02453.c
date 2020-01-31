extern void abort (void);
extern long unsigned int strlen (const char *);
extern char *strcpy (char *, const char *);

int x = 6;

void
main_test(void)
{
  const char *const foo = "hello world";
  char str[8];
  char *ptr;

  if (strlen (foo) != 11)
    abort ();
  if (strlen (foo + 4) != 7)
    abort ();
  if (strlen (foo + (x++ & 7)) != 5)
    abort ();
  if (x != 7)
    abort ();

  ptr = str;
  ptr[0] = 'n'; ptr[1] = 't'; ptr[2] = 's'; ptr[3] = '\0';
  if (strlen (ptr) == 0)
    abort ();

  ptr[0] = 'n'; ptr[1] = 't'; ptr[2] = 's'; ptr[3] = '\0';
  if (strlen (ptr) < 1)
    abort ();

  ptr[0] = 'n'; ptr[1] = 't'; ptr[2] = 's'; ptr[3] = '\0';
  if (strlen (ptr) <= 0)
    abort ();

  ptr[0] = 'n'; ptr[1] = 't'; ptr[2] = 's'; ptr[3] = '\0';
  if (strlen (ptr+3) != 0)
    abort ();

  ptr[0] = 'n'; ptr[1] = 't'; ptr[2] = 's'; ptr[3] = '\0';
  if (strlen (ptr+3) > 0)
    abort ();

  ptr[0] = 'n'; ptr[1] = 't'; ptr[2] = 's'; ptr[3] = '\0';
  if (strlen (str+3) >= 1)
    abort ();



  if (__builtin_strlen (foo) != 11)
    abort ();
}
