extern int f(int);
extern int g(int);
int test(int a, int b) {
  int res;
  if (a==2) {
    int r = f(b);
    res = r + b;
    a += 2;
  } else {
    int r = f(a);
    res = r + a;
    b += 1;
  }
  return res;
}
