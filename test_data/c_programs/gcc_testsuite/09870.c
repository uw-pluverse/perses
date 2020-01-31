typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

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
extern void checkSfi (Sfi x, int i); extern Sfi g1sSfi, g2sSfi, g3sSfi, g4sSfi; extern Sfi g5sSfi, g6sSfi, g7sSfi, g8sSfi; extern Sfi g9sSfi, g10sSfi, g11sSfi, g12sSfi; extern Sfi g13sSfi, g14sSfi, g15sSfi, g16sSfi; void checkgSfi (void) { checkSfi ( g1sSfi, 1); checkSfi ( g2sSfi, 2); checkSfi ( g3sSfi, 3); checkSfi ( g4sSfi, 4); checkSfi ( g5sSfi, 5); checkSfi ( g6sSfi, 6); checkSfi ( g7sSfi, 7); checkSfi ( g8sSfi, 8); checkSfi ( g9sSfi, 9); checkSfi ( g10sSfi, 10); checkSfi ( g11sSfi, 11); checkSfi ( g12sSfi, 12); checkSfi ( g13sSfi, 13); checkSfi ( g14sSfi, 14); checkSfi ( g15sSfi, 15); checkSfi ( g16sSfi, 16); } void testSfi (Sfi s1, Sfi s2, Sfi s3, Sfi s4, Sfi s5, Sfi s6, Sfi s7, Sfi s8, Sfi s9, Sfi s10, Sfi s11, Sfi s12, Sfi s13, Sfi s14, Sfi s15, Sfi s16) { checkSfi (s1, 1); checkSfi (s2, 2); checkSfi (s3, 3); checkSfi (s4, 4); checkSfi (s5, 5); checkSfi (s6, 6); checkSfi (s7, 7); checkSfi (s8, 8); checkSfi (s9, 9); checkSfi (s10, 10); checkSfi (s11, 11); checkSfi (s12, 12); checkSfi (s13, 13); checkSfi (s14, 14); checkSfi (s15, 15); checkSfi (s16, 16); } void testvaSfi (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Sfi t = __builtin_va_arg(ap, Sfi); checkSfi (t, i+1); } __builtin_va_end(ap); } }
extern void checkSfii (Sfii x, int i); extern Sfii g1sSfii, g2sSfii, g3sSfii, g4sSfii; extern Sfii g5sSfii, g6sSfii, g7sSfii, g8sSfii; extern Sfii g9sSfii, g10sSfii, g11sSfii, g12sSfii; extern Sfii g13sSfii, g14sSfii, g15sSfii, g16sSfii; void checkgSfii (void) { checkSfii ( g1sSfii, 1); checkSfii ( g2sSfii, 2); checkSfii ( g3sSfii, 3); checkSfii ( g4sSfii, 4); checkSfii ( g5sSfii, 5); checkSfii ( g6sSfii, 6); checkSfii ( g7sSfii, 7); checkSfii ( g8sSfii, 8); checkSfii ( g9sSfii, 9); checkSfii ( g10sSfii, 10); checkSfii ( g11sSfii, 11); checkSfii ( g12sSfii, 12); checkSfii ( g13sSfii, 13); checkSfii ( g14sSfii, 14); checkSfii ( g15sSfii, 15); checkSfii ( g16sSfii, 16); } void testSfii (Sfii s1, Sfii s2, Sfii s3, Sfii s4, Sfii s5, Sfii s6, Sfii s7, Sfii s8, Sfii s9, Sfii s10, Sfii s11, Sfii s12, Sfii s13, Sfii s14, Sfii s15, Sfii s16) { checkSfii (s1, 1); checkSfii (s2, 2); checkSfii (s3, 3); checkSfii (s4, 4); checkSfii (s5, 5); checkSfii (s6, 6); checkSfii (s7, 7); checkSfii (s8, 8); checkSfii (s9, 9); checkSfii (s10, 10); checkSfii (s11, 11); checkSfii (s12, 12); checkSfii (s13, 13); checkSfii (s14, 14); checkSfii (s15, 15); checkSfii (s16, 16); } void testvaSfii (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Sfii t = __builtin_va_arg(ap, Sfii); checkSfii (t, i+1); } __builtin_va_end(ap); } }
extern void checkSfifi (Sfifi x, int i); extern Sfifi g1sSfifi, g2sSfifi, g3sSfifi, g4sSfifi; extern Sfifi g5sSfifi, g6sSfifi, g7sSfifi, g8sSfifi; extern Sfifi g9sSfifi, g10sSfifi, g11sSfifi, g12sSfifi; extern Sfifi g13sSfifi, g14sSfifi, g15sSfifi, g16sSfifi; void checkgSfifi (void) { checkSfifi ( g1sSfifi, 1); checkSfifi ( g2sSfifi, 2); checkSfifi ( g3sSfifi, 3); checkSfifi ( g4sSfifi, 4); checkSfifi ( g5sSfifi, 5); checkSfifi ( g6sSfifi, 6); checkSfifi ( g7sSfifi, 7); checkSfifi ( g8sSfifi, 8); checkSfifi ( g9sSfifi, 9); checkSfifi ( g10sSfifi, 10); checkSfifi ( g11sSfifi, 11); checkSfifi ( g12sSfifi, 12); checkSfifi ( g13sSfifi, 13); checkSfifi ( g14sSfifi, 14); checkSfifi ( g15sSfifi, 15); checkSfifi ( g16sSfifi, 16); } void testSfifi (Sfifi s1, Sfifi s2, Sfifi s3, Sfifi s4, Sfifi s5, Sfifi s6, Sfifi s7, Sfifi s8, Sfifi s9, Sfifi s10, Sfifi s11, Sfifi s12, Sfifi s13, Sfifi s14, Sfifi s15, Sfifi s16) { checkSfifi (s1, 1); checkSfifi (s2, 2); checkSfifi (s3, 3); checkSfifi (s4, 4); checkSfifi (s5, 5); checkSfifi (s6, 6); checkSfifi (s7, 7); checkSfifi (s8, 8); checkSfifi (s9, 9); checkSfifi (s10, 10); checkSfifi (s11, 11); checkSfifi (s12, 12); checkSfifi (s13, 13); checkSfifi (s14, 14); checkSfifi (s15, 15); checkSfifi (s16, 16); } void testvaSfifi (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Sfifi t = __builtin_va_arg(ap, Sfifi); checkSfifi (t, i+1); } __builtin_va_end(ap); } }
extern void checkSfiifii (Sfiifii x, int i); extern Sfiifii g1sSfiifii, g2sSfiifii, g3sSfiifii, g4sSfiifii; extern Sfiifii g5sSfiifii, g6sSfiifii, g7sSfiifii, g8sSfiifii; extern Sfiifii g9sSfiifii, g10sSfiifii, g11sSfiifii, g12sSfiifii; extern Sfiifii g13sSfiifii, g14sSfiifii, g15sSfiifii, g16sSfiifii; void checkgSfiifii (void) { checkSfiifii ( g1sSfiifii, 1); checkSfiifii ( g2sSfiifii, 2); checkSfiifii ( g3sSfiifii, 3); checkSfiifii ( g4sSfiifii, 4); checkSfiifii ( g5sSfiifii, 5); checkSfiifii ( g6sSfiifii, 6); checkSfiifii ( g7sSfiifii, 7); checkSfiifii ( g8sSfiifii, 8); checkSfiifii ( g9sSfiifii, 9); checkSfiifii ( g10sSfiifii, 10); checkSfiifii ( g11sSfiifii, 11); checkSfiifii ( g12sSfiifii, 12); checkSfiifii ( g13sSfiifii, 13); checkSfiifii ( g14sSfiifii, 14); checkSfiifii ( g15sSfiifii, 15); checkSfiifii ( g16sSfiifii, 16); } void testSfiifii (Sfiifii s1, Sfiifii s2, Sfiifii s3, Sfiifii s4, Sfiifii s5, Sfiifii s6, Sfiifii s7, Sfiifii s8, Sfiifii s9, Sfiifii s10, Sfiifii s11, Sfiifii s12, Sfiifii s13, Sfiifii s14, Sfiifii s15, Sfiifii s16) { checkSfiifii (s1, 1); checkSfiifii (s2, 2); checkSfiifii (s3, 3); checkSfiifii (s4, 4); checkSfiifii (s5, 5); checkSfiifii (s6, 6); checkSfiifii (s7, 7); checkSfiifii (s8, 8); checkSfiifii (s9, 9); checkSfiifii (s10, 10); checkSfiifii (s11, 11); checkSfiifii (s12, 12); checkSfiifii (s13, 13); checkSfiifii (s14, 14); checkSfiifii (s15, 15); checkSfiifii (s16, 16); } void testvaSfiifii (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Sfiifii t = __builtin_va_arg(ap, Sfiifii); checkSfiifii (t, i+1); } __builtin_va_end(ap); } }
