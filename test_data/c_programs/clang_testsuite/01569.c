void vf(void);
int if1(void);
char if2(void);
long if3(void);
float rf1(void);
double rf2(void);
_Complex double cf(void);
enum e { E1 } ef(void);
_Bool bf(void);
char *pf1(void);
int *pf2(void);
void
foo(void)
{
  (void)vf();
  (void)if1();
  (void)cf();
  (const void)bf();
  (int)if1();
  (long)if2();
  (char)if3();
  (float)rf1();
  (long double)rf2();
  (_Complex float)cf();
  (enum f { F1 })ef();
  (_Bool)bf();
  (void *)pf1();
  (char *)pf2();
  (float)if1();
  (double)if2();
  (_Bool)if3();
  (int)rf1();
  (long)rf2();
  (double)cf();
  (int)ef();
  (int)bf();
  (long unsigned int)pf1();
  (long int)pf2();
}
