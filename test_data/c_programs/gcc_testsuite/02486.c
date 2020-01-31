extern void abort(void);
extern void main_test (void);
extern void abort (void);
int inside_main;

int
main ()
{
  inside_main = 1;
  main_test ();
  inside_main = 0;
  return 0;
}






void
link_error (void)
{
  abort ();
}
