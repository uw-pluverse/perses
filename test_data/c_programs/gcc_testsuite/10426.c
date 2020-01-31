





typedef union { union w *u; int *i; } H __attribute__ ((transparent_union));
void (*h) (H);
void g (int *s) { h (s); }
