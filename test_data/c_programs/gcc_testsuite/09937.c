typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

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


void initScd (Scd *p, int i)
{ p->c = (char)i; p->d = (double)i+1; }
void initScdc (Scdc *p, int i)
{ p->c = (char)i; p->d = (double)i+1; p->b = (char)i+2; }
void initSd (Sd *p, int i)
{ p->d = (double)i; }
void initSdi (Sdi *p, int i)
{ p->d = (double)i; p->i = i+1; }
void initScsds (Scsds *p, int i)
{ p->c = (char)i; p->sd.d = (double)i+1; }
void initScsdsc (Scsdsc *p, int i)
{ p->c = (char)i; p->sd.d = (double)i+1; p->b = (char)i+2; }
void initScsdis (Scsdis *p, int i)
{ p->c = (char)i; p->sdi.d = (double)i+1; p->sdi.i = i+2; }
void initScsdisc (Scsdisc *p, int i)
{ p->c = (char)i; p->sdi.d = (double)i+1; p->sdi.i = i+2; p->b = (char)i+3; }
void initSsds (Ssds *p, int i)
{ p->sd.d = (double)i; }
void initSsdsc (Ssdsc *p, int i)
{ p->sd.d = (double)i; p->c = (char)i+1; }
void initScssdss (Scssdss *p, int i)
{ p->c = (char)i; p->ssds.sd.d = (double)i+1; }
void initScssdssc (Scssdssc *p, int i)
{ p->c = (char)i; p->ssds.sd.d = (double)i+1; p->b = (char)i+2; }

