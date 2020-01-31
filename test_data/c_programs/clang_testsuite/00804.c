void foo() {
  int a;
  __builtin_prefetch(&a);
  __builtin_prefetch(&a, 1);
  __builtin_prefetch(&a, 1, 2);
  __builtin_prefetch(&a, 1, 9, 3);
  __builtin_prefetch(&a, "hello", 2);
  __builtin_prefetch(&a, a, 2);
  __builtin_prefetch(&a, 2);
  __builtin_prefetch(&a, 0, 4);
  __builtin_prefetch(&a, -1, 4);
}
