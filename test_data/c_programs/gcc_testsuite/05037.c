





void bar (unsigned);

void foo (void)
{
  unsigned i, a;

  for (i = 0; i < 5; i++)
    a = i * i;

  bar (a);
}
