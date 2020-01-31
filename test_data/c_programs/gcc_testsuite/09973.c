extern void abort (void);

extern int fails;


typedef struct { char c; double d; } Scd;
typedef struct { char c; double d; char b; } Scdc;
typedef struct { double d; } Sd;
typedef struct { double d; int i; } Sdi;
typedef struct { char c; Sd sd; } Scsds;
typedef struct { char c; Sd sd; char b; } Scsdsc;
typedef struct { char c; Sdi sdi; } Scsdis;
typedef struct { char c; Sdi sdi; char b; } Scsdisc;
typedef struct { Sd sd; } Ssds;
typedef struct { Sd sd; char c; } Ssdsc;
typedef struct { char c; Ssds ssds; } Scssdss;
typedef struct { char c; Ssds ssds; char b; } Scssdssc;

typedef struct { float f; int i; } Sfi;
typedef struct { float f; int i1; int i2; } Sfii;
typedef struct { float f; int i; Sfi fi; } Sfifi;
typedef struct { float f; int i1; int i2; Sfii fii; } Sfiifii;


void checkScd (Scd x, int i)
{ if (x.c != (char)i || x.d != (double)i+1) abort (); }
void checkScdc (Scdc x, int i)
{ if (x.c != (char)i || x.d != (double)i+1 || x.b != (char)i+2) abort (); }
void checkSd (Sd x, int i)
{ if (x.d != (double)i) abort (); }
void checkSdi (Sdi x, int i)
{ if (x.d != (double)i || x.i != i+1) abort (); }
void checkScsds (Scsds x, int i)
{ if (x.c != (char)i || x.sd.d != (double)i+1) abort (); }
void checkScsdsc (Scsdsc x, int i)
{ if (x.c != (char)i || x.sd.d != (double)i+1 || x.b != (char)i+2) abort (); }
void checkScsdis (Scsdis x, int i)
{ if (x.c != (char)i || x.sdi.d != (double)i+1 || x.sdi.i != i+2) abort (); }
void checkScsdisc (Scsdisc x, int i)
{ if (x.c != (char)i || x.sdi.d != (double)i+1 || x.sdi.i != i+2
    || x.b != (char)i+3) abort (); }
void checkSsds (Ssds x, int i)
{ if (x.sd.d != (double)i) abort (); }
void checkSsdsc (Ssdsc x, int i)
{ if (x.sd.d != (double)i || x.c != (char)i+1) abort (); }
void checkScssdss (Scssdss x, int i)
{ if (x.c != (char)i || x.ssds.sd.d != (double)i+1) abort (); }
void checkScssdssc (Scssdssc x, int i)
{ if (x.c != (char)i || x.ssds.sd.d != (double)i+1
    || x.b != (char)i+2) abort (); }

void checkSfi (Sfi x, int i)
{ if (x.f != (float)i || x.i != i+1) abort (); }
void checkSfii (Sfii x, int i)
{ if (x.f != (float)i || x.i1 != i+1 || x.i2 != i+2) abort (); }
void checkSfifi (Sfifi x, int i)
{ if (x.fi.f != (float)i || x.fi.i != i+1) abort (); }
void checkSfiifii (Sfiifii x, int i)
{ if (x.fii.f != (float)i || x.fii.i1 != i+1 || x.fii.i2 != i+2) abort (); }

