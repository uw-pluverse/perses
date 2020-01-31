






extern void abort (void);
typedef long unsigned int size_t;
extern void *memchr (const void *, int, size_t);

void
main_test (void)
{
  const char* const foo1 = "hello world";

  if (memchr (foo1, 'x', 11))
    abort ();
  if (memchr (foo1, 'o', 11) != foo1 + 4)
    abort ();
  if (memchr (foo1, 'w', 2))
    abort ();
  if (memchr (foo1 + 5, 'o', 6) != foo1 + 7)
    abort ();
  if (memchr (foo1, 'd', 11) != foo1 + 10)
    abort ();
  if (memchr (foo1, 'd', 10))
    abort ();
  if (memchr (foo1, '\0', 11))
    abort ();
  if (memchr (foo1, '\0', 12) != foo1 + 11)
    abort ();



  if (__builtin_memchr (foo1, 'r', 11) != foo1 + 8)
    abort ();
}
