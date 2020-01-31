long unsigned int f1(void) {
  return __builtin_wasm_current_memory();
}
long unsigned int f2(long unsigned int delta) {
  return __builtin_wasm_grow_memory(delta);
}