Sfi g1sSfi, g2sSfi, g3sSfi, g4sSfi; Sfi g5sSfi, g6sSfi, g7sSfi, g8sSfi; Sfi g9sSfi, g10sSfi, g11sSfi, g12sSfi; Sfi g13sSfi, g14sSfi, g15sSfi, g16sSfi; extern void initSfi (Sfi *p, int i); extern void checkgSfi (void); extern void testSfi (Sfi s1, Sfi s2, Sfi s3, Sfi s4, Sfi s5, Sfi s6, Sfi s7, Sfi s8, Sfi s9, Sfi s10, Sfi s11, Sfi s12, Sfi s13, Sfi s14, Sfi s15, Sfi s16); extern void testvaSfi (int n, ...); void test2_Sfi (Sfi s1, Sfi s2, Sfi s3, Sfi s4, Sfi s5, Sfi s6, Sfi s7, Sfi s8) { testSfi (s1, g2sSfi, s2, g4sSfi, s3, g6sSfi, s4, g8sSfi, s5, g10sSfi, s6, g12sSfi, s7, g14sSfi, s8, g16sSfi); } void testitSfi (void) { ; ; initSfi ( &g1sSfi, 1); initSfi ( &g2sSfi, 2); initSfi ( &g3sSfi, 3); initSfi ( &g4sSfi, 4); initSfi ( &g5sSfi, 5); initSfi ( &g6sSfi, 6); initSfi ( &g7sSfi, 7); initSfi ( &g8sSfi, 8); initSfi ( &g9sSfi, 9); initSfi (&g10sSfi, 10); initSfi (&g11sSfi, 11); initSfi (&g12sSfi, 12); initSfi (&g13sSfi, 13); initSfi (&g14sSfi, 14); initSfi (&g15sSfi, 15); initSfi (&g16sSfi, 16); checkgSfi (); ; ; ; testSfi (g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi, g8sSfi, g9sSfi, g10sSfi, g11sSfi, g12sSfi, g13sSfi, g14sSfi, g15sSfi, g16sSfi); ; ; ; ; testvaSfi (1, g1sSfi); ; testvaSfi (2, g1sSfi, g2sSfi); ; testvaSfi (3, g1sSfi, g2sSfi, g3sSfi); ; testvaSfi (4, g1sSfi, g2sSfi, g3sSfi, g4sSfi); ; testvaSfi (5, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi); ; testvaSfi (6, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi); ; testvaSfi (7, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi); ; testvaSfi (8, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi, g8sSfi); ; testvaSfi (9, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi, g8sSfi, g9sSfi); ; testvaSfi (10, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi, g8sSfi, g9sSfi, g10sSfi); ; testvaSfi (11, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi, g8sSfi, g9sSfi, g10sSfi, g11sSfi); ; testvaSfi (12, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi, g8sSfi, g9sSfi, g10sSfi, g11sSfi, g12sSfi); ; testvaSfi (13, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi, g8sSfi, g9sSfi, g10sSfi, g11sSfi, g12sSfi, g13sSfi); ; testvaSfi (14, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi, g8sSfi, g9sSfi, g10sSfi, g11sSfi, g12sSfi, g13sSfi, g14sSfi); ; testvaSfi (15, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi, g8sSfi, g9sSfi, g10sSfi, g11sSfi, g12sSfi, g13sSfi, g14sSfi, g15sSfi); ; testvaSfi (16, g1sSfi, g2sSfi, g3sSfi, g4sSfi, g5sSfi, g6sSfi, g7sSfi, g8sSfi, g9sSfi, g10sSfi, g11sSfi, g12sSfi, g13sSfi, g14sSfi, g15sSfi, g16sSfi); ; ; ; test2_Sfi (g1sSfi, g3sSfi, g5sSfi, g7sSfi, g9sSfi, g11sSfi, g13sSfi, g15sSfi); ; }
Sfii g1sSfii, g2sSfii, g3sSfii, g4sSfii; Sfii g5sSfii, g6sSfii, g7sSfii, g8sSfii; Sfii g9sSfii, g10sSfii, g11sSfii, g12sSfii; Sfii g13sSfii, g14sSfii, g15sSfii, g16sSfii; extern void initSfii (Sfii *p, int i); extern void checkgSfii (void); extern void testSfii (Sfii s1, Sfii s2, Sfii s3, Sfii s4, Sfii s5, Sfii s6, Sfii s7, Sfii s8, Sfii s9, Sfii s10, Sfii s11, Sfii s12, Sfii s13, Sfii s14, Sfii s15, Sfii s16); extern void testvaSfii (int n, ...); void test2_Sfii (Sfii s1, Sfii s2, Sfii s3, Sfii s4, Sfii s5, Sfii s6, Sfii s7, Sfii s8) { testSfii (s1, g2sSfii, s2, g4sSfii, s3, g6sSfii, s4, g8sSfii, s5, g10sSfii, s6, g12sSfii, s7, g14sSfii, s8, g16sSfii); } void testitSfii (void) { ; ; initSfii ( &g1sSfii, 1); initSfii ( &g2sSfii, 2); initSfii ( &g3sSfii, 3); initSfii ( &g4sSfii, 4); initSfii ( &g5sSfii, 5); initSfii ( &g6sSfii, 6); initSfii ( &g7sSfii, 7); initSfii ( &g8sSfii, 8); initSfii ( &g9sSfii, 9); initSfii (&g10sSfii, 10); initSfii (&g11sSfii, 11); initSfii (&g12sSfii, 12); initSfii (&g13sSfii, 13); initSfii (&g14sSfii, 14); initSfii (&g15sSfii, 15); initSfii (&g16sSfii, 16); checkgSfii (); ; ; ; testSfii (g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii, g8sSfii, g9sSfii, g10sSfii, g11sSfii, g12sSfii, g13sSfii, g14sSfii, g15sSfii, g16sSfii); ; ; ; ; testvaSfii (1, g1sSfii); ; testvaSfii (2, g1sSfii, g2sSfii); ; testvaSfii (3, g1sSfii, g2sSfii, g3sSfii); ; testvaSfii (4, g1sSfii, g2sSfii, g3sSfii, g4sSfii); ; testvaSfii (5, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii); ; testvaSfii (6, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii); ; testvaSfii (7, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii); ; testvaSfii (8, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii, g8sSfii); ; testvaSfii (9, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii, g8sSfii, g9sSfii); ; testvaSfii (10, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii, g8sSfii, g9sSfii, g10sSfii); ; testvaSfii (11, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii, g8sSfii, g9sSfii, g10sSfii, g11sSfii); ; testvaSfii (12, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii, g8sSfii, g9sSfii, g10sSfii, g11sSfii, g12sSfii); ; testvaSfii (13, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii, g8sSfii, g9sSfii, g10sSfii, g11sSfii, g12sSfii, g13sSfii); ; testvaSfii (14, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii, g8sSfii, g9sSfii, g10sSfii, g11sSfii, g12sSfii, g13sSfii, g14sSfii); ; testvaSfii (15, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii, g8sSfii, g9sSfii, g10sSfii, g11sSfii, g12sSfii, g13sSfii, g14sSfii, g15sSfii); ; testvaSfii (16, g1sSfii, g2sSfii, g3sSfii, g4sSfii, g5sSfii, g6sSfii, g7sSfii, g8sSfii, g9sSfii, g10sSfii, g11sSfii, g12sSfii, g13sSfii, g14sSfii, g15sSfii, g16sSfii); ; ; ; test2_Sfii (g1sSfii, g3sSfii, g5sSfii, g7sSfii, g9sSfii, g11sSfii, g13sSfii, g15sSfii); ; }
Sfifi g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi; Sfifi g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi; Sfifi g9sSfifi, g10sSfifi, g11sSfifi, g12sSfifi; Sfifi g13sSfifi, g14sSfifi, g15sSfifi, g16sSfifi; extern void initSfifi (Sfifi *p, int i); extern void checkgSfifi (void); extern void testSfifi (Sfifi s1, Sfifi s2, Sfifi s3, Sfifi s4, Sfifi s5, Sfifi s6, Sfifi s7, Sfifi s8, Sfifi s9, Sfifi s10, Sfifi s11, Sfifi s12, Sfifi s13, Sfifi s14, Sfifi s15, Sfifi s16); extern void testvaSfifi (int n, ...); void test2_Sfifi (Sfifi s1, Sfifi s2, Sfifi s3, Sfifi s4, Sfifi s5, Sfifi s6, Sfifi s7, Sfifi s8) { testSfifi (s1, g2sSfifi, s2, g4sSfifi, s3, g6sSfifi, s4, g8sSfifi, s5, g10sSfifi, s6, g12sSfifi, s7, g14sSfifi, s8, g16sSfifi); } void testitSfifi (void) { ; ; initSfifi ( &g1sSfifi, 1); initSfifi ( &g2sSfifi, 2); initSfifi ( &g3sSfifi, 3); initSfifi ( &g4sSfifi, 4); initSfifi ( &g5sSfifi, 5); initSfifi ( &g6sSfifi, 6); initSfifi ( &g7sSfifi, 7); initSfifi ( &g8sSfifi, 8); initSfifi ( &g9sSfifi, 9); initSfifi (&g10sSfifi, 10); initSfifi (&g11sSfifi, 11); initSfifi (&g12sSfifi, 12); initSfifi (&g13sSfifi, 13); initSfifi (&g14sSfifi, 14); initSfifi (&g15sSfifi, 15); initSfifi (&g16sSfifi, 16); checkgSfifi (); ; ; ; testSfifi (g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi, g9sSfifi, g10sSfifi, g11sSfifi, g12sSfifi, g13sSfifi, g14sSfifi, g15sSfifi, g16sSfifi); ; ; ; ; testvaSfifi (1, g1sSfifi); ; testvaSfifi (2, g1sSfifi, g2sSfifi); ; testvaSfifi (3, g1sSfifi, g2sSfifi, g3sSfifi); ; testvaSfifi (4, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi); ; testvaSfifi (5, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi); ; testvaSfifi (6, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi); ; testvaSfifi (7, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi); ; testvaSfifi (8, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi); ; testvaSfifi (9, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi, g9sSfifi); ; testvaSfifi (10, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi, g9sSfifi, g10sSfifi); ; testvaSfifi (11, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi, g9sSfifi, g10sSfifi, g11sSfifi); ; testvaSfifi (12, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi, g9sSfifi, g10sSfifi, g11sSfifi, g12sSfifi); ; testvaSfifi (13, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi, g9sSfifi, g10sSfifi, g11sSfifi, g12sSfifi, g13sSfifi); ; testvaSfifi (14, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi, g9sSfifi, g10sSfifi, g11sSfifi, g12sSfifi, g13sSfifi, g14sSfifi); ; testvaSfifi (15, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi, g9sSfifi, g10sSfifi, g11sSfifi, g12sSfifi, g13sSfifi, g14sSfifi, g15sSfifi); ; testvaSfifi (16, g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi, g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi, g9sSfifi, g10sSfifi, g11sSfifi, g12sSfifi, g13sSfifi, g14sSfifi, g15sSfifi, g16sSfifi); ; ; ; test2_Sfifi (g1sSfifi, g3sSfifi, g5sSfifi, g7sSfifi, g9sSfifi, g11sSfifi, g13sSfifi, g15sSfifi); ; }
Sfiifii g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii; Sfiifii g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii; Sfiifii g9sSfiifii, g10sSfiifii, g11sSfiifii, g12sSfiifii; Sfiifii g13sSfiifii, g14sSfiifii, g15sSfiifii, g16sSfiifii; extern void initSfiifii (Sfiifii *p, int i); extern void checkgSfiifii (void); extern void testSfiifii (Sfiifii s1, Sfiifii s2, Sfiifii s3, Sfiifii s4, Sfiifii s5, Sfiifii s6, Sfiifii s7, Sfiifii s8, Sfiifii s9, Sfiifii s10, Sfiifii s11, Sfiifii s12, Sfiifii s13, Sfiifii s14, Sfiifii s15, Sfiifii s16); extern void testvaSfiifii (int n, ...); void test2_Sfiifii (Sfiifii s1, Sfiifii s2, Sfiifii s3, Sfiifii s4, Sfiifii s5, Sfiifii s6, Sfiifii s7, Sfiifii s8) { testSfiifii (s1, g2sSfiifii, s2, g4sSfiifii, s3, g6sSfiifii, s4, g8sSfiifii, s5, g10sSfiifii, s6, g12sSfiifii, s7, g14sSfiifii, s8, g16sSfiifii); } void testitSfiifii (void) { ; ; initSfiifii ( &g1sSfiifii, 1); initSfiifii ( &g2sSfiifii, 2); initSfiifii ( &g3sSfiifii, 3); initSfiifii ( &g4sSfiifii, 4); initSfiifii ( &g5sSfiifii, 5); initSfiifii ( &g6sSfiifii, 6); initSfiifii ( &g7sSfiifii, 7); initSfiifii ( &g8sSfiifii, 8); initSfiifii ( &g9sSfiifii, 9); initSfiifii (&g10sSfiifii, 10); initSfiifii (&g11sSfiifii, 11); initSfiifii (&g12sSfiifii, 12); initSfiifii (&g13sSfiifii, 13); initSfiifii (&g14sSfiifii, 14); initSfiifii (&g15sSfiifii, 15); initSfiifii (&g16sSfiifii, 16); checkgSfiifii (); ; ; ; testSfiifii (g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii, g9sSfiifii, g10sSfiifii, g11sSfiifii, g12sSfiifii, g13sSfiifii, g14sSfiifii, g15sSfiifii, g16sSfiifii); ; ; ; ; testvaSfiifii (1, g1sSfiifii); ; testvaSfiifii (2, g1sSfiifii, g2sSfiifii); ; testvaSfiifii (3, g1sSfiifii, g2sSfiifii, g3sSfiifii); ; testvaSfiifii (4, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii); ; testvaSfiifii (5, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii); ; testvaSfiifii (6, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii); ; testvaSfiifii (7, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii); ; testvaSfiifii (8, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii); ; testvaSfiifii (9, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii, g9sSfiifii); ; testvaSfiifii (10, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii, g9sSfiifii, g10sSfiifii); ; testvaSfiifii (11, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii, g9sSfiifii, g10sSfiifii, g11sSfiifii); ; testvaSfiifii (12, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii, g9sSfiifii, g10sSfiifii, g11sSfiifii, g12sSfiifii); ; testvaSfiifii (13, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii, g9sSfiifii, g10sSfiifii, g11sSfiifii, g12sSfiifii, g13sSfiifii); ; testvaSfiifii (14, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii, g9sSfiifii, g10sSfiifii, g11sSfiifii, g12sSfiifii, g13sSfiifii, g14sSfiifii); ; testvaSfiifii (15, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii, g9sSfiifii, g10sSfiifii, g11sSfiifii, g12sSfiifii, g13sSfiifii, g14sSfiifii, g15sSfiifii); ; testvaSfiifii (16, g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii, g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii, g9sSfiifii, g10sSfiifii, g11sSfiifii, g12sSfiifii, g13sSfiifii, g14sSfiifii, g15sSfiifii, g16sSfiifii); ; ; ; test2_Sfiifii (g1sSfiifii, g3sSfiifii, g5sSfiifii, g7sSfiifii, g9sSfiifii, g11sSfiifii, g13sSfiifii, g15sSfiifii); ; }



void
struct_by_value_21_x ()
{




testitSfi ();
testitSfii ();
testitSfifi ();
testitSfiifii ();



if (fails != 0)
  abort ();


}
