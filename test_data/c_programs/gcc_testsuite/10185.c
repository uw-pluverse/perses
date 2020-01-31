




int __foo (void);
int __bar (void);

struct baz
{
  int *newp;
};

int
get_ice (int *op, struct baz *ret)
{
  int *tmpp;
  int c;
  c = (__foo () != 1);
  if (__bar ())
    {
      return (1);
    }
  if (c)
    tmpp = op;
  if (tmpp)
    {
    }
  else if (c)
    {
      ret->newp = tmpp;
    }
}
