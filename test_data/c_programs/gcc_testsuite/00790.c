


extern void abort (void);

long long int
dummy_number_generator ()
{



  return -346565474575675;
}

int
main (void)
{

  long long int num = dummy_number_generator ();
  if (num > 0)
    abort ();



  if (num / 69313094915135 != -5)
    abort ();

  return 0;
}
