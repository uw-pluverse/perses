




typedef struct {char a;} one;
typedef struct {short a;} two;
typedef struct {int a;} four;
typedef struct {long long a;} eight;
typedef struct {int a, b[12];} big;


one dcl_rone (void);


two dcl_rtwo (void);


four dcl_rfour (void);


eight dcl_reight (void);


big dcl_rbig (void);

void test_1 (void)
{
  dcl_rone ();
  dcl_rtwo ();
  dcl_rfour ();
  dcl_reight ();
  dcl_rbig ();
}




one dfn_rone (void)
{
  return ({one t; t.a = 1; t;});
}


two dfn_rtwo (void)
{
  return ({two t; t.a = 2; t;});
}


four dfn_rfour (void)
{
  return ({four t; t.a = 3; t;});
}


eight dfn_reight (void)
{
  return ({eight t; t.a = 4; t;});
}


big dfn_rbig (void)
{
  return ({big t; t.a = 5; t;});
}
