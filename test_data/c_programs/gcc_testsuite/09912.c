extern void abort (void);

extern int fails;




const int test_va = 1;


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

Scd g01Scd, g02Scd, g03Scd, g04Scd; Scd g05Scd, g06Scd, g07Scd, g08Scd; Scd g09Scd, g10Scd, g11Scd, g12Scd; Scd g13Scd, g14Scd, g15Scd, g16Scd; extern void initScd (Scd *p, int i); extern void checkgScd (void); extern Scd test0Scd (void); extern Scd test1Scd (Scd); extern Scd testvaScd (int n, ...); void testitScd (void) { Scd rslt; ; ; initScd (&g01Scd, 1); initScd (&g02Scd, 2); initScd (&g03Scd, 3); initScd (&g04Scd, 4); initScd (&g05Scd, 5); initScd (&g06Scd, 6); initScd (&g07Scd, 7); initScd (&g08Scd, 8); initScd (&g09Scd, 9); initScd (&g10Scd, 10); initScd (&g11Scd, 11); initScd (&g12Scd, 12); initScd (&g13Scd, 13); initScd (&g14Scd, 14); initScd (&g15Scd, 15); initScd (&g16Scd, 16); checkgScd (); ; ; ; rslt = test0Scd (); checkScd (rslt, 1); ; ; ; rslt = test1Scd (g01Scd); checkScd (rslt, 1); if (test_va) { ; ; ; rslt = testvaScd (1, g01Scd); checkScd (rslt, 1); rslt = testvaScd (5, g01Scd, g02Scd, g03Scd, g04Scd, g05Scd); checkScd (rslt, 5); rslt = testvaScd (9, g01Scd, g02Scd, g03Scd, g04Scd, g05Scd, g06Scd, g07Scd, g08Scd, g09Scd); checkScd (rslt, 9); rslt = testvaScd (16, g01Scd, g02Scd, g03Scd, g04Scd, g05Scd, g06Scd, g07Scd, g08Scd, g09Scd, g10Scd, g11Scd, g12Scd, g13Scd, g14Scd, g15Scd, g16Scd); checkScd (rslt, 16); } ; }
Scsds g01Scsds, g02Scsds, g03Scsds, g04Scsds; Scsds g05Scsds, g06Scsds, g07Scsds, g08Scsds; Scsds g09Scsds, g10Scsds, g11Scsds, g12Scsds; Scsds g13Scsds, g14Scsds, g15Scsds, g16Scsds; extern void initScsds (Scsds *p, int i); extern void checkgScsds (void); extern Scsds test0Scsds (void); extern Scsds test1Scsds (Scsds); extern Scsds testvaScsds (int n, ...); void testitScsds (void) { Scsds rslt; ; ; initScsds (&g01Scsds, 1); initScsds (&g02Scsds, 2); initScsds (&g03Scsds, 3); initScsds (&g04Scsds, 4); initScsds (&g05Scsds, 5); initScsds (&g06Scsds, 6); initScsds (&g07Scsds, 7); initScsds (&g08Scsds, 8); initScsds (&g09Scsds, 9); initScsds (&g10Scsds, 10); initScsds (&g11Scsds, 11); initScsds (&g12Scsds, 12); initScsds (&g13Scsds, 13); initScsds (&g14Scsds, 14); initScsds (&g15Scsds, 15); initScsds (&g16Scsds, 16); checkgScsds (); ; ; ; rslt = test0Scsds (); checkScsds (rslt, 1); ; ; ; rslt = test1Scsds (g01Scsds); checkScsds (rslt, 1); if (test_va) { ; ; ; rslt = testvaScsds (1, g01Scsds); checkScsds (rslt, 1); rslt = testvaScsds (5, g01Scsds, g02Scsds, g03Scsds, g04Scsds, g05Scsds); checkScsds (rslt, 5); rslt = testvaScsds (9, g01Scsds, g02Scsds, g03Scsds, g04Scsds, g05Scsds, g06Scsds, g07Scsds, g08Scsds, g09Scsds); checkScsds (rslt, 9); rslt = testvaScsds (16, g01Scsds, g02Scsds, g03Scsds, g04Scsds, g05Scsds, g06Scsds, g07Scsds, g08Scsds, g09Scsds, g10Scsds, g11Scsds, g12Scsds, g13Scsds, g14Scsds, g15Scsds, g16Scsds); checkScsds (rslt, 16); } ; }
Scssdss g01Scssdss, g02Scssdss, g03Scssdss, g04Scssdss; Scssdss g05Scssdss, g06Scssdss, g07Scssdss, g08Scssdss; Scssdss g09Scssdss, g10Scssdss, g11Scssdss, g12Scssdss; Scssdss g13Scssdss, g14Scssdss, g15Scssdss, g16Scssdss; extern void initScssdss (Scssdss *p, int i); extern void checkgScssdss (void); extern Scssdss test0Scssdss (void); extern Scssdss test1Scssdss (Scssdss); extern Scssdss testvaScssdss (int n, ...); void testitScssdss (void) { Scssdss rslt; ; ; initScssdss (&g01Scssdss, 1); initScssdss (&g02Scssdss, 2); initScssdss (&g03Scssdss, 3); initScssdss (&g04Scssdss, 4); initScssdss (&g05Scssdss, 5); initScssdss (&g06Scssdss, 6); initScssdss (&g07Scssdss, 7); initScssdss (&g08Scssdss, 8); initScssdss (&g09Scssdss, 9); initScssdss (&g10Scssdss, 10); initScssdss (&g11Scssdss, 11); initScssdss (&g12Scssdss, 12); initScssdss (&g13Scssdss, 13); initScssdss (&g14Scssdss, 14); initScssdss (&g15Scssdss, 15); initScssdss (&g16Scssdss, 16); checkgScssdss (); ; ; ; rslt = test0Scssdss (); checkScssdss (rslt, 1); ; ; ; rslt = test1Scssdss (g01Scssdss); checkScssdss (rslt, 1); if (test_va) { ; ; ; rslt = testvaScssdss (1, g01Scssdss); checkScssdss (rslt, 1); rslt = testvaScssdss (5, g01Scssdss, g02Scssdss, g03Scssdss, g04Scssdss, g05Scssdss); checkScssdss (rslt, 5); rslt = testvaScssdss (9, g01Scssdss, g02Scssdss, g03Scssdss, g04Scssdss, g05Scssdss, g06Scssdss, g07Scssdss, g08Scssdss, g09Scssdss); checkScssdss (rslt, 9); rslt = testvaScssdss (16, g01Scssdss, g02Scssdss, g03Scssdss, g04Scssdss, g05Scssdss, g06Scssdss, g07Scssdss, g08Scssdss, g09Scssdss, g10Scssdss, g11Scssdss, g12Scssdss, g13Scssdss, g14Scssdss, g15Scssdss, g16Scssdss); checkScssdss (rslt, 16); } ; }



void
struct_return_20_x ()
{




testitScd ();
testitScsds ();
testitScssdss ();



if (fails != 0)
  abort ();


}
