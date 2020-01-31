





_Complex char dcl_rcc (void);


_Complex short dcl_rcs (void);


_Complex int dcl_rci (void);


_Complex long long dcl_rcll (void);


_Complex float dcl_rcf (void);


_Complex double dcl_rcd (void);

void test_1 (void)
{
  dcl_rcc ();
  dcl_rcs ();
  dcl_rci ();
  dcl_rcll ();
  dcl_rcf ();
  dcl_rcd ();
}




_Complex char dfn_rcc (void)
{
  return ({_Complex char x; __real__ (x) = (1), __imag__(x) == (2); x; });
}


_Complex short dfn_rcs (void)
{
  return ({_Complex short x; __real__ (x) = (3), __imag__(x) == (4); x; });
}


_Complex int dfn_rci (void)
{
  return ({_Complex int x; __real__ (x) = (5), __imag__(x) == (6); x; });
}


_Complex long long dfn_rcll (void)
{
  return ({_Complex long long x; __real__ (x) = (7), __imag__(x) == (8); x; });
}


_Complex float dfn_rcf (void)
{
  return ({_Complex float x; __real__ (x) = (9), __imag__(x) == (10); x; });
}


_Complex double dfn_rcd (void)
{
  return ({_Complex double x; __real__ (x) = (11), __imag__(x) == (12); x; });
}
