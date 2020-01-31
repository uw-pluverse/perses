






extern void abort (void);

extern int fails;



typedef int __attribute__((mode(QI))) qi;
typedef int __attribute__((mode(HI))) hi;
typedef int __attribute__((mode(SI))) si;
typedef int __attribute__((mode(DI))) di;
typedef float __attribute__((mode(SF))) sf;

typedef float __attribute__((mode(DF))) df;






typedef qi __attribute__((vector_size (8))) v8qi;
typedef qi __attribute__((vector_size (16))) v16qi;

typedef hi __attribute__((vector_size (4))) v2hi;
typedef hi __attribute__((vector_size (8))) v4hi;
typedef hi __attribute__((vector_size (16))) v8hi;

typedef si __attribute__((vector_size (8))) v2si;
typedef si __attribute__((vector_size (16))) v4si;

typedef di __attribute__((vector_size (8))) v1di;
typedef di __attribute__((vector_size (16))) v2di;

typedef sf __attribute__((vector_size (8))) v2sf;
typedef sf __attribute__((vector_size (16))) v4sf;
typedef sf __attribute__((vector_size (64))) v16sf;

typedef df __attribute__((vector_size (16))) v2df;
typedef qi __attribute__((vector_size (32))) v32qi;
typedef hi __attribute__((vector_size (32))) v16hi;
typedef si __attribute__((vector_size (32))) v8si;
typedef di __attribute__((vector_size (32))) v4di;
typedef sf __attribute__((vector_size (32))) v8sf;
typedef df __attribute__((vector_size (32))) v4df;

typedef union U32QI { v32qi v; qi a[32]; } u32qi;
typedef union U16HI { v16hi v; hi a[16]; } u16hi;
typedef union U8SI { v8si v; si a[8]; } u8si;
typedef union U4DI { v4di v; di a[4]; } u4di;
typedef union U8SF { v8sf v; sf a[8]; } u8sf;
typedef union U4DF { v4df v; df a[4]; } u4df;

typedef union U8QI { v8qi v; qi a[8]; } u8qi;
typedef union U16QI { v16qi v; qi a[16]; } u16qi;

typedef union U2HI { v2hi v; hi a[2]; } u2hi;
typedef union U4HI { v4hi v; hi a[4]; } u4hi;
typedef union U8HI { v8hi v; hi a[8]; } u8hi;

typedef union U2SI { v2si v; si a[2]; } u2si;
typedef union U4SI { v4si v; si a[4]; } u4si;

typedef union U1DI { v1di v; di a[1]; } u1di;
typedef union U2DI { v2di v; di a[2]; } u2di;

typedef union U2SF { v2sf v; sf a[2]; } u2sf;
typedef union U4SF { v4sf v; sf a[4]; } u4sf;
typedef union U16SF { v16sf v; sf a[16]; } u16sf;

typedef union U2DF { v2df v; df a[2]; } u2df;

