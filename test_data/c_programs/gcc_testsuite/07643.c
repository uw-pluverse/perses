int foo1(int);
int foo2();

typedef struct {
  double d;
  int a;
} str_t;

void bar(double d, int i, str_t s)
{
  d = ((double (*) (int)) foo1) (i);
  i = ((int (*) (double)) foo1) (d);
  s = ((str_t (*) (int)) foo1) (i);
  ((void (*) (int)) foo1) (d);
  i = ((int (*) (int)) foo1) (i);
  (void) foo1 (i);

  d = ((double (*) (int)) foo2) (i);
  i = ((int (*) (double)) foo2) (d);
  s = ((str_t (*) (int)) foo2) (i);
  ((void (*) (int)) foo2) (d);
  i = ((int (*) (int)) foo2) (i);
  (void) foo2 (i);
}

int foo1(int arg)
{

  __asm volatile ("" : "+r" (arg));
  return arg;
}

int foo2(arg)
  int arg;
{

  __asm volatile ("" : "+r" (arg));
  return arg;
}
