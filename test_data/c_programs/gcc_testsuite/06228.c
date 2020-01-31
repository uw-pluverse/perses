





extern void abort ();

typedef unsigned int myint __attribute__((aligned(1)));

unsigned int
foo (myint *p)
{
  return *p;
}




struct blah
{
  char c;
  myint i[8];
};

struct blah g;

int
main (int argc, char **argv)
{
  int i, k;
  for (k = 0; k < 8; k++)
    {
      g.i[k] = (int) 0xdeadbeef;
      i = foo (&g.i[k]);

      if (i != (int) 0xdeadbeef)
 abort ();
    }
  return 0;
}
