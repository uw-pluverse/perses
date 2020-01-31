




typedef int __attribute__((mode(TI))) ti;


void dcl_av (void);


void dcl_ac (char);


void dcl_as (short);


void dcl_ai (int);


void dcl_all (long long);


void dcl_ati (ti);


void dcl_af (float);


void dcl_ad (double);


void dcl_ap (void *);

void test_1 (void)
{
  dcl_av ();
  dcl_ac (1);
  dcl_as (2);
  dcl_ai (3);
  dcl_all (4);
  dcl_ati (5);
  dcl_af (6);
  dcl_ad (7);
  dcl_ap (0);
}


void dfn_av (void)
{
}


void dfn_ac (char c)
{
}


void dfn_as (short s)
{
}


void dfn_ai (int i)
{
}


void dfn_all (long long ll)
{
}


void dfn_ati (ti t)
{
}


void dfn_af (float f)
{
}


void dfn_ad (double d)
{
}


void dfn_ap (void *p)
{
}
