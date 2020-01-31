int x;
typedef void* (*fn_t)(long a, long b, char *f, int c);
fn_t ABC __attribute__ ((nocommon));
int y __attribute__((common));
