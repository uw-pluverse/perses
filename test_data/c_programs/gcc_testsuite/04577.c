


typedef const unsigned long long int CULLI;
typedef volatile int VI;
struct s { signed long int a; };

int
main (void)
{
  int a = 1;
  struct s s = { .a = 400 };
  CULLI culli = 42;
  VI vi = 370;
  volatile int shiftcount = 153;

  a <<= 152;
  1 << shiftcount;
  1 << 154;
  culli << 524;
  1 << vi++;
  (long) 1 << (s.a + 2);

  return 0;
}
