





_Bool F1 (_Bool B1, _Bool B2)
{
  _Bool R;

  if (B1
      && B2)
    R = 1;
  else
    R = 0;
  return R;
}

_Bool F2 (_Bool B1, _Bool B2)
{
  _Bool R;

  R = B1
      && B2;
  return R;
}

_Bool F3 (_Bool B1, _Bool B2)
{
  _Bool R = 0;

  if (B1
      && B2)
    R = 1;
  return R;
}

_Bool F4 (_Bool B1, _Bool B2)
{
  _Bool R = 0;

  if (B1
      || B2)
    ;
  else
    R = 1;
  return R;
}

_Bool F5 (_Bool B1, _Bool B2)
{
  _Bool R = 0;

  if (!(B1
        && B2))
    R = 1;
  return R;
}

_Bool F8 (_Bool B1, _Bool B2, _Bool B3, _Bool B4, _Bool B5, _Bool B6,
          _Bool B7, _Bool B8)
{
  _Bool R;

  if ((B1
       || B2)
       && B3
       && !(B4
            || B5)
       && (B6
           || (B7
               && B8)))
    R = 1;
  else
    R = 0;
  return R;
}
