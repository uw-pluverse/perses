struct foo {
  int big[128];
};
struct bar {
  char c[3];
};
struct bar smallThing;
struct foo bigThing;
_Atomic(struct foo) bigAtomic;
void structAtomicStore() {
  struct foo f = {0};
  __c11_atomic_store(&bigAtomic, f, 5);
  struct bar b = {0};
  __atomic_store(&smallThing, &b, 5);
  __atomic_store(&bigThing, &f, 5);
}
void structAtomicLoad() {
  struct foo f = __c11_atomic_load(&bigAtomic, 5);
  struct bar b;
  __atomic_load(&smallThing, &b, 5);
  __atomic_load(&bigThing, &f, 5);
}
