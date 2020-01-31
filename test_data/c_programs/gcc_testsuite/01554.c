





void dcl_av ();


void dcl_ac ();


void dcl_as ();


void dcl_ai ();


void dcl_all ();


void dcl_af ();


void dcl_ad ();


void dcl_ap ();

void test_1 (void)
{
  dcl_av ();
  dcl_ac ((char)1);
  dcl_as ((short)2);
  dcl_ai ((int)3);
  dcl_all ((long long)4);
  dcl_af ((float)5);
  dcl_ad ((double)6);
  dcl_ap ((void *)0);
}


void dfn_av ()
{
}


void dfn_ac (c)
  char c;
{
}


void dfn_as (s)
  short s;
{
}


void dfn_ai (i)
  int i;
{
}


void dfn_all (ll)
  long long ll;
{
}


void dfn_af (f)
  float f;
{
}


void dfn_ad (d)
  double d;
{
}


void dfn_ap (p)
  void *p;
{
}





void dfn_acf (_Complex float f)
{
}
