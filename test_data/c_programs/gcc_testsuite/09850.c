





extern int aligned_x (void);
extern int aligned_y_avx (void);
extern void abort (void);

int
main ()
{
  if (aligned_x () != aligned_y_avx ())
    abort ();

  return 0;
}
