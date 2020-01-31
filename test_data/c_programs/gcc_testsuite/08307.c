








static _Bool
compare_and_swap(long *addr, long old, long new_val)
{
  return __sync_bool_compare_and_swap(addr, old, new_val);
}

void
foo (long *address)
{
  long he_address = *address & ~1;
  while (!compare_and_swap(address, he_address, he_address | 1))
    he_address = *address & ~1;
}
