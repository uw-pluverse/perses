





__attribute__ ((target ("+nosimd")))
int
baz (int *a)
{
  for (int i = 0; i < 1024; i++)
    a[i] += 5;
}

__attribute__ ((target ("arch=armv8-a+nosimd")))
int
baz2 (int *a)
{
  for (int i = 0; i < 1024; i++)
    a[i] += 5;
}

__attribute__ ((target ("cpu=cortex-a53+nosimd")))
int
baz3 (int *a)
{
  for (int i = 0; i < 1024; i++)
    a[i] += 5;
}

__attribute__ ((target ("general-regs-only")))
int
baz4 (int *a)
{
  for (int i = 0; i < 1024; i++)
    a[i] += 5;
}
