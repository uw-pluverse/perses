long test1(long *p) {
  return _InterlockedIncrement(p);
}
long test2(long *p) {
  return _InterlockedDecrement(p);
}
