struct a {
  signed b : 18;
  signed c : 1;
};
int d, e;
static int f = -5L;
int g(h) { return h; }
int main() {
  struct a i = {7};
  i.c = g(5);
  i.c = d = e % (~f / i.c);
  i.c;
}
