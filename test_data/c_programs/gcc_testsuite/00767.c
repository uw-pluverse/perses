



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

struct hfa_fx2_t hfa_fx2 = {1.2f, 2.2f};
struct hfa_fx3_t hfa_fx3 = {3.2f, 4.2f, 5.2f};
vf4_t float32x4 = {6.2f, 7.2f, 8.2f, 9.2f};
vf4_t float32x4_2 = {10.2f, 11.2f, 12.2f, 13.2f};


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


  { float __x = 1.0f; ; if (validate_memory (&__x, stack + 64, sizeof (float), flat) != 0) abort(); }
  { float __x = 2.0f; ; if (validate_memory (&__x, stack + 68, sizeof (float), flat) != 0) abort(); }
  { float __x = 3.0f; ; if (validate_memory (&__x, stack + 72, sizeof (float), flat) != 0) abort(); }
  { float __x = 4.0f; ; if (validate_memory (&__x, stack + 76, sizeof (float), flat) != 0) abort(); }
  { float __x = 5.0f; ; if (validate_memory (&__x, stack + 80, sizeof (float), flat) != 0) abort(); }
  { float __x = 6.0f; ; if (validate_memory (&__x, stack + 84, sizeof (float), flat) != 0) abort(); }
  { float __x = 7.0f; ; if (validate_memory (&__x, stack + 88, sizeof (float), flat) != 0) abort(); }
  { struct hfa_fx3_t __x = hfa_fx3; ; if (validate_memory (&__x, stack + 336, sizeof (struct hfa_fx3_t), flat) != 0) abort(); }


  { struct hfa_fx2_t __x = hfa_fx2; ; if (validate_memory (&__x, stack + 336 + 16, sizeof (struct hfa_fx2_t), flat) != 0) abort(); }

  { vf4_t __x = float32x4; ; if (validate_memory (&__x, stack + 336 + 32, sizeof (vf4_t), flat) != 0) abort(); }
  { vf4_t __x = float32x4_2; ; if (validate_memory (&__x, stack + 336 + 48, sizeof (vf4_t), flat) != 0) abort(); }

  { double __x = 123456789.987; ; if (validate_memory (&__x, stack + 336 + 64, sizeof (double), flat) != 0) abort(); }

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


  float,
  float,
  float,
  float,
  float,
  float,
  float,
  struct hfa_fx3_t,


  struct hfa_fx2_t,

  vf4_t,
  vf4_t,

  double

) ;






void stdarg_func(


  float _f0,
  float _f1,
  float _f2,
  float _f3,
  float _f4,
  float _f5,
  float _f6,
  struct hfa_fx3_t _f7,


  struct hfa_fx2_t _f8,

  vf4_t _f9,
  vf4_t _f65535,
  ...

)
{

  va_list ap;

  __builtin_va_start(ap, _f65535);;


  dummy_func (0, 0, 0, 0, 0, 0, 0, 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);


  __sync_synchronize ();
    {



  float _x0 = _f0;
  float _x1 = _f1;
  float _x2 = _f2;
  float _x3 = _f3;
  float _x4 = _f4;
  float _x5 = _f5;
  float _x6 = _f6;
  struct hfa_fx3_t _x7 = _f7;


  struct hfa_fx2_t _x8 = _f8;

  vf4_t _x9 = _f9;
  vf4_t _x65535 = _f65535;

  double _x11 = __builtin_va_arg(ap, double);



      myfunc (


  _x0,
  _x1,
  _x2,
  _x3,
  _x4,
  _x5,
  _x6,
  _x7,


  _x8,

  _x9,
  _x65535,

  _x11

);
    }
  __builtin_va_end(ap);
}




int main()
{
  which_kind_of_test = TK_VA_ARG;
  stdarg_func(



  1.0f,
  2.0f,
  3.0f,
  4.0f,
  5.0f,
  6.0f,
  7.0f,
  hfa_fx3,


  hfa_fx2,

  float32x4,
  float32x4_2,

  123456789.987

);
  return 0;
}

