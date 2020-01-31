int printf(const char*, ...);

int add(int a, int b) {
  return a + b;
}

void print(int v) {
  if (add(add(v, v), add(v, v)) > 0) {
    printf("he");
  } else if (add(v, v) == 0) {
    printf("llo");
  } else {
    printf("cannot be here.");
  }
}

int main (int argc, char *argv[]) {
  (1, 2, 3);
  print(1);
  print(0);
  printf("\n");
  return 0;
}
