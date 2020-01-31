


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;
extern void baz(char *);
void bar (va_list *args)
{
  if (args)
    {
      char *s = __builtin_va_arg(*args, char *);
      baz(s);
    }
}
