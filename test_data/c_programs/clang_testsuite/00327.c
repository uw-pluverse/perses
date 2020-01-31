void foo(int *P) {
  __builtin_prefetch(P);
  __builtin_prefetch(P, 1);
}
