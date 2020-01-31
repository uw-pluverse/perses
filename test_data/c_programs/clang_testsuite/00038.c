typedef unsigned int uint32_t;
typedef enum memory_order {
  memory_order_relaxed = 0,
  memory_order_consume = 1,
  memory_order_acquire = 2,
  memory_order_release = 3,
  memory_order_acq_rel = 4,
  memory_order_seq_cst = 5
} memory_order;
void clang_analyzer_eval(int);
struct RefCountedStruct {
  uint32_t refCount;
  void *ptr;
};
void test_atomic_fetch_add(struct RefCountedStruct *s) {
  s->refCount = 1;
  uint32_t result = __c11_atomic_fetch_add((volatile _Atomic(uint32_t) *)&s->refCount,- 1, memory_order_relaxed);
  clang_analyzer_eval(s->refCount == 1);
  clang_analyzer_eval(result == 1);
}
void test_atomic_load(struct RefCountedStruct *s) {
  s->refCount = 1;
  uint32_t result = __c11_atomic_load((volatile _Atomic(uint32_t) *)&s->refCount, memory_order_relaxed);
  clang_analyzer_eval(s->refCount == 1);
  clang_analyzer_eval(result == 1);
}
void test_atomic_store(struct RefCountedStruct *s) {
  s->refCount = 1;
  __c11_atomic_store((volatile _Atomic(uint32_t) *)&s->refCount, 2, memory_order_relaxed);
  clang_analyzer_eval(s->refCount == 1);
}
void test_atomic_exchange(struct RefCountedStruct *s) {
  s->refCount = 1;
  uint32_t result = __c11_atomic_exchange((volatile _Atomic(uint32_t) *)&s->refCount, 2, memory_order_relaxed);
  clang_analyzer_eval(s->refCount == 1);
  clang_analyzer_eval(result == 1);
}
void test_atomic_compare_exchange_strong(struct RefCountedStruct *s) {
  s->refCount = 1;
  uint32_t expected = 2;
  uint32_t desired = 3;
  _Bool result = __c11_atomic_compare_exchange_strong((volatile _Atomic(uint32_t) *)&s->refCount, &expected, desired, memory_order_relaxed, memory_order_relaxed);
  clang_analyzer_eval(s->refCount == 3);
  clang_analyzer_eval(expected == 2);
}
void test_atomic_compare_exchange_weak(struct RefCountedStruct *s) {
  s->refCount = 1;
  uint32_t expected = 2;
  uint32_t desired = 3;
  _Bool result = __c11_atomic_compare_exchange_weak((volatile _Atomic(uint32_t) *)&s->refCount, &expected, desired, memory_order_relaxed, memory_order_relaxed);
  clang_analyzer_eval(s->refCount == 3);
  clang_analyzer_eval(expected == 2);
}
