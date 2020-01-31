



struct S
{
  int i:8;
};

void bar (struct S, int);

void
foo (struct S s, int i)
{
  s.i = i;
  bar (s, i);
}
