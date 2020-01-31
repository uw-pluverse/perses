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


  { float __x = 1.0; ; if (validate_memory (&__x, stack + 64, sizeof (float), flat) != 0) abort(); }
  { float __x = 2.0; ; if (validate_memory (&__x, stack + 68, sizeof (float), flat) != 0) abort(); }
  { float __x = 3.0; ; if (validate_memory (&__x, stack + 72, sizeof (float), flat) != 0) abort(); }
  { float __x = 4.0; ; if (validate_memory (&__x, stack + 76, sizeof (float), flat) != 0) abort(); }
  { float __x = 5.0; ; if (validate_memory (&__x, stack + 80, sizeof (float), flat) != 0) abort(); }
  { float __x = 6.0; ; if (validate_memory (&__x, stack + 84, sizeof (float), flat) != 0) abort(); }
  { float __x = 7.0; ; if (validate_memory (&__x, stack + 88, sizeof (float), flat) != 0) abort(); }
  { float __x = 8.0; ; if (validate_memory (&__x, stack + 92, sizeof (float), flat) != 0) abort(); }

  { float __x = 9.0; ; if (validate_memory (&__x, stack + 336, sizeof (float), flat) != 0) abort(); }
  { float __x = 10.0; ; if (validate_memory (&__x, stack + 336 +8, sizeof (float), flat) != 0) abort(); }

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
  float,

  float,
  float

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

