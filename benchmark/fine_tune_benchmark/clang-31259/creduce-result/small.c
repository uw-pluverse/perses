int a, b, d, e, f, g;
int c[7][5][7] = {{8}, {{8}, 8}};
int main() {
  e = b = 1;
  for (; e < 5; e++)
    d = 6;
  for (; d >= 0; d--) {
    a--;
    c[1][b][d] = 0;
  }
  for (; f < 7; f++) {
    g = 0;
    for (; g < 5; g++)
      printf("%d\n", c[f][g][0]);
  }
  return 0;
}
