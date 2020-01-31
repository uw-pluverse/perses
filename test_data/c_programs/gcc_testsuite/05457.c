







struct f {
  int i;
};

int
foo (struct f *p)
{
  if (p != 0)
    if (&p->i != 0)
      return 123;
  return 0;
}
