


struct thing
{
  union
  {
    int raw;
    struct
    {
      unsigned a : 1;
      unsigned b : 1;
    };
  };
};

extern void func (int);

void
blah ()
{
  struct thing xx;
  xx.a = xx.b = 1;
  func (xx.raw);
}
