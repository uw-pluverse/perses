



void fn (const char *, const char *) __attribute__ ((__noreturn__));
int var;

inline void
foo (void)
{
  if (__builtin_expect (var != 0, 0))
    fn ("a", "b");
};

void
bar (void)
{
  foo ();
};

void
baz (void)
{
  foo ();
};
