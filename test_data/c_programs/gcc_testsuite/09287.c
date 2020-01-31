



typedef int IA[];
typedef int IA5[5];
typedef int IA10[10];
typedef IA *IAP;
typedef IA5 *IA5P;
typedef IA10 *IA10P;
extern IAP a[];
void
f (void)
{
  extern IA5P a[];
}
IAP a[] = { 0 };
extern IA10P a[];
