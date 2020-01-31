struct z
{
  double x[4];
};

struct z a = { 5.0, 6.0, 7.0, 8.0 };


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


  { int __x = 0xdeadbeef; ; if (validate_memory (&__x, stack + 96, sizeof (int), flat) != 0) abort(); }

  { double __x = 4.0; ; if (validate_memory (&__x, stack + 0, sizeof (double), flat) != 0) abort(); }
  { struct z __x = a; ; if (validate_memory (&__x, stack + 8, sizeof (struct z), flat) != 0) abort(); }

  return;
}
typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;



__attribute__ ((noinline)) void
dummy_func (int w0, int w1, int w2, int w3, int w4, int w5, int w6, int w7,
     float s0, float s1, float s2, float s3, float s4, float s5,
     float s6, float s7)
{
  asm ("");
  return;
}


void myfunc(


  int,

  double,
  struct z

) ;






void stdarg_func(


  int _f65535,
  ...

)
{

  va_list ap;

  __builtin_va_start(ap, _f65535);;


  dummy_func (0, 0, 0, 0, 0, 0, 0, 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);


  __sync_synchronize ();
    {



  int _x65535 = _f65535;

  double _x1 = __builtin_va_arg(ap, double);
  struct z _x2 = __builtin_va_arg(ap, struct z);



      myfunc (


  _x65535,

  _x1,
  _x2

);
    }
  __builtin_va_end(ap);
}




int main()
{
  which_kind_of_test = TK_VA_ARG;
  stdarg_func(



  0xdeadbeef,

  4.0,
  a

);
  return 0;
}

