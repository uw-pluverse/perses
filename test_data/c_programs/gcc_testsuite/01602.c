



struct S
{
  void *s[256];
};

struct T
{
  long t[23];
  struct S *u;
};

extern struct T __attribute__((model (small))) v;

void *
foo (void)
{
  return v.u->s[0];
}
