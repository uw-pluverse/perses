int foo(int x, int y) __attribute__((always_inline));
int foo(int x, int y) { return x + y; }
int sum = 0;
void bar(int x) {
  sum += foo(x, x - 2);
}
int main(int argc, const char *argv[]) {
  for (int i = 0; i < 30; i++)
    bar(argc);
  return sum;
}
