


struct S {
  int i;
};

extern struct S foo (void);
extern int foo2 (void);

struct S s, s2;

int bar (int c) {
  int r;

  if (c)
    {
      s = foo ();
      r = foo2 ();
    }
  else
    {
      s2 = foo ();
      r = foo2 ();
    }

  return r;
}
