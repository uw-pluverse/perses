


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void __attribute__ ((sysv_abi)) abort (void);

char *a = "1";
char *b = "2";

static void __attribute__((noinline,noclone))
do_cpy2 (va_list argp)
{
  char *e;

  e = __builtin_va_arg(argp, char *);
  e = __builtin_va_arg(argp, char *);
  if (e != b)
    abort ();
}

void __attribute__((noinline,noclone))
do_cpy (int dummy, ...)
{
  va_list argp;

  __builtin_va_start(argp, dummy);

  do_cpy2 (argp);

  __builtin_va_end(argp);
}

int __attribute__ ((sysv_abi))
main ()
{
  do_cpy (0, a, b);

  return 0;
}
