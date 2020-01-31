




extern void link_error (void);

void
f3 (int s)
{
  if (s >> 3 == -2)

    ;
  else
    {

      switch (s)
 {
 case -16:
 case -12:
 case -9:
   link_error ();
   break;
 default:
   break;
 }
    }
}

int
main ()
{
  return 0;
}
