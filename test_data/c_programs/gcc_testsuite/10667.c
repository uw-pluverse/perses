





void func(int n) {
  static int __thread v = 0;
  int i;
  for (i = 0; i < n; ++i) {
    volatile int *p = &v;
    volatile int x __attribute__ ((unused)) = *p;
  }
}

int main(int argc, char **argv) {
  func(argc);
  return 0;
}
