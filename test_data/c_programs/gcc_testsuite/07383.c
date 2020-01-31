


_Bool a[1024];
_Bool b[1024];
_Bool c[1024];
void foo (void)
{
  unsigned i;
  for (i = 0; i < 1024; ++i)
    a[i] = b[i] | c[i];
}
