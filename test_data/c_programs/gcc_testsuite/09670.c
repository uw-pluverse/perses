




extern void bar (int);
extern void baz (int) __attribute__((noreturn));

void
foo (int k)
{
  int i;
 for (i = 0; i < 10; ++i)
    bar (i);
 for (i = 0; i < 10; ++i)
    bar (i);
 for (i = 0; i < 10; ++i)
    bar (i);
  if (k)
 for (i = 0; i < 10; ++i)
      baz (i);
 for (i = 0; i < 10; ++i)
    bar (i);
}
