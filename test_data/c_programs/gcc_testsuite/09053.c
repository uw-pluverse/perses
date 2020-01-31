







extern void *memset(void *s, int c, long unsigned int n);

struct S1 { int i; };

struct S2
{
  int ver;
  struct S1 s;
};

static __thread struct S2 m;

void init(void)
{
  memset(&m.s, 0, sizeof(m.s));
}
