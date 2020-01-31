



typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

static void
foo (va_list ap)
{
  __builtin_va_arg(ap, char *)[0];
}

void
bar (va_list ap)
{
  foo (ap);
}

void
baz (va_list ap)
{
  foo (ap);
}
