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

Sfi g01Sfi, g02Sfi, g03Sfi, g04Sfi; Sfi g05Sfi, g06Sfi, g07Sfi, g08Sfi; Sfi g09Sfi, g10Sfi, g11Sfi, g12Sfi; Sfi g13Sfi, g14Sfi, g15Sfi, g16Sfi; extern void initSfi (Sfi *p, int i); extern void checkgSfi (void); extern Sfi test0Sfi (void); extern Sfi test1Sfi (Sfi); extern Sfi testvaSfi (int n, ...); void testitSfi (void) { Sfi rslt; ; ; initSfi (&g01Sfi, 1); initSfi (&g02Sfi, 2); initSfi (&g03Sfi, 3); initSfi (&g04Sfi, 4); initSfi (&g05Sfi, 5); initSfi (&g06Sfi, 6); initSfi (&g07Sfi, 7); initSfi (&g08Sfi, 8); initSfi (&g09Sfi, 9); initSfi (&g10Sfi, 10); initSfi (&g11Sfi, 11); initSfi (&g12Sfi, 12); initSfi (&g13Sfi, 13); initSfi (&g14Sfi, 14); initSfi (&g15Sfi, 15); initSfi (&g16Sfi, 16); checkgSfi (); ; ; ; rslt = test0Sfi (); checkSfi (rslt, 1); ; ; ; rslt = test1Sfi (g01Sfi); checkSfi (rslt, 1); if (test_va) { ; ; ; rslt = testvaSfi (1, g01Sfi); checkSfi (rslt, 1); rslt = testvaSfi (5, g01Sfi, g02Sfi, g03Sfi, g04Sfi, g05Sfi); checkSfi (rslt, 5); rslt = testvaSfi (9, g01Sfi, g02Sfi, g03Sfi, g04Sfi, g05Sfi, g06Sfi, g07Sfi, g08Sfi, g09Sfi); checkSfi (rslt, 9); rslt = testvaSfi (16, g01Sfi, g02Sfi, g03Sfi, g04Sfi, g05Sfi, g06Sfi, g07Sfi, g08Sfi, g09Sfi, g10Sfi, g11Sfi, g12Sfi, g13Sfi, g14Sfi, g15Sfi, g16Sfi); checkSfi (rslt, 16); } ; }
Sfii g01Sfii, g02Sfii, g03Sfii, g04Sfii; Sfii g05Sfii, g06Sfii, g07Sfii, g08Sfii; Sfii g09Sfii, g10Sfii, g11Sfii, g12Sfii; Sfii g13Sfii, g14Sfii, g15Sfii, g16Sfii; extern void initSfii (Sfii *p, int i); extern void checkgSfii (void); extern Sfii test0Sfii (void); extern Sfii test1Sfii (Sfii); extern Sfii testvaSfii (int n, ...); void testitSfii (void) { Sfii rslt; ; ; initSfii (&g01Sfii, 1); initSfii (&g02Sfii, 2); initSfii (&g03Sfii, 3); initSfii (&g04Sfii, 4); initSfii (&g05Sfii, 5); initSfii (&g06Sfii, 6); initSfii (&g07Sfii, 7); initSfii (&g08Sfii, 8); initSfii (&g09Sfii, 9); initSfii (&g10Sfii, 10); initSfii (&g11Sfii, 11); initSfii (&g12Sfii, 12); initSfii (&g13Sfii, 13); initSfii (&g14Sfii, 14); initSfii (&g15Sfii, 15); initSfii (&g16Sfii, 16); checkgSfii (); ; ; ; rslt = test0Sfii (); checkSfii (rslt, 1); ; ; ; rslt = test1Sfii (g01Sfii); checkSfii (rslt, 1); if (test_va) { ; ; ; rslt = testvaSfii (1, g01Sfii); checkSfii (rslt, 1); rslt = testvaSfii (5, g01Sfii, g02Sfii, g03Sfii, g04Sfii, g05Sfii); checkSfii (rslt, 5); rslt = testvaSfii (9, g01Sfii, g02Sfii, g03Sfii, g04Sfii, g05Sfii, g06Sfii, g07Sfii, g08Sfii, g09Sfii); checkSfii (rslt, 9); rslt = testvaSfii (16, g01Sfii, g02Sfii, g03Sfii, g04Sfii, g05Sfii, g06Sfii, g07Sfii, g08Sfii, g09Sfii, g10Sfii, g11Sfii, g12Sfii, g13Sfii, g14Sfii, g15Sfii, g16Sfii); checkSfii (rslt, 16); } ; }
Sfifi g01Sfifi, g02Sfifi, g03Sfifi, g04Sfifi; Sfifi g05Sfifi, g06Sfifi, g07Sfifi, g08Sfifi; Sfifi g09Sfifi, g10Sfifi, g11Sfifi, g12Sfifi; Sfifi g13Sfifi, g14Sfifi, g15Sfifi, g16Sfifi; extern void initSfifi (Sfifi *p, int i); extern void checkgSfifi (void); extern Sfifi test0Sfifi (void); extern Sfifi test1Sfifi (Sfifi); extern Sfifi testvaSfifi (int n, ...); void testitSfifi (void) { Sfifi rslt; ; ; initSfifi (&g01Sfifi, 1); initSfifi (&g02Sfifi, 2); initSfifi (&g03Sfifi, 3); initSfifi (&g04Sfifi, 4); initSfifi (&g05Sfifi, 5); initSfifi (&g06Sfifi, 6); initSfifi (&g07Sfifi, 7); initSfifi (&g08Sfifi, 8); initSfifi (&g09Sfifi, 9); initSfifi (&g10Sfifi, 10); initSfifi (&g11Sfifi, 11); initSfifi (&g12Sfifi, 12); initSfifi (&g13Sfifi, 13); initSfifi (&g14Sfifi, 14); initSfifi (&g15Sfifi, 15); initSfifi (&g16Sfifi, 16); checkgSfifi (); ; ; ; rslt = test0Sfifi (); checkSfifi (rslt, 1); ; ; ; rslt = test1Sfifi (g01Sfifi); checkSfifi (rslt, 1); if (test_va) { ; ; ; rslt = testvaSfifi (1, g01Sfifi); checkSfifi (rslt, 1); rslt = testvaSfifi (5, g01Sfifi, g02Sfifi, g03Sfifi, g04Sfifi, g05Sfifi); checkSfifi (rslt, 5); rslt = testvaSfifi (9, g01Sfifi, g02Sfifi, g03Sfifi, g04Sfifi, g05Sfifi, g06Sfifi, g07Sfifi, g08Sfifi, g09Sfifi); checkSfifi (rslt, 9); rslt = testvaSfifi (16, g01Sfifi, g02Sfifi, g03Sfifi, g04Sfifi, g05Sfifi, g06Sfifi, g07Sfifi, g08Sfifi, g09Sfifi, g10Sfifi, g11Sfifi, g12Sfifi, g13Sfifi, g14Sfifi, g15Sfifi, g16Sfifi); checkSfifi (rslt, 16); } ; }
Sfiifii g01Sfiifii, g02Sfiifii, g03Sfiifii, g04Sfiifii; Sfiifii g05Sfiifii, g06Sfiifii, g07Sfiifii, g08Sfiifii; Sfiifii g09Sfiifii, g10Sfiifii, g11Sfiifii, g12Sfiifii; Sfiifii g13Sfiifii, g14Sfiifii, g15Sfiifii, g16Sfiifii; extern void initSfiifii (Sfiifii *p, int i); extern void checkgSfiifii (void); extern Sfiifii test0Sfiifii (void); extern Sfiifii test1Sfiifii (Sfiifii); extern Sfiifii testvaSfiifii (int n, ...); void testitSfiifii (void) { Sfiifii rslt; ; ; initSfiifii (&g01Sfiifii, 1); initSfiifii (&g02Sfiifii, 2); initSfiifii (&g03Sfiifii, 3); initSfiifii (&g04Sfiifii, 4); initSfiifii (&g05Sfiifii, 5); initSfiifii (&g06Sfiifii, 6); initSfiifii (&g07Sfiifii, 7); initSfiifii (&g08Sfiifii, 8); initSfiifii (&g09Sfiifii, 9); initSfiifii (&g10Sfiifii, 10); initSfiifii (&g11Sfiifii, 11); initSfiifii (&g12Sfiifii, 12); initSfiifii (&g13Sfiifii, 13); initSfiifii (&g14Sfiifii, 14); initSfiifii (&g15Sfiifii, 15); initSfiifii (&g16Sfiifii, 16); checkgSfiifii (); ; ; ; rslt = test0Sfiifii (); checkSfiifii (rslt, 1); ; ; ; rslt = test1Sfiifii (g01Sfiifii); checkSfiifii (rslt, 1); if (test_va) { ; ; ; rslt = testvaSfiifii (1, g01Sfiifii); checkSfiifii (rslt, 1); rslt = testvaSfiifii (5, g01Sfiifii, g02Sfiifii, g03Sfiifii, g04Sfiifii, g05Sfiifii); checkSfiifii (rslt, 5); rslt = testvaSfiifii (9, g01Sfiifii, g02Sfiifii, g03Sfiifii, g04Sfiifii, g05Sfiifii, g06Sfiifii, g07Sfiifii, g08Sfiifii, g09Sfiifii); checkSfiifii (rslt, 9); rslt = testvaSfiifii (16, g01Sfiifii, g02Sfiifii, g03Sfiifii, g04Sfiifii, g05Sfiifii, g06Sfiifii, g07Sfiifii, g08Sfiifii, g09Sfiifii, g10Sfiifii, g11Sfiifii, g12Sfiifii, g13Sfiifii, g14Sfiifii, g15Sfiifii, g16Sfiifii); checkSfiifii (rslt, 16); } ; }



void
struct_return_21_x ()
{




testitSfi ();
testitSfii ();
testitSfifi ();
testitSfiifii ();



if (fails != 0)
  abort ();


}
