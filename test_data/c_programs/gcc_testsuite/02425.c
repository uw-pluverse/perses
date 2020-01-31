typedef long unsigned int size_t;
extern void abort (void);
extern char *strstr (const char *, const char *)
  __asm ("" "my_strstr");

const char *p = "rld", *q = "hello world";

void
main_test (void)
{
  const char *const foo = "hello world";

  if (strstr (foo, "") != foo)
    abort ();
  if (strstr (foo + 4, "") != foo + 4)
    abort ();
  if (strstr (foo, "h") != foo)
    abort ();
  if (strstr (foo, "w") != foo + 6)
    abort ();
  if (strstr (foo + 6, "o") != foo + 7)
    abort ();
  if (strstr (foo + 1, "world") != foo + 6)
    abort ();
  if (strstr (foo + 2, p) != foo + 8)
    abort ();
  if (strstr (q, "") != q)
    abort ();
  if (strstr (q + 1, "o") != q + 4)
    abort ();



  if (__builtin_strstr (foo + 1, "world") != foo + 6)
    abort ();
}
