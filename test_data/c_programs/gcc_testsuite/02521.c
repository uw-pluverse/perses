






extern void abort (void);
extern char *strchr (const char *, int);
extern char *index (const char *, int);

void
main_test (void)
{
  const char *const foo = "hello world";

  if (strchr (foo, 'x'))
    abort ();
  if (strchr (foo, 'o') != foo + 4)
    abort ();
  if (strchr (foo + 5, 'o') != foo + 7)
    abort ();
  if (strchr (foo, '\0') != foo + 11)
    abort ();


  if (index ("hello", 'z') != 0)
    abort ();



  if (__builtin_strchr (foo, 'o') != foo + 4)
    abort ();
  if (__builtin_index (foo, 'o') != foo + 4)
    abort ();
}
