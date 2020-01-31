


extern void * foo (void);
void * foo (void) { return (void *)foo; }

extern void * foo (void) __attribute__((weak));
