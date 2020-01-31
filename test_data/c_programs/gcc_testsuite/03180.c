

extern void f (char *);

void foo (char *s)
{
  f (__builtin_stpcpy (s, "hi"));
}

void bar (char *s)
{
  f (__builtin_mempcpy (s, "hi", 3));
}
