int printf(const char*, ...);

void fun() {
  int a = 1;
  int b = a + 1;
  printf("%d\n", b);
  printf("hello\n");
  printf("world\n");
}

int main (int argc, char *argv[]) {
  fun();
  return 0;
}
