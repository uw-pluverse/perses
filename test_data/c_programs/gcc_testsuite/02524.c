






extern void abort (void);
extern char *strrchr (const char *, int);
extern char *rindex (const char *, int);

char *bar = "hi world";
int x = 7;

void
main_test (void)
{
  const char *const foo = "hello world";

  if (strrchr (foo, 'x'))
    abort ();
  if (strrchr (foo, 'o') != foo + 7)
    abort ();
  if (strrchr (foo, 'e') != foo + 1)
    abort ();
  if (strrchr (foo + 3, 'e'))
    abort ();
  if (strrchr (foo, '\0') != foo + 11)
    abort ();
  if (strrchr (bar, '\0') != bar + 8)
    abort ();
  if (strrchr (bar + 4, '\0') != bar + 8)
    abort ();
  if (strrchr (bar + (x++ & 3), '\0') != bar + 8)
    abort ();
  if (x != 8)
    abort ();


  if (rindex ("hello", 'z') != 0)
    abort ();



  if (__builtin_strrchr (foo, 'o') != foo + 7)
    abort ();
  if (__builtin_rindex (foo, 'o') != foo + 7)
    abort ();
}
