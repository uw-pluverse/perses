




typedef int __attribute__((mode(TI))) ti;


void dcl_rv (void);


char dcl_rc (void);


short dcl_rs (void);


int dcl_ri (void);


long long dcl_rll (void);


ti dcl_rti (void);


float dcl_rf (void);


double dcl_rd (void);


void *dcl_rp (void);

void test_1 (void)
{
  dcl_rv ();
  dcl_rc ();
  dcl_rs ();
  dcl_ri ();
  dcl_rll ();
  dcl_rti ();
  dcl_rf ();
  dcl_rd ();
  dcl_rp ();
}


void dfn_rv (void)
{
  return;
}


char dfn_rc (void)
{
  return 1;
}


short dfn_rs (void)
{
  return 2;
}


int dfn_ri (void)
{
  return 3;
}


long long dfn_rll (void)
{
  return 4;
}


ti dfn_rti (void)
{
  return 5;
}


float dfn_rf (void)
{
  return 6;
}


double dfn_rd (void)
{
  return 7;
}


void *dfn_rp (void)
{
  return 0;
}
