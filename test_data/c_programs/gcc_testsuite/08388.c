extern void abort (void);
int e = 10, f = 100;






int
main ()
{
  if (4 + e != 14)
    abort ();

  if (4 + 4 + f != 108)
    abort ();

  if (e + e + f != 120)
    abort ();

  return 0;
}
