





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

v2sf g_v2sf; sf g_sf; extern void test_v2sf (void); extern void checkp_2sf (sf *); void pass_v2sf (v2sf v) { u2sf u; int j; sf a[2]; u.v = v; for (j = 0; j < 2; j++) a[j] = u.a[j]; checkp_2sf (a); } v2sf return_v2sf (void) { return g_v2sf; };
v4sf g_v4sf; sf g_sf; extern void test_v4sf (void); extern void checkp_4sf (sf *); void pass_v4sf (v4sf v) { u4sf u; int j; sf a[4]; u.v = v; for (j = 0; j < 4; j++) a[j] = u.a[j]; checkp_4sf (a); } v4sf return_v4sf (void) { return g_v4sf; };
v16sf g_v16sf; sf g_sf; extern void test_v16sf (void); extern void checkp_16sf (sf *); void pass_v16sf (v16sf v) { u16sf u; int j; sf a[16]; u.v = v; for (j = 0; j < 16; j++) a[j] = u.a[j]; checkp_16sf (a); } v16sf return_v16sf (void) { return g_v16sf; };
v8sf g_v8sf; sf g_sf; extern void test_v8sf (void); extern void checkp_8sf (sf *); void pass_v8sf (v8sf v) { u8sf u; int j; sf a[8]; u.v = v; for (j = 0; j < 8; j++) a[j] = u.a[j]; checkp_8sf (a); } v8sf return_v8sf (void) { return g_v8sf; };
v2df g_v2df; df g_df; extern void test_v2df (void); extern void checkp_2df (df *); void pass_v2df (v2df v) { u2df u; int j; df a[2]; u.v = v; for (j = 0; j < 2; j++) a[j] = u.a[j]; checkp_2df (a); } v2df return_v2df (void) { return g_v2df; };
v4df g_v4df; df g_df; extern void test_v4df (void); extern void checkp_4df (df *); void pass_v4df (v4df v) { u4df u; int j; df a[4]; u.v = v; for (j = 0; j < 4; j++) a[j] = u.a[j]; checkp_4df (a); } v4df return_v4df (void) { return g_v4df; };



void
vector_2_x (void)
{



  test_v2sf();
  test_v4sf();
  test_v8sf();
  test_v16sf();
  test_v4df();
  test_v2df();



  if (fails != 0)
    abort ();

}
