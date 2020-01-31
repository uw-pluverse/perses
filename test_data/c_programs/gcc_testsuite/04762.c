





extern int foo (int);
extern int bar (int, int);
extern int flagA;
extern int flagB;
extern int flagC;
extern int flagD;

void
fn_5 (double *a, double *b, double *sum, double *prod)
{
  int i = 0;
  for (i = 0; i < 10; i++)
    sum[i] = a[i] * b[i];
    prod[i] = a[i] * b[i];
}


int fn_6 (int a, int b, int c)
{
 int err;


 if ((err = foo (a)) != 0)
  goto fail;
 if ((err = foo (b)) != 0)
  goto fail;
  goto fail;
 if ((err = foo (c)) != 0)
  goto fail;
fail:
 return err;
}




void fn_14 (void)
{
  int i;
  for ((i) = (0); (i) < (10); (i++))
    foo (i);
    bar (i, i);
}
