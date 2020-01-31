




typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

union U
{
  long l1[2];
};

union U u;

void foo (int z, ...)
{
  int i;
  va_list ap;
  __builtin_va_start(ap, z);
  i = __builtin_va_arg(ap, int);
  __builtin_va_end(ap);
}

int main(void)
{
  foo (1, 1, 1, 1, 1, u);
  return 0;
}
