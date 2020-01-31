



extern void abort (void);
extern void exit (int);

typedef int int32 __attribute__ ((mode (SI)));
typedef int int64 __attribute__ ((mode (DI)));
int foo (float inf, int64 in64, int32 in32)
{
  int64 res64;
  int32 res32;
}

int main ()
{
  foo (11.4f, 25, 60);
  exit (0);
}
