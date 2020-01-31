



void foo (void);
void (*fp) (void);
char x[sizeof (1, foo) == sizeof (fp) ? 1 : -1];
