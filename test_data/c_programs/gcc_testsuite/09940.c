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

Scdc g01Scdc, g02Scdc, g03Scdc, g04Scdc; Scdc g05Scdc, g06Scdc, g07Scdc, g08Scdc; Scdc g09Scdc, g10Scdc, g11Scdc, g12Scdc; Scdc g13Scdc, g14Scdc, g15Scdc, g16Scdc; extern void initScdc (Scdc *p, int i); extern void checkgScdc (void); extern Scdc test0Scdc (void); extern Scdc test1Scdc (Scdc); extern Scdc testvaScdc (int n, ...); void testitScdc (void) { Scdc rslt; ; ; initScdc (&g01Scdc, 1); initScdc (&g02Scdc, 2); initScdc (&g03Scdc, 3); initScdc (&g04Scdc, 4); initScdc (&g05Scdc, 5); initScdc (&g06Scdc, 6); initScdc (&g07Scdc, 7); initScdc (&g08Scdc, 8); initScdc (&g09Scdc, 9); initScdc (&g10Scdc, 10); initScdc (&g11Scdc, 11); initScdc (&g12Scdc, 12); initScdc (&g13Scdc, 13); initScdc (&g14Scdc, 14); initScdc (&g15Scdc, 15); initScdc (&g16Scdc, 16); checkgScdc (); ; ; ; rslt = test0Scdc (); checkScdc (rslt, 1); ; ; ; rslt = test1Scdc (g01Scdc); checkScdc (rslt, 1); if (test_va) { ; ; ; rslt = testvaScdc (1, g01Scdc); checkScdc (rslt, 1); rslt = testvaScdc (5, g01Scdc, g02Scdc, g03Scdc, g04Scdc, g05Scdc); checkScdc (rslt, 5); rslt = testvaScdc (9, g01Scdc, g02Scdc, g03Scdc, g04Scdc, g05Scdc, g06Scdc, g07Scdc, g08Scdc, g09Scdc); checkScdc (rslt, 9); rslt = testvaScdc (16, g01Scdc, g02Scdc, g03Scdc, g04Scdc, g05Scdc, g06Scdc, g07Scdc, g08Scdc, g09Scdc, g10Scdc, g11Scdc, g12Scdc, g13Scdc, g14Scdc, g15Scdc, g16Scdc); checkScdc (rslt, 16); } ; }
Sd g01Sd, g02Sd, g03Sd, g04Sd; Sd g05Sd, g06Sd, g07Sd, g08Sd; Sd g09Sd, g10Sd, g11Sd, g12Sd; Sd g13Sd, g14Sd, g15Sd, g16Sd; extern void initSd (Sd *p, int i); extern void checkgSd (void); extern Sd test0Sd (void); extern Sd test1Sd (Sd); extern Sd testvaSd (int n, ...); void testitSd (void) { Sd rslt; ; ; initSd (&g01Sd, 1); initSd (&g02Sd, 2); initSd (&g03Sd, 3); initSd (&g04Sd, 4); initSd (&g05Sd, 5); initSd (&g06Sd, 6); initSd (&g07Sd, 7); initSd (&g08Sd, 8); initSd (&g09Sd, 9); initSd (&g10Sd, 10); initSd (&g11Sd, 11); initSd (&g12Sd, 12); initSd (&g13Sd, 13); initSd (&g14Sd, 14); initSd (&g15Sd, 15); initSd (&g16Sd, 16); checkgSd (); ; ; ; rslt = test0Sd (); checkSd (rslt, 1); ; ; ; rslt = test1Sd (g01Sd); checkSd (rslt, 1); if (test_va) { ; ; ; rslt = testvaSd (1, g01Sd); checkSd (rslt, 1); rslt = testvaSd (5, g01Sd, g02Sd, g03Sd, g04Sd, g05Sd); checkSd (rslt, 5); rslt = testvaSd (9, g01Sd, g02Sd, g03Sd, g04Sd, g05Sd, g06Sd, g07Sd, g08Sd, g09Sd); checkSd (rslt, 9); rslt = testvaSd (16, g01Sd, g02Sd, g03Sd, g04Sd, g05Sd, g06Sd, g07Sd, g08Sd, g09Sd, g10Sd, g11Sd, g12Sd, g13Sd, g14Sd, g15Sd, g16Sd); checkSd (rslt, 16); } ; }
Sdi g01Sdi, g02Sdi, g03Sdi, g04Sdi; Sdi g05Sdi, g06Sdi, g07Sdi, g08Sdi; Sdi g09Sdi, g10Sdi, g11Sdi, g12Sdi; Sdi g13Sdi, g14Sdi, g15Sdi, g16Sdi; extern void initSdi (Sdi *p, int i); extern void checkgSdi (void); extern Sdi test0Sdi (void); extern Sdi test1Sdi (Sdi); extern Sdi testvaSdi (int n, ...); void testitSdi (void) { Sdi rslt; ; ; initSdi (&g01Sdi, 1); initSdi (&g02Sdi, 2); initSdi (&g03Sdi, 3); initSdi (&g04Sdi, 4); initSdi (&g05Sdi, 5); initSdi (&g06Sdi, 6); initSdi (&g07Sdi, 7); initSdi (&g08Sdi, 8); initSdi (&g09Sdi, 9); initSdi (&g10Sdi, 10); initSdi (&g11Sdi, 11); initSdi (&g12Sdi, 12); initSdi (&g13Sdi, 13); initSdi (&g14Sdi, 14); initSdi (&g15Sdi, 15); initSdi (&g16Sdi, 16); checkgSdi (); ; ; ; rslt = test0Sdi (); checkSdi (rslt, 1); ; ; ; rslt = test1Sdi (g01Sdi); checkSdi (rslt, 1); if (test_va) { ; ; ; rslt = testvaSdi (1, g01Sdi); checkSdi (rslt, 1); rslt = testvaSdi (5, g01Sdi, g02Sdi, g03Sdi, g04Sdi, g05Sdi); checkSdi (rslt, 5); rslt = testvaSdi (9, g01Sdi, g02Sdi, g03Sdi, g04Sdi, g05Sdi, g06Sdi, g07Sdi, g08Sdi, g09Sdi); checkSdi (rslt, 9); rslt = testvaSdi (16, g01Sdi, g02Sdi, g03Sdi, g04Sdi, g05Sdi, g06Sdi, g07Sdi, g08Sdi, g09Sdi, g10Sdi, g11Sdi, g12Sdi, g13Sdi, g14Sdi, g15Sdi, g16Sdi); checkSdi (rslt, 16); } ; }
Scsdsc g01Scsdsc, g02Scsdsc, g03Scsdsc, g04Scsdsc; Scsdsc g05Scsdsc, g06Scsdsc, g07Scsdsc, g08Scsdsc; Scsdsc g09Scsdsc, g10Scsdsc, g11Scsdsc, g12Scsdsc; Scsdsc g13Scsdsc, g14Scsdsc, g15Scsdsc, g16Scsdsc; extern void initScsdsc (Scsdsc *p, int i); extern void checkgScsdsc (void); extern Scsdsc test0Scsdsc (void); extern Scsdsc test1Scsdsc (Scsdsc); extern Scsdsc testvaScsdsc (int n, ...); void testitScsdsc (void) { Scsdsc rslt; ; ; initScsdsc (&g01Scsdsc, 1); initScsdsc (&g02Scsdsc, 2); initScsdsc (&g03Scsdsc, 3); initScsdsc (&g04Scsdsc, 4); initScsdsc (&g05Scsdsc, 5); initScsdsc (&g06Scsdsc, 6); initScsdsc (&g07Scsdsc, 7); initScsdsc (&g08Scsdsc, 8); initScsdsc (&g09Scsdsc, 9); initScsdsc (&g10Scsdsc, 10); initScsdsc (&g11Scsdsc, 11); initScsdsc (&g12Scsdsc, 12); initScsdsc (&g13Scsdsc, 13); initScsdsc (&g14Scsdsc, 14); initScsdsc (&g15Scsdsc, 15); initScsdsc (&g16Scsdsc, 16); checkgScsdsc (); ; ; ; rslt = test0Scsdsc (); checkScsdsc (rslt, 1); ; ; ; rslt = test1Scsdsc (g01Scsdsc); checkScsdsc (rslt, 1); if (test_va) { ; ; ; rslt = testvaScsdsc (1, g01Scsdsc); checkScsdsc (rslt, 1); rslt = testvaScsdsc (5, g01Scsdsc, g02Scsdsc, g03Scsdsc, g04Scsdsc, g05Scsdsc); checkScsdsc (rslt, 5); rslt = testvaScsdsc (9, g01Scsdsc, g02Scsdsc, g03Scsdsc, g04Scsdsc, g05Scsdsc, g06Scsdsc, g07Scsdsc, g08Scsdsc, g09Scsdsc); checkScsdsc (rslt, 9); rslt = testvaScsdsc (16, g01Scsdsc, g02Scsdsc, g03Scsdsc, g04Scsdsc, g05Scsdsc, g06Scsdsc, g07Scsdsc, g08Scsdsc, g09Scsdsc, g10Scsdsc, g11Scsdsc, g12Scsdsc, g13Scsdsc, g14Scsdsc, g15Scsdsc, g16Scsdsc); checkScsdsc (rslt, 16); } ; }
Scsdis g01Scsdis, g02Scsdis, g03Scsdis, g04Scsdis; Scsdis g05Scsdis, g06Scsdis, g07Scsdis, g08Scsdis; Scsdis g09Scsdis, g10Scsdis, g11Scsdis, g12Scsdis; Scsdis g13Scsdis, g14Scsdis, g15Scsdis, g16Scsdis; extern void initScsdis (Scsdis *p, int i); extern void checkgScsdis (void); extern Scsdis test0Scsdis (void); extern Scsdis test1Scsdis (Scsdis); extern Scsdis testvaScsdis (int n, ...); void testitScsdis (void) { Scsdis rslt; ; ; initScsdis (&g01Scsdis, 1); initScsdis (&g02Scsdis, 2); initScsdis (&g03Scsdis, 3); initScsdis (&g04Scsdis, 4); initScsdis (&g05Scsdis, 5); initScsdis (&g06Scsdis, 6); initScsdis (&g07Scsdis, 7); initScsdis (&g08Scsdis, 8); initScsdis (&g09Scsdis, 9); initScsdis (&g10Scsdis, 10); initScsdis (&g11Scsdis, 11); initScsdis (&g12Scsdis, 12); initScsdis (&g13Scsdis, 13); initScsdis (&g14Scsdis, 14); initScsdis (&g15Scsdis, 15); initScsdis (&g16Scsdis, 16); checkgScsdis (); ; ; ; rslt = test0Scsdis (); checkScsdis (rslt, 1); ; ; ; rslt = test1Scsdis (g01Scsdis); checkScsdis (rslt, 1); if (test_va) { ; ; ; rslt = testvaScsdis (1, g01Scsdis); checkScsdis (rslt, 1); rslt = testvaScsdis (5, g01Scsdis, g02Scsdis, g03Scsdis, g04Scsdis, g05Scsdis); checkScsdis (rslt, 5); rslt = testvaScsdis (9, g01Scsdis, g02Scsdis, g03Scsdis, g04Scsdis, g05Scsdis, g06Scsdis, g07Scsdis, g08Scsdis, g09Scsdis); checkScsdis (rslt, 9); rslt = testvaScsdis (16, g01Scsdis, g02Scsdis, g03Scsdis, g04Scsdis, g05Scsdis, g06Scsdis, g07Scsdis, g08Scsdis, g09Scsdis, g10Scsdis, g11Scsdis, g12Scsdis, g13Scsdis, g14Scsdis, g15Scsdis, g16Scsdis); checkScsdis (rslt, 16); } ; }
Scsdisc g01Scsdisc, g02Scsdisc, g03Scsdisc, g04Scsdisc; Scsdisc g05Scsdisc, g06Scsdisc, g07Scsdisc, g08Scsdisc; Scsdisc g09Scsdisc, g10Scsdisc, g11Scsdisc, g12Scsdisc; Scsdisc g13Scsdisc, g14Scsdisc, g15Scsdisc, g16Scsdisc; extern void initScsdisc (Scsdisc *p, int i); extern void checkgScsdisc (void); extern Scsdisc test0Scsdisc (void); extern Scsdisc test1Scsdisc (Scsdisc); extern Scsdisc testvaScsdisc (int n, ...); void testitScsdisc (void) { Scsdisc rslt; ; ; initScsdisc (&g01Scsdisc, 1); initScsdisc (&g02Scsdisc, 2); initScsdisc (&g03Scsdisc, 3); initScsdisc (&g04Scsdisc, 4); initScsdisc (&g05Scsdisc, 5); initScsdisc (&g06Scsdisc, 6); initScsdisc (&g07Scsdisc, 7); initScsdisc (&g08Scsdisc, 8); initScsdisc (&g09Scsdisc, 9); initScsdisc (&g10Scsdisc, 10); initScsdisc (&g11Scsdisc, 11); initScsdisc (&g12Scsdisc, 12); initScsdisc (&g13Scsdisc, 13); initScsdisc (&g14Scsdisc, 14); initScsdisc (&g15Scsdisc, 15); initScsdisc (&g16Scsdisc, 16); checkgScsdisc (); ; ; ; rslt = test0Scsdisc (); checkScsdisc (rslt, 1); ; ; ; rslt = test1Scsdisc (g01Scsdisc); checkScsdisc (rslt, 1); if (test_va) { ; ; ; rslt = testvaScsdisc (1, g01Scsdisc); checkScsdisc (rslt, 1); rslt = testvaScsdisc (5, g01Scsdisc, g02Scsdisc, g03Scsdisc, g04Scsdisc, g05Scsdisc); checkScsdisc (rslt, 5); rslt = testvaScsdisc (9, g01Scsdisc, g02Scsdisc, g03Scsdisc, g04Scsdisc, g05Scsdisc, g06Scsdisc, g07Scsdisc, g08Scsdisc, g09Scsdisc); checkScsdisc (rslt, 9); rslt = testvaScsdisc (16, g01Scsdisc, g02Scsdisc, g03Scsdisc, g04Scsdisc, g05Scsdisc, g06Scsdisc, g07Scsdisc, g08Scsdisc, g09Scsdisc, g10Scsdisc, g11Scsdisc, g12Scsdisc, g13Scsdisc, g14Scsdisc, g15Scsdisc, g16Scsdisc); checkScsdisc (rslt, 16); } ; }
Ssds g01Ssds, g02Ssds, g03Ssds, g04Ssds; Ssds g05Ssds, g06Ssds, g07Ssds, g08Ssds; Ssds g09Ssds, g10Ssds, g11Ssds, g12Ssds; Ssds g13Ssds, g14Ssds, g15Ssds, g16Ssds; extern void initSsds (Ssds *p, int i); extern void checkgSsds (void); extern Ssds test0Ssds (void); extern Ssds test1Ssds (Ssds); extern Ssds testvaSsds (int n, ...); void testitSsds (void) { Ssds rslt; ; ; initSsds (&g01Ssds, 1); initSsds (&g02Ssds, 2); initSsds (&g03Ssds, 3); initSsds (&g04Ssds, 4); initSsds (&g05Ssds, 5); initSsds (&g06Ssds, 6); initSsds (&g07Ssds, 7); initSsds (&g08Ssds, 8); initSsds (&g09Ssds, 9); initSsds (&g10Ssds, 10); initSsds (&g11Ssds, 11); initSsds (&g12Ssds, 12); initSsds (&g13Ssds, 13); initSsds (&g14Ssds, 14); initSsds (&g15Ssds, 15); initSsds (&g16Ssds, 16); checkgSsds (); ; ; ; rslt = test0Ssds (); checkSsds (rslt, 1); ; ; ; rslt = test1Ssds (g01Ssds); checkSsds (rslt, 1); if (test_va) { ; ; ; rslt = testvaSsds (1, g01Ssds); checkSsds (rslt, 1); rslt = testvaSsds (5, g01Ssds, g02Ssds, g03Ssds, g04Ssds, g05Ssds); checkSsds (rslt, 5); rslt = testvaSsds (9, g01Ssds, g02Ssds, g03Ssds, g04Ssds, g05Ssds, g06Ssds, g07Ssds, g08Ssds, g09Ssds); checkSsds (rslt, 9); rslt = testvaSsds (16, g01Ssds, g02Ssds, g03Ssds, g04Ssds, g05Ssds, g06Ssds, g07Ssds, g08Ssds, g09Ssds, g10Ssds, g11Ssds, g12Ssds, g13Ssds, g14Ssds, g15Ssds, g16Ssds); checkSsds (rslt, 16); } ; }
Ssdsc g01Ssdsc, g02Ssdsc, g03Ssdsc, g04Ssdsc; Ssdsc g05Ssdsc, g06Ssdsc, g07Ssdsc, g08Ssdsc; Ssdsc g09Ssdsc, g10Ssdsc, g11Ssdsc, g12Ssdsc; Ssdsc g13Ssdsc, g14Ssdsc, g15Ssdsc, g16Ssdsc; extern void initSsdsc (Ssdsc *p, int i); extern void checkgSsdsc (void); extern Ssdsc test0Ssdsc (void); extern Ssdsc test1Ssdsc (Ssdsc); extern Ssdsc testvaSsdsc (int n, ...); void testitSsdsc (void) { Ssdsc rslt; ; ; initSsdsc (&g01Ssdsc, 1); initSsdsc (&g02Ssdsc, 2); initSsdsc (&g03Ssdsc, 3); initSsdsc (&g04Ssdsc, 4); initSsdsc (&g05Ssdsc, 5); initSsdsc (&g06Ssdsc, 6); initSsdsc (&g07Ssdsc, 7); initSsdsc (&g08Ssdsc, 8); initSsdsc (&g09Ssdsc, 9); initSsdsc (&g10Ssdsc, 10); initSsdsc (&g11Ssdsc, 11); initSsdsc (&g12Ssdsc, 12); initSsdsc (&g13Ssdsc, 13); initSsdsc (&g14Ssdsc, 14); initSsdsc (&g15Ssdsc, 15); initSsdsc (&g16Ssdsc, 16); checkgSsdsc (); ; ; ; rslt = test0Ssdsc (); checkSsdsc (rslt, 1); ; ; ; rslt = test1Ssdsc (g01Ssdsc); checkSsdsc (rslt, 1); if (test_va) { ; ; ; rslt = testvaSsdsc (1, g01Ssdsc); checkSsdsc (rslt, 1); rslt = testvaSsdsc (5, g01Ssdsc, g02Ssdsc, g03Ssdsc, g04Ssdsc, g05Ssdsc); checkSsdsc (rslt, 5); rslt = testvaSsdsc (9, g01Ssdsc, g02Ssdsc, g03Ssdsc, g04Ssdsc, g05Ssdsc, g06Ssdsc, g07Ssdsc, g08Ssdsc, g09Ssdsc); checkSsdsc (rslt, 9); rslt = testvaSsdsc (16, g01Ssdsc, g02Ssdsc, g03Ssdsc, g04Ssdsc, g05Ssdsc, g06Ssdsc, g07Ssdsc, g08Ssdsc, g09Ssdsc, g10Ssdsc, g11Ssdsc, g12Ssdsc, g13Ssdsc, g14Ssdsc, g15Ssdsc, g16Ssdsc); checkSsdsc (rslt, 16); } ; }
Scssdssc g01Scssdssc, g02Scssdssc, g03Scssdssc, g04Scssdssc; Scssdssc g05Scssdssc, g06Scssdssc, g07Scssdssc, g08Scssdssc; Scssdssc g09Scssdssc, g10Scssdssc, g11Scssdssc, g12Scssdssc; Scssdssc g13Scssdssc, g14Scssdssc, g15Scssdssc, g16Scssdssc; extern void initScssdssc (Scssdssc *p, int i); extern void checkgScssdssc (void); extern Scssdssc test0Scssdssc (void); extern Scssdssc test1Scssdssc (Scssdssc); extern Scssdssc testvaScssdssc (int n, ...); void testitScssdssc (void) { Scssdssc rslt; ; ; initScssdssc (&g01Scssdssc, 1); initScssdssc (&g02Scssdssc, 2); initScssdssc (&g03Scssdssc, 3); initScssdssc (&g04Scssdssc, 4); initScssdssc (&g05Scssdssc, 5); initScssdssc (&g06Scssdssc, 6); initScssdssc (&g07Scssdssc, 7); initScssdssc (&g08Scssdssc, 8); initScssdssc (&g09Scssdssc, 9); initScssdssc (&g10Scssdssc, 10); initScssdssc (&g11Scssdssc, 11); initScssdssc (&g12Scssdssc, 12); initScssdssc (&g13Scssdssc, 13); initScssdssc (&g14Scssdssc, 14); initScssdssc (&g15Scssdssc, 15); initScssdssc (&g16Scssdssc, 16); checkgScssdssc (); ; ; ; rslt = test0Scssdssc (); checkScssdssc (rslt, 1); ; ; ; rslt = test1Scssdssc (g01Scssdssc); checkScssdssc (rslt, 1); if (test_va) { ; ; ; rslt = testvaScssdssc (1, g01Scssdssc); checkScssdssc (rslt, 1); rslt = testvaScssdssc (5, g01Scssdssc, g02Scssdssc, g03Scssdssc, g04Scssdssc, g05Scssdssc); checkScssdssc (rslt, 5); rslt = testvaScssdssc (9, g01Scssdssc, g02Scssdssc, g03Scssdssc, g04Scssdssc, g05Scssdssc, g06Scssdssc, g07Scssdssc, g08Scssdssc, g09Scssdssc); checkScssdssc (rslt, 9); rslt = testvaScssdssc (16, g01Scssdssc, g02Scssdssc, g03Scssdssc, g04Scssdssc, g05Scssdssc, g06Scssdssc, g07Scssdssc, g08Scssdssc, g09Scssdssc, g10Scssdssc, g11Scssdssc, g12Scssdssc, g13Scssdssc, g14Scssdssc, g15Scssdssc, g16Scssdssc); checkScssdssc (rslt, 16); } ; }



void
struct_return_19_x ()
{




testitScdc ();
testitSd ();
testitSdi ();
testitScsdsc ();
testitScsdis ();
testitScsdisc ();
testitSsds ();
testitSsdsc ();
testitScssdssc ();



if (fails != 0)
  abort ();


}
