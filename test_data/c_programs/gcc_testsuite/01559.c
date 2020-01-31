




typedef char __attribute__ ((vector_size (1))) vc1;
typedef char __attribute__ ((vector_size (2))) vc2;
typedef char __attribute__ ((vector_size (4))) vc4;
typedef char __attribute__ ((vector_size (8))) vc8;

typedef short __attribute__ ((vector_size (2))) vs1;
typedef short __attribute__ ((vector_size (4))) vs2;
typedef short __attribute__ ((vector_size (8))) vs4;
typedef short __attribute__ ((vector_size (16))) vs8;

typedef int __attribute__ ((vector_size (4))) vi1;
typedef int __attribute__ ((vector_size (8))) vi2;
typedef int __attribute__ ((vector_size (16))) vi4;
typedef int __attribute__ ((vector_size (32))) vi8;

typedef long long __attribute__ ((vector_size (8))) vll1;
typedef long long __attribute__ ((vector_size (16))) vll2;
typedef long long __attribute__ ((vector_size (32))) vll4;
typedef long long __attribute__ ((vector_size (64))) vll8;

typedef float __attribute__ ((vector_size (4))) vf1;
typedef float __attribute__ ((vector_size (8))) vf2;
typedef float __attribute__ ((vector_size (16))) vf4;
typedef float __attribute__ ((vector_size (32))) vf8;

typedef double __attribute__ ((vector_size (8))) vd1;
typedef double __attribute__ ((vector_size (16))) vd2;
typedef double __attribute__ ((vector_size (32))) vd4;
typedef double __attribute__ ((vector_size (64))) vd8;


vc1 dcl_rvc1 (void);

vc2 dcl_rvc2 (void);

vc4 dcl_rvc4 (void);

vc8 dcl_rvc8 (void);


vs1 dcl_rvs1 (void);

vs2 dcl_rvs2 (void);

vs4 dcl_rvs4 (void);

vs8 dcl_rvs8 (void);


vi1 dcl_rvi1 (void);

vi2 dcl_rvi2 (void);

vi4 dcl_rvi4 (void);

vi8 dcl_rvi8 (void);


vll1 dcl_rvll1 (void);

vll2 dcl_rvll2 (void);

vll4 dcl_rvll4 (void);

vll8 dcl_rvll8 (void);


vf1 dcl_rvf1 (void);

vf2 dcl_rvf2 (void);

vf4 dcl_rvf4 (void);

vf8 dcl_rvf8 (void);


vd1 dcl_rvd1 (void);

vd2 dcl_rvd2 (void);

vd4 dcl_rvd4 (void);

vd8 dcl_rvd8 (void);

void test_1 (void)
{
  dcl_rvc1 ();
  dcl_rvc2 ();
  dcl_rvc4 ();
  dcl_rvc8 ();

  dcl_rvs1 ();
  dcl_rvs2 ();
  dcl_rvs4 ();
  dcl_rvs8 ();

  dcl_rvi1 ();
  dcl_rvi2 ();
  dcl_rvi4 ();
  dcl_rvi8 ();

  dcl_rvll1 ();
  dcl_rvll2 ();
  dcl_rvll4 ();
  dcl_rvll8 ();

  dcl_rvf1 ();
  dcl_rvf2 ();
  dcl_rvf4 ();
  dcl_rvf8 ();

  dcl_rvd1 ();
  dcl_rvd2 ();
  dcl_rvd4 ();
  dcl_rvd8 ();
}




vc1 dfn_rvc1 (void)
{
  return ({vc1 t;t[0]= 1;t;});
}

vc2 dfn_rvc2 (void)
{
  return ({vc2 t;t[0]= 2;t;});
}

vc4 dfn_rvc4 (void)
{
  return ({vc4 t;t[0]= 3;t;});
}

vc8 dfn_rvc8 (void)
{
  return ({vc8 t;t[0]= 4;t;});
}


vs1 dfn_rvs1 (void)
{
  return ({vs1 t;t[0]= 5;t;});
}

vs2 dfn_rvs2 (void)
{
  return ({vs2 t;t[0]= 6;t;});
}

vs4 dfn_rvs4 (void)
{
  return ({vs4 t;t[0]= 7;t;});
}

vs8 dfn_rvs8 (void)
{
  return ({vs8 t;t[0]= 8;t;});
}


vi1 dfn_rvi1 (void)
{
  return ({vi1 t;t[0]= 9;t;});
}

vi2 dfn_rvi2 (void)
{
  return ({vi2 t;t[0]= 10;t;});
}

vi4 dfn_rvi4 (void)
{
  return ({vi4 t;t[0]= 11;t;});
}

vi8 dfn_rvi8 (void)
{
  return ({vi8 t;t[0]= 12;t;});
}


vll1 dfn_rvll1 (void)
{
  return ({vll1 t;t[0]= 13;t;});
}

vll2 dfn_rvll2 (void)
{
  return ({vll2 t;t[0]= 14;t;});
}

vll4 dfn_rvll4 (void)
{
  return ({vll4 t;t[0]= 16;t;});
}

vll8 dfn_rvll8 (void)
{
  return ({vll8 t;t[0]= 6;t;});
}


vf1 dfn_rvf1 (void)
{
  return ({vf1 t;t[0]= 17;t;});
}

vf2 dfn_rvf2 (void)
{
  return ({vf2 t;t[0]= 18;t;});
}

vf4 dfn_rvf4 (void)
{
  return ({vf4 t;t[0]= 19;t;});
}

vf8 dfn_rvf8 (void)
{
  return ({vf8 t;t[0]= 20;t;});
}


vd1 dfn_rvd1 (void)
{
  return ({vd1 t;t[0]= 21;t;});
}

vd2 dfn_rvd2 (void)
{
  return ({vd2 t;t[0]= 22;t;});
}

vd4 dfn_rvd4 (void)
{
  return ({vd4 t;t[0]= 23;t;});
}

vd8 dfn_rvd8 (void)
{
  return ({vd8 t;t[0]= 24;t;});
}
