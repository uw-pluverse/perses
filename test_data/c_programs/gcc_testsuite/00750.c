struct y0
{
  char ch;
} c0 = { 'A' };

struct y2
{
  long long ll[2];
} c2 = { 0xDEADBEEF, 0xCAFEBABE };

struct y3
{
  int i[3];
} c3 = { 56789, 67890, 78901 };

typedef float vf2_t __attribute__((vector_size (8)));
struct x0
{
  vf2_t v;
} s0;

typedef short vh4_t __attribute__((vector_size (8)));

struct x1
{
  vh4_t v[2];
} s1;


void init_data ()
{
  s0.v = (vf2_t){ 17.f, 18.f };
  s1.v[0] = (vh4_t){ 345, 456, 567, 678 };
  s1.v[1] = (vh4_t){ 789, 890, 901, 123 };
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


{ struct y0 __x = c0; ; if (validate_memory (&__x, stack + 128, sizeof (struct y0), flat) != 0) abort(); }
{ struct y2 __x = c2; ; if (validate_memory (&__x, stack + 136, sizeof (struct y2), flat) != 0) abort(); }
{ struct y3 __x = c3; ; if (validate_memory (&__x, stack + 152, sizeof (struct y3), flat) != 0) abort(); }
{ struct x0 __x = s0; ; if (validate_memory (&__x, stack + 0, sizeof (struct x0), f32in64) != 0) abort(); }
{ struct x1 __x = s1; ; if (validate_memory (&__x, stack + 8, sizeof (struct x1), flat) != 0) abort(); }
{ int __x = 89012; ; if (validate_memory (&__x, stack + 168, sizeof (int), i32in64) != 0) abort(); }

  return;
}






void myfunc(


struct y0,
struct y2,
struct y3,
struct x0,
struct x1,
int

) ;
int main()
{




  init_data ();



  which_kind_of_test = TK_PARAM;
  myfunc(






c0,
c2,
c3,
s0,
s1,
89012

);
  return 0;
}

