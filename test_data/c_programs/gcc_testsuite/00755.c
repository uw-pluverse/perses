






struct y
{
  float p;
  float q;
} v = { 345.0f, 678.0f };


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
  { struct y __x = v; ; if (validate_memory (&__x, stack + 68, sizeof (struct y), flat) != 0) abort(); }
  { float __x = 901.0f; ; if (validate_memory (&__x, stack + 76, sizeof (float), flat) != 0) abort(); }

  return;
}






void myfunc(


  float,
  struct y,
  float

) ;
int main()
{
  which_kind_of_test = TK_PARAM;
  myfunc(






  123.0f,
  v,
  901.0f

);
  return 0;
}

