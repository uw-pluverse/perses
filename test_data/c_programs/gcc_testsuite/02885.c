

typedef __builtin_va_list va_list;
typedef __builtin_va_list __gnuc_va_list;

typedef struct {
  void *stream;
  va_list ap;
  int nChar;
} ScanfState;

void dummy (va_list vap)
{
  if (__builtin_va_arg(vap, int) != 1234) abort();
  return;
}

void test (int fmt, ...)
{
  ScanfState state, *statep;

  statep = &state;

  __builtin_va_start(statep->ap, fmt);
  dummy (statep->ap);
  __builtin_va_end(statep->ap);

  __builtin_va_start(state.ap, fmt);
  dummy (state.ap);
  __builtin_va_end(state.ap);

  return;
}

int main (void)
{
  test (456, 1234);
  exit (0);
}
