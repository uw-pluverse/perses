



__attribute__((noinline)) int *
foo (int *x, int y)
{
  return x + y;
}

int a[1024];
int *b[1024] = { &a[0] };

int
main ()
{
  int i;
  for (i = 0; i < 1024; i++)
    b[i] = &a[1023 - i];
 for (i = 0; i < 1024; i++)
    b[i] = foo (b[i], i);
  for (i = 0; i < 1024; i++)
    if (b[i] != &a[1023])
      __builtin_abort ();
  return 0;
}
