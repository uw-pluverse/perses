struct my_s {
  unsigned long a[18];
};
void foo(unsigned long *t) {
  *(struct my_s *)t = *((struct my_s *)(1UL));
}
