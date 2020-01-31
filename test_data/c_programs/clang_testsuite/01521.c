void b1 (void) { for (void (*f) (void);;); }
void b2 (void) { for (void f (void);;); }
void b3 (void) { for (static int f;;); }
void b4 (void) { for (typedef int f;;); }
