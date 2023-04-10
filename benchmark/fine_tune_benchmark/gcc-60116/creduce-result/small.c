int printf(const char *, ...);
short a, b, c, g;
int d, i;
unsigned e = 3;
long long f, h;
short j() { return a && b; }
int main() {
  int k;
  h = 0;
  c = 0;
  for (; c <= 3; c++) {
    g = j();
    k = ~(g != 0) + h && 7;
    if (e)
      d = f = k;
    else
      i = k;
  }
  printf("%d\n", d);
  return 0;
}
