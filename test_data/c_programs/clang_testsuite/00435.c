struct s0 {
  int a;
};
static struct s0 g0;
static int f0(void) {
  return g0.a;
}
static struct s0 g0 = {3};
void *g1 = f0;
