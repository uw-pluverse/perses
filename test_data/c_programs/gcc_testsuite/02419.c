



struct A
{
  int t;
  int i;
};

struct B
{
  int *p;
  float b;
};

float X;

foo (struct B b, struct A *q, float *h)
{
  X += *h;
  *(b.p) = 3;
  q->t = 2;
  return *(b.p);
}

main()
{
  struct A a;
  struct B b;

  b.p = &a.t;
  if (foo (b, &a, &X) == 3)
    abort ();

  return 0;
}
