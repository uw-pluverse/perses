int cnt;

void
bar (int i)
{
  cnt += i;
}

void
foo (int i)
{
  if (!i)
    bar (0);
  else
    {
      static int varz = 5;
      goto f1;
    }
  bar (1);
f1:
  bar (2);
}

int
main (void)
{
  foo (0);
  foo (1);
  return 0;
}
