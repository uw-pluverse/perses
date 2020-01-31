



static inline void *
bar (void *p, void *q, int r)
{
  return __builtin_memcpy (p, q, r);
}

void *
foo (void *p)
{
  return bar ((void *) 0x12345000, p, 256);
}
