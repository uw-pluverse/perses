






struct s
  {
    long x;
    long y;
  };


typedef __attribute__ ((__aligned__ (32))) struct s overaligned;


overaligned a = { 2, 3 };
overaligned b = { 5, 8 };
overaligned c = { 13, 21 };


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


  { int __x = 7; ; if (validate_memory (&__x, stack + 96, sizeof (int), flat) != 0) abort(); }

  { overaligned __x = a; ; if (validate_memory (&__x, stack + 136, sizeof (overaligned), flat) != 0) abort(); }
  { int __x = 9; ; if (validate_memory (&__x, stack + 108, sizeof (int), flat) != 0) abort(); }
  { int __x = 11; ; if (validate_memory (&__x, stack + 112, sizeof (int), flat) != 0) abort(); }
  { overaligned __x = b; ; if (validate_memory (&__x, stack + 168, sizeof (overaligned), flat) != 0) abort(); }
  { int __x = 15; ; if (validate_memory (&__x, stack + 124, sizeof (int), flat) != 0) abort(); }

  { int __x = 10; ; if (validate_memory (&__x, stack + 336, sizeof (int), flat) != 0) abort(); }




  { overaligned __x = c; ; if (validate_memory (&__x, stack + 336 + 8, sizeof (overaligned), flat) != 0) abort(); }

  return;
}






void myfunc(


  int,

  overaligned,
  int,
  int,
  overaligned,
  int,

  int,




  overaligned

) ;
int main()
{
  which_kind_of_test = TK_PARAM;
  myfunc(






  7,

  a,
  9,
  11,
  b,
  15,

  10,




  c

);
  return 0;
}

