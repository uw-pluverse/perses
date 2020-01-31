






struct st {
  int a;
  int b;
  int c;
} __attribute__((aligned(16)));

int foo (struct st * s_p)
{
  return s_p->b;
}
