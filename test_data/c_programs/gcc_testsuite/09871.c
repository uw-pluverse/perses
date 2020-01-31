






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

extern v2sf g_v2sf; extern sf g_sf; extern void pass_v2sf (v2sf); extern v2sf return_v2sf (void); void checkp_2sf (sf *p) { int i; for (i = 0; i < 2; i++) { if (p[i] != g_sf + i) abort ();; } } void checkg_2sf (void) { u2sf u; sf *p = u.a; u.v = g_v2sf; checkp_2sf (p); } void init_2sf (void) { int i; u2sf u; g_sf = 301.0; for (i = 0; i < 2; i++) u.a[i] = 301.0 + i; g_v2sf = u.v; } void test_v2sf (void) { v2sf v; u2sf u; sf *p = u.a; ; ; ; init_2sf (); checkg_2sf (); ; ; pass_v2sf (g_v2sf); ; ; v = g_v2sf; pass_v2sf (v); ; ; u.v = return_v2sf (); checkp_2sf (p); ; }
extern v4sf g_v4sf; extern sf g_sf; extern void pass_v4sf (v4sf); extern v4sf return_v4sf (void); void checkp_4sf (sf *p) { int i; for (i = 0; i < 4; i++) { if (p[i] != g_sf + i) abort ();; } } void checkg_4sf (void) { u4sf u; sf *p = u.a; u.v = g_v4sf; checkp_4sf (p); } void init_4sf (void) { int i; u4sf u; g_sf = 302.0; for (i = 0; i < 4; i++) u.a[i] = 302.0 + i; g_v4sf = u.v; } void test_v4sf (void) { v4sf v; u4sf u; sf *p = u.a; ; ; ; init_4sf (); checkg_4sf (); ; ; pass_v4sf (g_v4sf); ; ; v = g_v4sf; pass_v4sf (v); ; ; u.v = return_v4sf (); checkp_4sf (p); ; }
extern v8sf g_v8sf; extern sf g_sf; extern void pass_v8sf (v8sf); extern v8sf return_v8sf (void); void checkp_8sf (sf *p) { int i; for (i = 0; i < 8; i++) { if (p[i] != g_sf + i) abort ();; } } void checkg_8sf (void) { u8sf u; sf *p = u.a; u.v = g_v8sf; checkp_8sf (p); } void init_8sf (void) { int i; u8sf u; g_sf = 303.0; for (i = 0; i < 8; i++) u.a[i] = 303.0 + i; g_v8sf = u.v; } void test_v8sf (void) { v8sf v; u8sf u; sf *p = u.a; ; ; ; init_8sf (); checkg_8sf (); ; ; pass_v8sf (g_v8sf); ; ; v = g_v8sf; pass_v8sf (v); ; ; u.v = return_v8sf (); checkp_8sf (p); ; }
extern v16sf g_v16sf; extern sf g_sf; extern void pass_v16sf (v16sf); extern v16sf return_v16sf (void); void checkp_16sf (sf *p) { int i; for (i = 0; i < 16; i++) { if (p[i] != g_sf + i) abort ();; } } void checkg_16sf (void) { u16sf u; sf *p = u.a; u.v = g_v16sf; checkp_16sf (p); } void init_16sf (void) { int i; u16sf u; g_sf = 304.0; for (i = 0; i < 16; i++) u.a[i] = 304.0 + i; g_v16sf = u.v; } void test_v16sf (void) { v16sf v; u16sf u; sf *p = u.a; ; ; ; init_16sf (); checkg_16sf (); ; ; pass_v16sf (g_v16sf); ; ; v = g_v16sf; pass_v16sf (v); ; ; u.v = return_v16sf (); checkp_16sf (p); ; }
extern v2df g_v2df; extern df g_df; extern void pass_v2df (v2df); extern v2df return_v2df (void); void checkp_2df (df *p) { int i; for (i = 0; i < 2; i++) { if (p[i] != g_df + i) abort ();; } } void checkg_2df (void) { u2df u; df *p = u.a; u.v = g_v2df; checkp_2df (p); } void init_2df (void) { int i; u2df u; g_df = 402.0; for (i = 0; i < 2; i++) u.a[i] = 402.0 + i; g_v2df = u.v; } void test_v2df (void) { v2df v; u2df u; df *p = u.a; ; ; ; init_2df (); checkg_2df (); ; ; pass_v2df (g_v2df); ; ; v = g_v2df; pass_v2df (v); ; ; u.v = return_v2df (); checkp_2df (p); ; }
extern v4df g_v4df; extern df g_df; extern void pass_v4df (v4df); extern v4df return_v4df (void); void checkp_4df (df *p) { int i; for (i = 0; i < 4; i++) { if (p[i] != g_df + i) abort ();; } } void checkg_4df (void) { u4df u; df *p = u.a; u.v = g_v4df; checkp_4df (p); } void init_4df (void) { int i; u4df u; g_df = 402.0; for (i = 0; i < 4; i++) u.a[i] = 402.0 + i; g_v4df = u.v; } void test_v4df (void) { v4df v; u4df u; df *p = u.a; ; ; ; init_4df (); checkg_4df (); ; ; pass_v4df (g_v4df); ; ; v = g_v4df; pass_v4df (v); ; ; u.v = return_v4df (); checkp_4df (p); ; }

