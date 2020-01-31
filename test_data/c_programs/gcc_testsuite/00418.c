



typedef struct bar {
  void *a;
  void *b;
} TYPE;

void foo (TYPE *p, TYPE *q) { *p = *q; }
