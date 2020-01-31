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
extern Scdc g01Scdc, g02Scdc, g03Scdc, g04Scdc; extern Scdc g05Scdc, g06Scdc, g07Scdc, g08Scdc; extern Scdc g09Scdc, g10Scdc, g11Scdc, g12Scdc; extern Scdc g13Scdc, g14Scdc, g15Scdc, g16Scdc; extern void checkScdc (Scdc x, int i); void checkgScdc (void) { checkScdc (g01Scdc, 1); checkScdc (g02Scdc, 2); checkScdc (g03Scdc, 3); checkScdc (g04Scdc, 4); checkScdc (g05Scdc, 5); checkScdc (g06Scdc, 6); checkScdc (g07Scdc, 7); checkScdc (g08Scdc, 8); checkScdc (g09Scdc, 9); checkScdc (g10Scdc, 10); checkScdc (g11Scdc, 11); checkScdc (g12Scdc, 12); checkScdc (g13Scdc, 13); checkScdc (g14Scdc, 14); checkScdc (g15Scdc, 15); checkScdc (g16Scdc, 16); } Scdc test0Scdc (void) { return g01Scdc; } Scdc test1Scdc (Scdc x01) { return x01; } Scdc testvaScdc (int n, ...) { int i; Scdc rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Scdc); __builtin_va_end(ap); return rslt; }
extern Sd g01Sd, g02Sd, g03Sd, g04Sd; extern Sd g05Sd, g06Sd, g07Sd, g08Sd; extern Sd g09Sd, g10Sd, g11Sd, g12Sd; extern Sd g13Sd, g14Sd, g15Sd, g16Sd; extern void checkSd (Sd x, int i); void checkgSd (void) { checkSd (g01Sd, 1); checkSd (g02Sd, 2); checkSd (g03Sd, 3); checkSd (g04Sd, 4); checkSd (g05Sd, 5); checkSd (g06Sd, 6); checkSd (g07Sd, 7); checkSd (g08Sd, 8); checkSd (g09Sd, 9); checkSd (g10Sd, 10); checkSd (g11Sd, 11); checkSd (g12Sd, 12); checkSd (g13Sd, 13); checkSd (g14Sd, 14); checkSd (g15Sd, 15); checkSd (g16Sd, 16); } Sd test0Sd (void) { return g01Sd; } Sd test1Sd (Sd x01) { return x01; } Sd testvaSd (int n, ...) { int i; Sd rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Sd); __builtin_va_end(ap); return rslt; }
extern Sdi g01Sdi, g02Sdi, g03Sdi, g04Sdi; extern Sdi g05Sdi, g06Sdi, g07Sdi, g08Sdi; extern Sdi g09Sdi, g10Sdi, g11Sdi, g12Sdi; extern Sdi g13Sdi, g14Sdi, g15Sdi, g16Sdi; extern void checkSdi (Sdi x, int i); void checkgSdi (void) { checkSdi (g01Sdi, 1); checkSdi (g02Sdi, 2); checkSdi (g03Sdi, 3); checkSdi (g04Sdi, 4); checkSdi (g05Sdi, 5); checkSdi (g06Sdi, 6); checkSdi (g07Sdi, 7); checkSdi (g08Sdi, 8); checkSdi (g09Sdi, 9); checkSdi (g10Sdi, 10); checkSdi (g11Sdi, 11); checkSdi (g12Sdi, 12); checkSdi (g13Sdi, 13); checkSdi (g14Sdi, 14); checkSdi (g15Sdi, 15); checkSdi (g16Sdi, 16); } Sdi test0Sdi (void) { return g01Sdi; } Sdi test1Sdi (Sdi x01) { return x01; } Sdi testvaSdi (int n, ...) { int i; Sdi rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Sdi); __builtin_va_end(ap); return rslt; }
extern Scsdsc g01Scsdsc, g02Scsdsc, g03Scsdsc, g04Scsdsc; extern Scsdsc g05Scsdsc, g06Scsdsc, g07Scsdsc, g08Scsdsc; extern Scsdsc g09Scsdsc, g10Scsdsc, g11Scsdsc, g12Scsdsc; extern Scsdsc g13Scsdsc, g14Scsdsc, g15Scsdsc, g16Scsdsc; extern void checkScsdsc (Scsdsc x, int i); void checkgScsdsc (void) { checkScsdsc (g01Scsdsc, 1); checkScsdsc (g02Scsdsc, 2); checkScsdsc (g03Scsdsc, 3); checkScsdsc (g04Scsdsc, 4); checkScsdsc (g05Scsdsc, 5); checkScsdsc (g06Scsdsc, 6); checkScsdsc (g07Scsdsc, 7); checkScsdsc (g08Scsdsc, 8); checkScsdsc (g09Scsdsc, 9); checkScsdsc (g10Scsdsc, 10); checkScsdsc (g11Scsdsc, 11); checkScsdsc (g12Scsdsc, 12); checkScsdsc (g13Scsdsc, 13); checkScsdsc (g14Scsdsc, 14); checkScsdsc (g15Scsdsc, 15); checkScsdsc (g16Scsdsc, 16); } Scsdsc test0Scsdsc (void) { return g01Scsdsc; } Scsdsc test1Scsdsc (Scsdsc x01) { return x01; } Scsdsc testvaScsdsc (int n, ...) { int i; Scsdsc rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Scsdsc); __builtin_va_end(ap); return rslt; }
extern Scsdis g01Scsdis, g02Scsdis, g03Scsdis, g04Scsdis; extern Scsdis g05Scsdis, g06Scsdis, g07Scsdis, g08Scsdis; extern Scsdis g09Scsdis, g10Scsdis, g11Scsdis, g12Scsdis; extern Scsdis g13Scsdis, g14Scsdis, g15Scsdis, g16Scsdis; extern void checkScsdis (Scsdis x, int i); void checkgScsdis (void) { checkScsdis (g01Scsdis, 1); checkScsdis (g02Scsdis, 2); checkScsdis (g03Scsdis, 3); checkScsdis (g04Scsdis, 4); checkScsdis (g05Scsdis, 5); checkScsdis (g06Scsdis, 6); checkScsdis (g07Scsdis, 7); checkScsdis (g08Scsdis, 8); checkScsdis (g09Scsdis, 9); checkScsdis (g10Scsdis, 10); checkScsdis (g11Scsdis, 11); checkScsdis (g12Scsdis, 12); checkScsdis (g13Scsdis, 13); checkScsdis (g14Scsdis, 14); checkScsdis (g15Scsdis, 15); checkScsdis (g16Scsdis, 16); } Scsdis test0Scsdis (void) { return g01Scsdis; } Scsdis test1Scsdis (Scsdis x01) { return x01; } Scsdis testvaScsdis (int n, ...) { int i; Scsdis rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Scsdis); __builtin_va_end(ap); return rslt; }
extern Scsdisc g01Scsdisc, g02Scsdisc, g03Scsdisc, g04Scsdisc; extern Scsdisc g05Scsdisc, g06Scsdisc, g07Scsdisc, g08Scsdisc; extern Scsdisc g09Scsdisc, g10Scsdisc, g11Scsdisc, g12Scsdisc; extern Scsdisc g13Scsdisc, g14Scsdisc, g15Scsdisc, g16Scsdisc; extern void checkScsdisc (Scsdisc x, int i); void checkgScsdisc (void) { checkScsdisc (g01Scsdisc, 1); checkScsdisc (g02Scsdisc, 2); checkScsdisc (g03Scsdisc, 3); checkScsdisc (g04Scsdisc, 4); checkScsdisc (g05Scsdisc, 5); checkScsdisc (g06Scsdisc, 6); checkScsdisc (g07Scsdisc, 7); checkScsdisc (g08Scsdisc, 8); checkScsdisc (g09Scsdisc, 9); checkScsdisc (g10Scsdisc, 10); checkScsdisc (g11Scsdisc, 11); checkScsdisc (g12Scsdisc, 12); checkScsdisc (g13Scsdisc, 13); checkScsdisc (g14Scsdisc, 14); checkScsdisc (g15Scsdisc, 15); checkScsdisc (g16Scsdisc, 16); } Scsdisc test0Scsdisc (void) { return g01Scsdisc; } Scsdisc test1Scsdisc (Scsdisc x01) { return x01; } Scsdisc testvaScsdisc (int n, ...) { int i; Scsdisc rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Scsdisc); __builtin_va_end(ap); return rslt; }
extern Ssds g01Ssds, g02Ssds, g03Ssds, g04Ssds; extern Ssds g05Ssds, g06Ssds, g07Ssds, g08Ssds; extern Ssds g09Ssds, g10Ssds, g11Ssds, g12Ssds; extern Ssds g13Ssds, g14Ssds, g15Ssds, g16Ssds; extern void checkSsds (Ssds x, int i); void checkgSsds (void) { checkSsds (g01Ssds, 1); checkSsds (g02Ssds, 2); checkSsds (g03Ssds, 3); checkSsds (g04Ssds, 4); checkSsds (g05Ssds, 5); checkSsds (g06Ssds, 6); checkSsds (g07Ssds, 7); checkSsds (g08Ssds, 8); checkSsds (g09Ssds, 9); checkSsds (g10Ssds, 10); checkSsds (g11Ssds, 11); checkSsds (g12Ssds, 12); checkSsds (g13Ssds, 13); checkSsds (g14Ssds, 14); checkSsds (g15Ssds, 15); checkSsds (g16Ssds, 16); } Ssds test0Ssds (void) { return g01Ssds; } Ssds test1Ssds (Ssds x01) { return x01; } Ssds testvaSsds (int n, ...) { int i; Ssds rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Ssds); __builtin_va_end(ap); return rslt; }
extern Ssdsc g01Ssdsc, g02Ssdsc, g03Ssdsc, g04Ssdsc; extern Ssdsc g05Ssdsc, g06Ssdsc, g07Ssdsc, g08Ssdsc; extern Ssdsc g09Ssdsc, g10Ssdsc, g11Ssdsc, g12Ssdsc; extern Ssdsc g13Ssdsc, g14Ssdsc, g15Ssdsc, g16Ssdsc; extern void checkSsdsc (Ssdsc x, int i); void checkgSsdsc (void) { checkSsdsc (g01Ssdsc, 1); checkSsdsc (g02Ssdsc, 2); checkSsdsc (g03Ssdsc, 3); checkSsdsc (g04Ssdsc, 4); checkSsdsc (g05Ssdsc, 5); checkSsdsc (g06Ssdsc, 6); checkSsdsc (g07Ssdsc, 7); checkSsdsc (g08Ssdsc, 8); checkSsdsc (g09Ssdsc, 9); checkSsdsc (g10Ssdsc, 10); checkSsdsc (g11Ssdsc, 11); checkSsdsc (g12Ssdsc, 12); checkSsdsc (g13Ssdsc, 13); checkSsdsc (g14Ssdsc, 14); checkSsdsc (g15Ssdsc, 15); checkSsdsc (g16Ssdsc, 16); } Ssdsc test0Ssdsc (void) { return g01Ssdsc; } Ssdsc test1Ssdsc (Ssdsc x01) { return x01; } Ssdsc testvaSsdsc (int n, ...) { int i; Ssdsc rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Ssdsc); __builtin_va_end(ap); return rslt; }
extern Scssdssc g01Scssdssc, g02Scssdssc, g03Scssdssc, g04Scssdssc; extern Scssdssc g05Scssdssc, g06Scssdssc, g07Scssdssc, g08Scssdssc; extern Scssdssc g09Scssdssc, g10Scssdssc, g11Scssdssc, g12Scssdssc; extern Scssdssc g13Scssdssc, g14Scssdssc, g15Scssdssc, g16Scssdssc; extern void checkScssdssc (Scssdssc x, int i); void checkgScssdssc (void) { checkScssdssc (g01Scssdssc, 1); checkScssdssc (g02Scssdssc, 2); checkScssdssc (g03Scssdssc, 3); checkScssdssc (g04Scssdssc, 4); checkScssdssc (g05Scssdssc, 5); checkScssdssc (g06Scssdssc, 6); checkScssdssc (g07Scssdssc, 7); checkScssdssc (g08Scssdssc, 8); checkScssdssc (g09Scssdssc, 9); checkScssdssc (g10Scssdssc, 10); checkScssdssc (g11Scssdssc, 11); checkScssdssc (g12Scssdssc, 12); checkScssdssc (g13Scssdssc, 13); checkScssdssc (g14Scssdssc, 14); checkScssdssc (g15Scssdssc, 15); checkScssdssc (g16Scssdssc, 16); } Scssdssc test0Scssdssc (void) { return g01Scssdssc; } Scssdssc test1Scssdssc (Scssdssc x01) { return x01; } Scssdssc testvaScssdssc (int n, ...) { int i; Scssdssc rslt; va_list ap; __builtin_va_start(ap, n); for (i = 0; i < n; i++) rslt = __builtin_va_arg(ap, Scssdssc); __builtin_va_end(ap); return rslt; }
