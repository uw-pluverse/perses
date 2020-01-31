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
static void rt_endian_check ()
{
  const char* msg_endian[2] = {"little-endian", "big-endian"};
  const char* msg_env[2] = {"compile-time", "run-time"};
  union
  {
    unsigned int ui;
    unsigned char ch[4];
  } u;
  int flag = -1;

  u.ui = 0xCAFEBABE;

  printf ("u.ui=0x%X, u.ch[0]=0x%X\n", u.ui, u.ch[0]);

  if (u.ch[0] == 0xBE)
    {





    }
  else
    {



      flag = 0;

    }

  if (flag != -1)
    {

      printf ("Error: endianness conflicts between %s and %s:\n\t%s: %s\n\t%s: %s\n", msg_env[0], msg_env[1], msg_env[0], msg_endian[flag],

         msg_env[1], msg_endian[1-flag]);
      abort ();
    }

  return;
}
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


  { int __x = 4; ; if (validate_memory (&__x, stack + 96, sizeof (int), flat) != 0) abort(); }
  { double __x = 4.0; ; if (validate_memory (&__x, stack + 0, sizeof (double), flat) != 0) abort(); }
  { int __x = 3; ; if (validate_memory (&__x, stack + 100, sizeof (int), flat) != 0) abort(); }


  { char __x = 0xEF; ; if (validate_memory (&__x, stack + 144, sizeof (char), flat) != 0) abort(); }
  { short __x = 0xBEEF; ; if (validate_memory (&__x, stack + 152, sizeof (short), flat) != 0) abort(); }
  { int __x = 0xDEADBEEF; ; if (validate_memory (&__x, stack + 160, sizeof (int), flat) != 0) abort(); }






  { long long __x = 0xDEADBEEFCAFEBABELL; ; if (validate_memory (&__x, stack + 168, sizeof (long long), flat) != 0) abort(); }

  return;
}






void myfunc(


  int,
  double,
  int,


  char,
  short,
  int,






  long long

) ;
int main()
{

  rt_endian_check();






  which_kind_of_test = TK_PARAM;
  myfunc(






  4,
  4.0,
  3,


  0xEF,
  0xBEEF,
  0xDEADBEEF,






  0xDEADBEEFCAFEBABELL

);
  return 0;
}

