




typedef enum { a = 0x1, b } Echar;
typedef enum { c = 0x100, d } Eshort;
typedef enum { e = 0x10000, f } Eint;
typedef enum { g = 0x100000000LL, h } Elonglong;


Echar dcl_rc (void);


Eshort dcl_rs (void);


Eint dcl_ri (void);


Elonglong dcl_rll (void);

void test_1 (void)
{
  dcl_rc ();
  dcl_rs ();
  dcl_ri ();
  dcl_rll ();
}


Echar dfn_rc (void)
{
  return 1;
}


Eshort dfn_rs (void)
{
  return 2;
}


Eint dfn_ri (void)
{
  return 3;
}


Elonglong dfn_rll (void)
{
  return 4;
}
