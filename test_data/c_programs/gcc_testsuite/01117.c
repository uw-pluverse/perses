







  typedef __builtin_va_list __gnuc_va_list;




  typedef __gnuc_va_list va_list;

extern long unsigned int strlen (const char *);
extern int sprintf (char *,const char *, ...);
extern void abort (void);

static
void __attribute__ ((ms_abi)) vdo_cpy (char *s, __builtin_ms_va_list argp)
{
  long unsigned int len;
  char *r = s;
  char *e;
  *r = 0;
  for (;;) {
    e = __builtin_va_arg(argp,char *);
    if (*e == 0) break;
    sprintf (r,"%s", e);
    r += strlen (r);
  }
}

static
void __attribute__ ((ms_abi)) do_cpy (char *s, ...)
{
  __builtin_ms_va_list argp;
  __builtin_ms_va_start(argp,s);
  vdo_cpy (s, argp);
  __builtin_ms_va_end(argp);
}

int main ()
{
  char s[256];

  do_cpy (s, "1","2","3","4", "5", "6", "7", "");

  if (s[0] != '1' || s[1] !='2' || s[2] != '3' || s[3] != '4'
      || s[4] != '5' || s[5] != '6' || s[6] != '7' || s[7] != 0)
    abort ();

  return 0;
}
