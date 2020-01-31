volatile int *a;

inline void
third (int arg3)
{
  int var3 = arg3;
  a[0] = var3;
}

inline void
second (int arg2)
{
  int var2 = arg2;
  third (var2+1);
}

inline void
first (int arg1)
{
  int var1 = arg1;
  second (var1+1);
}

int
main ()
{
  int some_int = 1;
  first (some_int);
  return 0;
}
