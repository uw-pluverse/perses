

struct stuff
{
    int a;
    int b;
    int c;
    int d;
    int e;
    char *f;
    int g;
};

void __attribute__ ((noinline))
bar (struct stuff *x)
{
  if (x->g != 2)
    __builtin_abort ();
}

int
main (int argc, char** argv)
{
  struct stuff x = {0, 0, 0, 0, 0, 0, 0};
  x.a = 100;
  x.d = 100;
  x.g = 2;

  bar (&x);
  return 0;
}
