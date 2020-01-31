




extern int a[];
int *p;
char c;
signed char sc;
unsigned char uc;

void
f (void)
{
  a[sc];
  a[uc];
  sc[a];
  uc[a];
  p[sc];
  p[uc];
  sc[p];
  uc[p];
  a[c];
  p[c];


  c[a];
  c[p];
}
