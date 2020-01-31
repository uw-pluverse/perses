typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

extern void abort (void);

int foo_arg, bar_arg;
long x;
double d;
va_list gap;
va_list *pap;

void
foo (int v, va_list ap)
{
  switch (v)
    {
    case 5: foo_arg = __builtin_va_arg(ap, int); break;
    default: abort ();
    }
}

void
bar (int v)
{
  if (v == 0x4006)
    {
      if (__builtin_va_arg(gap, double) != 17.0
   || __builtin_va_arg(gap, long) != 129L)
 abort ();
    }
  else if (v == 0x4008)
    {
      if (__builtin_va_arg(*pap, long long) != 14LL
   || __builtin_va_arg(*pap, long double) != 131.0L
   || __builtin_va_arg(*pap, int) != 17)
 abort ();
    }
  bar_arg = v;
}

void
f0 (int i, ...)
{
}

void
f1 (int i, ...)
{
  va_list ap;
  __builtin_va_start(ap, i);
  __builtin_va_end(ap);
}

void
f2 (int i, ...)
{
  va_list ap;
  __builtin_va_start(ap, i);
  bar (d);
  x = __builtin_va_arg(ap, long);
  bar (x);
  __builtin_va_end(ap);
}

void
f3 (int i, ...)
{
  va_list ap;
  __builtin_va_start(ap, i);
  d = __builtin_va_arg(ap, double);
  __builtin_va_end(ap);
}

void
f4 (int i, ...)
{
  va_list ap;
  __builtin_va_start(ap, i);
  x = __builtin_va_arg(ap, double);
  foo (i, ap);
  __builtin_va_end(ap);
}

void
f5 (int i, ...)
{
  va_list ap;
  __builtin_va_start(ap, i);
  __builtin_va_copy(gap, ap);
  bar (i);
  __builtin_va_end(ap);
  __builtin_va_end(gap);
}

void
f6 (int i, ...)
{
  va_list ap;
  __builtin_va_start(ap, i);
  bar (d);
  __builtin_va_arg(ap, long);
  __builtin_va_arg(ap, long);
  x = __builtin_va_arg(ap, long);
  bar (x);
  __builtin_va_end(ap);
}

void
f7 (int i, ...)
{
  va_list ap;
  __builtin_va_start(ap, i);
  pap = &ap;
  bar (i);
  __builtin_va_end(ap);
}

void
f8 (int i, ...)
{
  va_list ap;
  __builtin_va_start(ap, i);
  pap = &ap;
  bar (i);
  d = __builtin_va_arg(ap, double);
  __builtin_va_end(ap);
}

int
main (void)
{
  f0 (1);
  f1 (2);
  d = 31.0;
  f2 (3, 28L);
  if (bar_arg != 28 || x != 28)
    abort ();
  f3 (4, 131.0);
  if (d != 131.0)
    abort ();
  f4 (5, 16.0, 128);
  if (x != 16 || foo_arg != 128)
    abort ();
  f5 (0x4006, 17.0, 129L);
  if (bar_arg != 0x4006)
    abort ();
  f6 (7, 12L, 14L, -31L);
  if (bar_arg != -31)
    abort ();
  f7 (0x4008, 14LL, 131.0L, 17, 26.0);
  if (bar_arg != 0x4008)
    abort ();
  f8 (0x4008, 14LL, 131.0L, 17, 27.0);
  if (bar_arg != 0x4008 || d != 27.0)
    abort ();
  return 0;
}
