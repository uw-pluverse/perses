


struct f
{
  int i;
};

int g(int i, int c, struct f *ff, int g)
{
  int *t;
  if (c)
    t = &i;
  else
    t = &ff->i;
  return *t;
}
