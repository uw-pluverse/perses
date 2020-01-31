



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
  union int128_t v;
} w;

struct x
{
  long long p;
  int q;
} s = {0xDEADBEEFCAFEBABELL, 0xFEEBDAED};


void init_data ()
{

  w.v.l64 = 0xfdb9753102468aceLL;
  w.v.h64 = 0xeca8642013579bdfLL;
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


  { int __x = 0xAB; ; if (validate_memory (&__x, stack + 96, sizeof (int), flat) != 0) abort(); }
  { struct y __x = w; ; if (validate_memory (&__x, stack + 144, sizeof (struct y), flat) != 0) abort(); }
  { int __x = 0xCD; ; if (validate_memory (&__x, stack + 112, sizeof (int), flat) != 0) abort(); }
  { struct x __x = s; ; if (validate_memory (&__x, stack + 168, sizeof (struct x), flat) != 0) abort(); }
  { int __x = 0xFF00FF00; ; if (validate_memory (&__x, stack + 124, sizeof (int), flat) != 0) abort(); }

  return;
}






void myfunc(


  int,
  struct y,
  int,
  struct x,
  int

) ;
int main()
{




  init_data ();



  which_kind_of_test = TK_PARAM;
  myfunc(






  0xAB,
  w,
  0xCD,
  s,
  0xFF00FF00

);
  return 0;
}

