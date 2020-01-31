







extern void abort (void);
extern void exit (int);
extern int strcmp (const char *, const char *);

static const union codestrs_t_4 {
  struct {
    char str_2[sizeof ("Illegal opcode")];
  };
  char str[0];
} codestrs_4 = { {"Illegal opcode"} };

static const union codestrs_t_8 {
  struct {
    char str_12[sizeof ("Integer divide by zero")];
  };
  char str[0];
} codestrs_8 = { {"Integer divide by zero"} };

const char *
psiginfo (int pinfo)
{
  const char *base = ((void *)0);

  switch (pinfo)
    {
    case 4: base = codestrs_4.str; break;
    case 8: base = codestrs_8.str; break;
    }
  return base;
}

int
main (void)
{
  if (strcmp (psiginfo (4), codestrs_4.str))
    abort ();
  if (strcmp (psiginfo (8), codestrs_8.str))
    abort ();
  exit (0);
}
