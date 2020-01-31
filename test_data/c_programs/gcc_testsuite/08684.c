



struct S
{
  int a, b, c;
};

void *blah(int, void *);

static void __attribute__ ((noinline))
foo (struct S *p)
{
  int i, c = p->c;
  int b = p->b;
  void *v = (void *) p;

  for (i= 0; i< c; i++)
    v = blah(b + i, v);
}

static void __attribute__ ((noinline))
bar (struct S *p)
{
  foo (p);
}

void
entry1 (int c)
{
  struct S s;
  int i;

  for (i = 0; i<c; i++)
    {
      s.a = 1;
      s.b = 64;
      s.c = 32;
      bar (&s);
    }
  s.c = 2;
  bar (&s);
}

void
entry2 (int c)
{
  struct S s;
  int i;

  for (i = 0; i<c; i++)
    {
      s.a = 6;
      s.b = 64;
      s.c = 32;
      foo (&s);
    }
  s.c = 2;
  foo (&s);
}
