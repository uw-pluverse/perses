



typedef float vf2_t __attribute__((vector_size (8)));


typedef float vf4_t __attribute__((vector_size (16)));


typedef int vi4_t __attribute__((vector_size (16)));


typedef long double vlf1_t __attribute__((vector_size (16)));


union int128_t
{
  __int128 i;
  struct
    {
      signed long long l64;
      signed long long h64;
    };
};



struct hfa_fx1_t
{
  float a;
};

struct hfa_fx2_t
{
  float a;
  float b;
};

struct hfa_fx3_t
{
  float a;
  float b;
  float c;
};

struct hfa_dx2_t
{
  double a;
  double b;
};

struct hfa_dx4_t
{
  double a;
  double b;
  double c;
  double d;
};

struct hfa_ldx3_t
{
  long double a;
  long double b;
  long double c;
};

struct hfa_ffs_t
{
  float a;
  float b;
  struct hfa_fx2_t c;
};

union hfa_union_t
{
  struct
    {
      float a;
      float b;
    } s;
  float c;
};



struct non_hfa_fx5_t
{
  float a;
  float b;
  float c;
  float d;
  float e;
};

struct non_hfa_ffs_t
{
  float a;
  float b;
  struct hfa_dx2_t c;
};

struct non_hfa_ffs_2_t
{
  struct
    {
      int a;
      int b;
    } s;
  float c;
  float d;
};

struct hva_vf2x1_t
{
  vf2_t a;
};

struct hva_vf2x2_t
{
  vf2_t a;
  vf2_t b;
};

struct hva_vi4x1_t
{
  vi4_t a;
};

struct non_hfa_ffd_t
{
  float a;
  float b;
  double c;
};

struct non_hfa_ii_t
{
  int a;
  int b;
};

struct non_hfa_c_t
{
  char a;
};

struct non_hfa_ffvf2_t
{
  float a;
  float b;
  vf2_t c;
};

struct non_hfa_fffd_t
{
  float a;
  float b;
  float c;
  double d;
};

union non_hfa_union_t
{
  double a;
  float b;
};

struct hfa_fx1_t hfa_fx1 = {12.345f};
struct hfa_fx2_t hfa_fx2 = {123.456f, 234.456f};
struct hfa_dx2_t hfa_dx2 = {234.567, 345.678};
struct hfa_dx4_t hfa_dx4 = {1234.123, 2345.234, 3456.345, 4567.456};
struct hfa_ldx3_t hfa_ldx3 = {123456.7890, 234567.8901, 345678.9012};
struct non_hfa_fx5_t non_hfa_fx5 = {456.789f, 567.890f, 678.901f, 789.012f, 890.123f};
struct hfa_ffs_t hfa_ffs;
struct non_hfa_ffs_t non_hfa_ffs;
struct non_hfa_ffs_2_t non_hfa_ffs_2;
struct hva_vf2x1_t hva_vf2x1;
struct hva_vf2x2_t hva_vf2x2;
struct hva_vi4x1_t hva_vi4x1;
struct non_hfa_ffd_t non_hfa_ffd = {23.f, 24.f, 25.0};
struct non_hfa_ii_t non_hfa_ii = {26, 27};
struct non_hfa_c_t non_hfa_c = {28};
struct non_hfa_ffvf2_t non_hfa_ffvf2;
struct non_hfa_fffd_t non_hfa_fffd = {33.f, 34.f, 35.f, 36.0};
union hfa_union_t hfa_union;
union non_hfa_union_t non_hfa_union;


void init_data ()
{
  hva_vf2x1.a = (vf2_t){17.f, 18.f};
  hva_vf2x2.a = (vf2_t){19.f, 20.f};
  hva_vf2x2.b = (vf2_t){21.f, 22.f};
  hva_vi4x1.a = (vi4_t){19, 20, 21, 22};

  non_hfa_ffvf2.a = 29.f;
  non_hfa_ffvf2.b = 30.f;
  non_hfa_ffvf2.c = (vf2_t){31.f, 32.f};

  hfa_union.s.a = 37.f;
  hfa_union.s.b = 38.f;
  hfa_union.c = 39.f;

  non_hfa_union.a = 40.0;
  non_hfa_union.b = 41.f;

  hfa_ffs.a = 42.f;
  hfa_ffs.b = 43.f;
  hfa_ffs.c.a = 44.f;
  hfa_ffs.c.b = 45.f;

  non_hfa_ffs.a = 46.f;
  non_hfa_ffs.b = 47.f;
  non_hfa_ffs.c.a = 48.0;
  non_hfa_ffs.c.b = 49.0;

  non_hfa_ffs_2.s.a = 50;
  non_hfa_ffs_2.s.b = 51;
  non_hfa_ffs_2.c = 52.f;
  non_hfa_ffs_2.d = 53.f;
}


