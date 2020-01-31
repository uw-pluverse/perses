volatile int i;

void c1 () __attribute__((constructor));
void c1 () { ++i; }

void d1 () __attribute__((destructor));
void d1 () { --i; }
