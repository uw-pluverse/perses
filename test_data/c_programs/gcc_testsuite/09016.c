


extern void *memcpy (void *, const void *, long unsigned int);






float fx; char fy[sizeof (fx)] __attribute__((aligned (__alignof__ (fx)))); void f (void) { memcpy (&fx, &fy, sizeof (fx)); };
double dx; char dy[sizeof (dx)] __attribute__((aligned (__alignof__ (dx)))); void d (void) { memcpy (&dx, &dy, sizeof (dx)); };
long double ldx; char ldy[sizeof (ldx)] __attribute__((aligned (__alignof__ (ldx)))); void ld (void) { memcpy (&ldx, &ldy, sizeof (ldx)); };
_Complex float cfx; char cfy[sizeof (cfx)] __attribute__((aligned (__alignof__ (cfx)))); void cf (void) { memcpy (&cfx, &cfy, sizeof (cfx)); };
_Complex double cdx; char cdy[sizeof (cdx)] __attribute__((aligned (__alignof__ (cdx)))); void cd (void) { memcpy (&cdx, &cdy, sizeof (cdx)); };
_Complex long double cldx; char cldy[sizeof (cldx)] __attribute__((aligned (__alignof__ (cldx)))); void cld (void) { memcpy (&cldx, &cldy, sizeof (cldx)); };
float __attribute__((vector_size (8))) d8fx; char d8fy[sizeof (d8fx)] __attribute__((aligned (__alignof__ (d8fx)))); void d8f (void) { memcpy (&d8fx, &d8fy, sizeof (d8fx)); };
float __attribute__((vector_size (16))) d16fx; char d16fy[sizeof (d16fx)] __attribute__((aligned (__alignof__ (d16fx)))); void d16f (void) { memcpy (&d16fx, &d16fy, sizeof (d16fx)); };
float __attribute__((vector_size (32))) d32fx; char d32fy[sizeof (d32fx)] __attribute__((aligned (__alignof__ (d32fx)))); void d32f (void) { memcpy (&d32fx, &d32fy, sizeof (d32fx)); };
float __attribute__((vector_size (64))) d64fx; char d64fy[sizeof (d64fx)] __attribute__((aligned (__alignof__ (d64fx)))); void d64f (void) { memcpy (&d64fx, &d64fy, sizeof (d64fx)); };
float __attribute__((vector_size (128))) d128fx; char d128fy[sizeof (d128fx)] __attribute__((aligned (__alignof__ (d128fx)))); void d128f (void) { memcpy (&d128fx, &d128fy, sizeof (d128fx)); };
double __attribute__((vector_size (16))) d16dx; char d16dy[sizeof (d16dx)] __attribute__((aligned (__alignof__ (d16dx)))); void d16d (void) { memcpy (&d16dx, &d16dy, sizeof (d16dx)); };
double __attribute__((vector_size (32))) d32dx; char d32dy[sizeof (d32dx)] __attribute__((aligned (__alignof__ (d32dx)))); void d32d (void) { memcpy (&d32dx, &d32dy, sizeof (d32dx)); };
double __attribute__((vector_size (64))) d64dx; char d64dy[sizeof (d64dx)] __attribute__((aligned (__alignof__ (d64dx)))); void d64d (void) { memcpy (&d64dx, &d64dy, sizeof (d64dx)); };
double __attribute__((vector_size (128))) d128dx; char d128dy[sizeof (d128dx)] __attribute__((aligned (__alignof__ (d128dx)))); void d128d (void) { memcpy (&d128dx, &d128dy, sizeof (d128dx)); };
