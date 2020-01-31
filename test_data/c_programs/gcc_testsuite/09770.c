



void
foo (char *p)
{
  p = __builtin_assume_aligned (p, 64);
  __builtin_memset (p, 0, 0x100000001ULL);
}
