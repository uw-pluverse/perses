extern bar(void *);
void f(void *cd) {
  bar(((void *)((unsigned long)(cd) ^ -1)));
}
