typedef float vf2_t __attribute__((vector_size (8)));
struct x0
{
  vf2_t v;
} s0;
struct x3
{
  vf2_t v[2];
} s3;
struct x4
{
  vf2_t v[3];
} s4;

typedef float vf4_t __attribute__((vector_size(16)));
struct x1
{
  vf4_t v;
} s1;

struct x2
{
  double df[3];
} s2;


void init_data ()
{
  s0.v = (vf2_t){ 17.f, 18.f };
  s1.v = (vf4_t){ 567.890f, 678.901f, 789.012f, 890.123f };
  s2.df[0] = 123.456;
  s2.df[1] = 234.567;
  s2.df[2] = 345.678;
  s3.v[0] = (vf2_t){ 19.f, 20.f };
  s3.v[1] = (vf2_t){ 23.f, 24.f };
  s4.v[0] = (vf2_t){ 27.f, 28.f };
  s4.v[1] = (vf2_t){ 31.f, 32.f };
  s4.v[2] = (vf2_t){ 35.f, 36.f };
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


{ struct x0 __x = s0; ; if (validate_memory (&__x, stack + 0, sizeof (struct x0), flat) != 0) abort(); }
{ struct x2 __x = s2; ; if (validate_memory (&__x, stack + 8, sizeof (struct x2), flat) != 0) abort(); }
{ struct x1 __x = s1; ; if (validate_memory (&__x, stack + 256, sizeof (struct x1), flat) != 0) abort(); }
{ struct x3 __x = s3; ; if (validate_memory (&__x, stack + 40, sizeof (struct x3), flat) != 0) abort(); }
{ struct x4 __x = s4; ; if (validate_memory (&__x, stack + 336, sizeof (struct x4), flat) != 0) abort(); }
{ int __x = 0xdeadbeef; ; if (validate_memory (&__x, stack + 96, sizeof (int), flat) != 0) abort(); }
{ double __x = 456.789; ; if (validate_memory (&__x, stack + 336 +24, sizeof (double), flat) != 0) abort(); }

  return;
}






void myfunc(


struct x0,
struct x2,
struct x1,
struct x3,
struct x4,
int,
double

) ;
int main()
{




  init_data ();



  which_kind_of_test = TK_PARAM;
  myfunc(






s0,
s2,
s1,
s3,
s4,
0xdeadbeef,
456.789

);
  return 0;
}

