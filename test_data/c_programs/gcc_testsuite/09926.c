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

Scd g1sScd, g2sScd, g3sScd, g4sScd; Scd g5sScd, g6sScd, g7sScd, g8sScd; Scd g9sScd, g10sScd, g11sScd, g12sScd; Scd g13sScd, g14sScd, g15sScd, g16sScd; extern void initScd (Scd *p, int i); extern void checkgScd (void); extern void testScd (Scd s1, Scd s2, Scd s3, Scd s4, Scd s5, Scd s6, Scd s7, Scd s8, Scd s9, Scd s10, Scd s11, Scd s12, Scd s13, Scd s14, Scd s15, Scd s16); extern void testvaScd (int n, ...); void test2_Scd (Scd s1, Scd s2, Scd s3, Scd s4, Scd s5, Scd s6, Scd s7, Scd s8) { testScd (s1, g2sScd, s2, g4sScd, s3, g6sScd, s4, g8sScd, s5, g10sScd, s6, g12sScd, s7, g14sScd, s8, g16sScd); } void testitScd (void) { ; ; initScd ( &g1sScd, 1); initScd ( &g2sScd, 2); initScd ( &g3sScd, 3); initScd ( &g4sScd, 4); initScd ( &g5sScd, 5); initScd ( &g6sScd, 6); initScd ( &g7sScd, 7); initScd ( &g8sScd, 8); initScd ( &g9sScd, 9); initScd (&g10sScd, 10); initScd (&g11sScd, 11); initScd (&g12sScd, 12); initScd (&g13sScd, 13); initScd (&g14sScd, 14); initScd (&g15sScd, 15); initScd (&g16sScd, 16); checkgScd (); ; ; ; testScd (g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd, g8sScd, g9sScd, g10sScd, g11sScd, g12sScd, g13sScd, g14sScd, g15sScd, g16sScd); ; ; ; ; testvaScd (1, g1sScd); ; testvaScd (2, g1sScd, g2sScd); ; testvaScd (3, g1sScd, g2sScd, g3sScd); ; testvaScd (4, g1sScd, g2sScd, g3sScd, g4sScd); ; testvaScd (5, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd); ; testvaScd (6, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd); ; testvaScd (7, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd); ; testvaScd (8, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd, g8sScd); ; testvaScd (9, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd, g8sScd, g9sScd); ; testvaScd (10, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd, g8sScd, g9sScd, g10sScd); ; testvaScd (11, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd, g8sScd, g9sScd, g10sScd, g11sScd); ; testvaScd (12, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd, g8sScd, g9sScd, g10sScd, g11sScd, g12sScd); ; testvaScd (13, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd, g8sScd, g9sScd, g10sScd, g11sScd, g12sScd, g13sScd); ; testvaScd (14, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd, g8sScd, g9sScd, g10sScd, g11sScd, g12sScd, g13sScd, g14sScd); ; testvaScd (15, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd, g8sScd, g9sScd, g10sScd, g11sScd, g12sScd, g13sScd, g14sScd, g15sScd); ; testvaScd (16, g1sScd, g2sScd, g3sScd, g4sScd, g5sScd, g6sScd, g7sScd, g8sScd, g9sScd, g10sScd, g11sScd, g12sScd, g13sScd, g14sScd, g15sScd, g16sScd); ; ; ; test2_Scd (g1sScd, g3sScd, g5sScd, g7sScd, g9sScd, g11sScd, g13sScd, g15sScd); ; }
Scsds g1sScsds, g2sScsds, g3sScsds, g4sScsds; Scsds g5sScsds, g6sScsds, g7sScsds, g8sScsds; Scsds g9sScsds, g10sScsds, g11sScsds, g12sScsds; Scsds g13sScsds, g14sScsds, g15sScsds, g16sScsds; extern void initScsds (Scsds *p, int i); extern void checkgScsds (void); extern void testScsds (Scsds s1, Scsds s2, Scsds s3, Scsds s4, Scsds s5, Scsds s6, Scsds s7, Scsds s8, Scsds s9, Scsds s10, Scsds s11, Scsds s12, Scsds s13, Scsds s14, Scsds s15, Scsds s16); extern void testvaScsds (int n, ...); void test2_Scsds (Scsds s1, Scsds s2, Scsds s3, Scsds s4, Scsds s5, Scsds s6, Scsds s7, Scsds s8) { testScsds (s1, g2sScsds, s2, g4sScsds, s3, g6sScsds, s4, g8sScsds, s5, g10sScsds, s6, g12sScsds, s7, g14sScsds, s8, g16sScsds); } void testitScsds (void) { ; ; initScsds ( &g1sScsds, 1); initScsds ( &g2sScsds, 2); initScsds ( &g3sScsds, 3); initScsds ( &g4sScsds, 4); initScsds ( &g5sScsds, 5); initScsds ( &g6sScsds, 6); initScsds ( &g7sScsds, 7); initScsds ( &g8sScsds, 8); initScsds ( &g9sScsds, 9); initScsds (&g10sScsds, 10); initScsds (&g11sScsds, 11); initScsds (&g12sScsds, 12); initScsds (&g13sScsds, 13); initScsds (&g14sScsds, 14); initScsds (&g15sScsds, 15); initScsds (&g16sScsds, 16); checkgScsds (); ; ; ; testScsds (g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds, g8sScsds, g9sScsds, g10sScsds, g11sScsds, g12sScsds, g13sScsds, g14sScsds, g15sScsds, g16sScsds); ; ; ; ; testvaScsds (1, g1sScsds); ; testvaScsds (2, g1sScsds, g2sScsds); ; testvaScsds (3, g1sScsds, g2sScsds, g3sScsds); ; testvaScsds (4, g1sScsds, g2sScsds, g3sScsds, g4sScsds); ; testvaScsds (5, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds); ; testvaScsds (6, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds); ; testvaScsds (7, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds); ; testvaScsds (8, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds, g8sScsds); ; testvaScsds (9, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds, g8sScsds, g9sScsds); ; testvaScsds (10, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds, g8sScsds, g9sScsds, g10sScsds); ; testvaScsds (11, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds, g8sScsds, g9sScsds, g10sScsds, g11sScsds); ; testvaScsds (12, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds, g8sScsds, g9sScsds, g10sScsds, g11sScsds, g12sScsds); ; testvaScsds (13, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds, g8sScsds, g9sScsds, g10sScsds, g11sScsds, g12sScsds, g13sScsds); ; testvaScsds (14, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds, g8sScsds, g9sScsds, g10sScsds, g11sScsds, g12sScsds, g13sScsds, g14sScsds); ; testvaScsds (15, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds, g8sScsds, g9sScsds, g10sScsds, g11sScsds, g12sScsds, g13sScsds, g14sScsds, g15sScsds); ; testvaScsds (16, g1sScsds, g2sScsds, g3sScsds, g4sScsds, g5sScsds, g6sScsds, g7sScsds, g8sScsds, g9sScsds, g10sScsds, g11sScsds, g12sScsds, g13sScsds, g14sScsds, g15sScsds, g16sScsds); ; ; ; test2_Scsds (g1sScsds, g3sScsds, g5sScsds, g7sScsds, g9sScsds, g11sScsds, g13sScsds, g15sScsds); ; }
Scssdss g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss; Scssdss g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss; Scssdss g9sScssdss, g10sScssdss, g11sScssdss, g12sScssdss; Scssdss g13sScssdss, g14sScssdss, g15sScssdss, g16sScssdss; extern void initScssdss (Scssdss *p, int i); extern void checkgScssdss (void); extern void testScssdss (Scssdss s1, Scssdss s2, Scssdss s3, Scssdss s4, Scssdss s5, Scssdss s6, Scssdss s7, Scssdss s8, Scssdss s9, Scssdss s10, Scssdss s11, Scssdss s12, Scssdss s13, Scssdss s14, Scssdss s15, Scssdss s16); extern void testvaScssdss (int n, ...); void test2_Scssdss (Scssdss s1, Scssdss s2, Scssdss s3, Scssdss s4, Scssdss s5, Scssdss s6, Scssdss s7, Scssdss s8) { testScssdss (s1, g2sScssdss, s2, g4sScssdss, s3, g6sScssdss, s4, g8sScssdss, s5, g10sScssdss, s6, g12sScssdss, s7, g14sScssdss, s8, g16sScssdss); } void testitScssdss (void) { ; ; initScssdss ( &g1sScssdss, 1); initScssdss ( &g2sScssdss, 2); initScssdss ( &g3sScssdss, 3); initScssdss ( &g4sScssdss, 4); initScssdss ( &g5sScssdss, 5); initScssdss ( &g6sScssdss, 6); initScssdss ( &g7sScssdss, 7); initScssdss ( &g8sScssdss, 8); initScssdss ( &g9sScssdss, 9); initScssdss (&g10sScssdss, 10); initScssdss (&g11sScssdss, 11); initScssdss (&g12sScssdss, 12); initScssdss (&g13sScssdss, 13); initScssdss (&g14sScssdss, 14); initScssdss (&g15sScssdss, 15); initScssdss (&g16sScssdss, 16); checkgScssdss (); ; ; ; testScssdss (g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss, g9sScssdss, g10sScssdss, g11sScssdss, g12sScssdss, g13sScssdss, g14sScssdss, g15sScssdss, g16sScssdss); ; ; ; ; testvaScssdss (1, g1sScssdss); ; testvaScssdss (2, g1sScssdss, g2sScssdss); ; testvaScssdss (3, g1sScssdss, g2sScssdss, g3sScssdss); ; testvaScssdss (4, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss); ; testvaScssdss (5, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss); ; testvaScssdss (6, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss); ; testvaScssdss (7, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss); ; testvaScssdss (8, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss); ; testvaScssdss (9, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss, g9sScssdss); ; testvaScssdss (10, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss, g9sScssdss, g10sScssdss); ; testvaScssdss (11, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss, g9sScssdss, g10sScssdss, g11sScssdss); ; testvaScssdss (12, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss, g9sScssdss, g10sScssdss, g11sScssdss, g12sScssdss); ; testvaScssdss (13, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss, g9sScssdss, g10sScssdss, g11sScssdss, g12sScssdss, g13sScssdss); ; testvaScssdss (14, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss, g9sScssdss, g10sScssdss, g11sScssdss, g12sScssdss, g13sScssdss, g14sScssdss); ; testvaScssdss (15, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss, g9sScssdss, g10sScssdss, g11sScssdss, g12sScssdss, g13sScssdss, g14sScssdss, g15sScssdss); ; testvaScssdss (16, g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss, g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss, g9sScssdss, g10sScssdss, g11sScssdss, g12sScssdss, g13sScssdss, g14sScssdss, g15sScssdss, g16sScssdss); ; ; ; test2_Scssdss (g1sScssdss, g3sScssdss, g5sScssdss, g7sScssdss, g9sScssdss, g11sScssdss, g13sScssdss, g15sScssdss); ; }



void
struct_by_value_20_x ()
{




testitScd ();
testitScsds ();
testitScssdss ();



if (fails != 0)
  abort ();


}
