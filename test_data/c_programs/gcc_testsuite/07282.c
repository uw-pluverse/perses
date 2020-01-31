



static inline void xyzzy(void *p __attribute__((unused)))
{
}

void doit(void)
{
  int x __attribute__((cleanup (xyzzy)));
}