enum aapcs64_test_kind
{
  TK_PARAM = 0,
  TK_VA_ARG,
  TK_RETURN
};

int which_kind_of_test;

extern int printf (const char*, ...);
extern void abort (void);
extern void dumpregs () __asm("myfunc");
enum structure_type
{
  flat = 0,
  i32in128,
  f32in64,
  i8in64,
  i16in64,
  i32in64,
};



typedef long unsigned int size_t;
int memcmp (void *, void *, size_t);



const int element_size[] = { 1, 4, 4, 1, 2, 4 };
const int block_reverse_size[] = { 1, 16, 8, 8, 8, 8 };

int
validate_memory (void *mem1, char *mem2, size_t size, enum structure_type type)
{
  unsigned int i;
  char *cmem1 = (char *) mem1;
  switch (type)
    {
    case f32in64:
    case i32in128:
    default:
      break;
    }
  return memcmp (mem1, mem2, size);
}
void testfunc(char* stack)
{


  { int __x = 1; ; if (validate_memory (&__x, stack + 96, sizeof (int), flat) != 0) abort(); }


  { struct hfa_fx1_t __x = hfa_fx1; ; if (validate_memory (&__x, stack + 64, sizeof (struct hfa_fx1_t), flat) != 0) abort(); }
  { struct hfa_fx2_t __x = hfa_fx2; ; if (validate_memory (&__x, stack + 68, sizeof (struct hfa_fx2_t), flat) != 0) abort(); }
  { struct hfa_dx2_t __x = hfa_dx2; ; if (validate_memory (&__x, stack + 24, sizeof (struct hfa_dx2_t), flat) != 0) abort(); }
  { struct hva_vf2x1_t __x = hva_vf2x1; ; if (validate_memory (&__x, stack + 40, sizeof (struct hva_vf2x1_t), flat) != 0) abort(); }
  { struct hva_vi4x1_t __x = hva_vi4x1; ; if (validate_memory (&__x, stack + 288, sizeof (struct hva_vi4x1_t), flat) != 0) abort(); }
  { struct hfa_dx4_t __x = hfa_dx4; ; if (validate_memory (&__x, stack + 336, sizeof (struct hfa_dx4_t), flat) != 0) abort(); }
  { struct hfa_ffs_t __x = hfa_ffs; ; if (validate_memory (&__x, stack + 336 +32, sizeof (struct hfa_ffs_t), flat) != 0) abort(); }
  { union hfa_union_t __x = hfa_union; ; if (validate_memory (&__x, stack + 336 +48, sizeof (union hfa_union_t), flat) != 0) abort(); }
  { struct hfa_ldx3_t __x = hfa_ldx3; ; if (validate_memory (&__x, stack + 336 +64, sizeof (struct hfa_ldx3_t), flat) != 0) abort(); }

  { struct non_hfa_fx5_t * ptr; ; ptr = *(struct non_hfa_fx5_t **)(stack + 136); if (memcmp (ptr, &non_hfa_fx5, sizeof (struct non_hfa_fx5_t)) != 0) abort (); }
  { struct non_hfa_ffd_t __x = non_hfa_ffd; ; if (validate_memory (&__x, stack + 144, sizeof (struct non_hfa_ffd_t), flat) != 0) abort(); }
  { struct non_hfa_ii_t __x = non_hfa_ii; ; if (validate_memory (&__x, stack + 160, sizeof (struct non_hfa_ii_t), flat) != 0) abort(); }
  { struct non_hfa_c_t __x = non_hfa_c; ; if (validate_memory (&__x, stack + 168, sizeof (struct non_hfa_c_t), flat) != 0) abort(); }
  { struct non_hfa_ffvf2_t __x = non_hfa_ffvf2; ; if (validate_memory (&__x, stack + 176, sizeof (struct non_hfa_ffvf2_t), flat) != 0) abort(); }
  { struct non_hfa_fffd_t * ptr; ; ptr = *(struct non_hfa_fffd_t **)(stack + 336 +112); if (memcmp (ptr, &non_hfa_fffd, sizeof (struct non_hfa_fffd_t)) != 0) abort (); }
  { struct non_hfa_ffs_t * ptr; ; ptr = *(struct non_hfa_ffs_t **)(stack + 336 +120); if (memcmp (ptr, &non_hfa_ffs, sizeof (struct non_hfa_ffs_t)) != 0) abort (); }
  { struct non_hfa_ffs_2_t __x = non_hfa_ffs_2; ; if (validate_memory (&__x, stack + 336 +128, sizeof (struct non_hfa_ffs_2_t), flat) != 0) abort(); }
  { union non_hfa_union_t __x = non_hfa_union; ; if (validate_memory (&__x, stack + 336 +144, sizeof (union non_hfa_union_t), flat) != 0) abort(); }

  { int __x = 2; ; if (validate_memory (&__x, stack + 336 +152, sizeof (int), flat) != 0) abort(); }

  return;
}
typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;



