extern int inside_main;
extern void abort (void);






typedef long int intmax_t;

__attribute__ ((__noinline__))
int
abs (int x)
{
  do { } while (0);
  return x < 0 ? -x : x;
}

__attribute__ ((__noinline__))
long
labs (long x)
{
  do { } while (0);
  return x < 0 ? -x : x;
}

__attribute__ ((__noinline__))
long long
llabs (long long x)
{
  do { } while (0);
  return x < 0 ? -x : x;
}

__attribute__ ((__noinline__))
intmax_t
imaxabs (intmax_t x)
{
  do { } while (0);
  return x < 0 ? -x : x;
}