extern v8qi g_v8qi; extern qi g_qi; extern void pass_v8qi (v8qi); extern v8qi return_v8qi (void); void checkp_8qi (qi *p) { int i; for (i = 0; i < 8; i++) { if (p[i] != g_qi + i) abort ();; } } void checkg_8qi (void) { u8qi u; qi *p = u.a; u.v = g_v8qi; checkp_8qi (p); } void init_8qi (void) { int i; u8qi u; g_qi = 101; for (i = 0; i < 8; i++) u.a[i] = 101 + i; g_v8qi = u.v; } void test_v8qi (void) { v8qi v; u8qi u; qi *p = u.a; ; ; ; init_8qi (); checkg_8qi (); ; ; pass_v8qi (g_v8qi); ; ; v = g_v8qi; pass_v8qi (v); ; ; u.v = return_v8qi (); checkp_8qi (p); ; }
extern v16qi g_v16qi; extern qi g_qi; extern void pass_v16qi (v16qi); extern v16qi return_v16qi (void); void checkp_16qi (qi *p) { int i; for (i = 0; i < 16; i++) { if (p[i] != g_qi + i) abort ();; } } void checkg_16qi (void) { u16qi u; qi *p = u.a; u.v = g_v16qi; checkp_16qi (p); } void init_16qi (void) { int i; u16qi u; g_qi = 101; for (i = 0; i < 16; i++) u.a[i] = 101 + i; g_v16qi = u.v; } void test_v16qi (void) { v16qi v; u16qi u; qi *p = u.a; ; ; ; init_16qi (); checkg_16qi (); ; ; pass_v16qi (g_v16qi); ; ; v = g_v16qi; pass_v16qi (v); ; ; u.v = return_v16qi (); checkp_16qi (p); ; }
extern v32qi g_v32qi; extern qi g_qi; extern void pass_v32qi (v32qi); extern v32qi return_v32qi (void); void checkp_32qi (qi *p) { int i; for (i = 0; i < 32; i++) { if (p[i] != g_qi + i) abort ();; } } void checkg_32qi (void) { u32qi u; qi *p = u.a; u.v = g_v32qi; checkp_32qi (p); } void init_32qi (void) { int i; u32qi u; g_qi = 90; for (i = 0; i < 32; i++) u.a[i] = 90 + i; g_v32qi = u.v; } void test_v32qi (void) { v32qi v; u32qi u; qi *p = u.a; ; ; ; init_32qi (); checkg_32qi (); ; ; pass_v32qi (g_v32qi); ; ; v = g_v32qi; pass_v32qi (v); ; ; u.v = return_v32qi (); checkp_32qi (p); ; }
extern v2hi g_v2hi; extern hi g_hi; extern void pass_v2hi (v2hi); extern v2hi return_v2hi (void); void checkp_2hi (hi *p) { int i; for (i = 0; i < 2; i++) { if (p[i] != g_hi + i) abort ();; } } void checkg_2hi (void) { u2hi u; hi *p = u.a; u.v = g_v2hi; checkp_2hi (p); } void init_2hi (void) { int i; u2hi u; g_hi = 201; for (i = 0; i < 2; i++) u.a[i] = 201 + i; g_v2hi = u.v; } void test_v2hi (void) { v2hi v; u2hi u; hi *p = u.a; ; ; ; init_2hi (); checkg_2hi (); ; ; pass_v2hi (g_v2hi); ; ; v = g_v2hi; pass_v2hi (v); ; ; u.v = return_v2hi (); checkp_2hi (p); ; }
extern v4hi g_v4hi; extern hi g_hi; extern void pass_v4hi (v4hi); extern v4hi return_v4hi (void); void checkp_4hi (hi *p) { int i; for (i = 0; i < 4; i++) { if (p[i] != g_hi + i) abort ();; } } void checkg_4hi (void) { u4hi u; hi *p = u.a; u.v = g_v4hi; checkp_4hi (p); } void init_4hi (void) { int i; u4hi u; g_hi = 202; for (i = 0; i < 4; i++) u.a[i] = 202 + i; g_v4hi = u.v; } void test_v4hi (void) { v4hi v; u4hi u; hi *p = u.a; ; ; ; init_4hi (); checkg_4hi (); ; ; pass_v4hi (g_v4hi); ; ; v = g_v4hi; pass_v4hi (v); ; ; u.v = return_v4hi (); checkp_4hi (p); ; }
extern v8hi g_v8hi; extern hi g_hi; extern void pass_v8hi (v8hi); extern v8hi return_v8hi (void); void checkp_8hi (hi *p) { int i; for (i = 0; i < 8; i++) { if (p[i] != g_hi + i) abort ();; } } void checkg_8hi (void) { u8hi u; hi *p = u.a; u.v = g_v8hi; checkp_8hi (p); } void init_8hi (void) { int i; u8hi u; g_hi = 203; for (i = 0; i < 8; i++) u.a[i] = 203 + i; g_v8hi = u.v; } void test_v8hi (void) { v8hi v; u8hi u; hi *p = u.a; ; ; ; init_8hi (); checkg_8hi (); ; ; pass_v8hi (g_v8hi); ; ; v = g_v8hi; pass_v8hi (v); ; ; u.v = return_v8hi (); checkp_8hi (p); ; }
extern v16hi g_v16hi; extern hi g_hi; extern void pass_v16hi (v16hi); extern v16hi return_v16hi (void); void checkp_16hi (hi *p) { int i; for (i = 0; i < 16; i++) { if (p[i] != g_hi + i) abort ();; } } void checkg_16hi (void) { u16hi u; hi *p = u.a; u.v = g_v16hi; checkp_16hi (p); } void init_16hi (void) { int i; u16hi u; g_hi = 203; for (i = 0; i < 16; i++) u.a[i] = 203 + i; g_v16hi = u.v; } void test_v16hi (void) { v16hi v; u16hi u; hi *p = u.a; ; ; ; init_16hi (); checkg_16hi (); ; ; pass_v16hi (g_v16hi); ; ; v = g_v16hi; pass_v16hi (v); ; ; u.v = return_v16hi (); checkp_16hi (p); ; }
extern v2si g_v2si; extern si g_si; extern void pass_v2si (v2si); extern v2si return_v2si (void); void checkp_2si (si *p) { int i; for (i = 0; i < 2; i++) { if (p[i] != g_si + i) abort ();; } } void checkg_2si (void) { u2si u; si *p = u.a; u.v = g_v2si; checkp_2si (p); } void init_2si (void) { int i; u2si u; g_si = 301; for (i = 0; i < 2; i++) u.a[i] = 301 + i; g_v2si = u.v; } void test_v2si (void) { v2si v; u2si u; si *p = u.a; ; ; ; init_2si (); checkg_2si (); ; ; pass_v2si (g_v2si); ; ; v = g_v2si; pass_v2si (v); ; ; u.v = return_v2si (); checkp_2si (p); ; }
extern v4si g_v4si; extern si g_si; extern void pass_v4si (v4si); extern v4si return_v4si (void); void checkp_4si (si *p) { int i; for (i = 0; i < 4; i++) { if (p[i] != g_si + i) abort ();; } } void checkg_4si (void) { u4si u; si *p = u.a; u.v = g_v4si; checkp_4si (p); } void init_4si (void) { int i; u4si u; g_si = 302; for (i = 0; i < 4; i++) u.a[i] = 302 + i; g_v4si = u.v; } void test_v4si (void) { v4si v; u4si u; si *p = u.a; ; ; ; init_4si (); checkg_4si (); ; ; pass_v4si (g_v4si); ; ; v = g_v4si; pass_v4si (v); ; ; u.v = return_v4si (); checkp_4si (p); ; }
extern v8si g_v8si; extern si g_si; extern void pass_v8si (v8si); extern v8si return_v8si (void); void checkp_8si (si *p) { int i; for (i = 0; i < 8; i++) { if (p[i] != g_si + i) abort ();; } } void checkg_8si (void) { u8si u; si *p = u.a; u.v = g_v8si; checkp_8si (p); } void init_8si (void) { int i; u8si u; g_si = 303; for (i = 0; i < 8; i++) u.a[i] = 303 + i; g_v8si = u.v; } void test_v8si (void) { v8si v; u8si u; si *p = u.a; ; ; ; init_8si (); checkg_8si (); ; ; pass_v8si (g_v8si); ; ; v = g_v8si; pass_v8si (v); ; ; u.v = return_v8si (); checkp_8si (p); ; }
extern v1di g_v1di; extern di g_di; extern void pass_v1di (v1di); extern v1di return_v1di (void); void checkp_1di (di *p) { int i; for (i = 0; i < 1; i++) { if (p[i] != g_di + i) abort ();; } } void checkg_1di (void) { u1di u; di *p = u.a; u.v = g_v1di; checkp_1di (p); } void init_1di (void) { int i; u1di u; g_di = 401; for (i = 0; i < 1; i++) u.a[i] = 401 + i; g_v1di = u.v; } void test_v1di (void) { v1di v; u1di u; di *p = u.a; ; ; ; init_1di (); checkg_1di (); ; ; pass_v1di (g_v1di); ; ; v = g_v1di; pass_v1di (v); ; ; u.v = return_v1di (); checkp_1di (p); ; }
extern v2di g_v2di; extern di g_di; extern void pass_v2di (v2di); extern v2di return_v2di (void); void checkp_2di (di *p) { int i; for (i = 0; i < 2; i++) { if (p[i] != g_di + i) abort ();; } } void checkg_2di (void) { u2di u; di *p = u.a; u.v = g_v2di; checkp_2di (p); } void init_2di (void) { int i; u2di u; g_di = 402; for (i = 0; i < 2; i++) u.a[i] = 402 + i; g_v2di = u.v; } void test_v2di (void) { v2di v; u2di u; di *p = u.a; ; ; ; init_2di (); checkg_2di (); ; ; pass_v2di (g_v2di); ; ; v = g_v2di; pass_v2di (v); ; ; u.v = return_v2di (); checkp_2di (p); ; }
extern v4di g_v4di; extern di g_di; extern void pass_v4di (v4di); extern v4di return_v4di (void); void checkp_4di (di *p) { int i; for (i = 0; i < 4; i++) { if (p[i] != g_di + i) abort ();; } } void checkg_4di (void) { u4di u; di *p = u.a; u.v = g_v4di; checkp_4di (p); } void init_4di (void) { int i; u4di u; g_di = 403; for (i = 0; i < 4; i++) u.a[i] = 403 + i; g_v4di = u.v; } void test_v4di (void) { v4di v; u4di u; di *p = u.a; ; ; ; init_4di (); checkg_4di (); ; ; pass_v4di (g_v4di); ; ; v = g_v4di; pass_v4di (v); ; ; u.v = return_v4di (); checkp_4di (p); ; }

