typedef __typeof__(sizeof(int)) size_t;
extern void *malloc(size_t);
extern void free(void *ptr);
void *malloc(unsigned long s);
struct table {
  int nentry;
  unsigned *table;
  unsigned offset_max;
};
static int table_build(struct table *t) {
  t->nentry = ((t->offset_max >> 2) + 31) / 32;
  t->table = (unsigned *)malloc(sizeof(unsigned) * t->nentry);
  int n;
  n = 10000;
  int *p = malloc(sizeof(int) * n);
  free(p);
  return t->nentry;
}
static int table_build_1(struct table *t) {
  t->nentry = (sizeof(struct table) * 2 + 31) / 32;
  t->table = (unsigned *)malloc(sizeof(unsigned) * t->nentry);
  return t->nentry;
}
void *f(int n) {
  return malloc(n * 0 * sizeof(int));
}
