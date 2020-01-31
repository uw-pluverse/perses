




typedef enum { a = 0x1, b } Echar;
typedef enum { c = 0x100, d } Eshort;
typedef enum { e = 0x10000, f } Eint;
typedef enum { g = 0x100000000LL, h } Elonglong;


void dcl_ac (Echar);


void dcl_as (Eshort);


void dcl_ai (Eint);


void dcl_all (Elonglong);

void test_1 (void)
{
  dcl_ac (1);
  dcl_as (2);
  dcl_ai (3);
  dcl_all (4);
}


void dfn_ac (Echar c)
{
}


void dfn_as (Eshort s)
{
}


void dfn_ai (Eint i)
{
}


void dfn_all (Elonglong ll)
{
}
