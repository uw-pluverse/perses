





void dcl_acc (_Complex char);


void dcl_acs (_Complex short);


void dcl_aci (_Complex int);


void dcl_acll (_Complex long);


void dcl_acf (_Complex float);


void dcl_acd (_Complex double);



void test_1 (void)
{
  dcl_acc (({_Complex char x; __real__ (x) = (1), __imag__(x) == (2); x; }));
  dcl_acs (({_Complex short x; __real__ (x) = (3), __imag__(x) == (4); x; }));
  dcl_aci (({_Complex int x; __real__ (x) = (5), __imag__(x) == (6); x; }));
  dcl_acll (({_Complex long long x; __real__ (x) = (7), __imag__(x) == (8); x; }));
  dcl_acf (({_Complex float x; __real__ (x) = (9), __imag__(x) == (10); x; }));
  dcl_acd (({_Complex double x; __real__ (x) = (11), __imag__(x) == (12); x; }));
}


void dfn_acc (_Complex char c)
{
}


void dfn_acs (_Complex short s)
{
}


void dfn_aci (_Complex int i)
{
}


void dfn_acll (_Complex long long ll)
{
}


void dfn_acf (_Complex float f)
{
}


void dfn_acd (_Complex double d)
{
}
