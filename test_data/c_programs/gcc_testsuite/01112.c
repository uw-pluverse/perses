







  typedef __builtin_va_list __gnuc_va_list;




  typedef __gnuc_va_list va_list;

extern void abort (void);

long double
__attribute__ ((ms_abi)) func_cross (long double a, double b, float c, long d, int e,
     char f)
{
  long double ret;
  ret = a + (long double) b + (long double) c;
  ret *= (long double) (d + (long) e);
  if (f>0)
    ret += func_cross (a,b,c,d,e,-f);
  return ret;
}

long double
               func_native (long double a, double b, float c, long d, int e,
       char f)
{
  long double ret;
  ret = a + (long double) b + (long double) c;
  ret *= (long double) (d + (long) e);
  if (f>0)
    ret += func_native (a,b,c,d,e,-f);
  return ret;
}

int main ()
{
  if (func_cross (1.0,2.0,3.0,1,2,3)
      != func_native (1.0,2.0,3.0,1,2,3))
    abort ();
  return 0;
}
