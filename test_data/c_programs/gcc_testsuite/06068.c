


extern void abort (void);

int
foo (int k, int j)
{
  if (k >= 10)
    {
      if (j > k)
 {

   if (j < 10)
     abort ();
 }
    }

  return j;
}

int
main()
{
  foo (10, 3);
  return 0;
}
