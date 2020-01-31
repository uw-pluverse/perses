




static __thread int xyzzy __attribute__ ((tls_model ("initial-exec")));
int foo(void) { return xyzzy; }
