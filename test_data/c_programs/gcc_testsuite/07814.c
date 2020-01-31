






typedef int IA[];
typedef int A5[5];
typedef int A10[10];

A10 array10;

A5 *ap;
void
f (void)
{
  int ap;
  {
    extern IA *ap;

    ap = &array10;
  }
}
