


typedef unsigned __int128 V;
typedef unsigned long long int H;





__attribute__((noinline, noclone)) void
foo (V b, V c)
{
  V a;
  b &= (H) -1;
  c &= (H) -1;
  a = b * c;
  if (a != 1)
    __builtin_abort ();
}

int
main ()
{
  foo (1, 1);
  return 0;
}
