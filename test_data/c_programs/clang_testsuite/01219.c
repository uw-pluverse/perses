int arr[6] = {1, 2, 3, 4, 5, 6};
void f(void) {
  for (int i = 0; i < 6; ++i) {
    (void)arr[i];
  }
}
