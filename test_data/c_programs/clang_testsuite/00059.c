int rand(void);
double drand48(void);
double erand48(unsigned short[3]);
long jrand48(unsigned short[3]);
void lcong48(unsigned short[7]);
long lrand48(void);
long mrand48(void);
long nrand48(unsigned short[3]);
long random(void);
int rand_r(unsigned *);
void test_rand()
{
  unsigned short a[7];
  unsigned b;
  rand();
  drand48();
  erand48(a);
  jrand48(a);
  lcong48(a);
  lrand48();
  mrand48();
  nrand48(a);
  rand_r(&b);
  random();
}
