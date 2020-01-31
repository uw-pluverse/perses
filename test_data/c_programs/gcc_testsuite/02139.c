main ()
{
  union
    {
      double d;
      unsigned short i[sizeof (double) / sizeof (short)];
    } u;
  int a = 0;
  int b = -5;
  int j;

  u.d = (double) a / b;



  for (j = 0; j < sizeof (double) / sizeof (short); j++)
    {
      if (u.i[j] == 0x8000)
 exit (0);
    }
  abort ();
}
