


char *a;

main ()
{

  a = (char *)&a;


  a[0]++;




  if (a == (char *)&a)
    abort ();

  return 0;
}
