int printf(const char*, ...);

int main (int argc, char *argv[]) {
  int a = 1;
  int b = a + 1;
  if (b > a) {
    printf("hello\n");
    printf("world\n");
  }
  return 0;
}
