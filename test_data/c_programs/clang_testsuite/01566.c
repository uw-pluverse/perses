void __attribute__((annotate("foo"))) foo(float *a) {
  __attribute__((annotate("bar"))) int x;
  __attribute__((annotate(1))) int y;
  __attribute__((annotate("bar", 1))) int z;
  int u = __builtin_annotation(z, (char*) 0);
  int v = __builtin_annotation(z, (char*) L"bar");
  int w = __builtin_annotation(z, "foo");
  float b = __builtin_annotation(*a, "foo");
}
