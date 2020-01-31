




void abort (void);
extern int undef_var0, undef_var1;
extern __attribute__ ((weak)) int weak_undef_var0;
extern __attribute__ ((weak)) int weak_undef_var1;
__attribute__ ((weak)) int weak_def_var0;
int def_var0=0, def_var1=0;
static int alias_var0 __attribute__ ((alias("def_var0")));
extern int weak_alias_var0 __attribute__ ((alias("def_var0"))) __attribute__ ((weak));
void undef_fn0(void);
void undef_fn1(void);
void def_fn0(void)
{
}
void def_fn1(void)
{
}
__attribute__ ((weak))
void weak_def_fn0(void)
{
}
__attribute__ ((weak))
void weak_def_fn1(void)
{
}
__attribute__ ((weak)) void weak_undef_fn0(void);

inline
void inline_fn0(void)
{
}
inline
void inline_fn1(void)
{
}

int
main(int argc, char **argv)
{

  if (!__builtin_constant_p (def_fn0 == def_fn1))
    abort();
  if (def_fn0 == def_fn1)
    abort();

  if (!__builtin_constant_p (&def_var0 == &def_var1))
    abort();
  if (&def_var0 == &def_var1)
    abort();


  if (!__builtin_constant_p (undef_fn0 != undef_fn0))
    abort ();
  if (undef_fn0 != undef_fn0)
    abort ();


  if (!__builtin_constant_p (&undef_var0 + argc != &undef_var0 + argc))
    abort ();
  if (&undef_var0 + argc != &undef_var0 + argc)
    abort ();


  if (!__builtin_constant_p (&def_var0 != &alias_var0))
    abort ();
  if (&def_var0 != &alias_var0 )
    abort ();

  if (__builtin_constant_p (&def_var0 != &weak_alias_var0))
    abort ();
  if (&def_var0 != &weak_alias_var0)
    abort ();


  if (__builtin_constant_p ((void *)weak_undef_fn0 == (void *)&weak_undef_var0))
    abort ();
  if ((void *)weak_undef_fn0 != (void *)&weak_undef_var0)
    abort ();


  if (!__builtin_constant_p ((void *)undef_fn0 == (void *)&undef_var0))
    abort ();
  if ((void *)undef_fn0 == (void *)&undef_var0)
    abort ();


  if (!__builtin_constant_p ((void *)weak_undef_fn0 == (void *)&weak_def_var0))
    abort ();
  if ((void *)weak_undef_fn0 == (void *)&weak_def_var0)
    abort ();


  if (!__builtin_constant_p (inline_fn0 != inline_fn1))
    abort ();
  if (inline_fn0 == inline_fn1)
    abort ();
  return 0;
}
