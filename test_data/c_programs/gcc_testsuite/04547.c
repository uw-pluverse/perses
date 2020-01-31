


struct S
{
  unsigned long a[1];
  int l;
};

static inline unsigned long
fn (const struct S *s, int i)
{
  return s->a[i] << i;
}

int
main ()
{
  struct S s;
  fn (&s, 1);
}
