






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

v8qi g_v8qi; qi g_qi; extern void test_v8qi (void); extern void checkp_8qi (qi *); void pass_v8qi (v8qi v) { u8qi u; int j; qi a[8]; u.v = v; for (j = 0; j < 8; j++) a[j] = u.a[j]; checkp_8qi (a); } v8qi return_v8qi (void) { return g_v8qi; };
v16qi g_v16qi; qi g_qi; extern void test_v16qi (void); extern void checkp_16qi (qi *); void pass_v16qi (v16qi v) { u16qi u; int j; qi a[16]; u.v = v; for (j = 0; j < 16; j++) a[j] = u.a[j]; checkp_16qi (a); } v16qi return_v16qi (void) { return g_v16qi; };
v32qi g_v32qi; qi g_qi; extern void test_v32qi (void); extern void checkp_32qi (qi *); void pass_v32qi (v32qi v) { u32qi u; int j; qi a[32]; u.v = v; for (j = 0; j < 32; j++) a[j] = u.a[j]; checkp_32qi (a); } v32qi return_v32qi (void) { return g_v32qi; };
v2hi g_v2hi; hi g_hi; extern void test_v2hi (void); extern void checkp_2hi (hi *); void pass_v2hi (v2hi v) { u2hi u; int j; hi a[2]; u.v = v; for (j = 0; j < 2; j++) a[j] = u.a[j]; checkp_2hi (a); } v2hi return_v2hi (void) { return g_v2hi; };
v4hi g_v4hi; hi g_hi; extern void test_v4hi (void); extern void checkp_4hi (hi *); void pass_v4hi (v4hi v) { u4hi u; int j; hi a[4]; u.v = v; for (j = 0; j < 4; j++) a[j] = u.a[j]; checkp_4hi (a); } v4hi return_v4hi (void) { return g_v4hi; };
v8hi g_v8hi; hi g_hi; extern void test_v8hi (void); extern void checkp_8hi (hi *); void pass_v8hi (v8hi v) { u8hi u; int j; hi a[8]; u.v = v; for (j = 0; j < 8; j++) a[j] = u.a[j]; checkp_8hi (a); } v8hi return_v8hi (void) { return g_v8hi; };
v16hi g_v16hi; hi g_hi; extern void test_v16hi (void); extern void checkp_16hi (hi *); void pass_v16hi (v16hi v) { u16hi u; int j; hi a[16]; u.v = v; for (j = 0; j < 16; j++) a[j] = u.a[j]; checkp_16hi (a); } v16hi return_v16hi (void) { return g_v16hi; };
v2si g_v2si; si g_si; extern void test_v2si (void); extern void checkp_2si (si *); void pass_v2si (v2si v) { u2si u; int j; si a[2]; u.v = v; for (j = 0; j < 2; j++) a[j] = u.a[j]; checkp_2si (a); } v2si return_v2si (void) { return g_v2si; };
v4si g_v4si; si g_si; extern void test_v4si (void); extern void checkp_4si (si *); void pass_v4si (v4si v) { u4si u; int j; si a[4]; u.v = v; for (j = 0; j < 4; j++) a[j] = u.a[j]; checkp_4si (a); } v4si return_v4si (void) { return g_v4si; };
v8si g_v8si; si g_si; extern void test_v8si (void); extern void checkp_8si (si *); void pass_v8si (v8si v) { u8si u; int j; si a[8]; u.v = v; for (j = 0; j < 8; j++) a[j] = u.a[j]; checkp_8si (a); } v8si return_v8si (void) { return g_v8si; };
v1di g_v1di; di g_di; extern void test_v1di (void); extern void checkp_1di (di *); void pass_v1di (v1di v) { u1di u; int j; di a[1]; u.v = v; for (j = 0; j < 1; j++) a[j] = u.a[j]; checkp_1di (a); } v1di return_v1di (void) { return g_v1di; };
v2di g_v2di; di g_di; extern void test_v2di (void); extern void checkp_2di (di *); void pass_v2di (v2di v) { u2di u; int j; di a[2]; u.v = v; for (j = 0; j < 2; j++) a[j] = u.a[j]; checkp_2di (a); } v2di return_v2di (void) { return g_v2di; };
v4di g_v4di; di g_di; extern void test_v4di (void); extern void checkp_4di (di *); void pass_v4di (v4di v) { u4di u; int j; di a[4]; u.v = v; for (j = 0; j < 4; j++) a[j] = u.a[j]; checkp_4di (a); } v4di return_v4di (void) { return g_v4di; };



void
vector_1_x (void)
{



  test_v8qi();
  test_v16qi();
  test_v32qi();
  test_v2hi();
  test_v4hi();
  test_v8hi();
  test_v16hi();
  test_v2si();
  test_v4si();
  test_v8si();
  test_v1di();
  test_v2di();
  test_v4di();



  if (fails != 0)
    abort ();

}

