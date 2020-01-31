


void f1(long *);
void f2(unsigned long *);

int main()
{
  long *lp;
  unsigned long *ulp;
  char *cp;
  unsigned char *ucp;
  signed char *scp;

  ulp = lp;
  lp = ulp;
  f1(ulp);
  f2(lp);

  cp = ucp;
  cp = scp;
  ucp = scp;
  ucp = cp;
  scp = ucp;
  scp = cp;
}
