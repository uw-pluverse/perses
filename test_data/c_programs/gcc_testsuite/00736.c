struct float_float_t
{
  float a;
  float b;
} float_float;

union float_int_t
{
  float b8;
  int b5;
} float_int;


void
init_data ()
{
  float_float.a = 1.2f;
  float_float.b = 2.2f;

  float_int.b8 = 4983.80f;
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


  { float __x = 1.0f; ; if (validate_memory (&__x, stack + 64, sizeof (float), flat) != 0) abort(); }
  { float __x = 2.0f; ; if (validate_memory (&__x, stack + 68, sizeof (float), flat) != 0) abort(); }
  { float __x = 3.0f; ; if (validate_memory (&__x, stack + 72, sizeof (float), flat) != 0) abort(); }
  { float __x = 4.0f; ; if (validate_memory (&__x, stack + 76, sizeof (float), flat) != 0) abort(); }
  { float __x = 5.0f; ; if (validate_memory (&__x, stack + 80, sizeof (float), flat) != 0) abort(); }
  { float __x = 6.0f; ; if (validate_memory (&__x, stack + 84, sizeof (float), flat) != 0) abort(); }
  { float __x = 7.0f; ; if (validate_memory (&__x, stack + 88, sizeof (float), flat) != 0) abort(); }
  { struct float_float_t __x = float_float; ; if (validate_memory (&__x, stack + 336, sizeof (struct float_float_t), flat) != 0) abort(); }
  { int __x = 9; ; if (validate_memory (&__x, stack + 96, sizeof (int), flat) != 0) abort(); }
  { int __x = 10; ; if (validate_memory (&__x, stack + 100, sizeof (int), flat) != 0) abort(); }
  { int __x = 11; ; if (validate_memory (&__x, stack + 104, sizeof (int), flat) != 0) abort(); }
  { int __x = 12; ; if (validate_memory (&__x, stack + 108, sizeof (int), flat) != 0) abort(); }
  { int __x = 13; ; if (validate_memory (&__x, stack + 112, sizeof (int), flat) != 0) abort(); }
  { int __x = 14; ; if (validate_memory (&__x, stack + 116, sizeof (int), flat) != 0) abort(); }
  { int __x = 15; ; if (validate_memory (&__x, stack + 120, sizeof (int), flat) != 0) abort(); }







  { union float_int_t __x = float_int; ; if (validate_memory (&__x, stack + 184, sizeof (union float_int_t), flat) != 0) abort(); }
  { long long __x = 12683143434LL; ; if (validate_memory (&__x, stack + 336 + 8, sizeof (long long), flat) != 0) abort(); }

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


  float,
  float,
  float,
  float,
  float,
  float,
  float,
  struct float_float_t,
  int,
  int,
  int,
  int,
  int,
  int,
  int,







  union float_int_t,
  long long

) ;






void stdarg_func(


  float _f0,
  float _f1,
  float _f2,
  float _f3,
  float _f4,
  float _f5,
  float _f6,
  struct float_float_t _f7,
  int _f8,
  int _f9,
  int _f10,
  int _f11,
  int _f12,
  int _f13,
  int _f65535,
  ...

)
{

  va_list ap;

  __builtin_va_start(ap, _f65535);;


  dummy_func (0, 0, 0, 0, 0, 0, 0, 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);


  __sync_synchronize ();
    {



  float _x0 = _f0;
  float _x1 = _f1;
  float _x2 = _f2;
  float _x3 = _f3;
  float _x4 = _f4;
  float _x5 = _f5;
  float _x6 = _f6;
  struct float_float_t _x7 = _f7;
  int _x8 = _f8;
  int _x9 = _f9;
  int _x10 = _f10;
  int _x11 = _f11;
  int _x12 = _f12;
  int _x13 = _f13;
  int _x65535 = _f65535;







  union float_int_t _x15 = __builtin_va_arg(ap, union float_int_t);
  long long _x16 = __builtin_va_arg(ap, long long);



      myfunc (


  _x0,
  _x1,
  _x2,
  _x3,
  _x4,
  _x5,
  _x6,
  _x7,
  _x8,
  _x9,
  _x10,
  _x11,
  _x12,
  _x13,
  _x65535,







  _x15,
  _x16

);
    }
  __builtin_va_end(ap);
}




int main()
{




  init_data ();






  which_kind_of_test = TK_VA_ARG;
  stdarg_func(



  1.0f,
  2.0f,
  3.0f,
  4.0f,
  5.0f,
  6.0f,
  7.0f,
  float_float,
  9,
  10,
  11,
  12,
  13,
  14,
  15,







  float_int,
  12683143434LL

);
  return 0;
}

