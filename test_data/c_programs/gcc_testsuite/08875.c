





extern void abort ();

typedef unsigned int myint __attribute__((aligned(1)));

void
foo (myint *p, unsigned int i)
{
  *p = i;
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
  int k;

  for (k = 0; k < 8; k++)
    {
      foo (&g.i[k], (int) 0xdeadbeef);
      if (g.i[k] != (int) 0xdeadbeef)
 abort ();
    }
  return 0;
}
