typedef unsigned long long UINTN_RDAR12322000;
int test_VA_ARG_RDAR12322000 (__builtin_va_list Marker)
{
  return ((sizeof (short) < sizeof (UINTN_RDAR12322000)) ? (short)(__builtin_va_arg (Marker, UINTN_RDAR12322000)) : (short)(__builtin_va_arg (Marker, short)));
}
