typedef char A __attribute__ ((vector_size (64)));

struct y
{
  double df[8];
};

union u
{
  struct y x;
  A a;
} u;


void init_data ()
{
  u.x.df[0] = 1.0;
  u.x.df[1] = 2.0;
  u.x.df[2] = 3.0;
  u.x.df[3] = 4.0;
  u.x.df[4] = 5.0;
  u.x.df[5] = 6.0;
  u.x.df[6] = 7.0;
  u.x.df[7] = 8.0;
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


{ float __x = 123.0f; ; if (validate_memory (&__x, stack + 64, sizeof (float), flat) != 0) abort(); }
{ A * ptr; ; ptr = *(A **)(stack + 128); if (memcmp (ptr, &u.a, sizeof (A)) != 0) abort (); }
{ int __x = 0xdeadbeef; ; if (validate_memory (&__x, stack + 136, sizeof (int), i32in64) != 0) abort(); }

  return;
}






void myfunc(


float,
A,
int

) ;
int main()
{




  init_data ();



  which_kind_of_test = TK_PARAM;
  myfunc(






123.0f,
u.a,
0xdeadbeef

);
  return 0;
}

