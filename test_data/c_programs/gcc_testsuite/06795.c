






int a[199];

extern void abort (void);

int
main ()
{
  int i, x;
  for (i = 0; i < 199; i++)
    {
      x = a[i];
      if (x != i)
 abort ();
    }
  return 0;
}
