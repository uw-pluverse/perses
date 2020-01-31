



struct S
{
  int i;
  void (*f)(struct S *);
  unsigned u;
};

struct U
{
  struct U *next;
  struct S s;
  short a[8];
};

extern void non_existent(struct S *p, int);

static void hooray1 (struct S *p)
{
  non_existent (p, 1);
}

static __attribute__ ((noinline))
void hiphip1 (struct S *p)
{
  p->f (p);
}

int test1 (void)
{
  struct S s;
  s.i = 1234;
  s.f = hooray1;
  s.u = 1001;
  hiphip1 (&s);
  return 0;
}
