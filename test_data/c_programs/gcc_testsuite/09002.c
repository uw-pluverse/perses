


char c[4] __attribute__ ((aligned (4)));

struct S {
  char c1;
  char c2;
  char c3;
  char c4;
};

int f1 (void)
{
  return 3 & (long unsigned int)&c[1];
}

int f2 (void)
{
  return 3 & (long unsigned int)&((struct S *)&c)->c2;
}
