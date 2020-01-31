


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern long unsigned int __attribute__ ((sysv_abi)) strlen (const char *);
extern int __attribute__ ((sysv_abi)) sprintf (char *, const char *, ...);

static void
vdo_cpy (char *s, va_list argp)
{
  long unsigned int len;
  char *r = s;
  char *e;
  *r = 0;
  for (;;) {
    e = __builtin_va_arg(argp, char *);
    if (*e == 0) break;
    sprintf (r,"%s", e);
    r += strlen (r);
  }
}

void
do_cpy (char *s, ...)
{
  va_list argp;
  __builtin_va_start(argp, s);
  vdo_cpy (s, argp);
  __builtin_va_end(argp);
}
