


int min_test(long a, long b, long c) {
  int cmp1 = a < b;
  int cmp2 = a < c;
  return cmp1 & cmp2;
}

int max_test (long a, long b, long c) {
  int cmp1 = a > b;
  int cmp2 = a > c;
  return cmp1 & cmp2;
}
