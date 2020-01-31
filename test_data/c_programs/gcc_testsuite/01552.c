





void dcl_rv ();


char dcl_rc ();


short dcl_rs ();


int dcl_ri ();


long long dcl_rll ();


float dcl_rf ();


double dcl_rd ();


void *dcl_rp ();

void test_1 ()
{
  dcl_rv ();
  dcl_rc ();
  dcl_rs ();
  dcl_ri ();
  dcl_rll ();
  dcl_rf ();
  dcl_rd ();
  dcl_rp ();
}


void dfn_rv ()
{
  return;
}


char dfn_rc ()
{
  return 1;
}


short dfn_rs ()
{
  return 2;
}


int dfn_ri ()
{
  return 3;
}


long long dfn_rll ()
{
  return 4;
}


float dfn_rf ()
{
  return 5;
}


double dfn_rd ()
{
  return 6;
}


void *dfn_rp ()
{
  return 0;
}
