


typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

struct S
{
  int (*m_fn1) (void);
} a;

void
fn1 (int d, ...)
{
  va_list c;
  __builtin_va_start(c, d);

  {
    int *d = __builtin_va_arg(c, int *);

    int **e = &d;

    a.m_fn1 ();
  }

  a.m_fn1 ();

  __builtin_va_end(c);
}
