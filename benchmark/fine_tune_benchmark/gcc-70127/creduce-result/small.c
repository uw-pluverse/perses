struct a {
  int b;
  signed c : 2;
} e[1];
int d;
int main() {
  struct a f = {8, 6};
  for (; d <= 1; d++)
    f = e[0] = f;
  printf("%d\n", e[0].c);
  return 0;
}
