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

extern void checkScd (Scd x, int i);
extern void checkScdc (Scdc x, int i);
extern void checkSd (Sd x, int i);
extern void checkSdi (Sdi x, int i);
extern void checkScsds (Scsds x, int i);
extern void checkScsdsc (Scsdsc x, int i);
extern void checkScsdis (Scsdis x, int i);
extern void checkScsdisc (Scsdisc x, int i);
extern void checkSsds (Ssds x, int i);
extern void checkSsdsc (Ssdsc x, int i);
extern void checkScssdss (Scssdss x, int i);
extern void checkScssdssc (Scssdssc x, int i);




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
extern Scd g1sScd, g2sScd, g3sScd, g4sScd; extern Scd g5sScd, g6sScd, g7sScd, g8sScd; extern Scd g9sScd, g10sScd, g11sScd, g12sScd; extern Scd g13sScd, g14sScd, g15sScd, g16sScd; void checkgScd (void) { checkScd ( g1sScd, 1); checkScd ( g2sScd, 2); checkScd ( g3sScd, 3); checkScd ( g4sScd, 4); checkScd ( g5sScd, 5); checkScd ( g6sScd, 6); checkScd ( g7sScd, 7); checkScd ( g8sScd, 8); checkScd ( g9sScd, 9); checkScd ( g10sScd, 10); checkScd ( g11sScd, 11); checkScd ( g12sScd, 12); checkScd ( g13sScd, 13); checkScd ( g14sScd, 14); checkScd ( g15sScd, 15); checkScd ( g16sScd, 16); } void testScd (Scd s1, Scd s2, Scd s3, Scd s4, Scd s5, Scd s6, Scd s7, Scd s8, Scd s9, Scd s10, Scd s11, Scd s12, Scd s13, Scd s14, Scd s15, Scd s16) { checkScd (s1, 1); checkScd (s2, 2); checkScd (s3, 3); checkScd (s4, 4); checkScd (s5, 5); checkScd (s6, 6); checkScd (s7, 7); checkScd (s8, 8); checkScd (s9, 9); checkScd (s10, 10); checkScd (s11, 11); checkScd (s12, 12); checkScd (s13, 13); checkScd (s14, 14); checkScd (s15, 15); checkScd (s16, 16); } void testvaScd (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Scd t = __builtin_va_arg(ap, Scd); checkScd (t, i+1); } __builtin_va_end(ap); } }
extern Scsds g1sScsds, g2sScsds, g3sScsds, g4sScsds; extern Scsds g5sScsds, g6sScsds, g7sScsds, g8sScsds; extern Scsds g9sScsds, g10sScsds, g11sScsds, g12sScsds; extern Scsds g13sScsds, g14sScsds, g15sScsds, g16sScsds; void checkgScsds (void) { checkScsds ( g1sScsds, 1); checkScsds ( g2sScsds, 2); checkScsds ( g3sScsds, 3); checkScsds ( g4sScsds, 4); checkScsds ( g5sScsds, 5); checkScsds ( g6sScsds, 6); checkScsds ( g7sScsds, 7); checkScsds ( g8sScsds, 8); checkScsds ( g9sScsds, 9); checkScsds ( g10sScsds, 10); checkScsds ( g11sScsds, 11); checkScsds ( g12sScsds, 12); checkScsds ( g13sScsds, 13); checkScsds ( g14sScsds, 14); checkScsds ( g15sScsds, 15); checkScsds ( g16sScsds, 16); } void testScsds (Scsds s1, Scsds s2, Scsds s3, Scsds s4, Scsds s5, Scsds s6, Scsds s7, Scsds s8, Scsds s9, Scsds s10, Scsds s11, Scsds s12, Scsds s13, Scsds s14, Scsds s15, Scsds s16) { checkScsds (s1, 1); checkScsds (s2, 2); checkScsds (s3, 3); checkScsds (s4, 4); checkScsds (s5, 5); checkScsds (s6, 6); checkScsds (s7, 7); checkScsds (s8, 8); checkScsds (s9, 9); checkScsds (s10, 10); checkScsds (s11, 11); checkScsds (s12, 12); checkScsds (s13, 13); checkScsds (s14, 14); checkScsds (s15, 15); checkScsds (s16, 16); } void testvaScsds (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Scsds t = __builtin_va_arg(ap, Scsds); checkScsds (t, i+1); } __builtin_va_end(ap); } }
extern Scssdss g1sScssdss, g2sScssdss, g3sScssdss, g4sScssdss; extern Scssdss g5sScssdss, g6sScssdss, g7sScssdss, g8sScssdss; extern Scssdss g9sScssdss, g10sScssdss, g11sScssdss, g12sScssdss; extern Scssdss g13sScssdss, g14sScssdss, g15sScssdss, g16sScssdss; void checkgScssdss (void) { checkScssdss ( g1sScssdss, 1); checkScssdss ( g2sScssdss, 2); checkScssdss ( g3sScssdss, 3); checkScssdss ( g4sScssdss, 4); checkScssdss ( g5sScssdss, 5); checkScssdss ( g6sScssdss, 6); checkScssdss ( g7sScssdss, 7); checkScssdss ( g8sScssdss, 8); checkScssdss ( g9sScssdss, 9); checkScssdss ( g10sScssdss, 10); checkScssdss ( g11sScssdss, 11); checkScssdss ( g12sScssdss, 12); checkScssdss ( g13sScssdss, 13); checkScssdss ( g14sScssdss, 14); checkScssdss ( g15sScssdss, 15); checkScssdss ( g16sScssdss, 16); } void testScssdss (Scssdss s1, Scssdss s2, Scssdss s3, Scssdss s4, Scssdss s5, Scssdss s6, Scssdss s7, Scssdss s8, Scssdss s9, Scssdss s10, Scssdss s11, Scssdss s12, Scssdss s13, Scssdss s14, Scssdss s15, Scssdss s16) { checkScssdss (s1, 1); checkScssdss (s2, 2); checkScssdss (s3, 3); checkScssdss (s4, 4); checkScssdss (s5, 5); checkScssdss (s6, 6); checkScssdss (s7, 7); checkScssdss (s8, 8); checkScssdss (s9, 9); checkScssdss (s10, 10); checkScssdss (s11, 11); checkScssdss (s12, 12); checkScssdss (s13, 13); checkScssdss (s14, 14); checkScssdss (s15, 15); checkScssdss (s16, 16); } void testvaScssdss (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Scssdss t = __builtin_va_arg(ap, Scssdss); checkScssdss (t, i+1); } __builtin_va_end(ap); } }
