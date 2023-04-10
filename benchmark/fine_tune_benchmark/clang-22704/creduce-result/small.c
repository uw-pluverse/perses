int a, b;
char c() {
  if (b)
    goto d;
  c();
  char e;
  return e;
d:
  a = 6;
  c();
  return 5;
}
int main() {}
