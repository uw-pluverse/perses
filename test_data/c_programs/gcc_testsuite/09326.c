





static inline int xyzzy0 (int);
static int xyzzy0 (int x) { return x; }
int test0 (void)
{
  return xyzzy0 (5);
}


static int xyzzy1 (int);
static inline int xyzzy1 (int x) { return x; }
int test1 (void)
{
  return xyzzy1 (5);
}


extern inline int xyzzy2 (int x) { return x; }
int test2 (void)
{
  extern int xyzzy2 (int);
  return xyzzy2 (5);
}