void initSfi (Sfi *x, int i)
{ x->f = (float)i; x->i = i+1; }
void initSfii (Sfii *x, int i)
{ x->f = (float)i; x->i1 = i+1; x->i2 = i+2; }
void initSfifi (Sfifi *x, int i)
{ x->fi.f = (float)i; x->fi.i = i+1; }
void initSfiifii (Sfiifii *x, int i)
{ x->fii.f = (float)i; x->fii.i1 = i+1; x->fii.i2 = i+2; }
extern Sfi g01Sfi, g02Sfi, g03Sfi, g04Sfi; extern Sfi g05Sfi, g06Sfi, g07Sfi, g08Sfi; extern Sfi g09Sfi, g10Sfi, g11Sfi, g12Sfi; extern Sfi g13Sfi, g14Sfi, g15Sfi, g16Sfi; extern void checkSfi (Sfi x, int i); void checkgSfi (void) { checkSfi (g01Sfi, 1); checkSfi (g02Sfi, 2); checkSfi (g03Sfi, 3); checkSfi (g04Sfi, 4); checkSfi (g05Sfi, 5); checkSfi (g06Sfi, 6); checkSfi (g07Sfi, 7); checkSfi (g08Sfi, 8); checkSfi (g09Sfi, 9); checkSfi (g10Sfi, 10); checkSfi (g11Sfi, 11); checkSfi (g12Sfi, 12); checkSfi (g13Sfi, 13); checkSfi (g14Sfi, 14); checkSfi (g15Sfi, 15); checkSfi (g16Sfi, 16); } Sfi test0Sfi (void) { return g01Sfi; } Sfi test1Sfi (Sfi x01) { return x01; } Sfi testvaSfi (int n, ...) { int i; Sfi rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Sfi); __builtin_va_end(ap); return rslt; }
extern Sfii g01Sfii, g02Sfii, g03Sfii, g04Sfii; extern Sfii g05Sfii, g06Sfii, g07Sfii, g08Sfii; extern Sfii g09Sfii, g10Sfii, g11Sfii, g12Sfii; extern Sfii g13Sfii, g14Sfii, g15Sfii, g16Sfii; extern void checkSfii (Sfii x, int i); void checkgSfii (void) { checkSfii (g01Sfii, 1); checkSfii (g02Sfii, 2); checkSfii (g03Sfii, 3); checkSfii (g04Sfii, 4); checkSfii (g05Sfii, 5); checkSfii (g06Sfii, 6); checkSfii (g07Sfii, 7); checkSfii (g08Sfii, 8); checkSfii (g09Sfii, 9); checkSfii (g10Sfii, 10); checkSfii (g11Sfii, 11); checkSfii (g12Sfii, 12); checkSfii (g13Sfii, 13); checkSfii (g14Sfii, 14); checkSfii (g15Sfii, 15); checkSfii (g16Sfii, 16); } Sfii test0Sfii (void) { return g01Sfii; } Sfii test1Sfii (Sfii x01) { return x01; } Sfii testvaSfii (int n, ...) { int i; Sfii rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Sfii); __builtin_va_end(ap); return rslt; }
extern Sfifi g01Sfifi, g02Sfifi, g03Sfifi, g04Sfifi; extern Sfifi g05Sfifi, g06Sfifi, g07Sfifi, g08Sfifi; extern Sfifi g09Sfifi, g10Sfifi, g11Sfifi, g12Sfifi; extern Sfifi g13Sfifi, g14Sfifi, g15Sfifi, g16Sfifi; extern void checkSfifi (Sfifi x, int i); void checkgSfifi (void) { checkSfifi (g01Sfifi, 1); checkSfifi (g02Sfifi, 2); checkSfifi (g03Sfifi, 3); checkSfifi (g04Sfifi, 4); checkSfifi (g05Sfifi, 5); checkSfifi (g06Sfifi, 6); checkSfifi (g07Sfifi, 7); checkSfifi (g08Sfifi, 8); checkSfifi (g09Sfifi, 9); checkSfifi (g10Sfifi, 10); checkSfifi (g11Sfifi, 11); checkSfifi (g12Sfifi, 12); checkSfifi (g13Sfifi, 13); checkSfifi (g14Sfifi, 14); checkSfifi (g15Sfifi, 15); checkSfifi (g16Sfifi, 16); } Sfifi test0Sfifi (void) { return g01Sfifi; } Sfifi test1Sfifi (Sfifi x01) { return x01; } Sfifi testvaSfifi (int n, ...) { int i; Sfifi rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Sfifi); __builtin_va_end(ap); return rslt; }
extern Sfiifii g01Sfiifii, g02Sfiifii, g03Sfiifii, g04Sfiifii; extern Sfiifii g05Sfiifii, g06Sfiifii, g07Sfiifii, g08Sfiifii; extern Sfiifii g09Sfiifii, g10Sfiifii, g11Sfiifii, g12Sfiifii; extern Sfiifii g13Sfiifii, g14Sfiifii, g15Sfiifii, g16Sfiifii; extern void checkSfiifii (Sfiifii x, int i); void checkgSfiifii (void) { checkSfiifii (g01Sfiifii, 1); checkSfiifii (g02Sfiifii, 2); checkSfiifii (g03Sfiifii, 3); checkSfiifii (g04Sfiifii, 4); checkSfiifii (g05Sfiifii, 5); checkSfiifii (g06Sfiifii, 6); checkSfiifii (g07Sfiifii, 7); checkSfiifii (g08Sfiifii, 8); checkSfiifii (g09Sfiifii, 9); checkSfiifii (g10Sfiifii, 10); checkSfiifii (g11Sfiifii, 11); checkSfiifii (g12Sfiifii, 12); checkSfiifii (g13Sfiifii, 13); checkSfiifii (g14Sfiifii, 14); checkSfiifii (g15Sfiifii, 15); checkSfiifii (g16Sfiifii, 16); } Sfiifii test0Sfiifii (void) { return g01Sfiifii; } Sfiifii test1Sfiifii (Sfiifii x01) { return x01; } Sfiifii testvaSfiifii (int n, ...) { int i; Sfiifii rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Sfiifii); __builtin_va_end(ap); return rslt; }
