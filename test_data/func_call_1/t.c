int printf(const char*, ...);

int add(int a, int b) {
  return a + b;
}

void print(int v) {
  if (add(v, v) == 2) {
    printf("he");
  } else if (add(v, v) == 4) {
    printf("llo");
  } else {
    printf("cannot be here.");
  }
}

int main (int argc, char *argv[]) {
  (1, 2, 3);
  print(1);
  print(2);
  printf("\n");
  return 0;
}
