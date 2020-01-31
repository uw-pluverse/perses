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
extern Scdc g1sScdc, g2sScdc, g3sScdc, g4sScdc; extern Scdc g5sScdc, g6sScdc, g7sScdc, g8sScdc; extern Scdc g9sScdc, g10sScdc, g11sScdc, g12sScdc; extern Scdc g13sScdc, g14sScdc, g15sScdc, g16sScdc; void checkgScdc (void) { checkScdc ( g1sScdc, 1); checkScdc ( g2sScdc, 2); checkScdc ( g3sScdc, 3); checkScdc ( g4sScdc, 4); checkScdc ( g5sScdc, 5); checkScdc ( g6sScdc, 6); checkScdc ( g7sScdc, 7); checkScdc ( g8sScdc, 8); checkScdc ( g9sScdc, 9); checkScdc ( g10sScdc, 10); checkScdc ( g11sScdc, 11); checkScdc ( g12sScdc, 12); checkScdc ( g13sScdc, 13); checkScdc ( g14sScdc, 14); checkScdc ( g15sScdc, 15); checkScdc ( g16sScdc, 16); } void testScdc (Scdc s1, Scdc s2, Scdc s3, Scdc s4, Scdc s5, Scdc s6, Scdc s7, Scdc s8, Scdc s9, Scdc s10, Scdc s11, Scdc s12, Scdc s13, Scdc s14, Scdc s15, Scdc s16) { checkScdc (s1, 1); checkScdc (s2, 2); checkScdc (s3, 3); checkScdc (s4, 4); checkScdc (s5, 5); checkScdc (s6, 6); checkScdc (s7, 7); checkScdc (s8, 8); checkScdc (s9, 9); checkScdc (s10, 10); checkScdc (s11, 11); checkScdc (s12, 12); checkScdc (s13, 13); checkScdc (s14, 14); checkScdc (s15, 15); checkScdc (s16, 16); } void testvaScdc (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Scdc t = __builtin_va_arg(ap, Scdc); checkScdc (t, i+1); } __builtin_va_end(ap); } }
extern Sd g1sSd, g2sSd, g3sSd, g4sSd; extern Sd g5sSd, g6sSd, g7sSd, g8sSd; extern Sd g9sSd, g10sSd, g11sSd, g12sSd; extern Sd g13sSd, g14sSd, g15sSd, g16sSd; void checkgSd (void) { checkSd ( g1sSd, 1); checkSd ( g2sSd, 2); checkSd ( g3sSd, 3); checkSd ( g4sSd, 4); checkSd ( g5sSd, 5); checkSd ( g6sSd, 6); checkSd ( g7sSd, 7); checkSd ( g8sSd, 8); checkSd ( g9sSd, 9); checkSd ( g10sSd, 10); checkSd ( g11sSd, 11); checkSd ( g12sSd, 12); checkSd ( g13sSd, 13); checkSd ( g14sSd, 14); checkSd ( g15sSd, 15); checkSd ( g16sSd, 16); } void testSd (Sd s1, Sd s2, Sd s3, Sd s4, Sd s5, Sd s6, Sd s7, Sd s8, Sd s9, Sd s10, Sd s11, Sd s12, Sd s13, Sd s14, Sd s15, Sd s16) { checkSd (s1, 1); checkSd (s2, 2); checkSd (s3, 3); checkSd (s4, 4); checkSd (s5, 5); checkSd (s6, 6); checkSd (s7, 7); checkSd (s8, 8); checkSd (s9, 9); checkSd (s10, 10); checkSd (s11, 11); checkSd (s12, 12); checkSd (s13, 13); checkSd (s14, 14); checkSd (s15, 15); checkSd (s16, 16); } void testvaSd (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Sd t = __builtin_va_arg(ap, Sd); checkSd (t, i+1); } __builtin_va_end(ap); } }
extern Sdi g1sSdi, g2sSdi, g3sSdi, g4sSdi; extern Sdi g5sSdi, g6sSdi, g7sSdi, g8sSdi; extern Sdi g9sSdi, g10sSdi, g11sSdi, g12sSdi; extern Sdi g13sSdi, g14sSdi, g15sSdi, g16sSdi; void checkgSdi (void) { checkSdi ( g1sSdi, 1); checkSdi ( g2sSdi, 2); checkSdi ( g3sSdi, 3); checkSdi ( g4sSdi, 4); checkSdi ( g5sSdi, 5); checkSdi ( g6sSdi, 6); checkSdi ( g7sSdi, 7); checkSdi ( g8sSdi, 8); checkSdi ( g9sSdi, 9); checkSdi ( g10sSdi, 10); checkSdi ( g11sSdi, 11); checkSdi ( g12sSdi, 12); checkSdi ( g13sSdi, 13); checkSdi ( g14sSdi, 14); checkSdi ( g15sSdi, 15); checkSdi ( g16sSdi, 16); } void testSdi (Sdi s1, Sdi s2, Sdi s3, Sdi s4, Sdi s5, Sdi s6, Sdi s7, Sdi s8, Sdi s9, Sdi s10, Sdi s11, Sdi s12, Sdi s13, Sdi s14, Sdi s15, Sdi s16) { checkSdi (s1, 1); checkSdi (s2, 2); checkSdi (s3, 3); checkSdi (s4, 4); checkSdi (s5, 5); checkSdi (s6, 6); checkSdi (s7, 7); checkSdi (s8, 8); checkSdi (s9, 9); checkSdi (s10, 10); checkSdi (s11, 11); checkSdi (s12, 12); checkSdi (s13, 13); checkSdi (s14, 14); checkSdi (s15, 15); checkSdi (s16, 16); } void testvaSdi (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Sdi t = __builtin_va_arg(ap, Sdi); checkSdi (t, i+1); } __builtin_va_end(ap); } }
extern Scsdsc g1sScsdsc, g2sScsdsc, g3sScsdsc, g4sScsdsc; extern Scsdsc g5sScsdsc, g6sScsdsc, g7sScsdsc, g8sScsdsc; extern Scsdsc g9sScsdsc, g10sScsdsc, g11sScsdsc, g12sScsdsc; extern Scsdsc g13sScsdsc, g14sScsdsc, g15sScsdsc, g16sScsdsc; void checkgScsdsc (void) { checkScsdsc ( g1sScsdsc, 1); checkScsdsc ( g2sScsdsc, 2); checkScsdsc ( g3sScsdsc, 3); checkScsdsc ( g4sScsdsc, 4); checkScsdsc ( g5sScsdsc, 5); checkScsdsc ( g6sScsdsc, 6); checkScsdsc ( g7sScsdsc, 7); checkScsdsc ( g8sScsdsc, 8); checkScsdsc ( g9sScsdsc, 9); checkScsdsc ( g10sScsdsc, 10); checkScsdsc ( g11sScsdsc, 11); checkScsdsc ( g12sScsdsc, 12); checkScsdsc ( g13sScsdsc, 13); checkScsdsc ( g14sScsdsc, 14); checkScsdsc ( g15sScsdsc, 15); checkScsdsc ( g16sScsdsc, 16); } void testScsdsc (Scsdsc s1, Scsdsc s2, Scsdsc s3, Scsdsc s4, Scsdsc s5, Scsdsc s6, Scsdsc s7, Scsdsc s8, Scsdsc s9, Scsdsc s10, Scsdsc s11, Scsdsc s12, Scsdsc s13, Scsdsc s14, Scsdsc s15, Scsdsc s16) { checkScsdsc (s1, 1); checkScsdsc (s2, 2); checkScsdsc (s3, 3); checkScsdsc (s4, 4); checkScsdsc (s5, 5); checkScsdsc (s6, 6); checkScsdsc (s7, 7); checkScsdsc (s8, 8); checkScsdsc (s9, 9); checkScsdsc (s10, 10); checkScsdsc (s11, 11); checkScsdsc (s12, 12); checkScsdsc (s13, 13); checkScsdsc (s14, 14); checkScsdsc (s15, 15); checkScsdsc (s16, 16); } void testvaScsdsc (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Scsdsc t = __builtin_va_arg(ap, Scsdsc); checkScsdsc (t, i+1); } __builtin_va_end(ap); } }
extern Scsdis g1sScsdis, g2sScsdis, g3sScsdis, g4sScsdis; extern Scsdis g5sScsdis, g6sScsdis, g7sScsdis, g8sScsdis; extern Scsdis g9sScsdis, g10sScsdis, g11sScsdis, g12sScsdis; extern Scsdis g13sScsdis, g14sScsdis, g15sScsdis, g16sScsdis; void checkgScsdis (void) { checkScsdis ( g1sScsdis, 1); checkScsdis ( g2sScsdis, 2); checkScsdis ( g3sScsdis, 3); checkScsdis ( g4sScsdis, 4); checkScsdis ( g5sScsdis, 5); checkScsdis ( g6sScsdis, 6); checkScsdis ( g7sScsdis, 7); checkScsdis ( g8sScsdis, 8); checkScsdis ( g9sScsdis, 9); checkScsdis ( g10sScsdis, 10); checkScsdis ( g11sScsdis, 11); checkScsdis ( g12sScsdis, 12); checkScsdis ( g13sScsdis, 13); checkScsdis ( g14sScsdis, 14); checkScsdis ( g15sScsdis, 15); checkScsdis ( g16sScsdis, 16); } void testScsdis (Scsdis s1, Scsdis s2, Scsdis s3, Scsdis s4, Scsdis s5, Scsdis s6, Scsdis s7, Scsdis s8, Scsdis s9, Scsdis s10, Scsdis s11, Scsdis s12, Scsdis s13, Scsdis s14, Scsdis s15, Scsdis s16) { checkScsdis (s1, 1); checkScsdis (s2, 2); checkScsdis (s3, 3); checkScsdis (s4, 4); checkScsdis (s5, 5); checkScsdis (s6, 6); checkScsdis (s7, 7); checkScsdis (s8, 8); checkScsdis (s9, 9); checkScsdis (s10, 10); checkScsdis (s11, 11); checkScsdis (s12, 12); checkScsdis (s13, 13); checkScsdis (s14, 14); checkScsdis (s15, 15); checkScsdis (s16, 16); } void testvaScsdis (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Scsdis t = __builtin_va_arg(ap, Scsdis); checkScsdis (t, i+1); } __builtin_va_end(ap); } }
extern Scsdisc g1sScsdisc, g2sScsdisc, g3sScsdisc, g4sScsdisc; extern Scsdisc g5sScsdisc, g6sScsdisc, g7sScsdisc, g8sScsdisc; extern Scsdisc g9sScsdisc, g10sScsdisc, g11sScsdisc, g12sScsdisc; extern Scsdisc g13sScsdisc, g14sScsdisc, g15sScsdisc, g16sScsdisc; void checkgScsdisc (void) { checkScsdisc ( g1sScsdisc, 1); checkScsdisc ( g2sScsdisc, 2); checkScsdisc ( g3sScsdisc, 3); checkScsdisc ( g4sScsdisc, 4); checkScsdisc ( g5sScsdisc, 5); checkScsdisc ( g6sScsdisc, 6); checkScsdisc ( g7sScsdisc, 7); checkScsdisc ( g8sScsdisc, 8); checkScsdisc ( g9sScsdisc, 9); checkScsdisc ( g10sScsdisc, 10); checkScsdisc ( g11sScsdisc, 11); checkScsdisc ( g12sScsdisc, 12); checkScsdisc ( g13sScsdisc, 13); checkScsdisc ( g14sScsdisc, 14); checkScsdisc ( g15sScsdisc, 15); checkScsdisc ( g16sScsdisc, 16); } void testScsdisc (Scsdisc s1, Scsdisc s2, Scsdisc s3, Scsdisc s4, Scsdisc s5, Scsdisc s6, Scsdisc s7, Scsdisc s8, Scsdisc s9, Scsdisc s10, Scsdisc s11, Scsdisc s12, Scsdisc s13, Scsdisc s14, Scsdisc s15, Scsdisc s16) { checkScsdisc (s1, 1); checkScsdisc (s2, 2); checkScsdisc (s3, 3); checkScsdisc (s4, 4); checkScsdisc (s5, 5); checkScsdisc (s6, 6); checkScsdisc (s7, 7); checkScsdisc (s8, 8); checkScsdisc (s9, 9); checkScsdisc (s10, 10); checkScsdisc (s11, 11); checkScsdisc (s12, 12); checkScsdisc (s13, 13); checkScsdisc (s14, 14); checkScsdisc (s15, 15); checkScsdisc (s16, 16); } void testvaScsdisc (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Scsdisc t = __builtin_va_arg(ap, Scsdisc); checkScsdisc (t, i+1); } __builtin_va_end(ap); } }
extern Ssds g1sSsds, g2sSsds, g3sSsds, g4sSsds; extern Ssds g5sSsds, g6sSsds, g7sSsds, g8sSsds; extern Ssds g9sSsds, g10sSsds, g11sSsds, g12sSsds; extern Ssds g13sSsds, g14sSsds, g15sSsds, g16sSsds; void checkgSsds (void) { checkSsds ( g1sSsds, 1); checkSsds ( g2sSsds, 2); checkSsds ( g3sSsds, 3); checkSsds ( g4sSsds, 4); checkSsds ( g5sSsds, 5); checkSsds ( g6sSsds, 6); checkSsds ( g7sSsds, 7); checkSsds ( g8sSsds, 8); checkSsds ( g9sSsds, 9); checkSsds ( g10sSsds, 10); checkSsds ( g11sSsds, 11); checkSsds ( g12sSsds, 12); checkSsds ( g13sSsds, 13); checkSsds ( g14sSsds, 14); checkSsds ( g15sSsds, 15); checkSsds ( g16sSsds, 16); } void testSsds (Ssds s1, Ssds s2, Ssds s3, Ssds s4, Ssds s5, Ssds s6, Ssds s7, Ssds s8, Ssds s9, Ssds s10, Ssds s11, Ssds s12, Ssds s13, Ssds s14, Ssds s15, Ssds s16) { checkSsds (s1, 1); checkSsds (s2, 2); checkSsds (s3, 3); checkSsds (s4, 4); checkSsds (s5, 5); checkSsds (s6, 6); checkSsds (s7, 7); checkSsds (s8, 8); checkSsds (s9, 9); checkSsds (s10, 10); checkSsds (s11, 11); checkSsds (s12, 12); checkSsds (s13, 13); checkSsds (s14, 14); checkSsds (s15, 15); checkSsds (s16, 16); } void testvaSsds (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Ssds t = __builtin_va_arg(ap, Ssds); checkSsds (t, i+1); } __builtin_va_end(ap); } }
extern Ssdsc g1sSsdsc, g2sSsdsc, g3sSsdsc, g4sSsdsc; extern Ssdsc g5sSsdsc, g6sSsdsc, g7sSsdsc, g8sSsdsc; extern Ssdsc g9sSsdsc, g10sSsdsc, g11sSsdsc, g12sSsdsc; extern Ssdsc g13sSsdsc, g14sSsdsc, g15sSsdsc, g16sSsdsc; void checkgSsdsc (void) { checkSsdsc ( g1sSsdsc, 1); checkSsdsc ( g2sSsdsc, 2); checkSsdsc ( g3sSsdsc, 3); checkSsdsc ( g4sSsdsc, 4); checkSsdsc ( g5sSsdsc, 5); checkSsdsc ( g6sSsdsc, 6); checkSsdsc ( g7sSsdsc, 7); checkSsdsc ( g8sSsdsc, 8); checkSsdsc ( g9sSsdsc, 9); checkSsdsc ( g10sSsdsc, 10); checkSsdsc ( g11sSsdsc, 11); checkSsdsc ( g12sSsdsc, 12); checkSsdsc ( g13sSsdsc, 13); checkSsdsc ( g14sSsdsc, 14); checkSsdsc ( g15sSsdsc, 15); checkSsdsc ( g16sSsdsc, 16); } void testSsdsc (Ssdsc s1, Ssdsc s2, Ssdsc s3, Ssdsc s4, Ssdsc s5, Ssdsc s6, Ssdsc s7, Ssdsc s8, Ssdsc s9, Ssdsc s10, Ssdsc s11, Ssdsc s12, Ssdsc s13, Ssdsc s14, Ssdsc s15, Ssdsc s16) { checkSsdsc (s1, 1); checkSsdsc (s2, 2); checkSsdsc (s3, 3); checkSsdsc (s4, 4); checkSsdsc (s5, 5); checkSsdsc (s6, 6); checkSsdsc (s7, 7); checkSsdsc (s8, 8); checkSsdsc (s9, 9); checkSsdsc (s10, 10); checkSsdsc (s11, 11); checkSsdsc (s12, 12); checkSsdsc (s13, 13); checkSsdsc (s14, 14); checkSsdsc (s15, 15); checkSsdsc (s16, 16); } void testvaSsdsc (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Ssdsc t = __builtin_va_arg(ap, Ssdsc); checkSsdsc (t, i+1); } __builtin_va_end(ap); } }
extern Scssdssc g1sScssdssc, g2sScssdssc, g3sScssdssc, g4sScssdssc; extern Scssdssc g5sScssdssc, g6sScssdssc, g7sScssdssc, g8sScssdssc; extern Scssdssc g9sScssdssc, g10sScssdssc, g11sScssdssc, g12sScssdssc; extern Scssdssc g13sScssdssc, g14sScssdssc, g15sScssdssc, g16sScssdssc; void checkgScssdssc (void) { checkScssdssc ( g1sScssdssc, 1); checkScssdssc ( g2sScssdssc, 2); checkScssdssc ( g3sScssdssc, 3); checkScssdssc ( g4sScssdssc, 4); checkScssdssc ( g5sScssdssc, 5); checkScssdssc ( g6sScssdssc, 6); checkScssdssc ( g7sScssdssc, 7); checkScssdssc ( g8sScssdssc, 8); checkScssdssc ( g9sScssdssc, 9); checkScssdssc ( g10sScssdssc, 10); checkScssdssc ( g11sScssdssc, 11); checkScssdssc ( g12sScssdssc, 12); checkScssdssc ( g13sScssdssc, 13); checkScssdssc ( g14sScssdssc, 14); checkScssdssc ( g15sScssdssc, 15); checkScssdssc ( g16sScssdssc, 16); } void testScssdssc (Scssdssc s1, Scssdssc s2, Scssdssc s3, Scssdssc s4, Scssdssc s5, Scssdssc s6, Scssdssc s7, Scssdssc s8, Scssdssc s9, Scssdssc s10, Scssdssc s11, Scssdssc s12, Scssdssc s13, Scssdssc s14, Scssdssc s15, Scssdssc s16) { checkScssdssc (s1, 1); checkScssdssc (s2, 2); checkScssdssc (s3, 3); checkScssdssc (s4, 4); checkScssdssc (s5, 5); checkScssdssc (s6, 6); checkScssdssc (s7, 7); checkScssdssc (s8, 8); checkScssdssc (s9, 9); checkScssdssc (s10, 10); checkScssdssc (s11, 11); checkScssdssc (s12, 12); checkScssdssc (s13, 13); checkScssdssc (s14, 14); checkScssdssc (s15, 15); checkScssdssc (s16, 16); } void testvaScssdssc (int n, ...) { int i; va_list ap; if (test_va) { __builtin_va_start(ap, n); for (i = 0; i < n; i++) { Scssdssc t = __builtin_va_arg(ap, Scssdssc); checkScssdssc (t, i+1); } __builtin_va_end(ap); } }
