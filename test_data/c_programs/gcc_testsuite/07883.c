







int foo(int n) {
  int i, ret = 0;
  for (i = 0; i < n; i++) {
    if (i % 10 == 1)
      ret++;
    else
      ret--;
  }
  return ret;
}
