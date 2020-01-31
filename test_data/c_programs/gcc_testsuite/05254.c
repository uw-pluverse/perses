


extern void link_error (void);



void
f3 (int s, int b)
{
  if (s >> 3 == -2)

    {
      s += 17;

      b = (b & 1) + 1;

      b = b << s;



      if (b == 1 || b == 513)
 link_error ();
    }
}

int
main ()
{
  return 0;
}