__attribute__ ((noinline)) void
dummy_func (int w0, int w1, int w2, int w3, int w4, int w5, int w6, int w7,
     float s0, float s1, float s2, float s3, float s4, float s5,
     float s6, float s7)
{
  asm ("");
  return;
}


void myfunc(


  int,


  struct hfa_fx1_t,
  struct hfa_fx2_t,
  struct hfa_dx2_t,
  struct hva_vf2x1_t,
  struct hva_vi4x1_t,
  struct hfa_dx4_t,
  struct hfa_ffs_t,
  union hfa_union_t,
  struct hfa_ldx3_t,

  struct non_hfa_fx5_t,
  struct non_hfa_ffd_t,
  struct non_hfa_ii_t,
  struct non_hfa_c_t,
  struct non_hfa_ffvf2_t,
  struct non_hfa_fffd_t,
  struct non_hfa_ffs_t,
  struct non_hfa_ffs_2_t,
  union non_hfa_union_t,

  int

) ;






void stdarg_func(


  int _f65535,
  ...

)
{

  va_list ap;

  __builtin_va_start(ap, _f65535);;


  dummy_func (0, 0, 0, 0, 0, 0, 0, 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);


  __sync_synchronize ();
    {



  int _x65535 = _f65535;


  struct hfa_fx1_t _x0 = __builtin_va_arg(ap, struct hfa_fx1_t);
  struct hfa_fx2_t _x1 = __builtin_va_arg(ap, struct hfa_fx2_t);
  struct hfa_dx2_t _x2 = __builtin_va_arg(ap, struct hfa_dx2_t);
  struct hva_vf2x1_t _x11 = __builtin_va_arg(ap, struct hva_vf2x1_t);
  struct hva_vi4x1_t _x12 = __builtin_va_arg(ap, struct hva_vi4x1_t);
  struct hfa_dx4_t _x3 = __builtin_va_arg(ap, struct hfa_dx4_t);
  struct hfa_ffs_t _x4 = __builtin_va_arg(ap, struct hfa_ffs_t);
  union hfa_union_t _x5 = __builtin_va_arg(ap, union hfa_union_t);
  struct hfa_ldx3_t _x6 = __builtin_va_arg(ap, struct hfa_ldx3_t);

  struct non_hfa_fx5_t _x10 = __builtin_va_arg(ap, struct non_hfa_fx5_t);
  struct non_hfa_ffd_t _x13 = __builtin_va_arg(ap, struct non_hfa_ffd_t);
  struct non_hfa_ii_t _x14 = __builtin_va_arg(ap, struct non_hfa_ii_t);
  struct non_hfa_c_t _x15 = __builtin_va_arg(ap, struct non_hfa_c_t);
  struct non_hfa_ffvf2_t _x16 = __builtin_va_arg(ap, struct non_hfa_ffvf2_t);
  struct non_hfa_fffd_t _x17 = __builtin_va_arg(ap, struct non_hfa_fffd_t);
  struct non_hfa_ffs_t _x18 = __builtin_va_arg(ap, struct non_hfa_ffs_t);
  struct non_hfa_ffs_2_t _x19 = __builtin_va_arg(ap, struct non_hfa_ffs_2_t);
  union non_hfa_union_t _x20 = __builtin_va_arg(ap, union non_hfa_union_t);

  int _x30 = __builtin_va_arg(ap, int);



      myfunc (


  _x65535,


  _x0,
  _x1,
  _x2,
  _x11,
  _x12,
  _x3,
  _x4,
  _x5,
  _x6,

  _x10,
  _x13,
  _x14,
  _x15,
  _x16,
  _x17,
  _x18,
  _x19,
  _x20,

  _x30

);
    }
  __builtin_va_end(ap);
}




int main()
{




  init_data ();






  which_kind_of_test = TK_VA_ARG;
  stdarg_func(



  1,


  hfa_fx1,
  hfa_fx2,
  hfa_dx2,
  hva_vf2x1,
  hva_vi4x1,
  hfa_dx4,
  hfa_ffs,
  hfa_union,
  hfa_ldx3,

  non_hfa_fx5,
  non_hfa_ffd,
  non_hfa_ii,
  non_hfa_c,
  non_hfa_ffvf2,
  non_hfa_fffd,
  non_hfa_ffs,
  non_hfa_ffs_2,
  non_hfa_union,

  2

);
  return 0;
}

