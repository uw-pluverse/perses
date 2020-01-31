



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void abort (void);

void
foo (int p[100], int k, ...)
{
  int j, *q;
  va_list ap;

  __builtin_va_start(ap, k);
  q = __builtin_va_arg(ap, int *);
  for (j = 0; j < 100; j++)
    q[j] = p[j] + 10;
  __builtin_va_end(ap);
}

int
main (void)
{
  int buf[100], buf2[100], i;
  for (i = 0; i < 100; i++)
    buf[i] = i + 1;
  foo (buf, 0, buf2);
  for (i = 0; i < 100; i++)
    if (buf2[i] != buf[i] + 10)
      abort ();
  return 0;
}
