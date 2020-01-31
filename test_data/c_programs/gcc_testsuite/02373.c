typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

va_list global;

void vat(va_list param, ...)
{
  va_list local;

  __builtin_va_start(local, param);
  __builtin_va_copy(global, local);
  __builtin_va_copy(param, local);
  if (__builtin_va_arg(local, int) != 1)
    abort();
  __builtin_va_end(local);
  if (__builtin_va_arg(global, int) != 1)
    abort();
  __builtin_va_end(global);
  if (__builtin_va_arg(param, int) != 1)
    abort();
  __builtin_va_end(param);

  __builtin_va_start(param, param);
  __builtin_va_start(global, param);
  __builtin_va_copy(local, param);
  if (__builtin_va_arg(local, int) != 1)
    abort();
  __builtin_va_end(local);
  __builtin_va_copy(local, global);
  if (__builtin_va_arg(local, int) != 1)
    abort();
  __builtin_va_end(local);
  if (__builtin_va_arg(global, int) != 1)
    abort();
  __builtin_va_end(global);
  if (__builtin_va_arg(param, int) != 1)
    abort();
  __builtin_va_end(param);
}

int main(void)
{
  va_list t;
  vat (t, 1);
  exit (0);
}
