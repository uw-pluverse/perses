int f(int a, int b) {
  return a + b;
}
int g(int a) {
  return a + 1;
}
int main() {
  return f(2, g(2));
}
