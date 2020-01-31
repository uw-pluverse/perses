struct
  {
    int input;
    int output;
  }
ffstesttab[] =
  {


    { 0x80000000, 32 },
    { 0xa5a5a5a5, 1 },
    { 0x5a5a5a5a, 2 },
    { 0xcafe0000, 18 },



    { 0x8000, 16 },
    { 0xa5a5, 1 },
    { 0x5a5a, 2 },
    { 0x0ca0, 6 },




  };



extern void abort (void);
extern void exit (int);

int
main (void)
{
  int i;

  for (i = 0; i < (sizeof (ffstesttab) / sizeof (ffstesttab[0])); i++)
    {
      if (__builtin_ffs (ffstesttab[i].input) != ffstesttab[i].output)
 abort ();
    }

  exit (0);
}
