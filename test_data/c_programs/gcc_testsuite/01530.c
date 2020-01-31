


struct X
{
  int c;
};

extern void bar(struct X *);

void foo ()
{
  struct X x;
  bar (&x);
  bar (&x);
  bar (&x);
}
