struct z
{
  double x[4];
};

double d1 = 25.0;
struct z a = { 5.0, 6.0, 7.0, 8.0 };
struct z b = { 9.0, 10.0, 11.0, 12.0 };


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


  { double __x = 11.0; ; if (validate_memory (&__x, stack + 0, sizeof (double), flat) != 0) abort(); }

  { int __x = 8; ; if (validate_memory (&__x, stack + 96, sizeof (int), flat) != 0) abort(); }
  { struct z __x = a; ; if (validate_memory (&__x, stack + 8, sizeof (struct z), flat) != 0) abort(); }
  { struct z __x = b; ; if (validate_memory (&__x, stack + 336, sizeof (struct z), flat) != 0) abort(); }
  { int __x = 5; ; if (validate_memory (&__x, stack + 100, sizeof (int), flat) != 0) abort(); }
  { double __x = d1; ; if (validate_memory (&__x, stack + 336 +32, sizeof (double), flat) != 0) abort(); }
  { double __x = 0.5; ; if (validate_memory (&__x, stack + 336 +40, sizeof (double), flat) != 0) abort(); }

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


  double,

  int,
  struct z,
  struct z,
  int,
  double,
  double

) ;






void stdarg_func(


  double _f65535,
  ...

)
{

  va_list ap;

  __builtin_va_start(ap, _f65535);;


  dummy_func (0, 0, 0, 0, 0, 0, 0, 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);


  __sync_synchronize ();
    {



  double _x65535 = _f65535;

  int _x1 = __builtin_va_arg(ap, int);
  struct z _x2 = __builtin_va_arg(ap, struct z);
  struct z _x3 = __builtin_va_arg(ap, struct z);
  int _x4 = __builtin_va_arg(ap, int);
  double _x5 = __builtin_va_arg(ap, double);
  double _x6 = __builtin_va_arg(ap, double);



      myfunc (


  _x65535,

  _x1,
  _x2,
  _x3,
  _x4,
  _x5,
  _x6

);
    }
  __builtin_va_end(ap);
}




int main()
{
  which_kind_of_test = TK_VA_ARG;
  stdarg_func(



  11.0,

  8,
  a,
  b,
  5,
  d1,
  0.5

);
  return 0;
}

