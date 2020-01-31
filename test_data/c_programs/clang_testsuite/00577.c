typedef int _Atomic_word;
_Atomic_word exchange_and_add(volatile _Atomic_word *__mem, int __val) {
  return __atomic_fetch_add(__mem, __val, 4);
}
