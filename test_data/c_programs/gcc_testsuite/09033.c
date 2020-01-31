





struct foo
{
  int i;
  long l;
};

struct foo f0 = { 0, 0 };
static struct foo f1 = { 0, 0 };

void
testfunc1 ()
{
  struct foo f3 = { 0, 0 };
  static struct foo f4 = { 0, 0 };

  f3 = f4;

  __extension__ ({
    struct foo f5 = { 0, 0 };
    f5.i = 0;
  });

  {
    struct foo f6 = { 0, 0 };
    f6.i = 0;
  }
}


struct foo f7 = { 0, 0 };
static struct foo f8 = { 0, 0 };

void
testfunc2 ()
{
  struct foo f9 = { 0, 0 };
  static struct foo f10 = { 0, 0 };

  f9 = f10;
}
