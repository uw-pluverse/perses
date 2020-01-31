



struct S {
  int i;
};

int
main (void)
{
  struct S **s = 0;
  return (*s)->i;
}
