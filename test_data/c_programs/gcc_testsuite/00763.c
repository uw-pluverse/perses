






typedef __attribute__ ((__aligned__ (16))) long alignedint;

alignedint a = 11;
alignedint b = 13;
alignedint c = 17;
alignedint d = 19;
alignedint e = 23;
alignedint f = 29;
alignedint g = 31;
alignedint h = 37;
alignedint i = 41;
alignedint j = 43;


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


  { alignedint __x = a; ; if (validate_memory (&__x, stack + 128, sizeof (alignedint), flat) != 0) abort(); }

  { alignedint __x = b; ; if (validate_memory (&__x, stack + 136, sizeof (alignedint), flat) != 0) abort(); }
  { alignedint __x = c; ; if (validate_memory (&__x, stack + 144, sizeof (alignedint), flat) != 0) abort(); }
  { alignedint __x = d; ; if (validate_memory (&__x, stack + 152, sizeof (alignedint), flat) != 0) abort(); }
  { alignedint __x = e; ; if (validate_memory (&__x, stack + 160, sizeof (alignedint), flat) != 0) abort(); }
  { alignedint __x = f; ; if (validate_memory (&__x, stack + 168, sizeof (alignedint), flat) != 0) abort(); }
  { alignedint __x = g; ; if (validate_memory (&__x, stack + 176, sizeof (alignedint), flat) != 0) abort(); }
  { alignedint __x = h; ; if (validate_memory (&__x, stack + 184, sizeof (alignedint), flat) != 0) abort(); }
  { alignedint __x = i; ; if (validate_memory (&__x, stack + 336, sizeof (alignedint), flat) != 0) abort(); }

  { alignedint __x = j; ; if (validate_memory (&__x, stack + 336 + 8, sizeof (alignedint), flat) != 0) abort(); }

  return;
}






void myfunc(


  alignedint,

  alignedint,
  alignedint,
  alignedint,
  alignedint,
  alignedint,
  alignedint,
  alignedint,
  alignedint,

  alignedint

) ;
int main()
{
  which_kind_of_test = TK_PARAM;
  myfunc(






  a,

  b,
  c,
  d,
  e,
  f,
  g,
  h,
  i,

  j

);
  return 0;
}

