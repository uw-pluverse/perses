


extern void abort (void);



short a[128];
short d[128];

volatile int y = 0;

int foo ()
{
  int i;
  short b[128];
  short c[128];
  for (i = 0; i < 128/2; i++)
    {
      b[i] = i*3;
      c[i] = i;


      if (y)
 abort ();
    }


  for (i = 0; i < 128/2; i++)
    {
      a[i] = b[2*i+1] * c[2*i+1] - b[2*i] * c[2*i];
      d[i] = b[2*i] * c[2*i+1] + b[2*i+1] * c[2*i];
    }

  return 0;
}
