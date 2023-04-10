struct a {
  signed b : 18;
};
int c, d, e;
void f() {
  struct a g;
  g.b = e;
  int h = d && g.b, i = g.b | -(5 && g.b) - h;
  c = i;
}
int main() {}
