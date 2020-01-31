


struct S {
  int i;
};

extern struct S foo (void);
extern int foo2 (void);

struct S s;

int bar (int c) {
  int r;

  if (c)
    {
      s = foo ();
      r = foo2 ();
    }
  else
    {
      s = foo ();
      r = foo2 ();
    }

  return r;
}
