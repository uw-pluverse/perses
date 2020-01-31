







  typedef __builtin_va_list __gnuc_va_list;




  typedef __gnuc_va_list va_list;

extern void abort (void);



static
int fct1 (__builtin_ms_va_list argp, ...)
{
  long long p1,p2;
  int ret = 1;
  va_list argp_2;

    __builtin_va_start(argp_2,argp);
  do {
    p1 = __builtin_va_arg(argp_2,long long);
    p2 = __builtin_va_arg(argp,long long);
    if (p1 != p2)
      ret = 0;
  } while (ret && p1 != 0);
  __builtin_va_end(argp_2);
  return ret;
}

static
int __attribute__ ((ms_abi)) fct2 (int dummy, ...)
{
  __builtin_ms_va_list argp;
  int ret = dummy;

  __builtin_ms_va_start(argp,dummy);
  ret += fct1 (argp, 1ll,2ll,3ll,4ll,5ll,6ll,7ll,0ll);
  __builtin_ms_va_end(argp);
  return ret;
}

int main()
{
  if (fct2 (-1, 1ll,2ll,3ll,4ll,5ll,6ll,7ll,0ll) != 0)
    abort ();
  return 0;
}
