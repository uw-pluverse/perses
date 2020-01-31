



static inline int foo () { return 0; }
static int bar () __attribute__ ((alias ("foo")));
int main () { return bar (); }
