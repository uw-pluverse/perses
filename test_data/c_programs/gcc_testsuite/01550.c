




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


void dcl_avc1 (vc1);

void dcl_avc2 (vc2);

void dcl_avc4 (vc4);

void dcl_avc8 (vc8);


void dcl_avs1 (vs1);

void dcl_avs2 (vs2);

void dcl_avs4 (vs4);

void dcl_avs8 (vs8);


void dcl_avi1 (vi1);

void dcl_avi2 (vi2);

void dcl_avi4 (vi4);

void dcl_avi8 (vi8);


void dcl_avll1 (vll1);

void dcl_avll2 (vll2);

void dcl_avll4 (vll4);

void dcl_avll8 (vll8);


void dcl_avf1 (vf1);

void dcl_avf2 (vf2);

void dcl_avf4 (vf4);

void dcl_avf8 (vf8);


void dcl_avd1 (vd1);

void dcl_avd2 (vd2);

void dcl_avd4 (vd4);

void dcl_avd8 (vd8);



void test_1 (void)
{
  dcl_avc1 (({vc1 t;t[0]= 1;t;}));
  dcl_avc2 (({vc2 t;t[0]= 2;t;}));
  dcl_avc4 (({vc4 t;t[0]= 3;t;}));
  dcl_avc8 (({vc8 t;t[0]= 4;t;}));

  dcl_avs1 (({vs1 t;t[0]= 5;t;}));
  dcl_avs2 (({vs2 t;t[0]= 6;t;}));
  dcl_avs4 (({vs4 t;t[0]= 7;t;}));
  dcl_avs8 (({vs8 t;t[0]= 8;t;}));

  dcl_avi1 (({vi1 t;t[0]= 9;t;}));
  dcl_avi2 (({vi2 t;t[0]= 10;t;}));
  dcl_avi4 (({vi4 t;t[0]= 11;t;}));
  dcl_avi8 (({vi8 t;t[0]= 12;t;}));

  dcl_avll1 (({vll1 t;t[0]= 13;t;}));
  dcl_avll2 (({vll2 t;t[0]= 14;t;}));
  dcl_avll4 (({vll4 t;t[0]= 15;t;}));
  dcl_avll8 (({vll8 t;t[0]= 16;t;}));

  dcl_avf1 (({vf1 t;t[0]= 17;t;}));
  dcl_avf2 (({vf2 t;t[0]= 18;t;}));
  dcl_avf4 (({vf4 t;t[0]= 19;t;}));
  dcl_avf8 (({vf8 t;t[0]= 20;t;}));

  dcl_avd1 (({vd1 t;t[0]= 21;t;}));
  dcl_avd2 (({vd2 t;t[0]= 22;t;}));
  dcl_avd4 (({vd4 t;t[0]= 23;t;}));
  dcl_avd8 (({vd8 t;t[0]= 24;t;}));
}


void dfn_avc1(vc1 a)
{
}

void dfn_avc2(vc2 a)
{
}

void dfn_avc4(vc4 a)
{
}

void dfn_avc8(vc8 a)
{
}


void dfn_avs1(vs1 a)
{
}

void dfn_avs2(vs2 a)
{
}

void dfn_avs4(vs4 a)
{
}

void dfn_avs8(vs8 a)
{
}


void dfn_avi1(vi1 a)
{
}

void dfn_avi2(vi2 a)
{
}

void dfn_avi4(vi4 a)
{
}

void dfn_avi8(vi8 a)
{
}


void dfn_avll1(vll1 a)
{
}

void dfn_avll2(vll2 a)
{
}

void dfn_avll4(vll4 a)
{
}

void dfn_avll8(vll8 a)
{
}


void dfn_avf1(vf1 a)
{
}

void dfn_avf2(vf2 a)
{
}

void dfn_avf4(vf4 a)
{
}

void dfn_avf8(vf8 a)
{
}


void dfn_avd1(vd1 a)
{
}

void dfn_avd2(vd2 a)
{
}

void dfn_avd4(vd4 a)
{
}

void dfn_avd8(vd8 a)
{
}
