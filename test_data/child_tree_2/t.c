int printf(const char*, ...);

int main (int argc, char *argv[]) {
  int a = 1;
  int b = a + 1;
  if (b <= a) {
    printf("dead\n");
  } else {
    while(a + 2 > a + 1) {
      if (b <= a) {
        printf("dead\n");
      } else {
        printf("hello\n");
        printf("world\n");
      }
      break;
    }
  }
  return 0;
}
