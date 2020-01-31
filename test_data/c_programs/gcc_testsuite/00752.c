struct z
{
  char c;
  short s;
  int ia[4];
};

struct z a, b, c;


void init_data ()
{
  a.c = 0x11;
  a.s = 0x2222;
  a.ia[0] = 0x33333333;
  a.ia[1] = 0x44444444;
  a.ia[2] = 0x55555555;
  a.ia[3] = 0x66666666;

  b.c = 0x77;
  b.s = 0x8888;
  b.ia[0] = 0x99999999;
  b.ia[1] = 0xaaaaaaaa;
  b.ia[2] = 0xbbbbbbbb;
  b.ia[3] = 0xcccccccc;

  c.c = 0xdd;
  c.s = 0xeeee;
  c.ia[0] = 0xffffffff;
  c.ia[1] = 0x12121212;
  c.ia[2] = 0x23232323;
  c.ia[3] = 0x34343434;
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


  { struct z * ptr; ; ptr = *(struct z **)(stack + 128); if (memcmp (ptr, &a, sizeof (struct z)) != 0) abort (); }
  { int __x = 0xdeadbeef; ; if (validate_memory (&__x, stack + 100, sizeof (int), flat) != 0) abort(); }
  { int __x = 0xcafebabe; ; if (validate_memory (&__x, stack + 104, sizeof (int), flat) != 0) abort(); }
  { int __x = 0xdeadbabe; ; if (validate_memory (&__x, stack + 108, sizeof (int), flat) != 0) abort(); }
  { int __x = 0xcafebeef; ; if (validate_memory (&__x, stack + 112, sizeof (int), flat) != 0) abort(); }
  { int __x = 0xbeefdead; ; if (validate_memory (&__x, stack + 116, sizeof (int), flat) != 0) abort(); }
  { int __x = 0xbabecafe; ; if (validate_memory (&__x, stack + 120, sizeof (int), flat) != 0) abort(); }

  { struct z * ptr; ; ptr = *(struct z **)(stack + 184); if (memcmp (ptr, &b, sizeof (struct z)) != 0) abort (); }
  { struct z * ptr; ; ptr = *(struct z **)(stack + 336); if (memcmp (ptr, &c, sizeof (struct z)) != 0) abort (); }

  { int __x = 0xbabedead; ; if (validate_memory (&__x, stack + 336 +8, sizeof (int), flat) != 0) abort(); }



  { double __x = 123.45; ; if (validate_memory (&__x, stack + 0, sizeof (double), flat) != 0) abort(); }

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


  struct z,
  int,
  int,
  int,
  int,
  int,
  int,

  struct z,
  struct z,

  int,



  double

) ;






void stdarg_func(


  struct z _f0,
  int _f1,
  int _f2,
  int _f3,
  int _f4,
  int _f5,
  int _f65535,
  ...

)
{

  va_list ap;

  __builtin_va_start(ap, _f65535);;


  dummy_func (0, 0, 0, 0, 0, 0, 0, 0, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f, 0.f);


  __sync_synchronize ();
    {



  struct z _x0 = _f0;
  int _x1 = _f1;
  int _x2 = _f2;
  int _x3 = _f3;
  int _x4 = _f4;
  int _x5 = _f5;
  int _x65535 = _f65535;

  struct z _x7 = __builtin_va_arg(ap, struct z);
  struct z _x8 = __builtin_va_arg(ap, struct z);

  int _x9 = __builtin_va_arg(ap, int);



  double _x10 = __builtin_va_arg(ap, double);



      myfunc (


  _x0,
  _x1,
  _x2,
  _x3,
  _x4,
  _x5,
  _x65535,

  _x7,
  _x8,

  _x9,



  _x10

);
    }
  __builtin_va_end(ap);
}




int main()
{




  init_data ();






  which_kind_of_test = TK_VA_ARG;
  stdarg_func(



  a,
  0xdeadbeef,
  0xcafebabe,
  0xdeadbabe,
  0xcafebeef,
  0xbeefdead,
  0xbabecafe,

  b,
  c,

  0xbabedead,



  123.45

);
  return 0;
}

