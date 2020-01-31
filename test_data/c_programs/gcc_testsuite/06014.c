



int cst_fun1 (int) __attribute__((__const__));
int cst_fun2 (int) __attribute__((__const__));
int pure_fun1 (int) __attribute__((__pure__));
int pure_fun2 (int) __attribute__((__pure__));
int foo (void);

int xxx (void)
{
  int i, k = foo (), x = 0;

  for (i = 0; i < 100; i++)
    {
      x += cst_fun1 (k);
      x += pure_fun1 (k);

      if (k)
 {
   x += cst_fun2 (k);
   x += pure_fun2 (k);
 }
    }

  return x;
}
