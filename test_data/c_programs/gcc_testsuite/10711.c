




extern int get_val (void);
extern int set_val (void);
extern void do_nothing (void);
void abort (void);
int
main()
{
  int a;
  int b;
  set_val ();
  a = get_val ();
  do_nothing();
  b = get_val ();
  if (a==b)
    {
      if (!__builtin_constant_p (a==b))
 abort ();
      return 0;
    }
  else
    abort ();
}
