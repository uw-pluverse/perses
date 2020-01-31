


extern int* f(int) __attribute__((returns_nonnull));
extern void eliminate ();
void g () {
  if (f (2) == 0)
    eliminate ();
}
void h () {
  int *p = f (2);
  if (p == 0)
    eliminate ();
}
