







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


  { double __x = 1.0; ; if (validate_memory (&__x, stack + 0, sizeof (double), flat) != 0) abort(); }
  { double __x = 2.0; ; if (validate_memory (&__x, stack + 8, sizeof (double), flat) != 0) abort(); }
  { double __x = 3.0; ; if (validate_memory (&__x, stack + 16, sizeof (double), flat) != 0) abort(); }
  { double __x = 4.0; ; if (validate_memory (&__x, stack + 24, sizeof (double), flat) != 0) abort(); }
  { double __x = 5.0; ; if (validate_memory (&__x, stack + 32, sizeof (double), flat) != 0) abort(); }
  { double __x = 6.0; ; if (validate_memory (&__x, stack + 40, sizeof (double), flat) != 0) abort(); }
  { double __x = 7.0; ; if (validate_memory (&__x, stack + 48, sizeof (double), flat) != 0) abort(); }
  { double __x = 8.0; ; if (validate_memory (&__x, stack + 56, sizeof (double), flat) != 0) abort(); }
  { double __x = 9.0; ; if (validate_memory (&__x, stack + 336, sizeof (double), flat) != 0) abort(); }
  { double __x = 10.0; ; if (validate_memory (&__x, stack + 336 +8, sizeof (double), flat) != 0) abort(); }

  return;
}






void myfunc(


  double,
  double,
  double,
  double,
  double,
  double,
  double,
  double,
  double,
  double

) ;
int main()
{
  which_kind_of_test = TK_PARAM;
  myfunc(






  1.0,
  2.0,
  3.0,
  4.0,
  5.0,
  6.0,
  7.0,
  8.0,
  9.0,
  10.0

);
  return 0;
}

