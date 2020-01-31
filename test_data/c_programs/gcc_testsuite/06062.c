


extern void eliminate (void);
extern void* f1 (void *a, void *b) __attribute__((nonnull));
extern void* f2 (void *a, void *b) __attribute__((nonnull(2)));
void g1 (void*p, void*q){
  f1 (q, p);
  if (p == 0)
    eliminate ();
}
void g2 (void*p, void*q){
  f2 (q, p);
  if (p == 0)
    eliminate ();
}
