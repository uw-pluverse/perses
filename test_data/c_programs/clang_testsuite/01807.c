int g(int a) {
  return a;
}
int f(int a) {
  if (1 && g(a))
    return 1;
  return 0;
}
