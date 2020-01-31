



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
struct hfa_dx2_t hfa_dx2 = {234.567, 345.678};
struct hfa_ffs_t hfa_ffs;
union hfa_union_t hfa_union;


void init_data ()
{
  hfa_union.s.a = 37.f;
  hfa_union.s.b = 38.f;
  hfa_union.c = 39.f;

  hfa_ffs.a = 42.f;
  hfa_ffs.b = 43.f;
  hfa_ffs.c.a = 44.f;
  hfa_ffs.c.b = 45.f;
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

  { struct hfa_ffs_t __x = hfa_ffs; ; if (validate_memory (&__x, stack + 64, sizeof (struct hfa_ffs_t), flat) != 0) abort(); }
  { union hfa_union_t __x = hfa_union; ; if (validate_memory (&__x, stack + 80, sizeof (union hfa_union_t), flat) != 0) abort(); }
  { struct hfa_dx2_t __x = hfa_dx2; ; if (validate_memory (&__x, stack + 48, sizeof (struct hfa_dx2_t), flat) != 0) abort(); }
  { struct hfa_fx1_t __x = hfa_fx1; ; if (validate_memory (&__x, stack + 336, sizeof (struct hfa_fx1_t), flat) != 0) abort(); }
  { double __x = 1.0; ; if (validate_memory (&__x, stack + 336 +8, sizeof (double), flat) != 0) abort(); }

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

  struct hfa_ffs_t,
  union hfa_union_t,
  struct hfa_dx2_t,
  struct hfa_fx1_t,
  double

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

  struct hfa_ffs_t _x0 = __builtin_va_arg(ap, struct hfa_ffs_t);
  union hfa_union_t _x1 = __builtin_va_arg(ap, union hfa_union_t);
  struct hfa_dx2_t _x2 = __builtin_va_arg(ap, struct hfa_dx2_t);
  struct hfa_fx1_t _x3 = __builtin_va_arg(ap, struct hfa_fx1_t);
  double _x4 = __builtin_va_arg(ap, double);



      myfunc (


  _x65535,

  _x0,
  _x1,
  _x2,
  _x3,
  _x4

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

  hfa_ffs,
  hfa_union,
  hfa_dx2,
  hfa_fx1,
  1.0

);
  return 0;
}

