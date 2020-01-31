int __attribute__((constructor)) foo(void) {
  return 0;
}
void __attribute__((constructor)) bar(void) {}
