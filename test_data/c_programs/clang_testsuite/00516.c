struct foo {
  long long a;
  char b;
  int c:16;
  int d[16];
};
long long bar(int a, int b, int c, int d, int e,
              struct foo z) {
  return z.a;
}
