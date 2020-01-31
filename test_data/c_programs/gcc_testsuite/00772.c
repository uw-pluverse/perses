



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

vf2_t vf2 = (vf2_t){ 17.f, 18.f };
vi4_t vi4 = (vi4_t){ 0xdeadbabe, 0xbabecafe, 0xcafebeef, 0xbeefdead };
union int128_t qword;
signed char sc = 0xed;
signed int sc_promoted = 0xffffffed;
signed short ss = 0xcba9;
signed int ss_promoted = 0xffffcba9;
float fp = 65432.12345f;
double fp_promoted = (double)65432.12345f;


void init_data ()
{

  qword.l64 = 0xfdb9753102468aceLL;
  qword.h64 = 0xeca8642013579bdfLL;
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


  { int __x = 0xff; ; if (validate_memory (&__x, stack + 96, sizeof (int), flat) != 0) abort(); }

  { unsigned int __x = 0xfe; ; if (validate_memory (&__x, stack + 100, sizeof (unsigned int), flat) != 0) abort(); }
  { signed int __x = sc_promoted; ; if (validate_memory (&__x, stack + 104, sizeof (signed int), flat) != 0) abort(); }
  { unsigned int __x = 0xdcba; ; if (validate_memory (&__x, stack + 108, sizeof (unsigned int), flat) != 0) abort(); }
  { signed int __x = ss_promoted; ; if (validate_memory (&__x, stack + 112, sizeof (signed int), flat) != 0) abort(); }
  { unsigned int __x = 0xdeadbeef; ; if (validate_memory (&__x, stack + 116, sizeof (unsigned int), flat) != 0) abort(); }
  { signed int __x = 0xcafebabe; ; if (validate_memory (&__x, stack + 120, sizeof (signed int), flat) != 0) abort(); }
  { unsigned long long __x = 0xba98765432101234ULL; ; if (validate_memory (&__x, stack + 184, sizeof (unsigned long long), flat) != 0) abort(); }
  { signed long long __x = 0xa987654321012345LL; ; if (validate_memory (&__x, stack + 336, sizeof (signed long long), flat) != 0) abort(); }
  { __int128 __x = qword.i; ; if (validate_memory (&__x, stack + 336 +16, sizeof (__int128), flat) != 0) abort(); }
  { double __x = fp_promoted; ; if (validate_memory (&__x, stack + 0, sizeof (double), flat) != 0) abort(); }
  { double __x = 9876543.212345; ; if (validate_memory (&__x, stack + 8, sizeof (double), flat) != 0) abort(); }
  { long double __x = 98765432123456789.987654321L; ; if (validate_memory (&__x, stack + 224, sizeof (long double), flat) != 0) abort(); }
  { vf2_t __x = vf2; ; if (validate_memory (&__x, stack + 24, sizeof (vf2_t), flat) != 0) abort(); }
  { vi4_t __x = vi4; ; if (validate_memory (&__x, stack + 256, sizeof (vi4_t), flat) != 0) abort(); }

  { int __x = 0xeeee; ; if (validate_memory (&__x, stack + 336 +32, sizeof (int), flat) != 0) abort(); }

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

  unsigned int,
  signed int,
  unsigned int,
  signed int,
  unsigned int,
  signed int,
  unsigned long long,
  signed long long,
  __int128,
  double,
  double,
  long double,
  vf2_t,
  vi4_t,

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

  unsigned int _x1 = __builtin_va_arg(ap, unsigned int);
  signed int _x2 = __builtin_va_arg(ap, signed int);
  unsigned int _x3 = __builtin_va_arg(ap, unsigned int);
  signed int _x4 = __builtin_va_arg(ap, signed int);
  unsigned int _x5 = __builtin_va_arg(ap, unsigned int);
  signed int _x6 = __builtin_va_arg(ap, signed int);
  unsigned long long _x7 = __builtin_va_arg(ap, unsigned long long);
  signed long long _x8 = __builtin_va_arg(ap, signed long long);
  __int128 _x9 = __builtin_va_arg(ap, __int128);
  double _x10 = __builtin_va_arg(ap, double);
  double _x11 = __builtin_va_arg(ap, double);
  long double _x12 = __builtin_va_arg(ap, long double);
  vf2_t _x13 = __builtin_va_arg(ap, vf2_t);
  vi4_t _x14 = __builtin_va_arg(ap, vi4_t);

  int _x15 = __builtin_va_arg(ap, int);



      myfunc (


  _x65535,

  _x1,
  _x2,
  _x3,
  _x4,
  _x5,
  _x6,
  _x7,
  _x8,
  _x9,
  _x10,
  _x11,
  _x12,
  _x13,
  _x14,

  _x15

);
    }
  __builtin_va_end(ap);
}




int main()
{




  init_data ();






  which_kind_of_test = TK_VA_ARG;
  stdarg_func(



  0xff,

  0xfe,
  sc,
  0xdcba,
  ss,
  0xdeadbeef,
  0xcafebabe,
  0xba98765432101234ULL,
  0xa987654321012345LL,
  qword.i,
  fp,
  9876543.212345,
  98765432123456789.987654321L,
  vf2,
  vi4,

  0xeeee

);
  return 0;
}

