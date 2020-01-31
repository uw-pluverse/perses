



typedef int T __attribute__((may_alias));
typedef unsigned int U __attribute__((may_alias));

void
foo (void *p)
{
  T *a = (int *) p;
  int *b = (T *) p;
  U *c = (unsigned int *) p;
  unsigned int *d = (U *) p;
  (void) a;
  (void) b;
  (void) c;
  (void) d;
}
