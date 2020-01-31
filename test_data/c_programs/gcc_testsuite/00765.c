



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

struct y
{
  int p;
  int q;
  int r;
  int s;
};

struct y v1 = { 1, 2, 3, 4 };
struct y v2 = { 5, 6, 7, 8 };
struct y v3 = { 9, 10, 11, 12 };
struct y v4 = { 13, 14, 15, 16 };

struct z
{
  double x[4];
};

struct z a = { 5.0, 6.0, 7.0, 8.0 };
struct z b = { 9.0, 10.0, 11.0, 12.0 };

vf4_t c = { 13.f, 14.f, 15.f, 16.f };

struct x
{
  vf4_t v;
} w;

char ch='a';
short sh=13;
int i=14;
long long ll=15;

struct s1
{
  short sh[3];
} s1;

struct s2
{
  int i[2];
  char c;
} s2;

struct ldx2_t
{
  long double ld[2];
} ldx2 = { 12345.67890L, 23456.78901L };

union u_t
{
  long double ld;
  double d[2];
} u;


void init_data ()
{
  w.v = (vf4_t){ 17.f, 18.f, 19.f, 20.f };
  s1.sh[0] = 16;
  s1.sh[1] = 17;
  s1.sh[2] = 18;
  s2.i[0] = 19;
  s2.i[1] = 20;
  s2.c = 21;
  u.ld = 34567.89012L;
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


  { struct y __x = v1; ; if (validate_memory (&__x, stack + 128, sizeof (struct y), flat) != 0) abort(); }
  { struct y __x = v2; ; if (validate_memory (&__x, stack + 144, sizeof (struct y), flat) != 0) abort(); }
  { struct y __x = v3; ; if (validate_memory (&__x, stack + 160, sizeof (struct y), flat) != 0) abort(); }
  { struct y __x = v4; ; if (validate_memory (&__x, stack + 176, sizeof (struct y), flat) != 0) abort(); }
  { struct z __x = a; ; if (validate_memory (&__x, stack + 0, sizeof (struct z), flat) != 0) abort(); }
  { struct z __x = b; ; if (validate_memory (&__x, stack + 32, sizeof (struct z), flat) != 0) abort(); }
  { double __x = 12.5; ; if (validate_memory (&__x, stack + 336, sizeof (double), flat) != 0) abort(); }
  { vf4_t __x = c; ; if (validate_memory (&__x, stack + 336 +16, sizeof (vf4_t), flat) != 0) abort(); }
  { double __x = 17.0; ; if (validate_memory (&__x, stack + 336 +32, sizeof (double), flat) != 0) abort(); }
  { struct x __x = w; ; if (validate_memory (&__x, stack + 336 +48, sizeof (struct x), flat) != 0) abort(); }

  { char __x = ch; ; if (validate_memory (&__x, stack + 336 +64, sizeof (char), flat) != 0) abort(); }
  { short __x = sh; ; if (validate_memory (&__x, stack + 336 +72, sizeof (short), flat) != 0) abort(); }
  { int __x = i; ; if (validate_memory (&__x, stack + 336 +80, sizeof (int), flat) != 0) abort(); }





  { long long __x = ll; ; if (validate_memory (&__x, stack + 336 +88, sizeof (long long), flat) != 0) abort(); }
  { struct s1 __x = s1; ; if (validate_memory (&__x, stack + 336 +96, sizeof (struct s1), flat) != 0) abort(); }
  { double __x = 18.0; ; if (validate_memory (&__x, stack + 336 +104, sizeof (double), flat) != 0) abort(); }
  { struct s2 __x = s2; ; if (validate_memory (&__x, stack + 336 +112, sizeof (struct s2), flat) != 0) abort(); }
  { double __x = 19.0; ; if (validate_memory (&__x, stack + 336 +128, sizeof (double), flat) != 0) abort(); }
  { long double __x = 30.0L; ; if (validate_memory (&__x, stack + 336 +144, sizeof (long double), flat) != 0) abort(); }
  { double __x = 31.0; ; if (validate_memory (&__x, stack + 336 +160, sizeof (double), flat) != 0) abort(); }
  { struct ldx2_t __x = ldx2; ; if (validate_memory (&__x, stack + 336 +176, sizeof (struct ldx2_t), flat) != 0) abort(); }
  { double __x = 32.0; ; if (validate_memory (&__x, stack + 336 +208, sizeof (double), flat) != 0) abort(); }
  { __int128 __x = 33; ; if (validate_memory (&__x, stack + 336 +224, sizeof (__int128), flat) != 0) abort(); }
  { double __x = 34.0; ; if (validate_memory (&__x, stack + 336 +240, sizeof (double), flat) != 0) abort(); }
  { union u_t __x = u; ; if (validate_memory (&__x, stack + 336 +256, sizeof (union u_t), flat) != 0) abort(); }
  { int __x = 35.0; ; if (validate_memory (&__x, stack + 336 +272, sizeof (int), i32in64) != 0) abort(); }

  return;
}






void myfunc(


  struct y,
  struct y,
  struct y,
  struct y,
  struct z,
  struct z,
  double,
  vf4_t,
  double,
  struct x,

  char,
  short,
  int,





  long long,
  struct s1,
  double,
  struct s2,
  double,
  long double,
  double,
  struct ldx2_t,
  double,
  __int128,
  double,
  union u_t,
  int

) ;
int main()
{




  init_data ();



  which_kind_of_test = TK_PARAM;
  myfunc(






  v1,
  v2,
  v3,
  v4,
  a,
  b,
  12.5,
  c,
  17.0,
  w,

  ch,
  sh,
  i,





  ll,
  s1,
  18.0,
  s2,
  19.0,
  30.0L,
  31.0,
  ldx2,
  32.0,
  33,
  34.0,
  u,
  35.0

);
  return 0;
}

