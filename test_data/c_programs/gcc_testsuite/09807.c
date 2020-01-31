


void f(void) __attribute__((interrupt_handler));
void g(void) { }
void f(void) { g(); }
