void *memcpy(void *dest, const void *src, unsigned int n);
void use_builtin_memcpy(void *dest, const void *src, unsigned int n) {
  __builtin_memcpy(dest, src, n);
}
void use_memcpy(void *dest, const void *src, unsigned int n) {
  memcpy(dest, src, n);
}
