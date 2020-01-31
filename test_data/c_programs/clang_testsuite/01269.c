int g1 = 1;
int volatile g2 = 2;
static void toggle(int t) {
  if (t & 1)
    g1 *= t;
  else
    g2 *= t;
}
int main() {
  int i;
  toggle(g1);
  toggle(g2);
  return 0;
}
