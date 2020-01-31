


feq (x)
     long long int x;
{
  if (x == 0)
    return 13;
  else
    return 140;
}

fne (x)
     long long int x;
{
  if (x != 0)
    return 13;
  else
    return 140;
}

flt (x)
     long long int x;
{
  if (x < 0)
    return 13;
  else
    return 140;
}

fge (x)
     long long int x;
{
  if (x >= 0)
    return 13;
  else
    return 140;
}

fgt (x)
     long long int x;
{
  if (x > 0)
    return 13;
  else
    return 140;
}

fle (x)
     long long int x;
{
  if (x <= 0)
    return 13;
  else
    return 140;
}

main ()
{
  if (feq (0LL) != 13)
    abort ();
  if (feq (-1LL) != 140)
    abort ();
  if (feq (0x8000000000000000LL) != 140)
    abort ();
  if (feq (0x8000000000000001LL) != 140)
    abort ();
  if (feq (1LL) != 140)
    abort ();
  if (feq (0x7fffffffffffffffLL) != 140)
    abort ();

  if (fne (0LL) != 140)
    abort ();
  if (fne (-1LL) != 13)
    abort ();
  if (fne (0x8000000000000000LL) != 13)
    abort ();
  if (fne (0x8000000000000001LL) != 13)
    abort ();
  if (fne (1LL) != 13)
    abort ();
  if (fne (0x7fffffffffffffffLL) != 13)
    abort ();

  if (flt (0LL) != 140)
    abort ();
  if (flt (-1LL) != 13)
    abort ();
  if (flt (0x8000000000000000LL) != 13)
    abort ();
  if (flt (0x8000000000000001LL) != 13)
    abort ();
  if (flt (1LL) != 140)
    abort ();
  if (flt (0x7fffffffffffffffLL) != 140)
    abort ();

  if (fge (0LL) != 13)
    abort ();
  if (fge (-1LL) != 140)
    abort ();
  if (fge (0x8000000000000000LL) != 140)
    abort ();
  if (fge (0x8000000000000001LL) != 140)
    abort ();
  if (fge (1LL) != 13)
    abort ();
  if (fge (0x7fffffffffffffffLL) != 13)
    abort ();

  if (fgt (0LL) != 140)
    abort ();
  if (fgt (-1LL) != 140)
    abort ();
  if (fgt (0x8000000000000000LL) != 140)
    abort ();
  if (fgt (0x8000000000000001LL) != 140)
    abort ();
  if (fgt (1LL) != 13)
    abort ();
  if (fgt (0x7fffffffffffffffLL) != 13)
    abort ();

  if (fle (0LL) != 13)
    abort ();
  if (fle (-1LL) != 13)
    abort ();
  if (fle (0x8000000000000000LL) != 13)
    abort ();
  if (fle (0x8000000000000001LL) != 13)
    abort ();
  if (fle (1LL) != 140)
    abort ();
  if (fle (0x7fffffffffffffffLL) != 140)
    abort ();

  exit (0);
}
