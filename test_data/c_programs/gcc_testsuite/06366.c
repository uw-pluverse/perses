

int i;
void *f1 (int) __attribute__((alloc_align (1)));
void *f2 (int, int, int) __attribute__((alloc_align (3)));
void *f3 (void) __attribute__((alloc_align));
void *f4 (int, int) __attribute__((alloc_align (1, 2)));
void *f5 (void) __attribute__((alloc_align (i)));
void *f6 (int) __attribute__((alloc_align (0)));
void *f7 (int) __attribute__((alloc_align (2)));
