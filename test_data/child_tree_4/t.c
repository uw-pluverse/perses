int printf(const char*, ...);

int main() {
  int a = 1;
  {
    int b = a + 1;
    {
      int c = b + 1;
      {
        printf("c=%d\n", c);
      }
    }
  }
  return 0;
}
