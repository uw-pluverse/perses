


extern void abort (void);
extern void exit (int);

int
main (void)
{
  int array1[1] = { 1 };
  int array2[2][1]= { { 1 }, { 0 } };
  if (array1[0] != 1)
    abort ();
  exit (0);
}
