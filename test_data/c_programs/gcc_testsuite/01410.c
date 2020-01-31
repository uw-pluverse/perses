





extern float fabsf (float);
extern float sqrtf (float);
extern double fabs (double);
extern double sqrt (double);

volatile float f1, f2, f3;

void test_sf() {


  f1 = fabsf (f1);


  f1 = -f1;


  f1 = f2 + f3;


  f1 = f2 - f3;


  f1 = f2 / f3;


  f1 = f2 * f3;


  f1 = -f2 * f3;


  f1 = f2 * f3 + f1;


  f1 = f2 * f3 - f1;


  f1 = f2 - f3 * f1;


  f1 = -f2 * f3 - f1;


  f1 = sqrtf (f1);
}

volatile double d1, d2, d3;

void test_df() {


  d1 = fabs (d1);


  d1 = -d1;


  d1 = d2 + d3;


  d1 = d2 - d3;


  d1 = d2 / d3;


  d1 = d2 * d3;


  d1 = -d2 * d3;


  d1 = d2 * d3 + d1;


  d1 = d2 * d3 - d1;


  d1 = d2 - d3 * d1;


  d1 = -d2 * d3 - d1;


  d1 = sqrt (d1);
}

volatile int i1;
volatile unsigned int u1;

void test_convert () {


  d1 = f1;


  f1 = d1;


  i1 = f1;


  i1 = d1;


  u1 = f1;


  u1 = d1;


  f1 = i1;


  d1 = i1;


  f1 = u1;


  d1 = u1;
}

void test_ldst (float f[], double d[]) {




  f[256] = f[255] + f[-255];




  d[32] = d[127] + d[-127];
}
